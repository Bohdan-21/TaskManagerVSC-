#include "Task.h"


Task::Task()
{
    this->tasks_ = new stack<string>();
}
//+
ReturnCommand Task::addTask(string task) noexcept
{ 
    if (this->tasks_ == nullptr)
        return ReturnCommand::UN_ADDED;

    this->tasks_->push(task);
    return ReturnCommand::ADDED;
}
//testing
ReturnCommand Task::removeTask(string task) noexcept
{
    if (this->tasks_ == nullptr)
        return ReturnCommand::NOT_REMOVE;

    stack<string>* copy;
    int size;
    string temp;

    copy = copyStack(tasks_);

    delete tasks_;

    tasks_ = new stack<string>();

    size = copy->size();

    for (int i = 0; i < size;i++)
    {
        temp = copy->top();

        if (temp != task)
        {
            tasks_->push(temp);
        }
        copy->pop();
    }

    delete copy;

    return ReturnCommand::REMOVE;
}
//testing
ReturnCommand Task::removeTask(int position) noexcept
{
    stack<string>* result = new stack<string>();
    int size;

    size = tasks_->size();

    if (this->tasks_ == nullptr || position >= size)
        return ReturnCommand::NOT_REMOVE;

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
    
    delete tasks_;

    tasks_ = copyStack(result);

    delete result;

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
//+
ReturnCommand Task::loadTasks(fstream* read)
{
    string buff = "";

    if (!tasks_ != NULL)
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
        return ReturnCommand::UN_LOADED;
    }
    return ReturnCommand::LOADED;
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

    delete copy;
}
