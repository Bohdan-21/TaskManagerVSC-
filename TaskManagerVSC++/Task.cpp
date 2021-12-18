#include "Task.h"


Task::Task()
{
    this->tasks_ = new stack<string>();
}

ReturnCommand Task::Add(string task) noexcept
{ 
    this->tasks_->push(task);
    return ReturnCommand::ADDED;
}

ReturnCommand Task::Remove(string task) noexcept
{
    stack<string>* copy;
    int* arr;
    int size, realSizeArray = 0, j = 0, position;

    copy = Copy(tasks_);
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
        Remove(position);
    }
    delete[] arr;

    return ReturnCommand::REMOVE;
}

ReturnCommand Task::Remove(int position) noexcept
{
    stack<string>* result = new stack<string>();
    int size;

    size = tasks_->size();

    if(position >= size)
        return ReturnCommand::ERROR;

    tasks_ = Reverse(tasks_);

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
    
    tasks_ = Copy(result);

    return ReturnCommand::REMOVE;
}

stack<string> *Task::Reverse(stack<string>* stackForReverse)
{
    stack<string> *result = new stack<string>();
    stack<string> *copy;

    copy = Copy(stackForReverse);

    int size = copy->size();

    for (int i = 0; i < size; i++)
    {
        result->push(copy->top());
        copy->pop();
    }

    delete copy;

    return result;
}

void Task::Display()
{
    stack<string>* taskStack;
    int size;

    taskStack = Reverse(tasks_);
    size = taskStack->size();    

    for (int i = 0; i < size; i++)
    {
        cout << i << " - " << taskStack->top() << endl;
        taskStack->pop();
    }
}

stack<string>* Task::Copy(stack<string>* copyStack) noexcept
{
    stack<string> *result = new stack<string>;
    int size;
    string* array;

    size = copyStack->size();

    array = new string[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = copyStack->top();
        copyStack->pop();
    }
    
    for (int i = size - 1; i != -1; i--)
    {
        copyStack->push(array[i]);
        result->push(array[i]);
    }

    delete[] array;

    return result;
}

ReturnCommand Task::saveStack(fstream* write)
{
    stack<string>* copy;
    int size;

    copy = Copy(tasks_);
    copy = Reverse(copy);

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
        return ReturnCommand::ERROR;
    }

    return ReturnCommand::SAVED;
}

ReturnCommand Task::loadStack(fstream* read)
{
    string buff;
    tasks_ = new stack<string>();

    try
    {
        while (*read)
        {
            *read >> buff;
            tasks_->push(buff);
        }
    }
    catch (...)
    {
        return ReturnCommand::ERROR;
    }
    return ReturnCommand::READED;
}