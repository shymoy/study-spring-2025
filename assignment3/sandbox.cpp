/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include <iostream>

#include "class.h"
void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
    Character c;
    Character cn("Red A", "Archer");
    std::cout << c.get_name() << "," << cn.get_name();
}