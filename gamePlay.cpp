#include "gamePlay.h"
//======= Constructor & Destructor =======
gamePlay::gamePlay()
{
	this->initVariables();
	this->initWindows();
}
gamePlay::~gamePlay()
{
	delete this->window;
}
//======= Sets & Gets =======
const bool gamePlay::getEndGame() const
{
	return this->endGame;
}
//======= FUNCIONES =======
void gamePlay::upDate()
{
	this->updateEvent();
	this->player.update();
} 

void gamePlay::draw()
{
	this->window->clear();
	//this->window->draw();
	this->player.draw(this->window);
	this->window->display();
}

//======= FUNCIONES AUX =======
const bool gamePlay::runnig() const
{
	return this->window->isOpen();
}

//======= INIT =======
void gamePlay::initVariables()
{
	this->endGame = false;
}

void gamePlay::initWindows()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "SFML JUEGO 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}
//======= UPDATE =======
void gamePlay::updateEvent()
{
	while(this->window->pollEvent(this->event)){
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
		default:
			break;
		}
	}
}
//======= DRAW =======