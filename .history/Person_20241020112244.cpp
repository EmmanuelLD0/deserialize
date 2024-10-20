#include "Person.hpp"

void Person::print()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
}

void Person::setName(std::string name)
{
    this->name = name;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setHeight(float height)
{
    this->height = height;
}