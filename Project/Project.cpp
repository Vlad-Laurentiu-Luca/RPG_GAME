// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include "Intro.h"
#include <thread>   // For std::this_thread::sleep_for
#include <chrono>   // For std::chrono::seconds
#include "Player.h"
#include "Sound.h"
#include "FinalBattle.h"






int main()
{
    

    Intro  mainMenu;
    
    Intro intro;
    Sound sunetintro; 
    
    mainMenu.mainMenu();
    intro.printInfo();

    //sunetele mainmenu (intro)
    sunetintro.introSound();
    sunetintro.stopSound();

    Sound sunetSelectClass;
    //sunetele selectClass+explorarea
    sunetSelectClass.introClassSelectSound();
    sunetSelectClass.stopSound();

    Sound sunetFinalBattle;
    sunetFinalBattle.bossFightSound();
    sunetFinalBattle.stopSound();



    Player* p1 = selectClass();
    Player* p2 = new Player(100);


    std::cout << "REMINDER: \n";
    std::cout << "The class that you have selected is: " << p1->getCharRace() << std::endl;

   
    
    
    
   
    Item* item = p1->createItem();

    p1->addItemToInventory(item);



    p1->crossroads(item);

    
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "You encountered a mutant rabbit that is x3 bigger than you!\n";
    
    Army1_Monsters* army1 = new Army1_Monsters(100);
    std::cout << "Type F or f in order to hit it in the head!\n";
    std::cout << "Type G or G in order to hit it in the chest!\n";

    std::string answer="";
    while (answer.empty()) {
        std::cin >> answer;
        if (answer == "F" or answer == "f") {
            army1->takeDamage(30);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 30 Hp damage to your rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            
            

            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }
        }
        else if (answer == "G" or answer == "g") {
            army1->takeDamage(20);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 20 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

           
           

            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F or G or g\n";

            answer = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    

    std::cout << "The rabbit becomes angry at you and is preparing it's first attack\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::string dodge="";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge.empty()) {

        std::cin >> dodge;
        if (dodge == "Right" || dodge == "right" || dodge == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the head!(You lost 35 hp)\n";
            p2->primesteDamage(35);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //aici o sa fac sa imi printeze, nu sa fie hardcodata viata (cata viata a mai ramas)
            std::cout << "Now you have " << p2->getHpPlayer() << "hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }

        }
        else if (dodge == "Left" or dodge=="left" or dodge=="l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You succefully dodged the attack!\n";
        }
        else if (dodge == "Dash" or dodge=="dash" or dodge=="d") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the back! (You lost 15 hp)\n";
            p2->primesteDamage(15);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "Now you have " <<p2->getHpPlayer() <<  " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }

        }
        else {
            std::cout << "Invalid Input!\n"; 
            std::cout << "Try again to type d or dash or Dash or r or right or Right or l or left or left!\n";
            dodge = "";
            continue;
        }
        

    }
    //continuare dupa atac
    
    std::cout << "Type F or f in order to hit it in the head again!\n";
    std::cout << "Type G or G in order to hit it in the chest again!\n";

    std::string answer1 = "";
    while (answer1.empty()) {
        std::cin >> answer1;
        if (answer1 == "F" or answer1 == "f") {
           
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You missed! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
        else if (answer1 == "G" or answer1 == "g") {
            army1->takeDamage(30);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 20 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            
            

            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }

        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F\n";

            answer1 = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    
    //E CORECT, TREBUIE DOAR MODFICIAT SA NU FIE HARDCODAT CI SA FAC O FUNCTIE IN CPP DE VIATA, SA FIE CA LA ARMY1 IN MAIN, NU E HARDCODATA VIATA CU CARE A RAMAS, AM COMENTAT DOAR SA ARAT CA MERGE

    std::string dodge1 = "";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge1.empty()) {

        std::cin >> dodge1;
        if (dodge1 == "Right" || dodge1 == "right" || dodge1 == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You succefully dodged the attack!\n";

           
            std::this_thread::sleep_for(std::chrono::seconds(1));

           
        }
        else if (dodge1 == "Left" or dodge1=="left" or dodge1=="l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";
            

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }
        }
        else if (dodge1 == "Dash" or dodge1 == "dash" or dodge1 == "d") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the back! (You lost 15 hp)\n";
            p2->primesteDamage(15);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }

        }
        else {
            std::cout << "Invalid Input!\n";
            std::cout << "Try again to type d or D or Dash!\n";
            dodge1 = "";
            continue;
        }


    }


    std::cout << "Type F or f in order to hit it in the head again!\n";
    std::cout << "Type G or G in order to hit it in the chest again!\n";

    std::string answer2 = "";
    while (answer2.empty()) {
        std::cin >> answer2;
        if (answer2 == "F" or answer2 == "f") {

            army1->takeDamage(30);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 20 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }
            
           


        }
        else if (answer2 == "G" or answer2 == "g") {
            
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You missed! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            

            break;

        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F\n";

            answer2 = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }




    std::string dodge2 = "";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge2.empty()) {

        std::cin >> dodge2;
        if (dodge2 == "Right" || dodge2 == "right" || dodge2 == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You tried to dodge but you got hit in the back! (You lost 35 hp)\n";
            
            p2->primesteDamage(35);

            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            std::this_thread::sleep_for(std::chrono::seconds(1));

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }

        }
        else if (dodge2 == "Left" or dodge2 == "left" or dodge2 == "l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the head!(You lost 45 hp)\n";
            p2->primesteDamage(45);
            std::cout << "Now you have 65 hp left!\n"; //nu e corecta viata, trebuie adaugat o functie in cpp care sa ii de-a viata si sa nu fie hardcoadata, sa fie ca la army1 de ex in main

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }

        }
        else if (dodge2 == "Dash" or dodge2 == "dash" or dodge2 == "d") {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You succefully dodged the attack!\n";

            
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            


            
            
        }
        else {
            std::cout << "Invalid Input!\n";
            std::cout << "Try again to type d or D or Dash!\n";
            dodge2 = "";
            continue;
        }


    }



    //aici nu am un answer/attack, doar dodge 2 si 3

    std::cout << "Type F or f in order to hit it in the head again!\n";
    std::cout << "Type G or G in order to hit it in the chest again!\n";
    std::string answer3 = "";
    while (answer3.empty()) {
        std::cin >> answer3;
        if (answer3 == "F" or answer3 == "f") {

            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You missed! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));



            break;


        }
        else if (answer3 == "G" or answer3 == "g") {
            army1->takeDamage(35);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 35 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));




            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F\n";

            answer3 = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }





    std::string dodge3 = "";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge3.empty()) {

        std::cin >> dodge3;
        if (dodge3 == "Right" || dodge3 == "right" || dodge3 == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You succefully dodged the attack!\n";


            std::this_thread::sleep_for(std::chrono::seconds(1));


        }
        else if (dodge3 == "Left" or dodge3 == "left" or dodge3 == "l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";
            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }
        }
        else if (dodge3 == "Dash" or dodge3 == "dash" or dodge3 == "d") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the back! (You lost 15 hp)\n";
            p2->primesteDamage(15);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);
            }
        }
        else {
            std::cout << "Invalid Input!\n";
            std::cout << "Try again to type d or D or Dash!\n";
            dodge3 = "";
            continue;
        }

        



    }







    std::cout << "Type F or f in order to hit it in the head again!\n";
    std::cout << "Type G or G in order to hit it in the chest again!\n";

    std::string answer4 = "";
    while (answer4.empty()) {
        std::cin >> answer4;
        if (answer4 == "F" or answer4 == "f") {

            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You missed! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));


            
            break;


        }
        else if (answer4 == "G" or answer4 == "g") {
            army1->takeDamage(35);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 35 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));




            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F\n";

            answer4 = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }





    std::string dodge4 = "";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge4.empty()) {

        std::cin >> dodge4;
        if (dodge4 == "Right" || dodge4 == "right" || dodge4 == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You succefully dodged the attack!\n";


            std::this_thread::sleep_for(std::chrono::seconds(1));


        }
        else if (dodge4 == "Left" or dodge4 == "left" or dodge4 == "l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";
            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }
        }
        else if (dodge4 == "Dash" or dodge4 == "dash" or dodge4 == "d") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the back! (You lost 25 hp)\n";
            p2->primesteDamage(25);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);
            }
        }
        else {
            std::cout << "Invalid Input!\n";
            std::cout << "Try again to type d or D or Dash!\n";
            dodge4 = "";
            continue;
        }





    }






    std::cout << "Type F or f in order to hit it in the head again!\n";
    std::cout << "Type G or G in order to hit it in the chest again!\n";

    std::string answer5 = "";
    while (answer5.empty()) {
        std::cin >> answer5;
        if (answer5 == "F" or answer5 == "f") {


            army1->takeDamage(35);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 35 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));


            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }


        }
        else if (answer5 == "G" or answer5 == "g") {
            

            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You missed! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));


            std::this_thread::sleep_for(std::chrono::seconds(1));
            


            
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F\n";

            answer5 = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }







    std::string dodge5 = "";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge5.empty()) {

        std::cin >> dodge5;
        if (dodge5 == "Right" || dodge5 == "right" || dodge5 == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));



            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);
            }


        }
        else if (dodge5 == "Left" or dodge5 == "left" or dodge5 == "l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";
            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }
        }
        else if (dodge5 == "Dash" or dodge5 == "dash" or dodge5 == "d") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You succefully dodged the attack!\n";


            
            std::this_thread::sleep_for(std::chrono::seconds(1));

            

            
        }
        else {
            std::cout << "Invalid Input!\n";
            std::cout << "Try again to type d or D or Dash!\n";
            dodge5 = "";
            continue;
        }





    }



    std::cout << "Type F or f in order to hit it in the head again!\n";
    std::cout << "Type G or G in order to hit it in the chest again!\n";

    std::string answer6 = "";
    while (answer6.empty()) {
        std::cin >> answer6;
        if (answer6 == "F" or answer6 == "f") {


           


            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You missed! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));


            std::this_thread::sleep_for(std::chrono::seconds(1));


        }
        else if (answer6 == "G" or answer6 == "g") {


            
            army1->takeDamage(35);
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You gave 35 Hp damage to the rabbit! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));


            if (army1->getHP() <= 0) {
                std::cout << "You Won the Game!\n";
                std::cout << "The First Part is completed, the next part will be done soon!\n";
                exit(0);

            }
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Type again just f or F\n";

            answer6 = "";
            continue;
        }

        std::cout << "Monster hp: " << army1->getHP() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }




    std::string dodge6 = "";
    std::cout << "Type Left or Right or right or r or d (to dash) in order to dodge!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (dodge6.empty()) {

        std::cin >> dodge6;
        if (dodge6 == "Right" || dodge6 == "right" || dodge6 == "r") {
            std::this_thread::sleep_for(std::chrono::seconds(1));



            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);
            }


        }
        else if (dodge6 == "Left" or dodge6 == "left" or dodge6 == "l") {
            std::this_thread::sleep_for(std::chrono::seconds(1));

           




            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "You succefully dodged the attack!\n";



            std::this_thread::sleep_for(std::chrono::seconds(1));







            
        }
        else if (dodge6 == "Dash" or dodge6 == "dash" or dodge6 == "d") {
            
            std::cout << "You tried to dodge but you got hit in the head!(You lost 40 hp)\n";
            p2->primesteDamage(40);
            std::cout << "Now you have " << p2->getHpPlayer() << " hp left!\n";

            if (p2->getHpPlayer() <= 0) {
                std::cout << "Game Over! You have no HP left.\n";
                exit(0);

            }

        }
        else {
            std::cout << "Invalid Input!\n";
            std::cout << "Try again to type d or D or Dash!\n";
            dodge6 = "";
            continue;
        }





    }













    delete p1;
    delete army1;

    std::cin.get();
    //cleanup la player sa fac destructorul 
    //pt celellate doua clase de implementat metoda de createItem

}


