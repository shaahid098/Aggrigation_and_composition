#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include "../Crop.h"

TEST_CASE("Crop class with valid values") {
    Crop corn("Corn", 120, 150.0, 2.5);

    SECTION("Verify crop attributes") {
        REQUIRE(corn.getYieldPerAcre() == 150.0);
        REQUIRE(corn.getPricePerUnit() == 2.5);
    }

    SECTION("DisplayInfo format test") {
        std::string expected = "Crop: Corn, Harvest Time: 120 days, Yield: 150 units per acre, Price: $2.5 per unit";
        REQUIRE(corn.displayInfo() == expected);
    }
}

TEST_CASE("Crop class with different values") {
    Crop wheat("Wheat", 90, 100.0, 1.8);

    SECTION("Verify crop attributes") {
        REQUIRE(wheat.getYieldPerAcre() == 100.0);
        REQUIRE(wheat.getPricePerUnit() == 1.8);
    }

    SECTION("DisplayInfo format test") {
        std::string expected = "Crop: Wheat, Harvest Time: 90 days, Yield: 100 units per acre, Price: $1.8 per unit";
        REQUIRE(wheat.displayInfo() == expected);
    }
}

TEST_CASE("Edge case: Crop with zero yield") {
    Crop emptyCrop("Empty", 30, 0.0, 1.0);

    SECTION("Verify zero yield handling") {
        REQUIRE(emptyCrop.getYieldPerAcre() == 0.0);
    }
}
