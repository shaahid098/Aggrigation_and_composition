#include "Crop.h"
#include <sstream>

//constructor
Crop::Crop(std::string cropName, int harvestTime, double yield, double price)
        :name(cropName),harvestTime(harvestTime),yieldPerAcre(yield),pricePerUnit(price) {}

//Returns a string summarizing the crop's details.
std::string Crop::displayInfo() const {
        std::stringstream ss;
        ss <<"Crop: "<<name
           <<", Harvest Time: "<<harvestTime<<" days"
           <<", Yield: "<<yieldPerAcre<<" units per acre"
           <<", Price: $"<<pricePerUnit<<" per unit";
        return ss.str();
}
//Returns the yield per acre as a double.
double Crop::getYieldPerAcre() const {
    return yieldPerAcre;
}

//Returns the price per unit as a double.
double Crop::getPricePerUnit() const {
    return pricePerUnit;
}
