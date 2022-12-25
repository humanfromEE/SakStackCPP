#include <conio.h> // For getch()

#include "..\..\test\test_methods\test_methods.h"

int main() {
    getSakStacksAnyLength();

    std::cout << "\n\n" << "Double-click for close window console" << std::endl;
    getch();
    getch();

    return 0;
}