#include <iostream>

class Target {
public:
    virtual void request() {
    }
    virtual ~Target() = default;
};

class SpecAdapter {
public:
    void specificRequest() {
        std::cout << "Executing specific request!" << std::endl;
    }
};

class Adapter : public Target {
private:
    SpecAdapter* adapter1;

public:
    Adapter(SpecAdapter* adapter1) : adapter1(adapter1) {}

    void request() override {
        adapter1->specificRequest();
    }
};

int main() {
    SpecAdapter* adapter1 = new SpecAdapter();
    Adapter* adapter = new Adapter(adapter1);

    adapter->request();

    delete adapter;
    delete adapter1;

    return 0;
}