#pragma once
#include <random>
#include "Graphics.h"

class BackGround
{
public:
	BackGround();
	~BackGround();
	void Go(Graphics& gfx);

private:
	void Draw(Graphics& gfx);
	std::mt19937 rnd;
	std::uniform_int_distribution<int>starx;
	std::uniform_int_distribution<int>stary;
	static constexpr int nStar = 200;
	int stars[nStar];
	int starsx[nStar];
	int starsy[nStar];	
};

