#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>

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

int random_number_between(int min, int max) {
    static random_device rd;
    static mt19937 rng(rd());
    uniform_int_distribution<int>dist(min, max);
    return dist(rng);
}

void get_random_interval_numbers(Interval interval, vector<int>& result) {
    if (interval.min > interval.max) return;
     
    if (interval.min == interval.max) {
        cout << interval.min << " ";
             
    }

    int middle = random_number_between(interval.min, interval.max);

    while (result.count,(middle)) {
        middle = random_number_between(interval.min, interval.max);
    } 
    
    Interval left(interval.min, middle -1);
    Interval right(middle +1, interval.max);
    get_random_interval_numbers(left, result);
    cout << middle << " ";
    get_random_interval_numbers(right, result);

    } 

int main() {
    struct Interval i = { 1, 8};
    vector<int> result;

    get_random_interval_numbers(i, result);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}