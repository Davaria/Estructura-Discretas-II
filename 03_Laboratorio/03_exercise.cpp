#include <iostream>
// librerias para generar numeros aleatorios
#include <stdlib.h>
#include <time.h>

using namespace std;

void Matriz();
void printMatrix(int **, int, int);
void matrizSquare(int **, int, int);

int **matriz, rows, columns;

int main()
{
    Matriz(); //preguntar al ingeniero manana
    printMatrix(matriz, rows, columns);
    matrizSquare(matriz, rows, columns);
    printMatrix(matriz, rows, columns);

    for (int i = 0; i < rows; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}

void Matriz()
{
    rows = columns = 6;

    //reservar memoria para la matriz
    matriz = new int *[rows];
    for (int i = 0; i < rows; i++)
        matriz[i] = new int[columns];

    // Definimos la matriz de adyecencia
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < columns; j++)
        {
            if (rand() % 2 == 1)
            {
                matriz[i][j] = 1;
                matriz[j][i] = 1;
            }
            else
            {

                matriz[i][j] = 0;
                matriz[j][i] = 0;
            }
        }
        matriz[i][i] = 0;
    }
}
void printMatrix(int **M, int rows, int columns)
{
    cout << "Imprimiendo matriz" << endl;

    cout << "  ";
    for (size_t i = 0; i < columns; i++)
        cout << i + 1 << " ";
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < columns; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

void matrizSquare(int **M, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        int account{0};
        for (int j = 0; j < columns; j++)
        {
            if (M[i][j] == 1)
                account++;
        }

        if (account)
            M[i][i] = account;
    }
}
