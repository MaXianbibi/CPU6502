#ifndef RTS_HPP
#define RTS_HPP

class RTS : public Ins
{
private:
	
public:
	RTS(CPU &_CPU) : Ins(6, _CPU) { printHex("JSR : ", _CPU.getPC());}
	~RTS() = default;

	void run() override
	{
		_CPU.executeClock(NULL);
		// _CPU.setPC(_CPU.getPC() + 1);

		_CPU.executeClock(&CPU::execSetPC, _CPU.getPC() + 1); // Ne fait rien d'autre que pc++.. Idk man

		
	}
};



#endif