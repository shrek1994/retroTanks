#pragma once
#include <string>


class Config
{
public:
    Config(std::string filename = "res/config.json");

    unsigned enemyInOneRound = 100;
    unsigned maxEnemyAtTheSameTime = 10;

};
