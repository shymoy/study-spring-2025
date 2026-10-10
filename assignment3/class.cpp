#include "class.h"

Character::Character() {
    name = "default";
    profession = "default";
}

Character::Character(std::string name, std::string profession) : name(name), profession(profession){
}

std::string Character::get_name() const {
    return name;
}

void Character::set_name(std::string name) {
    if (!valiate_name(name)) return;
    this->name = name;
}

bool Character::valiate_name(std::string name) {
    if (name.size() > 8) {
        return false;
    }
    return true;
}
