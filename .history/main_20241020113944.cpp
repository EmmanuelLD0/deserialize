#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>
#include <map>

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
