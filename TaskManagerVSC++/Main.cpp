#include "Manager.h"

void menu();


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
            result = manager->createNewUser();

            if (result == ReturnCommand::CREATED)
                cout << "User create" << endl;
            else
                cout << "User cant create" << endl;

            break;
        }
        case 2:
        {   
            result = manager->addTask();
            
            if (result == ReturnCommand::ADDED)
                cout << "Your task added" << endl;
            else 
                cout << "Your task cant added" << endl;
            break;
        }
        case 3:
        {
            result = manager->removeTask();
            
            if (result == ReturnCommand::REMOVE)
                cout << "Your task remove" << endl;
            else
                cout << "Your task cant remove" << endl;
            break;
        }
        case 4:
        {
            result = manager->showTask();

            if (result == ReturnCommand::ACCEPT)
                cout << "Your do verifycatioun" << endl;
            else
                cout << "Your dont verifycation" << endl;
           break;
        }
        case 5:
        {
            result = manager->saveDate();
            
            if (result == ReturnCommand::SAVED)
                cout << "Your file saved" << endl;
            else
                cout << "Your file not saved" << endl;

            break;
        }
        case 6:
        {
            result = manager->loadDate();

            if (result == ReturnCommand::READED)
                cout << "Your file is read" << endl;
            else
                cout << "Your file cant read" << endl;


            break;

        }
        case 7:
        {
            return ;
        }
        }
        system("pause");
        system("cls");
    }


    manager->~Manager();
    manager = nullptr;
}
