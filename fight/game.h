#pragma once
// game.h
#pragma once
#include <iostream>
#include <random>
#include <string>

class Random {
private:
    std::mt19937 gen;

public:
    Random(unsigned int seed);
    int number(int min, int max);
};

class Model {
private:
    std::string name;
    int health;
    int attack;
    int spattack1;
    int spattack2;

public:
    Model();
    Model(std::string a, int b, int c, int d, int e);
    friend void fight(int advType, int& spaCounter, Model& player, Model& enemy,
                      Random& rnd);
    friend int getDamage(Random& rnd, Model& a, int advType, int& spaCounter);
    friend bool isDead(Model& adv);
};

void fight(int advType, int& spaCounter, Model& player, Model& enemy,
           Random& rnd);
int getDamage(Random& rnd, Model& a, int advType, int& spaCounter);
bool isDead(Model& a);

