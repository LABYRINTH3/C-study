#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
//�̸� ���� �μ� ��ȭ��ȣ
//��ö�� 23 �λ��� 010-2342-1453
//������ 31 ������ȹ�� 010-4231-1241
//������ 35 �λ��� 010-3421-6894
//������ 26 ����1�� 010-9653-3532
using namespace std;
class Employee {
private:
    string e_name; int e_age; string e_depart; string e_phone;
public:
    Employee();
    Employee(string name, int age, string depart, string phone);

    // ������ ��������� ���� ��ȯ���ִ� �Լ�
    string getName(); // �̸�
    int getAge(); // ����
    string getDepart(); // �μ�
    string getPhone(); // ��ȭ��ȣ

    // ����Ʈ ������
    // ������ ��������� ���� �Ű������� ������ �ٲپ��ִ� ���ν���
    void setName(string name);
    void setAge(int age);
    void setDepart(string depart);
    void setPhone(string phone);

    // �̸�, ����, �μ�, ��ȭ��ȣ�� ������ִ� �Լ�
    void printEmp();

    // �Ҹ���
    ~Employee();

};
#endif