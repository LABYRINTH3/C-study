#ifndef RECT_H
#define RECT_H
#include <cmath>

class Rect {
private:
    float p1_x, p2_x, p1_y, p2_y;
public:
    //생성자를 선언합니다.
    Rect();
    Rect(float x1, float x2, float y1, float y2);
    float get_area(); // 직사각형의 넓이를 구하는 함수
    float get_diagonal_length(); // 직사각형의 내부 대각선 길이 구하는 함수
};

// 생성자에서 받아온 실수들을 private안에 저장되어 있는 멤버 변수들 안에 저장
Rect::Rect(float x1, float x2, float y1, float y2) {
    p1_x = x1;
    p2_x = x2;
    p1_y = y1;
    p2_y = y2;
}
float Rect::get_area() {
    float area = (p1_x - p2_x) * (p1_y - p2_y);
    // 두 좌표를 빼고 곱한 후 음수값이 나오면 -1을 곱하고 양수값이 나오면 그대로 반환
    if (area > 0)
        return area;
    else
        return -1 * area;
}

// 대각선의 길이를 구하기 위해 피타고라스 정리를 이용했습니다.
float Rect::get_diagonal_length() {
    float length = (p1_x - p2_x) * (p1_x - p2_x) + (p1_y - p2_y) * (p1_y - p2_y);
    //루트를 씌웠습니다.
    length = sqrt(length);
    return length;
}
#endif