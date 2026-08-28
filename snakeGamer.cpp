#include "raylib.h"
#include "Snake.h"
#include <iostream>

int main() {
	const int wordWidth = 960;
	const int wordHeight = 540; 
	const int sizegrid = 30;

	InitWindow(wordWidth, wordHeight, "snake Game");
	SetTargetFPS(60);

	Snake snake;
	snake.width = 30;
	snake.height = 30;
	snake.color = DARKGREEN;

	snake.x = wordWidth/ 2;
	snake.y = wordHeight / 2;

	snake.speedX = 0;
	snake.speedY = 0;

	snake.body.push_back({ (float)snake.x - snake.width, (float)snake.y });
	snake.body.push_back({ (float)snake.x - snake.width * 2, (float)snake.y });

	Camera2D camera = { 0 };
	camera.target = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.rotation = 0.0f;	
	camera.zoom = 1.0f;

	float appleX = 200.0f;
	float appleY = 200.0f;
	float appleRay = 12.0f;

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

		Rectangle snakeHead = { (float)snake.x, (float)snake.y, (float)snake.width, (float)snake.height };

		Vector2 appleCore = { appleX, appleY };

		if (CheckCollisionCircleRec(appleCore, appleRay, snakeHead)) {
			Vector2 lastPiece = snake.body[snake.body.size() - 1];
			snake.body.push_back(lastPiece);

			int feasibleSchedule = wordWidth / sizegrid;
			appleX = GetRandomValue(0, feasibleSchedule - 1) * sizegrid;

			int possibleLine = wordHeight / sizegrid;
			appleY = GetRandomValue(0, possibleLine - 1) * sizegrid;
		}

		if (IsKeyPressed(KEY_F11)) {
			int monitor = GetCurrentMonitor();
			camera.zoom = 1.8f;
			if (IsWindowFullscreen()) {
				ToggleFullscreen();
				camera.zoom = 0.9f;
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

				for (int i = 0; i <= wordWidth; i += sizegrid) {
					DrawLine(i, 0, i, wordHeight, ColorAlpha(DARKGRAY, 0.5f));
				}
				for (int i = 0; i <= wordHeight; i += sizegrid) {
					DrawLine(0, i, wordWidth, i, ColorAlpha(DARKGRAY, 0.5f)); 
				}

				for (int i = 0; i < snake.body.size(); i++) {
					DrawRectangle(snake.body[i].x, snake.body[i].y, snake.width, snake.height, GREEN);
					DrawRectangleLines(snake.body[i].x, snake.body[i].y, snake.width, snake.height, BLACK);
				}

				DrawRectangle(snake.x, snake.y, snake.width, snake.height, snake.color);
				DrawCircle(appleX + (sizegrid / 2), appleY + (sizegrid / 2), appleRay, RED);

				
				EndMode2D();

			DrawText("SCORE: 0 ", 10, 10, 20, WHITE);

		EndDrawing();
}

CloseWindow();
return 0;
}