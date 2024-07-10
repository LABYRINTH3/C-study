#include <iostream>
#include <string>
using namespace std;


class Movie{
public:
    string title;
    double rate; // 평점
    string movieDirect; // 감독 이름

    Movie();
    // 영화 정보를 넣어주는 함수입니다.
    void inputMovie(string title, double rate, string movieDirect);
    // 영화 정보를 출력해줍니다.
    void printMovie();
};

// 객체를 생성했을때 초기화를 해줍니다.
Movie::Movie(){
    title = " ";
    rate = 0;
    movieDirect = " ";
}
void Movie::inputMovie(string title, double rate, string movieDirect){
    this->title = title;
    this->rate = rate;
    this->movieDirect = movieDirect;
}
void Movie::printMovie(){
    cout << "제목: " << title << "  평점: " << rate << " | 감독 이름: " << movieDirect << endl;
}


class Audience{
public:
    string name;
    int age;
    string sex;

    Audience();
    // 관객의 정보를 넣어줍니다.
    void inputAudience(string name, int age, string sex);
    // 관객의 정보를 출력해줍니다.
    void printAudience();
    // 영화 제목으로 검색합니다.
    void searchTitle(Movie movie[], string& title);
    // 영화 감독 이름으로 검색합니다.
    void searchDirector(Movie movie[], string& movieDirect);
};

// 객체 생성후 초기화를 해줬습니다.
Audience::Audience(){
    name = " ";
    age = 0;
    sex = " ";
}
// 멤버 변수에 정보를 넣어주는 함수입니다.
void Audience::inputAudience(string name, int age, string sex){
    this->name = name;
    this->age = age;
    this->sex = sex;
}

// 관객의 정보를 출력해줍니다.
void Audience::printAudience(){
    cout << "이름: " << name << " | 나이: " << age << " | 성별: " << sex << endl;
}

// 반복문을 이용해 같은 감독 이름이 일치하는지 확인합니다. 있으면 출력 없으면 없다고 출력합니다.
void Audience::searchDirector(Movie movie[], string& movieDirect){
    int check = 0;
    for (int i = 0; i < 5; i++){
        if (movie[i].movieDirect == movieDirect){
            movie[i].printMovie();
            check++;
        }
    }
    if (check == 0){
        cout << "찾는 감독의 영화가 없습니다." << endl;
    }
}

// 반복문을 이용해 같은 영화 제목이 일치하는지 확인합니다. 있으면 출력 없으면 없다고 출력합니다.
void Audience::searchTitle(Movie movie[], string& title){
    int check = 0;
    for (int i = 0; i < 5; i++){
        if (movie[i].title == title){
            movie[i].printMovie();
            check++;
        }
    }
    if (check == 0){
        cout << "찾는 제목의 영화가 없습니다." << endl;
    }
}



class Admin{
public:
    // 영화 제목으로 영화를 찾은 후 정보를 수정해주는 함수입니다.
    void changeMovieTitle(Movie movie[], string& title);
    // 감독 이름으로 영화를 찾고 정보를 수정해주는 함수입니다.
    void changeMovieDirector(Movie movie[], string& movieDirect);
    // 관객의 정보를 수정해주는 함수입니다.
    void changeAudience(Audience& audience);
};


void Admin::changeMovieTitle(Movie movie[], string& title){
    int check = 0;
    for (int i = 0; i < 5; i++){
        if (movie[i].title == title){
            string titlea;
            double ratea;
            string directa;
            cout << "[ 현재 영화 정보 ]"<<endl;
            movie[i].printMovie();
            cout << "새로운 정보를 입력하세요"<< endl;
            
            cout << "제목: ";
            getline(cin, titlea);
            
            cout << "평점: ";
            cin >> ratea;
            cin.ignore(); // 저번 과제를 진행할때와 같은 오류가 발생해 엔터를 없애주는 ignore을 사용했습니다.
            
            cout << "감독 : ";
            getline(cin, directa);

            movie[i].inputMovie(titlea, ratea, directa);
            check++;
        }
    }
    if (check == 0){
        cout << "찾는 제목의 영화가 없습니다." << endl;
    }
}

void Admin::changeMovieDirector(Movie movie[], string& movieDirect){
    int check = 0;
    for (int i = 0; i < 5; i++){
        if (movie[i].movieDirect == movieDirect){
            string titlea;
            double ratea;
            string directa;
            cout << "[ 현재 영화 정보 ]"<<endl;
            movie[i].printMovie();
            cout << "새로운 정보를 입력하세요"<< endl;
            cout << "제목: ";
            getline(cin, titlea);

            cout << "평점: ";
            cin >> ratea;
            cin.ignore(); // 저번 과제를 진행할때와 같은 오류가 발생해 엔터를 없애주는 ignore을 사용했습니다.
            
            cout << "감독 : ";
            getline(cin, directa);

            movie[i].inputMovie(titlea, ratea, directa);
            check++;
        }
    }
    if (check == 0){
        cout << "찾는 감독의 영화가 없습니다." << endl;
    }
}

void Admin::changeAudience(Audience& audience){
    string namea;
    int agea;
    string sexa;

    cout << "[ 현재 관객 정보 ]" <<endl;
    audience.printAudience();
    cout << "새로운 정보를 입력하세요 " << endl;

    cout << "이름: ";
    getline(cin, namea);

    cout << "나이: ";
    cin >> agea;
    cin.ignore(); // 저번 과제를 진행할때와 같은 오류가 발생해 엔터를 없애주는 ignore을 사용했습니다.
    
    cout << "성별: ";
    getline(cin, sexa);
    audience.inputAudience(namea, agea, sexa);
}

int main(){
    Movie movie[5];
    movie[0].inputMovie("분노의 질주: 더 얼티메이트", 9.07, "저스틴 린");
    movie[1].inputMovie("도라에몽: 스탠바이미2", 5.98, "야기 류이치");
    movie[2].inputMovie("귀멸의 칼날: 무한기차편", 9.62, "소토자키 하루오");
    movie[3].inputMovie("더 스파이", 8.78, "도미닉 스키너");
    movie[4].inputMovie("스파이럴", 9.02, "대런 린 보우즈만");

    // 관객 정보를 담기위한 객체를 만듭니다.
    Audience audience;
    audience.inputAudience("이율무", 25, "여자");

    Admin admin;

    // 영화의 정보와 관객의 정보를 출력합니다.
    cout << " [ 영화 정보 ]" << endl;
    for (int i = 0; i < 5; i++){
        movie[i].printMovie();
    }
    cout << "[ 관객 정보 ]" << endl;
    audience.printAudience();
    cout << "\n";

    // 영화 제목으로 검색합니다.
    string titleb;
    cout << "검색할 영화의 제목을 입력하세요: ";
    getline(cin, titleb);
    audience.searchTitle(movie, titleb);
    cout << "\n";

    // 감독 이름으로 검색합니다.
    string directb;
    cout << "검색할 감독의 이름을 입력하세요: ";
    getline(cin, directb);
    audience.searchDirector(movie, directb);
    cout << "\n";

    // 영화 정보를 수정합니다. 총 4번 수정해야 합니다. 제목으로 2번 감독 이름으로 2번 했습니다.
    for (int i = 0; i < 2; ++i){
        string changeTitle;
        cout << "수정할 영화 제목을 입력하세요: ";
        getline(cin, changeTitle);
        admin.changeMovieTitle(movie, changeTitle);
        cout << "\n";
    }

    for (int i = 0; i < 2; ++i){
        string changeDirect;
        cout << "\n수정할 영화의 감독 이름을 입력하세요: ";
        getline(cin, changeDirect);
        admin.changeMovieDirector(movie, changeDirect);
        cout << "\n";
    }


    // 관객의 정보를 수정합니다.
    admin.changeAudience(audience);

    //영화와 관객의 정보를 출력합니다.
    cout << "[ 영화 정보 업데이트 ]" << endl;
    for (int i = 0; i < 5; i++){
        movie[i].printMovie();
    }
    cout << "[ 관객 정보 업데이트 ]" << endl;
    audience.printAudience();
    return 0;
}