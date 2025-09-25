#ifndef FIELD_H
#define FIELD_H
#include "Crop.h"

/*
 * Class: Field
 * ------------
 * Represents a farm field that contains a single crop and has a specific size in acres.
 * Uses composition: Field "has-a" Crop.
 */

class Field {
private:
    Crop crop;
    double sizeInAcres;

public:
    //Initializes the field using an initializer list to set the crop.
    Field(std::string cropName, int harvestTime, double yield, double price,double sizeInAcres);

    //Returns a string summarizing the crop details, field size, and total value.
    std::string toString() const;

    //Calculates and returns the total crop yield based on the field size.
    double totalYield() const;

    //Calculates and returns the total value based on the total yield and price per unit.
    double totalValue() const;


};
#endif // FIELD_H
