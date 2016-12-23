#include "ExpressionManager.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>

using namespace std;

const string OPEN = "([{";
const string CLOSE = ")]}";
const string OPERATORS = "+-*/%";

ExpressionManager::ExpressionManager()
{
	stack<int> operand_stack;
	stack<string> infix_stack;
	stack<char> operator_stack;
}
		
ExpressionManager::~ExpressionManager()
{
	
}

bool ExpressionManager::isBalanced(string expression)
{
	stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();

	while (balanced && (iter != expression.end()))
	{
		char test = *iter;
		if (is_open(test))
		{
			s.push(test);
		}

		else if (is_close(test))
		{
			if (s.empty())
			{
				balanced = false;
			}

			else
			{
				char top_character = s.top();
				s.pop();
				balanced = (balanced && (OPEN.find(top_character) == CLOSE.find(test)));
			}
		}

		++iter;
	}

	return (balanced && s.empty());
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
	while (!infix_stack.empty())
	{
		infix_stack.pop();
	}

	istringstream token(postfixExpression);

	char next;

	while (token >> next)
	{
		if (isdigit(next))
		{
			token.putback(next);
			string value;
			token >> value;

			for (int i = 0; i < value.size(); i++)
			{
				if (!isdigit(value[i]))
				{
					return "invalid";
				}
			}

			infix_stack.push(value);
		}

		if (is_operator(next))
		{
			if (infix_stack.size() >= 2)
			{
				string right_operand = infix_stack.top();
				infix_stack.pop();

				string left_operand = infix_stack.top();
				infix_stack.pop();

				string result = "";
				result += "(";
				result += " ";
				result += left_operand;
				result += " ";
				result += next;
				result += " ";
				result += right_operand;
				result += " ";
				result += ")";
				
				infix_stack.push(result);
			}

			else
			{
				return "invalid";
			}
		}

		if (!is_operator(next) && !isdigit(next))
		{
			return "invalid";
		}
	}

	if (infix_stack.size() == 1)
	{
		return infix_stack.top();
	}

	else
	{
		return "invalid";
	}
}

string ExpressionManager::infixToPostfix(string infixExpression) 
{
	bool balanced = (isBalanced(infixExpression));
	int num_operands = 0; // number of operands in the postfix string
	int num_operators = 0; //number of operators in the postfix string

	string postfix_string = "";

	istringstream tokens(infixExpression);
	char next;

	while (!operator_stack.empty())
	{
		operator_stack.pop();
	}

	if (balanced == true)
	{
		while (tokens >> next)
		{
			if (isdigit(next))
			{
				tokens.putback(next);
				string value;
				tokens >> value;

				for (int i = 0; i < value.size(); i++)
				{
					if (!isdigit(value[i]))
					{
						return "invalid";
					}
				}

				postfix_string += value;
				++num_operands;
				postfix_string += " ";
			}

			if (is_operator(next))
			{
				if (operator_stack.empty())
				{
					operator_stack.push(next);
				}

				else
				{
					if (precedence(next) > precedence(operator_stack.top()))
					{
						operator_stack.push(next);
					}

					else
					{
						while (!operator_stack.empty() && precedence(next) <= precedence(operator_stack.top()))
						{
							char temp = operator_stack.top();
							postfix_string += temp;
							postfix_string += " ";
							++num_operators;
							operator_stack.pop();
						}

						operator_stack.push(next);
					}

				}
			}

			if (is_open(next))
			{
				operator_stack.push(next);
			}

			if (is_close(next))
			{
				while (!is_open(operator_stack.top()))
				{
					char temp = operator_stack.top();
					postfix_string += temp;
					++num_operators;
					postfix_string += " ";
					operator_stack.pop();
				}

				operator_stack.pop();
			}

			if (!is_operator(next) && !isdigit(next) && !is_open(next) && !is_close(next))
			{
				return "invalid";
			}
		}

		if (operator_stack.size() > 0)
		{
			while (!operator_stack.empty())
			{
				char temp = operator_stack.top();
				postfix_string += temp;
				++num_operators;
				if (operator_stack.size() > 1)
				{
					postfix_string += " ";
				}

				operator_stack.pop();
			}

			if (postfix_string.size() < 3 || num_operators != (num_operands-1))
			{
				return "invalid";
			}

			return postfix_string;
		}

		else
		{
			return "invalid";
		}
	}

	else
	{
		return "invalid";
	}
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	while (!operand_stack.empty())
	{
		operand_stack.pop();
	}

	istringstream token(postfixExpression);

	char next;

	while (token >> next)
	{
		if (isdigit(next))
		{
			token.putback(next);
			int value;
			token >> value;
			operand_stack.push(value);
		}

		if (is_operator(next))
		{
			if (operand_stack.size() >= 2)
			{
				int right_operand = operand_stack.top();
				operand_stack.pop();

				int left_operand = operand_stack.top();
				operand_stack.pop();

				if (next == '/' && right_operand == 0)
				{
					return "invalid";
				}

				else
				{
					int result = evaluate(next, left_operand, right_operand);
					operand_stack.push(result);
				}
			}

			else
			{
				return "invalid";
			}
		}

		if (!is_operator(next) && !isdigit(next))
		{
			return "invalid";
		}
	}

	if (operand_stack.size() == 1)
	{
		stringstream answer;
		answer << operand_stack.top();

		string result;
		answer>>result;

		return result;

	}

	else
	{
		return "invalid";
	}

}

bool ExpressionManager::is_open(char ch)
{
	return OPEN.find(ch) != string::npos;
}

bool ExpressionManager::is_close(char ch)
{
	return CLOSE.find(ch) != string::npos;
}

bool ExpressionManager::is_operator(char ch)
{
	return OPERATORS.find(ch) != string::npos;
}

int ExpressionManager::evaluate(char op, int left, int right)
{
	int answer = 0;

	if (op == '+')
	{
		answer = left + right;
		return answer;
	}

	if (op == '-')
	{
		answer = left - right;
		return answer;
	}

	if (op == '*')
	{
		answer = left * right;
		return answer;
	}

	if (op == '/')
	{
		answer = left / right;
		return answer;
	}

	if (op == '%')
	{
		answer = left % right;
		return answer;
	}
}

int ExpressionManager::precedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}

	else
	{
		if (op == '*' || op == '/' || op == '%')
		{
			return 2;
		}

		else
		{
			return -1;
		}
	}
}