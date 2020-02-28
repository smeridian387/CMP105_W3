#include <iostream>
#include "Level.h"
using namespace std;
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(20);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2);
	circle.setPosition(30, 30);
	circle.setOrigin(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2);
	speed = 100.0f;
	direction = sf::Vector2f(1.0f,1.0f);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		direction.y = -1.0f;
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		direction.y = 1.0f;
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		direction.x = -1.0f;
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		direction.x = 1.0f;
	}
	else
	{
		direction = sf::Vector2f(0.0f, 0.0f);
	}
	
}

// Update game objects
void Level::update(float dt)
{
	Velocity = sf::Vector2f(speed * direction.x, speed*direction.y);
	
	if (circle.getPosition().x >= (window->getSize().x -20))
	{
		circle.setPosition(sf::Vector2f((window->getSize().x - 20), circle.getPosition().y));
	}
	else if (circle.getPosition().x <= 20.0f)
	{
		circle.setPosition(sf::Vector2f(20.0f, circle.getPosition().y));
	}
	if (circle.getPosition().y >= (window->getSize().y - 20))
	{
		circle.setPosition(sf::Vector2f(circle.getPosition().x, (window->getSize().y - 20)));
	}
	else if (circle.getPosition().y <= 20.0f)
	{
		circle.setPosition(sf::Vector2f(circle.getPosition().x, 20.0f));
	}

	circle.move(Velocity.x * dt, Velocity.y*dt);

	cout << "window size X : " << window->getSize().x << "window size Y :" << window->getSize().y << endl;
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
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