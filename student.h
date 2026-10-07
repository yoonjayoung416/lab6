
// 2. 클래스명.h: 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상): id(7digit), score(0~100), grade('A'~'F')
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴

#pragma once //헤더파일에는 header guard가 있어야 함
#include <iostream>

namespace yjy2372032 
{
    class student //class 정의
    {
    //private:
        int id{};
        int score{};
        char grade{}; //아스키테이블로 182
    // private 멤버함수 정의 id(7digit), score(0~100), grade('A'~'F')
        void testId(){//id (1000000 ~ 9999999): 7 digits
            if (id < 1000000 || id> 9999999)
            {
                std::cout << "Invalid ID\n";
                std::exit(1); //중괄호 없으면 프로그램 매번 종료됨
            }
        }
        void testScore(){ //score (0~100)
            if (score < 0 || score > 100)
            {
                std::cout<< "Invalid score\n";
                std::exit(1);
            }
           
        }
        void testGrade(){
            if(grade < 'A' || grade > 'F')
            {
                std::cout << "Invalid grade\n";
                std::exit(1);
            }
        }
        public://생성자
            student(int d = 1234567, int s = 0, char g = 'F')
            :id{d},score{s},grade{g}
            {
                testId(); testScore(); testGrade();
            }
            void input(){
                std::cout << "Enter id:";
                std::cin >> id; testId();
                std::cout << "Enter score:";
                std::cin >> score; testScore();
                std::cout << "Enter grade:";
                std::cin >> grade; testGrade();
            }
            void setId(int d){id = d; testId();}
            void setScore(int s){score = s; testScore();}
            void setGrade(char g){grade = g; testGrade();}
            //const멤버함수
            void print() const { std::cout << id << "," <<score << "," << grade <<"\n";}
            int getId() const {return id;}
            int getScore() const {return score;}
            char getGrade() const {return grade;}

    };
}
