#include <iostream>
#include "Mixer.h"
#include "Appliances.h"
#include "Technics.h"

using namespace std;

Mixer::Mixer(int id, int weight, const char* vendor, float price): 
    Appliances(weight), Technics(id, "Mixer", vendor, price){}

void Mixer::ShowSpec(){
    cout << "MIXER: " << dataId << endl
        << "      name: " << name << endl
        << "    vendor: " << vendor << endl
        << "    weight: " << _weight << "kg\n"
        << "     price: " << price << "$" << endl;
}    