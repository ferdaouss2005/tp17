#include "Config.h"
#include <fstream>
#include <iostream>

Config::Config() {
}

void Config::charger(const std::string& fichier) {
    std::ifstream file(fichier);

    if (!file.is_open()) {
        std::cout << "Erreur d'ouverture du fichier" << std::endl;
        return;
    }

    std::string ligne;

    while (std::getline(file, ligne)) {
        size_t pos = ligne.find(':');

        if (pos != std::string::npos) {
            std::string cle = ligne.substr(0, pos);
            std::string valeur = ligne.substr(pos + 1);

            cle.erase(0, cle.find_first_not_of(" \"{"));
            cle.erase(cle.find_last_not_of(" \",}") + 1);

            valeur.erase(0, valeur.find_first_not_of(" \""));
            valeur.erase(valeur.find_last_not_of(" \",}") + 1);

            donnees[cle] = valeur;
        }
    }

    file.close();
}

std::string Config::get(const std::string& cle) const {
    auto it = donnees.find(cle);

    if (it != donnees.end()) {
        return it->second;
    }

    return "Cle introuvable";
}
