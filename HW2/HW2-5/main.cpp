#include <iostream>
#include "Employee.h"
int main() {
    // Class ��ü�� �̷��� �迭 ����(���� �Ҵ�) �� �ʱ�ȭ
    // �迭�� ���̴� 4, ���� �������� ������ �־� �ʱ�ȭ
    Employee* emp_list1 = new Employee[4];
    for (int i = 0; i < 4; ++i) {
        emp_list1[i] = Employee("", 0, "", "");
    }
    emp_list1[0].setName("��ö��");
    emp_list1[0].setAge(23);
    emp_list1[0].setDepart("�λ���");
    emp_list1[0].setPhone("010-2342-1453");

    emp_list1[1].setName("������");
    emp_list1[1].setAge(31);
    emp_list1[1].setDepart("������ȹ��");
    emp_list1[1].setPhone("010-4231-1241");

    emp_list1[2].setName("������");
    emp_list1[2].setAge(35);
    emp_list1[2].setDepart("�λ���");
    emp_list1[2].setPhone("010-3421-6894");

    emp_list1[3].setName("������");
    emp_list1[3].setAge(26);
    emp_list1[3].setDepart("����1��");
    emp_list1[3].setPhone("010-9653-3532");

    // ���� �߰��� ������ ���� �Է¹޽��ϴ�.
    int arraryNum;
    cout << "���� �߰��� ������ ���� �Է��Ͻÿ� : ";
    cin >> arraryNum;

    // ���� ������ �� ������ ��� ������ �� �ִ� �� �����迭�� �Ҵ��մϴ�.
    Employee* emp_list2 = new Employee[arraryNum + 4];
    for (int i = 0; i < 4; ++i) {
        // ���� ������ ������ �� �迭�� �����մϴ�.
        emp_list2[i] = emp_list1[i];
    }

    // ���ο� ������ ������ �Է� �޽��ϴ�.
    for (int i = 0; i < arraryNum; ++i) {
        cout << "���� �߰��ϴ� " << i + 1 << "��° ������ �̸��� �Է��Ͻÿ� : ";
        string getNewData;
        int getNewAge;
        cin >> getNewData;
        emp_list2[i + 4].setName(getNewData);

        cout << "���� �߰��ϴ� " << i + 1 << "��° ������ ���̸� �Է��Ͻÿ� : ";
        cin >> getNewAge;
        emp_list2[i + 4].setAge(getNewAge);

        cout << "���� �߰��ϴ� " << i + 1 << "��° ������ �μ��� �Է��Ͻÿ� : ";
        cin >> getNewData;
        emp_list2[i + 4].setDepart(getNewData);

        cout << "���� �߰��ϴ� " << i + 1 << "��° ������ ��ȭ��ȣ�� �Է��Ͻÿ� : ";
        cin >> getNewData;
        emp_list2[i + 4].setPhone(getNewData);

        cout << "���������� ����Ǿ����ϴ�. \n";
    }

    // class�� ��� ���ν����� ���� ��ü���� ������ �����ؼ� ����մϴ�.
    for (int i = 0; i < arraryNum + 4; ++i) {
        emp_list2[i].printEmp();
    }

    // ������ �� ���� �Ҵ��� �޸��� ��ȯ�� Ȯ���� �� ��
    //�޸𸮸� ��ȯ�մϴ�.
    delete[]emp_list1;
    delete[]emp_list2;
    return 0;
}