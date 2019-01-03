#include <iostream>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include "world.hpp"
#include <Box2D/Box2D.h>
#include <vector>

int main()
{
    //timekeeping put before everything else to avoid dt equalling zero
    clock_t last_time = clock();
    clock_t current_time;
    double dt;

    //open and configure window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    const sf::Vector2i screen_size(constants::width, constants::height);
    sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Breakout", 
                            sf::Style::Close | sf::Style::Titlebar, settings);
    
    //configure text
    sf::Font font;
    if (!font.loadFromFile("../assets/arial.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
        return 1;
    }

    //limit frame rate to 60fps
    window.setFramerateLimit(constants::fps);

    //fps tracking
    double fps = 0.0;
    double fps_smoothing = 0.8;
    sf::Text FPS("fps: 0.0", font, 20);

    //score tracking
    int score = 0;
    sf::Text Score("Score: 0", font, 24);
    Score.setPosition(sf::Vector2f((float)constants::width - 150.0f, 0.0f));

    //lives tracking
    int lives = 3;
    sf::Text Lives("Lives: 3", font, 24);
    Lives.setPosition(sf::Vector2f((float)constants::width - 300.0f, 0.0f));
    
    //set up world
    breakout::World* world = new breakout::World();
    
    //world parameters
    float32 time_step = 1.0f / (float)constants::fps; 
    int32 velocity_iterations = 8;
    int32 position_iterations = 3;
    
    while (window.isOpen())
    {
        //check if ball is too low
        if (world->ball->get_position().y > constants::height - 25.0f)
        {
            if (lives > 1)
            {
                lives--;
                world->reset_ball();
                Lives.setString("Lives: " + std::to_string((int) lives));
            }
            else
            {
                std::cout << "Game over. Score: " << score << std::endl;
                break;
            }

        }

        if (world->bricks.size() == 0)
        {
            world->reset_bricks();
        }

        world->step(time_step, velocity_iterations, position_iterations);
        //fps tracker
        current_time = clock();
        dt = (double) ((double)(current_time - last_time) / CLOCKS_PER_SEC);
        last_time = current_time;
        fps *= fps_smoothing;
        fps += (1.0 / dt) * (1.0 - fps_smoothing);
        FPS.setString("fps: " + std::to_string((int) fps));

        //handle close window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //set paddle velocity to go left
            world->set_paddle_velocity(-constants::paddle_velocity);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //set paddle to go right
            world->set_paddle_velocity(constants::paddle_velocity);
        }
        else 
        {
            //stop moving
            world->set_paddle_velocity(0.0f);
        }

        world->update_display(&score);
        Score.setString("Score: " + std::to_string(score));
        world->draw(&window);

        window.draw(FPS);
        window.draw(Score);
        window.draw(Lives);
        window.display();
    }
    return 0;
}