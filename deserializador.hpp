#ifndef PROYECTO_2_FINAL_DESERIALIZADOR_H
#define PROYECTO_2_FINAL_DESERIALIZADOR_H

template <class T>
class Deserializador{
public:
    virtual T* deserializar (string cadena, char S)=0;
};

class DeserializadorMap: public Deserializador <Map>{
public:
    Map* deserializar (string cadena, char S) override{
        vector <string> campos;
        stringstream stream(cadena);
        string campo;
        while(getline(stream,campo,S)){
            if (campo == "")
                campos.push_back("0");
            else
                campos.push_back(campo);
        }
        if (campos.size() == 10){
            string country_or_area = campos[0];
            int year = stoll(campos[1]);
            long long int comm_code = stoll(campos[2]);
            string commodity = campos[3];
            string flow = campos[4];
            long long int trade_usd = stoll(campos[5]);
            long long int weight_kg = stoll(campos[6]);
            string quantity_name = campos[7];
            long long int quantity = stoll(campos[8]);
            string category = campos[9];
            return new Map(country_or_area,year,comm_code,commodity,flow,trade_usd,weight_kg,quantity_name,quantity,category);
        }
        throw logic_error("No se puede crear Map. Datos incompletos.");
    }
};

#endif //PROYECTO_2_DESERIALIZADOR_H