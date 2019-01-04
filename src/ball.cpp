#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "ball.hpp"
#include "paddle.hpp"
#include "shape.hpp"
#include "constants.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace breakout 
{
    Ball::Ball(const sf::Vector2f position, const float r, const sf::Vector2f velocity, 
               b2World* world, const sf::Color color)
    : r(r)
    {
        type = ball;

        //box2d circle
        b2BodyDef body_def;
        body_def.type = b2_dynamicBody;
        body_def.position.Set(position.x / constants::scale_factor, position.y / constants::scale_factor);
        body_def.angle = 0;
        body_def.linearDamping = 0.0f;
        body_def.fixedRotation = true;


        b2CircleShape circle_shape;
        circle_shape.m_radius = r / constants::scale_factor;

        b2FixtureDef circle_fixture_def;
        circle_fixture_def.shape = &circle_shape;
        circle_fixture_def.density = 1.0f;
        circle_fixture_def.friction = 0.0f;
        circle_fixture_def.restitution = 1.0f;

        circle_physics = world->CreateBody(&body_def);
        circle_physics->CreateFixture(&circle_fixture_def);
        circle_physics->SetLinearVelocity(b2Vec2(velocity.x / constants::scale_factor, 
                                                 velocity.y / constants::scale_factor));
        //set user data for collision callback
        circle_physics->SetUserData(this);


        //display circle
        circle_display.setPosition(position);
        circle_display.setRadius(r);
        circle_display.setFillColor(color);
    }



    sf::Vector2f Ball::get_position()
    {
        //returns display position (position in pixels)
        b2Vec2 position = circle_physics->GetPosition();
        //scale back up
        position.x *= constants::scale_factor;
        position.y *= constants::scale_factor;
        return sf::Vector2f(position.x, position.y);
    }


    void Ball::start_contact(Shape* crashedWith)
    {
    }


    void Ball::end_contact(Shape* crashedWith)
    {
        b2Vec2 velocity = circle_physics->GetLinearVelocity();

        //prevent the ball from travelling too slow in the y direction
        if (abs(velocity.y) > (constants::upper_ball_velocity_y / constants::scale_factor))
        {
            float scale_f = ((constants::upper_ball_velocity_y / constants::scale_factor) / abs(velocity.y));
            velocity.y *= scale_f;
        }
        else if (abs(velocity.y) < (constants::lower_ball_velocity_y / constants::scale_factor))
        {
            float scale_f = ((constants::lower_ball_velocity_y / constants::scale_factor) / abs(velocity.y));
            velocity.y *= scale_f;
        }
        //add randomness / control if hits paddle
        if (crashedWith->type == paddle)
        {
            //add randomness to bounce to make it more interesting (+- 50 to x velocity)
            velocity.x += (float)(rand() % 100 - 50) / constants::scale_factor;
            
            //allows player to get some control by bouncing the ball in the way the paddle is moving
            velocity.x += (static_cast<Paddle*>(crashedWith)->get_velocity().x) * 20.0f / constants::scale_factor;

            circle_physics->SetLinearVelocity(velocity);
        }
    }


    void Ball::set_color(sf::Color color)
    {
        circle_display.setFillColor(color);
    }


    void Ball::set_color(int r, int g, int b)
    {
        sf::Color color(r, g, b);
        circle_display.setFillColor(color);
    }


    void Ball::update_display()
    {
        b2Vec2 position = circle_physics->GetPosition();
        //scale back up
        position.x *= constants::scale_factor;
        position.y *= constants::scale_factor;
        
        circle_display.setPosition(sf::Vector2f(position.x - r, position.y - r));
    }


    void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(circle_display, states);
    }


    Ball::~Ball()
    {
        circle_physics->GetWorld()->DestroyBody(circle_physics);
    }
}