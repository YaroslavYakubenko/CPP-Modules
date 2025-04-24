#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal* dog = new Dog;
	const AAnimal* cat = new Cat;
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	delete dog;
	delete cat;
	std::cout << "\n--- Testing deep copy ---\n" << std::endl;
	Dog originalDog;
	originalDog.setIdea(0, "Chase the cat");
	originalDog.setIdea(1, "Fetch the ball");
	Dog copieDog = originalDog;
	std::cout << "OriginalDog Idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "CopieDog Idea[1]: " << copieDog.getIdea(1) << std::endl;
	originalDog.setIdea(0, "Slepp in the sun");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "OriginalDog Idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "CopieDog Idea[1]:" << copieDog.getIdea(1) << std::endl;
	std::cout << "\n--- Array of AAnimals ---\n" << std::endl;
	const int size = 4;
	AAnimal* animals[size];
	for (int i = 0; i < size; ++i) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < size; ++i) {
		std::cout << "[" << i << "]";
		animals[i]->makeSound();
	}
	for (int i = 0; i < size; ++i)
		delete animals[i];
	return 0;
}