#pragma once 
#include <iostream>
#include <string>
namespace yjy2372032 
{
    class student 
    {
    //private:
        std::string name{}; //string 멤버변수 추가
        int id{};
        int score{};
        char grade{}; 
    
        void testId(){
            if (id < 1000000 || id> 9999999)
            {
                std::cout << "Invalid ID\n";
                std::exit(1); 
            }
        }
        void testScore(){ 
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
        public://생성자 name추가/ const랑 reference는 함께 쓰임
            student(const std::string& n = "no name yet", int d = 1234567, int s = 0, char g = 'F')
            :name{n},id{d},score{s},grade{g}
            {
                testId(); testScore(); testGrade();
            }
            void input(){
                std::cout << "Enter name: ";
                //input함수 추가: std::string형 멤버변수는 std::string의 getline함수와 입력조작기 std::ws를 사용
                std::getline(std::cin >> std::ws, name); //name이 string일때 쓸 수 있는 ws는 공백 tap줄바꿈 없이 name에 값 넣어줌
                std::cout << "Enter id:";
                std::cin >> id; testId();
                std::cout << "Enter score:";
                std::cin >> score; testScore();
                std::cout << "Enter grade:";
                std::cin >> grade; testGrade();
            }
          
            friend std::istream& operator>>(std::istream& is, student& s) //reference안 적어주면 값이 저장되지 않음
            {
                //입력연산자에 name추가
                std::cout << "Enter name: ";
                std::getline(is >> std::ws, s.name);
                std::cout<< " Enter id: ";
                is >> s.id; s.testId();
                std::cout<< " Enter score: ";
                is >> s.score; s.testScore();
                std::cout<< " Enter grade: ";
                is >> s.grade; s.testGrade();
                return is;
            }
            //접근함수 name 추가
            void setName(const std::string& n){name = n;} //여기서는 const &써도 되고 안 써도 됨
            void setId(int d){id = d; testId();}
            void setScore(int s){score = s; testScore();}
            void setGrade(char g){grade = g; testGrade();}
            void print() const  
            {
                 std::cout << name << " (" <<id << "):" << score << " (" << grade << ")\n";
            }
            
         
            friend std::ostream& operator<<(std::ostream& os, const student& s)
            {
                //출력연산자에 name추가
                os << s.name << "," << s.id << "," << s.score << "," << s.grade <<"\n";
                return os;

            }
            //const멤버함수
            const std::string& getName() const {return name;}
            int getId() const {return id;}
            int getScore() const {return score;}
            char getGrade() const {return grade;}
            student operator++()//후위증가연산자에 name추가
            {
                return student{name, id, ++score, grade};
            }
       
            student operator++(int) //후위증가연산자에 name추가
            {
                student temp{name, id, score, grade};
                score++;
                return temp;
                
            } 
            friend bool operator==(const student& s1, const student& s2)
            {
                return s1.id == s2.id;
            }
            friend int operator+(const student& s1, const student& s2)
            {
                return s1.score + s2.score; 
            }

    };
}
