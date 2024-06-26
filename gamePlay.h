#pragma once
#include <SFML/Graphics.hpp>

//INCLUDE CLASS
#include "Player.h"
#include "SwagBalls.h" 
class gamePlay
{
private:
	//Variables
	bool endGame;

	float spawTimerMax;
	float spawTimer;
	int maxSwagsBalls;

	//Windows
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	//Game Clases
	Player player;
	std::vector <SwagBalls> swagBalls;
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
	void spawnSwagBalls();
protected:
	//Init
	void initVariables();
	void initWindows();
	//Update Secundario
	//	<Collision>
	void updateCollision();
	//	<KeyBoard Press>
	void updateEvent();
	//Draw
};

