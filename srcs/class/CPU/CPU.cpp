#include "CPU.hpp"

#include "../INS/INS_LIST.hpp"

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

	for (size_t i = 0; i < 7; i++)
		this->executeClock(NULL);
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

BYTE CPU::pushStack(BYTE value)
{
	if (this->SP == 0xFF - 1 )
		fatal("Stack overflow");
	this->SP++;
	this->mem->write(START_SP - this->SP, value);
	return 0;
}

BYTE CPU::pullStack(void) // je sais pas si sa prend un PC
{
	if (this->SP == 0)
		fatal("Stack underflow");
	BYTE value = this->mem->read(START_SP - this->SP);
	this->SP--;
	return value;
}

BYTE CPU::execSetPC(Adress PC)
{
	this->PC = PC;

	return 0;
}

// Execute Ins
void CPU::execute(void)
{
	// Fetch opcode

	BYTE OP_CODE = this->executeClock(&CPU::fetchBytes);

	// Look up opcode and execute
	switch (OP_CODE)
	{
	case INS_JMP_ABS:
	{
		JMP op(*this);
		op.run();
		break;
	}
	case INS_JMP_IND:
	{
		JMP_IND op(*this);
		op.run();
		break;
	}
	case INS_JSR_ABS:
	{
		JSR op(*this);
		op.run();
		break;
	}
	case INS_RTS_IMP:
	{
		RTS op(*this);
		op.run();
		break;
	}
	default:
		printHexDebug("Instruction non reconnue : ", OP_CODE);
		break;
	}
}


// C'est degalass avec les 3 wrappers différents, un template ou rassembler en une fonction plus global
// La fonction est wrapper qui execute un Ins en simulant la clock speed du 6502
BYTE CPU::executeClock(InsFunc insFunc)
{
	// start le timer
	auto start = std::chrono::high_resolution_clock::now();
	BYTE value = 0;

	// execute l'instruction
	if (insFunc)
		value = (this->*insFunc)();
	// arrete le temps
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	// stop le temps pour simuler la clock spped du 6502
	if (elapsed < time_expected)
		std::this_thread::sleep_for(std::chrono::microseconds(time_expected - elapsed));

	return value;
}

BYTE CPU::executeClock(InsFuncARG insFunc, BYTE arg)
{
	auto start = std::chrono::high_resolution_clock::now();
	BYTE value = 0;

	if (insFunc)
		value = (this->*insFunc)(arg);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	if (elapsed < time_expected)
		std::this_thread::sleep_for(std::chrono::microseconds(time_expected - elapsed));
	return value;
}

BYTE CPU::executeClock(InsFuncAdress insFunc, Adress arg)
{
	auto start = std::chrono::high_resolution_clock::now();
	BYTE value = 0;

	if (insFunc)
		value = (this->*insFunc)(arg);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
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

Memory *CPU::getMemory() const
{
	return this->mem;
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

void CPU::setMemory(Memory *mem)
{
	this->mem = mem;
}

