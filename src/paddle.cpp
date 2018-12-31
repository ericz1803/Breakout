#include <cmath>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "paddle.hpp"
#include "shape.hpp"
#include "constants.hpp"
#include <iostream>

namespace breakout 
{
    Paddle::Paddle(const sf::Vector2f position, const sf::Vector2f size, 
                   const sf::Vector2f velocity, b2World* world, const sf::Color color)
    : size(size)
    {
        type = paddle;
        //box2d paddle
        b2BodyDef body_def;
        body_def.type = b2_kinematicBody;
        body_def.position.Set(position.x / constants::scale_factor, position.y / constants::scale_factor);
        body_def.angle = 0;
        body_def.fixedRotation = true;

        b2PolygonShape paddle_shape;
        paddle_shape.SetAsBox(size.x / (2 * constants::scale_factor), size.y / (2 * constants::scale_factor));

        b2FixtureDef paddle_fixture_def;
        paddle_fixture_def.shape = &paddle_shape;
        paddle_fixture_def.density = 1;

        paddle_physics = world->CreateBody(&body_def);
        paddle_physics->CreateFixture(&paddle_fixture_def);
        paddle_physics->SetLinearVelocity(b2Vec2(velocity.x / constants::scale_factor, 
                                                 velocity.y / constants::scale_factor));
        //set user data for collision callback
        paddle_physics->SetUserData(this);

        //display paddle
        paddle_display.setPosition(position);
        paddle_display.setSize(size);
        paddle_display.setFillColor(color);

    }

    void Paddle::set_color(sf::Color color)
    {
        paddle_display.setFillColor(color);
    }

    void Paddle::set_color(int r, int g, int b)
    {
        sf::Color color(r, g, b);
        paddle_display.setFillColor(color);
    }

    void Paddle::set_velocity(sf::Vector2f velocity)
    {
        paddle_physics->SetLinearVelocity(b2Vec2(velocity.x / constants::scale_factor, 
                                          velocity.y / constants::scale_factor));
    }

    sf::Vector2f Paddle::get_velocity()
    {
        b2Vec2 velocity = paddle_physics->GetLinearVelocity();
        return sf::Vector2f(velocity.x, velocity.y);
    }

    sf::Vector2f Paddle::get_position()
    {
        b2Vec2 position = paddle_physics->GetPosition();
        //scale back up
        position.x *= constants::scale_factor;
        position.y *= constants::scale_factor;
        return sf::Vector2f(position.x, position.y);
    }



    void Paddle::start_contact(Shape* crashedWith)
    {
    }
    
    void Paddle::end_contact(Shape* crashedWith)
    {
    }

    void Paddle::update_display()
    {
        b2Vec2 position = paddle_physics->GetPosition();
        //scale back up
        position.x *= constants::scale_factor;
        position.y *= constants::scale_factor;
        
        paddle_display.setPosition(sf::Vector2f(position.x - size.x / 2, position.y - size.y / 2));
    }

    void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(paddle_display, states);
    }

    Paddle::~Paddle()
    {
        paddle_physics->GetWorld()->DestroyBody(paddle_physics);
    }
}