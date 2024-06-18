#pragma once
#include<iostream>
#include <string>
#include <thread>   // For std::this_thread::sleep_for
#include <chrono>   // For std::chrono::seconds


class Intro
{
public:
	
	Intro();

	void mainMenu();
	void  printInfo(); 
	int checkAnswer(std::string answer);
	
	~Intro();

	
};



