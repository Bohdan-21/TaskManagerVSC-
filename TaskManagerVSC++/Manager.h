#pragma once

#ifndef MANAGER_H
#define MANAGER_H

#include "Task.h"

stack<string>* getListFile();
stack<string>* getLoadFile(stack<string>*);
void displayListLoadFile(stack<string>*);
stack<string>* Copy(stack<string>*)noexcept;

class Manager /*: public SaveDateInFile*/
{
public:
	Manager();

	ReturnCommand addTask();

	ReturnCommand removeTask();

	ReturnCommand saveDate();

	ReturnCommand loadDate();

	ReturnCommand showTask();

	~Manager();

protected:
	/*ReturnCommand save() override;*/
private:
	
	Task *tasks_ = nullptr;
	string userName_;
	string hashCodeUserPassword_;

	string getHashCode(string);

	bool createNewUser();

	bool verifyUser();

	string crypt();

	string unCrypt(string);

	string selectFile(stack<string>*);

	ReturnCommand load(string);
};

#endif // MANAGER_H