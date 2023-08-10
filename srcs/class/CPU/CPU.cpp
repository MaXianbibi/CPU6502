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
	this->PC = 0xFFFC; 
	this->SP = 0x0100;
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
		(void)Ins;
	}

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