#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>

// Person class definition
class Person {
public:
    std::string name;
    int age;
    int height;

    Person() : age(0), height(0) {}

    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;
    }
};

// YAML conversion specialization for Person class
namespace YAML {
    template<>
    struct convert<Person> {
        static Node encode(const Person& person) {
            Node node;
            node["age"] = person.age;
            node["height"] = person.height;
            return node;
        }

        static bool decode(const Node& node, Person& person) {
            if (!node["Person"] || !node["Person"]["age"] || !node["Person"]["height"]) {
                return false;  // Missing required fields
            }
            person.age = node["Person"]["age"].as<int>();
            person.height = node["Person"]["height"].as<int>();
            return true;
        }
    };
}

// Main function to deserialize and print Person objects
int main() {
    try {
        // Load the YAML file
        YAML::Node root = YAML::LoadFile("person.yaml");

        // Iterate over each person (key-value pair)
        for (YAML::const_iterator it = root.begin(); it != root.end(); ++it) {
            Person person;

            // Assign the person's name from the key
            person.name = it->first.as<std::string>();

            // Deserialize the nested 'Person' attributes (age, height)
            person = it->second.as<Person>();  // Deserialize into a new Person object

            // Print the deserialized data
            person.print();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
