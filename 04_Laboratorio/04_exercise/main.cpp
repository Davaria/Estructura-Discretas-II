#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Matriz();
void printMatrix(int **, int, int);
void printDot(int **, int, int);
void indidenciaMatriz(int **, int, int);

int **matriz, rows{0}, columns{0}, size{0};
// int **matrizIncidencia;
char *characterArray;

int main()
{
  Matriz();
  printMatrix(matriz, rows, columns);
  printDot(matriz, rows, columns);
  // indidenciaMatriz(matrizIncidencia, size, rows);

  for (int i = 0; i < rows; i++)
    delete[] matriz[i];

  for (int i = 0; i < size; i++)
    // delete[] matrizIncidencia[i];

    delete[] matriz;
  // delete[] matrizIncidencia;
  delete[] characterArray;
  return 0;
}

void Matriz()
{
  rows = columns = 4;
  size = ((rows * rows - 1) / 2);

  characterArray = new char[size];

  matriz = new int *[rows];
  for (int i = 0; i < rows; i++)
    matriz[i] = new int[columns];

  // matrizIncidencia = new int *[size];
  for (int i = 0; i < size; i++)
    matriz[i] = new int[rows];

  // Matriz de incidencia
  // for (int i = 0; i < size; i++)
  // {
  //   for (int j = 0; j < rows; j++)
  //     matrizIncidencia[i][j] = 0;
  // }

  // Definimos la matriz de adyecencia
  for (int i = 0; i < rows; i++)
  {
    for (int j = i; j < columns; j++)
    {
      matriz[i][j] = 1;
      matriz[j][i] = 1;
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

void printDot(int **M, int rows, int columns)
{
  // Caracter a
  char character = 97;
  ofstream file;
  file.open("graph.dot");
  file << "digraph A {" << endl;
  int account{0};
  for (int i = 0; i < rows; i++)
  {
    for (int j = i; j < columns; j++)
    {
      if (matriz[i][j])
      {
        characterArray[account++] = character;

        file << i + 1 << " -> " << j + 1 << " "
             << "[label=\"" << character++ << "\"];" << endl;
      }
    }
  }
  file << "}" << endl;
  file.close();
  system("dot -Tpng ./graph.dot -o graph.png");
}

// void indidenciaMatriz(int **M, int size, int rows)
// {
//   for (int i = 0; i < size; i++)
//   {
//     for (int j = 0; j < rows; j++)
//       cout << M[i][j];
//   }
//   cout << endl;
// }