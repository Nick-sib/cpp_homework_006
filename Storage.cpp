#include <iostream>
#include "Storage.h"
#include "base/Mixer.h"
#include "base/Hairdryer.h"
#include "base/Phone.h"
#include "base/VacuumAir.h"
#include "base/Notebook.h"
#include "base/Appliances.h"
#include "base/Technics.h"
#include "base/IElectronics.h"
#include "base/Device.h"


using namespace std;

Storage::Storage(int size): _size(size)
{
    data = new IElectronics*[size];
}

Storage::~Storage()
{
    delete[] data;
}

bool Storage::AddElectronic(IElectronics* electronic)
{
    if (_size - _units < 1) return false;
    for (int i = 0; i < _size; i++)
    {
        if (!data[i]) {
            data[i] = electronic;
            _units++;
            return true;
        } 
    }
    return false;
}

bool Storage::AddMixer(int weight, const char* vendor, float price)
{
    return AddElectronic(new Mixer(_dataId++, weight, vendor, price));
}

bool Storage::AddHairdryer(int weight, const char* vendor, float price)
{
    return AddElectronic(new Hairdryer(_dataId++, weight, vendor, price));
}

bool Storage::AddPhone(int batteryLife, const char* vendor, float price)
{
    return AddElectronic(new Phone(_dataId++, batteryLife, vendor, price));
}

bool Storage::AddNotebook(int batteryLife, const char* vendor, float price)
{
    return AddElectronic(new Notebook(_dataId++, batteryLife, vendor, price));
}

bool Storage::AddVacuumAir(int batteryLife, int weight, const char* vendor, float price){    
    return AddElectronic(new VacuumAir(_dataId++, weight, batteryLife, vendor, price));
}

void Storage::Show()
{
    cout << "STORAGE:\n   SIZE = " << _size << " FREE = " << (_size - _units) << endl;
    if (_units == 0) 
    {
        cout << "storage is empty nothing there\n";
    } else 
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (data[i]) {
                data[i]->ShowSpec();
                cout << "-------------------------------------------\n";
            }     
        }
    }    
}