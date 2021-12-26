#pragma once

class Technics
{
protected:
    int dataId;
    const char* name;
    const char* vendor;
    float price;
public:    
    Technics(int _id, const char* _name, const char* _vendor, float _price);
    ~Technics();
};