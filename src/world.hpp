#ifndef WORLD_HPP
#define WORLD_HPP

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

namespace breakout
{
    class World
    {
        public:
            World();
            ~World();
            b2World* b2world;
            ContactListener contact_listener;
            Edge* edge;
            std::vector<Rectangle*> bricks;
            Paddle* paddle;
            Ball* ball;
            void step(float32 time_step, int32 velocity_iterations, int32 position_iterations);
            void update_display(int* score);
            void draw(sf::RenderWindow* window);
            void reset();
            void reset_bricks();
            void reset_ball();
            void set_paddle_velocity(float velocity);
    };
}


#endif