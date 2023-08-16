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
	putAdress(cpu, 0xB213, 0x2030);
	putIns(cpu, 0x2030, INS_JSR_ABS);
	putAdress(cpu, 0x2031, 0xABCD);
	putIns(cpu, 0xABCD, INS_RTS_IMP);
	
	// putAdress(cpu, 0x2021, 0xFFBB );

	cpu.execute();
	cpu.execute();
	cpu.execute();


	return 0;
}