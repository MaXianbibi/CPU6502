#include "../CPU/CPU.hpp"

// Total : 2 cycles
// Jcrois que ya un instruction dédier a ca... à renommer
Adress getAdress(CPU &CPU)
{
	Adress address = 0;
	address = CPU.executeClock(&CPU::fetchBytes); // 1 cycle
	address += CPU.executeClock(&CPU::fetchBytes) << 8;	   // 1 cycle
	return address;
}

void putAdress(CPU &CPU, Adress Index, Adress adress)
{
	CPU.getMemory()->write(Index, adress & 0xFF);
	CPU.getMemory()->write(Index + 1, (adress >> 8) & 0xFF);
}

void putIns(CPU &CPU, Adress Index, BYTE ins)
{
	CPU.getMemory()->write(Index, ins);
}