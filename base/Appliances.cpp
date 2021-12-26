#include <iostream>
#include "Appliances.h"

using namespace std;

Appliances::Appliances(int weight): _weight(weight){}

void Appliances::ShowSpec()
{
cout << "Weight: " << _weight << endl;
}