#include "globals.h"

class Snake
{
private:
    Vector2 pos;
    Vector2 vel;

    struct body_part {
        Vector2 pos;
        Vector2 vel;
        Color colour;
    };
    std::vector<body_part> body;

public:
    Snake();
    void draw_snake();
    void turn_snake(int, int);
    void grow_snake();
    void update_snake();
    bool die_snake();
    Vector2 get_pos();
};

Snake::Snake()
{
    struct body_part new_part = {pos, vel};
    pos = Vector2({400,400});
    vel = Vector2({0,0});
    new_part.pos = pos;
    new_part.vel = vel;
    new_part.colour = BLUE;
    body.push_back(new_part);
}

void Snake::draw_snake()
{
    for (auto i: body )
    {
        DrawRectangle(i.pos.x,i.pos.y,grid_size,grid_size, i.colour);
    }
    
}

void Snake::turn_snake(int x, int y)
{
    x *= grid_size;
    y *= grid_size;

    body[0].vel = Vector2{float(x), float(y)};
}

void Snake::grow_snake()
{  
    Vector2 pos = Vector2{body.front().pos.x, body.front().pos.y};
    Vector2 vel = Vector2{body.front().vel.x, body.front().vel.y};
    struct body_part new_part = {pos, vel};
    new_part.pos = pos;
    new_part.vel = vel;
    new_part.colour = SKYBLUE;

    body.push_back(new_part);
}

void Snake::update_snake()
{ 
    for (int b = body.size()-1; b >= 1; b--)
    {
        body[b].pos = body[b-1].pos;
    }

    body.front().pos = Vector2Add(body.front().pos, body.front().vel);
}

bool Snake::die_snake()
{
    if (body.front().pos.x < 0 || body.front().pos.x >= screenWidth){ return true;}
    else if (body.front().pos.y < 0 || body.front().pos.y >= screenHeight){ return true;}
    
    for (int b = body.size()-1; b>0; b--)
    {
        if (body[b].pos == body.front().pos)
        {
            return true;
        }
    }

    return false;
}

Vector2 Snake::get_pos()
{
    return body.front().pos;
}