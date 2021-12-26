#pragma once
#include "Device.h"
#include "Technics.h"

class Phone: public Device, Technics
{   
public:
    Phone(int id, int _batteryLife, const char* vendor, float price);
    void ShowSpec() override;
};