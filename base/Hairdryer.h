#pragma once
#include "Appliances.h"
#include "Technics.h"

class Hairdryer: public Appliances, Technics
{   
public:
    Hairdryer(int id, int weight, const char* vendor, float price);
    void ShowSpec() override;
};