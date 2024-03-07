#include <iostream>
using namespace std;

//int g =20;  /*전역변수*/
//
//int add(int x, int y){
//    return x+y;
//}

//int main() {
//    int a, b, sum; //지역변수
//    cin >> a >> b; //입력 받기
//    sum = a + b;
//    cout << sum << "\n";
//    cout << add(a, b) << "\n";
//    cout << "Hello, World!" << endl;
//    return 0;
//}


//int main(){
//    int score, div;
//    cout << "점수를 입력하시오: ";
//    cin >> score;
//    if (score > 100 || score < 0){
//        cout << "잘못된 점수입니다.";
//        return 0;
//    }
//    div = score/10;
//    switch(div){
//        case 9:
//            cout << "A";
//            break;
//        case 8:
//            cout << "B";
//            break;
//        case 7:
//            cout << "C";
//            break;
//        case 6:
//            cout << "D";
//            break;
//        default:
//            cout << "F";
//            break;
//    }
//}

//for문 예제
//int main() {
//    int a, b, sum = 0; //지역변수
//    cout << "두개의 정수 입력";
//    cin >> a >> b; //입력 받기
//    for (int i = a; i <= b ; ++i) {
//        sum +=i;
//    }
//    cout << a <<"부터 " << b <<"까지의 합은 "<< sum <<endl;
//    return 0;
//}

//while문 예제
//int main(){
//    int i, a, b, sum = 0;
//    cout << "두개의 정수 입력 : ";
//    cin >> a >> b;
//    i = a;
//    while(i<=b){
//        sum +=i;
//        i++;
//    }
//    cout << a << "부터 " << b <<"까지의 합은 "<< sum << endl;
//    return 0;
//}

//do - while 예제
//int main() {
//    int i, a, b, sum = 0;
//    cout << "두 개의 정수 입력>>";
//    cin >> a >> b;
//
//    i = a;
//    do{
//        sum+=i;
//        i++;
//    }while(i<=b);
//    cout << a << "부터 " << b <<"까지의 합은 "<< sum << endl;
//    return 0;
//}

//int main(){
//    int a;
//    while(true){
//        cout << "input integer : ";
//        cin >> a;
//        if (a==0){
//            cout << "END" << "\n";
//            break;
//        }
//        if(a % 3 != 0){
//            cout << "No" << "\n";
//            continue; // continue 를 쓰면 아래를 실행하지 않고 반복문 위로 다시 올라간다.
//        }
//        cout << "Yes" << "\n";
//    }
//    return 0;
//}

//int main(){
//    int n[10];
//    double d[] = {0.1, 0.2, 0.5, 3.9};
//
//    int i;
//    for (int i = 0; i < 10; ++i) {
//        n[i] = i*2;
//    }
//    for (int i = 0; i < 10; ++i) {
//        cout << n[i] << " ";
//    }
//    cout << "\n";
//    double sum = 0;
//    for (int i = 0; i < 4; ++i) {
//        sum += d[i];
//    }
//    cout << "배열 d의 합은 " << sum;
//    return 0;
//}

//adder 함수 만들기
//int adder(int a, int b){
//    int sum;
//    sum = a+b;
//    return sum;
//}
//
//int main(){
//    int n = adder(235, 456);
//    cout << 235 << "와 " << 456 << "의 합은" << n << "입니다\n";
//
//    int a, b;
//    cout << "두개의 정수를 입력하세요 : ";
//    cin >> a >> b;
//    n = adder(a, b);
//    cout << a << "와 " << b << "의 합은" << n << "입니다\n";
//}

//
//namespace 예시
//namespace math {
//    int add(int a, int b) {
//        return a + b;
//    }
//
//    int subtract(int a, int b) {
//        return a - b;
//    }
//}
//
//int main() {
//    // Call functions from the 'math' namespace
//    std::cout << "Addition: " << math::add(5, 3) << std::endl;
//    std::cout << "Subtraction: " << math::subtract(10, 4) << std::endl;
//
//    return 0;
//}

//잘못된 using namespace;
//
//namespace ns1 {
//    int value = 5;
//}
//
//namespace ns2 {
//    int value = 10;
//}
//
//int main() {
//    using namespace ns1;
//    using namespace ns2;
//
//    // Error: Ambiguous reference to 'value'
//    std::cout << "Value: " << value << std::endl;
//
//    return 0;
//}

//int main(){
//    char getString[100];
//    cin.getline(getString, 100, 'a');
//    cout << getString;
//    return 0;
//}

#include <iostream>
#include <string>

int main() {
    std::string myString;

    std::cin >> myString;
    std::cout << "String: " << myString << std::endl;
    return 0;
}