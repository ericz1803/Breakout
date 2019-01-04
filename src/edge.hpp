#ifndef EDGE_HPP
#define EDGE_HPP

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "shape.hpp"

namespace breakout
{
    class Edge : public Shape
    {
        public:
            Edge(sf::Vector2f top_left, sf::Vector2f size, b2World* world);
            ~Edge();
            
            void start_contact(Shape* crashedWith);
            void end_contact(Shape* crashedWith);
        
        private:
            b2Body* edge_body;
    };
}



#endif