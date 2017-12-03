#include "Config.hpp"
#include "common/debug.hpp"
#include "json.hpp"
#include <fstream>



Config::Config(std::string filename) {
    std::ifstream i(filename);
    if (! i.is_open())  {
        ERROR << "can't open : \'" << filename << "\', default config will be loaded\n";
        return;
    }
    nlohmann::json json;
    i >> json;

    enemyInOneRound = json.at("enemyInOneRound").get<unsigned>();
    maxEnemyAtTheSameTime = json.at("maxEnemyAtTheSameTime").get<unsigned>();
    numberOfTrees = json.at("numberOfTrees").get<unsigned>();
    numberOfBarrels = json.at("numberOfBarrels").get<unsigned>();
    numberOfSandbags = json.at("numberOfSandbags").get<unsigned>();
}

const Config& Config::getConfig(std::string filename) {
    static Config config(filename);
    return config;
}
