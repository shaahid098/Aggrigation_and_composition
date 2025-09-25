#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "../Animal.h"
#include "../Cow.h"
#include "../Chicken.h"
#include "../Pig.h"

TEST_CASE("Cow dietary requirements") {
    Cow bessie("Bessie", 700.0);

    SECTION("Dietary requirements for Bessie include correct amount and feed type") {
        CHECK_THAT(bessie.dietaryRequirements(), Catch::Matchers::ContainsSubstring("1750"));
        CHECK_THAT(bessie.dietaryRequirements(), Catch::Matchers::ContainsSubstring("grass"));
    }

    SECTION("Handles different cow weight correctly") {
        Cow daisy("Daisy", 650.0);
        CHECK_THAT(daisy.dietaryRequirements(), Catch::Matchers::ContainsSubstring("1625"));
        CHECK_THAT(daisy.dietaryRequirements(), Catch::Matchers::ContainsSubstring("grass"));
    }
}

TEST_CASE("Chicken dietary requirements") {
    Chicken clucky("Clucky", 2.5);

    SECTION("Dietary requirements for Clucky include correct amount and feed type") {
        CHECK_THAT(clucky.dietaryRequirements(), Catch::Matchers::ContainsSubstring("0.25"));
        CHECK_THAT(clucky.dietaryRequirements(), Catch::Matchers::ContainsSubstring("grain"));
    }

    SECTION("Handles different chicken weight correctly") {
        Chicken nugget("Nugget", 3.0);
        CHECK_THAT(nugget.dietaryRequirements(), Catch::Matchers::ContainsSubstring("0.3"));
        CHECK_THAT(nugget.dietaryRequirements(), Catch::Matchers::ContainsSubstring("grain"));
    }
}

TEST_CASE("Pig dietary requirements") {
    Pig porky("Porky", 150.0);

    SECTION("Dietary requirements for Porky include correct amount and feed type") {
        CHECK_THAT(porky.dietaryRequirements(), Catch::Matchers::ContainsSubstring("7.5"));
        CHECK_THAT(porky.dietaryRequirements(), Catch::Matchers::ContainsSubstring("feed"));
    }

    SECTION("Handles different pig weight correctly") {
        Pig bacon("Bacon", 100.0);
        CHECK_THAT(bacon.dietaryRequirements(), Catch::Matchers::ContainsSubstring("5"));
        CHECK_THAT(bacon.dietaryRequirements(), Catch::Matchers::ContainsSubstring("feed"));
    }
}
