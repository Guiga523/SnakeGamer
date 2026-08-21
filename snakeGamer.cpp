#include "raylib.h"
#include <iostream>

struct Snake{
	int x;
	int y;
	int width;
	int height;
	Color color;
};

int main() {
	InitWindow(960, 540, "snake Game");
	SetTargetFPS(60);

	Snake snake;
	snake.width = 30;
	snake.height = 30;
	snake.color = DARKGREEN;

	snake.x = GetScreenWidth() / 2 - snake.width / 2;
	snake.y = GetScreenHeight() / 2 - snake.height / 2;

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F11)) {
			ToggleFullscreen();
		}

		BeginDrawing();
			ClearBackground(BLACK);

			DrawRectangle(snake.x, snake.y, snake.width, snake.height, snake.color);

			DrawCircle(50, 50, 25, RED);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}