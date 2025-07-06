#include "Duck.h"

Duck::Duck()
{
	//setup duck
	//green box outline
	globalBounds.setFillColor(sf::Color::Transparent);
	globalBounds.setOutlineColor(sf::Color::Green);
	globalBounds.setOutlineThickness(2.0f);
	globalBounds.setSize(sf::Vector2f(30.0f, 30.0f));
	globalBounds.setOrigin(15.0f, 15.0f);
	globalBounds.setPosition(location);
}

void Duck::update()
{
	move();
}

sf::RectangleShape Duck::getBody()
{
	return sf::RectangleShape(globalBounds);
}

void Duck::move()
{
	//add speed to move duck. If speed negetive location will reduce 
	location.x += xspeed;
	location.y += yspeed;

	//move duck to that position on screen
	globalBounds.setPosition(location);

	//bounce off walls
	if (location.x + globalBounds.getOrigin().x >= SCREEN_WIDTH || location.x - globalBounds.getOrigin().x <= 0)
	{
		//if negetive, become positive and vice versa. Result: Direction change
		xspeed *= -1;
	}
	//bounce off top and bottom border
	if (location.y + globalBounds.getOrigin().y >= BOTTOM_BORDER || location.y - globalBounds.getOrigin().y <= 0)
	{
		//if negetive, become positive and vice versa. Result: Direction change
		yspeed *= -1;
	}
}
