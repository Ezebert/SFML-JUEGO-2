#include "Player.h"
//======= Constructor & Destructor =======
Player::Player()
{
	this->initVariables();
	this->initShape();
}

Player::Player(float x, float y)
{
		this->initVariables();
		this->initShape();
		this->shape.setPosition(x,y);
}

Player::~Player()
{
}
//======= Sets & Gets =======
//======= FUNCIONES PRINCIPALES =======
void Player::update(sf::RenderTarget* target)
{
	this->updateInput();
	
}

void Player::draw(sf::RenderTarget* target)
{
	target->draw(this->shape);
}



//======= FUNCIONES AUX =======

//======= INIT =======
void Player::initVariables()
{
	this->speed = 10.f;
}
void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setScale(sf::Vector2f(0.5f, 0.5f)); //reduce tama�o)
}
//======= UPDATE <KeyBoard Press> =======
void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->shape.move(0.f, -this->speed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->shape.move(0.f, this->speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->shape.move(-this->speed, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->shape.move(this->speed, 0.f);
}
//======= DRAW =======
//Funciones Pricipales


