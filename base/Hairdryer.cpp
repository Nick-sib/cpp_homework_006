#include <iostream>
#include "Hairdryer.h"
#include "Appliances.h"
#include "Technics.h"

using namespace std;

Hairdryer::Hairdryer(int id, int weight, const char* vendor, float price): 
    Appliances(weight), Technics(id, "Hairdryer", vendor, price){}

void Hairdryer::ShowSpec(){
    cout << "HAIRDRYER: " << dataId << endl
        << "      name: " << name << endl
        << "    vendor: " << vendor << endl
        << "    weight: " << _weight << "kg\n"
        << "     price: " << price << "$" << endl;
}   