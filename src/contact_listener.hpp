#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP

#include <Box2D/Box2D.h>
#include "rectangle.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include <iostream>
#include "shape.hpp"
#include <typeinfo>

namespace breakout
{
    class ContactListener : public b2ContactListener
    {
        void EndContact(b2Contact* contact) {

            //call end_contact function of both objects
            Shape* bodyUserDataA = static_cast<Shape*>(contact->GetFixtureA()->GetBody()->GetUserData());
            Shape* bodyUserDataB = static_cast<Shape*>(contact->GetFixtureB()->GetBody()->GetUserData());
            bodyUserDataA->end_contact(bodyUserDataB);
            bodyUserDataB->end_contact(bodyUserDataA);
        }
    };

}

#endif