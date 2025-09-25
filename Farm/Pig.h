#ifndef PIG_H
#define PIG_H
#include "Animal.h"

/*
 * Classes: Pig
 * ---------------------------
 * derived from Animal.
 * Implements dietaryRequirements() differently.
 */

class Pig: public Animal {
public:
    //Constructor
    Pig(std::string name,double weight);
    std::string dietaryRequirements() const override;

};

#endif // PIG_H
