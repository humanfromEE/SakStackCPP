#pragma once

#include <iostream>
#include <string>

#include "..\..\Stack\Stack.h"

void generateValuesStack(sak::Stack<int>& objRef, LLI objLen) {
    for (int i = 0; i < objLen; i++) {
        objRef.push(rand() % 10);
    }
}

void testOverloadOstream() {
    sak::Stack<int> obj1, obj2;
    generateValuesStack(obj2, 10);
    std::stack<int> obj_stack1, obj_stack2;
    for (int i = 0; i <= 5; i++) {
        obj_stack2.push(i);
    }
    std::cout
        << "Test overload ostream for sak::Stack<int>:" << "\n"
        << "\t" << "obj1(): " << obj1 << "\n"
        << "\t" << "obj2(push ...): " << obj1 << std::endl;
    std::cout << "Test overload ostream for std::stack<int>:" << std::endl;
    sak::operator<<(std::cout << "\t" << "obj_stack1(): ", obj_stack1) << std::endl;
    sak::operator<<(std::cout << "\t" << "obj_stack2(push ...): ", obj_stack2) << "\n" << std::endl;
}

void testBoolOpeation(std::string nameObjLeft, std::string nameObjRight, std::string boolSign, bool expression) {
    std::cout << "\t\t" << nameObjLeft << " " << boolSign << " " << nameObjRight << ": " << ( (expression) ? "true" : "false" ) << std::endl;
}

void testBoolOperations(std::string nameObjLeft, std::string nameObjRight, const sak::Stack<int>& objLeft, const sak::Stack<int>& objRight) {
    testBoolOpeation(nameObjLeft, nameObjRight, "==", (objLeft == objRight));
    testBoolOpeation(nameObjLeft, nameObjRight, "!=", (objLeft != objRight));
    testBoolOpeation(nameObjLeft, nameObjRight, "<=", (objLeft <= objRight));
    testBoolOpeation(nameObjLeft, nameObjRight, ">=", (objLeft >= objRight));
    testBoolOpeation(nameObjLeft, nameObjRight, "<", (objLeft < objRight));
    testBoolOpeation(nameObjLeft, nameObjRight, ">", (objLeft > objRight));
}

void testObjectsInBoolOpeations(
    std::string nameObj1, std::string nameObj2, std::string nameObj3,
    std::string nameObj4, std::string nameObj5, std::string nameObj6,
    std::string nameObj7, std::string nameObjTest,
    const sak::Stack<int>& obj1, const sak::Stack<int>& obj2, const sak::Stack<int>& obj3,
    const sak::Stack<int>& obj4, const sak::Stack<int>& obj5, const sak::Stack<int>& obj6,
    const sak::Stack<int>& obj7, const sak::Stack<int>& objTest 
) {
    std::cout << "\t" << "=================================================" << std::endl;
    std::cout << "\t" << "Test " << nameObjTest << " with all: " << std::endl;
    testBoolOperations(nameObjTest, nameObj1, objTest, obj1);
    testBoolOperations(nameObjTest, nameObj2, objTest, obj2);
    testBoolOperations(nameObjTest, nameObj3, objTest, obj3);
    testBoolOperations(nameObjTest, nameObj4, objTest, obj4);
    testBoolOperations(nameObjTest, nameObj5, objTest, obj5);
    testBoolOperations(nameObjTest, nameObj6, objTest, obj6);
    testBoolOperations(nameObjTest, nameObj7, objTest, obj7);
    std::cout << "\t" << "=================================================" << "\n" << std::endl;
}

void testOverloadBoolOperators() {
    sak::Stack<int> objVoid, objFive1, objTen, objFive2, objSeven;
    generateValuesStack(objVoid, 0);
    generateValuesStack(objFive1, 5);
    generateValuesStack(objTen, 10);
    generateValuesStack(objFive2, 5);
    generateValuesStack(objSeven, 7);
    sak::Stack<int> objTenCopy(objTen), objVoidCopy(objVoid);

    std::cout
        << "All Stack objects (for test bool overload operators):" << "\n"
        << "\t" << "objVoid: " << objVoid << "\n"
        << "\t" << "objFive1: " << objFive1 << "\n"
        << "\t" << "objTen: " << objTen << "\n"
        << "\t" << "objFive2: " << objFive2 << "\n"
        << "\t" << "objSeven: " << objSeven << "\n"
        << "\t" << "objTenCopy: " << objTenCopy << "\n"
        << "\t" << "objVoidCopy: " << objSeven << std::endl;

    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objVoid",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objVoid
    );
    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objFive1",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objFive1
    );
    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objTen",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objTen
    );
    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objFive2",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objFive2
    );
    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objSeven",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objSeven
    );
    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objTenCopy",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objTenCopy
    );
    testObjectsInBoolOpeations(
        "objVoid", "objFive1", "objTen", "objFive2", "objSeven", "objTenCopy", "objVoidCopy", "objVoidCopy",
        objVoid, objFive1, objTen, objFive2, objSeven, objTenCopy, objVoidCopy, objVoidCopy
    );
}