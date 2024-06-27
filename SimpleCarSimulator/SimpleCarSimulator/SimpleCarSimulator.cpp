#include <iostream>
#include <conio.h>
#include "Car.h"
#include <thread>
#include <chrono>
#include "Actions.h"

using namespace std;

int action;
void clearConsole() {
    cout << "\033[2J\033[1;1H";
}
void showAction() {
    cout << "Choose one of the following actions:" << endl;
    cout << "Num 0. Turn Engine On/Off" << endl;
    cout << "Num 1. Turn Handbrake On/Off" << endl;
    cout << "Num 2. Gear Up" << endl;
    cout << "Num 3. Gear Down" << endl;
    cout << "Num 4. Refuel" << endl;
    cout << "Num -. Brake" << endl;
    cout << "Num +. Accelerate" << endl;
    cout << "Num 9. Exit" << endl;
}
Action chooseAction() {
    char value = _getch();

    switch (value) {
    case '0': return TURN_ENGINE;
    case '1': return TURN_HANDBRAKE;
    case '2': return GEAR_UP;
    case '3': return GEAR_DOWN;
    case '4': return REFUEL;
    case '-': return BRAKE;
    case '+': return ACCELERATE;
    case '9': return EXIT;
    default: return INVALID;
    }
}
bool isKeyPressed() {
    // _kbhit() returns a non-zero value if a key was pressed
    return _kbhit() != 0;
}

int main()
{
    int refuelAmount;
    Car Opelek;

    do {
        clearConsole();
        Opelek.UpdateStatus();
        Opelek.displayStatus();
        cout << endl;
        showAction();
        cout << endl;
        Opelek.displayEvents();

        if (isKeyPressed()) {
            action = chooseAction();

            switch (action) {
            case TURN_ENGINE:     // Engine logic
                Opelek.changeEngineStatus();
                break;
            case TURN_HANDBRAKE:  // Handbrake logic
                Opelek.changeHandBrakeStatus();
                break;
            case GEAR_UP:         // Gear up logic
                Opelek.gearUp();
                break;
            case GEAR_DOWN:       // Gear down logic
                Opelek.gearDown();
                break;
            case REFUEL:          // Refueling logic
                cout << "Enter amount to refuel: ";
                cin >> refuelAmount;
                Opelek.refuel(refuelAmount);
                break;
            case BRAKE:           // Braking logic
                Opelek.brake();
                break;
            case ACCELERATE:      // Acceleration logic
                Opelek.accelerate();
                break;
            case EXIT:            // Exit
                action = EXIT;
                break;
            case INVALID:         // Invalid input
                cout << "Invalid option selected. Please try again." << endl;
                break;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1000)); // Delay for 1 seconds

    } while (action != EXIT);
}