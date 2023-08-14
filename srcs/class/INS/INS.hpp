#ifndef INS_HPP
#define INS_HPP

#include "../CPU/CPU.hpp"
#include "../include.hpp"

class Ins
{
protected:
	const unsigned char n_cylcle = 0;
	CPU &_CPU;

public:
	Ins(unsigned char n_cylcle, CPU &CPU) : n_cylcle(n_cylcle), _CPU(CPU) {}
	virtual ~Ins() = default;
	virtual void run() = 0;
};

// JMP ABS (3 cycles) : Jump to a new location
class JMP : public Ins
{
private:
	Adress address = 0;

public:
	JMP(CPU &CPU) : Ins(3, CPU) {
		std::cout << "JMP" << std::endl;
	}
	~JMP() = default;

	void run() override
	{
		address = getAdress(_CPU); // 2 cycles
		_CPU.setPC(address);

		printHexDebug("JMP ADRESS : ", address);
	}
};

// JMP IND (5 cycles) : Jump to a new location
class JMP_IND : public Ins
{
private:
	Adress address = 0;

public:
	JMP_IND(CPU &CPU) : Ins(3, CPU) {
		std::cout << "JMP_IND" << std::endl;
	}
	~JMP_IND() = default;

	void run() override
	{

		// get indirect adress
		address = getAdress(_CPU); // 2 cycles 

		printHexDebug("JMP_IND ADRESS : ", address);
		// je suis pas sur de ca
		_CPU.setPC(address);
		// get next pc adress 
		address = getAdress(_CPU); // 2 cycles 
		_CPU.setPC(address);
		printHexDebug("JMP_IND ADRESS : ", address);

	}

};



#endif