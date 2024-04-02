#include <iostream>
using namespace std;

class Color{
    //    Class Color를 작성하시오.
//    • 멤버 변수
private:
    float r, g, b ; // 빛의 삼원색: 0이면 가장 어두운 색, 1이면 가장 밝은 색
//    • 멤버함수
public:
    Color() ; // 색을 검은색으로 초기화
    Color(float r, float g, float b); // 입력색으로 초기화
    Color(const Color &c) ; // 복사 생성자
    ~Color() ; // 하는 일 없음
    float getR() ;
    float getG() ;
    float getB() ; // 각각 r,g,b 값을 리턴
    void setR(float r) ;
    void setG(float g) ;
    void setB(float b) ; // r,g,b 값을 바꿈
    void add (Color c) ; // 현재색을 현재색 + c 로 바꿈 : r,g,b 각각 더하되 1이 넘지 않게 함
//    Programming Practice 4
//    Class Color를 작성하시오.
//    • 멤버함수
    void increaseBrightness(float k) ; // r,g,b에 (1+k)를 곱함. 0<k<1. 곱한 결과가 1을 넘지 않아야 함
    void decreaseBrightness(float k) ; // r,g,b에 (1-k)를 곱함. 0<k<1. 곱한 결과가 0보다 작지 않아야 함
    void printColor(); // 화면에 색 값을 프린트
};

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

// 복사 생성자???
Color::Color(const Color &c) {
    r = c.r;
    g = c.g;
    b = c.b;
}

float Color::getR() {
    return r;
}
float Color::getG() {
    return g;
}
float Color::getB() {
    return b;
}

void Color::setR(float r) {
    this->r = r;
}
void Color::setG(float g) {
    this->g = g;
}
void Color::setB(float b) {
    this->b = b;
}

void Color::increaseBrightness(float k) {
    r = r * (1-k);
    g = g * (1-k);
    b = b * (1-k);
}
void Color::add(Color c) {
    r= c.r + r;
    g = c.g +g;
    if (g>1)
        g=1;
    b = c.b +b;

}

void Color::printColor() {
    cout << "r: " << r << " g: " << g << " b: " << b << endl;
}

Color::~Color(){

}
int main() {
//    Programming Practice 4
//    • main() 함수 테스트
    Color c1(0.2, 0.3, 0.7) ;
    Color c2(0.2, 0.3, 0.7) ;
    c1.setR(0.8);
    c1.setG(0.8);
    c1.setB(0.1) ;
    c2.add (c1) ;
    c2.printColor() ;
    c2.increaseBrightness (0.2) ;
    c2.printColor() ;
    return 0;
}
