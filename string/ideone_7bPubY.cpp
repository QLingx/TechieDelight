#include <bits/stdc++.h>
using namespace std;

// Function to check if given expression is balanced or not
bool balParenthesis(string exp)
{
    // take a empty stack of characters
    stack<char> stack;

    // traverse the input expression
    for (int i = 0; i < exp.length(); i++)
    {
        // if current char in the expression is a opening brace,
        // push it to the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            stack.push(exp[i]);

        // if current char in the expression is a closing brace
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // return false if mismatch is found (i.e. if stack is empty,
            // the number of opening braces is less than number of closing
            // brace, so expression cannot be balanced)
            if(stack.empty())
                return false;

            // pop character from the stack
            char top = stack.top();
            stack.pop();

            // if the popped character if not an opening brace or does not pair
            // with current character of the expression
            if ((top == '(' && exp[i] != ')') || (top == '{' && exp[i] != '}') 
                || (top == '[' && exp[i] != ']'))
            return false;
        }
    }

    // expression is balanced only if stack is empty at this point
    return stack.empty();
}

// main function
int main()
{
    string exp = "{()}[{}]";

    if (balParenthesis(exp))
        cout << "The expression is balanced";
    else
        cout << "The expression is not balanced";

    return 0;
}
