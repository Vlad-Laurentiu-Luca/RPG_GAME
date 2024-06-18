#pragma once
#include<iostream>
#include<string>
#include <thread>   // For std::this_thread::sleep_for
#include <chrono>   // For std::chrono::seconds
#include <vector>
#include <random>




class Item {
public:
	std::string itemName;
	Item(std::string nameItem);
	/*std::string answer;
	std::cout << "Do you want to store all of them?\n";
	std::cin >> answer;*/
	
};



class Player
{
protected:
	int Health;
	int Damage;
	std::string playerName;
	std::vector<Item*> playerInventory;
	
	

private:
	
	
	
	
public:
	
	Player();
	Player(std::string playerNume);
	Player(int health);
	~Player();
   friend Player* selectClass();
	void crossroads(Item* numeItem);
	//functiile friend pot sa vada atributele private ale claselor respective
	void addItemToInventory(Item* numeItem);
	const virtual int getCharRace();
	virtual Item* createItem();
	int getHpPlayer();
	void primesteDamage(int numar);
	
};

Player* selectClass(); 



class Warrior : public Player {
public:
	Item* createItem() override;

	Warrior();
	Warrior(int health, int damage);
	Warrior(std::string playerNume);
	const int getCharRace();
	void addItemToInventory(Item* numeItem);
	

};

class Wizzard : public Player {
public:
	Item* createItem() override;

	Wizzard();

	Wizzard(int health, int damage);
	Wizzard(std::string playerNume);
	const int getCharRace();
	

};

class Rogue : public Player {
public:
	Item* createItem() override;

	
	Rogue(); 

	Rogue(int health, int damage);
	Rogue(std::string playerNume);
	const int getCharRace(); 
	
};




