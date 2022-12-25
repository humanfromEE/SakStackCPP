#include <conio.h> // For getch()

#include "..\..\test\test_constructors\test_constructors.h"

int main() {
    defaultConstructor();
    copyConstructor();
    copyStdStackConstructor();

    std::cout << "\n\n" << "Double-click for close window console" << std::endl;
    getch();
    getch();

    return 0;
}