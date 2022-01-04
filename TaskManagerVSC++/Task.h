#pragma once
#ifndef TASK_H
#define TASK_H

#include "..\TaskManagerVSC++\Special.h"
#include "Special.h"
#include <fstream>

using std::fstream;
using std::cin;
using std::to_string;
using std::getline;
using std::stoi;
using std::get;
using std::ios;

class Task
{
public:

    ReturnCommand addTask(string) noexcept;

    ReturnCommand removeTask(string) noexcept;

    ReturnCommand removeTask(int) noexcept;

    ReturnCommand saveTasks(fstream*);

    void displayTasks();

    void cleanTasks();

    void create();

    ReturnCommand loadTasks(fstream*);

protected:

private:

    shared_ptr<stack<string>> tasks_ = shared_ptr<stack<string>>(new stack<string>);
};

#endif // TASK_H