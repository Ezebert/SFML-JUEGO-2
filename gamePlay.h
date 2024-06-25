#pragma once
#include <SFML/Graphics.hpp>

//INCLUDE CLASS
#include "Player.h"

class gamePlay
{
private:
	//Variables
	bool endGame;

	//Windows
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	//Game Clases
	Player player;
	//Mouse Posicion
	
	
	
	//Resources
	
	//Text
		
public:
	//Constructor & Destructor
	gamePlay();
	~gamePlay();
	//Sets & Gets
	const bool getEndGame()const;
	//Funciones
	void upDate();
	void draw();
	//Accesorios
	const bool runnig()const;
protected:
	//Init
	void initVariables();
	void initWindows();
	//Update
	void updateEvent();
	//Draw
};

