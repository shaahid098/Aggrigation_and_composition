#include "farm.h"
#include "Cow.h"
#include "Chicken.h"
#include "Pig.h"
#include <fstream>
#include "sstream"
#include <iostream>

/*
 * Program: FarmDriver
 * --------------------
 * The main function of the Farm Management System.
 * Reads field/crop and animal data from CSV files,
 * populates the farm, and prints full details.
 */


//Reads crop data from data/crops.csv and creates Field objects.
void readCropsFromFile(const std::string& filename, Farm& farm) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int harvestTime;
        double yield, price, size;

        getline(ss, name,',');
        ss >> harvestTime; ss.ignore();
        ss >> yield; ss.ignore();
        ss >> price; ss.ignore();
        ss >> size;

        Field field(name, harvestTime, yield, price, size);
        farm.addField(field);
    }

}


// Reads animal data from data/animals.csv and allocates animals dynamically.
void readAnimalsFromFile(const std::string& filename, Farm& farm) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type,name;
        double weight;
        getline(ss, type, ',');
        getline(ss, name, ',');
        ss >> weight;

        Animal* animal = nullptr;
        if (type == "Cow")
            animal = new Cow(name, weight);
        else if (type == "Chicken")
            animal = new Chicken(name, weight);
        else if (type == "Pig")
            animal = new Pig(name, weight);

        if (animal) {
            farm.addAnimal(animal);
        }
    }

}
int main() {

    Farm myFarm;
    readCropsFromFile("data/crops.csv", myFarm);
    readAnimalsFromFile("data/animals.csv", myFarm);

    std::cout << myFarm.toString();
    std::cout << "Total Farm Yield: " << myFarm.totalFarmYield() << " units\n";

    return 0;

    return 0;
}
