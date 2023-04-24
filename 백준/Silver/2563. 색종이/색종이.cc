#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define 반복(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define 만약 if
#define 입력 cin
#define 출력 cout

#define 벡터 vector
#define 정수 int
#define 공허 void

#define 메인함수 main



벡터<벡터<정수>> 도화지(100, 벡터<정수>(100));
정수 넓이;
공허 도화지칠하기(정수 엑, 정수 와) {
	반복(ㅁ, 10) 반복(ㄴ, 10){
		만약(도화지[ㅁ+엑][ㄴ+와] == 0) {
			도화지[ㅁ+엑][ㄴ+와] = 1;
			넓이++;
		}
	}	
}
정수 메인함수(){

	정수 색종이수;
	입력 >> 색종이수;
	반복(ㅁ, 색종이수) {
		정수 엑스, 와이;
		입력 >> 엑스 >> 와이;
		도화지칠하기(엑스, 와이);
	}
	출력 << 넓이;
}