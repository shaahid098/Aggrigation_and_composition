#include "Pig.h"
#include <sstream>

//Implementing constructor
Pig::Pig(std::string name, double weight)
    :Animal(name, weight) {}

//"Requires 2.5 kg of grass per kg of body weight."
std::string Pig::dietaryRequirements() const {
    double mixedFeed= 0.05 * weight;
    std::stringstream ss;
    ss << "Cow requires " << mixedFeed << " kg of mixed feed per day";
    return ss.str();
}

