#pragma once
#include "Device.h"
#include "Technics.h"

class Notebook: public Device, Technics
{   
public:
    Notebook(int id, int _batteryLife, const char* vendor, float price);
    void ShowSpec() override;
};