#include "Manager.h"

Manager::Manager()
{
	tasks_ = new Task();
}
//+
string Manager::getHashCode(string userDataForHashing)//TODO:rename variable
{
	string hashedData = "";
	int innerHash = 0;
	size_t sizeUserData;

	sizeUserData = userDataForHashing.size();

	for(size_t i = 0; i < sizeUserData; i++)
	{
		if (i == 0)
		{
			hashedData += to_string((int)userDataForHashing[i] % 100);
		}
		else if (i == sizeUserData - 1)
		{
			hashedData += to_string(innerHash);
			hashedData += to_string((int)userDataForHashing[i] % 100);
		}
		else
		{
			innerHash += (int)((int)userDataForHashing[i] % 100);
		}
	}

	return hashedData;
}

Manager::~Manager()
{
	if (tasks_ != nullptr)
	{
		cleanTasks();
		delete tasks_;
	}
}
//+
ReturnCommand Manager::createNewUser()
{
	string userName = "", password = "";

	cout << "User name -->";
	getline(cin, userName);

	cout << "User password -->";
	getline(cin, password);

	if(userName == "" || password == "")
		return ReturnCommand::UN_CREATED;

	userName_ = userName;
	hashCodeUserPassword_ = getHashCode(password);

	tasks_->create();

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
		tasks_->displayTasks();
		return ReturnCommand::ACCEPT;
	}
	return ReturnCommand::UNVERIFICATION;
}
//+
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

		result = tasks_->insert(task);

		return result;
	}

	return ReturnCommand::UNVERIFICATION;
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
			position = stoi(task);//string to int
		}
		catch (...)
		{
			isNumber = false;
		}

		if (isNumber)
		{
			result = tasks_->remove(position);
		}
		else
		{
			result = tasks_->remove(task);
		}
		return result;
	}
	return ReturnCommand::UNVERIFICATION;
}

ReturnCommand Manager::saveDate()
{
	bool verification;

	verification = verifyUser();

	if (!verification)
		return ReturnCommand::UNVERIFICATION;

	fstream write;
	string filename, password;
	ReturnCommand result;

	filename = userName_ + ".txt";

	write.open(filename, ios::out);

	if (!write.is_open())
		return ReturnCommand::UN_SAVED;

	try
	{
		write << userName_ << "\n";

		write << hashCodeUserPassword_ << "\n";
	}
	catch (...)
	{
		return ReturnCommand::UN_SAVED;
	}
	result = tasks_->saveTasks(&write);

	write.close();

	return result;
}
//+
ReturnCommand Manager::loadDate()
{
	shared_ptr<stack<string>> listFile;
	string fileName;
	ReturnCommand result;

	listFile = getListFile();

	displayStack(listFile);

	fileName = selectFile(listFile);

	result = load(fileName);

	return result;
}
//+
string Manager::selectFile(shared_ptr<stack<string>> listFile)
{
	int choise;
	string fileName;
	size_t size;

	listFile = reverseStack(listFile);//критическая точка удаление списка файлов старого образца и подмена на новый

	size = listFile->size();
	
	cout << "Change file for load -->";
	cin >> choise;

	for (size_t i = 0; i < size; i++)
	{
		fileName = listFile->top();
		listFile->pop();
		if (choise == i)
			return fileName;
	}
	return "";
}
//+
ReturnCommand Manager::load(string fileName)//TODO:SCARY
{
	fstream read;
	ReturnCommand result;
	bool verification;

	read.open(fileName, ios::in);

	if (!read.is_open())
		return ReturnCommand::UN_LOADED;

	try
	{
		read >> userName_;
		read >> hashCodeUserPassword_;
	}
	catch (...)
	{
		return ReturnCommand::UN_LOADED;
	}
	
	result = tasks_->loadTasks(&read);

	verification = verifyUser();
	
	if (!verification)
	{
		cleanTasks();
		return ReturnCommand::UNVERIFICATION;
	}

	return result;
}

void Manager::cleanTasks()
{
	tasks_->cleanTasks();

	userName_ = hashCodeUserPassword_ = "";
}
//+
shared_ptr<stack<string>> Manager::getListFile()
{
	DIR* direc;
	dirent* dp;
	shared_ptr<stack<string>> listLoadFile = shared_ptr<stack<string>>(new stack<string>);
	string fileName;
	char* pos;

	direc = opendir(".");

	while ((dp = readdir(direc)) != NULL)
	{
		fileName = dp->d_name;
		pos = strstr(&fileName[0], ".txt");//fynction find only txt file

		if (pos != NULL)
			listLoadFile->push(fileName);
	}
	delete direc;
	delete dp;

	return listLoadFile;
}
