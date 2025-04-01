#include <iostream>

class Time
{
public:
    double hours;
    double minutes;
public:
    Time() : hours(0), minutes(0) {}
    Time(double h, double m) : hours(h), minutes(m) {}
    
    // 友元函数 operator*
    friend Time operator*(double m, Time & t);
    
    friend std::ostream & operator<<(std::ostream & os, const Time & t)
    {
        os << t.hours << ":" << t.minutes;
        return os; // 确保返回 os
    }
};

// 定义友元函数 operator*(double, Time&)
Time operator*(double m, Time & t) {
    Time result;
    result.hours = t.hours * m;
    result.minutes = t.minutes * m;
    return result;
}

int main() {
    Time beijing(8, 5);
    std::cout << beijing << std::endl;
    beijing = 2 * beijing;
    std::cout << beijing << std::endl;
    return 0;
}