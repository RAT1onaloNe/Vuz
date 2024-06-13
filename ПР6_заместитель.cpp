#include <iostream>
#include <memory>

// Abstract Subject
class Subject {
public:
    virtual void request() = 0;
    virtual ~Subject() = default;
};

// Real Subject
class Handler : public Subject {
public:
    void request() override {
        std::cout << "Handler: Processing request..." << std::endl;
    }
};

// Proxy
class Proxy : public Subject {
private:
    std::unique_ptr<Handler> handler;
public:
    void request() override {
        if (!handler) {
            handler = std::make_unique<Handler>();
        }
        std::cout << "Proxy: Actions before processing request" << std::endl;
        handler->request();
        std::cout << "Proxy: Additional actions after processing request" << std::endl;
    }
};

// Main
int main() {
    Proxy proxy;
    proxy.request();
    return 0;
}