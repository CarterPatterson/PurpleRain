#pragma once
#include "raylib.h"
#include "Globals.h"
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

class Drop
{
public:
	Drop();
	~Drop();

	void randomize();
	void fall();
	void draw();
	void clampVel();

	bool isFree = true;
	Vector2 position;
	unsigned char opacity;
	float length;
	float focus;
	float velocity = 0.00f;
};