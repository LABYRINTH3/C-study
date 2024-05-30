#include <iostream>
#include <cstring>
using namespace std;
class myString{
//클래스를 구현하십시오
private:
    char *str;
    int len;
public:
    myString() { str = NULL; len = 0; }
    myString(char *);
    myString(const myString& );
    myString& operator ++(); //전위
    myString& operator ++(int x); // 후위
    myString operator *(myString );
    myString& operator =(const myString& );
    void myPrint();
    ~myString();
};

myString::myString(char *letter) {
    // strlen을 이용해 문자열의 길이를 알아냅니다.
    len = strlen(letter);
    // 배열을 할당해 문자열을 입력합니다.
    str = new char[len+1];
    strcpy(str, letter);
}

// 아래 코드가 해당 main 함수에서 쓰이지는 않지만 위의 코드와 같은 형식의 코드를 작성했습니다.
myString::myString(const myString &letter) {
    // string의 경우 len을 이용해 문자열의 길이를 알아냅니다.
    len = letter.len;
    // 위와 같이 배열을 할당해 문자열을 입력합니다.
    str = new char[len+1];
    strcpy(str, letter.str);
}

// 전위 연산자 코드입니다.
myString& myString::operator++ () {
    // 아래 코드를 이용해 1을 추가해 아스키 코드에 1을 더해줍니다.
    for (int i = 0; i < len; i++) {
        str[i]++;
    }
    return *this;
}

// 후위 연산자 코드입니다.
myString& myString::operator++(int x) {
    // 아래 코드를 이용해 1을 추가해 아스키 코드에 1을 더해줍니다.
    for (int i = 0; i < len; i++) {
        str[i]++;
    }
    return *this;
}

myString myString::operator* (myString letter) {
    myString answer;
    // 객체 answer의 배열 길이를 넣고 배열을 생성합니다.
    answer.len = len + letter.len;
    answer.str = new char[answer.len + 1];
    // 반복문을 이용해서 배열에 문자를 입력합니다.
    int num = 0;
    for (int i = 0; i < len; i++) {
        answer.str[num] = str[i];
        answer.str[num+1] = letter.str[i];
        num = num + 2;
    }
    // 객체를 반환합니다.
    return answer;
}

myString& myString::operator= (const myString &letter) {
    // = 연산자를 이용해서 객체를 반환합니다.
    // str에 주어진 문자열을 복사해서 반환합니다.
    strcpy(str, letter.str);
    return *this;
}

void myString::myPrint() {
    // str을 출력합니다.
    cout << str << endl;
}
myString::~myString() {
    // delete를 이용해 해제합니다.
    delete[] str;
}
int main() {
    myString str1((char*)"HonGik");
    myString str2((char*)"ace");
    myString str3((char*)"bdf");

    str1++;
    str1.myPrint();
    str3 = str2 * str3;
    str3.myPrint();

    return 0;
}