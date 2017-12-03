#include "Config.hpp"
#include "debug.hpp"
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

    DEBUG << json << "\n";
    DEBUG << enemyInOneRound << "\n";
    DEBUG << maxEnemyAtTheSameTime << "\n";
}
