/*

File: main.cpp
Date: 4/16/2026

Description:
  Main file - Instantiates Zoo object, adds Animal objects to
  and animal vector, calls method for displaying info, and 
  demonstrates runtime polymorphism with a derived Ibex object.

*/

#include "Zoo.h"

int main() {

  // Instantiates zoo object
  Zoo zoo;

  // Calls addAnimal method for zoo class
  zoo.addAnimal(new Lion("Bryan", 5, "Savanna", "Goldenrod"));
  zoo.addAnimal(new Eagle("Spiegel", 12, "America", 1.6));
  zoo.addAnimal(new Ibex("Sherpa", 15, "Mountains", "Himalayan"));
  zoo.addAnimal(new SnowLeopard("Rosette", 10, "Mountains",
        "Ghost of the Mountains"));

  // Calls daily show method for zoo class
  zoo.dailyShow();  
 
  // Calls displayAllInfo method for zoo class
  zoo.displayAllInfo();



   
  std::cout << "=== Polymorphism Demo ===\n" << std::endl;

  // Zoo-independent animal object
  Animal* a = new Ibex("Hopper", 10, "Mountains", "Siberian");

  std::cout 
    << "Name: " << a->getName() << "\n"
    << "Age: " << a->getAge() << "\n"
    << "Habitat: " << a->getHabitat() << "\n"
    << std::endl;

  // Calls base class functions
  a->speak();
  a->move();
  a->diet();
  delete a;

  return 0;
}
