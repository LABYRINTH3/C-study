#include <iostream>

using namespace std;
class RationalNumber { //유리수
private:
    int numerator; //분자
    int denominator; //분모
    void reduction(RationalNumber&); //약분 (계산후에는 반드시 약분을 해야 함.)
public:
    // 디폴트 매개변수를 가지는 생성자를 만들었습니다.
    RationalNumber (int n = 0, int d = 1); // n/d
    //단 위 중복된 생성자들을 디폴트 매개 변수를 가진 하나의 생성자로 작성하라
    //유리수와 유리수를 더함.
    const RationalNumber operator+ ( const RationalNumber& );

    /*이곳에 operator- 에 대한 프로토타입을 선언하시오. */
    const RationalNumber operator- ( const RationalNumber& );

    const RationalNumber operator* ( const RationalNumber& );
    const RationalNumber operator/ ( const RationalNumber& );

    bool operator> ( const RationalNumber& ) const; //유리수의 크기를 비교
    bool operator< ( const RationalNumber& ) const;

    /* 이곳에 operator <= 에 대한 프로토타입을 선언하시오. */
    bool operator<= ( const RationalNumber& ) const;

    bool operator>= ( const RationalNumber& ) const;
    bool operator== ( const RationalNumber& ) const;
    bool operator!= ( const RationalNumber& ) const;
    friend ostream& operator << (ostream&, const RationalNumber&);
};

// 약분
void RationalNumber::reduction(RationalNumber& num) {
    // 둘중 더 큰 수를 구한후
    if (num.denominator > num.numerator){
        // 더 큰 수 까지 루프를 돌며 하나씩 나눠서 나머지를 봅니다.
        // 작은 수부터 나누면 9의 배수 같은 경우 3으로 나누고 넘어가는 문제가 발생해 큰 수에서 부터 줄이는 방법을 채택했습니다.
        for (int i = num.denominator; i > 2; --i) {
            if (num.denominator % i == 0 && num.numerator % i == 0){
                // 둘다 0으로 나누어 떨어지는 경우 값을 대체 합니다.
                num.denominator = num.denominator / i;
                num.numerator = num.numerator / i;
            }
        }
    } else{
        // 위의 과정을 반복합니다.
        for (int i = num.numerator; i > 2; --i) {
            if (num.denominator % i == 0 && num.numerator % i == 0){
                num.denominator = num.denominator / i;
                num.numerator = num.numerator / i;
            }
        }
    }
};
//RationalNumber::RationalNumber() {
//    numerator = 0;
//    denominator = 1;
//}
//
//RationalNumber::RationalNumber(int n) {
//    numerator = n;
//    denominator = 1;
//}

//단 위 중복된 생성자들을 디폴트 매개 변수를 가진 하나의 생성자로 작성하라는 조건을 만족하기 위해...
RationalNumber::RationalNumber(int n, int d) {
    numerator = n;
    denominator = d;
}

const RationalNumber RationalNumber::operator+ (const RationalNumber& num){
    RationalNumber answer;
    // 두 유리수를 더하기 위해 분모를 같게 만들고 분자에 분모를 곱한 값 두개를 더합니다.
    answer.denominator = this->denominator * num.denominator;
    answer.numerator = this->numerator * num.denominator + num.numerator * this->denominator;
    reduction(answer);
    return answer;
}

const RationalNumber RationalNumber::operator- (const RationalNumber& num) {
    RationalNumber answer;
    // 두 유리수를 빼기 위해 분모를 같게 만들고 분자에 분모를 곱한 값 두개를 뺍니다.
    answer.denominator = this->denominator * num.denominator;
    answer.numerator = this->numerator * num.denominator - num.numerator * this->denominator;
    reduction(answer);
    return answer;
}

const RationalNumber RationalNumber::operator* (const RationalNumber& num) {
    RationalNumber answer;
    // 두 유리수를 곱하기 위해 분자와 분모를 곱합니다.
    answer.denominator = this->denominator * num.denominator;
    answer.numerator = this->numerator * num.numerator;
    reduction(answer);
    return answer;
}

const RationalNumber RationalNumber::operator/(const RationalNumber &num) {
    RationalNumber answer;
    // 두 유리수를 곱하기 위해 역수를 분자와 분모를 곱합니다.
    answer.denominator = this->denominator * num.numerator;
    answer.numerator = this->numerator * num.denominator;
    reduction(answer);
    return answer;
}

bool RationalNumber::operator> (const RationalNumber& num) const {
    // 대소 비교를 통해 어떤 수가 더 큰지 확인합니다.
    if (this->numerator/this->denominator > num.numerator/num.denominator)
        return true;
    else
        return false;
}
// 같은 방식으로
bool RationalNumber::operator< (const RationalNumber& num) const {
    if (this->numerator/this->denominator < num.numerator/num.denominator)
        return true;
    else
        return false;
}
// 같은 방식으로
bool RationalNumber::operator>= (const RationalNumber& num) const {
    if (this->numerator/this->denominator >= num.numerator/num.denominator)
        return true;
    else
        return false;
}
// 같은 방식으로
bool RationalNumber::operator<= (const RationalNumber& num) const {
    if (this->numerator/this->denominator<= num.numerator/num.denominator)
        return true;
    else
        return false;
}
// 같은 방식으로
bool RationalNumber::operator== (const RationalNumber& num) const {
    if (this->numerator/this->denominator == num.numerator/num.denominator)
        return true;
    else
        return false;
}
// 같은 방식으로
bool RationalNumber::operator!= (const RationalNumber& num) const {
    if (this->numerator/this->denominator != num.numerator/num.denominator)
        return true;
    else
        return false;
}

// ostream이 뭔지 모르겠어서 블로그를 참고하고 ostream이 무엇인지에 대해 알아보았습니다.
// https://blog.naver.com/xtelite/50017022142
// ostream 객체 (std::cout 등)랑 << 연산자를 사용해서 RationalNumber 객체를 출력합니다.
ostream& operator << (ostream& stream, const RationalNumber& r)
{
    stream << r.numerator << "/" << r.denominator;
    return stream;
}


//함수를 구현하십시오
int main() {
    RationalNumber c(7, 3);
    RationalNumber d(3, 9);
    RationalNumber x;
    x = c + d;

    cout << c << " + " << d << " = " << x << endl;
    x = c - d;
    cout << c << " - " << d << " = " << x << endl;
    x = c * d;
    cout << c << " * " << d << " = " << x << endl;
    x = c / d;
    cout << c << " / " << d << " = " << x << endl;
    RationalNumber a(2, 5), b(3), y;
    cout << y << endl;
    // 다른 operator들을 test 할 수 있는 코드를 각자 작성
    cout << a << " < " << b << " : " << (a < b) << endl;

    cout << a << " > " << b << " : " << (a > b) << endl;

    cout << a << " <= " << b << " : " << (a <= b) << endl;

    cout << a << " >= " << b << " : " << (a >= b) << endl;

    cout << a << " == " << b << " : " << (a == b) << endl;

    cout << a << " != " << b << " : " << (a != b) << endl;
};
