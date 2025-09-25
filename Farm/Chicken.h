#ifndef CHICKEN_H
#define CHICKEN_H
#include "Animal.h"

/*
 * Classes: Chicken
 * ---------------------------
 *derived from Animal.
 *Implements dietaryRequirements() differently.
 */
class Chicken: public Animal {
public:
    //Constructor
    Chicken(std::string name,double weight);
    std::string dietaryRequirements() const override;

};
#endif // CHICKEN_H
