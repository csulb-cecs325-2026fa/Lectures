#include <iostream>

int main(int argc, char* argv[]) {
    // Make sure there is a single command-line argument.
    if (argc != 2) {
        std::cout << "Usage: air_quality {pm25value}" << std::endl;
        return 1;
    }

    // Convert the first command-line argument to a double.
    double pm25 {std::stod(argv[1])};

    // We can declare more than one variable of the same type on the same line.
    double cLow, cHigh;
    int iLow, iHigh;
    // int is for integers.

    // Conditional branching is done with "if" statements. The condition is ALWAYS wrapped in parentheses.
    // Matching curly braces { } start and end the "then" block of the branch.
    if (pm25 <= 12.0) {
        cLow = 0.0;
        cHigh = 12.0;
        iLow = 0;
        iHigh = 50;
    }
    // There is no "elif"; we write "else if". && is used for "and".
    else if (pm25 > 12.0 && pm25 <= 35.4) {
        cLow = 12.1;
        cHigh = 35.4;
        iLow = 51;
        iHigh = 100;
    }
    else if (pm25 > 35.4 && pm25 <= 55.4) {
        cLow = 35.5;
        cHigh = 55.4;
        iLow = 101;
        iHigh = 150;
    }
    else if (pm25 > 55.4 && pm25 <= 150.4) {
        cLow = 55.5;
        cHigh = 150.4;
        iLow = 151;
        iHigh = 200;
    }
    else if (pm25 > 150.4 && pm25 <= 250.4) {
        cLow = 150.5;
        cHigh = 250.4;
        iLow = 201;
        iHigh = 300;
    }
    else if (pm25 > 250.4 && pm25 <= 350.4) {
        cLow = 250.5;
        cHigh = 350.4;
        iLow = 301;
        iHigh = 400;
    }
    else if (pm25 > 350.4 && pm25 <= 500.4) {
        cLow = 350.5;
        cHigh = 500.4;
        iLow = 401;
        iHigh = 500;
    }
    else {
        cLow = 500.5;
        cHigh = 999.9;
        iLow = 501;
        iHigh = 999;
    }
    double aqi {(iHigh - iLow) / (cHigh - cLow) * (pm25 - cLow) + iLow};
    std::cout << "PM2.5 reading: " << pm25 << std::endl;
    std::cout << "AQI: " << aqi << std::endl;

    if (aqi <= 50) {
        std::cout << "Air Quality: Good" << std::endl;
    }
    else if (aqi <= 100) {
        std::cout << "Air Quality: Moderate" << std::endl;
    }
    else if (aqi <= 150) {
        std::cout << "Air Quality: Unhealthy for Sensitive Groups" << std::endl;
    }
    else if (aqi <= 200) {
        std::cout << "Air Quality: Unhealthy" << std::endl;
    }
    else if (aqi <= 300) {
        std::cout << "Air Quality: Very Unhealthy" << std::endl;
    }
    else {
        std::cout << "Air Quality: Hazardous" << std::endl;
    }

    return 0;
}
