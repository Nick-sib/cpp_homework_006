#pragma once
#include "Appliances.h"
#include "Technics.h"

class Mixer: public Appliances, Technics
{   
public:
    Mixer(int id, int weight, const char* vendor, float price);
    void ShowSpec() override;
};
