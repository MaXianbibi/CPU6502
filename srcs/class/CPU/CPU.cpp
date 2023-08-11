#include "CPU.hpp"
#include "../INS/INS.hpp"

CPU::CPU()
{
	this->reset();
}

CPU::CPU(Memory &memory)
{
	this->reset(memory);
}

CPU::~CPU()
{
}

// Reset CPU
void CPU::reset()
{
	this->PC = START_PC; 
	this->SP = 0;
	this->A = 0;
	this->X = 0;
	this->Y = 0;
	this->P.status = 0x24;
	this->mem = nullptr;
}

void CPU::reset(Memory &mem)
{
	this->reset();
	mem.init();
	this->mem = &mem;

	JMP op(*this);
	op.run();
}

// Fetch
// Fetch est une oppération qui demande un cycle de CPU
BYTE CPU::fetchBytes(void)
{
	BYTE value = this->mem->read(this->PC);
	this->PC++;
	return value;
}

// Execute Ins
void CPU::execute(void)
{
	// Fetch opcode

	std::cout << "pc at exec : " << std::hex << getPC() << std::endl;

	BYTE OP_CODE = this->executeClock(&CPU::fetchBytes);

	printHexDebug("pc after exec : ", getPC());

	// Look up opcode and execute
	switch (OP_CODE)
	{
	case INS_JMP_ABS:
	{
		JMP op(*this);
		op.run();
		break;
	}
		
	default:
		printHexDebug("Instruction non reconnue : ", OP_CODE);
		break;
	}
}



// La fonction est wrapper qui execute un Ins en simulant la clock speed du 6502
BYTE CPU::executeClock(InsFunc insFunc)
{
	// start le timer
	auto start = std::chrono::high_resolution_clock::now();

	// execute l'instruction
	BYTE value = (this->*insFunc)();

	// diminue le cycle 

	// arrete le temps
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	// stop le temps pour simuler la clock spped du 6502
	if (elapsed < time_expected)
		std::this_thread::sleep_for(std::chrono::microseconds(time_expected - elapsed));

	return value;
}

// Getter
BYTE CPU::getA() const
{
	return this->A;
}

BYTE CPU::getX() const
{
	return this->X;
}

BYTE CPU::getY() const
{
	return this->Y;
}

BYTE CPU::getStatus() const
{
	return this->P.status;
}

WORD CPU::getPC() const
{
	return this->PC;
}

WORD CPU::getSP() const
{
	return this->SP;
}

// Setter
void CPU::setA(BYTE A)
{
	this->A = A;
}

void CPU::setX(BYTE X)
{
	this->X = X;
}

void CPU::setY(BYTE Y)
{
	this->Y = Y;
}

void CPU::setStatus(BYTE status)
{
	this->P.status = status;
}

void CPU::setPC(WORD PC)
{
	this->PC = PC;
}

void CPU::setSP(WORD SP)
{
	this->SP = SP;
}