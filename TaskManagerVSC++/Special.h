#pragma once

#ifndef SPECIAL_H
#define SPECIAL_H
#include <stack>
#include <string>
#include <iostream>
#include <string.h>

using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::strstr;

enum class ReturnCommand : short {
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

stack<string>* copyStack(stack<string>*)noexcept;

stack<string>* reverseStack(stack<string>*)noexcept;

void displayStack(stack<string>* stackForDisplay)noexcept;

#endif //SPECIAL_H