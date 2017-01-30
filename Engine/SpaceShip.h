#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "deathStars.h"
class SpaceShip
{
public:
	SpaceShip(MainWindow& wnd);
	~SpaceShip();
	void Go(Graphics& gfx);
	bool BulletHasHit(int in_x, int in_y, int in_rad);

	int Getbulletx() { return bulletx; }
	int Getbullety() { return bullety; }
	int GerBulletRad() { return bulletrad; }

	int GetShipx() { return shipx; }
	int GetShipy() { return shipy; }
	
private:
	void Draw(Graphics& gfx);
	void DrawBullet(Graphics& gfx);
	void Move();
	void Shoot(Graphics& gfx);

	int shipx = 0;
	int shipy = 0;
	int shipVelocity = 2;
	int bulletx;
	int bullety;
	int bulletrad = 10;
	int bulletVelocit = -6;
	int bulletStorex;
	bool shootBullet = false;
	bool bulletIsOnTheWay = false;
	int dx;
	int dy;
	MainWindow& wnd;
	Graphics gfx;
	
};

