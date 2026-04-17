#include "Zoo.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor with initializer list
Animal::Animal(std::string name, int age, std::string habitat)
  : name(name), age(age), habitat(habitat){}

// Destructor
Animal::~Animal() {}

void Animal::displayInfo() {
  std::cout 
    << "Name: " << name << "\n"
    << "Type: "<< getAnimal() << "\n"
    << "Age: " << age << "\n"
    << "Habitat: " << habitat << "\n"
    << "Unique Attribute: " << getUnique() << "\n"
    << std::endl;
}

std::string Animal::getName() const {
  return name;
}
int Animal::getAge() const {
  return age;
}
std::string Animal::getHabitat() const {
  return habitat;
}




// Lion

Lion::Lion(std::string name, int age, std::string habitat, std::string maneColor)
  : Animal(name, age, habitat), maneColor(maneColor) {}

void Lion::setManeColor(std::string color) {
  maneColor = color;
}

std::string Lion::getManeColor() {
  return maneColor;
}

std::string Lion::getUnique() {
  return "Mane Color: " + maneColor; 
}

std::string Lion::getAnimal() {
  return "Lion";
}

void Lion::speak() {
  std::cout << "Vocabulary: Roar" << std::endl;
}
void Lion::move() {
  std::cout << "Movement Style: Walk/Run" << std::endl;
}
void Lion::diet() {
  std::cout << "Diet: Carnivore - Herd Animals" << std::endl;
}

// Eagle

Eagle::Eagle(std::string name, int age, std::string habitat, double wingSpan)
  : Animal(name, age, habitat), wingSpan(wingSpan) {}

void Eagle::setWingSpan(double span) {
  wingSpan = span;
}

double Eagle::getWingSpan() {
  return wingSpan;
}

std::string Eagle::getUnique() {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2) << wingSpan;
  return "Wing Span: " + stream.str() + " meters";
}


std::string Eagle::getAnimal() {
  return "Bald Eagle";
}

void Eagle::speak() {
  std::cout << "Vocabulary: Screech" << std::endl;
}

void Eagle::move() {
  std::cout << "Movement Style: Fly/Dive" << std::endl;
}

void Eagle::diet() {
  std::cout << "Diet: Carnivore - Rodents/Fish" << std::endl;
}

// Ibex

Ibex::Ibex(std::string name, int age, std::string habitat,
    std::string species) : Animal(name, age, habitat), species(species) {}

void Ibex::setSpecies(std::string type) {
  species = type;
}

std::string Ibex::getSpecies() {
  return species;
}

std::string Ibex::getUnique() {
  return "Species: " + species;
}

std::string Ibex::getAnimal() {
  return "Ibex";
}

void Ibex::speak() {
  std::cout << "Vocabulary: Whistle/Chirp" << std::endl;
}

void Ibex::move() {
  std::cout << "Movement Style: Jump/Climb" << std::endl;
}

void Ibex::diet() {
  std::cout << "Diet: Herbivore - Grasses/Shrubs" << std::endl;
}

// Snow Leopard

SnowLeopard::SnowLeopard(std::string name, int age, std::string habitat,
    std::string nickname) : Animal(name, age, habitat), nickname(nickname) {}

void SnowLeopard::setNickname(std::string phrase) {
  nickname = phrase;
}

std::string SnowLeopard::getNickname() {
  return nickname;
}

std::string SnowLeopard::getUnique() {
  return "Nickname: " + nickname;
}

std::string SnowLeopard::getAnimal() {
  return "Snow Leopard";
}

void SnowLeopard::speak() {
  std::cout << "Vocabulary: Growl, Hiss, Prusten" << std::endl;
}

void SnowLeopard::move() {
  std::cout << "Movement style: Climb/Leap" << std::endl;
}

void SnowLeopard::diet() {
  std::cout << "Diet: Carnivore - Wild sheep/Ibex" << std::endl;
}
    
// Zoo

void Zoo::addAnimal(Animal* a) {
  animals.push_back(a);
}

void Zoo::dailyShow() {
  std::cout << "~~~ Welcome to the Zoo! ~~~\n" << std::endl;
  std::cout << "=== Today's Lineup ===\n" << std::endl;
  for (Animal* a : animals) {
    std::cout
      << "\n=== " << a->getName() << " the "
      << a->getAnimal() << " ===\n"
      << "Age: " << a->getAge() << "\n"
      << "Habitat: " << a->getHabitat() << "\n"
      << a->getUnique()
      << std::endl;

    a->speak();
    a->move();
    a->diet();
  }
}

void Zoo::displayAllInfo() {

  std::cout << "\n=== Animal Information ===\n" << std::endl;
  for (Animal* a : animals) {
    a->displayInfo();
  }
}

Zoo::~Zoo() {
  for (Animal* a : animals) {
    delete a;
  }
}


