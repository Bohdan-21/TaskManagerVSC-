#pragma once

#ifndef MANAGER_H
#define MANAGER_H

#include "Task.h"
#include "..\dirent-master\include\dirent.h"

class Manager
{
public:
	Manager();

	ReturnCommand addTask();

	ReturnCommand removeTask();

	ReturnCommand saveDate();

	ReturnCommand loadDate();

	ReturnCommand showTask();

	ReturnCommand createNewUser();

	void cleanTasks();

	~Manager();

protected:

private:
	
	Task *tasks_ = nullptr;
	string userName_;
	string hashCodeUserPassword_;

	string getHashCode(string);

	bool verifyUser();

	string selectFile(stack<string>*);

	ReturnCommand load(string);

	stack<string>* getListFile();
};

#endif