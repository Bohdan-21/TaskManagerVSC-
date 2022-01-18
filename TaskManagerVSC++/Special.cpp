#include "Special.h"

shared_ptr<stack<string>> copyStack(shared_ptr<stack<string>> copyStack) noexcept//TODO:rename
{
	size_t sizeAllTasks;

	sizeAllTasks = copyStack->size();

	unique_ptr<string[]> arr(new string[sizeAllTasks]);
	shared_ptr<stack<string>> result = shared_ptr<stack<string>>(new stack<string>);

	for (size_t i = 0; i < sizeAllTasks; i++)
	{
		arr[i] = copyStack->top();
		copyStack->pop();
	}
	
	for (size_t i = sizeAllTasks - 1; i != -1; i--)
	{
		copyStack->push(arr[i]);
		result->push(arr[i]);
	}

	return result;
}

shared_ptr<stack<string>> reverseStack(shared_ptr<stack<string>> stackForReverse)noexcept//TODO:dont use this
{
	shared_ptr<stack<string>> result = shared_ptr<stack<string>>(new stack<string>);
	size_t sizeAllTasks;

	sizeAllTasks = stackForReverse->size();

	for (size_t i = 0; i < sizeAllTasks; i++)
	{
		result->push(stackForReverse->top());
		stackForReverse->pop();
	}
	return result;
}

void displayStack(shared_ptr<stack<string>> stackForDisplay)noexcept//TODO:rename
{
	shared_ptr<stack<string>> copy;
	size_t sizeAllTasks;

	copy = copyStack(stackForDisplay);//copy stack
	copy = reverseStack(copy);//and reverse him to display stack from first element

	sizeAllTasks = copy->size();

	for (size_t i = 0; i < sizeAllTasks; i++)
	{
		cout << i << " - " << copy->top() << endl;
		copy->pop();
	}
}
