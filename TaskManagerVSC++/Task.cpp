#include "Task.h"


Task::Task()
{
    this->tasks_ = new stack<string>();
}

ReturnCommand Task::addTask(string task) noexcept
{ 
    if (this->tasks_ == nullptr)
        return ReturnCommand::ERRORS;

    this->tasks_->push(task);
    return ReturnCommand::ADDED;
}

ReturnCommand Task::removeTask(string task) noexcept
{
    if (this->tasks_ == nullptr)
        return ReturnCommand::ERRORS;

    stack<string>* copy;
    int* arr;
    int size, realSizeArray = 0, j = 0, position;

    copy = copyStack(tasks_);
    size = tasks_->size();

    arr = new int[size] {0};

    for (int i = size - 1; i != -1; i--)
    {
        if (copy->top() == task)
        {
            arr[j] = i;
            j++;
            realSizeArray++;
        }
        copy->pop();
    }

    delete copy;

    for (int i = 0; i < realSizeArray; i++)
    {
        position = arr[i] - i;
        removeTask(position);
    }
    delete[] arr;

    return ReturnCommand::REMOVE;
}

ReturnCommand Task::removeTask(int position) noexcept
{
    if (this->tasks_ == nullptr)
        return ReturnCommand::ERRORS;

    stack<string>* result = new stack<string>();
    int size;

    size = tasks_->size();

    if(position >= size)
        return ReturnCommand::ERRORS;

    tasks_ = reverseStack(tasks_);

    for (int i = 0; i < size;i++)
    {
        if (position != i)
        {
            result->push(tasks_->top());
            tasks_->pop();
        }
        else
        {
            tasks_->pop();
        }
    }
    
    tasks_ = copyStack(result);

    return ReturnCommand::REMOVE;
}

ReturnCommand Task::saveTasks(fstream* write)
{
    if (this->tasks_ == nullptr)
        return ReturnCommand::ERRORS;

    stack<string>* copy;
    int size;

    copy = copyStack(tasks_);
    copy = reverseStack(copy);

    size = copy->size();

    try
    {
        for (int i = 0; i < size; i++)
        {
           *write << copy->top() << "\n";
            copy->pop();
        }
    }
    catch (...)
    {
        return ReturnCommand::ERRORS;
    }

    return ReturnCommand::SAVED;
}

ReturnCommand Task::loadTasks(fstream* read)
{
    if (this->tasks_ == nullptr)
        return ReturnCommand::ERRORS;

    string buff = "";

    if (!tasks_->empty())
        delete tasks_;

    tasks_ = new stack<string>();

    try
    {
        while (*read)
        {
            *read >> buff;

            if (buff != "")
            {
                tasks_->push(buff);
                buff = "";
            }
        }
    }
    catch (...)
    {
        return ReturnCommand::ERRORS;
    }
    return ReturnCommand::READED;
}

void Task::cleanTasks()//TODO: method clean is bullshit
{
    delete tasks_;
    tasks_ = nullptr;
}

void Task::displayTasks()
{
    if (this->tasks_ == nullptr)
        return;

    stack<string>* copy = copyStack(tasks_);
    
    displayStack(copy);//TODO:NOT SAFE displayStack(tasks_);
}
