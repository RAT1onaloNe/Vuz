#include <iostream>
#include <stdexcept>

// Abstract Product A
class AbstractProductA {
public:
    virtual void methodA() = 0;
    virtual ~AbstractProductA() = default;
};

class ProductA1 : public AbstractProductA {
public:
    void methodA() override {
        std::cout << "Product 1 method A" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
public:
    void methodA() override {
        std::cout << "Product 2 method A" << std::endl;
    }
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void methodB() = 0;
    virtual ~AbstractProductB() = default;
};

class ProductB3 : public AbstractProductB {
public:
    void methodB() override {
        std::cout << "Product 3 method B" << std::endl;
    }
};

class ProductB4 : public AbstractProductB {
public:
    void methodB() override {
        std::cout << "Product 4 method B" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() = default;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ProductB3();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ProductB4();
    }
};

// Main
int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB3 = factory1->createProductB();

    productA1->methodA();
    productB3->methodB();

    delete productA1;
    delete productB3;
    delete factory1;

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB4 = factory2->createProductB();

    productA2->methodA();
    productB4->methodB();

    delete productA2;
    delete productB4;
    delete factory2;

    return 0;
}