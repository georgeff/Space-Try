#pragma once
#include <random>
#include "Graphics.h"
class Explosion
{
public:
	Explosion();
	~Explosion();
	void Draw(Graphics&gfx);
private:
	std::mt19937 rnd1;
	std::uniform_real_distribution<float> velx;
	std::uniform_real_distribution<float> vely;
	float x;
	float y;
	float vx;
	float vy;
	static constexpr int nFlames = 50;
	int flames[nFlames];
};

