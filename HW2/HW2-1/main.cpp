#include <iostream>
#include <cmath>
#include "Rect.h"
using namespace std;

int main() {
    float x1, x2, y1, y2;
    // 입력 받는 2개의 좌표정보, 입력 받는 부분은 생략되어있음

    // 좌표값을 입력 받습니다.
    cout << "첫번째 좌표의 x좌표를 입력하세요 : ";
    cin >> x1;
    cout << "첫번째 좌표의 y좌표를 입력하세요 : ";
    cin >> y1;
    cout << "두번째 좌표의 x좌표를 입력하세요 : ";
    cin >> x2;
    cout << "두번째 좌표의 y좌표를 입력하세요 : ";
    cin >> y2;

    // 위 정보를 가지고 직사각형 객체 생성
    Rect rect1(x1, x2, y1, y2);

    // 멤버함수의 결과값 받기
    float rectangleArea = rect1.get_area();
    float rectangleDiagonal = rect1.get_diagonal_length();

    //결과 출력
    cout << "직사각형 넓이 : " << rectangleArea << endl;// 직사각형의 넓이 출력
    cout << "직사각형 내부 대각선 길이 : " << rectangleDiagonal << endl;// 직사각형의 내부 대각선 길이 출력
    return 0;
}
