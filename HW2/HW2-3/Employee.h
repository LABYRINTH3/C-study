#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
//이름 나이 부서 전화번호
//김철수 23 인사팀 010-2342-1453
//정연우 31 연구계획팀 010-4231-1241
//박지운 35 인사팀 010-3421-6894
//최지우 26 영업1팀 010-9653-3532
using namespace std;
class Employee {
private:
    string e_name; int e_age; string e_depart; string e_phone;
public:
    Employee();
    Employee(string name, int age, string depart, string phone);

    // 각각의 멤버변수의 값을 반환해주는 함수
    string getName(); // 이름
    int getAge(); // 나이
    string getDepart(); // 부서
    string getPhone(); // 전화번호

// 디폴트 생성자
// 각각의 멤버변수의 값을 매개변수의 값으로 바꾸어주는 프로시저
    void setName(string name);
    void setAge(int age);
    void setDepart(string depart);
    void setPhone(string phone);

    // 이름, 나이, 부서, 전화번호를 출력해주는 함수
    void printEmp();

    // 소멸자
    ~Employee();

};
#endif