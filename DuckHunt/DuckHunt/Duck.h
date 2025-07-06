#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"

//duck data
class Duck
{
private:
	//horizontal movement
	int xspeed = 1;
	//vertical speed
	int yspeed = 1;
	//default spawn in the middle of the screen
	sf::Vector2f location{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};

	//duck hitbox
	sf::RectangleShape globalBounds{};

public:
	//default constructor
	Duck();
	//update information
	void update();

	//return duck body
	sf::RectangleShape getBody(); //temporary until sprite is added
	
	//move duck
	void move();
};