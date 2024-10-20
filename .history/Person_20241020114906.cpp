// Person.cpp

#include "Person.hpp"

// Getter methods
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

int Person::getHeight() const {
    return height;
}

// Setter methods
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setHeight(int height) {
    this->height = height;
}

// Print method
void Person::print() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;
}

// YAML conversion logic
namespace YAML {
    Node convert<Person>::encode(const Person& person) {
        Node node;
        node["age"] = person.getAge();
        node["height"] = person.getHeight();
        return node;
    }

    bool convert<Person>::decode(const Node& node, Person& person) {
        if (!node["age"] || !node["height"]) {
            return false;  // Missing required fields
        }

        person.setAge(node["age"].as<int>());
        person.setHeight(node["height"].as<int>());
        return true;
    }
}
