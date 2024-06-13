#include <iostream>
#include <string>

// Product class
class Product {
private:
    std::string partA;
    std::string partB;
    std::string partC;

public:
    void setPartA(const std::string& partA) {
        this->partA = partA;
    }

    void setPartB(const std::string& partB) {
        this->partB = partB;
    }

    void setPartC(const std::string& partC) {
        this->partC = partC;
    }

    void show() const {
        std::cout << "Product parts: " << partA << ", " << partB << ", " << partC << std::endl;
    }
};

// Abstract Builder class
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getProduct() = 0;
    virtual ~Builder() = default;
};

// Concrete Builder class
class SomeBuilder : public Builder {
private:
    Product* product;

public:
    SomeBuilder() {
        this->product = new Product();
    }

    ~SomeBuilder() {
        delete product;
    }

    void buildPartA() override {
        product->setPartA("Part A");
    }

    void buildPartB() override {
        product->setPartB("Part B");
    }

    void buildPartC() override {
        product->setPartC("Part C");
    }

    Product* getProduct() override {
        return product;
    }
};

// Director class
class Director {
private:
    Builder* builder;

public:
    void setBuilder(Builder* builder) {
        this->builder = builder;
    }

    void construct() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

// Main function
int main() {
    SomeBuilder* builder = new SomeBuilder();
    Director director;
    director.setBuilder(builder);

    director.construct();
    Product* product = builder->getProduct();
    product->show();

    delete builder; // Note: This will also delete the product as SomeBuilder's destructor is called

    return 0;
}
