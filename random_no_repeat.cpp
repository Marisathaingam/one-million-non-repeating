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

class IntervalFactory {
public: 
    std::unique_ptr<Interval> create (int min, int max) {
        if (min > max) return nullptr;
        return std::make_unique<Interval>(min, max);
    }
};

class UniqueRandomGenerator {
private:
    std::vector<int> result;
    IntervalFactory factory;
    std::mt19937 rng;

public:
    UniqueRandomGenerator() {
        std::random_device rd;
        rng = std::mt19937(rd());
    }
    
    std::vector<int> generateAll() {
        auto initial = factory.create(1, 1'000'000);
        generate(std::move(initial));
        return result;
    }

private:
   void generate (std::unique_ptr<Interval> interval) {
       if (!interval || !interval->isValid()) return;

       std::uniform_int_distribution<int> dist(interval->min, interval->max);
       int selected = dist(rng);
       result.push_back(selected);

       auto left = factory.create(interval->min, selected - 1);
       auto right = factory.create(selected + 1, interval->max);

       generate(std::move(left));
       generate(std::move(right));
   }
   
};