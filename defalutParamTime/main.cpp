#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class CircleWithDefault {
private:
    int radius;
public:
    CircleWithDefault(int radius = 1) { this->radius = radius; }
    int getArea() { return 3.14 * radius * radius; }
};

class CircleWithoutDefault {
private:
    int radius;
public:
    CircleWithoutDefault() { radius = 1; }
    CircleWithoutDefault(int radius) { this->radius = radius; }
    int getArea() { return 3.14 * radius * radius; }
};

int main() {
    unsigned long iterations = 100000000;  // Number of instances to create for the test.

    auto startWithoutDefault = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        CircleWithDefault circle1;
        CircleWithoutDefault circle2(i % 100);
        cout << circle1.getArea() << circle2.getArea()<< endl;
    }
    auto stopWithoutDefault = high_resolution_clock::now();

    auto startWithDefault = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        CircleWithDefault circle1;
        CircleWithDefault circle2(i % 100);
        cout << circle1.getArea() <<circle2.getArea()<< endl;
    }
    auto stopWithDefault = high_resolution_clock::now();

    auto durationWithDefault = duration_cast<microseconds>(stopWithDefault - startWithDefault);
    auto durationWithoutDefault = duration_cast<microseconds>(stopWithoutDefault - startWithoutDefault);

    cout << "Time taken by function with default parameter: " << durationWithDefault.count() << " microseconds" << endl;
    cout << "Time taken by function without default parameter: " << durationWithoutDefault.count() << " microseconds" << endl;

    return 0;
}
