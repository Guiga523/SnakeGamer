#include "raylib.h"
#include "Snake.h"
#include <iostream>

int main() {
	const int wordWidth = 960;
	const int wordHeight = 540;
	InitWindow(wordWidth, wordHeight, "snake Game");
	SetTargetFPS(60);

	Snake snake;
	snake.width = 30;
	snake.height = 30;
	snake.color = DARKGREEN;

	snake.x = GetScreenWidth() / 2 - snake.width / 2;
	snake.y = GetScreenHeight() / 2 - snake.height / 2;

	Camera2D camera = { 0 };
	camera.target = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.rotation = 0.0f;	
	camera.zoom = 1.0f;

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_W)) {
			snake.y -= 30;
		}
		if (IsKeyPressed(KEY_S)) {
			snake.y += 30;
		}
		if (IsKeyPressed(KEY_A)) {
			snake.x -= 30;
		}
		if (IsKeyPressed(KEY_D)) {
			snake.x += 30;
		}


		if (IsKeyPressed(KEY_F11)) {
			int monitor = GetCurrentMonitor();
			if (IsWindowFullscreen()) {
				ToggleFullscreen();
				SetWindowSize(wordWidth, wordHeight);
			}
			else {
				SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
				ToggleFullscreen();
			}
		}
		camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

		BeginDrawing();
			ClearBackground(BLACK);

			BeginMode2D(camera);
				
				DrawRectangleLines(0, 0, wordWidth, wordHeight, DARKGRAY);
				DrawRectangle(snake.x, snake.y, snake.width, snake.height, snake.color);

		EndMode2D();

		DrawText("PLACA: 0 ", 10, 10, 20, WHITE);

	EndDrawing();
}

CloseWindow();
return 0;
}