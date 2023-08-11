#include "class/CPU/CPU.hpp"
#include "class/Memory/Memory.hpp"


#include <iostream>

int main(void)
{
	Memory mem;
	CPU cpu;


	cpu.reset(mem);

	mem[cpu.getPC()] = INS_LDA_IM;
	mem[cpu.getPC() + 1] = 0x42;
	cpu.execute();

	printHexDebug("final pc : ", cpu.getPC());
	// cpu.execute();

	return 0;
}