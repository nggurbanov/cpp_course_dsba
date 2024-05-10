/*
Написать код для 10 исключений (См. пример)
 * */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <cstring>
#include <memory>
#include <cmath>
#include <functional>

int main() {
    try {
        // 1. std::out_of_range
        std::vector<int> v(5);
        std::cout << v.at(10);
    } catch (const std::out_of_range&) {
        std::cout << "Exception: out_of_range\n";
    }

    try {
        // 2. std::bad_alloc
        int* p = new int[10000000000];
        delete[] p;
    } catch (const std::bad_alloc&) {
        std::cout << "Exception: bad_alloc\n";
    }

    try {
        // 3. std::bad_cast
        int x = 10;
        double y = static_cast<double>(x); // correct static_cast usage
    } catch (const std::bad_cast&) {
        std::cout << "Exception: bad_cast\n";
    }

    try {
        // 4. std::invalid_argument
        throw std::invalid_argument("Invalid argument");
    } catch (const std::invalid_argument&) {
        std::cout << "Exception: invalid_argument\n";
    }

    try {
        // 5. std::length_error
        std::vector<int> v(10);
        v.resize(20);
    } catch (const std::length_error&) {
        std::cout << "Exception: length_error\n";
    }

    try {
        // 6. std::runtime_error
        throw std::runtime_error("Runtime error");
    } catch (const std::runtime_error&) {
        std::cout << "Exception: runtime_error\n";
    }

    try {
        // 7. std::logic_error
        throw std::logic_error("Logic error");
    } catch (const std::logic_error&) {
        std::cout << "Exception: logic_error\n";
    }

    try {
        // 8. std::domain_error
        throw std::domain_error("Domain error");
    } catch (const std::domain_error&) {
        std::cout << "Exception: domain_error\n";
    }

    try {
        // 9. std::bad_function_call
        std::function<void()> f;
        f();
    } catch (const std::bad_function_call&) {
        std::cout << "Exception: bad_function_call\n";
    }

    try {
        // 10. std::bad_weak_ptr
        std::shared_ptr<int> sp(new int(10));
        std::weak_ptr<int> wp(sp);
        sp.reset();
        std::shared_ptr<int> sp2 = wp.lock();
        if (!sp2) {
            throw std::bad_weak_ptr();
        }
    } catch (const std::bad_weak_ptr&) {
        std::cout << "Exception: bad_weak_ptr\n";
    }

    return 0;
}
