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
	void checkBoundary(sf::CircleShape);

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circle;
	sf::Vector2f direction;
	float speed;

	sf::CircleShape myPlayer;
	sf::Vector2f myPlayerDir;
	float myPlayerSpeed;

	sf::Vector2u screenBoundary;

	std::string speedStrng;
	sf::Font font;
	sf::Text text;

};