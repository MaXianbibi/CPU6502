#include "CPU.hpp"


CPU::CPU()
{
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
}

void CPU::reset(Memory &mem)
{
	this->reset();
	mem.init();
}

// Fetch
BYTE CPU::fetchBytes(Memory &mem, u32 &Cycles)
{
	BYTE data = mem.read(this->PC);
	this->PC++;
	Cycles--;
	return data;
}


// Execute
void CPU::execute(Memory &mem, u32 Cycles)
{
	while (Cycles > 0)
	{
		BYTE Ins = fetchBytes(mem, Cycles);
		switch ( Ins )
		{
			case INS_LDA_IM:
			{
				std::cout << "[DEBUG] : INS_LDA_IM" << std::endl;

				BYTE value = fetchBytes( mem, Cycles);
				A = value;
				P.flags.Zero = (A == 0);
				P.flags.Negative = (A & 0b10000000) > 0;
			} break ;
			default:
			{
				std::cout << "Instruction not handled " << Ins << std::endl;
			} break ;
		}
	}
}


// La fonction est wrapper qui execute un Ins en simulant la clock speed du 6502
void CPU::executeClock(Memory &mem, u32 &Cycles, InsFunc insFunc)
{
	// start le timer
	auto start = std::chrono::high_resolution_clock::now();

	// execute l'instruction
	(this->*insFunc)(mem);

	// diminue le cycle 
	Cycles--;

	// arrete le temps
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	// stop le temps pour simuler la clock spped du 6502
	if (elapsed < time_expected)
		std::this_thread::sleep_for(std::chrono::microseconds(time_expected - elapsed));
}

// Même chose sauf qu'elle est destiné a l'instrucion Fetch
BYTE CPU::executeClock(Memory &mem, u32 &Cycles, FetchFunc fetchFunc)
{
	auto start = std::chrono::high_resolution_clock::now();
	BYTE value = (this->*fetchFunc)(mem);

	Cycles--;
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