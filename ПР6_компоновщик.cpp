#include <iostream>
#include <vector>
#include <memory>

class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() = default;
};

class Notice : public Component {
public:
    void operation() override {
        std::cout << "Notice: Performing operation." << std::endl;
    }
};

class Alpha : public Component {
private:
    std::vector<std::shared_ptr<Component>> children;
public:
    void add(std::shared_ptr<Component> component) {
        children.push_back(component);
    }

    void operation() override {
        std::cout << "Alpha: Performing operation for all child components." << std::endl;
        for (const auto& child : children) {
            child->operation();
        }
    }
};

int main() {
    std::shared_ptr<Alpha> composite = std::make_shared<Alpha>();
    composite->add(std::make_shared<Notice>());
    composite->add(std::make_shared<Notice>());
    composite->operation();
    return 0;
}