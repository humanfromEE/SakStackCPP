#pragma once

#include <iostream>
#include <stack>
#include <string>

#include "..\..\Stack\Stack.h"

std::string getStringFromBool(bool expression) {
    return (expression) ? "true" : "false";
}

std::string getStringLine() {
    std::string stringLine = "";
    for (int i = 0; i <= 100; i++) {
        stringLine += "=";
    }
    return stringLine;
}

sak::Stack<int> generateRandomSakStack(int length) {
    sak::Stack<int> randomSakStack;
    for (int i = 0; i < length; i++) {
        randomSakStack.push(i);
    }
    return randomSakStack;
}

void testFunctionsForOnlyOneObject(sak::Stack<int>& obj) {
    std::cout << "Obj for test: " << obj << std::endl;
    std::cout << "\t" << "obj.size(): " << obj.size() << std::endl;
    std::cout << "\t" << "obj.empty(): " << getStringFromBool(obj.empty()) << std::endl;
    std::cout << "\t" << "obj.this_sizeof(): " << obj.this_sizeof() << std::endl;
    obj.reverse();
    std::cout << "\t" << "obj.reverse(): " << obj << std::endl;
    if (!obj.empty()) {
        std::cout << "\t" << "obj.top(): " << "not test object null!" << std::endl;
        obj.top() = 777777;
        std::cout << "\t" << "obj.top() = 777777: " << obj.top() << std::endl;
    } else {
        std::cout << "\t" << "NOT TEST top() because object not has elements" << std::endl;
    }

    std::cout << "\t" << "NOT TEST clear(), copy(...), getArrayValues(...), this_convert(...), this_reconvert(), Stack<int>::convert(...), Stack<int>::reconvert(...)" << std::endl;
    std::cout << "\t\t" << "-> because this methods uses in object methods and test in another test-files" << std::endl; 
}

void getSakStacksAnyLength() {
    for (int i = 0; i <= 10; i++) {
        sak::Stack<int> testSakStack(generateRandomSakStack(i));
        std::cout << getStringLine() << std::endl;
        testFunctionsForOnlyOneObject(testSakStack);
        std::cout << getStringLine() << std::endl;
    }
}