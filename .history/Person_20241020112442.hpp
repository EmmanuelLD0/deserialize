#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>

class Person
{
    private:
        std::string name;
        int age;
        float height;
    public:
        Person() = default;
        void print();
        void setName(std::string name);
        void setAge(int age);
        void setHeight(float height);
        void init(const YAML::Node& node);
}