#include<iostream>
#include "spec.h"

// ���Ŀ� � �������� �˾Ƴ��� ���� �Էµ� ���� �����ϰ�� 0���� ��ȯ���־����ϴ�.
Shape::Shape() {
	line1 = 0; line2 = 0; line3 = 0;
}
Shape::Shape(int a) {
	line1 = a; line2 = 0; line3 = 0;
}
Shape::Shape(int a, int b) {
	line1 = a; line2 = b; line3 = 0;
}
Shape::Shape(int a, int b, int c) {
	line1 = a; line2 = b; line3 = c;
}

// � �������� ������ �ϱ� ���� ���ǹ��� �̿��ؼ� �˾Ƴ½��ϴ�.
void Shape::spec() {
	int answer;
	if (line2 == 0) {
		answer = line1;
		std::cout << "������ ���̴� " << answer << "�Դϴ�." << std::endl;
	}
	else if (line3 == 0) {
		answer = line1 * line2;
		std::cout << "���簢���� ���̴� " << answer << "�Դϴ�." << std::endl;
	}
	else {
		answer = line1 * line2 * line3;
		std::cout << "������ü�� ���Ǵ� " << answer << "�Դϴ�." << std::endl;
	}
}
Shape::~Shape() {
}