#include <iostream>
using namespace std;

class Rectangle{
private:
    float width;
    float height;

public:
    Rectangle();
    Rectangle(float w, float h);
    ~Rectangle();
};

Rectangle::Rectangle() {
    width = 1.0;
    height = 1.0;
    cout << width << ' ' << height <<" 생성자가 호출되었습니다.\n";
}
Rectangle::Rectangle(float w, float h) {
    width = w;
    height = h;
    cout << width << ' ' << height <<" 생성자가 호출되었습니다.\n";
}

Rectangle::~Rectangle() {
    cout << width << ' ' <<height <<" 소멸자가 호출되었습니다."<<endl;
};

int main() {
    float height, width;
    cout <<"세로를 입력하세요 : ";
    cin >> height;
    cout <<"가로를 입력하세요 : ";
    cin >> width;
    Rectangle square1;
    Rectangle square2(height, width);

    return 0;
}
