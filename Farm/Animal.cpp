#include "Animal.h"
#include <sstream>

//Implementing constructor
Animal::Animal(std::string animalName, double weight)
        :name(animalName),weight(weight){}

std::string Animal::toString() const {
        std::stringstream ss;
        ss <<"Animal Name is: "<<name<< " "
           <<",Weight: "<< weight << " KG ";
        return ss.str();
}
