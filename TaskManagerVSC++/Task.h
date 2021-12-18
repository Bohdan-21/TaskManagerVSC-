#pragma once
#ifndef TASK_H
#define TASK_H

#include <stack>
#include "..\TaskManagerVSC++\Special.h"
#include <string>
#include <iostream>
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

class Task
{
public:
    Task();

    ReturnCommand Add(string) noexcept;

    ReturnCommand Remove(string) noexcept;

    ReturnCommand Remove(int) noexcept;

    ReturnCommand saveStack(fstream*);

    void Display();

    void clean();

    ReturnCommand loadStack(fstream*);

protected:

private:

    stack<string>* tasks_ = nullptr;

    stack<string> *Reverse(stack<string>*);

    stack<string>* Copy(stack<string>*) noexcept;
    
};

#endif // TASK_H
