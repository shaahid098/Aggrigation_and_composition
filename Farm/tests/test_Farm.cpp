#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include "../Farm.h"
#include "../Cow.h"
#include "../Chicken.h"
#include "../Pig.h"
#include "../Field.h"

TEST_CASE("Adding fields to farm") {
    Farm farm;
    Field field1("Corn", 120, 150.0, 2.5, 10.0);
    Field field2("Wheat", 90, 100.0, 1.8, 5.0);

    farm.addField(field1);
    farm.addField(field2);

    SECTION("Total farm yield calculation") {
        REQUIRE(farm.totalFarmYield() == 2000.0);
    }
}

TEST_CASE("Adding animals to farm") {
    Farm farm;
    Cow* bessie = new Cow("Bessie", 700.0);
    Chicken* clucky = new Chicken("Clucky", 2.5);
    Pig* porky = new Pig("Porky", 150.0);

    farm.addAnimal(bessie);
    farm.addAnimal(clucky);
    farm.addAnimal(porky);

    SECTION("Farm summary contains all animals") {
        std::string summary = farm.toString();
        REQUIRE(summary.find("Bessie") != std::string::npos);
        REQUIRE(summary.find("Clucky") != std::string::npos);
        REQUIRE(summary.find("Porky") != std::string::npos);
        REQUIRE(summary.find("Field size") == std::string::npos);
        // REQUIRE(summary.find("Animal") == std::string::npos);
    }
}

TEST_CASE("Farm with no animals or fields") {
    Farm farm;

    SECTION("Empty farm summary") {
        std::string summary = farm.toString();
        REQUIRE(summary.find("Field size") == std::string::npos);
//        REQUIRE(summary.find("Animal") == std::string::npos);
    }
}
