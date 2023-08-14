#include "class/CPU/CPU.hpp"
#include "class/Memory/Memory.hpp"

#include "class/include.hpp"
#include <iostream>

int main(void)
{
	Memory mem;
	CPU cpu;


	cpu.reset(mem);


	putIns(cpu, START_RESET, 0x4C);
	putAdress(cpu, START_RESET + 1, 0xB213);

	putIns(cpu, 0xB213, 0xA);


	cpu.execute();
	cpu.execute();

	return 0;
}