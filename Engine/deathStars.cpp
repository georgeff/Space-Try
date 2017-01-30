#include "deathStars.h"






deathStars::~deathStars()
{
}

void deathStars::Go(Graphics & gfx)
{
	Draw(gfx);
}

void deathStars::Init(int in_x, int in_y)
{
	deathStarx = in_x;
	deathStary = in_y;

}

void deathStars::Draw(Graphics & gfx)
{
	for (int i = deathStary - rad; i < deathStary + rad; i++)
	{
		for (int j = deathStarx - rad; j < deathStarx + rad; j++)
		{
			if (((deathStarx - j)*(deathStarx - j)) + ((deathStary - i)*(deathStary - i)) < rad*rad)
			{
				if (i<Graphics::ScreenHeight&&i>0)
				{
					gfx.PutPixel(j, i, 255, 0, 0);
				}
			}
		}
	}
	deathStary++;
}

bool deathStars::DeathStarIsHit(int in_x, int in_y, int in_rad)
{
	return 
		((((deathStarx - in_x) * (deathStarx - in_x)) + ((deathStary - in_y) * (deathStary - in_y)))
			< ((in_rad + rad) * (in_rad + rad)));

}

bool deathStars::DeathStarHits(int in_x, int in_y, int in_rad)
{
	return
		((((deathStarx - in_x) * (deathStarx - in_x)) + ((deathStary - in_y) * (deathStary - in_y)))
			< ((in_rad + rad) * (in_rad + rad)));
}

