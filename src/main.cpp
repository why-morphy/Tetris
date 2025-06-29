#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

#define SCREEN_HEIGHT 620
#define SCREEN_WIDTH 500
#define GAME_NAME "TETRISter"
#define FPS_LOCK 60

double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(FPS_LOCK);

    Font font = LoadFontEx("fonts/PressStart2P-Regular.ttf", 64, 0, 0);

    Color darkBlue = {44, 44, 127, 255};

    Game game = Game();

    while (!WindowShouldClose()) {

        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {355, 15}, 19, 2, WHITE);
        DrawTextEx(font, "Next", {355, 175}, 19, 2, WHITE);
        if (game.gameover)
        {
            DrawTextEx(font, "Game", {340, 450}, 32, 2, WHITE);
            DrawTextEx(font, "Over", {340, 485}, 32, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 70}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}