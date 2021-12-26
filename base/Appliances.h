//household technic
#pragma once

#include "IElectronics.h"

class Appliances: virtual public IElectronics
{
protected:
    int _weight;
public:
    Appliances(int weight);
    void ShowSpec() override;
};
