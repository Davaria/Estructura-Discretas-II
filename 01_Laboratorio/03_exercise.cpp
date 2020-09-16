#include <iostream>
#include <time.h>
using namespace std;

static int matriz[3][3];

void input_data();
void show();
void exchange();
void principal();
void secondary();

int main()
{
    input_data();

    int option;

    for (;;)
    {
        int status{0};

        cout << "1. Leer Datos " << endl;
        cout << "2. Modificar Datos " << endl;
        cout << "3. Mostrar Datos " << endl;
        cout << "4. Mostrar la suma de la diagonal principal " << endl;
        cout << "5. Mostrar la suma de la diagonal secundaria " << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion escogida : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << endl;
            show();
            cout << endl;
            break;
        case 2:
            cout << endl;
            exchange();
            cout << endl;
            break;
        case 3:
            cout << endl;
            show();
            cout << endl;
            break;
        case 4:
            cout << endl;
            principal();
            cout << endl;
            break;
        case 5:
            cout << endl;
            secondary();
            cout << endl;
            break;
        case 6:
            cout << "Desea culminar el programa ¿?" << endl;
            cout << "(1) -> Si" << endl;
            cout << "(2) -> No" << endl;
            cin >> status;
            if (status == 1)
                return 0;
            else
                return main();
            break;
        default:
            cout << "Opcion incorrecta " << endl;
            return main();
            break;
        }
    }

    return 0;
}

void input_data()
{
    int number;
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            number = 1 * rand() % (10 - 1);
            matriz[i][j] = number;
        }
    }
}

void show()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

void exchange()
{
    int fila, columna, nuevo;
    cout << "Ingrese la columna y la fila para hacer el cambio correspondiente: " << endl;
    cout << "Fila: ";
    cin >> fila;
    cout << "Columna: ";
    cin >> columna;

    cout << "Ingrese un nuevo valor: ";
    cin >> nuevo;

    matriz[fila][columna] = nuevo;
}

void principal()
{
    int suma = 0;
    for (int i = 0; i < 3; i++)
        suma = suma + matriz[i][i];
    cout << "La suma de la diagonal principal es: " << suma << endl;
}

void secondary()
{
    int suma = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i + j == 2)
                suma = suma + matriz[i][j];
        }
    }
    cout << "La suma de la diagonal secundaria es: " << suma << endl;
}
