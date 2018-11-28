/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "drop.h"
#include <string>
#include <ctime>
#include <iostream>

float GRAVITY = 0.50f;
float MIN_VEL = 6.00f;
float TERM_VEL = 12.00f;
int MAX_DROPS = 8000;
int FREE_DROPS = MAX_DROPS;
unsigned long long int RECONSTRUCTIONS = 0;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 2000;
	int screenHeight = 1100;

	srand(static_cast <unsigned> (time(0)));


	InitWindow(screenWidth, screenHeight, "raylib [core] example - Purple Rain");

	Drop *drops = new Drop[MAX_DROPS];

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		
		//if (IsKeyDown(KEY_UP)) {
			for (int i = 0; i < MAX_DROPS; i++) {
				if (drops[i].isFree) {
					drops[i].isFree = false;
					FREE_DROPS--;
					break;
				}
			}
		//}

		if (IsKeyDown(KEY_DOWN)) {
			for (int i = FREE_DROPS; i >= 0; i--) {
				if (!drops[i].isFree) {
					drops[i].isFree = true;
					FREE_DROPS++;
					break;
				}
			}
		}

		std::cout << "MAX DROPS: " << MAX_DROPS << std::endl;
		std::cout << "FREE DROPS: " << FREE_DROPS << std::endl;

		for (int i = 0; i < MAX_DROPS; i++) {
			drops[i].fall();
		}

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(DARKPURPLE);


		for (int i = 0; i < MAX_DROPS; i++) {
			drops[i].draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}