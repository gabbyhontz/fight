// game.cpp
#include "game.h"

Random::Random(unsigned int seed) : gen(seed) {}

int Random::number(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return (dist(gen));
}

Model::Model() : name(""), health(0), attack(0), spattack1(0), spattack2(0) {}

Model::Model(std::string a, int b, int c, int d, int e)
    : name(a), health(b), attack(c), spattack1(d), spattack2(e) {}

void fight(int advType, int& spaCounter, Model& player, Model& enemy,
           Random& rnd) {
    // player attack
    int damage = getDamage(rnd, player, advType, spaCounter);
    enemy.health -= damage;
    std::cout << player.name << " deals : " << damage << " to... \n" << enemy.name
              << " -- health left : " << enemy.health << '\n';

    if (isDead(enemy))
        return;

    // enemy attack
    damage = getDamage(rnd, enemy, 0, spaCounter);
    player.health -= damage;
    std::cout << enemy.name << " deals : " << damage << " to... \n" << player.name
              << " -- health left : " << player.health << '\n';
}

int getDamage(Random& rnd, Model& a, int advType, int& spaCounter) {
    // crit
    int crit = 1;
    if (rnd.number(0, 99) == 99)
        crit = 2;

    // adv damage
    if (advType == 1 && spaCounter == 0)
        return (a.attack * crit);
    else if (advType == 2 && spaCounter > 0) {
        spaCounter--;
        return (a.spattack1 * crit);
    }

    // enemy damage
    int enemyType = rnd.number(0, 99);
    if (enemyType > 94 && enemyType <= 99 && a.name == "BigBoss")
        return (a.spattack2 * crit);
    else if (enemyType > 79 && enemyType <= 99 &&
             (a.name == "Crocodile" || a.name == "BigBoss"))
        return (a.spattack1 * crit);
    else
        return (a.attack * crit);
}

bool isDead(Model& a) {
    return (a.health <= 0 ? true : false);
}
