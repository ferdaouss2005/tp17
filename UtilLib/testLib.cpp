#include <iostream>
#include "Logger.h"
#include "Config.h"

int main() {
    Logger::getInstance().log("Application demarree");

    Config config;
    config.charger("config.json");

    std::cout << "Nom : " << config.get("nom") << std::endl;

    return 0;
}

