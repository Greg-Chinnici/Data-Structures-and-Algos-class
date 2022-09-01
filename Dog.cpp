#include "Dog.h"

class Dog{
private:
  string m_name;
  int m_age;
  Person* m_owner;
public:
  Dog(){
    m_name = "NoName";
    m_age = 0;
    m_owner = nullptr
  }
  Dog(string n, int a, string ownerName){
    this->m_name = n;
    this->m_age = a;
    this->m_owner = Person(ownerName)
  }
  virtual ~Dog(){
    delete Dog
  }

  void speak(){
    cout << "Dog Name: " << m_name << ", Dog Age: " << m_age << ", Owner: " << m_owner << endl;
  }
  
  string getName(){
    return this->m_name;
  }
  int getAge(){
    return this->m_age;
  }
  
  void setName(string n){
    this->m_name = n;
  }
  void setAge(int a){
    this->m_age = a;
  }

};