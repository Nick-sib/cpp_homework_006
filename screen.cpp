#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "screen.h"

using namespace std;

#define LINUX // if OS = WINDOWS comment out this line
//#define WINDOWS // if OS = WINDOWS uncomment out this line

const string ERROR_TEXT = "error input";

void cls() {
    #ifdef WINDOWS
    system("cls");
    #else
    system("clear");
    #endif
}

char getChar() {
    #ifdef WINDOWS
    return getch();
    #else
    char result;
    system("stty raw -echo");
    result = getchar();
    system("stty -raw echo");
    return result;
    #endif
}

void printScreen(int position) {
    cls();
            
    cout << "\n   Доступные функции:\n"
        << (position == 1 ? " > " : "   ")  << " 1 - Добавить Фен\n"
        << (position == 2 ? " > " : "   ")  << " 2 - Добавить Миксер\n"
        << (position == 3 ? " > " : "   ")  << " 3 - Добавить Ноутбук\n"
        << (position == 4 ? " > " : "   ")  << " 4 - Добавить Телефон\n"
        << (position == 5 ? " > " : "   ")  << " 5 - Добавить Пылисос Air\n"
        << "-------------------------------------\n"
        << (position == 6 ? " > " : "   ")  << " 6 - Распечатать данные склада\n\n"
        << (position == 0 ? " > " : "   ") << "0 - выход\n";
}

void printAppliances(int position, int weight, float price, const char* vendor)
{
cout << (position == 0 ? " > " : "   ") << "weight (" << (position > 0 ? weight : 0) << ")\n"
     << (position == 1 ? " > " : "   ") << "price (" << (position > 1 ? price : 0) << ")\n"
     << (position == 3 ? " > " : "   ") << "vendor (" << (position == 3 ? vendor : "-") << ")\n\n";
}

void printDevice(int position, int batteryLife, float price, const char* vendor)
{
cout << (position == 0 ? " > " : "   ") << "battery life (" << (position > 0 ? batteryLife : 0) << ")\n"
     << (position == 1 ? " > " : "   ") << "price (" << (position > 2 ? price : 0) << ")\n"
     << (position == 3 ? " > " : "   ") << "vendor (" << (position == 3 ? vendor : "-") << ")\n\n";
}

void printComboElectronic(int position, int weight, int batteryLife, float price, const char* vendor)
{
cout << (position == 0 ? " > " : "   ") << "weight (" << (position > 0 ? weight : 0) << ")\n"
     << (position == 1 ? " > " : "   ") << "battery life (" << (position > 1 ? batteryLife : 0) << ")\n"
     << (position == 2 ? " > " : "   ") << "price (" << (position > 2 ? price : 0) << ")\n"
     << (position == 3 ? " > " : "   ") << "vendor (" << (position == 3 ? vendor : "-") << ")\n\n";
}

void printElectronic(ElectronicType electronicType, int position, int weight, int batteryLife, float price, const char* vendor)
{
    cls();
    cout << "INPUT DATA:\n";
    switch (electronicType)
    {
    case HAIRDRYER: case MIXER:
        printAppliances(position, weight, price, vendor);
        break;
    case NOTEBOOK: case PHONE:
        printDevice(position, batteryLife, price, vendor);
        break;
    case VACUUMAIR:
        printComboElectronic(position, weight, batteryLife, price, vendor);
        break;
    default:
        break;
    } 

}



