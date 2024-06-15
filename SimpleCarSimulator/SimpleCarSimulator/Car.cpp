#include "Car.h"
#include <iostream>

using namespace std;

//Construction deffinition
Car::Car() :
	IsEngineOn(false),
	speed(0),
	fuelConsumption(5),
	fuelLevel(40),
	maxFuelCapacity(50),
	currentGear(0),
	engineTemperature(25),
	IsHandBrakeActive(true),
	milage(0)
{

}

//function implementation
void Car::turnEngineOn() {
	IsEngineOn = true;
}

void Car::turnEngineOff() {
	IsEngineOn = false;
}

void Car::turnHandBrakeOn() {
	IsHandBrakeActive = true;
}

void Car::turnHandBrakeOff() {
	IsHandBrakeActive = false;
}

void Car::gearUp() {
	if (currentGear < 6) {
		currentGear++;
	}
}

void Car::gearDown() {
	if (currentGear >= 0) {
		currentGear--;
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
	if (speed >= 20) {
		speed -= 20;
	}
}

void Car::accelerate() {
	if (IsHandBrakeActive == false && IsEngineOn == true && fuelLevel > 0 && currentGear != 0) {
		speed += 20;
	}
}

//Get methods

bool Car::isEngineOn() const {
	return IsEngineOn;
}

bool Car::isHandBrakeActive() const {
	return IsHandBrakeActive;
}

int Car::getSpeed() const {
	return speed;
}

int Car::getFuelLevel() const {
	return fuelLevel;
}

int Car::getMilage() const {
	return milage;
}

int Car::getCurrentGear() const {
	return currentGear;
}

int Car::getEngineTemperature() const {
	return engineTemperature;
}
	
void Car::displayStatus() const {
	cout << "Engine Status: " << (IsEngineOn ? "On" : "Off") << "\n";
	cout << "Speed: " << speed << " km/h\n";
	cout << "Fuel Level: " << fuelLevel << " liters\n";
	cout << "Mileage: " << milage << " km\n";
	cout << "Current Gear: " << currentGear << "\n";
	cout << "Engine Temperature: " << engineTemperature << " °C\n";
	cout << "Hand brake Status: " << (IsHandBrakeActive ? "On" : "Off") << " \n";
}