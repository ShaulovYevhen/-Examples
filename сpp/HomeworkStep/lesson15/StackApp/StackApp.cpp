#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	string s="()(){{}}";
	Stack<char> q;
	for (auto c = s.begin(); c != s.end(); c++)
	{
		if (*c == ')' && q.peek() == '(' || *c == ']' && q.peek() == '[' ||	*c == '}' && q.peek() == '{'|| *c == '>' && q.peek() == '<')
		{
			q.pop();
		}
		else if (*c == ')' || *c == ']' || *c == '}' || *c=='>')
		{
			cout << "NO";
			return 0;
		}
		else
			q.push(*c);
	}
	q.is_empty() ? cout << "YES" : cout << "NO";
}

