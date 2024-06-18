#include "Sound.h"
#include "Intro.h"
#include "Player.h"

void Sound::introSound()
{

	PlaySound(TEXT("Main_Menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


}




void Sound::introClassSelectSound()
{
	PlaySound(TEXT("selectClassANDExploring.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

void Sound::bossFightSound()
{
	PlaySound(TEXT("BattleFinal.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

void Sound::stopSound() {
	PlaySound(NULL, 0, 0); // This stops any currently playing sound
}