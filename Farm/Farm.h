#ifndef FARM_H
#define FARM_H
#include <vector>
#include <string>
#include "Field.h"
#include "Animal.h"

/*
 * Class: Farm
 * ------------
 * Holds a collection of fields and a list of animals (using pointers).
 * Uses aggregation for animals — does not own them but is responsible for deleting them.
 */

class Farm {
private:
    std::vector<Field> fields;
    std::vector<Animal*> animals;

public:
    ~Farm();
    void addField(const Field& field); //Adds a field to the farm.
    void addAnimal(Animal* animal); //Adds an animal to the farm.
    std::string toString() const; //Returns a string summarizing all the fields and animals on the farm.
    double totalFarmYield() const; //Calculates and returns the total yield from all fields.


};

#endif // FARM_H
