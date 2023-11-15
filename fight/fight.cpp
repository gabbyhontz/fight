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
    //Model adv("Wizard", 350, 35, 55, 0);
    Model boss("Boss", 50, 1, 2, 5);

    std::cout << "THE FIGHT BEGIN!" << '\n';
    
    int advType;
    int spaCounter = 5;
    while (!isDead(adv) && !isDead(boss)) {
        do {
            std::cout << '\n'
                << "1 Normal Attack - 2 Special Attack(" << spaCounter
                << ") : ";
            std::cin >> advType;
        } while (advType < 1 || advType > 2);

        fight(advType, spaCounter, adv, boss, rnd);
    }

    if (isDead(boss)) {
        std::cout << "You defeated the boss! You Win!" << '\n';
    }
    else {
        std::cout << "You are DEAD!" << '\n';
    }

    return 0;
}

