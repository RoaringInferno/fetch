#include <iostream>

#include "main_menu.hpp"

int main()
{
    SUBCOMMAND subc{run_main_menu()};
    std::cout << "Selected: " << to_String(subc) << ".\n";
    return 0;
}
