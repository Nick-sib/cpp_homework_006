#include <iostream>
#include "VacuumAir.h"
#include "Device.h"
#include "Technics.h"
#include "Appliances.h"

using namespace std;

VacuumAir::VacuumAir(int id, int weight, int batteryLife, const char* vendor, float price): 
    Device(batteryLife), Appliances(weight), Technics(id, "Vacuum cleaner Air", vendor, price){}

void VacuumAir::ShowSpec(){
    cout << "Vacuum air: " << dataId << endl
        << "      name: " << name << endl
        << "    vendor: " << vendor << endl
        << "    weight: " << _weight << "kg\n"
        << "batteryLife: " << _batteryLife << "hours\n"
        << "     price: " << price << "$" << endl;
}    