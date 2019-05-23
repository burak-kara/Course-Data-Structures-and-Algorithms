#include "Calculator.h"

Calculator::Calculator(string infixExpression) {

	this->infixExpression = infixExpression;
	this->stack = new Stack();
	this->postfixExpression = convertToPostfix(this->infixExpression) + ";";

}

Calculator::~Calculator() {

	delete stack;

}

string Calculator::getPostfix() {

	return postfixExpression;
}

int Calculator::calculate() {

	int index = 0;
	vector<string> subStrings;
	istringstream ss(postfixExpression);
	string s;

	stack->push(new StackItem("0"));

	while (getline(ss, s, ' ')) {

		subStrings.push_back(s);
	}

	string str = subStrings.at(index);

	while (str.compare(";") != 0) {

		if (StackItem(str).isOperator) {

			int lastNumber  = stack->top()->n;
			stack->pop();
			int firstNumber = stack->top()->n;
			stack->pop();
			int result;

			if (str.compare("-") == 0)
				result = firstNumber - lastNumber;
			else if (str.compare("+") == 0)
				result = firstNumber + lastNumber;
			else if (str.compare("/") == 0)
				result = firstNumber / lastNumber;
			else if (str.compare("*") == 0)
				result = firstNumber * lastNumber;

			stack->push(new StackItem(to_string(result)));

		}
		else {

			stack->push(new StackItem(str));

		}

		str = subStrings.at(index);
		index++;
	}

	return (stack->top()->n);

}

string Calculator::convertToPostfix(string infixExpression) {

	stack->push(new StackItem("("));
	infixExpression += " )";

	int index      = -1;
	string postfix = "";
	vector<string> subStrings;
	istringstream ss(infixExpression);
	string s;

	while (getline(ss, s, ' ')) {

		subStrings.push_back(s);
	}

	while (!stack->isEmpty()) {

		index++;
		string str = subStrings.at(index);

		if (str.compare(";") == 0) {

			continue;
		}
		else {

			if (StackItem(str).isOperator) {													// if operator encountered (general)

				if (StackItem(str).toString().compare("(") == 0){										// if left paranthesis encountered
				
					stack->push(new StackItem(str));
				}
				else if (StackItem(str).toString().compare(")") == 0) {									// check here if right paranthesis encountered

					while ((stack->top())->toString().compare("(") != 0) {

						postfix += (stack->top())->toString() + " ";
						stack->pop();
					}

					stack->pop();															// at the end, to remove ("(") the left paranthesis
				}
				else {																		// if operator encountered
					
					if (StackItem(str).op > stack->top()->op) {

						stack->push(new StackItem(str));
					}
					else if (StackItem(str).op == stack->top()->op) {

						postfix += (stack->top())->toString() + " ";
					}
					else {																	// if stack top has higher precedence

						if ((stack->top())->toString().compare("(") == 0 || (stack->top())->toString().compare(")") == 0) {

							stack->push(new StackItem(str));
						}
						else {

							postfix += (stack->top())->toString() + " ";
							stack->pop();
							stack->push(new StackItem(str));
						}
					}
				}
			}
			else {																			// if operand encountered

				postfix += str + " ";
			}
		}
	}

	return postfix;
}

