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

    while (true) {
        // 사용자에게 정보를 받습니다.
        cout << "찾는 사용자의 아이디를 입력하시오 : ";
        string getUserId;
        cin >> getUserId;
        cout << "해당 아이디에 맞는 Password를 입력하시오 : ";
        string getUserPassword;
        cin >> getUserPassword;
        // 동일한 정보가 있다면 출력하고, 없으면 이를 알려줌
        // check이 0이면 사용자가 입력한 정보와 같은 사람이 없는 것 입니다.
        int check = 0;
        for (int i = 0; i < 4; ++i) {
            if(userData[i].getID() == getUserId && userData[i].getPWD() == getUserPassword){
                userData[i].prinrtMemInfo();
                check++;
            }
        }
        if (check == 0){
            cout << "찾으시는 사용자가 존재하지 않습니다."<<endl;
        }
        // 만약 아이디와 Password가 모두 “0000” 이면 프로그램 종료
        if (getUserId == "0000" && getUserPassword == "0000"){
            // 종료할 때 동적 할당한 메모리의 반환을 확실히 할 것
            delete[] userData;
            cout << "프로그램을 종료합니다."<<endl;
            break;
        }
    }
    return 0;
}
