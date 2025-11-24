
#include "clock.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// Base class implementation
void clockType::getTime(int &h, int &m, int &s) const {
    h = hr;
    m = min;
    s = sec;
}

bool clockType::validMin() const { return min >= 0 && min <= 59; }
bool clockType::validSec() const { return sec >= 0 && sec <= 59; }

void clockType::incrementSeconds() {
    sec++;
    if (sec > 59) {
        sec = 0;
        incrementMinutes();
    }
}
void clockType::incrementMinutes() {
    min++;
    if (min > 59) {
        min = 0;
        incrementHours();
    }
}
void clockType::setMinute(int m) {
    min = m;
    if (!validMin()) min = 0;
}
void clockType::setSecond(int s) {
    sec = s;
    if (!validSec()) sec = 0;
}

// Added missing setTime implementation
void clockType::setTime(int h, int m, int s) {
    hr = h;
    min = m;
    sec = s;
}

std::string clockType::toString() const {
    std::ostringstream out;  // FIXED
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    return out.str();
}

const clockType &clockType::operator++() {
    incrementSeconds();
    return *this;
}
const clockType &clockType::operator++(int) {
    clockType *temp = makeCopy();
    incrementSeconds();
    return *temp;
}

int clockType::getHour() const { return hr; }
int clockType::getMinute() const { return min; }
int clockType::getSecond() const { return sec; }

// TwentyFourHrClock implementation
TwentyFourHrClock::TwentyFourHrClock(int h, int m, int s) { setTime(h, m, s); }
bool TwentyFourHrClock::validHr() const { return hr >= 0 && hr <= 23; }
void TwentyFourHrClock::invalidHr() { std::cout << "Hours must be between 0 and 23. Defaulting to 0." << std::endl; hr = 0; }
void TwentyFourHrClock::incrementHours() { hr++; if (hr > 23) hr = 0; }
void TwentyFourHrClock::setHour(int hour) { hr = hour; if (!validHr()) invalidHr(); }

bool TwentyFourHrClock::operator==(const TwentyFourHrClock &rightHandClock) const {
    return hr == rightHandClock.hr && min == rightHandClock.min && sec == rightHandClock.sec;
}
bool TwentyFourHrClock::operator!=(const TwentyFourHrClock &rightHandClock) const {
    return !(*this == rightHandClock);
}

clockType *TwentyFourHrClock::makeCopy() { return new TwentyFourHrClock(*this); }
const clockType &TwentyFourHrClock::operator*() { return *this; }

// Lab B Comparison Operators
bool operator<(const TwentyFourHrClock &left, const TwentyFourHrClock &right) {
    if (left.getHour() != right.getHour()) return left.getHour() < right.getHour();
    if (left.getMinute() != right.getMinute()) return left.getMinute() < right.getMinute();
    return left.getSecond() < right.getSecond();
}
bool operator>(const TwentyFourHrClock &left, const TwentyFourHrClock &right) { return right < left; }
bool operator<=(const TwentyFourHrClock &left, const TwentyFourHrClock &right) { return !(right < left); }
bool operator>=(const TwentyFourHrClock &left, const TwentyFourHrClock &right) { return !(left < right); }

std::ostream &operator<<(std::ostream &out, const clockType &c) {
    out << c.toString();
    return out;
}
