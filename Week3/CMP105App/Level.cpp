#include "Level.h"
#include <math.h>


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(15);
	circle.setOrigin(15, 15);
	circle.setPosition(100, 50);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2.f);
	direction = sf::Vector2f(10, 10);
	speed = 150.f;

	myPlayer.setRadius(15);
	myPlayer.setOrigin(15,15);
	myPlayer.setPointCount(5);
	myPlayer.setPosition(60, 60);
	myPlayer.setFillColor(sf::Color::Green);
	myPlayer.setOutlineColor(sf::Color::Black);
	myPlayer.setOutlineThickness(2.f);
	myPlayerDir = sf::Vector2f(0, 0);
	myPlayerSpeed = 150.f;
	
	screenBoundary = window->getSize();

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading Font\n";
	}
	speedStrng = "Speed: ";

	text.setFont(font);
	text.setString(speedStrng);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	screenBoundary = window->getSize();

	
	//Make the circle move right when right arrow is pressed
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		myPlayerDir.y = -2.f;
	}

	//Move Down
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		myPlayerDir.y = 2.f;
	}

	//Move Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		myPlayerDir.x = 2.f;
	}

	//Move Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		myPlayerDir.x = -2.f;
	}

	//If neither up or down dir.y is 0
	if (!input->isKeyDown(sf::Keyboard::Up) & !input->isKeyDown(sf::Keyboard::Down))
	{
		myPlayerDir.y = 0.f;
	}
	
	//If neither left or right dir.x is 0
	if (!input->isKeyDown(sf::Keyboard::Left) & !input->isKeyDown(sf::Keyboard::Right))
	{
		myPlayerDir.x = 0.f;
	}

	//If plus is pressed, increase speed
	if (input->isKeyDown(sf::Keyboard::Equal))
	{
		speed += 1;
	}

	//if - is pressed decrease speed
	if (input->isKeyDown(sf::Keyboard::Hyphen)& (speed > 0))
	{
		speed -= 1;
	}



}

// Update game objects
void Level::update(float dt)
{
	screenBoundary = window->getSize();

	//Circle x boundary conditions
	if((screenBoundary.x <= (circle.getPosition().x + circle.getRadius()))| ((circle.getPosition().x - circle.getRadius()) <= 0))
	{
		direction.x = direction.x * -1;
	}

	//Circle y boundary conditions
	if ((screenBoundary.y <= (circle.getPosition().y + circle.getRadius())) | ((circle.getPosition().y - circle.getRadius()) <= 0))
	{
		direction.y = direction.y * -1;
	}

	//Player y boundary conditions
	if ((myPlayer.getPosition().y + myPlayer.getRadius()) >= screenBoundary.y)
	{
		myPlayer.setPosition(myPlayer.getPosition().x, screenBoundary.y - myPlayer.getRadius());
	}
	else if ((myPlayer.getPosition().y - myPlayer.getRadius()) <= 0)
	{
		myPlayer.setPosition(myPlayer.getPosition().x, 0 + myPlayer.getRadius());
	}

	//Player x boundary conditions
	if ((myPlayer.getPosition().x + myPlayer.getRadius()) >= screenBoundary.x)
	{
		myPlayer.setPosition(screenBoundary.x - myPlayer.getRadius(), myPlayer.getPosition().y);
	}
	else if ((myPlayer.getPosition().x - myPlayer.getRadius()) <= 0)
	{
		myPlayer.setPosition(0 + myPlayer.getRadius(), myPlayer.getPosition().y);
	}

	speedStrng = "Speed: " + std::to_string(speed);
	text.setString(speedStrng);

	direction = normalise(direction);
	myPlayerDir = normalise(myPlayerDir);

	circle.move(speed * dt * direction);
	myPlayer.move(myPlayerSpeed * dt * myPlayerDir);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(myPlayer);
	window->draw(text);
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
	if ((dir.x == 0) & (dir.y == 0))
	{
		return dir;
	}

	dir = dir / (sqrt((dir.x * dir.x) + (dir.y * dir.y)));

	return dir;
	
}

void Level::checkBoundary(sf::CircleShape player)
{

}
