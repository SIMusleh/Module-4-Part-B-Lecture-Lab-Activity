#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <typeinfo>

enum class partType {
    AM,
    PM
};

const partType parts[2] = {partType::AM, partType::PM};
const std::string partToStr[2] = {"AM", "PM"};

class clockType {
public:
    void getTime(int &, int &, int &) const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    std::string printTime() const;
    bool validMin() const;
    bool validSec() const;
    void incrementSeconds();
    void incrementMinutes();
    void setMinute(int m);
    void setSecond(int s);
    virtual std::string toString() const;
    virtual void setTime(int, int, int);
    virtual bool validHr() const = 0;
    virtual void invalidHr() = 0;
    virtual void incrementHours() = 0;
    virtual void setHour(int hour) = 0;
    virtual clockType *makeCopy() = 0;
    const clockType &operator++();
    const clockType &operator++(int);
    friend std::ostream &operator<<(std::ostream &, const clockType &);
    friend std::istream &operator>>(std::istream &, clockType &);
    virtual const clockType &operator*() = 0;

protected:
    int hr;
    int min;
    int sec;
};

class TwelveHrClock;

class TwentyFourHrClock : public clockType {
public:
    TwentyFourHrClock(int h = 0, int m = 0, int s = 0);
    TwentyFourHrClock(const TwelveHrClock &);
    TwentyFourHrClock(const clockType &);
    virtual bool validHr() const;
    virtual void invalidHr();
    virtual void incrementHours();
    virtual void setHour(int hour);
    bool operator==(const TwentyFourHrClock &rightHandClock) const;
    bool operator!=(const TwentyFourHrClock &rightHandClock) const;

    // Added friend declarations for Lab B
    friend bool operator<(const TwentyFourHrClock &left, const TwentyFourHrClock &right);
    friend bool operator>(const TwentyFourHrClock &left, const TwentyFourHrClock &right);
    friend bool operator<=(const TwentyFourHrClock &left, const TwentyFourHrClock &right);
    friend bool operator>=(const TwentyFourHrClock &left, const TwentyFourHrClock &right);

    virtual clockType *makeCopy();
    virtual const clockType &operator*();
};

class TwelveHrClock : public clockType {
public:
    TwelveHrClock(int h, int m, int s, partType part);
    virtual bool validHr() const;
    virtual void invalidHr();
    virtual void incrementHours();
    virtual void setHour(int hour);
    void setPartOfDay(partType part);
    std::string getPartOfDay() const;
    partType getPartType() const;
    std::string toString() const;
    virtual clockType *makeCopy();
    virtual const clockType &operator*();

private:
    partType partOfDay;
};

#endif
