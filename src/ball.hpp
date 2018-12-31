#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "shape.hpp"

namespace breakout
{
    class Ball : public Shape, public sf::Drawable 
    {
        public:
            Ball(const sf::Vector2f position, const float r, const sf::Vector2f velocity, 
                 b2World* world, const sf::Color color = sf::Color::White);
            ~Ball();
            //functions
            void set_color(sf::Color color);
            void set_color(int r, int g, int b);
            void update_display();
            void start_contact(Shape* crashedWith);
            void end_contact(Shape* crashedWith);
            sf::Vector2f get_position();

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            

        private:
            b2Body* circle_physics;
            float r;
            
            //visuals
            sf::CircleShape circle_display;
    };
}
#endif