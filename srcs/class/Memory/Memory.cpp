#include "Memory.hpp"

Memory::Memory()
{
	this->init();
}

Memory::~Memory()
{
}

void Memory::init()
{
	for (u32 i = 0; i < MAX_MEMORY; i++)
		this->Data[i] = 0;
}


// Read
// aucune vérification d'adresse
// Techniquement, on ne peut pas lire en dehors de la mémoire
BYTE Memory::read(WORD addr) const
{
	return this->Data[addr];
}

BYTE Memory::operator[](WORD addr) const
{
	return this->read(addr);
}

// Write
// aucune vérification d'adresse, même chose que read
void Memory::write(WORD addr, BYTE data)
{
	this->Data[addr] = data;
}

BYTE & Memory::operator[](WORD addr)
{
	return this->Data[addr];
}