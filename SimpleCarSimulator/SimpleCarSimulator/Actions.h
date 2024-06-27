#pragma once

enum Action {
    TURN_ENGINE = 0,
    TURN_HANDBRAKE = 1,
    GEAR_UP = 2,
    GEAR_DOWN = 3,
    REFUEL = 4,
    BRAKE = 5,
    ACCELERATE = 6,
    EXIT = 9,
    INVALID = -1
};