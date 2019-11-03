#ifndef PROYECTO_2_FINAL_HEAP_HPP
#define PROYECTO_2_FINAL_HEAP_HPP

#include "container.hpp"
#include "funciones.hpp"
#include <string>

class Heap{
public:
    void heap(Container* container, int size, int node, string atr){
        int smallest = node;
        int izq = 2*node + 1;
        int der = 2*node + 2;
        if (atr == "1"){
            if (izq < size && (*container->getElements())[izq]->getTrade_usd() <
            (*container->getElements())[smallest]->getTrade_usd())
                smallest = izq;
            if (der < size && (*container->getElements())[der]->getTrade_usd() <
            (*container->getElements())[smallest]->getTrade_usd())
                smallest = der;
        } else {
            if (izq < size && comparar((*container->getElements())[smallest], (*container->getElements())[izq]))
                smallest = izq;
            if (der < size && comparar((*container->getElements())[smallest], (*container->getElements())[der]))
                smallest = der;
        }
        if (smallest !=  node){
            std::swap((*container->getElements())[node], (*container->getElements())[smallest]);
            heap(container, size, smallest, atr);
        }
    }
    void sort(Container* container, int first, int end, string atr){
        for (int i = (end+1)/2 - 1; i >= 0; --i){
            heap(container, end+1, i, atr);
        }
        for (int i = end; i >= 0; --i){
            std::swap((*container->getElements())[0], (*container->getElements())[i]);
            heap(container, i, 0, atr);
        }
    }
};

#endif //PROYECTO_2_FINAL_HEAP_HPP
