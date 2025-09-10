#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t serialized;
	Data *deserialized;

	data.name = "Joe";
	data.number = 1;
	std::cout << "Original adress:	" << &data << std::endl;
	
	serialized = Serializer::serialize(&data);
	std::cout << "Serialized adress:	" << serialized << std::endl;

	deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized adress:	" << deserialized << std::endl;
	std::cout << "Name: " << deserialized->name << ", Number: " << deserialized->number << std::endl;

	if (deserialized == &data)
		std::cout << "The adresses match" << std::endl;
	else 
		std::cout << "The adresses do not match" << std::endl;

	return (0);
	
}