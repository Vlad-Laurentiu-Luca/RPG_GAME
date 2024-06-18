//librarii necesare pentru a scoate sunete

#pragma once
#include <Windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
class Sound
{
public:

	void introSound();
	void stopSound();
	void introClassSelectSound();
	void bossFightSound();
	
};

