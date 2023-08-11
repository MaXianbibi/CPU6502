#include <iostream>

#include "class/include.hpp"


void printHexDebug(std::string msg, u32 hex )
{
	std::cout << msg << std::uppercase << std::hex << hex <<  " : " << std::dec << hex << std::endl;
}

void printHexDebug( u32 hex )
{
	std::cout << std::uppercase << std::hex << hex <<  " : " << std::dec << hex << std::endl;
}

void printHex(std::string msg, u32 hex )
{
	std::cout << msg << std::uppercase << std::hex << hex << std::endl;
}

void printHex(u32 hex )
{
	std::cout << std::uppercase << std::hex << hex << std::endl;
}
