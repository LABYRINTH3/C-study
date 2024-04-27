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
    int a1 = 4;
    int b1 = 5;
    cout << add(a1, b1) << endl;

    float a2 = 4.5;
    float b2 = 3.2;
    cout << add(a2, b2) << endl;

    int arr_1[4] = {45, 32, 11, 65};
    cout << add(arr_1, 4) << endl;

    int arr_2[4] = {11, 43, 32, 56};
    int arr_3[4];
    // 해당 코드를 작성함으로써 함수에는 주소값을 주었다
    // 따라서 함수에서 배열을 조작하면 배열 안에 있는 값이 변경된다.
    add(arr_3, arr_1, arr_2, 4);

    for(int i = 0; i < 4; i++){
        cout << arr_3[i] << " ";
    }
    cout << endl;

    return 0;
}