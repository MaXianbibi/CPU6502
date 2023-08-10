#include "class/CPU/CPU.hpp"
#include "class/Memory/Memory.hpp"




int main(void)
{
	Memory mem;
	CPU cpu;


	cpu.reset(mem);

	mem[cpu.getPC()] = INS_LDA_IM;
	mem[cpu.getPC() + 1] = 0x42;
	cpu.execute(mem, 2);
	cpu.execute(mem, 2);


	std::cout << cpu.getPC() << std::endl;

	std::cout << (int)cpu.getA() << std::endl;
	return 0;
}