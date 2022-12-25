#pragma once

#include <stack> // For manipulation with classes Stack and stack (for convert and equal)
#include <iostream> // For overload operator <<

#include "..\Stack\StackElement.h"
#include "..\Stack\Stack.h"

/*
    * StAcK - sak
    * TD - Type Data
    * fTD - friend Type Data (for friend methods of class Stack)
    * StackElement - element of stack (class StackElement)
    * Stack - stack (class Stack)
*/

namespace sak {
    template<typename fTD>
    std::ostream& operator<<(std::ostream& os, const Stack<fTD>& obj);

    template<typename fTD>
    std::ostream& operator<<(std::ostream& os, const std::stack<fTD>& obj_stack);

    template<typename fTD>
    bool operator==(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);

    template<typename fTD>
    bool operator!=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);

    template<typename fTD>
    bool operator<=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);

    template<typename fTD>
    bool operator>=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);

    template<typename fTD>
    bool operator<(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);

    template<typename fTD>
    bool operator>(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
}

#include "..\Stack\Implementation\ImplementationFriendStack.h"
