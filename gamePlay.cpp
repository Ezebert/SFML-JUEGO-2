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
	this->updateCollision();

	this->updateEvent();
	this->player.update(this->window);

	this->spawnSwagBalls();
	
	
} 


void gamePlay::draw()
{
	this->window->clear();
	//this->window->draw();
	this->player.draw(this->window);

	for (auto& e : this->swagBalls)
	{
		e.draw(*this->window);
	}
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

}

void gamePlay::initWindows()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "SFML JUEGO 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//======= UPDATE <Collision> =======
void gamePlay::updateCollision()
{
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
			swagBalls.erase(swagBalls.begin() + i); 
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