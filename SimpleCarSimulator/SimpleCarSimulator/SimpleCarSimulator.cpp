#include <iostream>
#include <conio.h>
#include "Car.h"
#include <thread>

using namespace std;

int action;
void clearConsole() {
    cout << "\033[2J\033[1;1H";
}

int chooseAction() {
    cout << "Choose one of the following actions:" << endl;
    cout << "Num 0. Turn Engine On/Off" << endl;
    cout << "Num 1. Turn Handbrake On/Off" << endl;
    cout << "Num 2. Gear Up" << endl;
    cout << "Num 3. Gear Down" << endl;
    cout << "Num 4. Refuel" << endl;
    cout << "Num -. Brake" << endl;
    cout << "Num +. Accelerate" << endl;
    cout << "Num 9. Exit" << endl;

    int ch = _getch();  // Get a character without waiting for Enter

    switch (ch) {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '-':
        return 5;
    case '+':
        return 6;
    case '9':
        return 9;
    case 107:  // Numpad +
        return 6;
    case 109:  // Numpad -
        return 5;
    default:
        return -1;  // Invalid input
    }
}

int main()
{

    int refuelAmount;

    Car Opelek;
    do {
        clearConsole();
        Opelek.displayStatus();
        cout << endl;

        action = chooseAction();

        switch (action) {
        case 0:     // Logika silnika
            if (Opelek.isEngineOn()) {
                Opelek.turnEngineOff();
                while (!Opelek.isEngineOn() && Opelek.getSpeed() > 0) {
                    clearConsole();
					Opelek.decreaseSpeedEngineOff(); // Wytracanie prędkości
                    Opelek.displayStatus(); // Wyświetl status po zmianie prędkości
                    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Opóźnienie
                }
            }
            else {
                Opelek.turnEngineOn();
            }
            break;
		case 1:	 // Logika hamulca ręcznego 
            if (Opelek.isHandBrakeActive()) {
                Opelek.turnHandBrakeOff();
            }
            else {
                Opelek.turnHandBrakeOn();
                while (Opelek.isHandBrakeActive() && Opelek.getSpeed() > 0) {
                    Opelek.decreaseSpeedHandBrake(); // Wytracanie prędkości
                    clearConsole();
                    Opelek.displayStatus(); // Wyświetl status po zmianie prędkości
                    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Opóźnienie
                }
            }
            break;
		case 2:     // Logika zmiany biegu na wyższy
            Opelek.gearUp();
            break;
        case 3:     // Logika zmiany biegu na niższy
            Opelek.gearDown();
            while (Opelek.getSpeed() > Opelek.getCurrentGear() * 30) {
                clearConsole();
				Opelek.adjustSpeedForGearDown(); // Wytracanie prędkości
                Opelek.displayStatus(); // Wyświetl status po zmianie prędkości
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Opóźnienie
            }
            break;
		case 4:     // Logika tankowania
            cout << "Enter amount to refuel: ";
            cin >> refuelAmount;
            Opelek.refuel(refuelAmount);
            break;
		case 5:     // Logika hamowania
            Opelek.brake();
            break;
		case 6:     // Logika przyspieszania
            Opelek.accelerate();
            break;
        case 9:
            break;
        }

    } while (action != 11);
}