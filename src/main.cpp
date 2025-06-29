#include <raylib.h>
#include "game.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 300
#define GAME_NAME "TETRISter"
#define FPS_LOCK 60

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(FPS_LOCK);

    Color darkBlue = {44, 44, 127, 255};

    Game game = Game();

    while (!WindowShouldClose()) {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}