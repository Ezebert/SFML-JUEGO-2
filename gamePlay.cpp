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
	this->initTextEndGame();
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
	if (!this->endGame) {
		this->updatePlayer();
		this->updateTextPoint();

		this->updateCollision();
		this->spawnSwagBalls();
	}
	
	
}
void gamePlay::updatePlayer()
{
	this->player.update(this->window);

	//check life
	if (this->player.getHp() <= 0) {
		this->endGame = true;
	
	}
	
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

	if (this->endGame == true)
	{
		this->window->draw(this->textEndGame);
	}

	//=============================
	this->window->display();
	
}

//======= FUNCIONES AUX =======
const bool gamePlay::runnig() const
{
	return this->window->isOpen();// && !this->endGame;
}

void gamePlay::spawnSwagBalls()
{
	//Timer
	if (this->spawTimer < this->spawTimerMax)
		this->spawTimer += 1.f;
	else if (this->swagBalls.size() < this->maxSwagsBalls) {
		//Agrega un nuevo enemigo
		//this->swagBalls.push_back(SwagBalls(*this->window));
		this->swagBalls.push_back(SwagBalls(*this->window,this->randBallType()));
		this->spawTimer = 0.f;
	}	
}

int gamePlay::randBallType()
{
	int type = SwagBallsType::DeFAULT;
	int randValue = rand() % 100 + 1; // Entr 1 y 100
	if (randValue > 60 && randValue <= 90)
		type = SwagBallsType::DAMEGING;
	if (randValue > 90 && randValue <= 100)
		type = SwagBallsType::HEALING;
	return type;
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
void gamePlay::initTextEndGame()
{
	this->textEndGame.setFont(this->font);
	this->textEndGame.setCharacterSize(60);
	this->textEndGame.setFillColor(sf::Color::Red);
	this->textEndGame.setString("Gamame Over ");
	// Calcular la posición del texto
	sf::FloatRect textRect = textEndGame.getLocalBounds();
	textEndGame.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	this->textEndGame.setPosition(sf::Vector2f(
		this->window->getSize().x / 2.0f,
		this->window->getSize().y / 2.0f));

}
//======= UPDATE Secundario ======= 
void gamePlay::updateTextPoint()
{
	std::stringstream ss;
	ss << " Point: " << this->points
		<<" Health: " << this->player.getHp() << " / " << this->player.getMaxHp();
	this->textPoint.setString(ss.str());
}

//======= UPDATE <Collision> ======= 
void gamePlay::updateCollision() //Enemies & Player
{
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds())) {
			switch (this->swagBalls[i].getType())
			{
			case SwagBallsType::DAMEGING:
				this->player.takeDamage(this->player.getMaxHp()/2 + 1 );
				break;
			case SwagBallsType::HEALING:
				this->player.gainHealth(1);
				break;
			default:
				this->points++;
				break;
			}
			

			swagBalls.erase(swagBalls.begin() + i);
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