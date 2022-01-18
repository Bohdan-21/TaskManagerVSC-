#pragma once

#ifndef SPECIAL_H
#define SPECIAL_H
#include <stack>
#include <string>
#include <iostream>
#include <string.h>
#include <memory>

using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::strstr;
using std::unique_ptr;
using std::shared_ptr;

enum class ReturnCommand : short {//TODO:remove this dependencies
    ADDED = 0,
    REMOVE,
    ERRORS,//TODO:rename ERROR to ERRORS because library dirent use ERROR. fix this later
    SAVED,
    LOADED,
    ACCEPT,
    CREATED,
    UN_SAVED,
    UN_ADDED,
    UN_LOADED,
    NOT_REMOVE,
    UN_CREATED,
    VERIFICATION,
    UNVERIFICATION,
};

shared_ptr<stack<string>> copyStack(shared_ptr<stack<string>>)noexcept;

shared_ptr<stack<string>> reverseStack(shared_ptr<stack<string>>)noexcept;

void displayStack(shared_ptr<stack<string>> stackForDisplay)noexcept;

#endif //SPECIAL_H