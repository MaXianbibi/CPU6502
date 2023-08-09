#include "class/CPU/CPU.hpp"
#include "class/Memory/Memory.hpp"


int main(void)
{
	Memory mem;
	CPU cpu;


	cpu.reset(mem);
	cpu.execute(mem, 10);
	cpu.execute(mem, 10);
	cpu.execute(mem, 10);
	cpu.execute(mem, 10);

	return 0;
}