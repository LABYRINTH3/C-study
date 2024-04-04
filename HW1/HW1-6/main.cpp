// C211128 이태훈 HW1 5번 문제
#include <iostream>
#include <string>
using namespace std;

int count_words(char *s){
//문자열에 포함된 단어의 개수를 반환해주는 함수
// 단어의 개수는 띄어쓰기의 수 + 1이기 때문에 띄어쓰기의 수를 세는 코드를 작성하고 + 1 했습니다.
int charLen = strlen(s);
int blackNum = 0;
    for (int i = 0; i < charLen; ++i) {
        if (s[i] == ' '){
            blackNum++;
        }
    }
    blackNum++;
    // 만약 문자열이 띄어쓰기 한칸인 경우 그것은 단어가 없는 예외 사항이기 때문에 예외처리 했습니다.
    if (*s == ' '){
        blackNum = 0;
    }
    return blackNum;
}

int count_sentences(char *s){
//문자열에 포함된 문장의 개수를 반환해주는 함수
// 문장은 항상 . 으로 끝나기 때문에 온점의 개수를 세주면 문장의 개수를 알 수 있기 때문에 온점을 세는 코드를 작성했습니다.
    int charLen = strlen(s);
    int sentenceNum = 0;
    for (int i = 0; i < charLen; ++i) {
        if (s[i] == '.') {
            sentenceNum++;
        }
    }
    return sentenceNum;
}

int main() {
    // char을 이용해서 교수님께서 주신 문자열을 가르키는 포인터를 words1,2,3에 할당했습니다.
    char *words1 = "Object-oriented programming is a programming paradigm based on the concept of objects, which may contain data, in the form of fields, often known as attributes; and code, in the form of procedures, often known as methods. A feature of objects is that an object's procedures can access and often modify the data fields of the object with which they are associated. In OOP, computer programs are designed by making them out of objects that interact with one another. There is significant diversity of OOP languages, but the most popular ones are class-based, meaning that objects are instances of classes, which typically also determine their type.";
    char *words2 = "melon, apple, grape, kiwi, pear, orange";
    char *words3 = " ";

    //문자열에 포함된 단어의 수를 반환하는 함수에서 값을 받아서 출력하는 코드입니다.
    int firstCountWords = count_words( words1 );
    cout << "첫 번째 문자열에 포함된 단어 수: " << firstCountWords << endl;
    int secondCountWords = count_words( words2 );
    cout << "두 번째 문자열에 포함된 단어 수: " << secondCountWords << endl;
    int thirdCountWords = count_words( words3 );
    cout << "세 번째 문자열에 포함된 단어 수: " << thirdCountWords << endl;
    cout << '\n';

    // 문장 세는 함수에서 문자의 개수를 반환 받고 문장 개수를 출력하는 코드입니다.
    int firstCountSentence = count_sentences( words1);
    cout << "첫 번째 문자열에 포함된 문장 수: " << firstCountSentence << endl;
    int secondCountSentence = count_sentences( words2);
    cout << "두 번째 문자열에 포함된 문장 수: " << secondCountSentence << endl;
    int thirdCountSentence = count_sentences( words3);
    cout << "세 번째 문자열에 포함된 문장 수: " << thirdCountSentence << endl;
    return 0;
}
