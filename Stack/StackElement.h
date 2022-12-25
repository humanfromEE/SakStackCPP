#pragma once

/*
    * StAcK - sak
    * TD - Type Data
    * fTD - friend Type Data (for friend methods of class Stack)
    * StackElement - element of stack (class StackElement)
    * Stack - stack (class Stack)
*/

namespace sak {
    template<typename TD>
    class StackElement {
        private:
            StackElement<TD>* _back; // For deleting current and set new head of Stack
            TD value;
        
        private:
            StackElement(StackElement<TD>* _back, TD value) noexcept; // First object of ElementsStack for class Stack has _back value: nullptr

        template<typename fTD>
            friend class Stack;
    };
}

#include "..\Stack\Implementation\ImplementationStackElement.h"