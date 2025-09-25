#include "Field.h"
#include <sstream>

/*
 * @param Implementation of field class header
*/

//Implementing constructor value
Field::Field(std::string cropName, int harvestTime, double yield, double price, double sizeInAcres)
    : crop(cropName, harvestTime, yield, price), sizeInAcres(sizeInAcres) {}

std::string Field::toString() const {
    std::stringstream ss;
    ss<<"Field Size: "<<sizeInAcres<<" Acres \n"
      <<crop.displayInfo()<<"\n"
      <<"Total Price: $"<<totalValue()<<"\n";
    return ss.str();
}

//Calculates and returns the total crop yield based on the field size.
double Field::totalYield() const {
    return crop.getYieldPerAcre() * sizeInAcres;
}

//Calculates and returns the total value based on the total yield and price per unit.
double Field::totalValue() const {
    return totalYield() * crop.getPricePerUnit();
}

