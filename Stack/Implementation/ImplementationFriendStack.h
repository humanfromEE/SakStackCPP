#pragma once

#include "..\..\Stack\FriendStack.h"

/*
    * StAcK - sak
    * TD - Type Data
    * fTD - friend Type Data (for friend methods of class Stack)
    * StackElement - element of stack (class StackElement)
    * Stack - stack (class Stack)
*/

namespace sak {
    template<typename fTD>
    std::ostream& operator<<(std::ostream& os, const Stack<fTD>& obj) {
        os << "[ ";
        if (obj.length != 0) {
            fTD* arrayValues = obj.getArrayValues(false);
            for (LLI i = 0; i < (obj.length - 1); i++) {
                os << arrayValues[i] << " -> ";
            }
            os << arrayValues[obj.length - 1];
            delete [] arrayValues;
        }
        return (os << " ]");
    }

    template<typename fTD>
    std::ostream& operator<<(std::ostream& os, const std::stack<fTD>& obj_stack) {
        return (os << Stack<fTD>::convert(obj_stack));
    }

    template<typename fTD>
    bool operator==(const Stack<fTD>& objLeft, const Stack<fTD>& objRight) {
        if ( (&objLeft == &objRight) || ( objLeft.empty() && objRight.empty() ) ) {
            return true;
        } else if (objLeft.length == objRight.length) {
            StackElement<fTD>* left = objLeft._head;
            StackElement<fTD>* right = objRight._head;
            while (left) {
                if (Stack<fTD>::getValueStackElement(left) != Stack<fTD>::getValueStackElement(right)) {
                    return false;
                }
                left = Stack<fTD>::getBackStackElement(left);
                right = Stack<fTD>::getBackStackElement(right);
            }
            return true;
        }
        return false;
    }

    template<typename fTD>
    bool operator!=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight) {
        return !(objLeft == objRight);
    }

    template<typename fTD>
    bool operator<=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight) {
        if ( (&objLeft == &objRight) || ( objLeft.empty() && objRight.empty() ) ) {
            return true;
        } else if ( (objLeft.length <= objRight.length) && (!objRight.empty()) ) {
            StackElement<fTD>* left = objLeft._head;
            StackElement<fTD>* right = objRight._head;
            while (left) {
                if (Stack<fTD>::getValueStackElement(left) > Stack<fTD>::getValueStackElement(right)) {
                    return false;
                }
                left = Stack<fTD>::getBackStackElement(left);
                right = Stack<fTD>::getBackStackElement(right);
            }
            return true;
        }
        return false;
    }

    template<typename fTD>
    bool operator>=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight) {
        if ( (&objLeft == &objRight) || ( objLeft.empty() && objRight.empty() ) ) {
            return true;
        } else if ( (objLeft.length >= objRight.length) && (!objLeft.empty()) ) {
            StackElement<fTD>* left = objLeft._head;
            StackElement<fTD>* right = objRight._head;
            while (right) {
                if (Stack<fTD>::getValueStackElement(left) < Stack<fTD>::getValueStackElement(right)) {
                    return false;
                }
                left = Stack<fTD>::getBackStackElement(left);
                right = Stack<fTD>::getBackStackElement(right);
            }
            return true;
        }
        return false;
    }

    template<typename fTD>
    bool operator<(const Stack<fTD>& objLeft, const Stack<fTD>& objRight) {
        if ( (&objLeft == &objRight) || ( objLeft.empty() && objRight.empty() ) ) {
            return false;
        } else if ( (objLeft.length < objRight.length) && (!objRight.empty()) ) {
            StackElement<fTD>* left = objLeft._head;
            StackElement<fTD>* right = objRight._head;
            while (left) {
                if (Stack<fTD>::getValueStackElement(left) < Stack<fTD>::getValueStackElement(right)) {
                    return false;
                }
                left = Stack<fTD>::getBackStackElement(left);
                right = Stack<fTD>::getBackStackElement(right);
            }
            return true;
        }
        return false;
    }

    template<typename fTD>
    bool operator>(const Stack<fTD>& objLeft, const Stack<fTD>& objRight) {
        if ( (&objLeft == &objRight) || ( objLeft.empty() && objRight.empty() ) ) {
            return false;
        } else if ( (objLeft.length > objRight.length) && (!objLeft.empty()) ) {
            StackElement<fTD>* left = objLeft._head;
            StackElement<fTD>* right = objRight._head;
            while (right) {
                if (Stack<fTD>::getValueStackElement(left) < Stack<fTD>::getValueStackElement(right)) {
                    return false;
                }
                left = Stack<fTD>::getBackStackElement(left);
                right = Stack<fTD>::getBackStackElement(right);
            }
            return true;
        }
        return false;
    }
}
