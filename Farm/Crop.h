#ifndef CROP_H
#define CROP_H
#include <string>


/*
 * Class: Crop
 * ------------
 * Represents a crop with a name, harvest time, yield per acre, and price per unit.
 * Used by Field class for yield and value calculations.
 */
class Crop {
private:
    std::string name; //Name of the crop (e.g., "Corn").
    int harvestTime; //Number of days required for harvest.
    double yieldPerAcre; //Units produced per acre.
    double pricePerUnit; //Price per unit of yield.
public:
    //Constructor-Initializes the crop’s attributes with the given parameters.
    Crop(std::string cropName,int harvestTime,double yield,double price);


    std:: string displayInfo() const; //Returns a string summarizing the crop's details.

    //getters
    double getYieldPerAcre() const; //Returns the yield per acre as a double.
    double getPricePerUnit() const; //Returns the price per unit as a double.


};

#endif // CROP_H
