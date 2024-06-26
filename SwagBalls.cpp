#include "SwagBalls.h"
//======= Constructor & Destructor =======
SwagBalls::SwagBalls(const sf::RenderWindow& window)
{
	this->initVariables();
	this->initShapes(window);
}
SwagBalls::SwagBalls(const sf::RenderWindow& window, int type)
	:type (type)
{
	this->initVariables();//Vacio
	this->initShapes(window);
	this->type = type;
}
SwagBalls::~SwagBalls()
{
}
//======= Sets & Gets =======
const sf::CircleShape SwagBalls::getShape() const
{
	return this->shape;
}

int SwagBalls::getType()
{
	return this->type ;
}

//======= FUNCIONES PRINCIPALES =======
void SwagBalls::upDate()
{
}
void SwagBalls::draw(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
//======= INIT =======
void SwagBalls::initVariables()
{
}
void SwagBalls::initShapes(const sf::RenderWindow& window)
{
	
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color;
	switch (this->type)
	{
	case DeFAULT:
		color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;
	case DAMEGING:
		color = sf::Color::Red;
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(2.F);
		break;
	case HEALING:
		color = sf::Color::Green;
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(2.F);
		break;
	}
	
	this->shape.setFillColor(color);
	this->shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
			static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
			)
	);
}
//======= FUNCIONES AUX =======


//======= UPDATE =======
	//	<Collision>
	//	<KeyBoard Press>
//======= DRAW =======

