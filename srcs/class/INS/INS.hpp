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



class JMP : public Ins
{
private:
    Adress address = 0;

public:
    JMP(CPU &CPU) : Ins(3, CPU) {}
    ~JMP() = default;

    void run() override
    {
        address = _CPU.executeClock(&CPU::fetchBytes) << 8;
        address += _CPU.executeClock(&CPU::fetchBytes);


        _CPU.setPC(address);
        (void) n_cylcle;

        std::cout << "JMP ADRESSE : " << address << std::endl;
    }
};

#endif