// C211128 이태훈 HW1 4번 문제
#include <iostream>
using namespace std;

// decimal 을 넣으면 hexadecimal로 변환해주는 함수
char hexade(int num);

// hexadecimal을 만들기 위해서는 decimal을 16으로 나눈후 나머지를 출력하면 된다.
// 하지만 나머지를 순서대로 반환하면 거꾸로 출력되기 때문에 배열에 저장후 거꾸로 출력해주려고 한다.
int main() {
    int numGet, numDiv , charNum = 0;
    char num[100]={0,};
    cout << "십진수를 입력하시오: ";
    cin >> numGet;
    // decimal을 입력 받은 후 16으로 나눠 나머지를 numDiv에 저장후 내가 만든 함수로 보내 16진수에 맞는 문자로 변환한다.
    while (numGet >= 16) {
        numDiv = numGet % 16;
        numGet = numGet / 16;
        num[charNum] = hexade(numDiv);
        charNum++;
    }
    num[charNum] = hexade(numGet);
    // 거꾸로 저장되었기 때문에 다시 반대로 출력해준다.
    for (int i = charNum; i >= 0 ; i--) {
        cout << num[i];
    }
}

// switch 문을 이용해서 나머지를 넣으면 hexadecimal에 해당하는 문자를 반환 해주는 함수를 만들어준다.
char hexade(int num) {
    switch (num) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
    }
}