#pragma once
class FinalBattle
{
public:
	FinalBattle();
	~FinalBattle();

};

class Army1_Monsters :public FinalBattle{
public:
	Army1_Monsters(int hp);
	int getHP();
	void takeDamage(int amount);

private:
	int mHP;

};