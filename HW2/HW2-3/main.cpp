#include <iostream>
#include "Employee.h"
int main() {
    // Class 객체로 이뤄진 배열 생성(동적 할당) 및 초기화
    // 배열의 길이는 4, 위의 직원들의 정보를 넣어 초기화
    Employee* employeeData = new Employee[4];
    for (int i = 0; i < 4; ++i) {
        employeeData[i] = Employee("", 0, "", "");
    }
    employeeData[0].setName("김철수");
    employeeData[0].setAge(23);
    employeeData[0].setDepart("인사팀");
    employeeData[0].setPhone("010-2342-1453");

    employeeData[1].setName("정연우");
    employeeData[1].setAge(31);
    employeeData[1].setDepart("연구계획팀");
    employeeData[1].setPhone("010-4231-1241");

    employeeData[2].setName("박지운");
    employeeData[2].setAge(35);
    employeeData[2].setDepart("인사팀");
    employeeData[2].setPhone("010-3421-6894");

    employeeData[3].setName("최지우");
    employeeData[3].setAge(26);
    employeeData[3].setDepart("영업1팀");
    employeeData[3].setPhone("010-9653-3532");

    // class의 출력 프로시저를 통해 객체들의 정보를 나열해서 출력
    for (int i = 0; i < 4; ++i) {
        employeeData[i].printEmp();
    }
    // 종료할 때 동적 할당한 메모리의 반환을 확실히 할 것
    delete[]employeeData;
    return 0;
}