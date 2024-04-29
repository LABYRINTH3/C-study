#include <iostream>
using namespace std;

// 함수 오버로딩을 이용해 입력값을 정수로 설정해 두 값을 더한 후 반환했다.
int add(int a1, int b1){
    return a1 + b1;
}

// 함수 오버로딩을 이용해 입력값을 실수로 설정해 두 값을 더한후 반환했다.
float add(float a2, float b2){
    return a2 + b2;
}

// 함수가 배열을 받고 반복문을 이용해 반복해 배열 안의 값을 더한다.
int add(int arr[], int num){
    int arrSum = 0;
    for (int i = 0; i < num; ++i) {
        arrSum += arr[i];
    }
    return arrSum;
}

void add(int arr3[], int arr1[], int arr2[], int num){
    for (int i = 0; i < num; ++i) {
        arr3[i] = arr1[i] + arr2[i];
    }
}


int main() {
    int a1;
    int b1;
    // 두 정수를 입력 받는 코드입니다.
    cout << "첫번째 정수를 입력하시오: ";
    cin >> a1;
    cout << "두번째 정수를 입력하시오: ";
    cin >> b1;
    cout << add(a1, b1) << endl;

    float a2;
    float b2;
    // 두 실수를 입력 받는 코드입니다.
    cout << "첫번째 실수를 입력하시오: ";
    cin >> a2;
    cout << "두번째 실수를 입력하시오: ";
    cin >> b2;
    cout << add(a2, b2) << endl;

    // 배열의 수를 입력 받는 코드입니다.
    int numArr;
    cout << "첫번째 배열의 수를 입력하시오: ";
    cin >> numArr;
    // 첫번째 배열을 입력 받는 코드입니다.
    int arr_1[numArr];
    for (int i = 0; i < numArr; ++i) {
        cout << "첫번째 배열의 "<< i <<"번째 정수를 입력하시오: ";
        cin >> arr_1[i];
    }
    cout << add(arr_1, numArr) << endl;

    // 두번째 배열을 입력 받는 코드입니다.
    cout << "두번째 배열의 수는 " << numArr << "입니다." << endl;
    int arr_2[numArr];

    for (int i = 0; i < numArr; ++i) {
        cout << "두번째 배열의 "<< i <<"번째 정수를 입력하시오: ";
        cin >> arr_2[i];
    }
    int arr_3[4];
    add(arr_3, arr_1, arr_2, numArr);

    // 배열의 합의 결과를 출력하는 코드입니다.
    for (int i = 0; i < 4; i++) {
        cout << arr_3[i] << " ";
    }
    return 0;
}
