#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* animals[6];
	animals[0] = new Dog;
	animals[1] = new Cat;
	animals[2] = new Dog;
	animals[3] = new Cat;
	animals[4] = new Dog;
	animals[5] = new Cat;

	for (int i = 0; i < 6; ++i) {
		std::cout << animals[i]->getType() << " makes sound: ";
		animals[i]->makeSound();
	}

	Dog originalDog;
	Dog copieDog = originalDog;
	std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
	std::cout << "Copied Dog type: " << copieDog.getType() << std::endl;
	for (int i = 0; i < 6; ++i)
		delete animals[i];
	return 0;
}