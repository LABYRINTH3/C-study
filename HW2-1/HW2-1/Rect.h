#ifndef RECT_H
#define RECT_H
#include <cmath>

class Rect {
private:
    float p1_x, p2_x, p1_y, p2_y;
public:
    //�����ڸ� �����մϴ�.
    Rect();
    Rect(float x1, float x2, float y1, float y2);
    float get_area(); // ���簢���� ���̸� ���ϴ� �Լ�
    float get_diagonal_length(); // ���簢���� ���� �밢�� ���� ���ϴ� �Լ�
};

// �����ڿ��� �޾ƿ� �Ǽ����� private�ȿ� ����Ǿ� �ִ� ��� ������ �ȿ� ����
Rect::Rect(float x1, float x2, float y1, float y2) {
    p1_x = x1;
    p2_x = x2;
    p1_y = y1;
    p2_y = y2;
}
float Rect::get_area() {
    float area = (p1_x - p2_x) * (p1_y - p2_y);
    // �� ��ǥ�� ���� ���� �� �������� ������ -1�� ���ϰ� ������� ������ �״�� ��ȯ
    if (area > 0)
        return area;
    else
        return -1 * area;
}

// �밢���� ���̸� ���ϱ� ���� ��Ÿ��� ������ �̿��߽��ϴ�.
float Rect::get_diagonal_length() {
    float length = (p1_x - p2_x) * (p1_x - p2_x) + (p1_y - p2_y) * (p1_y - p2_y);
    //��Ʈ�� �������ϴ�.
    length = sqrt(length);
    return length;
}
#endif