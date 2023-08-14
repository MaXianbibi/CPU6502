#include "class/CPU/CPU.hpp"
#include "class/Memory/Memory.hpp"

#include "class/include.hpp"
#include <iostream>

int main(void)
{
	Memory mem;
	CPU cpu;


	cpu.reset(mem);

	putIns(cpu, START_RESET, INS_JMP_IND);
	putAdress(cpu, START_RESET + 1, 0xB213);
	putIns(cpu, 0xB213, 0x30);
	putIns(cpu, 0xB214, 0x20);
	// putIns(cpu, 0x2020, INS_JSR_ABS);

	// putAdress(cpu, 0x2021, 0xFFBB );

	cpu.execute();
	// cpu.execute();

	return 0;
}