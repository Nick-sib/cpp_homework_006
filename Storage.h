#pragma once

#include "base/IElectronics.h"

class Storage
{
private:
    int _size;
    int _dataId = 127;
    int _units = 0;
    IElectronics** data;
public:
    Storage(int size);
    ~Storage();

    bool AddElectronic(IElectronics* electronic);
    bool AddMixer(int weight, const char* vendor, float price);
    bool AddHairdryer(int weight, const char* vendor, float price);
    bool AddPhone(int batteryLife, const char* vendor, float price);
    bool AddNotebook(int batteryLife, const char* vendor, float price);
    bool AddVacuumAir(int batteryLife, int weight, const char* vendor, float price);

    void Show();
};