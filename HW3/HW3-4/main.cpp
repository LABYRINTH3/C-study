#include <iostream>
#include "Member.h"
using namespace std;

int main() {
    // Member class 객체로 이뤄진 배열 생성(동적 할당) 및 초기화

    // 배열의 길이는 4, 위의 사용자들의 정보를 넣어 초기화
    Member *userData = new Member[4];

    // 각각의 멤버변수 값 입력은 위에서 정의한 setID(char* id), setPWD(char* pwd),
    //setName(char* name), setAge(int age)를 통해 값을 대입할 것
    userData[0].setID("cheol88");
    userData[0].setPWD("cheol88");
    userData[0].setName("김철수");
    userData[0].setAge(23);

    userData[1].setID("ywjeong123");
    userData[1].setPWD("12345^");
    userData[1].setName("정연우");
    userData[1].setAge(31);

    userData[2].setID("Jiwoon456");
    userData[2].setPWD("34563%");
    userData[2].setName("박지운");
    userData[2].setAge(35);

    userData[3].setID("Choi931");
    userData[3].setPWD("96454$$");
    userData[3].setName("최지우");
    userData[3].setAge(26);

    // 해당 아이디를 가지고 있는 자료를 찾아내기 위해 루프를 돌려 찾아냈습니다.
    string jiwoon = "Jiwoon456";
    for (int i = 0; i < 4; ++i) {
        if (userData[i].getID() == jiwoon){
            // 이름과 나이를 변경했습니다.
            userData[i].setName("박다니엘");
            userData[i].setAge(22);
        }
    }
    // 전체 정보를 출력합니다.
    for (int i = 0; i < 4; ++i) {
        userData[i].prinrtMemInfo();
    }
    // 할당한 메모리를 반환합니다.
    delete[] userData;
    return 0;
}
