#include "Adapter.h"

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>

class String {
    std::string s;

public:
    String(const std::string &s) : s(s) {}

    String to_lower_copy() const {
        return { boost::to_lower_copy(s) };
    }

    std::vector<String> split(const std::string & delimiter = "") const {
        std::vector<std::string> parts;
        boost::split(parts, s, boost::is_any_of(delimiter), boost::token_compress_on);
        return std::vector<String>(parts.begin(), parts.end());
    }

    size_t get_length() {
        return s.length();
    }
};


int Adapter::RunExample() {
    std::cout << "### Adapter Example:" << std::endl;

    String s{ "Hello     world!" };

    for (auto& word : s.to_lower_copy().split()) {
        std::cout << word.get_length() << std::endl;
    }

    return 0;
}
