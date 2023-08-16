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
	std::cout << msg << "0x" << std::uppercase << std::hex << hex << std::endl;
}

void printHex(u32 hex )
{
	std::cout << "0x" << std::uppercase << std::hex << hex << std::endl;
}

void fatal(std::string msg)
{
	std::cout << "FATAL : " << msg << std::endl;
	exit(1);
}
