#ifndef CPU_HPP
#define CPU_HPP

#include "../Memory/Memory.hpp"

class CPU;

using InsFunc = BYTE (CPU::*) (void);

class CPU
{
private:
    WORD PC{0};
    BYTE SP{0};
    BYTE A{0}, X{0}, Y{0};

    union Status
    {
        struct 
        {
            BYTE Carry : 1;
            BYTE Zero : 1; 
            BYTE Interrupt : 1;
            BYTE Decimal : 1;
            BYTE Break : 1;
            BYTE Unused : 1;
            BYTE Overflow : 1;
            BYTE Negative : 1;
        } flags;
        
        BYTE status{0};
    } P{};


    Memory *mem;
public:
    CPU();
    CPU(Memory &mem);
    ~CPU();


	// Reset CPU
	void reset();
	void reset(Memory &mem);


	// Execute
	void execute(void);
	BYTE fetchBytes();

    // Clock  + execute
    BYTE executeClock(InsFunc insFunc);

    // Instructions













	// Getter
	BYTE getA() const;
	BYTE getX() const;
	BYTE getY() const;
	BYTE getStatus() const;
	WORD getPC() const;
	WORD getSP() const;

	Memory *getMemory() const;


	// Setter
	void setA(BYTE);
	void setX(BYTE);
	void setY(BYTE);
	void setStatus(BYTE);
	void setPC(WORD);
	void setSP(WORD);

	void setMemory(Memory *mem);

};

#endif
