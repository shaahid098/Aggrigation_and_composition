#include "Chicken.h"
#include <sstream>

//Implementing constructor
Chicken::Chicken(std::string name, double weight)
    :Animal(name, weight) {}

//"Requires 0.1 kg of grain per kg of body weight."
std::string Chicken::dietaryRequirements() const {
    double grains= 0.1 * weight;
    std::stringstream ss;
    ss << "Chicken requires " << grains << " kg of grains per day";
    return ss.str();
}
