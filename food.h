#include "globals.h"

class Food
{
private:
    Vector2 pos;

public:
    Food();
    void draw_food();
    void move_food();
    Vector2 get_pos();

};

Food::Food()
{
    int posX = rand() % screenWidth / grid_size * grid_size;
    int posY = rand() % screenHeight / grid_size * grid_size;

    pos = Vector2{float(posX), float(posY)};
};

void Food::move_food()
{
    pos.x = rand() % screenWidth / grid_size * grid_size;
    pos.y = rand() % screenHeight / grid_size * grid_size;

}

void Food::draw_food()
{
    DrawRectangle(pos.x,pos.y,grid_size,grid_size, GREEN);
}

Vector2 Food::get_pos()
{
    return pos;
}

