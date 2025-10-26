#pragma once

#include <cstdint>
#include <string>

enum class SUBCOMMAND : uint8_t
                        // DO NOT CHANGE ORDER
{
    SHOCK, // TODO   : Build the deck            
    SURVEIL, // TODO : Tune and optimize nonlands
    TRIOME, // TODO  : Tune manabase             
    TAPPED, // TODO  :                           
    SNOW, // TODO    : Substitutions             
    CYCLE, // TODO   :                           
    TANGO, // TODO   : Budget                    
    DUAL, // TODO    : Database, search          
    EXIT //          : Close application
};
SUBCOMMAND run_main_menu();

std::string to_String(const SUBCOMMAND subc);
std::string to_FancyString(const SUBCOMMAND subc);
std::string helptext(const SUBCOMMAND subc);
