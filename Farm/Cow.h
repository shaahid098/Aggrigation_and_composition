#ifndef COW_H
#define COW_H
#include "Animal.h"

/*
 * Classes: Cow
 * ---------------------------
 *derived from Animal.
 *Implements dietaryRequirements() differently.
 */

class Cow: public Animal {
public:
    //Constructor
    Cow(std::string name,double weight);
    std::string dietaryRequirements() const override;

};

#endif // COW_H
