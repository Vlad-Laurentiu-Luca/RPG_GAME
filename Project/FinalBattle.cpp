#include "FinalBattle.h"
#include "Sound.h"


Sound sunetFinalBattle;

FinalBattle::FinalBattle() {
	sunetFinalBattle.bossFightSound(); // Start the intro sound in loop

}




Army1_Monsters::Army1_Monsters(int hp) {

	mHP = hp;

}

int Army1_Monsters::getHP() {
	return mHP;
}

void Army1_Monsters::takeDamage(int amount) {
	mHP -= amount;

	if (mHP < 0) {
		mHP = 0;
	}
}

FinalBattle::~FinalBattle()
{
	sunetFinalBattle.stopSound(); // Stop the intro sound

}
