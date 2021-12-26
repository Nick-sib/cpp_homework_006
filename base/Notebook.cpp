#include <iostream>
#include "Notebook.h"
#include "Device.h"
#include "Technics.h"

using namespace std;

Notebook::Notebook(int id, int _batteryLife, const char* vendor, float price): 
    Device(_batteryLife), Technics(id, "NoteBook", vendor, price){}

void Notebook::ShowSpec(){
    cout << "NOTEBOOK: " << dataId << endl
        << "      name: " << name << endl
        << "    vendor: " << vendor << endl
        << "batteryLife: " << _batteryLife << " hours\n"
        << "     price: " << price << "$" << endl;
}    