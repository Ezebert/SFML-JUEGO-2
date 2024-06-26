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
	//<Timer>
	float spawTimerMax;
	float spawTimer;
	int maxSwagsBalls;
	int points;
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
	sf::Font font;
	sf::Text textPoint;
	sf::Text textEndGame;
	
public:
	//Constructor & Destructor
	gamePlay();
	~gamePlay();
	//Sets & Gets
	const bool getEndGame()const;
	//Funciones
	void upDate();
	void updatePlayer();
	void draw();
	//Accesorios
	const bool runnig()const;
	void spawnSwagBalls();
	int randBallType();
protected:
	//Init
	void initVariables();
	void initWindows();
	void initFont();
	void initTextPoint();
	void initTextEndGame();
	//Update Secundario
	void updateTextPoint();
	//	<Collision>
	void updateCollision();
	//	<KeyBoard Press>
	void updateEvent();
	
	//Draw
	void drawTextPoint(sf::RenderTarget& target);
	
};

