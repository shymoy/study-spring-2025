#include <string>

#ifndef  CS106L_A3_CHARACTER_H
#define CS106L_A3_CHARACTER_H

class Character {
private:
    std::string name;
    std::string profession;
    bool valiate_name(std::string name);

public:
    Character();
    Character(std::string name, std::string profession);

    std::string get_name() const;
    void set_name(std::string name);
};

#endif
