// C211128 이태훈 HW1 2번 문제
#include <iostream>
using namespace std;

int main() {
    int num;
    int numCheck=0;
    // num에 소수인지 판단할 정수를 입력받는다.
    cout << "하나의 정수를 입력하시오: ";
    cin >> num;
    // 1보다 작은 수는 소수가 될 수 없으므로 우선 제외해준다.
    if (num <= 1){
        cout << num <<"은 소수가 아닙니다."<< endl;
    }
    // 루프를 통해 2부터 num까지 num을 나눌 수 있는 숫자가 있는지 확인한다.
    // 만약 나눠진다면 num은 소수가 아닙니다를 출력하고 루프를 종료한다.
    // 만약 루프가 끝날때까지 나누어지지 않았다면 num은 소수입니다를 출력한다.
    else{
        for (int i = 2; i < num; ++i) {
            if (num%i == 0){
                cout << num <<"은 소수가 아닙니다."<< endl;
                numCheck++;
                break;
            }
        }
        if (numCheck==0)
            cout << num <<"은 소수입니다.";
    }
    return 0;
}
