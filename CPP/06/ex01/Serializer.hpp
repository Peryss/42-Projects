#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>
#include <iostream>

struct Data {
	int			number;
	std::string	name;
};

class Serializer
{
	private:
		Serializer ();
		~Serializer ();
		Serializer (const Serializer &other);
		Serializer &operator= (const Serializer &other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif