#include <yaml-cpp/yaml.h>
#include "Person.hpp"

namespace YAML {
    template<>
    struct convert<Person> {
        // Encoding is optional, but included for completeness
        static Node encode(const Person& person) {
            Node node;
            node["age"] = person.age;
            node["height"] = person.height;
            return node;
        }

        // Decoding: we need to handle the nested structure
        static bool decode(const Node& node, Person& person) {
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
