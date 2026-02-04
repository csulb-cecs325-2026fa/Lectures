#include <iostream>
#include <cmath>
#include "targetgame.h"

int main() {
    int targetDistance {0};

    std::cout << "Welcome to target practice!" << std::endl;
    std::cout << "Enter the target's distance: ";
    std::cin >> targetDistance;

    bool hitTarget {false};
    while (!hitTarget) {
        double angle {getAngle()};
        double gunpowder {getGunpowder()};

        double distance {distanceTraveled(angle, gunpowder)};
        double missedBy {std::fabs(distance - targetDistance)};
        if (missedBy <= 1.0) {
            std::cout << "You hit the target!" << std::endl;
            hitTarget = true;




            
        } else if (distance < targetDistance) {
            std::cout << "You were short by " << missedBy << "m. Try again!" << std::endl;
        } else {
            std::cout << "You were long by " << missedBy << "m. Try again!" << std::endl;
        }
    }
    return 0;
}
