#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "shape.hpp"

namespace breakout
{
    class Rectangle : public Shape, public sf::Drawable
    {
        public:
            Rectangle(const sf::Vector2f position, const sf::Vector2f size,
                      b2World* world, const sf::Color color = sf::Color::White);
            ~Rectangle();
            //position is top left of rectangle
            
            void start_contact(Shape* crashedWith);
            void end_contact(Shape* crashedWith);

            void set_color(sf::Color color);
            void set_color(int r, int g, int b);

            void update_display();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            
            bool remove;
        
        private:
            //full size of rectangle
            sf::Vector2f size;

            //physics rectangle
            b2Body* rectangle_physics;

            //display rectangle
            sf::RectangleShape rectangle_display;
    };
}

#endif