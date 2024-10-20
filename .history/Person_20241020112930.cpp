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
            if(!node.IsMap() || node.size() != 3)
            {
                return false;
            }

            rhs.name = node["name"].as<std::string>();
            rhs.age = node["age"].as<int>();
            rhs.height = node["height"].as<float>();
            return true;
        }
    };

}

void Person::init(const YAML::Node& node)
{

}