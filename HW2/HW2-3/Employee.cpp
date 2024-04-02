// Employee.cpp
#include "Employee.h"
Employee::Employee() {}
Employee::Employee(string name, int age, string depart, string phone_num) {
    e_name = name; e_age = age; e_depart = depart; e_phone = phone_num;
}
//직원의 이름을 반환하는 멤버 함수입니다.
string Employee::getName() {
    return e_name;
}
//직원의 나이를 반환하는 멤버 함수입니다.
int Employee::getAge() {
    return  e_age;
}
//직원이 속한 부서를 반환하는 멤버 함수입니다.
string Employee::getDepart() {
    return e_depart;
}
//직원의 전화번호를 반환하는 멤버 함수입니다.
string Employee::getPhone() {
    return e_phone;
}
//직원의 이름을 설정하는 멤버 함수입니다.
void Employee::setName(string name) {
    e_name = name;
}
//직원의 나이를 설정하는 멤버 함수입니다.
void Employee::setAge(int age) {
    e_age = age;
}
//직원이 속한 부서를 설정하는 멤버 함수입니다.
void Employee::setDepart(string depart) {
    e_depart = depart;
}
//직원의 전화번호를 설정하는 멤버 함수입니다.
void Employee::setPhone(string phone_num) {
    e_phone = phone_num;
}
//직원 정보를 출력하는 멤버 함수입니다.
void Employee::printEmp() {
    cout << "이름 : " << e_name << " | 나이 : " << e_age << " | 부서 : " << e_depart << " | 전화번호 : " << e_phone << endl;
}
//소멸자
Employee::~Employee() {}