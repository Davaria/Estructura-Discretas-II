#include <iostream>
// librerias para generar numeros aleatorios
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <stdbool.h>

using namespace std;

// Represente dicho grafo mediante una matriz de adyecencia y visualice dicho grafo
void Matriz();
void printMatrix(int **, int, int);
void printDot(int **, int, int);
int **matriz, rows, columns;

int main()
{
  Matriz();
  printMatrix(matriz, rows, columns);
  printDot(matriz, rows, columns);
  for (int i = 0; i < rows; i++)
    delete[] matriz[i];
  delete[] matriz;

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

  system("dot -Tpng ./graph.dot -o graph.png");
}