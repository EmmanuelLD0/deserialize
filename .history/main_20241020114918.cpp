// main.cpp

#include <yaml-cpp/yaml.h>
#include <iostream>
#include "Person.hpp"

int main() {
    try {
        // Load the YAML file
        YAML::Node root = YAML::LoadFile("person.yaml");

        // Iterate over each person (key-value pair)
        for (YAML::const_iterator it = root.begin(); it != root.end(); ++it) {
            Person person;

            // Set the person's name from the key
            person.setName(it->first.as<std::string>());

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
