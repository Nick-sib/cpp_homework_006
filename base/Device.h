//portable device
#pragma once

#include "IElectronics.h"

class Device: virtual public IElectronics
{
protected:
    int _batteryLife;
public:
    Device(int batteryLife);
    virtual void ShowSpec() override;
};