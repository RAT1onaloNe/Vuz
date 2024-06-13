#include <iostream>
#include <fstream>
#include <string>

// Абстрактный базовый класс, определяющий скелет алгоритма
class DocumentProcessor {
public:
    // Шаблонный метод
    void processDocument(const std::string& filename) {
        openDocument(filename);
        readDocument();
        processData();
        closeDocument();
    }

    // Шаги алгоритма, которые подклассы должны реализовать
    virtual void openDocument(const std::string& filename) = 0;
    virtual void readDocument() = 0;
    virtual void closeDocument() = 0;

    // Шаг алгоритма с реализацией по умолчанию
    virtual void processData() {
        std::cout << "Обработка данных документа..." << std::endl;
    }

    // Виртуальный деструктор для обеспечения правильного уничтожения объектов подклассов
    virtual ~DocumentProcessor() {}
};

// Подкласс для обработки текстовых документов
class TextDocumentProcessor : public DocumentProcessor {
private:
    std::ifstream file;
    std::string content;

public:
    void openDocument(const std::string& filename) override {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл");
        }
        std::cout << "Текстовый документ открыт: " << filename << std::endl;
    }

    void readDocument() override {
        content.assign((std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>());
        std::cout << "Текстовый документ считан" << std::endl;
    }

    void closeDocument() override {
        if (file.is_open()) {
            file.close();
            std::cout << "Текстовый документ закрыт" << std::endl;
        }
    }
};

// Подкласс для обработки CSV документов
class CSVDocumentProcessor : public DocumentProcessor {
private:
    std::ifstream file;
    std::string content;

public:
    void openDocument(const std::string& filename) override {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл");
        }
        std::cout << "CSV документ открыт: " << filename << std::endl;
    }

    void readDocument() override {
        content.assign((std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>());
        std::cout << "CSV документ считан" << std::endl;
    }

    void closeDocument() override {
        if (file.is_open()) {
            file.close();
            std::cout << "CSV документ закрыт" << std::endl;
        }
    }

    void processData() override {
        std::cout << "Обработка данных CSV документа..." << std::endl;
    }
};

int main() {
    try {
        TextDocumentProcessor textProcessor;
        textProcessor.processDocument("example.txt");

        CSVDocumentProcessor csvProcessor;
        csvProcessor.processDocument("example.csv");
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
