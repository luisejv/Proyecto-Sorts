#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include "container.hpp"
#include "map.hpp"
#include "Sorter.hpp"
#include "sumarizar.h"
#include "funciones.hpp"
#include <ctime>

using namespace std;

void ej1_criterio1();
void ej1_criterio2();
void ej2_criterio1();
void ej2_criterio2();

int main() {
    ej1_criterio1();
    ej1_criterio2();
    ej2_criterio1();
    ej2_criterio2();
    return 0;
}

void ej1_criterio1(){
    Container *cont = new Container("commodity_trade_statistics_data.csv");
    Container *cont2 = new Container("commodity_trade_statistics_data.csv");
    Container *cont3 = new Container("commodity_trade_statistics_data.csv");
    Container *cont4 = new Container("commodity_trade_statistics_data.csv");

    Sorter<Quick> Sort1;
    Sorter<Heap> Sort2;
    Sorter<Shell> Sort3;
    Sorter<Merge> Sort4;

    clock_t time = clock();
    double zeit;

    cout << "\nPrimer criterio - TradeUsd: " << endl;

    Sort1(cont, 0, cont->getElements()->size()-1, "1");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del quickSort es: " << zeit << " segundos" << endl;
    saveFile(cont->getElements(), "quickSort_Trade_usd.csv");

    Sort2(cont2,0,cont2->getElements()->size()-1, "1");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del heapSort es: " << zeit << " segundos" << endl;
    saveFile(cont2->getElements(), "heapSort_Trade_usd.csv");

    Sort3(cont3, 0, cont3->getElements()->size()-1, "1");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del shellSort es: " << zeit << " segundos" << endl;
    saveFile(cont3->getElements(), "shellSort_Trade_usd.csv");

    Sort4(cont4, 0, cont4->getElements()->size()-1, "1");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del mergeSort es: " << zeit << " segundos" << endl;
    saveFile(cont4->getElements(), "mergeSort_Trade_usd.csv");

    delete cont;
    delete cont2;
    delete cont3;
    delete cont4;
}

void ej1_criterio2(){
    Container *cont5 = new Container("commodity_trade_statistics_data.csv");
    Container *cont6 = new Container("commodity_trade_statistics_data.csv");
    Container *cont7 = new Container("commodity_trade_statistics_data.csv");
    Container *cont8 = new Container("commodity_trade_statistics_data.csv");

    Sorter<Quick> Sort1;
    Sorter<Heap> Sort2;
    Sorter<Shell> Sort3;
    Sorter<Merge> Sort4;

    clock_t time = clock();
    double zeit;

    cout << "\nSegundo criterio - CountryOrArea, Year, TradeUsd: " << endl;

    Sort1(cont5, 0, cont5->getElements()->size()-1, "3");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del quickSort es: " << zeit << " segundos" << endl;
    saveFile(cont5->getElements(), "quickSort_Criterio2.csv");

    Sort2(cont6, 0, cont6->getElements()->size()-1, "3");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del heapSort es: " << zeit << " segundos" << endl;
    saveFile(cont6->getElements(), "heapSort_Criterio2.csv");

    Sort3(cont7, 0, cont7->getElements()->size()-1, "3");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del shellSort es: " << zeit << " segundos" << endl;
    saveFile(cont7->getElements(), "shellSort_Criterio2.csv");

    Sort4(cont8, 0,cont8->getElements()->size() -1, "3");
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del mergeSort es: " << zeit << " segundos" << endl;
    saveFile(cont8->getElements(), "mergeSort_Criterio2.csv");

    delete cont5;
    delete cont6;
    delete cont7;
    delete cont8;
}

void ej2_criterio1(){
    Container *cont9 = new Container("commodity_trade_statistics_data.csv");
    criterio1(cont9);
    cout<<"Se guardo el archivo sumarizado.";
    delete cont9;
}

void ej2_criterio2(){
    auto cont9 = new Container("commodity_trade_statistics_data.csv");
    criterio2(cont9);
    cout<<"Se guardo el archivo sumarizado.";
    delete cont9;
}