#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::RectangleShape shape;
public:
	//Constructor y Destructor
	Player();
	~Player();
	//Sets & Gets
	//Funciones Pricipales
	void update();
	void draw(sf::RenderTarget * target);
	
	//Funciones Aux
protected:
	//init
	void initVariables();
	void initShape();
	//Update
	//Draw
	
};


