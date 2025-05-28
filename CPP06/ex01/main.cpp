#include "Serializer.hpp"

int main() {
	Data original;
	original.id = 42;
	original.content = "Hello 42!";

	std::cout << "Original data adress: " << &original << std::endl;
	std::cout << "Original data content: number = " << original.id << ", text = " << original.content << std::endl;

	//Serialization
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized raw value: " << raw << std::endl;

	//Deserialization
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized data adress: " << deserialized << std::endl;
	std::cout << "Deserialzied data adress: number = " << deserialized->id << ", text = " << deserialized->content << std::endl;

	// Adress matching check
	if (deserialized == &original)
		std::cout << "Success: pointers are matching" << std::endl;
	else
		std::cout << "Error: pointers are not matching" << std::endl;
	return 0;
}