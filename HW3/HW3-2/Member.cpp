#include <iostream>
#include <cstring>
#include "Member.h"

Member::Member() {};
Member::Member(char *id, char *pwd, char *name, int age) {
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

Member::~Member(){
    // delete를 이용해서 메모리를 해제해 메모리 누수를 방지합니다.
    delete[] m_id;
    delete[] m_pwd;
    delete[] m_name;
}