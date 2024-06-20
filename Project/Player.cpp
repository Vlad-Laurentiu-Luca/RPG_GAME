#include "Player.h"
#include "Sound.h"

Sound sunetSelectClass;



//constructor player
Player::Player() {
	sunetSelectClass.introClassSelectSound(); // Start the intro sound in loop



}


Player* selectClass() {
	Player* p = nullptr;
	int numClass=0;
	std::string playerName;
	std::cout << "Type 1 for: Warrior or  2 for: Wizzard or 3 for: Rogue\n";
	
	while (numClass == 0) {
		std::cin >> numClass;
		if (numClass == 1) {
			std::cout << "Enter your name: \n";
			std::cin >> playerName;

			std::cout << playerName << " From now on you are a Warrior!\n";
			p = new Warrior(playerName);

			break;

		}
		else if (numClass == 2) {
			std::cout << "Enter your name: \n";
			std::cin >> playerName;
			std::cout << playerName << " From now on you are a Wizzard!\n";

			p = new Wizzard(playerName);
			break;
		}
		else if (numClass == 3) {
			std::cout << "Enter your name: \n";
			std::cin >> playerName;
			std::cout << playerName << " From now on you are a Rogue!\n";

			p = new Rogue(playerName);
			break;
		}
		else {
			std::cout << "Invalid Input! Type Again:\n";

			numClass = 0;

		}

	}
	return p;
}




const int Player::getCharRace() { return -1; }



Player::Player(int health) {
	Health = health;
	

}








Item::Item(std::string nameItem) {
	itemName = nameItem;



}

Item* Player::createItem() {
	std::random_device rd; //folosit pt a folosi random
	std::mt19937 mt(rd());//folosit pt a folosi random
	int numClass = 0;
	std::vector<std::string> items{ "Axe", "Hammer", "Sword", "Wand of the Mystic Flame", "Orb of Eldritch Power", "Staff of Arcane Wisdom", "A pair of Daggers", "Crossbow", "Short Sword" };
	std::uniform_int_distribution<int> dist(0, items.size() - 1);
	int randomNumber = dist(mt);
	std::string answer;
	std::cout << "The chest has 3 symbols, Choose only the type of class you are: Type 1 for: Warrior or 2 for: Wizzard or 3 for: Rogue\n";
	std::cout << "IF YOU DON'T TYPE 1, 2 OR 3 THE GAME WILL CLOSE\n";
	std::cin >> numClass;
	if (numClass == 1) {
		std::cout << " You have found an axe!" << std::endl;
	}
	else if (numClass == 2) {
		std::cout << " You have found a Magic Wand!" << std::endl;


	}
	else if (numClass == 3) {
		std::cout << " You have found a Rogue's Sword!" << std::endl;


	}
	else {
		std::cout << "Invalid input\n";
	}
	//std::cout  << "You found in the chest: " << items[randomNumber] << std::endl;
	//std::cin >> answer;
	//if (answer == "y") {
	//	Item* item = new Item(items[randomNumber]); 
	//	
	//	return item;
	//}
	Item* item = new Item(items[randomNumber]);
	return item;
	//else if()
	//else()*/

}





//Warrior::Warrior(int health, int damage) {
//	health = Health;
//	damage = Damage;
//	std::cout << "Your health is: 100%\n";
//	std::cout << "Your Damage is: 10%\n";
//	std::string raspuns;
//	std::cout << "You have found a chest! Do you want to open it? Type: (Yes/No)\n";
//
//
//	while (raspuns.empty()) {
//		std::cin >> raspuns;
//
//		if (raspuns == "Yes") {
//			std::cout << "You found an axe!\n";
//			
//			break;
//		}
//		else if (raspuns == "No") {
//			std::cout << "Ok, you chose to not open the chest!\n";
//			std::cout << "You need to open the chest! Otherwise you will die instantly!\n";
//			exit(0);
//		}
//		else {
//			std::cout << "invalid Input!\n";
//			continue;
//		}
//
//	}
//
//
//
//}


const int Warrior::getCharRace() { return 1; }


Item* Warrior::createItem() {
	std::random_device rd; //folosit pt a folosi random
	std::mt19937 mt(rd());//folosit pt a folosi random
	int numClass = 0;
	std::vector<std::string> items{ "Axe", "Hammer", "Sword" };
	std::uniform_int_distribution<int> dist(0, items.size() - 1);
	int randomNumber = dist(mt);
	std::string answer;

	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You have found a beautiful chest!\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You decided to open it due to the fact that you are looking for something special for you\n";

	//aici ar trebui sa fac un while dar e mai greu (pt invalid, sa nu te lase sa pleci decat dupa ce ai pus ce trebuie)-Intreb la curs

	if (randomNumber == 0) {
		std::cout << " You have found an Axe!" << std::endl;
	}
	else if (randomNumber == 1) {
		std::cout << " You have found a Hammer!" << std::endl;


	}
	else if (randomNumber == 2) {
		std::cout << " You have found a Sword!" << std::endl;


	}
	else {
		std::cout << "Invalid input\n";
	}
	//std::cout  << "You found in the chest: " << items[randomNumber] << std::endl;
	//std::cin >> answer;
	//if (answer == "y") {
	//	Item* item = new Item(items[randomNumber]); 
	//	
	//	return item;
	//}
	Item* item = new Item(items[randomNumber]);
	return item;
	//else if()
	//else()*/

}






Item* Wizzard::createItem() {
	std::random_device rd; //folosit pt a folosi random
	std::mt19937 mt(rd());//folosit pt a folosi random
	int numClass = 0;
	std::vector<std::string> items{ "Wand of the Mystic Flame", "Orb of Eldritch Power", "Staff of Arcane Wisdom" };
	std::uniform_int_distribution<int> dist(0, items.size() - 1);
	int randomNumber = dist(mt);
	std::string answer;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You have found a beautiful chest!\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You decided to open it due to the fact that you are looking for something special for you\n";

	if (randomNumber == 0) {
		std::cout << " You have found a Wand of the Mystic Flame!" << std::endl;
	}
	else if (randomNumber == 1) {
		std::cout << " You have found an Orb of Eldritch Power!" << std::endl;


	}
	else if (randomNumber == 2) {
		std::cout << " You have found a Staff of Arcane Wisdom!" << std::endl;


	}
	else {
		std::cout << "Invalid input\n";
	}
	//std::cout  << "You found in the chest: " << items[randomNumber] << std::endl;
	//std::cin >> answer;
	//if (answer == "y") {
	//	Item* item = new Item(items[randomNumber]); 
	//	
	//	return item;
	//}
	Item* item = new Item(items[randomNumber]);
	return item;
	//else if()
	//else()*/

}








Item* Rogue::createItem() {
	std::random_device rd; //folosit pt a folosi random
	std::mt19937 mt(rd());//folosit pt a folosi random
	int numClass = 0;
	
	std::vector<std::string> items{ "A pair of Daggers", "Crossbow", "Short Sword" };
	std::uniform_int_distribution<int> dist(0, items.size() - 1);
	int randomNumber = dist(mt);
	std::string answer;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You have found a beautiful chest!\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "You decided to open it due to the fact that you are looking for something special for you\n";

	if (randomNumber == 0) {
		std::cout << " You have found A pair of Daggers!" << std::endl;
	}
	else if (randomNumber == 1) {
		std::cout << " You have found a Crossbow!" << std::endl;


	}
	else if (randomNumber == 2) {
		std::cout << " You have found a Short Sword!" << std::endl;


	}
	else {
		std::cout << "Invalid input\n";
	}
	//std::cout  << "You found in the chest: " << items[randomNumber] << std::endl;
	//std::cin >> answer;
	//if (answer == "y") {
	//	Item* item = new Item(items[randomNumber]); 
	//	
	//	return item;
	//}
	Item* item = new Item(items[randomNumber]);
	return item;
	//else if()
	//else()*/

}




void Player::addItemToInventory(Item* numeItem) {
	std::string answer = "";


	std::cout << "Do you want to store the items that you have found in the chest? Type (yes for Yes and no for No)\n";


	while (answer.empty()) {
		std::cin >> answer;
		if (answer == "yes") {
			std::cout << numeItem->itemName << " is added to your inventory!" << std::endl;
			playerInventory.push_back(numeItem);
			break;
		}
		else if (answer == "no") {
			std::cout << "Ok, you chose not to sotre the items in your inventory!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "You encountered an evil Warrior\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "Due to the fact that you don't have a weapon to defend yourself you decided to forfeit..\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "He decided to cut your head off\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "GAME OVER!\n";
			exit(0);
		}
		else {
			std::cout << "Invalid input!" << " Type again just yes or no !\n";
			answer = "";
			continue;
		}
	}




	/*std::cout << "Do you want to store this item in your inventory?\n (Type y or n)\n";
	std::cin >> answer;*/
	//if (answer == "y") {
	//	p->playerInventory.push_back(numeItem); 
	//
	//	std::cout << numeItem->itemName << " is added to your inventory!" << std::endl; //modalitate de a da cout, ca daca vreau sa dau simplu compilatorul nu vede
	//	
	//
	//}
}




int Player::getHpPlayer() {
	return Health;

}





void Player::primesteDamage(int numar)
{
	Health -= numar;

	if (Health < 0) {
		Health = 0;
	}
}



Warrior::Warrior(std::string playerNume) {
	playerName = playerNume;



}

Warrior::Warrior() {

}

Wizzard::Wizzard(int health, int damage) {
	health = Health;
	damage = Damage;

	std::cout << "Your health is: 100%\n";
	std::cout << "Your Damage is: 60%\n";

}

Wizzard::Wizzard(std::string playerNume) {
	playerName = playerNume;



}
Wizzard::Wizzard() {

}
const int Wizzard::getCharRace() { return 2; }
Rogue::Rogue(int health, int damage) {
	Health = health;
	Damage = damage;

	std::cout << "Your health is: 100%\n";
	std::cout << "Your Damage is: 20%\n";

}


Rogue::Rogue(std::string playerNume) {
	playerName = playerNume;



}

Rogue::Rogue() {

}
const int Rogue::getCharRace() { return 3; }



//destructor player














void Player::crossroads(Item* numeItem)  {
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "Where do you want to go?\n";
	std::cout << "Type 1 or 2 to choose your path\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "1. Cave\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "2. Stay where you are\n";
	int raspuns0;
	int raspunsinventar = 0;
	std::cin >> raspuns0;

	if (raspuns0 == 1) {
		int rasp;
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "It's dark, look for some ways to make light:\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "Type 1 or 2 to choose: \n";
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::cout << "1. Check your innventory.\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "2. Look around the cave.\n";

		std::cin >> rasp;
		if (rasp == 1) {

			/*std::cout << "You have: " << numeItem->itemName << " your inventory!" << std::endl;
			std::cout << "You should find some sort of light!\n";*/

			if (playerInventory.empty()) {
				std::string answer;
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "You have a Torch in your inventory!\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "Do you want to equip it? (Type y,yes,Yes) or (Type n,no,No)" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cin >> answer;
				if (answer == "Yes" or answer == "yes" or answer == "y") {
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You have equipped your torch! Now you have some sort of light\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					//aici continui cu torta
					std::cout << "It's dark but you finally find a big hole so you decided to get out using it.\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You are now outside..but behind the tree you see something big..you ran to it to see what it is..\n";
				}
				else if (answer == "No" or answer == "no" or answer == "n") {
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "Ok, you will remain in the darkness\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You try to go in darkness but you feel something climbing on you.\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "It started to make a sound: Shhshhh...\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You don't know what to do, so you try to stay still but it bites you and when you looked at it ou saw it's red eyes...\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You slowly but surely Died!\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					std::cout << "GAME OVER!\n";

					exit(0);
					//aici continui cu moartea
				}
				
				//continuare ce face dupa verifica inventarul?




			}
			else {
				for (const auto& item : playerInventory) { //aici m-a ajutat chat gpt, de ce a folosit const auto& item : playerInventory (cred ca e modul ala pe care inca nu l-am aprofundat la curs de a scrie for)
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You have: " << item->itemName << " in your inventory!" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You chose to use the " << item->itemName << "in order to escape from the cave!\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You put all your force in destroying a corner of the cave with " << item->itemName << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You successfully escaped from inside of that cave! " <<  std::endl;
					
					std::this_thread::sleep_for(std::chrono::seconds(1));

					//continuat poveste ce faci dupa ce iti printeaza ca ai acel inventar? cred ca trebuie sa fac verificarea daca e warrior, wizzard sau rogue si fiecare sa aiba un cout diferit
				}
			}
		}

		else if (rasp == 2) {
			std::string leftrightanswer;
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "Do you want to go to the (type r) right or (type l) left?\n";
			std::cin >> leftrightanswer;
			if (leftrightanswer == "l" || leftrightanswer == "left" || leftrightanswer == "Left") {
				std::string yesnoanswer;
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "You saw something that lightened the left corner of the cave\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "Do you want to go to see what is it? (Type yes/y or no/n) \n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cin >> yesnoanswer;
				if (yesnoanswer == "yes" || yesnoanswer == "Yes") {
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You found a gas lantern, but it doesn't has much gas left in it\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "Try to find the exit!\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You managed to see a small crack in the corner of the cave and you escaped from that cave.\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You see what different the world is..everything is rotten...even all the birds are laying on the ground and their skin is cut out..\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					
					std::cout << "What is that???\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					//poveste terminata (continua in main

				}
				else if (yesnoanswer == "no" or yesnoanswer == "No") {
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You chose to not seach that area but you stepped on a tile that opened a trap where a lot of arrows come in your direction and you Died!\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "GAME OVER!\n";

					exit(0);

					//poveste terminata
				}
				
			}
			else if (leftrightanswer == "r" || leftrightanswer == "right" || leftrightanswer == "Right") { 
				std::string answer1;
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "It's very dark, you don't know what could happen to you if you will try to go further in the darkness of the cave \n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				
				std::cout << "You fell in a pit!\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "Do you want to: " << std::endl << "(Type jump or Jump to:  Jump) or (Type Stay or stay to:  Stay and cry)\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cin >> answer1;
				if (answer1 == "jump" or answer1 == "Jump") {
					std::string answer2;
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You managed to  jump and climb to the surface\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "Try to find the exit of the cave in darkness\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "Where do you want to go? (type left for left or rght for right)\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cin >> answer2;
					if (answer2 == "left" or answer2 == "Left") {
						std::string answer3;
						std::this_thread::sleep_for(std::chrono::seconds(1));

						std::cout << "You found a lever, what do you want to to? (type pull to pull or leave it alone to leave it alone)\n";
						std::cin >> answer3;
						if (answer3 == "pull" or answer3 == "Pull") {
							std::this_thread::sleep_for(std::chrono::seconds(1));

							std::cout << "The cave is starting to collapse instantly" << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(1));

							std::cout << "You couldn't save yourself due to the fact that you didn't see anything so you DIED!\n";
							std::cout << "GAME OVER!\n";

							exit(0);
						}
						else if (answer3 == "leave" or answer3 == "Leave") {
							std::string answer4;
							std::this_thread::sleep_for(std::chrono::seconds(1));

							std::cout << "You decided to leave the lever alone but you see a giant spider that comes at you, what do you decide?\n";
							std::this_thread::sleep_for(std::chrono::seconds(1));

							std::cout << "Type attack to attack or run to run\n";
							std::this_thread::sleep_for(std::chrono::seconds(1));

							std::cin >> answer4;
							if (answer4 == "attack" or answer4 == "Attack") {
								std::this_thread::sleep_for(std::chrono::seconds(1));

								std::cout << "You tried to take a swing at the spider but it jumped in your face and started to suffocate you\n";
								std::this_thread::sleep_for(std::chrono::seconds(1));

								std::cout << "You tried so hard to get this far, but you DIED!\n";
								std::this_thread::sleep_for(std::chrono::seconds(1));

							}
							else if (answer4 == "run" or answer4 == "Run") {
								std::cout << "You decided to run and managed to escape!\n";
								std::this_thread::sleep_for(std::chrono::seconds(1));

								std::cout << "You suddenly see a spot of a cracked rock within the light entered so you decide to go there\n";
								std::this_thread::sleep_for(std::chrono::seconds(1));

								std::cout << "You finally found the exit of the cave!\n";
								std::this_thread::sleep_for(std::chrono::seconds(1));

							}
						}
					}
				}



				if (answer1 == "stay" || answer1 == "Stay")
					std::this_thread::sleep_for(std::chrono::seconds(1));

					std::cout << "You tried to reach the surface in the last 2 hours but you hear some sounds:\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "Krrk..Krrkj..Krrrkji\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "It's a scorpion! But it's a very weird one...he looks so strange.." << std::endl << " You tried to kill it but it killed you!\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "YOU DIED BY A MUTANT SCORPION!\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));

				std::cout << "GAME OVER!\n";

				exit(0);
				//terminat poveste aici
			}

		}

	}
	else if (raspuns0 == 2) {
		int rasp0;
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "An injured Goblin  comes in your way \n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "Type 1 or 2 to choose: \n";
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::cout << "1. Talk with him\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout << "2. Ignore him\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cin >> rasp0;
		if (rasp0 == 1) {


			std::cout << "YOU: What happened?\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//aici continui dialogul
			std::cout << "The Goblin: I...tried to warn my people of him...but he got at my village before me...\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "YOU: Who?\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin: There is a thing..a big one.. half human and half wolf\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "YOU: What are you talking about?\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin: I don't know..but the important thing is that he attacked half of the region..did you not notice anything?\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "YOU: No...I am living in the forrest for a while..because my king has been killed not so long time ago....and I don't know what to do..all the kingdom was in flames...\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin: I don't care what you went through...I want to know that you will kill him because if not, all the region will be in his hands..\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "YOU: Why do you want him to be dead so badly?\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin: Because..he....\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "YOU: Hey! Don't die on me!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin: My time...has..passed..\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "YOU: Give me an answer!!!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin: .......\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The Goblin has died due to internal bleeding\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "Your Main Focus Is To Kill That Thing!\n";





		}
		else if (rasp0 == 2) {
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "You need to figure out what hapened in this region by yourself now.\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "You went to the beutifull Armenia Cascade.\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::cout << "You saw something that was in front of the Cascade.\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));

			
			
			//pveste terminata (continuare in main
			
		}
		else {
			std::cout << "Invalid Input!\n";
		}
	}

}


Player::~Player()
{
	for (int i = 0; i < playerInventory.size(); i++) {
		delete playerInventory[i];
	}

	sunetSelectClass.stopSound(); // Stop the intro sound



}