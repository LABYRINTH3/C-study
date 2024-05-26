#include <iostream>
using namespace std;


class Record {
    //클래스를 구현하십시오
private:
    string name;
    int pushup;
    double run;
    int pullup;
    double jump;
    int situp;
    double sumpushup;
    double sumrun;
    double sumpullup;
    double sumjump;
    double sumsitup;
public:
    Record();
    void setname(string &name);
    void setdata(int pushup, double run, int pullup, double jump, int situp);
    void printdata();
    void printaverage(int a);
    string getname();
    friend Record& operator--(Record &data);
    friend Record& operator--(Record &data, int);
    Record operator+ (Record &data) const;
};

Record::Record() {
    pushup = 0;
    run = 0;
    pullup = 0;
    jump = 0;
    situp = 0;
    sumpushup = 0;
    sumrun = 0;
    sumpullup = 0;
    sumjump = 0;
    sumsitup = 0;
}
void Record::setname(std::string &name) {
    // 이름 입력하고 나머지는 0으로 초기화
    this -> name = name;
    pushup = 0;
    run = 0;
    pullup = 0;
    jump = 0;
    situp = 0;
}
void Record::setdata(int pushup, double run, int pullup, double jump, int situp) {
    // 입력한 데이터 입력
    this->pushup = pushup;
    this->run = run;
    this->pullup = pullup;
    this->jump = jump;
    this->situp = situp;
}

void Record::printdata() {
    cout << name << " | 팔굽혀 펴기: " << pushup << "| 50m 달리기: " << run << "| 턱걸이: " << pullup << "| 제자리멀리뛰기: "<< jump <<"| 윗몸일으키기: "<< situp << endl;
}

void Record::printaverage(int a) {
    cout << "팔굽혀 펴기: " << sumpushup/a << "| 50m 달리기: " << sumrun/a << "| 턱걸이: " << sumpullup/a << "| 제자리멀리뛰기: " << sumjump/a
         << "| 윗몸일으키기: " << sumsitup/a << endl;
}

string Record::getname() {
    return name;
}

// 전위 연산자 --를 정의합니다
Record& operator--(Record &data) {
    // 문제에 써있는 대로 점수를 뺍니다.
    data.pushup -= 5;
    data.run += 0.5;
    data.pullup -= 3;
    data.jump -= 30.0;
    data.situp -= 5;
    return data;
}

// 후위 연산자 --를 정의합니다
Record& operator--(Record &data, int) {
    // 문제에 써있는 대로 점수를 뺍니다.
    data.pushup -= 5;
    data.run += 0.5;
    data.pullup -= 3;
    data.jump -= 30.0;
    data.situp -= 5;
    return data;
}

Record Record::operator+ (Record &data) const {
    Record sum;
    sum.sumpushup = sumpushup + data.pushup;
    sum.sumrun = sumrun + data.run;
    sum.sumpullup = sumpullup + data.pullup;
    sum.sumjump = sumjump + data.jump;
    sum.sumsitup = sumsitup + data.situp;
    return sum;
}



int main() {
    bool check = true;
    int num;

    // 최대 인원이 100명 이기 때문에
    Record people[100];
    // 정보가 몇명 입력 되었는지 확인하기 위한 수입니다.
    int peopleNum = 0;
    while (check) {
        cout << "1~5중 선택하시오: ";
        cin >> num;
        if (num == 1) {
            // 이름과 기록 입력 받기
            string name;
            int pushup;
            double run;
            int pullup;
            double jump;
            int situp;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "팔굽혀 펴기 , 50m 달리기, 턱걸이, 제자리 멀리뛰기, 윗몸 일으키기를 순서대로 입력세요: ";
            cin >> pushup >> run >> pullup >> jump >> situp;
            people[peopleNum].setname(name);
            people[peopleNum].setdata(pushup, run, pullup, jump, situp);
            peopleNum++;
        }
        else if (num == 2) {
        //기록된 자료 출력
        // 기록된 모든 자료를 출력하기 위해 반복문을 사용했습니다.
            for (int i = 0; i < peopleNum; ++i) {
                people[i].printdata();
            }
        }
        else if (num == 3) {
            //참가자 이름을 입력 받아 그 참가자에게 패널티 주기
            // 참가자 이름을 받고 그 이름에 맞는 사람에게 패널티를 주는 반복문을 작성합니다.
            string penaltyName;
            cout << "패널티를 줄 사람: ";
            cin >> penaltyName;
            // 패널티를 줄 사람을 찾습니다.
            for (int i = 0; i < peopleNum; ++i) {
                if(people[i].getname() == penaltyName){
                    people[i]--;
                }
            }
        }
        else if (num == 4) {
            //종목별 평균을 내서 출력하는 기능
            Record average;
            for (int i = 0; i < peopleNum; ++i) {
                average = average + people[i];
            }
            average.printaverage(peopleNum);
        }
        else if (num == 5) {
        //프로그램 종료 구현
            cout << "프로그램을 종료합니다.";
            break;
        }
    }
}