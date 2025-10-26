#include <iostream>

#include "main_menu.hpp"

int main()
{
start:
    SUBCOMMAND subc{run_main_menu()};
    std::cout << "Selected: " << to_String(subc) << "\n";
    switch (subc)
    {
        // case SUBCOMMAND::DUAL:
        case SUBCOMMAND::EXIT:
            return 0; // Exit condition
        default:
            std::getchar();
            goto start; // Catch-all
    }
    return -1; // Something terrible has happened
}
