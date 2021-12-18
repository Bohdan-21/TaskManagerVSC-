#pragma once

#include "..\dirent-master\include\dirent.h"
#include <stack>
#include <string>
#include <iostream>
#include <string.h>

using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::strstr;

stack<string>* Copy(stack<string>*)noexcept;


stack<string>* getListFile()
{
	DIR* direc;
	dirent* dp;
	stack<string>* listFile = new stack<string>();

	direc = opendir(".");

	while ((dp = readdir(direc)) != NULL)
	{
		listFile->push(dp->d_name);
	}
	

	return listFile;
}

stack<string>* getLoadFile(stack<string>* listFile)
{
	stack<string>* listLoadFile = new stack<string>();
	string nameFile;
	int size;
	char* pos;

	size = listFile->size();

	for (int i = 0; i < size; i++)
	{
		nameFile = listFile->top();
		listFile->pop();
		pos = strstr(&nameFile[0], ".txt");//поиск подстроки strstr(char char)

		if (pos != NULL)
			listLoadFile->push(nameFile);
	}

	return listLoadFile;
}

void displayListLoadFile(stack<string>* listFile)
{
	stack<string>* copy;
	int size;

	copy = Copy(listFile);
	size = copy->size();

	for (int i = 0; i < size; i++)
	{
		cout << i << " - " << copy->top() << endl;
		copy->pop();
	}
}

stack<string>* Copy(stack<string>* copyStack) noexcept
{
	stack<string>* result = new stack<string>;
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


