#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

class Config {
private:
    std::map<std::string, std::string> donnees;

public:
    Config();
    void charger(const std::string& fichier);
    std::string get(const std::string& cle) const;
};

#endif
