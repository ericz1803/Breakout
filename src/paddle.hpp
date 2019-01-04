#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "shape.hpp"

namespace breakout
{
    class Paddle : public Shape, public sf::Drawable
    {
        public:
            Paddle(const sf::Vector2f position, const sf::Vector2f size, const sf::Vector2f velocity,
                   b2World* world, const sf::Color color = sf::Color::White);
            ~Paddle();
            //position is top left of paddle

            void set_velocity(sf::Vector2f velocity);
            sf::Vector2f get_velocity();
            sf::Vector2f get_position();
            sf::Vector2f get_size();
            void start_contact(Shape* crashedWith);
            void end_contact(Shape* crashedWith);

            void set_color(sf::Color color);
            void set_color(int r, int g, int b);

            void update_display();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        private:
            //physics rectangle
            b2Body* paddle_physics;
            
            //full size of paddle (pixels)
            sf::Vector2f size;

            //display rectangle
            sf::RectangleShape paddle_display;
    };
}

#endif