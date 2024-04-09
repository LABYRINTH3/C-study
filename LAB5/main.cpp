#include <iostream>
using namespace std;

class Circle{
private:
    int radius;
public:
    Circle();
    void setRadius(int radius);
    float getArea();
};
Circle::Circle() {

}

void  Circle::setRadius(int radius) {
    this -> radius = radius;
}
float Circle::getArea() {
    return radius * radius * 3.14;
}

void readRadius(Circle &c) {
    int radius = 0;
    cout << "반지름의 길이를 정수로 입력하세요: ";
    cin >> radius;
    c.setRadius(radius);
}

int main() {
    Circle circle;
    readRadius(circle);
    cout << "원의 넓이 : " << circle.getArea();
    return 0;
}
