#ifndef PROYECTO_2_FINAL_MERGE_HPP
#define PROYECTO_2_FINAL_MERGE_HPP

#include "container.hpp"
#include "funciones.hpp"
#include <string>

class Merge{
public:
    void merge(Container* container, int first, int middle, int end, string atr){
        int i, j, k;
        int n1 = middle - first + 1;
        int n2 = end - middle;
        auto L = new vector<Map*>;
        auto R = new vector<Map*>;
        for (i = 0; i < n1; i++)
            L->push_back ((*container->getElements())[first + i]);
        for (j = 0; j < n2; j++)
            R->push_back ((*container->getElements())[middle + 1+ j]);
        i = 0;
        j = 0;
        k = first;
        while (i < n1 && j < n2){
            if (atr == "1"){
                if ((*L)[i]->getTrade_usd() >= (*R)[j]->getTrade_usd()){
                    (*container->getElements())[k] = (*L)[i];
                    i++;
                } else {
                    (*container->getElements())[k] = (*R)[j];
                    j++;
                }
            } else {
                if (comparar((*L)[i], (*R)[j])){
                    (*container->getElements())[k] = (*L)[i];
                    i++;
                } else{
                    (*container->getElements())[k] = (*R)[j];
                    j++;
                }
            }
            /*if ((*L)[i]->getCountry_or_area() >= (*R)[j]->getCountry_or_area()) {
                (*container->getElements())[k] = (*L)[i];
                i++;
            }
            else if ((*L)[i]->getCountry_or_area() == (*R)[j]->getCountry_or_area()){
                if ((*L)[i]->getYear() >= (*R)[j]->getYear())
                    i++;
                else if ((*L)[i]->getYear() == (*R)[j]->getYear()){
                    if ((*L)[i]->getTrade_usd() >= (*R)[j]->getTrade_usd())
                        i++;
                }
            }
            else{
                (*container->getElements())[k] = (*R)[j];
                j++;
            }*/
            k++;
        }
        while (i < n1){
            (*container->getElements())[k] = (*L)[i];
            i++;
            k++;
        }
        while (j < n2){
            (*container->getElements())[k] = (*R)[j];
            j++;
            k++;
        }
    }
    void sort(Container* container, int first, int end, string atr){
        if (first < end){
            auto middle = first + (end - first) / 2;
            sort(container, first, middle, atr);
            sort(container, middle + 1, end, atr);
            merge(container, first, middle, end, atr);
        }
    }
};

#endif //PROYECTO_2_FINAL_MERGE_HPP
