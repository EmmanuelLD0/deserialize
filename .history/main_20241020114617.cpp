#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>

// Person class definition
class Person {
public:
    std::string name;  // This will store the top-level key (e.g., "John Doe")
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
            // Check if required fields exist
            if (!node["age"] || !node["height"]) {
                return false;  // Missing required fields
            }

            // Deserialize the 'age' and 'height' fields
            person.age = node["age"].as<int>();
            person.height = node["height"].as<int>();
            return true;
        }
    };
}

int main() {
    try {
        // Load the YAML file
        YAML::Node root = YAML::LoadFile("person.yaml");

        // Iterate over each person (key-value pair)
        for (YAML::const_iterator it = root.begin(); it != root.end(); ++it) {
            Person person;

            // Assign the person's name from the key (e.g., "John Doe")
            person.name = it->first.as<std::string>();

            std::cout << "Person: " << person.name << std::endl;

            // Deserialize the nested 'Person' attributes (age, height)
            person = it->second["Person"].as<Person>();

            // Print the deserialized data
            person.print();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
