#ifndef PROYECTO_2_FINAL_QUICK_HPP
#define PROYECTO_2_FINAL_QUICK_HPP

#include "container.hpp"
#include "funciones.hpp"
#include <string>

class Quick{
public:
    void sort(Container* container, int first, int end, string atr){
        int i = first;
        int j = end;
        auto p = ((*container->getElements()))[(first+end)/2];

        if (atr == "1"){
            while((*container->getElements())[i]->getTrade_usd() > p->getTrade_usd())
                i++;
            while((*container->getElements())[i]->getTrade_usd() < p->getTrade_usd())
                j--;
        } else {
            while (i <= j){
                while(comparar((*container->getElements())[i], p))
                    i++;
                while(!comparar((*container->getElements())[j], p))
                    j--;
                /*while((*container->getElements())[i]->getCountry_or_area() > p->getCountry_or_area()
                || ((*container->getElements())[i]->getCountry_or_area() == p->getCountry_or_area() && (*container->getElements())[i]->getYear() > p->getYear())
                || ((*container->getElements())[i]->getCountry_or_area() == p->getCountry_or_area() && (*container->getElements())[i]->getYear() == p->getYear()
                && (*container->getElements())[i]->getTrade_usd() > p->getTrade_usd()))
                    i++;
                while((*container->getElements())[j]->getCountry_or_area() < p->getCountry_or_area()
                      || ((*container->getElements())[j]->getCountry_or_area() == p->getCountry_or_area() && (*container->getElements())[j]->getYear() < p->getYear())
                      || ((*container->getElements())[j]->getCountry_or_area() == p->getCountry_or_area() && (*container->getElements())[j]->getYear() == p->getYear()
                          && (*container->getElements())[j]->getTrade_usd() < p->getTrade_usd()))
                    j--;*/
            }
        }
        if (i <= j){
            std::swap((*container->getElements())[i], (*container->getElements())[j]);
            i++;
            j--;
        }
        if (first < j)
            sort(container, first, j, atr);
        if (i < end)
            sort(container, i, end, atr);
    }
};
#endif //PROYECTO_2_FINAL_QUICK_HPP
