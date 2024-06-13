#include <iostream>
#include <functional>

class Processor {
public:
    void process(std::function<void()> callback) {
        std::cout << "Processing..." << std::endl;
        callback();
        std::cout << "Processing completed." << std::endl;
    }
};

void myCallback() {
    std::cout << "Callback function called!" << std::endl;
}

int main() {
    Processor processor;
    processor.process(myCallback);
    return 0;
}