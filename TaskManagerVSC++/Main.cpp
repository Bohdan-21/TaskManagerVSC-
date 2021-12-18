#include "Manager.h"
#include <exception>
#include <boost/filesystem.hpp>



using namespace std;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;

void menu();



int main()
{
    //test();
    menu();
    /*Task task;

    task.Add("3");
    task.Add("1");
    task.Add("2");
    task.Add("3");
    task.Add("4");
    task.Add("5");
    task.Add("3");

    task.Display();

    task.Remove("3");

    cout << endl << endl;

    task.Display();

    cout << "END" << endl;*/


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
            manager-
            break;
        }
        case 2:
        {   
            result = manager->addTask();
            
            if (result == ReturnCommand::ADDED)
                cout << "Your task added";
            else 
                cout << "Your task cant added";
            break;
        }
        case 3:
        {
            result = manager->removeTask();
            
            if (result == ReturnCommand::REMOVE)
                cout << "Your task remove";
            else
                cout << "Your task cant remove";
            break;
        }
        case 4:
        {
            result = manager->showTask();

            if (result == ReturnCommand::ACCEPT)
                cout << "Your do verifycatioun";
            else
                cout << "Your dont verifycation";
           break;
        }
        case 5:
        {
            result = manager->saveDate();
            
            if (result == ReturnCommand::SAVED)
                cout << "Your file saved";
            else
                cout << "Your file not saved";

            break;
        }
        case 6:
        {
            result = manager->loadDate();

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