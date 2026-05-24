#pragma once
#include "Box.h"


template <Comparable T>
class SortBox : public Box<T>
{
public:
    void addItem(const T& item) override;
};


