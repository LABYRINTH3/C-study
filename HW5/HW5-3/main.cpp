#include <iostream>
#include <string>
using namespace std;


class Dispenser {
protected:
    int food; //먹이
    string model;//디스펜서 모델
    string made; //제조 이름
public:
    //생성자
    Dispenser(string& model, string& made, int food);

    virtual void feed(int petNumber) = 0; //petNumber의 수 만큼 먹이를 줍니다.
    virtual void printData() = 0; //데이터를 출력합니다.

    void setFood(int food); //남은 먹이의 양을 설정합니다.
    int foodAmount(); //남은 먹이의 양을 반환합니다.

    void setModel(string& model); //디스펜서 모델 이름을 세팅합니다.
    string dispenserModel(); //디스펜서의 모델 이름을 반환합니다.

    void setMade(string& made); //제조사의 이름을 설정합니다.
    string madeBy(); //제조사의 이름을 줍니다.

    //오류를 방지하기 위해 추가했습니다.
    virtual ~Dispenser() = default;
};

// Dispenser 클래스입니다.
Dispenser::Dispenser(string& model, string& made, int food) {
    this -> model = model;
    this -> made = made;
    this -> food = food;
}

void Dispenser::setFood(int food){
    this -> food = food;
}
int Dispenser::foodAmount(){
    return food;
}

void Dispenser::setModel(string& model){
    this -> model = model;
}
string Dispenser::dispenserModel(){
    return model;
}

void Dispenser::setMade(string& made){
    this -> made = made;
}
string Dispenser::madeBy(){
    return made;
}


// dogDispenser 클래스입니다.
class DogfoodDispenser : public Dispenser{
private:
    int anFood; //남은 간식의 수
public:
    DogfoodDispenser(string& model, string& made, int food, int anFood);

    void feed(int petNumber) override; //개에게 먹이를 줍니다.

    int anFoodCount(); //남은 간식의 양을 반환합니다.
    void setAnFood(int anFood); //남은 간식의 양을 줍니다.

    void printData() override; //데이터를 출력합니다.
};

DogfoodDispenser::DogfoodDispenser(string& model, string& made, int food, int anFood) : Dispenser(model, made, food) {
    this -> anFood = anFood;//간식의 양을 설정합니다.
}
void DogfoodDispenser::feed(int petNumber){
    // 필요한 음식 및 간식의 양 계산
    int needFood = petNumber * 100; //개 1마리당 사료 100g
    int needAnFood = petNumber;

    // 음식과 간식이 충분한지 확인
    if (food >= needFood && anFood >= needAnFood) {
        food = food - needFood;
        anFood = anFood - needAnFood;
        cout << "배식하였습니다." << endl;
    }
    else {
        cout << "먹이가 부족합니다. 보충해 주세요." << endl;
    }
}

int DogfoodDispenser::anFoodCount(){
    return anFood;
}
void DogfoodDispenser::setAnFood(int anFood){
    this -> anFood = anFood;
}

void DogfoodDispenser::printData() {
    cout << "강아지용 : " << model << " | " << made << " | 남은 사료 " << food << "g | 남은 간식 " << anFood << "개" << endl;
}
// CatfoodDispenser 클래스
class CatfoodDispenser : public Dispenser{
private:
    int anFood; // 간식 양
public:
    // 생성자
    CatfoodDispenser(string& model, string& made, int food, int anFood);

    void feed(int petNumber) override; //고양이에게 먹이를 줍니다.

    void setAnFood(int anFood); // 남은 간식의 양을 설정
    int anFoodCount(); // 남은 간식의 양을 반환

    void printData() override; //데이터를 출력합니다.
};

// CatfoodDispenser 클래스
CatfoodDispenser::CatfoodDispenser(string& model, string& made, int food, int anFood) : Dispenser(model, made, food){
    this -> anFood = anFood;
}
void CatfoodDispenser::feed(int petNumber){
    // 필요한 음식 및 간식의 양 계산
    int needFood = petNumber * 80; // 고양이 한마리가 80 사료가 필요합니다.
    int needAnFood = petNumber; // 고양이 1마리당 간식이 1개 필요합니다.

    // 음식과 간식이 충분한지 확인합니다.
    if (food >= needFood && anFood >= needAnFood){
        food = food - needFood;
        anFood = anFood - needAnFood;
        cout << "배식했습니다." << endl;
    }
    else{
        cout << "먹이가 부족합니다. 보충해 주세요." << endl;
    }
}

void CatfoodDispenser::setAnFood(int anFood){
    this -> anFood = anFood;
}
int CatfoodDispenser::anFoodCount(){
    return anFood;
}


void CatfoodDispenser::printData(){
    cout << "고양이용 : " << model << " | " << made << " | 남은 사료 " << food << "g | 남은 간식 " << anFood << "개" << endl;
}

int main(){
    Dispenser* p[2];
    string dogFood1 = "PO-35x5";
    string dogFood2 = "펫홈";
    p[0] = new DogfoodDispenser(dogFood1, dogFood2, 800, 10);

    string catFood1 = "AA-6x45";
    string catFood2 = "마이펫";
    p[1] = new CatfoodDispenser(catFood1, catFood2, 1000, 20);

    cout << "현재 작동 중인 배식기는 아래와 같습니다." << endl;
    p[0] -> printData(); // 강아지용 디스펜서 정보 출력
    p[1] -> printData(); // 고양이용 디스펜서 정보 출력

    string check1 = "n";
    int check2 = 0;
    while (check1 == "y" || check2 == 0) {
        int animalType, petNumber;
        cout << "동물(1: 강아지용, 2: 고양이용)과 애완동물의 수를 입력하세요 >>  ";
        cin >> animalType >> petNumber; // 동물 종류와 수를 입력받습니다.

        if (animalType == 1) {
            p[0] -> feed(petNumber); // 개에게 먹이를 줍니다.
        }
        if (animalType == 2) {
            p[1] -> feed(petNumber); // 고양이에게 먹이를 줍니다.
        }

        cout << "현재 작동 중인 배식기는 아래와 같습니다." << endl;
        p[0] -> printData(); // 강아지용 디스펜서 데이터 출력합니다.
        p[1] -> printData(); // 고양이용 디스펜서 데이터 출력합니다.

        cout << "계속 배식하시겠습니까? (y/n) >> ";
        cin >> check1;
        check2++;
    }

    // 메모리를 해제합니다.
    delete p[0];
    delete p[1];

    return 0;
}
