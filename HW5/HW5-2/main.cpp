#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string model;
    int speed;
public:
    //생성자
    Vehicle(int speed, string &model);
    // 멤버 함수
    void increaseSpeed();
    void decreaseSpeed();
    void changeModel(string &model);
    virtual void print();
};

class Bike : public Vehicle {
private:
    string type;
public:
    // 생성자
    Bike(int speed, string &model, string &type);
    // 멤버 함수
    void changeType(string &type);
    void print() override;
};

// ElecBike 클래스 - Bike 클래스를 상속 받았습니다.
class ElecBike : public Bike {
private:
    int gear;
public:
    // 생성자
    ElecBike(int gear, int speed, string &model, string &type);
    // 멤버 함수
    void increaseSpeed(); // 속도를 증가 시키는 함수입니다.
    void decreaseSpeed(); // 속도를 감소 시키는 함수입니다.
    void increaseGear(); // 기어를 증가 시키는 함수입니다.
    void decreaseGear(); // 기어를 감소 시키는 함수입니다.
    void print() override; // 정보를 출력하는 함수입니다.
};


Vehicle::Vehicle(int speed, string &model) {
    this->speed = speed;
    this->model = model;
}
void Vehicle::increaseSpeed() {
    speed++; // 속도가 1 증가합니다.
}
void Vehicle::decreaseSpeed() {
    speed--; // 속도가 1 감소합니다.
}
void Vehicle::changeModel(string &model) {
    this->model = model; // 모델을 변경합니다.
}
void Vehicle::print() {
    cout << "모델 : " << model << " | 속도 : " << speed << endl; // 정보 출력
}



Bike::Bike(int speed, string &model, string &type) : Vehicle(speed, model) {
    this->type = type;
}
void Bike::changeType(string &type) {
    this->type = type;
}
void Bike::print() {
    Vehicle::print();
    cout << "자전거 종류: " << type << endl; // 자전거 종류를 출력합니다.
}



ElecBike::ElecBike(int gear, int speed, string &model, string &type) : Bike(speed, model, type) {
    this->gear = gear; // 기어 수 초기화
}
void ElecBike::increaseGear() {
    gear++; // 기어를 1 증가 시킵니다.
}
void ElecBike::decreaseGear() {
    gear--; // 기어를 1 감소 시킵니다.
}
void ElecBike::increaseSpeed() {
    // 속도를 5 증가시킵니다 // 반복문을 써서 5번 반복 합니다.
    for (int i = 0; i < 5; i++) {
        Vehicle::increaseSpeed();
    }
}
void ElecBike::decreaseSpeed() {
    // 속도를 5 감소시킵니다 // 반복문을 써서 5번 반복합니다.
    for (int i = 0; i < 5; i++) {
        Vehicle::decreaseSpeed();
    }
}
void ElecBike::print() {
    Bike::print();
    cout << "기어 : " << gear << endl; // 기어의 수를 출력합니다.
}


int main() {
    string bikeModel = "t235";
    string ebikeModel = "a39";

    string bikeType = "city";
    string ebikeType2 = "hybrid";


    Bike bike(10, bikeModel, bikeType); // Bike 객체 생성
    ElecBike e_bike(3, 30, ebikeModel, ebikeType2); // ElecBike 객체 생성

    bike.print();
    cout << '\n';
    // 자전거의 속도를 변경합니다
    bike.increaseSpeed(); // 속도 1 증가시킵니다
    bike.print();
    cout << '\n';
    bike.decreaseSpeed(); // 속도 1 감소시킵니다
    bike.print();
    cout << '\n';
    // 자전거의 모델을 변경합니다
    string a = "모델 변경";
    bike.changeModel(a);
    bike.print();
    cout << '\n';

    e_bike.print();
    cout << '\n';
    // 전기 자전거의 기어를 변경합니다
    // e_bike 기어 변경
    e_bike.increaseGear();
    e_bike.print();
    cout << '\n';
    e_bike.decreaseGear();
    e_bike.print();
    cout << '\n';
    e_bike.decreaseSpeed(); // 속도 5 감소시킵니다
    e_bike.print();
    cout << '\n';
    e_bike.increaseSpeed(); // 속도 5 증가시킵니다
    e_bike.print();
    cout << '\n';
    // 전기 자전거의 종류를 변경합니다
    string b = "전기 자전거 종류를 변경합니다.";
    e_bike.changeType(b);
    e_bike.print();
    cout << '\n';

    return 0;
}
