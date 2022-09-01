#ifndef DOG_H
#define DOG_H

#include "Person.h"
#include <iostream>
using namespace std;

class Dog{
public:
  Dog();
  Dog(string n, int a, string ownerName);
  virtual ~Dog();
  void speak();
  string getName();
  int getAge();
  void setName(string n);
  void setAge(int a);
private:
  string m_name;
  int m_age;
  Person* m_owner;

};

#endif
