#pragma once
#include "Graphics.h"
#include "SpaceShip.h"
#include "MainWindow.h"
class deathStars
{
public:

	~deathStars();
	void Go(Graphics& gfx);
	void Init(int in_x, int in_y);

	int GetdeathStarx() { return deathStarx; }
	int GetdeathStary() { return deathStary; }
	void Draw(Graphics& gfx);
	bool DeathStarIsHit(int in_x, int in_y, int in_rad);
	bool DeathStarHits(int in_x, int in_y, int in_rad);

	bool isHit = false;

private:
	bool ChekForStrike();

	int deathStarx;
	int deathStary;
	int rad = 20;
	bool deathStarIsHit = false;

};

