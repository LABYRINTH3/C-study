#include <iostream>
#include <cmath>
#include "Rect.h"
using namespace std;

int main() {
    float x1, x2, y1, y2;
    // �Է� �޴� 2���� ��ǥ����, �Է� �޴� �κ��� �����Ǿ�����

    // ��ǥ���� �Է� �޽��ϴ�.
    cout << "ù��° ��ǥ�� x��ǥ�� �Է��ϼ��� : ";
    cin >> x1;
    cout << "ù��° ��ǥ�� y��ǥ�� �Է��ϼ��� : ";
    cin >> y1;
    cout << "�ι�° ��ǥ�� x��ǥ�� �Է��ϼ��� : ";
    cin >> x2;
    cout << "�ι�° ��ǥ�� y��ǥ�� �Է��ϼ��� : ";
    cin >> y2;

    // �� ������ ������ ���簢�� ��ü ����
    Rect rect1(x1, x2, y1, y2);

    // ����Լ��� ����� �ޱ�
    float rectangleArea = rect1.get_area();
    float rectangleDiagonal = rect1.get_diagonal_length();

    //��� ���
    cout << "���簢�� ���� : " << rectangleArea << endl;// ���簢���� ���� ���
    cout << "���簢�� ���� �밢�� ���� : " << rectangleDiagonal << endl;// ���簢���� ���� �밢�� ���� ���
    return 0;
}
