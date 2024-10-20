#include <yaml-cpp/yaml.h>
#include <iostream>
#include "Person.hpp"

int main() {
    try {
        YAML::Node root = YAML::LoadFile("person.yaml");

        for (YAML::const_iterator it = root.begin(); it != root.end(); ++it) {
            Person person;

            person = it->second["Person"].as<Person>();
            person.setName(it->first.as<std::string>());

            person.print();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
