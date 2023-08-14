#ifndef JSR_HPP
#define JSR_HPP

class JSR : public Ins
{
	private:
		BYTE	tmp_address;
		Adress 	address;
	public:
	JSR(CPU &CPU_) : Ins(6, CPU_) { std::cout << "JSR" << std::endl; address = 0; tmp_address = 0; }
	~JSR() = default;

	void run() override
	{
		_CPU.setPC(_CPU.getPC() + 1);
		tmp_address = _CPU.executeClock(&CPU::fetchBytes);


		printHexDebug("JSR : TMP ADRESS : ", tmp_address);


		_CPU.getMemory()->write(START_SP - _CPU.getSP(), tmp_address);
		_CPU.setSP(_CPU.getSP() - 1);

		
		return;
	}
};


#endif