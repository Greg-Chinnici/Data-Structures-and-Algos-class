#include "Person.h"

class Person{
private:
  string m_name;
public:
  Person(){
    m_name = "NoName";
  }
  virtual ~Person(){
    delete Person
  }
  Person(string name){
    this->m_name = name;
  }
  string getName(){
    return this->m_name;
  }
};