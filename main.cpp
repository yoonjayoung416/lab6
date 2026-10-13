#include "student.h"
#include <array>

// 1의 본인이름학번의 네임스페이스안에 print클래스Array 함수를 정의하세요. 
// 리턴은 없고, 매개변수는 const 클래스형 배열과 const int형 배열크기
namespace yjy2372032
{
    void printStudentArray(const student a[], const int n)
    {
        // for구문을 이용하여 배열원소를 하나씩 표준스트림으로 출력연산자를 이용해 출력하세요.
        for (int i = 0 ; i < n ; ++i)
            std::cout << a[i];
    }
}

int main()
{
    using namespace yjy2372032;
    // 상수를 4로 선언하세요. 
    const int n{4}; //중괄호 : 변수 초기화
    student a[n]; // 클래스형을 상수개 갖는 배열을 선언합니다. 
    a[0] = student{"yjy", 2372032, 100 ,'A'}; // 배열의 첫번째 원소는 생성자를 이용하여 원하는 값으로 초기화.
    a[1].setName("Lee Pro"); a[1].setId(2372032); a[1].setScore(99); a[1].setGrade('A');// 배열의 두번째 원소는 set함수들을 호출하여 원하는 값을 넣어줍니다. 
    a[2].input(); // 배열의 세번째 원소는 input멤버함수를 호출하여 원하는 값을 넣어줍니다.
    std::cin >> a[3]; // 배열의 네번째 원소는 입력연산자를 이용하여 표준스트림으로 원하는 값을 입력합니다.
    printStudentArray(a,n);
    
    // print클래스Array 함수에 배열과 상수를 넣어 호출합니다.

    // 클래스형이 상수개인 std::array를 선언합니다. 
    std::array<student, n> arr; 
    // for구문을 이용하여 std::array의 각 원소에 배열의 각 원소를 각각 할당합니다. 
    // (size(), at() 멤버함수 사용)
    for (int i = 0; i < arr.size() ; ++i) //n대신에 size라는 멤버함수 사용
    {
        arr.at(i) = a[i];
    }
    for (const auto& arri : arr)
    {
        arri.print();
    }
} 


// for each 구문을 이용하여 std::array의 각 원소에서 print함수를 호출합니다. 
