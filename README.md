# Allocator

## Реализация Stack Allocator

Аллокатор (англ. Allocator) или распределитель памяти в языке программирования C++ — специализированный класс,
реализующий и инкапсулирующий малозначимые (с прикладной точки зрения) детали распределения и освобождения ресурсов
компьютерной памяти.

### allocate
Выделяет блок памяти, достаточный для хранения по крайней мере некоторого указанного числа элементов.

```c++
pointer allocate(size_type count, const void* _Hint);
```

### deallocate
Освобождает указанное число объектов из памяти, начиная с заданной позиции.

```c++
void deallocate(pointer ptr, size_type count);
```

## LINKS
https://en.cppreference.com/w/cpp/memory/allocator
https://docs.microsoft.com/ru-ru/cpp/standard-library/allocator-class?view=msvc-170
https://habr.com/ru/post/505632/
https://habr.com/ru/post/274827/
https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%BB%D0%BE%D0%BA%D0%B0%D1%82%D0%BE%D1%80
