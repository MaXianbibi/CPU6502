#ifndef JMP_HPP
#define JMP_HPP

class JMP : public Ins
{
private:
	Adress address = 0;
public:
	JMP(CPU &CPU_) : Ins(3, CPU_) {
		std::cout << "JMP" << std::endl;
	}
	~JMP() = default;

	void run() override
	{
		address = getAdress(_CPU); // 2 cycles

		printHexDebug("JMP ADRESS : ", address);

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