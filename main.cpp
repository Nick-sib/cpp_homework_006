#include <iostream>
#include "Storage.h"
#include "screen.h"

using namespace std;

#define LINUX

using namespace std;

const char CHAR_EXIT = (char) 27;
#ifdef LINUX 
const char CHAR_RETURN = (char) 13;
const char CHAR_DOWN = (char) 66;
const char CHAR_UP = (char) 65;
#else 
const char CHAR_RETURN = (char) 10;
const char CHAR_DOWN = (char) 80;
const char CHAR_UP = (char) 72;
#endif

enum VendorsType {
        SIMENS = 1,
        PHILIPS = 2,
        SAMSUNG = 3,
        APPLE = 4,
        LG = 5
    };


const char* getVendorName(int data) 
{
    VendorsType vendor = static_cast<VendorsType>(data);
    switch (vendor)
    {
        case SIMENS:
            return "simens";
        
        case PHILIPS:
            return "philips";

        case SAMSUNG:
            return "samsung";

        case APPLE:
            return "apple";

        case LG:
            return "lg";
        default:
            return "simens";
    }
}

void printStorage(Storage* storage)
{
    cls();
    storage->Show();
    getChar();
}

bool addElectronic(int appliancesIndex, Storage* storage)
{
    ElectronicType electronicType = static_cast<ElectronicType>(appliancesIndex);
    int weight = 0;
    int batteryLife = 0;
    float price = 0.0f;
    int step = 0;
    
    printElectronic(electronicType, step, weight, batteryLife, price, nullptr);
    switch (electronicType)
    {
    case HAIRDRYER: case MIXER:
        cin >> weight;
        step = 1;
        break;
    case NOTEBOOK: case PHONE:
        cin >> batteryLife;
        step = 1;
        break;
    case VACUUMAIR: 
        cin >> weight;
        step = 1;
        printElectronic(electronicType, step, weight, batteryLife, price, nullptr);
        cin >> batteryLife;
        step = 2;
        break;
    default:
        break;
    }
    
    printElectronic(electronicType, step, weight, batteryLife, price, nullptr);
    cin >> price;
    step = 3;
    char ipunputedChar;
    int vendorIndex = 1;
    const char* vendor;
    while (true)  {
        vendor = getVendorName(vendorIndex);
        printElectronic(electronicType, step, weight, batteryLife, price, vendor);
        
        ipunputedChar = getChar();

        switch (ipunputedChar)
        {
            case CHAR_DOWN: 
                if (vendorIndex == 5) vendorIndex = 1; else vendorIndex++;
                break;
            case CHAR_UP:
                if (vendorIndex == 1) vendorIndex = 5; else vendorIndex--; 
                break;
            case CHAR_RETURN:
                switch (electronicType)
                {
                    case HAIRDRYER:
                        return storage->AddHairdryer(weight, vendor, price);
                    case MIXER:
                        return storage->AddMixer(weight, vendor, price);
                    case NOTEBOOK:
                       return storage->AddNotebook(batteryLife, vendor, price);
                    case PHONE:
                       return storage->AddPhone(batteryLife, vendor, price); 
                    case VACUUMAIR:
                       return storage->AddVacuumAir(batteryLife, weight, vendor, price);
                }    
        }    
    }
}

int main() {
    Storage* storage = new Storage(10);
    char ipunputedChar;
    int position = 6;

    while (true)  {
        printScreen(position);
        
        ipunputedChar = getChar();
        
        switch (ipunputedChar) {
            case '0': position = 0; break;
            case '1': position = 1; break;
            case '2': position = 2; break;
            case '3': position = 3; break;
            case '4': position = 4; break;
            case '5': position = 5; break;
            case '6': position = 6; break;
            case CHAR_DOWN: 
                if (position == 6) position = 0; else position++;
                break;
            case CHAR_UP:
                if (position == 0) position = 6; else position--; 
                break;
            case CHAR_RETURN:
                switch (position) 
                {
                case 0:
                    return 0;  
                case 1: case 2: case 3: case 4: case 5:
                    if (!addElectronic(position, storage))
                    {
                        cls();
                        cout << "Склад переполнен!";
                        getChar();
                    };
                    break;     
                case 6:
                    printStorage(storage);
                    break;     
                default:
                    break;
                }
                
                break;
            default:
                break;
        }
    }

    delete storage;
    return 0;
}