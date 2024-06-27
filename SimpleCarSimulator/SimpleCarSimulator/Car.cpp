#include "Car.h"
#include <iostream>
#include <cmath>

using namespace std;

//Construction deffinition
Car::Car() :
	isEngineOn(false),
	speed(0),
	fuelLevel(30),
	maxFuelCapacity(50),
	currentGear(0),
	isHandBrakeActive(true),
	mileage(0)
{
}

#pragma region Function Implementation

void Car::turnEngineOn() {
	isEngineOn = true;
	addEvent("Engine turned on");
}

void Car::turnEngineOff() {
	isEngineOn = false;
	addEvent("Engine turned off");
}

void Car::changeEngineStatus() {
	if (getIsEngineOn()) {
		turnEngineOff();
		if (speed > 0) {
			decreaseSpeedToZero(20);
			addEvent("*You have turned off the engine while driving!");
		}
	}
	else {
		turnEngineOn();
	}
}

void Car::decreaseSpeedToZero(int value) {
	while(speed > 0) {
		speed -= value;
	}

	if (speed < 0) {
		speed = 0;
	}
}

void Car::turnHandBrakeOn() {
	isHandBrakeActive = true;
	addEvent("Hand brake active");
}

void Car::turnHandBrakeOff() {
	isHandBrakeActive = false;
	addEvent("Hand brake inactive");
}

void Car::changeHandBrakeStatus() {
	if (getIsHandBrakeActive()) {
		turnHandBrakeOff();
	}
	else {
		turnHandBrakeOn();
		if (speed != 0) {
			decreaseSpeedToZero(30);
			addEvent("*You have activated the handbrake while driving!");
		}
	}
}

void Car::gearUp() {
	if (currentGear < 6) {
		currentGear++;
		adjustSpeedForGearUp();
	}
	else {
		addEvent("You have reached the top gear.");
	}
	addEvent("Shift up");
}

void Car::gearDown() {
	if (currentGear > -1) {
		int previousGearMaxSpeed = currentGear * 30;
		currentGear--;
		adjustSpeedForGearDown();
	}
	else {
		addEvent("You have reached the lowest gear.");
	}
	addEvent("Shift down");
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
		addEvent("You are slowing down because you were driving too fast for that gear.");
		while(speed >= maxSpeedForCurrentGear) {
			speed -= 10;
		}
	}
}


void Car::refuel(int amount) {
	if (amount > 0 && (fuelLevel + amount) <= maxFuelCapacity) {
		fuelLevel += amount;
		addEvent("You have refueled " + to_string(amount) + " liters of fuel.");
	}
	else if ((fuelLevel + amount) > maxFuelCapacity) {
		fuelLevel = maxFuelCapacity;
		addEvent("Too much gas or too smaller tank!");
	}
}

void Car::brake() {
	if (speed > 0) {
		speed -= 10;
	}
}

void Car::accelerate() {
	if (isEngineOn == false) {
		addEvent("Unable to accelerate, engine is off.");
	}
	else if (isHandBrakeActive == true) {
		addEvent("Unable to accelerate, hand brake is on.");
	}
	else if (fuelLevel <= 0) {
		addEvent("Unable to accelerate, fuel level is empty.");
	}
	else if (currentGear == 0) {
		addEvent("Unable to accelerate, gear is in neutral.");
	}
	else {
		int maxSpeedForGear = currentGear * 30;
		if (speed < maxSpeedForGear) {
			speed += 10;
		}
		else {
			addEvent("Unable to accelerate further, change gear.");
		}
	}
}

void Car::updateMileage() {
	if (speed > 0) {
		float distance = speed / static_cast<float>(3600);
		mileage += distance;
	}
}

void Car::consumeFuel() {
	float fuelConsumption = 0.00f;

	if (isEngineOn) {
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
		addEvent("You have run out of fuel");
		turnEngineOff();
		if (speed > 0)
			decreaseSpeedToZero(20);
	}
}

void Car::UpdateStatus() {
	updateMileage();
	consumeFuel();
}

#pragma endregion

#pragma region GetMethods

bool Car::getIsEngineOn() const {
	return isEngineOn;
}

bool Car::getIsHandBrakeActive() const {
	return isHandBrakeActive;
}

int Car::getSpeed() const {
	return speed;
}

float Car::getFuelLevel() const {
	return fuelLevel;
}

float Car::getMileage() const {
	return mileage;
}

int Car::getCurrentGear() const {
	return currentGear;
}

#pragma endregion


#pragma region DisplayStatus

void Car::displayStatus() const {
	cout << "Engine Status: " << (isEngineOn ? "On" : "Off") << "\n";
	cout << "Speed: " << speed << " km/h\n";
	cout << "Fuel Level: " << round(fuelLevel * 100) / 100 << " liters\n";
	cout << "Mileage: " << round(mileage * 100) / 100 << " km\n";
	cout << "Current Gear: " << currentGear << "\n";
	cout << "Hand brake Status: " << (isHandBrakeActive ? "On" : "Off") << " \n";
}

void Car::addEvent(const string& event) {
	// Add the event to the list
	events.push_back(event);

	// If there are more than 5 events, remove the oldest
	while (events.size() > 5) {
		events.pop_front();
	}
}

void Car::displayEvents() const {
	// Display the last 5 events
	cout << "RECENT EVENTS:" << endl;
	for (const auto& e : events) {		// const ensures the elements are read-only during iteration
		cout << e << endl;				// auto automatically deduces the type (in this case, const string&)
	}
}

#pragma endregion



