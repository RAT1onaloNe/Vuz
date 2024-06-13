#include <iostream>
#include <vector>
#include <string>

// Forward declaration
class Colleague;

// Mediator class
class Mediator {
public:
    virtual void sendMessage(const std::string& message, Colleague* colleague) = 0;
    virtual ~Mediator() = default;
};

// Colleague class
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator = nullptr) : mediator(mediator) {}

    virtual void receiveMessage(const std::string& message) = 0;

    void sendMessage(const std::string& message) {
        if (mediator) {
            mediator->sendMessage(message, this);
        }
    }

    void setMediator(Mediator* mediator) {
        this->mediator = mediator;
    }

    virtual ~Colleague() = default;
};

// Concrete Colleague class
class SomeColleague : public Colleague {
private:
    std::string name;

public:
    SomeColleague(const std::string& name, Mediator* mediator = nullptr)
        : Colleague(mediator), name(name) {}

    void receiveMessage(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

// Concrete Mediator class
class SomeMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
        colleague->setMediator(this);
    }

    void sendMessage(const std::string& message, Colleague* colleague) override {
        for (Colleague* col : colleagues) {
            if (col != colleague) {
                col->receiveMessage(message);
            }
        }
    }
};

// Main function
int main() {
    SomeMediator* mediator = new SomeMediator();
    SomeColleague* colleague1 = new SomeColleague("User1", mediator);
    SomeColleague* colleague2 = new SomeColleague("User2", mediator);

    mediator->addColleague(colleague1);
    mediator->addColleague(colleague2);

    colleague1->sendMessage("Hi User2!");
    colleague2->sendMessage("Hello User1!");

    delete colleague1;
    delete colleague2;
    delete mediator;

    return 0;
}
