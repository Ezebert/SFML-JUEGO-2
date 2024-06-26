#pragma once
#include <SFML/Graphics.hpp>
enum SwagBallsType { DeFAULT = 0, DAMEGING, HEALING, NROFTYPES };
class SwagBalls
{
private:
	//Variables
	sf::CircleShape shape;
	int type;
	//Game Clases
	//Windows
	//Mouse Posicion
	//Resources
	// 	//Text
public:
	//Constructor (Init_Variables / Windows / etc) 
	SwagBalls(const sf::RenderWindow& window);
	SwagBalls(const sf::RenderWindow& window, int type);
	~SwagBalls(); //Destructor
	//Sets & Gets
	const sf::CircleShape getShape()const;
	int getType();
	//Funciones Principales
	void upDate();	//<Collision>& <Keyboard Press>
	void draw(sf::RenderTarget&target);
	//Accesorios

protected:
	//Init
	void initVariables();
	void initShapes(const sf::RenderWindow&window);

	sf::Color changeColor();

	//Update Secundario
	//	<Collision>
	//	<KeyBoard Press>

	//Draw Secundario

};

void changeColor();
