#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "edge.hpp"
#include "contact_listener.hpp"
#include "rectangle.hpp"
#include "paddle.hpp"
#include "constants.hpp"
#include "shape.hpp"
#include <Box2D/Box2D.h>
#include <vector>
#include "world.hpp"


namespace breakout
{
    World::World()
    {
        //set up box2d world with no gravity
        b2Vec2 gravity(0.0f, 0.0f);
        b2world = new b2World(gravity);

        //initialize contact listener
        b2world->SetContactListener(&contact_listener);


        //border
        edge = new Edge(sf::Vector2f(0.0f, constants::top_edge), 
                                     sf::Vector2f((float)constants::width, ((float)constants::height - constants::top_edge)), 
                                     b2world);

        //initialize bricks
        if (!bricks.empty())
        {
            bricks.clear();
        }

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                //create a rectangle in place at end of vector
                Rectangle* brick = new Rectangle(sf::Vector2f((25 + 50 * j), (100 + 25 * i)), 
                                                                     sf::Vector2f(50.0, 25.0), b2world);
                switch (i)
                {
                    case 0:
                        brick->set_color(sf::Color::Red);
                        break;
                    case 1:
                        //orange
                        brick->set_color(255, 100, 0);
                        break;
                    case 2:
                        brick->set_color(255, 170, 0);
                        break;
                    case 3:
                        brick->set_color(sf::Color::Yellow);
                        break;
                    case 4:
                        brick->set_color(sf::Color::Green);
                        break;
                    case 5:
                        brick->set_color(sf::Color::Blue);
                        break;

                }
                bricks.push_back(brick);
            }
        }

        //paddle
        paddle = new Paddle(sf::Vector2f(200.0, 950.0), sf::Vector2f(100.0, 15.0), 
                            sf::Vector2f(0.0, 0.0), b2world);
        //ball
        ball = new Ball(sf::Vector2f(paddle->get_position().x, paddle->get_position().y - 25.0f),
                                     15.0f, sf::Vector2f(200.0, -600.0), b2world);

    }
    
    
    void World::step(float32 time_step, int32 velocity_iterations, int32 position_iterations)
    {
        b2world->Step(time_step, velocity_iterations, position_iterations);
    }


    void World::reset_all()
    {
        //get rid of old world
        for (std::vector<Rectangle*>::iterator it = bricks.begin(); it != bricks.end(); ++it)
        {
            (*it)->~Rectangle();
        }
        bricks.clear();
        delete ball;
        delete edge;

        //border
        edge = new Edge(sf::Vector2f(0.0f, constants::top_edge), 
                                     sf::Vector2f((float)constants::width, ((float)constants::height - constants::top_edge)), 
                                     b2world);

        //initialize bricks
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                //create a rectangle in place at end of vector
                Rectangle* brick = new Rectangle(sf::Vector2f((25 + 50 * j), (100 + 25 * i)), 
                                                                     sf::Vector2f(50.0, 25.0), b2world);
                switch (i)
                {
                    case 0:
                        brick->set_color(sf::Color::Red);
                        break;
                    case 1:
                        //orange
                        brick->set_color(255, 100, 0);
                        break;
                    case 2:
                        brick->set_color(255, 170, 0);
                        break;
                    case 3:
                        brick->set_color(sf::Color::Yellow);
                        break;
                    case 4:
                        brick->set_color(sf::Color::Green);
                        break;
                    case 5:
                        brick->set_color(sf::Color::Blue);
                        break;

                }
                bricks.push_back(brick);
            }
        }

        //ball
        ball = new Ball(sf::Vector2f(paddle->get_position().x, paddle->get_position().y - 25.0f),
                                     15.0f, sf::Vector2f(200.0, -600.0), b2world);
    }


    void World::reset_bricks()
    {
        //make sure bricks vector is empty
        for (std::vector<Rectangle*>::iterator it = bricks.begin(); it != bricks.end(); ++it)
        {
            (*it)->~Rectangle();
        }
        bricks.clear();

        //initialize bricks
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                //create a rectangle in place at end of vector
                Rectangle* brick = new Rectangle(sf::Vector2f((25 + 50 * j), (100 + 25 * i)), 
                                                                     sf::Vector2f(50.0, 25.0), b2world);
                switch (i)
                {
                    case 0:
                        brick->set_color(sf::Color::Red);
                        break;
                    case 1:
                        //orange
                        brick->set_color(255, 100, 0);
                        break;
                    case 2:
                        brick->set_color(255, 170, 0);
                        break;
                    case 3:
                        brick->set_color(sf::Color::Yellow);
                        break;
                    case 4:
                        brick->set_color(sf::Color::Green);
                        break;
                    case 5:
                        brick->set_color(sf::Color::Blue);
                        break;

                }
                bricks.push_back(brick);
            }
        }
    }


    void World::reset_ball()
    {
        delete ball;
        //ball
        ball = new Ball(sf::Vector2f(paddle->get_position().x, paddle->get_position().y - 25.0f),
                                     15.0f, sf::Vector2f(200.0, -600.0), b2world);
    }


    void World::update_display(int* score)
    {
        for (std::vector<Rectangle*>::iterator it = bricks.begin(); it != bricks.end(); ++it)
        {
            if ((*it)->remove == true)
            {
                //remove brick
                (*it)->~Rectangle();
                bricks.erase(it);

                (*score)++;

                break;
            }
            
            (*it)->update_display();
        }
        ball->update_display();
        paddle->update_display();
    }


    void World::draw(sf::RenderWindow* window)
    {
        window->clear(sf::Color::Black);
        window->draw(*ball);
        for (std::vector<Rectangle*>::iterator it = bricks.begin(); it != bricks.end(); ++it)
        {
            window->draw(**it);
        }
        window->draw(*paddle);

    }


    World::~World()
    {
        for (std::vector<Rectangle*>::iterator it = bricks.begin(); it != bricks.end(); ++it)
        {
            (*it)->~Rectangle();
            bricks.erase(it);
        }
        delete paddle;
        delete ball;
        delete edge;
        delete b2world;
    }
}