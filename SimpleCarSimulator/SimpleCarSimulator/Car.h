#pragma once
class Car
{
private:
	bool IsEngineOn;
	int speed;
	float fuelLevel;
	int maxFuelCapacity;
	float milage;
	int currentGear;
	bool IsHandBrakeActive;

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
	float getMilage() const;
	int getCurrentGear() const;
	void displayStatus() const;




};

