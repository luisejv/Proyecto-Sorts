#ifndef PROYECTO_2_FINAL_SHELL_HPP
#define PROYECTO_2_FINAL_SHELL_HPP

#include "container.hpp"
#include "funciones.hpp"
#include <string>

class Shell{
public:
    void sort(Container* container, int first, int end, string atr){
        auto n = 2;
        auto pivot = first + (end - first)/n;
        while(pivot > first){
            auto ordenados = true;
            while(ordenados){
                auto cont = 0;
                auto j = first;
                auto iter = pivot;
                while (iter != end){
                    if (atr == "1"){
                        if(((*container->getElements())[j])->getTrade_usd() < ((*container->getElements())[iter])->getTrade_usd()){
                            std::swap((*container->getElements())[j], (*container->getElements())[iter]);
                            iter++;
                            j++;
                            cont++;
                            ordenados = true;
                        } else {
                            iter++;
                            j++;
                            ordenados = false;
                            if(cont >= 1){
                                ordenados = true;
                            }
                        }
                    } else {
                        if(comparar((*container->getElements())[iter], (*container->getElements())[j])){
                            std::swap((*container->getElements())[j], (*container->getElements())[iter]);
                            iter++;
                            j++;
                            cont++;
                            ordenados = true;
                        } else {
                            iter++;
                            j++;
                            ordenados = false;
                            if(cont >= 1){
                                ordenados = true;
                            }
                        }
                    }
                }
            }
            pivot = first + (pivot-first)/n;
        }
    }
};

#endif //PROYECTO_2_FINAL_SHELL_HPP
