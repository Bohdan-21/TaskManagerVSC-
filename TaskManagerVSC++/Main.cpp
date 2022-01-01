#include "Manager.h"



void menu();

void showMessage(ReturnCommand);

using namespace std;

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

int main()
{




    //SQLHANDLE sqlconnhandle;
    //SQLHANDLE sqlStmthandle;
    //SQLHANDLE sqlEnvhandle;
    //SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

    //sqlconnhandle = NULL;
    //sqlStmthandle = NULL;

    //if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvhandle))
    //    cout << "first" << endl;
    //if(SQL_SUCCESS != SQLSetEnvAttr(sqlEnvhandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
    //    cout << "second" << endl;
    //if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvhandle, &sqlconnhandle))
    //    cout << "third" << endl;


    //SQLRETURN sql_connect = SQLDriverConnect(sqlconnhandle, NULL,
    //    //(SQLWCHAR*)L"DRIVER={SQL Server}; SERVER=localhost, 50100; DATABASE=master;UID=username;PWD=password;"//if need  use  username and password
    //    (SQLWCHAR*)L"DRIVER={SQL Server}; SERVER=localhost, 50100; DATABASE=master;Trusted=true;",
    //    SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT);

    //switch (sql_connect)
    //{
    //case  SQL_SUCCESS:
    //    cout << "1" << endl;
    //    break;
    //case  SQL_SUCCESS_WITH_INFO:
    //    cout << "2" << endl;
    //    break;
    //case  SQL_INVALID_HANDLE:
    //    cout << "3" << endl;
    //    break;
    //case  SQL_ERROR:
    //    cout << "4" << endl;
    //    break;
    //}


    //if (SQL_SUCCESS == SQLExecDirect(sqlStmthandle, (SQLWCHAR*)L"SELECT @@VERSION", SQL_NTS)) 
    //{
    //    SQLCHAR sqlVersion[SQL_RESULT_LEN];
    //    SQLLEN prtSqlVersion;

    //    while (SQLFetch(sqlStmthandle) == SQL_SUCCESS)
    //    {
    //        SQLGetData(sqlStmthandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &prtSqlVersion);

    //        cout << "\n\nQuery result" << endl;
    //        cout << sqlVersion << endl;
    //    }
    //}



    //menu();

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