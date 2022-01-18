#include "Task.h"


//+
ReturnCommand Task::insert(string task) noexcept
{ 
    if (this->tasks_ == nullptr)
        return ReturnCommand::UN_ADDED;

    this->tasks_->push(task);
    return ReturnCommand::ADDED;
}
//testing
ReturnCommand Task::remove(string task) noexcept
{
    if (this->tasks_ == nullptr)
        return ReturnCommand::NOT_REMOVE;

    shared_ptr<stack<string>> copy;
    size_t size;
    string temp;

    copy = copyStack(tasks_);

    tasks_ = shared_ptr<stack<string>>(new stack<string>);

    size = copy->size();

    for (size_t i = 0; i < size;i++)
    {
        temp = copy->top();

        if (temp != task)
        {
            tasks_->push(temp);
        }
        copy->pop();
    }

    return ReturnCommand::REMOVE;
}
//testing
ReturnCommand Task::remove(int position) noexcept
{
    shared_ptr<stack<string>> result = shared_ptr<stack<string>>(new stack<string>);
    size_t size;

    size = tasks_->size();

    if (this->tasks_ == nullptr || position >= size)//what i must do in this situation. Warning c4018 int > size_t type
        return ReturnCommand::NOT_REMOVE;

    tasks_ = reverseStack(tasks_);

    for (size_t i = 0; i < size;i++)
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
        return ReturnCommand::SAVED;

    shared_ptr<stack<string>> copy;
    size_t size;

    copy = copyStack(tasks_);
    copy = reverseStack(copy);

    size = copy->size();

    try
    {
        for (size_t i = 0; i < size; i++)
        {
           *write << copy->top() << "\n";
            copy->pop();
        }
    }
    catch (...)
    {
        return ReturnCommand::UN_SAVED;
    }

    return ReturnCommand::SAVED;
}
//+
ReturnCommand Task::loadTasks(fstream* read)//maybe this? 
{
    string buff = "";

    tasks_ = shared_ptr<stack<string>>(new stack<string>);

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
    tasks_ = nullptr;
}

void Task::displayTasks()
{
    if (this->tasks_ == nullptr)
        return;

    shared_ptr<stack<string>> copy = copyStack(tasks_);
    
    displayStack(copy);//TODO:NOT SAFE displayStack(tasks_);
}

void Task::create()
{
    tasks_ = shared_ptr<stack<string>>(new stack<string>);
}
