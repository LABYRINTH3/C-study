#include <iostream>
#include <cstring>
using namespace std;
class Monster {
private:
    char* name;
    int hp;
public:
    Monster();
    Monster(const char* name, int hp);
    Monster(const Monster& temp); // 복사생성자
    Monster& operator= (const Monster& temp); //복사대입연산자
    bool operator ==(const Monster& temp);
    ~Monster();
};
Monster::Monster(const char *name, int hp) {
    this -> hp = hp;
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    this->name = new char [strlen(name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(this->name, name);
}
Monster& Monster::operator= (const Monster &temp) {
    //https://dydtjr1128.github.io/effectivec++/2019/07/25/Effective-Cpp-item-11.html
    //해당 블로그에 의하면 자기대입을 처리하지 않으면 메모리 누수등의 문제가 발생할 수 있고
    // 해결 방법으로는 if(this == &whs) return *this;의 형태로 자기대입을 처리해야 한다고 합니다.
    if(this == &temp){
        return *this;
    }
    // 자신을 복사하지 않았다면 삭제
    delete[] name;
    // 후 대입
    hp = temp.hp;
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    name = new char [strlen(temp.name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(name, temp.name);
    // 반환
    return *this;
}

Monster::Monster(const Monster &temp) {
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    this->name = new char [strlen(temp.name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(this->name, temp.name);
    this -> hp = temp.hp;
}

bool Monster::operator== (const Monster &temp) {
    // strcmp를 이용해서 두 문자열이 같은지 비교하는 과정을 거쳤습니다.
    if (strcmp(this->name, temp.name)==0 && hp == temp.hp){
        return true;
    }
    else
        return false;
}
Monster::~Monster() {
    delete[] name;
}

int main()
{
    Monster mon1((char*)"bear", 50);
    Monster mon2((char*)"dragon", 1030);
    Monster mon3 = mon1;
    if (mon2 == mon3) {
        cout << "it is same" << endl;
    } else {
        cout << "it is not same" << endl;
    }

    mon2 = mon1;
    if (mon2 == mon1) {
        cout << "mon2 is now same as mon1" << endl;
    }

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
class Monster {
private:
    char* name;
    int hp;
public:
    Monster();
    Monster(const char* name, int hp);
    Monster(const Monster& temp); // 복사생성자
    Monster& operator= (const Monster& temp); //복사대입연산자
    bool operator ==(const Monster& temp);
    ~Monster();
};
Monster::Monster(const char *name, int hp) {
    this -> hp = hp;
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    this->name = new char [strlen(name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(this->name, name);
}
Monster& Monster::operator= (const Monster &temp) {
    //https://dydtjr1128.github.io/effectivec++/2019/07/25/Effective-Cpp-item-11.html
    //해당 블로그에 의하면 자기대입을 처리하지 않으면 메모리 누수등의 문제가 발생할 수 있고
    // 해결 방법으로는 if(this == &whs) return *this;의 형태로 자기대입을 처리해야 한다고 합니다.
    if(this == &temp){
        return *this;
    }
    // 자신을 복사하지 않았다면 삭제
    delete[] name;
    // 후 대입
    hp = temp.hp;
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    name = new char [strlen(temp.name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(name, temp.name);
    // 반환
    return *this;
}

Monster::Monster(const Monster &temp) {
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    this->name = new char [strlen(temp.name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(this->name, temp.name);
    this -> hp = temp.hp;
}

bool Monster::operator== (const Monster &temp) {
    // strcmp를 이용해서 두 문자열이 같은지 비교하는 과정을 거쳤습니다.
    if (strcmp(this->name, temp.name)==0 && hp == temp.hp){
        return true;
    }
    else
        return false;
}
Monster::~Monster() {
    delete[] name;
}

int main()
{
    Monster mon1((char*)"bear", 50);
    Monster mon2((char*)"dragon", 1030);
    Monster mon3 = mon1;
    if (mon2 == mon3) {
        cout << "it is same" << endl;
    } 
    else {
        cout << "it is not same" << endl;
    }
    mon2 = mon1;
    if (mon2 == mon1) {
        cout << "mon2 == mon1" << endl;
    }
    return 0;
}
