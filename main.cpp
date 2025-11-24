#include <iostream>
#include "clock.h"

int main() {
    TwentyFourHrClock c1(12, 30, 45);
    TwentyFourHrClock c2(12, 30, 50);

    std::cout << "Clock 1: " << c1 << "\n";
    std::cout << "Clock 2: " << c2 << "\n\n";

    std::cout << (c1 < c2 ? "c1 is earlier\n" : "c1 is not earlier\n");
    std::cout << (c1 > c2 ? "c1 is later\n" : "c1 is not later\n");
    std::cout << (c1 <= c2 ? "c1 is earlier or equal\n" : "c1 is not earlier or equal\n");
    std::cout << (c1 >= c2 ? "c1 is later or equal\n" : "c1 is not later or equal\n");

    return 0;
}
