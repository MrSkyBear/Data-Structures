#pragma once
#include "ExpressionManagerInterface.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class ExpressionManager : public ExpressionManagerInterface
{
	public:
		ExpressionManager();
		virtual ~ExpressionManager();

		bool isBalanced(string expression);
		bool is_open(char ch);
		bool is_close(char ch);
		string postfixToInfix(string postfixExpression);
		string infixToPostfix(string infixExpression);
		string postfixEvaluate(string postfixExpression);
		bool is_operator(char op);
		int evaluate (char op, int left, int right);
		int precedence (char op);

		stack<int> operand_stack;
		stack<string> infix_stack;
		stack<char> operator_stack;
};