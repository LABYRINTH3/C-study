#include <iostream>
#include "Employee.h"
int main() {
    // Class ��ü�� �̷��� �迭 ����(���� �Ҵ�) �� �ʱ�ȭ
    // �迭�� ���̴� 4, ���� �������� ������ �־� �ʱ�ȭ
    Employee* employeeData = new Employee[4];
    for (int i = 0; i < 4; ++i) {
        employeeData[i] = Employee("", 0, "", "");
    }
    employeeData[0].setName("��ö��");
    employeeData[0].setAge(23);
    employeeData[0].setDepart("�λ���");
    employeeData[0].setPhone("010-2342-1453");

    employeeData[1].setName("������");
    employeeData[1].setAge(31);
    employeeData[1].setDepart("������ȹ��");
    employeeData[1].setPhone("010-4231-1241");

    employeeData[2].setName("������");
    employeeData[2].setAge(35);
    employeeData[2].setDepart("�λ���");
    employeeData[2].setPhone("010-3421-6894");

    employeeData[3].setName("������");
    employeeData[3].setAge(26);
    employeeData[3].setDepart("����1��");
    employeeData[3].setPhone("010-9653-3532");

    // class�� ��� ���ν����� ���� ��ü���� ������ �����ؼ� ���
    for (int i = 0; i < 4; ++i) {
        employeeData[i].printEmp();
    }
    // ������ �� ���� �Ҵ��� �޸��� ��ȯ�� Ȯ���� �� ��
    delete[]employeeData;
    return 0;
}