# Simple Car Simulator

Welcome to the Simple Car Simulator! This project is designed to simulate basic car functionalities, allowing users to interact with the car's engine, handbrake, gears, fuel, and speed. The simulator provides real-time feedback on the car's status and events, making it an engaging tool for understanding car mechanics.

## Table of Contents

1. [Features](#features)
2. [Presentation](#presentation)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Class and Function Details](#class-and-function-details)
6. [Contributing](#contributing)
7. [Contact](#contact)
8. [License](#license)

## Features

- Turn the engine on and off
- Activate and deactivate the handbrake
- Shift gears up and down
- Accelerate and brake the car
- Refuel the car
- Display the current status of the car
- Log and display recent events

## Presentation

Here's a brief walkthrough of what you'll see when you run the Simple Car Simulator.

### Initial Screen

When you start the simulator, you'll see the current status of the car and a list of available actions:

```
Engine Status: Off
Speed: 0 km/h
Fuel Level: 30 liters
Mileage: 0 km
Current Gear: 0
Hand brake Status: On

Choose one of the following actions:
Num 0. Turn Engine On/Off
Num 1. Turn Handbrake On/Off
Num 2. Gear Up
Num 3. Gear Down
Num 4. Refuel
Num -. Brake
Num +. Accelerate
Num 9. Exit

RECENT EVENTS:
```

### Performing Actions

As you interact with the simulator, the car's status will update in real-time. For example, turning the engine on and accelerating will update the display:

```
Engine Status: On
Speed: 10 km/h
Fuel Level: 29.99 liters
Mileage: 0.02 km
Current Gear: 1
Hand brake Status: Off

Choose one of the following actions:
Num 0. Turn Engine On/Off
Num 1. Turn Handbrake On/Off
Num 2. Gear Up
Num 3. Gear Down
Num 4. Refuel
Num -. Brake
Num +. Accelerate
Num 9. Exit

RECENT EVENTS:
Engine turned on
Shift up
```

### Event Log

The event log at the bottom of the screen keeps track of your recent actions, providing context for the car's current status.

```
RECENT EVENTS:
Engine turned on
Shift up
You have refueled 10 liters of fuel.
```

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/simple-car-simulator.git
   ```

2. **Navigate to the project directory:**
   ```bash
   cd simple-car-simulator
   ```

3. **Compile the project:**
   ```bash
   g++ SimpleCarSimulator.cpp Car.cpp -o SimpleCarSimulator
   ```

## Usage

1. **Run the simulator:**
   ```bash
   ./SimpleCarSimulator
   ```

2. **Follow the on-screen instructions to interact with the car.**
   - Use the numeric keys to choose actions:
     - `0` - Turn Engine On/Off
     - `1` - Turn Handbrake On/Off
     - `2` - Gear Up
     - `3` - Gear Down
     - `4` - Refuel
     - `-` - Brake
     - `+` - Accelerate
     - `9` - Exit

## Class and Function Details

### Car Class

The `Car` class encapsulates the car's functionalities and properties.

#### Private Members

- `bool IsEngineOn`
- `int speed`
- `float fuelLevel`
- `int maxFuelCapacity`
- `float mileage`
- `int currentGear`
- `bool IsHandBrakeActive`
- `std::deque<std::string> events`

#### Public Methods

- **Car()**: Initializes the car's properties.
- **void turnEngineOn(), turnEngineOff(), changeEngineStatus()**: Manage engine status.
- **void accelerate(), brake()**: Control car speed.
- **void consumeFuel(), refuel(int amount)**: Manage fuel.
- **void gearUp(), gearDown()**: Change gears.
- **void turnHandBrakeOn(), turnHandBrakeOff(), changeHandBrakeStatus()**: Manage handbrake.
- **void decreaseSpeed(int value)**: Reduce speed.
- **void updateMileage()**: Update mileage.
- **void UpdateStatus()**: Update car's status.
- **bool isEngineOn() const, isHandBrakeActive() const, getSpeed() const, getFuelLevel() const, getMileage() const, getCurrentGear() const**: Get current state.
- **void displayStatus() const**: Display car's status.
- **void displayEvents() const, addEvent(const std::string& event)**: Manage event log.

### SimpleCarSimulator

The `SimpleCarSimulator.cpp` file contains the main function and user interaction logic.

#### Functions

- **clearConsole()**: Clears the console.
- **showAction()**: Displays available actions.
- **chooseAction()**: Gets the user's action choice.
- **isKeyPressed()**: Checks if a key is pressed.

## Contributing

Feel free to submit issues and pull requests if you have any improvements or bug fixes.

## Contact

For any inquiries or questions, please contact the repository owner at [nikodem.kwasniewski@outlook.com](mailto:nikodem.kwasniewski@outlook.com).

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

Enjoy your time with the Simple Car Simulator! If you have any questions or encounter issues, feel free to open an issue on GitHub. Happy driving!