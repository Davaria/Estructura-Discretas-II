#include <iostream>
// librerias para generar numeros aleatorios
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <stdbool.h>

using namespace std;

void Matriz();
void printMatrix(int **, int, int);
void subMatriz();
void printDot(int **, int, int);
void complement(int **, int, int);
void isSubGraph();
int **matriz, rows, columns;
int **submatriz, subRows, subColumns;

int main()
{
    subMatriz();
    Matriz();
    printMatrix(matriz, rows, columns);
    printMatrix(submatriz, subRows, subColumns);
    printDot(submatriz, subRows, subColumns);
    isSubGraph();

    for (int i = 0; i < rows; i++)
        delete[] matriz[i];
    delete[] matriz;

    for (int i = 0; i < subRows; i++)
        delete[] submatriz[i];
    delete[] submatriz;
    return 0;
}

void Matriz()
{
    rows = columns = 5;
    //reservar memoria para la matriz
    matriz = new int *[rows];
    for (int i = 0; i < rows; i++)
        matriz[i] = new int[columns];

    ifstream file;
    file.open("./matriz.txt");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            file >> matriz[i][j];
    file.close();
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
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void printDot(int **M, int rows, int columns)
{
    ofstream file;
    file.open("graph.dot");
    // file.open("subgraph.dot");
    file << "graph A {" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < columns; j++)
        {
            if (M[i][j] == 1)
                file << "\t" << i + 1 << "--" << j + 1 << ";" << endl;
        }
    }
    file << "}" << endl;
    file.close();

    // system("dot -Tpng ./subgraph.dot -o subgraph.png");
    system("dot -Tpng ./graph.dot -o graph.png");
    // system("nohup display matriz.png &");
}

void complement(int **M, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (M[i][j] == 0)
                M[i][j] = 1;
            else
                M[i][j] = 0;
        }
        M[i][i] = 0;
    }

    ofstream file;
    file.open("graphComplement.txt");
    for (size_t i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            file << matriz[i][j] << " ";
        file << endl;
    }
    file.close();
}

void subMatriz()
{
    // srand(time(NULL));
    // // Numero aleatorios entre 2 y 5
    // subRows = subColumns = 1 + rand() % (6);
    // //reservar memoria para la matriz
    // submatriz = new int *[subRows];
    // for (int i = 0; i < subRows; i++)
    //     submatriz[i] = new int[subColumns];

    // for (size_t i = 0; i < subRows; i++)
    // {
    //     for (size_t j = i; j < subColumns; j++)
    //     {
    //         if (rand() % 2 == 1)
    //         {
    //             submatriz[i][j] = 1;
    //             submatriz[j][i] = 1;
    //         }
    //     }
    //     submatriz[i][i] = 0;
    // }

    // ifstream file;
    // file.open("./submatriz.txt");
    // for (int i = 0; i < rows; i++)
    //     for (int j = 0; j < columns; j++)
    //         file >> submatriz[i][j];
    // file.close();
    subRows = subColumns = 3;
    //reservar memoria para la matriz
    submatriz = new int *[subRows];
    for (int i = 0; i < subRows; i++)
        submatriz[i] = new int[subColumns];

    ifstream file;
    file.open("./submatriz.txt");
    for (int i = 0; i < subRows; i++)
        for (int j = 0; j < subColumns; j++)
            file >> submatriz[i][j];
    file.close();
}

void isSubGraph()
{
    bool condition;
    for (size_t i = 0; i < subRows; i++)
    {
        for (size_t j = 0; j < subColumns; j++)
        {
            if (matriz[i][j] == submatriz[i][j])
                condition = true;
            else
            {
                condition = false;
                break;
            }
        }
        if (condition == false)
        {
            break;
        }
    }

    if (condition)
        cout << "Si es un subgrafo" << endl;
    else
        cout << "No es un subgrafo" << endl;
}
