#include "Intro.h"

#include "Sound.h"

Sound sunetintro;

Intro::Intro() {
	sunetintro.introSound(); // Start the intro sound in loop
}



int Intro::checkAnswer(std::string answer)
{
	if (answer == "Yes" || answer == "y" || answer == "Y" || answer == "yes") {
		return 1;
	}
	else if (answer == "No" || answer == "n" || answer == "N" || answer == "no") {
		return 2;
	}
	else {
		return 3;
	}


}


void Intro::mainMenu()
{
	std::string answer = "";
	std::string playerName;

	std::cout << "Do you want to play? (Type: y/yes/Yes or n/no/No)\n";


	while (answer.empty()) {
		std::cin >> answer;
		if (checkAnswer(answer) == 1) {


			std::cout << "Welcome to the World In Fire \n";


			break;

		}
		//nu merge cum trebuie else if-ul
		else if (checkAnswer(answer) == 2) {



			std::cout << "Have a great back! Hope to see you soon!\n";
			exit(0);
		}
		else {


			std::cout << "Invalid input! Try again: \n";
			answer = "";
			continue;

		}
	}


}








void Intro::printInfo() {
	

	std::cout << "Scene: The adventurers find themselves at the entrance of the Ancient Crypt of Eldoria, a forgotten tomb hidden deep within the Whispering Woods. " << "\n";  
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "The entrance is flanked by two weathered stone statues of forgotten kings, their faces eroded by time.A heavy iron door stands ajar, revealing a dimly lit passageway beyond. " << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "The air is thick with the scent of damp earth and the faint glow of enchanted torches casts eerie shadows on the walls.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));



}

Intro::~Intro() {
	sunetintro.stopSound(); // Stop the intro sound
}






