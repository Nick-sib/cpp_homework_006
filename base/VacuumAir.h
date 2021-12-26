#pragma once
#include "Device.h"
#include "Technics.h"
#include "Appliances.h"

class VacuumAir: public Device, Appliances, Technics
{   
public:
    VacuumAir(int id, int batteryLife, int weight, const char* vendor, float price);
    void ShowSpec() override;
};