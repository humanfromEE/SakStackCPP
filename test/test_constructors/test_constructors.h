#pragma once

#include <iostream>
#include <stack>

#include "..\..\Stack\Stack.h"

void defaultConstructor() {
    sak::Stack<int> obj;
    std::cout 
        << "Dafault constructor:" << "\n"
        << "\t" << "obj(): " << obj << std::endl;
}

void copyConstructor() {
    sak::Stack<int> obj;
    for (int i = 0; i < 10; i++) {
        obj.push(i);
    }
    sak::Stack<int> objCopy(obj);
    std::cout 
        << "Copy constructor:" << "\n"
        << "\t" << "obj(push ...): " << obj << "\n"
        << "\t" << "objCopy(obj): " << objCopy << std::endl;
}

void copyStdStackConstructor() {
    std::stack<int> obj_stack;
    for (int i = 0; i < 10; i++) {
        obj_stack.push(i);
    }
    sak::Stack<int> objCopy(obj_stack);
    std::cout << "Copy constructor for std::stack:" << std::endl;
        sak::operator<<(std::cout << "\t" << "obj_stack(push ...): ", obj_stack) << "\n"
        << "\t" << "objCopy(obj_stack): " << objCopy << std::endl;
}