#include <iostream>
#include <string>
using namespace std;


int main() {
    string inputString1, inputString2;
    cout << "첫번째 문자열을 입력하시오: ";
    getline(cin, inputString1);
    cout << "두번째 문자열을 입력하시오: ";
    getline(cin, inputString2);
    cout << inputString1 << " " << inputString2 << endl;
    return 0;
}
