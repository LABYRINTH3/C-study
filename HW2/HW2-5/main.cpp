#include <iostream>
#include "Employee.h"
int main() {
    // Class 객체로 이뤄진 배열 생성(동적 할당) 및 초기화
    // 배열의 길이는 4, 위의 직원들의 정보를 넣어 초기화
    Employee* emp_list1 = new Employee[4];
    for (int i = 0; i < 4; ++i) {
        emp_list1[i] = Employee("", 0, "", "");
    }
    emp_list1[0].setName("김철수");
    emp_list1[0].setAge(23);
    emp_list1[0].setDepart("인사팀");
    emp_list1[0].setPhone("010-2342-1453");

    emp_list1[1].setName("정연우");
    emp_list1[1].setAge(31);
    emp_list1[1].setDepart("연구계획팀");
    emp_list1[1].setPhone("010-4231-1241");

    emp_list1[2].setName("박지운");
    emp_list1[2].setAge(35);
    emp_list1[2].setDepart("인사팀");
    emp_list1[2].setPhone("010-3421-6894");

    emp_list1[3].setName("최지우");
    emp_list1[3].setAge(26);
    emp_list1[3].setDepart("영업1팀");
    emp_list1[3].setPhone("010-9653-3532");

    // 새로 추가할 직원의 수를 입력받습니다.
    int arraryNum;
    cout << "새로 추가할 직원의 수를 입력하시오 : ";
    cin >> arraryNum;

    // 기존 직원과 새 직원을 모두 포함할 수 있는 새 동적배열을 할당합니다.
    Employee* emp_list2 = new Employee[arraryNum + 4];
    for (int i = 0; i < 4; ++i) {
        // 기존 직원의 정보를 새 배열로 복사합니다.
        emp_list2[i] = emp_list1[i];
    }

    // 새로운 직원의 정보를 입력 받습니다.
    for (int i = 0; i < arraryNum; ++i) {
        cout << "새로 추가하는 " << i + 1 << "번째 직원의 이름을 입력하시오 : ";
        string getNewData;
        int getNewAge;
        cin >> getNewData;
        emp_list2[i + 4].setName(getNewData);

        cout << "새로 추가하는 " << i + 1 << "번째 직원의 나이를 입력하시오 : ";
        cin >> getNewAge;
        emp_list2[i + 4].setAge(getNewAge);

        cout << "새로 추가하는 " << i + 1 << "번째 직원의 부서를 입력하시오 : ";
        cin >> getNewData;
        emp_list2[i + 4].setDepart(getNewData);

        cout << "새로 추가하는 " << i + 1 << "번째 직원의 전화번호를 입력하시오 : ";
        cin >> getNewData;
        emp_list2[i + 4].setPhone(getNewData);

        cout << "성공적으로 진행되었습니다. \n";
    }

    // class의 출력 프로시저를 통해 객체들의 정보를 나열해서 출력합니다.
    for (int i = 0; i < arraryNum + 4; ++i) {
        emp_list2[i].printEmp();
    }

    // 종료할 때 동적 할당한 메모리의 반환을 확실히 할 것
    //메모리를 반환합니다.
    delete[]emp_list1;
    delete[]emp_list2;
    return 0;
}