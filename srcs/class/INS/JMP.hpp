#ifndef JMP_HPP
#define JMP_HPP

class JMP : public Ins
{
private:
	Adress address = 0;
public:
	JMP(CPU &CPU_) : Ins(3, CPU_) {
		printHex("JMP : ", _CPU.getPC());
	}
	~JMP() = default;

	void run() override
	{
		address = getAdress(_CPU); // 2 cycles
		_CPU.setPC(address);
	}
};

// JMP IND (5 cycles) : Jump to a new location
class JMP_IND : public Ins
{
private:
	Adress address = 0;

public:
	JMP_IND(CPU &CPU) : Ins(3, CPU) {
		printHex("JMP_IND : ", _CPU.getPC());
	}
	~JMP_IND() = default;

	void run() override
	{

		// get indirect adress
		address = getAdress(_CPU); // 2 cycles 

		// je suis pas sur de ca
		_CPU.setPC(address);
		// get next pc adress 
		address = getAdress(_CPU); // 2 cycles 
		_CPU.setPC(address);
	}
};



#endif