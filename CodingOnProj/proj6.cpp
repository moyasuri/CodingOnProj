#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;



//1. 클래스 상속, 정적 멤버, 업 캐스팅, 가상 함수를 사용하여 다음과 같이 간단한 사칙연산을 수행하는 계산기 만들기

class Calc
{

public:
	virtual void Add() = 0;

	virtual void Sub() = 0;

	virtual void Mul() = 0;

	virtual void Div() = 0;



public:
	string _operator;
	string _cmd;
	int _divider;
	static double _result;

};
class C_Add : public Calc
{
public:
	double Add() {
		return

	}



};
class C_Sub : public Calc
{

};
class C_Mul : public Calc
{

};
class C_Div : public Calc
{

};
int main()
{

}