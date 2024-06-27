#pragma once
#include <algorithm>
#include <deque>
#include <string>

class Car
{
private:
	bool IsEngineOn;
	int speed;
	float fuelLevel;
	int maxFuelCapacity;
	float mileage;
	int currentGear;
	bool IsHandBrakeActive;
	std::deque<std::string> events;

public:
	Car();
	void turnEngineOn();
	void turnEngineOff();
	void changeEngineStatus();
	void accelerate();
	void brake();
	void consumeFuel();
	void refuel(int amount);
	void gearUp();
	void gearDown();
	void adjustSpeedForGearUp();
	void adjustSpeedForGearDown();
	void turnHandBrakeOn();
	void turnHandBrakeOff();
	void changeHandBrakeStatus();
	void decreaseSpeed(int value);
    void updateMileage();
	void UpdateStatus();
	
	//Get methods
	bool isEngineOn() const;
	bool isHandBrakeActive() const;
	int getSpeed() const;
	float getFuelLevel() const;
	float getMileage() const;
	int getCurrentGear() const;
	void displayStatus() const;

	//Display methods
	void displayEvents() const;
	void addEvent(const std::string& event);



};

