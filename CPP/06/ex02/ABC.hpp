#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A: public Base {
	private:
	public:
};

class B: public Base {
	private:
	public:
};

class C: public Base {
	private:
	public:
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif