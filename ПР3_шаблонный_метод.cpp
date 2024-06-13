#include <iostream>

// Абстрактный базовый класс, определяющий скелет алгоритма
class AbstractClass {
public:
    // Шаблонный метод
    void templateMethod() {
        step1();
        step2();
        step3();
    }
protected:
    // Шаги алгоритма, которые подклассы должны реализовать
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};

// Конкретный класс, реализующий шаги алгоритма
class TemplateMethodClass : public AbstractClass {
protected:
    void step1() override {
        std::cout << "Step 1" << std::endl;
    }
    void step2() override {
        std::cout << "Step 2" << std::endl;
    }
    void step3() override {
        std::cout << "Step 3" << std::endl;
    }
};

int main() {
    TemplateMethodClass templateMethod;
    templateMethod.templateMethod();
    return 0;
}
