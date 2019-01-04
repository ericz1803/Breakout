#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constants
{
    //scale factor for physics
    const float scale_factor = 100.0f;

    //velocity limits for ball
    const float upper_ball_velocity_y = 1200.0f;
    const float lower_ball_velocity_y = 250.0f;

    //pixels from top for ball to bounce
    const float top_edge = 20.0f;

    const int fps = 120;
    //size of screen
    const int width = 800;
    const int height = 1050;
    
    //paddle velocity (physics not pixels)
    const float paddle_velocity = 500.0f;
}

#endif