#include "Level.h"
#include <math.h>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(15);
	circle.setPosition(50, 50);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2.f);

	myPlayer.setRadius(15);
	myPlayer.setPointCount(5);
	myPlayer.setPosition(50, 50);
	myPlayer.setFillColor(sf::Color::Green);
	myPlayer.setOutlineColor(sf::Color::Black);
	myPlayer.setOutlineThickness(2.f);

	speed2 = 100.f;
	speed = 50.f;
	direction = sf::Vector2f(10, 10);

	screenBoundary = window->getSize();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	screenBoundary = window->getSize();


	//sf::Event event;
	//while (window->pollEvent(event))
	//{
	//	switch (event.type)
	//	{
	//	case sf::Event::KeyPressed:
	//		input->setKeyDown(event.key.code);
	//		break;
	//	case sf::Event::KeyReleased:
	//		input->setKeyUp(event.key.code);
	//		break;
	//	}
	//}






	/*
	Make the circle move right when right arrow is pressed
	*/


	if (input->isKeyDown(sf::Keyboard::Up))
	{
		direction2.y = 2.f;
	}


	myPlayer.move
	/*else if (input->isKeyDown(sf::Keyboard::Down))
	{
		input->setKeyUp(sf::Keyboard::Down);
		direction2.y = 2.f;
	}
	else
	{
		direction2.y = 0.f;
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		direction2.x = -2.f;
	}
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		direction2.x = 2.f;
	}
	else
	{
		direction2.x = 0.f;
	}
*/



}

// Update game objects
void Level::update(float dt)
{
	screenBoundary = window->getSize();
	circlePos = circle.getPosition();

	if((screenBoundary.x <= (circlePos.x + circle.getRadius()))| ((circlePos.x + circle.getRadius()) <= 0))
	{
		circlePos.x = screenBoundary.x;
		direction.x = direction.x * -1;
	}

	if ((screenBoundary.y <= (circlePos.y + circle.getRadius())) | ((circlePos.y + circle.getRadius()) <= 0))
	{
		circlePos.y = screenBoundary.y;
		direction.y = direction.y * -1;
	}

	if ((screenBoundary.x <= (circle2Pos.x + myPlayer.getRadius())) | ((circle2Pos.x + myPlayer.getRadius()) <= 0))
	{
		circle2Pos.x = screenBoundary.x;
		direction2.x = direction2.x * -1;
	}

	if ((screenBoundary.y <= (circle2Pos.y + myPlayer.getRadius())) | ((circle2Pos.y + myPlayer.getRadius()) <= 0))
	{
		circle2Pos.y = screenBoundary.y;
		direction2.y = direction2.y * -1;
	}


	direction = normalise(direction);
	direction2 = normalise(direction2);

	circle.move(speed * dt * direction);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(myPlayer);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{

	window->display();
}

sf::Vector2f Level::normalise(sf::Vector2f dir)
{
	return dir/ (sqrt((dir.x * dir.x) + (dir.y * dir.y)));
}
