#include <iostream>
#include "spec.h"
using namespace std;

int main() {
	int a1, a2, a3; // // 입력 받는 최대 3개의 숫자, 입력 받는 부분은 생략하였음
	// Class 이름은 Shape

	// 사용자에게 숫자를 입력 받습니다.
	cout << "정수를 3개 입력하세요 : ";
	cin >> a1 >> a2 >> a3;

	// spec()은 선분은 길이, 직사각형은 넓이, 직육면체는 부피를 출력하는 함수
	Shape S1(a1); // 생성자 : 선분
	S1.spec(); // 선분의 길이 출력
	Shape S2(a1, a2); // 생성자 : 직사각형
	S2.spec(); // 직사각형의 넓이 출력
	Shape S3(a1, a2, a3); // 생성자 : 직육면체
	S3.spec(); // 직육면체의 부피 출력
	return 0;
}