#pragma once

#include "..\..\Stack\StackElement.h"

/*
    * StAcK - sak
    * TD - Type Data
    * fTD - friend Type Data (for friend methods of class Stack)
    * StackElement - element of stack (class StackElement)
    * Stack - stack (class Stack)
*/

namespace sak {
    template<typename TD>
    StackElement<TD>::StackElement(StackElement<TD>* _back, TD value) noexcept {
        this->_back = _back;
        this->value = value;
    }
}