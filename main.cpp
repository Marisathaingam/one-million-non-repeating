#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>

using namespace std;

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
        std:: cout << "[" << min << "," << max << "]";
    }
};

void get_random_interval_numbers(Interval interval) {
    // Function: get_random_interval_numbers(interval)
    //if interval.min == interval.max:
    //    print(interval.min)
    //    return

    //middle = random_number_between(interval.min, interval.max)

    //left = Interval(interval.min, middle - 1)
    //right = Interval(middle + 1, interval.max)

    //get_random_interval_numbers(left)
    //print(middle)
    //get_random_interval_numbers(right)
}

int main() {
    struct Interval i = { 1, 8 };

    get_random_interval_numbers(i);

    return 0;
}