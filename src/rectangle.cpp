#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Rectangle.hpp"
#include "shape.hpp"
#include "constants.hpp"
#include <iostream>

namespace breakout
{
    Rectangle::Rectangle(const sf::Vector2f position, const sf::Vector2f size,
                         b2World* world, const sf::Color color)
    : size(size)
    {
        remove = false;
        type = brick;

        b2BodyDef body_def;
        body_def.type = b2_staticBody;
        body_def.position.Set(position.x / constants::scale_factor, position.y / constants::scale_factor);
        body_def.angle = 0;
        //set size of rectangle (half width and half height)

        b2PolygonShape box_shape;
        
        box_shape.SetAsBox(size.x / (2 * constants::scale_factor), size.y / (2 * constants::scale_factor));
        
        b2FixtureDef box_fixture_def;
        box_fixture_def.shape = &box_shape;

        rectangle_physics = world->CreateBody(&body_def);
        rectangle_physics->CreateFixture(&box_fixture_def);
        
        //set user data for collision callback
        rectangle_physics->SetUserData(this);

        //display rectangle
        rectangle_display.setPosition(position);
        rectangle_display.setSize(size);
        rectangle_display.setFillColor(color);
        rectangle_display.setOutlineColor(sf::Color::Black);
        rectangle_display.setOutlineThickness(1.0f);    
    }

    void Rectangle::set_color(sf::Color color)
    {
        rectangle_display.setFillColor(color);
    }

    void Rectangle::set_color(int r, int g, int b)
    {
        sf::Color color(r, g, b);
        rectangle_display.setFillColor(color);
    }

    void Rectangle::start_contact(Shape* crashedWith)
    {
    }

    void Rectangle::end_contact(Shape* crashedWith)
    {
        remove = true;
    }

    void Rectangle::update_display()
    {
        b2Vec2 position = rectangle_physics->GetPosition();
        //scale back up
        position.x *= constants::scale_factor;
        position.y *= constants::scale_factor;
        
        rectangle_display.setPosition(sf::Vector2f(position.x - (size.x / 2), position.y - (size.y / 2)));
    }

    void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rectangle_display, states);
    }

    Rectangle::~Rectangle()
    {
        rectangle_physics->GetWorld()->DestroyBody(rectangle_physics);
    }
}