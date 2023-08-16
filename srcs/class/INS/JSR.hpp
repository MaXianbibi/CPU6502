#ifndef JSR_HPP
#define JSR_HPP

class JSR : public Ins
{
	private:
		Adress 	address;
	public:
	JSR(CPU &CPU_) : Ins(6, CPU_) { std::cout << "JSR" << std::endl; address = 0;}
	~JSR() = default;

	void run() override
	{
		address = _CPU.executeClock(&CPU::fetchBytes); // READ LOW SOUS ROUTINE // 1 cycle : PC++ : 2 CYCLES 
		_CPU.executeClock(&CPU::pushStack, getHigh(_CPU.getPC() + 1)); // PUT HIGH PC IN SP // 1 CYCLE : PC : 3 CYCLES
		_CPU.executeClock(&CPU::pushStack, getLow(_CPU.getPC() + 1)); // PUT LOW PC IN SP // 1 CYCLE : PC : 4 CYCLES
		address += _CPU.executeClock(&CPU::fetchBytes) << 8; // READ HIGH SOUS ROUTINE // 1 cycle : PC++ : 5 CYCLES
		// Pourquoi elle prend un cycle alors que c'est un set ? 
		_CPU.setPC(address);  // SET PC TO SOUS ROUTINE // 1 CYCLE : PC : 6 CYCLES 
		return;
	}
};


#endif