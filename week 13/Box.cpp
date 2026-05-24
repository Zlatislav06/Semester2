#include "Box.h"

#include "Box.h"
#include <iostream>

template <Comparable T>
Box<T>::Box() = default;

template <Comparable T>
void Box<T>::addItem(const T& item) {
    items.push_back(item);
}

template <Comparable T>
void Box<T>::removeItem(size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
    }
}

template <Comparable T>
void Box<T>::print() const {
    for (const auto& item : items) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}


