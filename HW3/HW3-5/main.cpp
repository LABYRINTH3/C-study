#include <iostream>
#include <cctype>
#include "Member.h"

// 입력 받은 비밀번호 안에 특수 문자가 있는지 확인하는 함수입니다.
bool pwCheckFunc(char a){
    char pwCheck[32] = {'!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '}', '|', '~'};
    for (int i = 0; i < 32; ++i) {
        if (pwCheck[i] == a){
            return true;
        }
    }
    return false;
}


int main() {
    // Member class 객체로 이뤄진 배열 생성(동적 할당) 및 초기화

    // 배열의 길이는 4, 위의 사용자들의 정보를 넣어 초기화
    Member *userData = new Member[5];

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


    // 사용자의 이름을 입력 받습니다.
    std::cout << "이름을 입력하세요 : ";
    char getNewName[100]= {};
    std::cin.getline(getNewName, 99);
    userData[4].setName(getNewName);

    // 사용자의 나이를 입력 받습니다.
    std::cout << "나이를 입력하세요 : ";
    int getNewAge = 0;
    std::cin >> getNewAge;
    userData[4].setAge(getNewAge);

    while (true){
        // 사용자의 아이디를 받을 배열입니다.
        char getNewId[100]= {};
        while (true){
            // cin을 쓰고나서 남아있는 \n이 cin.getline을 사용할때 방해를 해서 아래 줄을 넣어 지워줬습니다.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "아이디를 입력하시오 (최대 99자, 소문자 영문, 숫자만 입력 가능): ";
            //사용자에게 아이디를 입력 받습니다.
            std::cin.getline(getNewId, 99);
            int checkLowerDigit = 0;
            for (int i = 0; i < 99; ++i) {
                // 소문자 영문, 숫자를 제외한 다른 문자가 들어있는지 확인하는 과정입니다.
                // '\0' 도 포함해줘야 합니다.
                if (islower(getNewId[i]) || isdigit(getNewId[i]) || getNewId[i] == '\0'){}
                else{
                    checkLowerDigit++;
                    break;
                }
            }

            // 사용자의 아이디에 소문자 영문, 숫자만 있었으면 다음 과정으로 아니면 다시 반복합니다.
            if (checkLowerDigit == 0){
                std::cout << "아이디 중복 검사를 시작합니다."<< std::endl;
                break;
            }
            else{
                std::cout << "사용자 id에는 소문자 영문, 숫자만 입력 가능합니다. 다른 아이디를 입력하기 위해서는 엔터를 눌러주세요."<< std::endl;
                for (int i = 0; i < 100; ++i) {
                    getNewId[i]='\0';
                }
            }
        }

        // 배열로 받은 id를 string으로 바꿔줍니다.
        std::string getNewIdSting(getNewId);
        int checkIdOverlap = 0;
        // 기존 데이터를 보며 중복되는지 확인합니다.
        for (int i = 0; i < 4; ++i) {
            if (userData[i].getID() == getNewIdSting){
                checkIdOverlap++;
            }
        }
        // 만약 중복되지 않았다면 비밀번호를 만드는걸로 넘어갑니다.
        if (checkIdOverlap == 0){
            std::cout << "아이디 생성이 성공적으로 진행되었습니다."<<std::endl;
            userData[4].setID(getNewId);
            break;
        }
        else{
            std::cout << "이미 존재하는 아이디입니다. 다른 아이디를 입력하기 위해서는 엔터를 눌러주세요."<< std::endl;
        }
    }
    std::cout <<"[비밀번호를 입력해주세요]\n" << "- 비밀번호의 길이는 11자 ~ 19자 입니다.\n" <<"- 특수문자: ! “ # $ % & ‘ ( ) * + , - . / : ; < = > ? @ [ ₩ ] ^ _ ‘ { } | ~ 를 반드시 포함해야합니다: ";
    while (true){
        char getNewPw[100]= {};
        std::cin.getline(getNewPw, 99);
        if(getNewPw[10]=='\0' || getNewPw[21]!='\0'){
            std::cout << "비밀번호의 길이는 11자 ~ 19자 입니다."<<std::endl;
            std::cout << "비밀번호를 입력해주세요 :" ;
        }
        else{
            int checkPwNum = 0;
            for (int i = 0; i <99; ++i){
                if(pwCheckFunc(getNewPw[i])){
                    checkPwNum++;
                    break;
                }
            }
            if (checkPwNum == 0){
                std::cout << "비밀번호는 적어도 하나의 특수문자를 포함해야 합니다." <<std::endl;
                std::cout << "비밀번호를 입력해주세요 :" ;
            } else{
                userData[4].setPWD(getNewPw);
                break;
            }
        }
    }

    // 전체 정보를 출력합니다.
    for (int i = 0; i < 5; ++i) {
        userData[i].prinrtMemInfo();
    }
    // 할당한 메모리를 반환합니다.
    delete[] userData;
    return 0;
}
