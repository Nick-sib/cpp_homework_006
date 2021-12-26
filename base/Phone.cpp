#include <iostream>
#include "Phone.h"
#include "Device.h"
#include "Technics.h"

using namespace std;

Phone::Phone(int id, int _batteryLife, const char* vendor, float price): 
    Device(_batteryLife), Technics(id, "Phone", vendor, price){}

void Phone::ShowSpec(){
    cout << "PHONE: " << dataId << endl
        << "      name: " << name << endl
        << "    vendor: " << vendor << endl
        << "batteryLife: " << _batteryLife << " hours\n"
        << "     price: " << price << "$" << endl;
}    