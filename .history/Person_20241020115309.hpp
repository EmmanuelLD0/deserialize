#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>

class Person {
private:
    std::string name;
    int age;
    int height;

public:
    Person() : age(0), height(0) {}

    // Getters
    std::string getName() const;
    int getAge() const;
    int getHeight() const;

    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void setHeight(int height);

    // Print function
    void print() const;
};

namespace YAML {
    template<>
    struct convert<Person> {
        static Node encode(const Person& person);
        static bool decode(const Node& node, Person& person);
    };
}

#endif  // PERSON_HPP
