#include <iostream>
#include <vector>

class Visitor;

class Item {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Item() = default;
};

class Visitor {
public:
    virtual void visitItem1(class Item1* item) = 0;
    virtual void visitItem2(class Item2* item) = 0;
    virtual ~Visitor() = default;
};

class Item1 : public Item {
public:
    void accept(Visitor& visitor) override {
        visitor.visitItem1(this);
    }
    void specificOperation1() {
        std::cout << "Item 1" << std::endl;
    }
};

class Item2 : public Item {
public:
    void accept(Visitor& visitor) override {
        visitor.visitItem2(this);
    }
    void specificOperation2() {
        std::cout << "Item 2" << std::endl;
    }
};

class ConcreteVisitor : public Visitor {
public:
    void visitItem1(Item1* item) override {
        item->specificOperation1();
    }
    void visitItem2(Item2* item) override {
        item->specificOperation2();
    }
};

int main() {
    Item1 item1;
    Item2 item2;
    ConcreteVisitor visitor;

    item1.accept(visitor);
    item2.accept(visitor);

    return 0;
}
