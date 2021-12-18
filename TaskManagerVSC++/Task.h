#pragma once
#ifndef TASK_H
#define TASK_H

#include <stack>
#include "..\TaskManagerVSC++\Special.h"
#include <string>
#include <iostream>
#include "SaveDateInFile.h"
#include <fstream>

using std::ofstream;
using std::fstream;
using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::getline;
using std::stoi;
using std::get;
using std::ios;
using std::nullptr_t;

class Task
{
public:
    Task();

    ReturnCommand Add(string) noexcept;

    ReturnCommand Remove(string) noexcept;

    ReturnCommand Remove(int) noexcept;

    ReturnCommand saveStack(fstream*);

    void Display();

    ReturnCommand loadStack(fstream*);

protected:

private:

    stack<string>* tasks_;

    stack<string> *Reverse(stack<string>*);

    stack<string>* Copy(stack<string>*) noexcept;
    
};

#endif // TASK_H
