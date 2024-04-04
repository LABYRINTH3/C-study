// C211128 이태훈 HW1 1번 문제

#include <iostream>
#include <cstring>
using namespace std;


// 아이디는 taehoon
// 비밀번호는 cpp 입니다!!



int main() {
    int num =0;
    while (true){
        // 아이디와 비밀번호를 입력받을 문자열을 만들어준다.
        char id[11];
        char password[16];
        // 사용자로 부터 아이디와 비밀번호를 입력 받는다.
        cout << "아이디를 입력하세요. (아이디는 영문 10글자 이내입니다): ";
        cin >> id;
        cout << "아이디를 입력하세요. (비밀번호는 영문 15글자 이내입니다): ";
        cin >> password;

        //id 와 비밀번호가 일치하면 성공 메세지를 출력하고 프로그램을 종료한다.
        if (strcmp(id, "taehoon") == 0 && strcmp(password, "cpp") == 0){
            cout << "아이디와 비밀번호가 일치합니다. 성공입니다." << endl;
            cout << "프로그램을 정상 종료합니다." << endl;
            break;
        }
        // 만약 둘 중 하나라도 틀리면 아래의 코드가 실행된다.
        // 만약 5번 입력이 틀리면 실행이 끝나게 하기 위해 num을 만들어 한번 실행할때마다 +1 해준다
        // num == 5 가 되면 비밀번호가 옳지 않다는 경고문을 내보내고 프로그램을 종료한다.
        else{
            num++;
            if (num == 5){
                cout << "아이디와 비밀번호를 5번 틀렸습니다.실패입니다." << endl;
                break;
            }
            cout << "아이디와 비밀번호가 일치하지 않습니다." << endl;
            cout << "아이디와 비밀번호를 다시 입력해주세요." << endl;

        }
    }
    return 0;
}
