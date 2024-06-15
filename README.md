
# SimpleCarSimulator

A simple console-based car simulation application implemented in C++. This project demonstrates basic car functionalities such as engine control, handbrake, gear shifting, refueling, and displaying the car's status.

## Features

- **Engine Control**: Turn the engine on or off.
- **Handbrake Control**: Engage or disengage the handbrake.
- **Gear Shifting**: Shift gears up or down.
- **Refueling**: Add fuel to the car.
- **Braking**: Apply the brakes.
- **Acceleration**: Accelerate the car.
- **Status Display**: Display the current status of the car, including engine status, speed, fuel level, mileage, current gear, and engine temperature.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++, MSVC)
- A terminal or command prompt

### Building and Running

1. Clone the repository:
   ```sh
   git clone https://github.com/kwasniewskin/SimpleCarSimulator.git
   ```
2. Navigate to the project directory:
   ```sh
   cd SimpleCarSimulator
   ```
3. Compile the project:
   ```sh
   g++ main.cpp Car.cpp -o CarSimulator
   ```
4. Run the executable:
   ```sh
   ./CarSimulator   # On Windows, use CarSimulator.exe
   ```

## Usage

1. The application will display the current status of the car.
2. Follow the on-screen prompts to choose an action using the numpad keys.
3. The status of the car will be updated based on the chosen actions.

## Example

```
Engine Status: Off
Speed: 0 km/h
Fuel Level: 40 liters
Mileage: 0 km
Current Gear: 0
Engine Temperature: 25 °C
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
```

## Contributing

Feel free to submit issues and pull requests if you have any improvements or bug fixes.

## Contact

For any inquiries or questions, please contact the repository owner at [nikodem.kwasniewski@outlook.com](mailto:nikodem.kwasniewski@outlook.com).
