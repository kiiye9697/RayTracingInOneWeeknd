#ifndef INTERVAL_H
#define INTERVAL_H
#include "rtweekend.h"
//COMMENT:
//在这里我们定义一个类用于定义范围函数，并且根据一些常量规定的最小值，最大值等相关行为。
class interval {
public:
    double min, max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double min, double max) : min(min), max(max) {}
    double clamp(double x) const 
    {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
    double size() const {
        return max - min;
    }

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif
