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
const sf::RectangleShape& Player::getShape() const
{
	// TODO: Insertar una instrucción "return" aquí
	return this->shape;
}
int Player::getHp()
{
	return this->hp;
}
int Player::getMaxHp()
{
	return this->maxHp;
}
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
void Player::takeDamage(int damage)
{
	if (this->hp > 0)
		this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::gainHealth(int health)
{
	if (this->hp < this->maxHp)
		this->hp += health;
	if (this->hp > this->maxHp)
		this->hp = this->maxHp;
}


//======= INIT =======
void Player::initVariables()
{
	this->speed = 10.f;
	this->hp = 10;
	this->maxHp = hp;
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
	//sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	//Left & Right
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	//Down & Top
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
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


