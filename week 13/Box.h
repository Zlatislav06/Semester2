#pragma once
#include "Item.h"
template <typename T>
concept Comparable = requires(T a, T b) {
    a <=> b;
};

template <Comparable T>
class Box {
protected:
    std::vector<T> items;

public:
    Box();

    virtual void addItem(const T& item);

    void removeItem(size_t index);

    void print() const;
};

