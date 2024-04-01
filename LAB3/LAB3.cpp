#include <iostream>
using namespace std;

class OneDPattern{
    // 멤버변수
private:
    int maxWidth; //패턴의 최대 길이
    int width; //실제패턴의길이
    char *fill;
public:
    // 멤버함수
    OneDPattern();// 기본 생성자
    OneDPattern(int w); // 생성자  – w 크기의 char array를 동적으로 할당
    ~OneDPattern();//소멸자: – 동적 메모리 반환

    void setFill (char c[]);
//    • 끝이 null로 끝나는 string(char array) c[]를 입력 받아 최대 maxWidth 길이만큼 fill[]에 복사하고 실제 길이를 width에 저장
//    • string c[]의 길이가 maxWidth보다 길면 maxWidth까지만 복사 저장
    void changeWidth (int w);
//    • 이전의 동적 메모리를 반환하고, 새로운 길이(w)의 동적 메모리를 새로 할당 받고, maxWidth = w, width = 0으로 초기화
    void draw();
//    • fill[]에 저장된 패턴을 화면에 출력
};

OneDPattern::OneDPattern(){
    fill = NULL;
    maxWidth = 0;
    width = 0;
}
OneDPattern::OneDPattern(int w) {
    maxWidth = w;
    width = 0;
    fill = new char[w];
}
OneDPattern:: ~OneDPattern(){
    delete []fill;
}

void OneDPattern::setFill(char *c) {
    for (int i = 0; i < 10; ++i) {
        if (c[i]==NULL){
            width = i+1;
        }
        fill[i]=c[i];
    }
}
void OneDPattern::changeWidth(int w) {
    delete []fill;
    fill = new char[w];
    maxWidth = w;
    width = 0;
}
void OneDPattern::draw() {
    cout << fill<<endl;
}

int main() {
    OneDPattern odp (5) ;

    char p1[6] = "#@$*%";
    odp.setFill (p1) ;

    odp.draw() ;

    odp.changeWidth (10) ;

    char p2[10] ;
    cin>>p2;
    odp.setFill (p2) ;

    odp.draw() ;
    return 0;
}
