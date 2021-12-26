#include<iostream>

enum ElectronicType {
        HAIRDRYER = 1,
        MIXER = 2,
        NOTEBOOK = 3,
        PHONE = 4,
        VACUUMAIR = 5
    };

void cls();
char getChar();
void printScreen(int position);
void printElectronic(ElectronicType electronicType, int position, int weight, int batteryLife, float price, const char* vendor);