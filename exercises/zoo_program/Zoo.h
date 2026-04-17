/*

File: Zoo.h
Date: 4/16/2026

Description:
  Header file - Declares signatures for base and derived classes,
  and all class variables and methods.

*/

#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <iostream>
#include <vector>


// Base

class Animal {
  protected:
    std::string name;
    int age;
    std::string habitat;

  public:
    // Constructors    
    Animal(std::string n, int a, std::string h);

    // Destructor
    virtual ~Animal();

    // Pure-virtual Functions
    virtual void speak() = 0;
    virtual void move() = 0;
    virtual void diet() = 0;

    // Pure-virtual Accessors
    virtual std::string getAnimal() = 0;
    virtual std::string getUnique() = 0;

    // Non-virtual function
    void displayInfo();

    // Non-virtual accessors - Constant
    std::string getName() const;
    int getAge() const;
    std::string getHabitat() const;

};

// Lion

class Lion : public Animal {

  // Class specific attribute
  private:
    std::string maneColor;

    
  public:

    // Constructor
    Lion(std::string name, int age, std::string habitat,
        std::string maneColor);

    // Class specific methods
    std::string getManeColor();
    void setManeColor(std::string color);

    // Pure-virtual functions
    void speak() override;
    void move() override;
    void diet() override;

    // Pure-virtual accessors
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Eagle

class Eagle : public Animal {

  // Class specific attribute
  private:
    double wingSpan;

  public:

    // Constructor
    Eagle(std::string name, int age,
        std::string habitat, double wingSpan);
    
    // Class specific methods
    double getWingSpan();
    void setWingSpan(double wingSpan);

    // Pure-virtual functions
    void speak() override;
    void move() override;
    void diet() override;

    // Pure-virtual accessors
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Ibex

class Ibex : public Animal {

  // Class specific attribute
  private:
    std::string species;

  public:

    // Constructor
    Ibex(std::string name, int age,
        std::string habitat, std::string species);

    // Class specific methods
    std::string getSpecies();
    void setSpecies(std::string species);

    // Pure-virtual functions
    void speak() override;
    void move() override;
    void diet() override;

    // Pure-virtual accessors
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Snow Leopard

class SnowLeopard : public Animal {

  // Class specific attribute
  private:
    std::string nickname;

  public:

    // Constructor
    SnowLeopard(std::string name, int age, std::string habitat,
        std::string nickname);

    // Class specific methods
    std::string getNickname();
    void setNickname(std::string nickname);

    // Pure-virtual methods
    void speak() override;
    void move() override;
    void diet() override;

    // Pure-virtual accessors
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Zoo

class Zoo {

  private:
    // Vector of animal objects pointing to base class
    std::vector<Animal*> animals;

  public:

    // Member functions
    void addAnimal(Animal* a);
    void dailyShow();
    void displayAllInfo();
    ~Zoo();
};

#endif
