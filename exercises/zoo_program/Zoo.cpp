/*

File: Zoo.cpp
Date: 4/16/2026

Description:
  Implementation file - Defines constructors for base and derived
  classes with initializer lists. Povides definitions for all class
  methods.

NOTE: This program uses the iomanip and sstream from the standard
library to format a double with 2 decimal places and convert
the double to a string for the Eagle class wingSpan attribute.

*/

#include "Zoo.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Base

// Animal class constructor 
Animal::Animal(std::string name, int age, std::string habitat)
  : name(name), age(age), habitat(habitat){}

  // Animal class destructor
  Animal::~Animal() {}

// Formatted animal info
void Animal::displayInfo() {
  std::cout 
    << "Name: " << name << "\n"
    << "Type: "<< getAnimal() << "\n"
    << "Age: " << age << "\n"
    << "Habitat: " << habitat << "\n"
    << "Unique Attribute: " << getUnique() << "\n"
    << std::endl;
}

// Accessors
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

// Constructor
Lion::Lion(std::string name, int age, std::string habitat, std::string maneColor)
  : Animal(name, age, habitat), maneColor(maneColor) {}

// Unique attribute methods
void Lion::setManeColor(std::string color) {
  maneColor = color;
}

std::string Lion::getManeColor() {
  return maneColor;
}

std::string Lion::getUnique() {
  return "Mane Color: " + maneColor; 
}

// Animal type getter
std::string Lion::getAnimal() {
  return "Lion";
}

// Pure-vitual functions
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

// Constructor
Eagle::Eagle(std::string name, int age, std::string habitat, double wingSpan)
  : Animal(name, age, habitat), wingSpan(wingSpan) {}

// Unique attribute methods
void Eagle::setWingSpan(double span) {
  wingSpan = span;
}

double Eagle::getWingSpan() {
  return wingSpan;
}

std::string Eagle::getUnique() {

  // Creates variable stream to hold text
  std::ostringstream stream;

  // Rounds wingspan double to 2 decimal places
  stream << std::fixed << std::setprecision(2) << wingSpan;

  // Concatenates the label string with the double string
  return "Wing Span: " + stream.str() + " meters";
}

// Animal type getter
std::string Eagle::getAnimal() {
  return "Bald Eagle";
}

// Pure-virtual functions
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

// Constructor
Ibex::Ibex(std::string name, int age, std::string habitat,
    std::string species) : Animal(name, age, habitat), species(species) {}

// Unique attribute methods
void Ibex::setSpecies(std::string type) {
  species = type;
}

std::string Ibex::getSpecies() {
  return species;
}

std::string Ibex::getUnique() {
  return "Species: " + species;
}

// Animal type getter
std::string Ibex::getAnimal() {
  return "Ibex";
}

// Pure-virtual methods
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

// Constructor
SnowLeopard::SnowLeopard(std::string name, int age, std::string habitat,
    std::string nickname) : Animal(name, age, habitat), nickname(nickname) {}

// Unique attribute methods
void SnowLeopard::setNickname(std::string phrase) {
  nickname = phrase;
}

std::string SnowLeopard::getNickname() {
  return nickname;
}

std::string SnowLeopard::getUnique() {
  return "Nickname: " + nickname;
}

// Animal type getter
std::string SnowLeopard::getAnimal() {
  return "Snow Leopard";
}

// Pure-virtual methods
void SnowLeopard::speak() {
  std::cout << "Vocabulary: Growl, Hiss, Prusten" << std::endl;
}

void SnowLeopard::move() {
  std::cout << "Movement style: Climb/Leap" << std::endl;
}

void SnowLeopard::diet() {
  std::cout << "Diet: Carnivore - Wild sheep/Ibex" << std::endl;
}
    
// Zoo manager class

// Adds new animal objects to animal vector
void Zoo::addAnimal(Animal* a) {
  animals.push_back(a);
}

// Formatted output for daily show method
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

    // Calls pure-virtual methods
    a->speak();
    a->move();
    a->diet();
  }
}

// Prints info for all animal vector objects
void Zoo::displayAllInfo() {

  std::cout << "\n=== Animal Information ===\n" << std::endl;
  for (Animal* a : animals) {
    a->displayInfo();
  }
}

// Zoo class destructor
Zoo::~Zoo() {
  for (Animal* a : animals) {
    delete a;
  }
}


