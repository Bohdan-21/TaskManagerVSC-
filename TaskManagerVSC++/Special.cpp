#include "Special.h"

shared_ptr<stack<string>> copyStack(shared_ptr<stack<string>> copyStack) noexcept
{
	return copy(copyStack);
}

shared_ptr<stack<string>> copy(shared_ptr<stack<string>> objectForCopy)
{
	size_t sizeCopyObject = getSizeObject(objectForCopy);
	shared_ptr<string[]> objectForCopyInArray = operationCopy(objectForCopy, sizeCopyObject);

	return operationPaste(objectForCopyInArray, objectForCopy, sizeCopyObject);
}

shared_ptr<string[]> operationCopy(shared_ptr<stack<string>> objectForCopy, size_t sizeCopyObject)
{
	shared_ptr<string[]> arr(new string[sizeCopyObject]);

	for (size_t i = 0; i < sizeCopyObject; i++)
	{
		arr[i] = objectForCopy->top();
		objectForCopy->pop();
	}
	return arr;
}

shared_ptr<stack<string>> operationPaste(shared_ptr<string[]> objectForPaste, shared_ptr<stack<string>> onjectForCopy, size_t sizeCopyObject)
{
	shared_ptr<stack<string>> result(new stack<string>);

	for (size_t i = sizeCopyObject - 1; i != -1; i--)
	{
		onjectForCopy->push(objectForPaste[i]);
		result->push(objectForPaste[i]);
	}
	return result;
}

size_t getSizeObject(shared_ptr<stack<string>> objectToGetTheSize)
{
	return objectToGetTheSize->size();
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
