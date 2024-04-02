#include<iostream>
#include "spec.h"

// 이후에 어떤 모형인지 알아내기 위해 입력된 값을 제외하고는 0으로 변환해주었습니다.
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

// 어떤 모형인지 구별을 하기 위해 조건문을 이용해서 알아냈습니다.
void Shape::spec() {
	int answer;
	if (line2 == 0) {
		answer = line1;
		std::cout << "직선의 길이는 " << answer << "입니다." << std::endl;
	}
	else if (line3 == 0) {
		answer = line1 * line2;
		std::cout << "직사각형의 넓이는 " << answer << "입니다." << std::endl;
	}
	else {
		answer = line1 * line2 * line3;
		std::cout << "직육면체의 부피는 " << answer << "입니다." << std::endl;
	}
}
Shape::~Shape() {
}