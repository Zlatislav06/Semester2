#include "SortBox.h"
template <Comparable T>
void SortBox<T>::addItem(const T& item)
{
    this->items.push_back(item);

    std::sort(this->items.begin(),
        this->items.end());
}

