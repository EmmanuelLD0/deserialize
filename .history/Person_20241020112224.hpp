#include <string>
#include <iostream>

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
}