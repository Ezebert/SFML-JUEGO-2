#include "gamePlay.h"
#include <iostream>
#include <sstream>
//======= Constructor & Destructor =======
gamePlay::gamePlay()
{
	this->initVariables();
	this->initWindows();

	this->initFont();
	this->initTextPoint();
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
	this->updateText();

	this->updateCollision();
	this->spawnSwagBalls();

	this->updateEvent();
	this->player.update(this->window);
	
} 


void gamePlay::draw()
{	//this->window->draw();
	this->window->clear();
	//=============================
	this->player.draw(this->window);

	for (auto& e : this->swagBalls)
	{
		e.draw(*this->window);
	}

	this->drawTextPoint(*this->window);
	//=============================
	this->window->display();
}

//======= FUNCIONES AUX =======
const bool gamePlay::runnig() const
{
	return this->window->isOpen();
}

void gamePlay::spawnSwagBalls()
{
	//Timer
	if (this->spawTimer < this->spawTimerMax)
		this->spawTimer += 1.f;
	else if (this->swagBalls.size() < this->maxSwagsBalls) {
		this->swagBalls.push_back(SwagBalls(*this->window));

	}

}

//======= INIT =======
void gamePlay::initVariables()
{
	this->endGame = false;
	
	this->spawTimer = 10.f;
	this->spawTimerMax = this->spawTimer;
	this->maxSwagsBalls = 10;
	this->points = 0;
}

void gamePlay::initWindows()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "SFML JUEGO 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void gamePlay::initFont()
{
	if (!this->font.loadFromFile("font/SIXTY.ttf")) {
		std::cout << " ERROR::GAME::InitFont";
	}
}

void gamePlay::initTextPoint()
{
	this->textPoint.setFont(this->font);
	
	this->textPoint.setCharacterSize(20);
	this->textPoint.setFillColor(sf::Color::White);

	this->textPoint.setString(" N/D ");


}
//======= UPDATE Secundario ======= 
void gamePlay::updateText()
{
	std::stringstream ss;
	ss << " Point: " << this->points;
	this->textPoint.setString(ss.str());
}

//======= UPDATE <Collision> ======= 
void gamePlay::updateCollision() //Enemies & Player
{
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds())) {
			swagBalls.erase(swagBalls.begin() + i);
			this->points++;
		}
			

	}
}
//======= UPDATE <KeyBoard Press> =======

void gamePlay::updateEvent()
{
	while (this->window->pollEvent(this->event)) {
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
void gamePlay::drawTextPoint(sf::RenderTarget& target)
{
	target.draw(this->textPoint);
}