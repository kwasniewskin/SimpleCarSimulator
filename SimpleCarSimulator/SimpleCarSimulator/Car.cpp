#include "Car.h"
#include <iostream>
#include <cmath>

using namespace std;

//Construction deffinition
Car::Car() :
	IsEngineOn(false),
	speed(0),
	fuelLevel(30),
	maxFuelCapacity(50),
	currentGear(0),
	IsHandBrakeActive(true),
	milage(0)
{
}

#pragma region Function Implementation

void Car::turnEngineOn() {
	IsEngineOn = true;
}

void Car::turnEngineOff() {
	IsEngineOn = false;
}

void Car::changeEngineStatus() {
	if (isEngineOn()) {
		turnEngineOff();
		if (speed > 0)
			decreaseSpeed(20);
	}
	else {
		turnEngineOn();
	}
}

void Car::decreaseSpeed(int value) {
	if (speed > 0) {
		speed -= value;
	}

	if (speed < 0) {
		speed = 0;
	}
}

void Car::turnHandBrakeOn() {
	IsHandBrakeActive = true;
}

void Car::turnHandBrakeOff() {
	IsHandBrakeActive = false;
}

void Car::changeHandBrakeStatus() {
	if (isHandBrakeActive()) {
		turnHandBrakeOff();
	}
	else {
		turnHandBrakeOn();
		if (speed != 0)
			decreaseSpeed(30);
	}
}

void Car::gearUp() {
	if (currentGear < 6) {
		currentGear++;
		adjustSpeedForGearUp();
	}
}

void Car::gearDown() {
	if (currentGear > -1) {
		int previousGearMaxSpeed = currentGear * 30;
		currentGear--;
		adjustSpeedForGearDown();
	}
}

void Car::adjustSpeedForGearUp() {
	int maxSpeedForGear = currentGear * 30;
	if (speed > maxSpeedForGear) {
		speed = maxSpeedForGear;
	}
}

void Car::adjustSpeedForGearDown() {
	int maxSpeedForCurrentGear = currentGear * 30;
	if (speed > maxSpeedForCurrentGear) {
		speed -= 10;
	}
}


void Car::refuel(int amount) {
	if (amount > 0 && (fuelLevel + amount) <= maxFuelCapacity) {
		fuelLevel += amount;
	}
	else if ((fuelLevel + amount) > maxFuelCapacity) {
		//cout << "Too much gas or too smaller tank!"
	}
}

void Car::brake() {
	if (speed > 0) {
		speed -= 10;
	}
}

void Car::accelerate() {
	if (IsHandBrakeActive == false && IsEngineOn == true && fuelLevel > 0 && currentGear != 0) {
		int maxSpeedForGear = currentGear * 30;
		if (speed < maxSpeedForGear && fuelLevel > 0) {
			speed += 10;
		}
	}
}

void Car::updateMileage() {
	if (speed > 0) {
		float distance = speed / static_cast<float>(3600);
		milage += distance;
	}
}

void Car::consumeFuel() {
	float fuelConsumption = 0.00f;

	if (IsEngineOn) {
		fuelConsumption = 0.005f;
	}

	if (speed > 0) {
		fuelConsumption = speed / 360.0f;
	}

	fuelLevel -= fuelConsumption;
	if (fuelLevel < 0) {
		fuelLevel = 0; // Ensure fuel level never goes below 0
		turnEngineOff();
	}
	if (fuelLevel == 0) {
		turnEngineOff();
		if (speed > 0)
			decreaseSpeed(20);
	}
}

void Car::UpdateStatus() {
	updateMileage();
	consumeFuel();
}

#pragma endregion

#pragma region GetMethods

bool Car::isEngineOn() const {
	return IsEngineOn;
}

bool Car::isHandBrakeActive() const {
	return IsHandBrakeActive;
}

int Car::getSpeed() const {
	return speed;
}

float Car::getFuelLevel() const {
	return fuelLevel;
}

float Car::getMilage() const {
	return milage;
}

int Car::getCurrentGear() const {
	return currentGear;
}

void Car::displayStatus() const {
	cout << "Engine Status: " << (IsEngineOn ? "On" : "Off") << "\n";
	cout << "Speed: " << speed << " km/h\n";
	cout << "Fuel Level: " << round(fuelLevel * 100) / 100 << " liters\n";
	cout << "Mileage: " << round(milage * 100) / 100 << " km\n";
	cout << "Current Gear: " << currentGear << "\n";
	cout << "Hand brake Status: " << (IsHandBrakeActive ? "On" : "Off") << " \n";
}

#pragma endregion


