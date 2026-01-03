#include "globals.h"


 void draw_grid(){
    for (int x=0; x < screenWidth; x += grid_size){
        for (int y = 0; y < screenHeight; y += grid_size){
            DrawLine(x,0, x, screenHeight, WHITE);
        }
        DrawLine(0,x, screenWidth,x, WHITE);
    }
    
 };

 void toggle_paused()
 {
    if (game_state == State::g_play) { game_state = State::g_paused; }
    else if (game_state == State::g_paused) { game_state = State::g_play; }
 }

 
void key_pressed()
{
    if (game_state == State::g_play)
    {
        if (IsKeyPressed(KEY_P)) game_state = State::g_paused;
        if (IsKeyPressed(KEY_RIGHT))s.turn_snake(1,0);
        if (IsKeyPressed(KEY_LEFT))s.turn_snake(-1,0);
        if (IsKeyPressed(KEY_DOWN))s.turn_snake(0,1);
        if (IsKeyPressed(KEY_UP))s.turn_snake(0,-1);
    }

    if (game_state == State::g_start)
    {
        if (IsKeyPressed(KEY_S)) game_state = State::g_play;
    }

    if (game_state == State::g_end)
    {
        if (IsKeyPressed(KEY_M)) game_state = State::g_start;
    }

    if (game_state == State::g_paused)
    {
        if (IsKeyPressed(KEY_R)) game_state = State::g_play;
    }
}


void eat_food()
{
        if (s.get_pos().x == f.get_pos().x && s.get_pos().y == f.get_pos().y)
        {
            f.move_food();
            s.grow_snake();
            score += 1;
        }
}

void game_over()
{
    DrawText("Game Over !", 300, 200, 40, RED);
    DrawText(TextFormat("Final Score: %03i", score), 300 , 250, 30, YELLOW);
    DrawText("Press M for Menu", 270, 350,30, RED);
}

void game_paused()
{
    DrawText("Game  Paused", 250, 200, 40, RED);
    DrawText("R - Restart Play", 200, 300, 40, RED);
}

void game_menu()
{
    DrawText("Snake Main Menu", 250, 100, 40, BLUE);
    DrawText("S   - Start Play", 100,200,20, SKYBLUE);
    DrawText("Esc - QUIT to Desktop",100,230,20, SKYBLUE);

}

void draw_game()
{
    DrawText(TextFormat("Score: %03i", score), 10, 10, 20, YELLOW);
    s.draw_snake();
    f.draw_food();
}

int main(void)
{
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Snake");
    
    SetTargetFPS(7);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch(game_state) {

            case State::g_start:
                game_menu();
                break;

            case State::g_paused:
                game_paused();
                break;

            case State::g_play:
                s.update_snake();
                if (s.die_snake() == true)
                { 
                    game_state = State::g_end;
                }
                eat_food();
                draw_game(); 
                break;

            case State::g_end:
                game_over();
                break;
        }
        key_pressed();

        EndDrawing();
  
    }

    CloseWindow();
    return 0;
}
