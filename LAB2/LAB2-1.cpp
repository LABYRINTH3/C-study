#include <iostream>
using namespace std;

class Rectangle{
private:
    float width;
    float height;

public:
    Rectangle(float a, float b);
    float Area();
    float perimeter();
    bool isSquare();
};

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
};

int main() {
    float height, width;
    cout <<"세로를 입력하세요 : ";
    cin >> height;
    cout <<"가로를 입력하세요 : ";
    cin >> width;
    Rectangle square(height, width);
    cout << "넓이는 " << square.Area()<< "입니다."<< endl;
    cout << "둘레는 " << square.perimeter()<< "입니다."<< endl;
    if (square.isSquare() == true)
        cout << "정사각형입니다.";
    else
        cout << "정사각형이 아닙니다.";
    return 0;
}
