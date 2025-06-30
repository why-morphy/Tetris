#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

#define SCREEN_HEIGHT 930
#define SCREEN_WIDTH 800
#define GAME_NAME "TETRISter"
#define FPS_LOCK 60

double lastUpdateTime = 0;
bool EventTriggered(double interval);

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(FPS_LOCK);

    Font font = LoadFontEx("fonts/PressStart2P-Regular.ttf", 64, 0, 0);
    Color background = {69, 31, 85, 255};
    Game game = Game();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggered(0.2)) game.MoveBlockDown();
        BeginDrawing();
        ClearBackground(background);

        //Draws
        DrawTextEx(font, "Score", {500, 55}, 50, 6, yellow);
        DrawTextEx(font, "Next", {520, 175}, 19, 2, yellow);
        if (game.gameover)
        {
            DrawTextEx(font, "Game", {520, 630}, 48, 4, yellow);
            DrawTextEx(font, "Over", {520, 680}, 48, 4, yellow);
        }
        DrawRectangleRounded({510, 135, 250, 90}, 0.3, 6, lightPurple);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {510 + (255 - textSize.x)/2, 160}, 38, 2, yellow);
        DrawRectangleRounded({510, 315, 240, 250}, 0.3, 6, lightPurple);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

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