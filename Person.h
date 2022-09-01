#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person{
public:
  Person();
  virtual ~Person();
  Person(string name);
  string getName();
private:
  string m_name;

};

#endif
