#include "SpaceShip.h"


SpaceShip::SpaceShip(MainWindow& wnd):wnd(wnd), bulletx(0), bullety(0),
gfx(wnd)//, deathstars(wnd)
{
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::Go(Graphics& gfx)
{
	Move();   // move must be first
	Shoot(gfx);	
	Draw(gfx);	
}

void SpaceShip::Draw(Graphics& gfx)
{
	int sum = 100;
	for (int j = 100; j < 150; j++)
	{
		for (int i = sum; i < 100;i++ )
		{				 
			 		gfx.PutPixel(i / 2 + 350 + shipx, j + 430, Colors::Red);		
		}
		sum = sum - 1;
	}
	for (int jk = 200; jk < 250; jk++)
	{
		for (int ik = sum; ik < 100; ik++)
		{
			gfx.PutPixel(jk / 2 + 300 + shipx, ik + 480, Colors::Red);
		}
		sum = sum + 1;;
	}
	if (bulletIsOnTheWay == false)
	{
		bulletx = shipx + 400;
	}
	if (bulletIsOnTheWay == true)
	{
		bulletStorex = shipx;
	}
	gfx.PutPixel(shipx + 400, shipy + 560, Colors::Green);
	gfx.PutPixel(bulletx, 340, Colors::Blue);	
}

void SpaceShip::DrawBullet(Graphics & gfx)
{
	//	bulletx = bulletStorex;
	for (int i = bullety - bulletrad; i < bullety + bulletrad ; i++)
	{
		for (int j = bulletx - bulletrad; j < bulletx + bulletrad; j++)
		{
			if (((bulletx - j)*(bulletx - j)) + ((bullety - i)*(bullety - i)) < bulletrad*bulletrad)
			{							
				if (i<Graphics::ScreenHeight&&i>0)
				{
					gfx.PutPixel(j, i, 255, 0, 0);
				}
				j++;				
			}
		}
	}
}

void SpaceShip::Move()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		shipx += shipVelocity;
		if (400 + shipx>760)
		{
			shipx = 360;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		shipx -= shipVelocity;
		if (400 + shipx <=40)
		{
			shipx = -360;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		bulletIsOnTheWay = true;
	}
}

void SpaceShip::Shoot(Graphics& gfx)
{
	if (bullety < 20)
	{
		bullety = 540;
		bulletIsOnTheWay = false;
	}
	if (bulletIsOnTheWay//&&(BulletHasHit(deathstars.GetdeathStarx(), deathstars.GetdeathStary(), 20))
		)
	{
		DrawBullet(gfx);
		bullety += bulletVelocit;
		bulletx == bulletStorex;    //dont forget the ==
	}
	else
	{
		bulletx == bulletx;
	}
}

bool SpaceShip::BulletHasHit(int in_x, int in_y, int in_rad)
{
	/*dx = in_x - bulletx;
	dy = in_y - bullety;*/
	return
				((((bulletx - in_x) * (bulletx - in_x)) + ((bullety - in_y) * (bullety - in_y))) < ((in_rad + bulletrad) * (in_rad + bulletrad)));

	//	((dx*dx) + (dy*dy) < (in_rad + bulletrad) * (in_rad + bulletrad));
}

