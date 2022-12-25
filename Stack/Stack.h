#pragma once

#include <stack> // For manipulation with classes Stack and stack (for convert and equal)
#include <iostream> // For overload operator <<

#include "..\Stack\StackElement.h"

#define LLI long long int // Use this type data for size of Stack 

/*
    * StAcK - sak
    * TD - Type Data
    * fTD - friend Type Data (for friend methods of class Stack)
    * StackElement - element of stack (class StackElement)
    * Stack - stack (class Stack)
*/

namespace sak {
    template<typename TD>
    class Stack {
        private:
            StackElement<TD>* _head;
            LLI length;
        
        public:
            Stack() noexcept; // Default constructor
            Stack(const Stack<TD>& obj) noexcept; // Copy constructor
            Stack(const std::stack<TD>& obj_stack) noexcept; // Copy constructor use object of std::stack
            ~Stack() noexcept; // Destructor
            LLI size() const noexcept; // Return size of Stack
            bool empty() const noexcept; // Check void of Stack
            void push(TD value) noexcept; // Append element on top of Stack
            void pop() noexcept; // Delete top element and current new top of Stack
            TD& top() noexcept; // Return reference on top of Stack for edit (get access on top)
            void swap(Stack<TD>& obj) noexcept; // Exchange data of this-Stack and signature-Stack
            void clear() noexcept; // Clear Stack (delete all data of Stack)
            void copy(const Stack<TD>& obj, bool reverseStack) noexcept; // Copy data of signature-Stack
            void reverse() noexcept; // Reverse data of Stack: Stack<int> a {1, 2, 3} => Stack<int> a {3, 2, 1}
            TD* getArrayValues(bool reverseStack) const noexcept; // Get array pointer of values of Stack Stack<int> a {1, 2, 3} => true: [3, 2, 1]; false: [1, 2, 3]
            void this_convert(std::stack<TD> obj_stack) noexcept; // Convert object std::stack to object Stack
            std::stack<TD> this_reconvert() const noexcept; // Convert object Stack to object std::stack
            LLI this_sizeof()  const noexcept; // Return size of Stack (use sizeof())

        public:
            static Stack<TD> convert(std::stack<TD> obj_stack) noexcept; // Static, convert object Stack to object std::stack
            static std::stack<TD> reconvert(const Stack<TD>& obj) noexcept; // Static, return size of Stack (use sizeof())

        private:
            static StackElement<TD>* getBackStackElement(StackElement<TD>* stackElement) noexcept; // Static, get pointer of filed _back (class StackElement) - uses in friend methods of Stack
            static TD getValueStackElement(StackElement<TD>* stackElement) noexcept; // Static, get value of filed value (class StackElement) - uses in friend methods of Stack

        template<typename fTD>
            friend std::ostream& operator<<(std::ostream& os, const Stack<fTD>& obj);
        template<typename fTD>
            friend std::ostream& operator<<(std::ostream& os, const std::stack<fTD>& obj_stack); // For cout output of object std::stack  
        template<typename fTD>
            friend bool operator==(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
        template<typename fTD>
            friend bool operator!=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
        template<typename fTD>
            friend bool operator<=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
        template<typename fTD>
            friend bool operator>=(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
        template<typename fTD>
            friend bool operator<(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
        template<typename fTD>
            friend bool operator>(const Stack<fTD>& objLeft, const Stack<fTD>& objRight);
    };
}

#include "..\Stack\Implementation\ImplementationStack.h"
#include "..\Stack\FriendStack.h" // include reference of implementation file