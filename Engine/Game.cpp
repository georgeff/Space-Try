/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	spaceShip(wnd),rnd(rd()), deathx(40,760), deathy(40,200)
{
	deathstars.Init(400, 30);
	for (int i = 0; i < ndeathstr; i++)
	{
		deathstr[i].Init(deathx(rnd), deathy(rnd));
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	for (int i = 0; i < ndeathstr; i++)
	{
		if (deathstr[i].DeathStarHits(spaceShip.GetShipx() + 400, spaceShip.GetShipy() + 560, 30))
		{
			shipIsHit = true;
		}
		if (deathstr[i].DeathStarIsHit(spaceShip.Getbulletx(), spaceShip.Getbullety(), spaceShip.GerBulletRad()))
		{
			deathstr[i].isHit = true;
			deathStarIsHit = true;
		}
	}
	if(spaceShip.BulletHasHit(deathstars.GetdeathStarx(), deathstars.GetdeathStary(), 20))
	{
		deathStarIsHit = true;
	}
	
}

void Game::ComposeFrame()
{
	bachground.Go(gfx);
	if (!shipIsHit)
	{
		spaceShip.Go(gfx);
	}
//	deathstars.Go(gfx);
	
	if (deathStarIsHit == false)
	{
//		deathstars.Draw(gfx);

	}
	for (int i = 0; i < ndeathstr; i++)
	{
//		if (!(deathstr[i].DeathStarIsHit(spaceShip.Getbulletx(), spaceShip.Getbullety(), spaceShip.GerBulletRad())))
		if(!deathstr[i].isHit)
		{
			deathstr[i].Draw(gfx);
		}
		
	}
	explosion.Draw(gfx);
}
