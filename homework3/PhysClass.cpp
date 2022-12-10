#include <iostream>
#include <string>
#include <map>

using namespace std;

class Energy
{
private:
    float energy;
public:
    static long SGS;
    static float eV;
    void setEnergy(int quantity, int type)
    {
        switch (type) {
        case 1:
            energy = quantity;
            break;
        case 2:
            energy = quantity / SGS;
            break;
        case 3:
            energy = quantity / eV;
            break;
        }
    }
    float getEnergy(int type) {
        switch (type) {
        case 1:
            return energy;
            break;
        case 2:
            return energy * SGS;
            break;
        case 3:
            return energy * eV;
            break;
        }
    }
    
};

long Energy::SGS = pow(10, 7);
float Energy::eV = 1.6;
int main()
{
    setlocale(LC_ALL, "Russian");
    int typeIn, typeOut;
    long quantity;
    cout << "Выберите, в каких единицах вы введёте энергию (1 - Дж, 2 - эрг, 3 - эВ*10^19): ";
    cin >> typeIn;
    cout << "Введите значение энергии: ";
    cin >> quantity;
    Energy energy;
    energy.setEnergy(quantity, typeIn);
    cout << "Выберите, в каких единицах вы хотите получить энергию (1 - Дж, 2 - эрг, 3 - эВ*10^19): ";
    cin >> typeOut;
    cout << "Ваш ответ: " << energy.getEnergy(typeOut);


}

