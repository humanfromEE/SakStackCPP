#include <iostream>
#include <cmath> // For pow()
#include <ctime>
#include <stack>

#include <conio.h> // For getch()

#include "Stack\Stack.h"

int main() {
    const int n = pow(10, 8); // 100 million
    sak::Stack<int> obj1;

    std::cout << "Start work program ..." << "\n" << std::endl;

    unsigned int timeStartPush = clock();
    for (int i = 1; i <= n; i++) {
        obj1.push(i);
    }
    LLI sizeObj = obj1.this_sizeof();
    unsigned int timeEndPush = clock();
    int lengthPush = obj1.size();
    std::cout << "Press any key" << std::endl;
    getch();
    unsigned int timeStartPop = clock();
    for (int i = 1; i <= n; i++) {
        obj1.pop();
    }
    unsigned int timeEndPop = clock();
    int lengthPop = obj1.size();

    std::cout 
        << "Time append 100 million elements: " << ( (double)(timeEndPush - timeStartPush) / 1000 ) << "\n"
        << "Size of Stack with 100 million elements: " << lengthPush << "\n"
        << "Sizeof() of Stack with 100 million elements: " << sizeObj << "\n"
        << "\t" << "Sizeof StackElement<int>: " << sizeof(sak::StackElement<int>) << "\n"
        << "\t" << "Sizeof Stack<int>: " << sizeof(sak::Stack<int>) << "\n"
        << "Time delete 100 million elements: "<< ( (double)(timeEndPop - timeStartPop) / 1000 ) << "\n"
        << "Size of Stack with 100 million elements: " << lengthPop << "\n\n"
        << "End program, press double any keys ..." << std::endl;

    getch();
    getch();
    
    return 0;
}