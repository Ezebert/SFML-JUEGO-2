#pragma once
#include <SFML/Graphics.hpp>
class SwagBalls
{
private:
	//Variables
	sf::CircleShape shape;
	//Game Clases
	//Windows
	//Mouse Posicion
	//Resources
	// 	//Text
public:
	//Constructor (Init_Variables / Windows / etc) 
	SwagBalls(const sf::RenderWindow& window);
	~SwagBalls(); //Destructor
	//Sets & Gets
	const sf::CircleShape getShape()const;
	//Funciones Principales
	void upDate();	//<Collision>& <Keyboard Press>
	void draw(sf::RenderTarget&target);
	//Accesorios

protected:
	//Init
	void initVariables();
	void initShapes(const sf::RenderWindow&window);
	//Update Secundario
	//	<Collision>
	//	<KeyBoard Press>

	//Draw Secundario

};

