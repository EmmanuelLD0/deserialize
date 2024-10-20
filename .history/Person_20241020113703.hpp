#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;
    int height;

    // Constructor for initialization (optional)
    Person() : age(0), height(0) {}

    // Helper method to print the person's details
    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;
    }
};
