#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "edge.hpp"
#include "shape.hpp"
#include "constants.hpp"
namespace breakout
{
    Edge::Edge(sf::Vector2f top_left, sf::Vector2f size, b2World* world)
    {
        type = edge;
        
        b2BodyDef edge_body_def;
        edge_body_def.type = b2_staticBody;
        edge_body_def.position.Set(top_left.x / constants::scale_factor, top_left.y / constants::scale_factor);

        //define edge shape with 4 vertices
        b2Vec2 edge[4];
        edge[0].Set(top_left.x / constants::scale_factor, top_left.y / constants::scale_factor);
        edge[1].Set((top_left.x + size.x) / constants::scale_factor, top_left.y / constants::scale_factor);
        edge[2].Set((top_left.x + size.x) / constants::scale_factor, (top_left.y + size.y)/ constants::scale_factor);
        edge[3].Set(top_left.x / constants::scale_factor, (top_left.y + size.y) / constants::scale_factor);
        b2ChainShape chain;
        chain.CreateLoop(edge, 4);

        b2FixtureDef edge_fixture_def;
        edge_fixture_def.shape = &chain;
        edge_fixture_def.restitution = 1.0f;

        edge_body =  world->CreateBody(&edge_body_def);
        edge_body->CreateFixture(&edge_fixture_def);
        edge_body->SetUserData(this);
    }


    void Edge::start_contact(Shape* crashedWith)
    {
    }
    

    void Edge::end_contact(Shape* crashedWith)
    {
    }


    Edge::~Edge()
    {
        edge_body->GetWorld()->DestroyBody(edge_body);
    }
}