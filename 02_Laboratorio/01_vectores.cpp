#include <iostream>
#include <fstream>
using namespace std;
void leer(int *V, int t)
{
    for (int i = 0; i < t; i++)
    {
        cout << "Ingrese un valor";
        cin >> V[i];
    }
}
void mostrar(int *V, int t)
{
    for (int i = 0; i < t; i++)
    {
        cout << V[i] << " ";
    }
}
int suma(int *V, int t)
{
    int s = 0;
    for (int j = 0; j < t; j++)
    {
        s = s + V[j];
    }
    return s;
}
int aprobado(int *V, int t)
{
    int s = 0;
    for (int i = 0; i < t; i++)
    {
        if (V[i] > 11)
        {
            s++;
        }
    }
    return s;
}
float promedio(int *V, int t)
{
    float supro;
    supro = (float)suma(V, t) / t;
    return (supro);
}
int mayor(int *V, int t)
{
    int may = V[0];
    for (int i = 0; i < t; i++)
    {
        if (V[i] > may)
            may = V[i];
    }
    return may;
}
//  aplicar 2 funciones
int menor(int *V, int t)
{
    int men = V[0];
    for (int i = 0; i < t; i++)
    {
        if (V[i] < men)
            men = V[i];
    }
    return men;
}

int menor(int *V, int t)
{
    int men = V[0];
    for (int i = 0; i < t; i++)
    {
        if (V[i] < men)
            men = V[i];
    }
    return men;
}

void numeros_pares(int *V, int t)
{
    for (int i = 0; i < t; i++)
    {
        if (V[i] % 2 == 0)
            cout << V[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    ifstream file;
    // ofstream
    // fo <<
    file.open("./notas.txt");

    int ta;
    cout << "Ingrese el tamaño:";
    cin >> ta;
    int *vector;
    vector = new int[ta];
    leer(vector, ta);
    cout << "Los datos ingresados fueron" << endl;
    mostrar(vector, ta);
    cout << endl
         << "La suma de los elementos ingresados es: " << suma(vector, ta) << endl;
    cout << "El promedio de sus notas es : " << promedio(vector, ta) << endl;
    cout << "el mayor de los elementos es: " << mayor(vector, ta) << endl;
    cout << "el menor de los elementos es: " << menor(vector, ta) << endl;
    cout << "Elementos: ";
    numeros_pares(vector, ta);

    return 0;
}
