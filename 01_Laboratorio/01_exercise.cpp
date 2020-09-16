#include <iostream>
#include <math.h>
using namespace std;

void normalSize(int list_numbers[], int size, int conditional_up, int conditional_low)
{
    for (size_t i = 0; i < size; i++)
    {
        if (list_numbers[i] > conditional_up)
            cout << " El perro " << i << " mide " << list_numbers[i] << " mas que el limite " << conditional_up << endl;
        if (list_numbers[i] < conditional_low)
            cout << " El perro " << i << " mide " << list_numbers[i] << " menos que el limite " << conditional_low << endl;
    }
}

int main(int argc, char const *argv[])
{
    int listDogs[5] = {600, 470, 170, 430, 300};
    int account = 0;
    int length = sizeof(listDogs) / sizeof(listDogs[0]);
    int media{0}, varianza{0}, desviacion_estandar{0};

    for (size_t i = 0; i < length; i++)
        account += listDogs[i];

    media = account / length;

    cout
        << "La media es " << account / length << endl;

    // VARIANZA
    // Para calcular la Varianza, toma cada diferencia, elévala al cuadrado, y calcula la media

    account = 0;
    for (size_t i = 0; i < length; i++)
    {
        varianza += pow(listDogs[i] - media, 2);
    }

    varianza /= 5;
    cout
        << "La varianza es " << varianza << endl;

    // Y la desviacion estandar es la raíz de la Varianza

    desviacion_estandar = sqrt(varianza);

    cout
        << "La desviacion estandar es " << desviacion_estandar << endl;

    normalSize(listDogs, length, desviacion_estandar + media, media - desviacion_estandar);
    return 0;
}
