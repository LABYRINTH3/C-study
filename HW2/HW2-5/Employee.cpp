// Employee.cpp
#include "Employee.h"
Employee::Employee() {}
Employee::Employee(string name, int age, string depart, string phone_num) {
    e_name = name; e_age = age; e_depart = depart; e_phone = phone_num;
}
//������ �̸��� ��ȯ�ϴ� ��� �Լ��Դϴ�.
string Employee::getName() {
    return e_name;
}
//������ ���̸� ��ȯ�ϴ� ��� �Լ��Դϴ�.
int Employee::getAge() {
    return  e_age;
}
//������ ���� �μ��� ��ȯ�ϴ� ��� �Լ��Դϴ�.
string Employee::getDepart() {
    return e_depart;
}
//������ ��ȭ��ȣ�� ��ȯ�ϴ� ��� �Լ��Դϴ�.
string Employee::getPhone() {
    return e_phone;
}
//������ �̸��� �����ϴ� ��� �Լ��Դϴ�.
void Employee::setName(string name) {
    e_name = name;
}
//������ ���̸� �����ϴ� ��� �Լ��Դϴ�.
void Employee::setAge(int age) {
    e_age = age;
}
//������ ���� �μ��� �����ϴ� ��� �Լ��Դϴ�.
void Employee::setDepart(string depart) {
    e_depart = depart;
}
//������ ��ȭ��ȣ�� �����ϴ� ��� �Լ��Դϴ�.
void Employee::setPhone(string phone_num) {
    e_phone = phone_num;
}
//���� ������ ����ϴ� ��� �Լ��Դϴ�.
void Employee::printEmp() {
    cout << "�̸� : " << e_name << " | ���� : " << e_age << " | �μ� : " << e_depart << " | ��ȭ��ȣ : " << e_phone << endl;
}
//�Ҹ���
Employee::~Employee() {}