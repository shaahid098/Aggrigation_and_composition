#include "Cow.h"
#include <sstream>

//Implementing constructor
Cow::Cow(std::string name, double weight)
    :Animal(name, weight) {}

//"Requires 2.5 kg of grass per kg of body weight."
std::string Cow::dietaryRequirements() const {
    double grass= 2.5 * weight;
    std::stringstream ss;
    ss << "Cow requires " << grass << " kg of grass per day";
    return ss.str();
}

