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

    // Pure-Virtual Functions
    virtual void speak() = 0;
    virtual void move() = 0;
    virtual void diet() = 0;

    // Pure-Virtual Accessors
    virtual std::string getAnimal() = 0;
    virtual std::string getUnique() = 0;

    // Non-virtual - Same for all classes
    void displayInfo();

    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getHabitat() const;

};

// Lion

class Lion : public Animal {
  private:
    std::string maneColor;

  public:
    Lion(std::string name, int age, std::string habitat,
        std::string maneColor);

    std::string getManeColor();
    void setManeColor(std::string color);

    void speak() override;
    void move() override;
    void diet() override;

    std::string getAnimal() override;
    std::string getUnique() override;
};

// Eagle

class Eagle : public Animal {
  private:
    double wingSpan;
  public:
    Eagle(std::string name, int age,
        std::string habitat, double wingSpan);
    
    double getWingSpan();
    void setWingSpan(double wingSpan);

    void speak() override;
    void move() override;
    void diet() override;
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Ibex

class Ibex : public Animal {
  private:
    std::string species;
  public:
    Ibex(std::string name, int age,
        std::string habitat, std::string species);

    std::string getSpecies();
    void setSpecies(std::string species);

    void speak() override;
    void move() override;
    void diet() override;
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Snow Leopard

class SnowLeopard : public Animal {
  private:
    std::string nickname;
  public:
    SnowLeopard(std::string name, int age, std::string habitat,
        std::string nickname);

    std::string getNickname();
    void setNickname(std::string nickname);

    void speak() override;
    void move() override;
    void diet() override;
    std::string getAnimal() override;
    std::string getUnique() override;
};

// Zoo

class Zoo {
  private:
    std::vector<Animal*> animals;

  public:
    void addAnimal(Animal* a);
    void dailyShow();
    void displayAllInfo();
    ~Zoo();
};

#endif
