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
	this->updateWindowsBoundsCollision(target);
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
//======= UPDATE <Collision> =======
void Player::updateWindowsBoundsCollision(sf::RenderTarget* target)
{	//Left = x and Top = y | Coordenadas FloatRect
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	//Left & Right
	if (playerBounds.left < 0.f)
		this->shape.setPosition(0.f, playerBounds.top);
	else if (playerBounds.left + playerBounds.width > target->getSize().x)
		this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	//Down & Top
	if (playerBounds.top < 0.f)
		this->shape.setPosition(playerBounds.left, 0.f);
	else if (playerBounds.top + playerBounds.height > target->getSize().y)
		this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
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


