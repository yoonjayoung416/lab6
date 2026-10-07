#pragma once
#include "student.h"

namespace yjy2372032
{
    class studentStatus //  -생성자: 모든 멤버변수 초기화, 기본값 설정
    {
        student s;
        bool status;
    public:
        studentStatus(student s0 = student{1234567,0,'F'}, bool st = false)//초기화
            :s{s0}, status{st}
        {}
        // -print: 표준스트림출력으로 멤버변수들 출력
        void print() const //studentStatus;:print()
        {
            s.print(); //student::print()
            if (status) std::cout <<"on school\n";
            else std::cout << "NOT on school\n";

        }
        // -클래스1형 객체의 접근함수를 참조형식으로 구현
        const student& getStudent() const {return s;}
        void setStudent(const student& s0) {s= s0;}

    };
}