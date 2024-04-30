        #ifndef MEMBER_H
        #define MEMBER_H
        class Member {
        private:
            char* m_id;   // 아이디
            char* m_pwd;  // 비밀번호
            char* m_name; // 이름
            int m_age;    // 나이

        public:
            Member(); // 디폴트 생성자
            Member(const char* id, const char* pwd, const char* name, int age); // 매개변수를 입력 받는 생성자

            // 각각의 멤버변수의 값을 반환해주는 함수
            char* getID();
            char* getPWD();
            char* getName();
            int getAge();

            // 각각의 멤버변수의 값을 매개변수의 값으로 바꾸어주는 프로시저
            void setID(const char* id);
            void setPWD(const char* pwd);
            void setName(const char* name);
            void setAge(int age);

            void prinrtMemInfo(); // 아이디, 이름, 나이를 출력해주는 프로시저

            ~Member(); // 소멸자
        };
        #endif