#ifndef PROYECTO_2_FINAL_SUMARIZAR_H
#define PROYECTO_2_FINAL_SUMARIZAR_H

//Criterio 1: country_or_area (ascendente), year (ascendente)

void criterio1(Container* container){
    auto *contador = new map<string , long long int>();
    string palabra;
    for (Map* element: *container->getElements())
        (*contador)[element->getCountry_or_area()+','+to_string(element->getYear())]+=element->getTrade_usd();
    fstream *archivo = new fstream("total_trade_by_country_year.csv", ios_base::out);
    if (archivo) {
        for(auto it = contador->begin(); it!=contador->end(); it++)
            *archivo <<it->first<<","<<it->second<<endl;
        archivo->close();
    }
}

//Criterio 2: country_or_area (ascendente), year (ascendente), flow (ascendente)

void criterio2(Container* container){
    auto* contador = new map<string, long int>();
    string palabra;
    for (auto element: *container->getElements())
        (*contador)[element->getCountry_or_area()+','+to_string(element->getYear())+','+element->getFlow()+','+element->getCommodity()]+=element->getTrade_usd();
    fstream* archivo = new fstream(" total_trade_by_country_year_flow.csv", ios_base::out);
    if (archivo) {
        for(auto it = contador->begin(); it!=contador->end(); it++)
            *archivo <<it->first<<","<<it->second<<endl;
        archivo->close();
    }
}

#endif //PROYECTO_2_SUMARIZAR_H