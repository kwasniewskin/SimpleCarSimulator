#pragma once
class Car
{
private:
	bool IsEngineOn;
	int speed;
	int fuelConsumption;
	int fuelLevel;
	int maxFuelCapacity;
	int milage;		//total distance traveled in km
	int currentGear;
	bool IsHandBrakeActive;
	int engineTemperature;

public:
	Car();
	void turnEngineOn();
	void turnEngineOff();
	void decreaseSpeedEngineOff();
	void accelerate();
	void brake();
	void refuel(int amount);
	void gearUp();
	void gearDown();
	void adjustSpeedForGearDown();
	void turnHandBrakeOn();
	void turnHandBrakeOff();
	void decreaseSpeedHandBrake();
	void adjustSpeedForGear();
	
	//Get methods
	bool isEngineOn() const;
	bool isHandBrakeActive() const;
	int getSpeed() const;
	int getFuelLevel() const;
	int getMilage() const;
	int getCurrentGear() const;
	int getEngineTemperature() const;
	void displayStatus() const;




};

