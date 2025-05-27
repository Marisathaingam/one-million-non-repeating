#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>

struct Interval {
    int min;
    int max;

    Interval(int min_, int max_) : min(min_), max(max_) {}

    int length() const {
         return max - min + 1;
    }

    bool isValid() const {
         return min <= max;
    }
      
    void print() const {
        std:: cout << "[" << "," << max << "]";
    }
};