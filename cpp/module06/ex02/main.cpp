#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
public:
	virtual ~Base() {};
};

class A: public Base
{
public:
	A( void ) {};
	~A( void ) {};
};

class B: public Base
{
public:
	B( void ) {};
	~B( void ) {};
};

class C: public Base
{
public:
	C( void ) {};
	~C( void ) {};
};

Base *generate(void)
{
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try{
		A tmp;
		tmp = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B tmp;
		tmp = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try{
		C tmp;
		tmp = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}

int main ()
{
	Base *base = NULL;
	base = generate();
	std::cout << "identify(Base *p):" << std::endl;
	identify(base);
	std::cout << "identify(Base &p)" << std::endl;
	identify(*base);
	delete base;
}
