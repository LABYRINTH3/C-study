#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char op1, op2;
    cin >> num1 >> op1 >> num2 >> op2;
    if (op2 != '=')
        cout << "잘못된 입력입니다. 다시 입력해주세요.";
    else
        switch (op1) {
            case '+':
                cout << num1 + num2;
                break;
            case '-':
                cout << num1 - num2;
                break;
            case '*':
                cout << num1 * num2;
                break;
            case '/':
                cout << num1 / num2;
                break;
            case '%':
                cout << num1 % num2;
                break;
        }
    return 0;
}
