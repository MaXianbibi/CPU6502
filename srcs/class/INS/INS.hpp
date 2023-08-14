#ifndef INS_HPP
#define INS_HPP



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


#endif