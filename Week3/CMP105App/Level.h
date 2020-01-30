#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	sf::Vector2f normalise(sf::Vector2f);

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circle;
	float speed;
	sf::Vector2f direction;
	sf::Vector2f circlePos;

	sf::CircleShape myPlayer;
	sf::Vector2f direction2;
	sf::Vector2f circle2Pos;
	float speed2;

	sf::Vector2u screenBoundary;

	bool keys[256];
};