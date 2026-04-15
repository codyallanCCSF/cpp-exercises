#include "Zoo.h"

int main() {
  Zoo zoo;

  zoo.addAnimal(new Lion("Simba", 5, "Savanna", "Goldenrod"));
  zoo.addAnimal(new Eagle("Spiegel", 12, "America", 1.6));
  zoo.dailyShow();
  // zoo.displayAllInfo();

 // Animal* a = new Lion("Mufasa", 10, "Savanna", "dark brown");
 // a->speak();
 // a->move();
 // a->diet();
 // delete a;

  return 0;
}
