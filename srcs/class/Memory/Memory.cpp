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


	// sa devrait être dans le fichier de config ou dans le CPU init, c'est plus logique ! 
	this->Data[START_PC] = START_RESET & 0xFF;
	this->Data[START_PC + 1] = (START_RESET >> 8) & 0xFF;

	// Test
	// this->Data[START_RESET] = 0x6C;
	// this->Data[START_RESET + 1] = START_PC >> 8;
	// this->Data[START_RESET + 2] = START_PC & 0xFF;
}


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

// aucune vérification d'adresse, même chose que read
void Memory::write(WORD addr, BYTE data)
{
	this->Data[addr] = data;
}

BYTE & Memory::operator[](WORD addr)
{
	return this->Data[addr];
}