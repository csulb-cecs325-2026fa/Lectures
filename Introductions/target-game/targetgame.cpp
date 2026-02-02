#include <iostream>
#include <numbers>
#include <cmath>
#include "targetgame.h"

double getAngle() {
    double angle{-1};
    while (angle < 0 || angle > 90) {
        std::cout << "Enter an angle of elevation for the cannon, from 0 to 90 degrees: ";
        std::cin >> angle;
    }
    return angle;
}

double getGunpowder() {
    double gunpowder{-1};
    while (gunpowder < 0) {
        std::cout << "Enter an amount of gunpowder to use, in kilograms: ";
        std::cin >> gunpowder;
    }
    return gunpowder;
}

double distanceTraveled(double angle, double gunpowder) {
    // Each kg of gunpowder creates 30 meters per second of velocity.
    const double GUNPOWDER_MPS{30};
    const double GRAVITY{9.81};

    double velocity{gunpowder * GUNPOWDER_MPS};
    double radians{angle * std::numbers::pi_v<double> / 180};
    // std::numbers::pi_v<double> is Pi, as a double value.

    // From physics: distance = v^2 * sin(2*theta) / G.
    return velocity * velocity * std::sin(2 * radians) / GRAVITY;
}
