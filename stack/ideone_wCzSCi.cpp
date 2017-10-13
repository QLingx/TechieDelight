#include <iostream>
#include <stack>
using namespace std;

// main function
int main()
{
	stack<string> s;

	s.push("A");	// Insert "A" in the stack
	s.push("B");	// Insert "B" in the stack
	s.push("C");	// Insert "C" in the stack
	s.push("D");	// Insert "D" in the stack

	// Returns the number of elements present in the stack
	cout << "Stack size is " << s.size() << endl;

	// Prints the top of the stack ("D")
	cout << "Top element is: " << s.top() << endl;

	s.pop();	// removing the top ("D")
	s.pop();	// removing the next top ("C")

	cout << "Stack size is " << s.size() << endl;

	// check if stack is empty
	if (s.empty())
		cout << "Stack is Empty\n";
	else
		cout << "Stack is not Empty\n";

	return 0;
}