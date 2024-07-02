#include <iostream>
#include <string>
using namespace std;

class Tax {
protected:
    string name;
    int price;
public:
    // 생성자
    Tax(string &name, int price);
    // 가상 함수입니다.
    virtual double calculateTax() = 0;
    virtual void print();
    // 가상 소멸자입니다.
    virtual ~Tax();
};


// Necessity 클래스 - Tax 클래스를 상속 받았습니다.
class Necessity : public Tax {
public:
    // 생성자
    Necessity(string &name, int price);
    // calculateTax 세금을 계산하는 함수입니다.
    double calculateTax() override;
};


// Luxury 클래스 - Tax 클래스를 상속 받았습니다.
class Luxury : public Tax {
public:
    // 생성자
    Luxury(string &name, int price);
    // calculateTax 세금을 계산 함수입니다.
    double calculateTax() override;
};


// Food 클래스 - Tax 클래스를 상속 받았습니다.
class Food : public Tax {
public:
    // 생성자
    Food(string &name, int price);
    // 세금 계산 함수
    double calculateTax() override;
};


// Tax 클래스
Tax::Tax(string &name, int price) {
    this->name = name;
    this->price = price;
}

void Tax::print(){
    // 이름과 세금을 출력합니다.
    cout << "제품 : " << name << endl;
    double tax = calculateTax();
    cout << "세금 : " << tax << endl;
}

Tax::~Tax() {}





Necessity::Necessity(string &name, int price) : Tax(name, price) {}

// 세금을 계산하는 함수입니다.
double Necessity::calculateTax(){
    return price * 0.10;
}





Luxury::Luxury(string &name, int price) : Tax(name, price) {}

// 세금을 계산하는 함수입니다.
double Luxury::calculateTax(){
    price = price  * 0.3;
    return price;
}





Food::Food(string &name, int price) : Tax(name, price) {}

// 세금을 계산하는 함수입니다.
double Food::calculateTax(){
    return price * 0.15;
}




int main() {
    Tax* products[3];
    string Necessitya = "휴지";
    string Luxurya = "금시계";
    string Fooda = "사과";

    products[0] = new Necessity(Necessitya, 5000);
    products[1] = new Luxury(Luxurya, 1000000);
    products[2] = new Food(Fooda, 550);

    for (int i = 0; i < 3; ++i) {
        products[i]->print();
        cout << "\n";
        delete products[i]; // 동적 메모리를 해제합니다.
    }
    return 0;
}
