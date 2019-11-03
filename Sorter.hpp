#ifndef PROYECTO_2_FINAL_SORTER_HPP
#define PROYECTO_2_FINAL_SORTER_HPP

#include "Merge.hpp"
#include "Quick.hpp"
#include "Heap.hpp"
#include "Shell.hpp"
#include "container.hpp"
#include <string>

template <typename T>
class Sorter : private T {
public:
    void operator()(Container* container, int first, int end, std::string atr){
        this->sort(container, first, end, atr);
    }
};

#endif //PROYECTO_2_FINAL_SORTER_HPP
