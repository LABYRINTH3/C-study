#include <iostream>
#include <cstring>
#include "Member.h"

Member::Member(){
};
Member::Member(const char *id,const char *pwd,const char *name, int age) {
    // new를 이용해 메모리를 동적할당합니다.
    m_id = new char[strlen(id) + 1];
    // strcpy를 이용해 동적할당한 메모리에 사용자에게 받은 값을 복사해 넣습니다.
    strcpy(m_id, id);

    m_pwd = new char[strlen(pwd) + 1];
    strcpy(m_pwd, pwd);

    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);

    m_age = age;
}
// 요청한 정보를 반환하는 멤버 함수입니다.
char* Member::getID(){
    return m_id;
}
char* Member::getPWD(){
    return m_pwd;
}
char* Member::getName(){
    return m_name;
}
int Member::getAge(){
    return m_age;
}

void Member::setID(const char* id) {
    delete[] m_id;  // 기존에 할당된 메모리가 있다면 메모리 해제합니다.
    m_id = new char[strlen(id) + 1];
    strcpy(m_id, id);
}

void Member::setPWD(const char* pwd) {
    delete[] m_pwd;
    m_pwd = new char[strlen(pwd) + 1];
    strcpy(m_pwd, pwd);
}

void Member::setName(const char* name) {
    delete[] m_name;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

void Member::setAge(int age) {
    m_age = age;
}

void Member::prinrtMemInfo() {
    std::cout << "이름: " << m_name << " | 아이디: " << m_id << " | 나이: " << m_age << std::endl;
}
Member::~Member(){
    // delete를 이용해서 메모리를 해제해 메모리 누수를 방지합니다.
    delete[] m_id;
    delete[] m_pwd;
    delete[] m_name;
}