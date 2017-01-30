#include "BackGround.h"
#include <time.h>


BackGround::BackGround():rnd(time(0)), stary(2, Graphics::ScreenHeight - 1),
                                      starx(2, Graphics::ScreenWidth - 1)
{
	for (int i = 0; i < nStar; i++)
	{
		starsx[i] = starx(rnd);
		starsy[i] = stary(rnd);
	}
}


BackGround::~BackGround()
{
}

void BackGround::Go(Graphics& gfx)
{
	Draw(gfx);
}

void BackGround::Draw(Graphics& gfx)
{
	for (int i = 0; i < nStar; i++)
	{
		if (starsy[i] > Graphics::ScreenHeight -1)
		{
			starsy[i] = 1;
		}
		gfx.PutPixel(starsx[i], starsy[i], Colors::Yellow);
		starsy[i]++;
		
	}
}



