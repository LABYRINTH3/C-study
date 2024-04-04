// C211128 이태훈 HW1 3번 문제
#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    int num3 = 1;
    // num1,2에 소수인지 판단할 정수를 입력받는다.
    cout << "두 수를 입력하시오: ";
    cin >> num1; cin >> num2;
    cout << "두 수의 공약수: ";
    // num1,2 중 작은 수 까지 루프를 돌며 공배수가 있는지 확인하고 공배수를 출력한다.
    if (num1 > num2){
        for (int i = 1; i <= num2; ++i) {
            if (num1 % i == 0 && num2 % i == 0){
                cout << i << ' ';
            }
        }
    }
    else{
        for (int i = 1; i <= num1; ++i) {
            if (num1 % i == 0 && num2 % i == 0){
                cout << i << ' ';
            }
        }
    }
    // 무한 루프를 돌며 숫자를 1씩 키우며 num1,2로 num3을 나눌 수 있는지 확인하고 나누어지면 출력한 후 루프를 종료한다.
    cout << '\n';
    while(true){
        if(num3 % num1 == 0 && num3 % num2 == 0){
            cout << "최소공배수: " << num3;
            break;
        }
        num3++;
    }
    return 0;
}
