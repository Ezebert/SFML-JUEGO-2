#include "Player.h"
//======= Constructor & Destructor =======
Player::Player()
{
	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}
//======= Sets & Gets =======
//======= FUNCIONES PRINCIPALES =======
void Player::update()
{
}

void Player::draw(sf::RenderTarget* target)
{
	target->draw(this->shape);
}



//======= FUNCIONES AUX =======

//======= INIT =======
void Player::initVariables()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setScale(sf::Vector2f(0.5f, 0.5f)); //reduce tama�o)
}
void Player::initShape()
{
}
//======= UPDATE =======
//======= DRAW =======
//Funciones Pricipales


