#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>
#include <map>
#include "Person.hpp"

int main() {
    try {
        // Load the YAML file
        YAML::Node root = YAML::LoadFile("person.yaml");

        // Iterate over each person (key-value pair)
        for (YAML::const_iterator it = root.begin(); it != root.end(); ++it) {
            Person person;

            // Assign the person's name from the key
            person.name = it->first.as<std::string>();
            it->second.as<Person>(person);

            // Deserialize the nested 'Person' attributes (age, height)
            // if (!it->second.as<Person>(person)) {
                // std::cerr << "Error deserializing person: " << person.name << std::endl;
                // continue;
            // }

            // Print the deserialized data
            person.print();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
