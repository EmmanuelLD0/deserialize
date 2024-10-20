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

namespace YAML
{
    template<>
    struct convert<Person>
    {
        static Node encode(const Person& rhs)
        {
            Node node;
            node["age"] = rhs.age;
            node["height"] = rhs.height;
            return node;
        }

        static bool decode(const Node& node, Person& rhs)
        {
            if (!node["Person"] || !node["Person"]["age"] || !node["Person"]["height"]) {
                return false;  // Missing required fields
            }

            // Deserialize the age and height fields
            person.age = node["Person"]["age"].as<int>();
            person.height = node["Person"]["height"].as<int>();
            return true;
        }
    };

}

void Person::init(const YAML::Node& node)
{
    // call the YAML::convert specialization for Person
    if (!node.as<Person>(*this)) {
        throw std::runtime_error("Error deserializing person: " + name);
    }
}