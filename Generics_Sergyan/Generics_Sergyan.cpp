#include "Stack.h"
#include <iostream>
#include <string>

int main()
{
	Stack<int> s;
	s.push(2);
	std::cout << s.top() << std::endl;
	s.push(4);
	s.push(6);
	s.pop();
	std::cout << s.top() << std::endl;

	std::string sep = "";
	for (Stack<int>::Iterator it = s.begin(); it != s.end(); ++it)
	{
		std::cout << sep << *it;
		sep = "; ";
	}
	std::cout << std::endl;
	return 0;
}