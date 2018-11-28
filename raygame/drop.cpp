#include "drop.h"

Drop::Drop()
{
	randomize();
	RECONSTRUCTIONS++;
	std::cout << "CONSTRUCTION " << RECONSTRUCTIONS << " COMPLETE out of " << MAX_DROPS << std::endl;
}


Drop::~Drop()
{
}

void Drop::randomize()
{
	length = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 50));
	focus = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1.5f));
	opacity = (unsigned char)GetRandomValue(0, 255);
	velocity = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / TERM_VEL));
	position = { (float)(GetRandomValue(0, GetScreenWidth())), (float)(GetRandomValue(-1000, -20)) };
	clampVel();
}

void Drop::fall()
{
	velocity;

	position.y += velocity;

	if (position.y > GetScreenHeight() + length) {
		position = { (float)(GetRandomValue(0, GetScreenWidth())), length * -1 };
		velocity = 0;
		randomize();
	}
}


void Drop::draw()
{
	if (!isFree) {
		DrawLineEx(position, { position.x, position.y + length }, focus, { 200, 122, 255, opacity });
	}
}

void Drop::clampVel()
{
	if (velocity < MIN_VEL)
		velocity = MIN_VEL;
	if (velocity > TERM_VEL)
		velocity = TERM_VEL;
}
