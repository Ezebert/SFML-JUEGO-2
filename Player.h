#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::RectangleShape shape;
	float speed;
	int hp;
	int maxHp;
public:
	//Constructor y Destructor
	Player();
	Player(float x, float y);
	~Player();
	//Sets & Gets
	const sf::RectangleShape &getShape()const;
	int getHp();
	int getMaxHp();
	//Funciones Pricipales
	void update(sf::RenderTarget* target);
	void draw(sf::RenderTarget* target);
	//Funciones Aux
	void takeDamage(int damage);
	void gainHealth(int health);
protected:
	//init
	void initVariables();
	void initShape();

	//Update
	//	<Collision>
	void updateWindowsBoundsCollision(sf::RenderTarget*target);
	//  <KeyBoard Press>
	void updateInput();
	
	//Draw
	
};


