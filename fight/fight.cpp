// fight.cpp : Defines the entry point for the application.
//

#include "fight.h"
#include "game.h"

using namespace std;

int main() {
    std::random_device seed;
    Random rnd(seed());

    int character;
    cout << "Choose a character: " << endl;
    cout << "1) Wizard" << endl;
    cout << "2) Fighter" << endl;
    cin >> character;

    Model adv;

    if (character == 1) {
        adv = Model("Wizard", 350, 35, 55, 0);
    }
    else if (character == 2) {
        adv = Model("Fighter", 400, 40, 65, 0);
    }

    Model boss1("MiniBoss", 50, 1, 2, 5); //mini boss

    std::cout << "You are fighting a Mini Boss!" << '\n';

    int advType;
    int spaCounter = 50; //counts turns down from 50
    while (!isDead(adv) && !isDead(boss1)) {
        do {
            std::cout << '\n'
                << "1 Normal Attack - 2 Special Attack(" << spaCounter
                << ") : ";
            std::cin >> advType;
        } while (advType < 1 || advType > 2);

        fight(advType, spaCounter, adv, boss1, rnd);
    }

    if (isDead(boss1)) {
        std::cout << "You defeated the Mini Boss! You Win!" << '\n';
    }
    else {
        std::cout << "You are DEAD!" << '\n';
    }

    cout << endl;
    //////////////////////////////////////////////////
    cout << "skips to a different battle" << endl;
    //////////////////////////////////////////////////
    cout << endl;

    Model boss2("BigBoss", 200, 5, 7, 10); //small boss

    std::cout << "You are fighting the Small Boss!" << '\n';

    while (!isDead(adv) && !isDead(boss2)) {
        do {
            std::cout << '\n'
                << "1 Normal Attack - 2 Special Attack(" << spaCounter
                << ") : ";
            std::cin >> advType;
        } while (advType < 1 || advType > 2);

        fight(advType, spaCounter, adv, boss2, rnd);
    }

    if (isDead(boss2)) {
        std::cout << "You defeated the Small Boss! You Win!" << '\n';
    }
    else {
        std::cout << "You are DEAD!" << '\n';
    }

    cout << endl;
    //////////////////////////////////////////////////
    cout << "skips to a different battle" << endl;
    //////////////////////////////////////////////////
    cout << endl;

    Model boss3("BigBoss", 350, 10, 20, 15); //medium boss

    std::cout << "You are fighting the Medium Boss!" << '\n';

    while (!isDead(adv) && !isDead(boss3)) {
        do {
            std::cout << '\n'
                << "1 Normal Attack - 2 Special Attack(" << spaCounter
                << ") : ";
            std::cin >> advType;
        } while (advType < 1 || advType > 2);

        fight(advType, spaCounter, adv, boss3, rnd);
    }

    if (isDead(boss3)) {
        std::cout << "You defeated the Medium Boss! You Win!" << '\n';
    }
    else {
        std::cout << "You are DEAD!" << '\n';
    }

    cout << endl;
    //////////////////////////////////////////////////
    cout << "skips to a different battle" << endl;
    //////////////////////////////////////////////////
    cout << endl;

    Model boss4("BigBoss", 400, 20, 30, 35); //large boss

    std::cout << "You are fighting the Large Boss!" << '\n';

    while (!isDead(adv) && !isDead(boss4)) {
        do {
            std::cout << '\n'
                << "1 Normal Attack - 2 Special Attack(" << spaCounter
                << ") : ";
            std::cin >> advType;
        } while (advType < 1 || advType > 2);

        fight(advType, spaCounter, adv, boss4, rnd);
    }

    if (isDead(boss4)) {
        std::cout << "You defeated the Large Boss! You Win!" << '\n';
    }
    else {
        std::cout << "You are DEAD!" << '\n';
    }

    return 0;

}

