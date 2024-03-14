#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, start =0;
    char op1;
    cout << "문자열을 입력하세요: ";
    while(true){
        if (start == 0) {
            cin >> num1;
            num3 = num1;
            start = start + 1;
        }
        cin >> op1;
        if (op1 == '=')
            break;
        cin >> num2;
        switch (op1) {
            case '+':
                num3 = num3 + num2;
                break;
            case '-':
                num3 = num3 - num2;
                break;
            case '*':
                num3 = num3 * num2;
                break;
            case '/':
                num3 = num3 / num2;
                break;
            case '%':
                num3 = num3 % num2;
                break;
        }
    }
    cout << num3 ;
    return 0;
}
