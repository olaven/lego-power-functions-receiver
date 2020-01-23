#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "../src/lego-power-functions-receiver.cpp"



TEST_CASE("Class Values") {

    SECTION("Default values are correct") {

        const int expected_pin = 10;
        const int expected_channel = 2;
        const int expected_output = LPF_RECEIVER_BLUE;
        const int expected_speed = 7; //i.e. middle step

        LegoPowerFunctions * lpf = new LegoPowerFunctions(expected_pin, expected_channel, expected_output);
        REQUIRE(lpf->led_pin == expected_pin);
        REQUIRE(lpf->channel == expected_channel);
        REQUIRE(lpf->output == expected_output);
        REQUIRE(lpf->speed == expected_speed);
    }

}

TEST_CASE("Speed regulation") {

    SECTION("going up") {

        LegoPowerFunctions * lpf = new LegoPowerFunctions(10, 2, LPF_RECEIVER_RED);
        for(int i = lpf->speed; i < 14; i++) {

            lpf->step_forwards();
            REQUIRE(lpf->speed == i + 1);
        }

        for(int i = 0; i < 10; i++) {

            lpf->step_forwards();
            REQUIRE(lpf->speed == 14);
        }
    }


    SECTION("going down") {

        LegoPowerFunctions * lpf = new LegoPowerFunctions(10, 2, LPF_RECEIVER_RED);
        for(int i = lpf->speed; i > 0; i--) {

            lpf->step_backwards();
            REQUIRE(lpf->speed == i - 1);
        }

        for(int i = 0; i < 10; i++) {

            lpf->step_backwards();
            REQUIRE(lpf->speed == 0);
        }
    }

    SECTION("stopping") {

        LegoPowerFunctions * lpf = new LegoPowerFunctions(10, 2, LPF_RECEIVER_RED);

        lpf->step_forwards();
        REQUIRE(lpf->speed != 7);

        lpf->stop();
        REQUIRE(lpf->speed == 7);

        lpf->step_backwards();
        REQUIRE(lpf->speed != 7);

        lpf->stop();
        REQUIRE(lpf->speed == 7);
    }
}


