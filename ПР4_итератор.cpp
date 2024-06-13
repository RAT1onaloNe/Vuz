#include <iostream>
#include <vector>

class Iterator {
public:
    Iterator(const std::vector<int>& container)
        : _container(container), _index(0) {}

    void next() {
        ++_index;
    }

    int value() const {
        return _container[_index];
    }

    bool hasMore() const {
        return _index < _container.size();
    }

private:
    const std::vector<int>& _container;
    size_t _index;
};

int main() {
    std::vector<int> vec = {1, 3, 32, 2};
    Iterator it(vec);

    while (it.hasMore()) {
        std::cout << it.value() << " ";
        it.next();
    }

    return 0;
}