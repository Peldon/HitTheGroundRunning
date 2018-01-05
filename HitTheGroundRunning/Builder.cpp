#include "Builder.h"
#include <iostream> // string
#include <vector>
#include <memory> // unique_ptr
#include <sstream> // ostringstream

struct HtmlBuilder;

class HtmlElement {
public:
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement(){}
    HtmlElement(const std::string &name, const std::string &text ) : name(name), text(text) {}

    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << '\n';
        if (text.size() > 0) {
            oss << std::string(indent_size*(indent + 1), ' ') << text << '\n';
        }
        for (const auto & e : elements) {
            oss << e.str(indent + 1);
        }

        oss << i << "</" << name << ">" << '\n';
        return oss.str();
    }

    static std::unique_ptr<HtmlBuilder> build(std::string root_name) {
        return std::make_unique<HtmlBuilder>(root_name);
    }
};


struct HtmlBuilder {

    HtmlElement root;

    HtmlBuilder(std::string root_name) {
        root.name = root_name;
    }

    HtmlBuilder& add_child(std::string child_name, std::string child_text) {
        HtmlElement e{ child_name, child_text };
        root.elements.emplace_back(e);
        return *this;
    }
    
    std::string str() { return root.str(); }

    operator HtmlElement() const { return root; }

};


int Builder::RunExample() {
    std::cout << "### Builder Example:" << std::endl;

    HtmlElement e = HtmlElement::build("ul")
        ->add_child("li", "hello").add_child("li", "world");
    std::cout << e.str() << std::endl;

    return 0;
}