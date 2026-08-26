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

	snake.speedX = 0;
	snake.speedY = 0;

	snake.body.push_back({ (float)snake.x - snake.width, (float)snake.y });
	snake.body.push_back({ (float)snake.x - snake.width * 2, (float)snake.y });
	snake.body.push_back({ (float)snake.x - snake.width * 2, (float)snake.y });
	snake.body.push_back({ (float)snake.x - snake.width * 3, (float)snake.y });
	snake.body.push_back({ (float)snake.x - snake.width * 4, (float)snake.y });

	Camera2D camera = { 0 };
	camera.target = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.rotation = 0.0f;	
	camera.zoom = 1.0f;

	int framesCounter = 0;

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_W) && snake.speedY == 0) {
			snake.speedX = 0;
			snake.speedY = -snake.height;
		}
		if (IsKeyPressed(KEY_S) && snake.speedY == 0) {
			snake.speedX = 0;
			snake.speedY = snake.height;
		}
		if (IsKeyPressed(KEY_A) && snake.speedX == 0) {
			snake.speedX = -snake.width;
			snake.speedY = 0;
		}
		if (IsKeyPressed(KEY_D) && snake.speedX == 0) {
			snake.speedX = snake.width;
			snake.speedY = 0;
		}
		framesCounter++;

		if (framesCounter >= 15) {
			for (int i = snake.body.size() - 1; i > 0; i--) {
				snake.body[i] = snake.body[i - 1];
			}
			if (snake.body.size() > 0) {
				snake.body[0] = { (float)snake.x, (float)snake.y };
			}

			snake.x += snake.speedX;
			snake.y += snake.speedY;

			framesCounter = 0;
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

				for (int i = 0; i < snake.body.size(); i++) {
					DrawRectangle(snake.body[i].x, snake.body[i].y, snake.width, snake.height, GREEN);
					DrawRectangleLines(snake.body[i].x, snake.body[i].y, snake.width, snake.height, BLACK);
				}

				DrawRectangle(snake.x, snake.y, snake.width, snake.height, snake.color);

		EndMode2D();

		DrawText("PLACA: 0 ", 10, 10, 20, WHITE);

	EndDrawing();
}

CloseWindow();
return 0;
}