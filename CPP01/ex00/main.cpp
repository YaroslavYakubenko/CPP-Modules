#include "Zombie.hpp"

int main(void) {
    // Create zombie in heap
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    // Create zombie in stack
    randomChump("StackZombie");

    return 0;
}