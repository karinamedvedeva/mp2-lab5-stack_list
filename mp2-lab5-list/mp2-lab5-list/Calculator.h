#pragma once

#include <string>
#include "Stack.h"
using namespace std;

class Calculator
{
	Stack <char> st_c;
	Stack <double> st_d;
	string infix;
	string postfix;
	int Priority(char elem);
public:
	void SetFormula(string str);
	string GetExpression()
	{
		return infix;
	}
	void SetExpression(string str)
	{
		infix = str;
	}
	string GetPostfix()
	{
		return postfix;
	}
	bool CheckBrackets();
	void ToPostfix(); //������� � ����������� �����
	double CalcPostfix(); //���������� ��������� � ����������� �����
};
