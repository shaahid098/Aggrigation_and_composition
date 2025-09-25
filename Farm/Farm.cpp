#include "Farm.h"
#include <sstream>

Farm::~Farm() {
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

//Adds a field to the farm.
void Farm::addField(const Field &field) {
    fields.push_back(field);
}

//Adds an animal to the farm.
void Farm::addAnimal(Animal* animal) {
    animals.push_back(animal);
}

//Returns a string summarizing all the fields and animals on the farm.
std::string Farm::toString() const {
    std::stringstream ss;
    ss << "Farm Details:" <<"\n"<< std::endl;

    for (const Field &field : fields) {
        ss << field.toString() << "\n\n";
    }
    for (Animal *animal : animals) {
        ss <<animal->toString()<<"\n"
           <<"Dietary Requirement: "<<animal->dietaryRequirements() << "\n\n";
    }
    return ss.str();
}

//Calculates and returns the total yield from all fields.
double Farm::totalFarmYield() const {
    double total = 0.0;
    for (const Field& field : fields) {
        total += field.totalYield();  // this function already does (yield × size)
    }
    return total;
}


