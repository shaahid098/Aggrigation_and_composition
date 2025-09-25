#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include "../Field.h"

TEST_CASE("Field with Corn crop") {
    Field field("Corn", 120, 150.0, 2.5, 10.0);

    SECTION("Total yield calculation") {
        REQUIRE(field.totalYield() == 1500.0);
    }

    SECTION("Total value calculation") {
        REQUIRE(field.totalValue() == 3750.0);
    }
}

TEST_CASE("Field with Wheat crop") {
    Field field("Wheat", 90, 100.0, 1.8, 5.0);

    SECTION("Total yield calculation") {
        REQUIRE(field.totalYield() == 500.0);
    }

    SECTION("Total value calculation") {
        REQUIRE(field.totalValue() == 900.0);
    }
}

TEST_CASE("Field with zero acres") {
    Field field("Soybean", 130, 200.0, 3.0, 0.0);

    SECTION("Zero-acre yield and value") {
        REQUIRE(field.totalYield() == 0.0);
        REQUIRE(field.totalValue() == 0.0);
    }
}
