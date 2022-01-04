#include "Manager.h"




void menu();

void showMessage(ReturnCommand);


int main()
{
   menu();
  
    return 0;
}

void menu()
{
    Manager* manager = nullptr;
    ReturnCommand result;
    int choose;
    string temp;

    manager = new Manager();

    while (true)
    {
        cout << "1 - Create user\n2 - Add task\n3 - Remove Task\n"
            "4 - Display task\n5 - Save\n6 - Read\n7 - Exit\n"
            "--> <--\b\b\b\b";
        cin >> choose;
        cin.ignore(100, '\n');

        switch (choose)
        {
        case 1:
        {
            result = manager->createNewUser();//+
            break;
        }
        case 2:
        {   
            result = manager->addTask();//+
            break;
        }
        case 3:
        {
            result = manager->removeTask();//+
            break;
        }
        case 4:
        {
            result = manager->showTask();//+
           break;
        }
        case 5:
        {
            result = manager->saveDate();//+
            break;
        }
        case 6:
        {
            result = manager->loadDate();//+
            break;
        }
        case 7:
        {
            return;
        }
        }
        showMessage(result);

        system("pause");
        system("cls");
    }

    manager->~Manager();
    manager = nullptr;
}

void showMessage(ReturnCommand command)
{
    switch (command)
    {
    case ReturnCommand::ADDED:
        cout << "Your task added" << endl;
        break;
    case ReturnCommand::REMOVE:
        cout << "Your task remove" << endl;
        break;
    case ReturnCommand::ERRORS:
        cout << "Fatal error!!!" << endl;
        break;
    case ReturnCommand::SAVED:
        cout << "Saved successful" << endl;
        break;
    case ReturnCommand::LOADED:
        cout << "Load file successful" << endl;
        break;
    case ReturnCommand::UN_LOADED:
        cout << "Load file unsuccessful" << endl;
        break;
    case ReturnCommand::ACCEPT:
        cout << "Validation pass successful" << endl;
        break;
    case ReturnCommand::CREATED:
        cout << "New user create" << endl;
        break;
    case ReturnCommand::UN_CREATED:
        cout << "New user cant create" << endl;
        break;
    case ReturnCommand::VERIFICATION:
        cout << "Access is allowed" << endl;
        break;
    case ReturnCommand::UNVERIFICATION:
        cout << "Access is denied" << endl;
        break;
    case ReturnCommand::UN_ADDED:
        cout << "Your task cant added" << endl;
        break;
    case ReturnCommand::NOT_REMOVE:
        cout << "Your task cant remove" << endl;
        break;
    case ReturnCommand::UN_SAVED:
        cout << "Your task cant save" << endl;
        break;
    }
}