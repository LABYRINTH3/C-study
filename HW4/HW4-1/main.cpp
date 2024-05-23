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
    bool operator ==(const Monster &temp);
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
Monster::Monster(const Monster &temp) {
    // new를 이용해 새로운 메모리를 할당합니다.
    // 메모리의 길이는 name 의 길이 + 1 입니다.
    this->name = new char [strlen(temp.name) + 1];
    // strcpy를 이용해 새로 할당한 메모리에 문자열을 집어 넣습니다.
    strcpy(this->name, temp.name);
    this -> hp = temp.hp;
}
int main()
{
    Monster mon1((char*)"bear", 50);
    Monster mon2((char*)"dragon", 1030);
    Monster mon3 = mon1;
    if (mon2 == mon3)
        cout << "it is same" << endl;
    return 0;
}
