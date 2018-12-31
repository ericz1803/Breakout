#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace breakout
{
    class Shape
    {
        public:
            enum ObjectType { ball, brick, paddle, edge } type;
            virtual void start_contact(Shape* crashedWith) = 0;
            virtual void end_contact(Shape* crashedWith) = 0;
    };
}

#endif