#include "Explosion.h"
#include <time.h>



Explosion::Explosion():rnd1(time(0)), velx(-1.0,1.0f), vely(-1.0f, 1.0f)  //from smaller to bigger int he distribution
{
	for (int i = 0; i < nFlames; i++)
	{
		/*flames[i] = velx(rnd1);
		flames[i] = vely(rnd1);*/
	}
}
Explosion::~Explosion()
{
}

void Explosion::Draw(Graphics&gfx)
{
//	x += velx;
	/*x = in_x;
	y = in_y;*/
	for (int i = 0; i < nFlames; i++)
	{
		/*flames[i] = velx(rnd);
		flames[i] = vely(rnd);*/
//		gfx.PutPixel(300 + velx, 300 + vely, Colors::Red);
	}
}
