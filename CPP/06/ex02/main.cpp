#include "ABC.hpp"

int main()
{
	Base *obj;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "--New--"<< std::endl;
		obj = generate();
		std::cout << "pointer:";
		identify(obj);
		std::cout << "reference:";
		identify(*obj);
		delete obj;
	}
}