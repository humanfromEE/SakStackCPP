#include <conio.h> // For getch()

#include "..\..\test\test_friend_functions\test_friend_functions.h"

int main() {
    testOverloadOstream();
    testOverloadBoolOperators();

    std::cout << "\n\n" << "Double-click for close window console" << std::endl;
    getch();
    getch();

    return 0;
}