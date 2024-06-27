#pragma once
#include <algorithm>
#include <deque>
#include <string>

class Car
{
private:
	bool isEngineOn;
	bool isHandBrakeActive;
	int speed;
	float fuelLevel;
	float maxFuelCapacity;
	float mileage;
	int currentGear;
	std::deque<std::string> events;

	void consumeFuel();
	void adjustSpeedForGearUp();
	void adjustSpeedForGearDown();
	void decreaseSpeedToZero(int value);
	void updateMileage();

	//display methods
	void addEvent(const std::string& event);

public:
	Car();
	void turnEngineOn();
	void turnEngineOff();
	void turnHandBrakeOn();
	void turnHandBrakeOff();
	void changeEngineStatus();
	void changeHandBrakeStatus();
	void accelerate();
	void brake();
	void refuel(int amount);
	void gearUp();
	void gearDown();
	void UpdateStatus();
	
	//Get methods
	bool getIsEngineOn() const;
	bool getIsHandBrakeActive() const;
	int getSpeed() const;
	float getFuelLevel() const;
	float getMileage() const;
	int getCurrentGear() const;
	void displayStatus() const;

	//Display methods
	void displayEvents() const;



};

