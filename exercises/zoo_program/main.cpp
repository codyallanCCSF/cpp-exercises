#include "Zoo.h"

int main() {
  Zoo zoo;

  zoo.addAnimal(new Lion("Bryan", 5, "Savanna", "Goldenrod"));
  zoo.addAnimal(new Eagle("Spiegel", 12, "America", 1.6));
  zoo.addAnimal(new Ibex("Sherpa", 15, "Mountains", "Himalayan"));
  zoo.addAnimal(new SnowLeopard("Rosette", 10, "Mountains",
        "Ghost of the Mountains"));
  zoo.dailyShow();
  
 
  zoo.displayAllInfo();

  std::cout << "=== Polymorphism Demo ===\n" << std::endl;

  Animal* a = new Ibex("Hopper", 10, "Mountains", "Siberian");

  std::cout 
    << "Name: " << a->getName() << "\n"
    << "Age: " << a->getAge() << "\n"
    << "Habitat: " << a->getHabitat() << "\n"
    << std::endl;

  a->speak();
  a->move();
  a->diet();
  delete a;

  return 0;
}
