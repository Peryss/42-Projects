#include "RPN.hpp"

static bool op(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int stringToStack(const std::string &input) {
	std::stack<int> result;
	std::istringstream iss(input);
	std::string tok;
	while (iss >> tok) { // splits on any whitespace
	    if (tok.size() != 1) {
	        throw std::runtime_error("Invalid token: " + tok);
	    }
	    char c = tok[0];
	    if (!isspace(static_cast<unsigned char>(c))) {
			if (c >= '0' && c <= '9')
	        	result.push(static_cast<int>(c) - 48);
			else  if (op(c)) {
				if (result.size() < 2) {
				   throw std::runtime_error("Not enough elements in the stack.");
				}
				int b = static_cast<int>(result.top());
				result.pop();
				int a = static_cast<int>(result.top());
				result.pop();
				switch (c){
					case '+':
						result.push(a + b);
						break ;
					case '-':
						result.push(a - b);
						break ;
					case '*':
						result.push(a * b);
						break;
					case '/':
						if (b == 0)
							throw std::runtime_error("Division by zero.");
						result.push(a / b);
						break;
				}

			}
	    }
	}
	if (result.size() == 0) {
	   throw std::runtime_error("No elements in the stack.");
	}
	if (result.size() > 1) {
	   throw std::runtime_error("Too many elements in stack.");
	}
	return result.top();
}