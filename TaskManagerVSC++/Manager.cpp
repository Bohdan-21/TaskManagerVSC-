#include "Manager.h"

Manager::Manager()
{
	tasks_ = new Task();
}

string Manager::getHashCode(string key)
{
	string hash = "";
	int insideHash = 0;
	int size;

	size = key.size();

	for(int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			hash += to_string((int)key[i] % 100);
		}
		else if (i == size - 1)
		{
			hash += to_string(insideHash);
			hash += to_string((int)key[i] % 100);
		}
		else
		{
			insideHash += (int)((int)key[i] % 100);
		}
	}

	return hash;
}

Manager::~Manager()
{
	if(tasks_ != nullptr)
		delete tasks_;
}

ReturnCommand Manager::createNewUser()
{
	string userName = "", password = "";

	cout << "User name -->";
	getline(cin, userName);

	cout << "User password -->";
	getline(cin, password);

	if(userName == "" || password == "")
		return ReturnCommand::ERROR;

	userName_ = userName;
	hashCodeUserPassword_ = getHashCode(password);

	return ReturnCommand::CREATED;
}

bool Manager::verifyUser()
{
	string userName = "", password = "", hash;

	cout << "User name -->";
	getline(cin >> std::ws, userName);

	cout << "\nUser password -->";
	getline(cin >> std::ws, password);

	hash = getHashCode(password);

	if (userName_ == userName && hashCodeUserPassword_ == hash)
		return true;
	return false;
}

ReturnCommand Manager::showTask()
{
	bool verify;

	verify = verifyUser();

	if (verify)
	{
		tasks_->Display();
		return ReturnCommand::ACCEPT;
	}
	return ReturnCommand::ERROR;
}

ReturnCommand Manager::addTask()
{
	bool verify;

	verify = verifyUser();

	if (verify)
	{
		string task = "";
		ReturnCommand result;

		cout << "Your task -->";
		getline(cin, task);

		result = tasks_->Add(task);

		return result;
	}

	return ReturnCommand::ERROR;
}

ReturnCommand Manager::removeTask()
{
	bool verify;

	verify = verifyUser();

	if (verify)
	{
		string task = "";
		int position = 0;
		bool isNumber = true;
		ReturnCommand result;

		cout << "Task for remove -->";
		getline(cin, task);

		try
		{
			position = stoi(task);
		}
		catch (...)
		{
			isNumber = false;
		}

		if (isNumber)
		{
			result = tasks_->Remove(position);
		}
		else
		{
			result = tasks_->Remove(task);
		}
		return result;
	}
	return ReturnCommand::ERROR;
}

ReturnCommand Manager::saveDate()
{
	bool verification;

	verification = verifyUser();

	if (!verification)
		return ReturnCommand::ERROR;

	fstream write;
	string filename, password;
	ReturnCommand result;

	filename = userName_ + ".txt";

	write.open(filename, ios::out);

	if (!write.is_open())
		return ReturnCommand::ERROR;

	try
	{
		write << userName_ << "\n";

		write << hashCodeUserPassword_ << "\n";
	}
	catch (...)
	{
		return ReturnCommand::ERROR;
	}
	result = tasks_->saveStack(&write);

	write.close();

	return result;
}

ReturnCommand Manager::loadDate()
{
	stack<string>* listFile;
	string fileName;
	ReturnCommand result;

	listFile = getListFile();

	listFile = getLoadFile(listFile);

	displayListLoadFile(listFile);

	fileName = selectFile(listFile);

	result = load(fileName);

	delete listFile;

	return result;
}

string Manager::selectFile(stack<string>* listFile)
{
	int size, choise;
	string fileName;

	size = listFile->size();
	
	cout << "Change file for load -->";
	cin >> choise;

	for (int i = 0; i < size; i++)
	{
		fileName = listFile->top();
		listFile->pop();
		if (choise == i)
			return fileName;
	}
	return "";
}

ReturnCommand Manager::load(string fileName)
{
	if (fileName == "")
		return ReturnCommand::ERROR;
	
	fstream read;
	ReturnCommand result;
	bool verification;

	read.open(fileName, ios::in);

	if (!read.is_open())
		return ReturnCommand::ERROR;

	try
	{
		read >> userName_;
		read >> hashCodeUserPassword_;
	}
	catch (...)
	{
		return ReturnCommand::ERROR;
	}
	
	result = tasks_->loadStack(&read);

	verification = verifyUser();
	
	if (!verification)
	{
		clean();
		return ReturnCommand::ERROR;
	}

	return result;
}

void Manager::clean()
{
	tasks_->clean();

	userName_ = hashCodeUserPassword_ = "";
}
