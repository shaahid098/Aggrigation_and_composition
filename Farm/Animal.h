#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

/*
 * Class: Animal (Abstract)
 * -------------------------
 * Base class for all animals on the farm.
 * Stores name and weight. Requires derived classes to define dietary needs.
 * Uses polymorphism for dietary requirements.
 */
class Animal {
protected:
    std::string name; //The animal’s name.
    double weight; // Weight of the animal in kilograms.
public:
    //Constructor-Initializes the animal's attributes.
    Animal(std::string animalName,double weight);

    /*
     *Returns a string summarizing the animal’s details.
     *Virtual function
    */
    virtual std::string toString() const;

    //Pure virtual function
    virtual std::string dietaryRequirements() const=0;


};
#endif // ANIMAL_H
