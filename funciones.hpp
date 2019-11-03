#ifndef PROYECTO_2_FINAL_FUNCIONES_HPP
#define PROYECTO_2_FINAL_FUNCIONES_HPP

#include "map.hpp"
#include <vector>
#include <fstream>

void saveFile (vector<Map*>* vector, string name){
    fstream* archivo = new fstream(name, ios_base::out);
    if (archivo) {
        for(auto element: *vector)
            *archivo <<element->getCountry_or_area()<<","<<element->getYear()<<","
                     <<element->getComm_code()<<","<<element->getCommodity()<<","
                     <<element->getFlow()<<","<<element->getTrade_usd()<<","
                     <<element->getWeight_kg()<<","<<element->getQuantity_name()<<","
                     <<element->getQuantity()<<","<<element->getCategory()<<endl;
        archivo->close();
    }
}

bool comparar(Map* ct1, Map* ct2){
    if ((ct1)->getCountry_or_area() > (ct2)->getCountry_or_area()){
        return true;
    }
    else if ((ct1)->getCountry_or_area() == (ct2)->getCountry_or_area()){
        if ((ct1)->getYear() > (ct2)->getYear()){
            return true;
        }
        else if ((ct1)->getYear() == (ct2)->getYear()){
            if ((ct1)->getTrade_usd() > (ct2)->getTrade_usd())
                return true;
        }
    }
    return false;
}


#endif //PROYECTO_2_FINAL_FUNCIONES_HPP
