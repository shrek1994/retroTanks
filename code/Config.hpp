#pragma once
#include <string>
#include <memory>


class Config
{
public:
    static const Config& getConfig(std::string filename = "res/config.json");
    Config(Config&) = delete;
    Config(Config&&) = delete;
    Config& operator= (Config&) = delete;
    Config& operator= (Config&&) = delete;

    unsigned enemyInOneRound = 100;
    unsigned maxEnemyAtTheSameTime = 10;
    unsigned numberOfTrees = 10;
    unsigned numberOfBarrels = 30;
    unsigned numberOfSandbags = 30;

private:
    Config(std::string filename);
};
