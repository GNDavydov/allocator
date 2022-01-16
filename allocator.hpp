// Copyright 2021 GNDavydov

#ifndef INCLUDE_ALLOCATOR_HPP_
#define INCLUDE_ALLOCATOR_HPP_

#include <iostream>

namespace my_allocator {
    class StackAllocator {
    private:
        void *begin_;
        void *used_;
        std::size_t total_size_;
        std::size_t used_size_;

    public:

        explicit StackAllocator(std::size_t total_size) : begin_(malloc(total_size)), used_(begin_), total_size_(total_size),
                                                     used_size_(0) {
            std::cout << "Create buffer\n";
        }

        template<class T>
        T *allocate(std::size_t num) {
            std::size_t size = num * sizeof(T);
            if (size > total_size_ - used_size_) throw std::bad_alloc();
            used_size_ += size;
            void *ptr(used_);
            used_ = static_cast<char *>(used_) + size;
            return static_cast<T *>(ptr);
        }

        template<class T>
        void deallocate(T *ptr, std::size_t num) {
            if (ptr + num != used_ && ptr > begin_) throw std::runtime_error("Bad pointer");
            used_ = ptr;
            used_size_ -= num * sizeof(T);
            for (std::size_t i = 0; i < num; ++i) {
                ptr->~T();
                ++ptr;
            }
        }

        ~StackAllocator() {
            free(begin_);
        }
    };
}

#endif //INCLUDE_ALLOCATOR_HPP_
