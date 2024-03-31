#include <iostream>
using namespace std;

class Rectangle{
private:
    float width;
    float height;

public:
    Rectangle();
    Rectangle(float a, float b);
    float Area();
    float perimeter();
    bool isSquare();
};

Rectangle::Rectangle() {
    width = 1.0;
    height = 1.0;
}

Rectangle::Rectangle(float a, float b) {
    width = a;
    height = b;
}


float Rectangle::Area() {
    return width*height;
}

float Rectangle::perimeter(){
    return width*2+height*2;
}

bool Rectangle::isSquare(){
    if (width == height)
        return true;
    else
        return false;
}

int main() {
    float height=4.7, width=3.5;
    Rectangle square1;
    cout << "넓이는 " << square1.Area()<< "입니다."<< endl;
    cout << "둘레는 " << square1.perimeter()<< "입니다."<< endl;
    if (square1.isSquare() == true)
        cout << "정사각형입니다.\n"<<endl;
    else
        cout << "정사각형이 아닙니다.";

    Rectangle square2(height, width);
    cout << "넓이는 " << square2.Area()<< "입니다."<< endl;
    cout << "둘레는 " << square2.perimeter()<< "입니다."<< endl;
    if (square2.isSquare() == true)
        cout << "정사각형입니다.";
    else
        cout << "정사각형이 아닙니다.";
    return 0;
}
