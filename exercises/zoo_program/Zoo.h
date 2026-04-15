#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <iostream>
#include <vector>

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

};

class Lion : public Animal {
  private:
    std::string maneColor;

  public:
    Lion(std::string name, int age, std::string habitat, std::string maneColor);

    std::string getManeColor();
    void setManeColor(std::string color);

    void speak() override;
    void move() override;
    void diet() override;

    std::string getAnimal() override;
    std::string getUnique() override;
};

class Eagle : public Animal {
  private:
    double wingSpan;
  public:
    Eagle(std::string name, int age, std::string habitat, double wingSpan);
    
    double getWingSpan();
    void setWingSpan(double wingSpan);

    void speak() override;
    void move() override;
    void diet() override;
    std::string getAnimal() override;
    std::string getUnique() override;


};

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
