// Copyright 2021 GNDavydov

#include<vector>

#include <allocator.hpp>

class A {
private:
    std::size_t x_;
    std::size_t y_;
    std::size_t z_;

public:
    A(std::size_t x, std::size_t y, std::size_t z) noexcept: x_(x), y_(y), z_(z) {
        std::cout << "Construct A\n";
    }

    [[nodiscard]]std::size_t x() const noexcept { return x_; }

    [[nodiscard]]std::size_t y() const noexcept { return y_; }

    [[nodiscard]]std::size_t z() const noexcept { return z_; }

    ~A() noexcept {
        std::cout << "Destruct A\n";
    }


};

int main() {
    my_allocator::StackAllocator allocator(240);
    A *p1 = allocator.allocate<A>(4);
    A *p2 = allocator.allocate<A>(6);

    for (std::size_t i = 0; i < 4; ++i) p1[i] = A(i, i * 2, i + 5);
    for (std::size_t i = 0; i < 6; ++i) p2[i] = A(i + 1, i * 2 + 1, i + 6);

    for (std::size_t i = 0; i < 4; ++i) std::cout << p1[i].y() << ' ';
    for (std::size_t i = 0; i < 6; ++i) std::cout << p2[i].y() << ' ';
    std::cout << std::endl;

    allocator.deallocate<A>(p2, 6);
    allocator.deallocate<A>(p1, 4);
}