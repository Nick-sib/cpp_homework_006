#include "Technics.h"

Technics::Technics(int _id, const char* _name, const char* _vendor, float _price): 
    dataId(_id),  price(_price)
{
    name = _name;
    vendor = _vendor;
}

Technics::~Technics(){
    delete[] name;
    delete[] vendor;
}