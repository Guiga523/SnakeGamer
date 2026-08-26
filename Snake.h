#pragma once
#include "raylib.h"
#include <Vector>

struct Snake {
	int x;
	int y;
	int width;
	int height;
	Color color;
	int speedX;
	int speedY;
	std::vector<Vector2> body;
};

