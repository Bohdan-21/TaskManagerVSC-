#include "Special.h"

stack<string>* copyStack(stack<string>* copyStack) noexcept
{
	stack<string>* result = new stack<string>();
	int size;
	string* array;

	size = copyStack->size();

	array = new string[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = copyStack->top();
		copyStack->pop();
	}

	for (int i = size - 1; i != -1; i--)
	{
		copyStack->push(array[i]);
		result->push(array[i]);
	}

	delete[] array;

	return result;
}

stack<string>* reverseStack(stack<string>* stackForReverse)noexcept
{
	stack<string>* result = new stack<string>();
	int size;

	size = stackForReverse->size();

	for (int i = 0; i < size; i++)
	{
		result->push(stackForReverse->top());
		stackForReverse->pop();
	}

	return result;
}

void displayStack(stack<string>* stackForDisplay)noexcept
{
	stack<string>* copy;
	int size;

	copy = copyStack(stackForDisplay);//copy stack
	copy = reverseStack(copy);//and reverse him to display stack from first element

	size = copy->size();

	for (int i = 0; i < size; i++)
	{
		cout << i << " - " << copy->top() << endl;
		copy->pop();
	}

	delete copy;
}