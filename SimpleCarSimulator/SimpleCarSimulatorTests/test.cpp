#include "pch.h"
#include <gtest/gtest.h>
#include "../SimpleCarSimulator/Car.cpp"

class CarTest : public ::testing::Test {
protected:
    Car car;

    void SetUp() override {
        // Setup code if needed.
    }
};

TEST_F(CarTest, InitializesCorrectly) {
    EXPECT_FALSE(car.getIsEngineOn());
    EXPECT_EQ(car.getSpeed(), 0);
    EXPECT_EQ(car.getFuelLevel(), 30);
    EXPECT_EQ(car.getCurrentGear(), 0);
    EXPECT_TRUE(car.getIsHandBrakeActive());
}

TEST_F(CarTest, EngineOnOff) {
    car.turnEngineOn();
    EXPECT_TRUE(car.getIsEngineOn());

    car.turnEngineOff();
    EXPECT_FALSE(car.getIsEngineOn());
}

TEST_F(CarTest, ChangeEngineStatus) {
    car.changeEngineStatus();
    EXPECT_TRUE(car.getIsEngineOn());

    car.changeEngineStatus();
    EXPECT_FALSE(car.getIsEngineOn());
}

TEST_F(CarTest, TurnHandBrakeOnOff) {
    car.turnHandBrakeOff();
    EXPECT_FALSE(car.getIsHandBrakeActive());

    car.turnHandBrakeOn();
    EXPECT_TRUE(car.getIsHandBrakeActive());
}

TEST_F(CarTest, ChangeHandBrakeStatus) {
    car.changeHandBrakeStatus();
    EXPECT_FALSE(car.getIsHandBrakeActive());

    car.changeHandBrakeStatus();
    EXPECT_TRUE(car.getIsHandBrakeActive());
}

TEST_F(CarTest, AccelerateAndBrake) {
    car.turnEngineOn();
    car.turnHandBrakeOff();
    car.gearUp(); // Move to first gear to allow acceleration.

    car.accelerate();
    EXPECT_GT(car.getSpeed(), 0);

    car.brake();
    EXPECT_EQ(car.getSpeed(), 0);
}

TEST_F(CarTest, Refuel) {
    car.refuel(10);
    EXPECT_EQ(car.getFuelLevel(), 40);

    car.refuel(20); // Attempt to overfill.
    EXPECT_EQ(car.getFuelLevel(), 50); // Max capacity.
}

TEST_F(CarTest, GearManagement) {
    car.gearUp();
    EXPECT_EQ(car.getCurrentGear(), 1);

    car.gearDown();
    EXPECT_EQ(car.getCurrentGear(), 0);
}
TEST_F(CarTest, MileageUpdate) {
    car.turnEngineOn();
    car.turnHandBrakeOff();
    car.gearUp();
    car.accelerate();
    car.UpdateStatus(); // Simulate driving for some time.

    EXPECT_GT(car.getMileage(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}