#pragma once

#include "..\..\Stack\Stack.h"

/*
    * StAcK - sak
    * TD - Type Data
    * fTD - friend Type Data (for friend methods of class Stack)
    * StackElement - element of stack (class StackElement)
    * Stack - stack (class Stack)
*/

namespace sak {
    template<typename TD>
    Stack<TD>::Stack() noexcept {
        _head = nullptr;
        length = 0;
    }

    template<typename TD>
    Stack<TD>::Stack(const Stack<TD>& obj) noexcept {
        _head = nullptr;
        length = 0;
        copy(obj, false);
    }

    template<typename TD>
    Stack<TD>::Stack(const std::stack<TD>& obj_stack) noexcept {
        _head = nullptr;
        length = 0;
        this_convert(obj_stack);
    }

    template<typename TD>
    Stack<TD>::~Stack() noexcept {
        clear();
    }

    template<typename TD>
    LLI Stack<TD>::size() const noexcept {
        return length;
    }

    template<typename TD>
    bool Stack<TD>::empty() const noexcept {
        return (length == 0);
    }

    template<typename TD>
    void Stack<TD>::push(TD value) noexcept {
        _head = new StackElement<TD>( (length == 0) ? nullptr : _head, value);
        length++;
    }

    template<typename TD>
    void Stack<TD>::pop() noexcept {
        if (length != 0) {
            StackElement<TD>* stackElement = _head->_back;
            delete _head;
            _head = stackElement;
            length--;
        }
    }

    template<typename TD>
    TD& Stack<TD>::top() noexcept {
        return _head->value;
    }

    template<typename TD>
    void Stack<TD>::swap(Stack<TD>& obj) noexcept {
        std::swap(_head, obj._head);
        std::swap(length, obj.length);
    }

    template<typename TD>
    void Stack<TD>::clear() noexcept {
        while (_head) {
            StackElement<TD>* stackElement = _head->_back;
            delete _head;
            _head = stackElement;
        }
        length = 0;
    }

    template<typename TD>
    void Stack<TD>::copy(const Stack<TD>& obj, bool reverseStack) noexcept {
        if (obj.length == 0) {
            _head = nullptr;
            length = 0;
        } else {
            TD* arrayValues = obj.getArrayValues(reverseStack);
            if (arrayValues) {
                for (LLI i = 0; i < obj.length; i++) {
                    push(arrayValues[i]);
                }
            }
            delete [] arrayValues;
        }
    }

    template<typename TD>
    void Stack<TD>::reverse() noexcept {
        if (length > 1) {
            TD* arrayValues = getArrayValues(true);
            LLI length = this->length;
            clear();
            for (LLI i = 0; i < length; i++) {
                push(arrayValues[i]);
            }
            this->length = length;
            delete [] arrayValues;
        }
    }

    template<typename TD>
    TD* Stack<TD>::getArrayValues(bool reverseStack) const noexcept {
        TD* arrayValues = new TD[length];
        LLI counter = (reverseStack) ? 0 : (length - 1);
        short int step = (reverseStack) ? 1 : -1;
        StackElement<TD>* stackElement = _head;
        while (stackElement) {
            arrayValues[counter] = stackElement->value; 
            stackElement = stackElement->_back;
            counter += step;
        }
        return arrayValues;
    }

    template<typename TD>
    void Stack<TD>::this_convert(std::stack<TD> obj_stack) noexcept {
        if (obj_stack.empty()) {
            _head = nullptr;
            length = 0;
        } else {
            LLI length = obj_stack.size();
            TD* arrayValues = new TD[length];
            LLI counter = length - 1;
            while (!obj_stack.empty()) {
                arrayValues[counter--] = obj_stack.top();
                obj_stack.pop();
            }
            clear();
            for(LLI i = 0; i < length; i++) {
                push(arrayValues[i]);
            }
            delete [] arrayValues;
        }
    }

    template<typename TD>
    std::stack<TD> Stack<TD>::this_reconvert() const noexcept {
        std::stack<TD> obj_stack;
        if (!empty()) {
            TD* arrayValues = getArrayValues(false);
            for (LLI i = 0; i < length; i++) {
                obj_stack.push(arrayValues[i]);
            }
            delete [] arrayValues;
        }
        return obj_stack;
    }

    template<typename TD>
    LLI Stack<TD>::this_sizeof() const noexcept {
        return ( sizeof(*this) + length * sizeof(StackElement<TD>) );
    }

    template<typename TD>
    Stack<TD> Stack<TD>::convert(std::stack<TD> obj_stack) noexcept {
        Stack<TD> obj(obj_stack);
        return obj;
    }

    template<typename TD>
    std::stack<TD> Stack<TD>::reconvert(const Stack<TD>& obj) noexcept {
        return obj.this_reconvert();
    }

    template<typename TD>
    StackElement<TD>* Stack<TD>::getBackStackElement(StackElement<TD>* stackElement) noexcept { // For get access in Stack friend-function
        return stackElement->_back;
    }

    template<typename TD>
    TD Stack<TD>::getValueStackElement(StackElement<TD>* stackElement) noexcept { // For get access in Stack friend-function
        return stackElement->value;
    }
}
