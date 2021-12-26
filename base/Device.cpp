#include <iostream>
#include "Device.h"

using namespace std;

Device::Device(int batteryLife):_batteryLife(batteryLife){}

void Device::ShowSpec() 
{
    cout << "Battery life: " << _batteryLife << endl;
}