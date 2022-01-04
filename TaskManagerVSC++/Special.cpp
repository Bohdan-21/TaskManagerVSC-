#include "Special.h"

shared_ptr<stack<string>> copyStack(shared_ptr<stack<string>> copyStack) noexcept
{
	int size;

	size = copyStack->size();

	unique_ptr<string[]> arr(new string[size]);
	shared_ptr<stack<string>> result = shared_ptr<stack<string>>(new stack<string>);

	for (int i = 0; i < size; i++)
	{
		arr[i] = copyStack->top();
		copyStack->pop();
	}
	
	for (int i = size - 1; i != -1; i--)
	{
		copyStack->push(arr[i]);
		result->push(arr[i]);
	}

	return result;
}

shared_ptr<stack<string>> reverseStack(shared_ptr<stack<string>> stackForReverse)noexcept
{
	shared_ptr<stack<string>> result = shared_ptr<stack<string>>(new stack<string>);
	int size;

	size = stackForReverse->size();

	for (int i = 0; i < size; i++)
	{
		result->push(stackForReverse->top());
		stackForReverse->pop();
	}
	return result;
}

void displayStack(shared_ptr<stack<string>> stackForDisplay)noexcept
{
	shared_ptr<stack<string>> copy;
	int size;

	copy = copyStack(stackForDisplay);//copy stack
	copy = reverseStack(copy);//and reverse him to display stack from first element

	size = copy->size();

	for (int i = 0; i < size; i++)
	{
		cout << i << " - " << copy->top() << endl;
		copy->pop();
	}
}
