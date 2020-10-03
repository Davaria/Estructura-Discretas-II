#include "Graph.h"

Graph::~Graph()
{
  for (int i = 0; i < rows; i++)
    delete[] matriz[i];
  delete[] matriz;
}

Graph::Graph()
{
  cols = rows = 0;
  this->isEmpty();
}

void Graph::setColumnsAndRows(int value)
{
  cols = rows = value;
  matriz = new int *[cols];
  for (int i = 0; i < cols; i++)
  {
    matriz[i] = new int[cols];
  }

  ifstream ma;
  ma.open("matriz.txt");

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      ma >> matriz[i][j];
    }
  }
  ma.close();
}

void Graph::print()
{
  cout << "Imprimiendo matriz" << endl;
  cout << "  ";
  for (size_t i = 0; i < rows; i++)
    cout << i + 1 << " ";
  cout << endl;

  for (int i = 0; i < rows; i++)
  {
    cout << i + 1 << " ";
    for (int j = 0; j < cols; j++)
      cout << matriz[i][j] << " ";
    cout << endl;
  }
}

void Graph::printDot()
{
  ofstream file;
  file.open("graph.dot");
  file << "graph A {" << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = i; j < cols; j++)
    {
      if (matriz[i][j] == 1)
        file << "\t" << i + 1 << "--" << j + 1 << ";" << endl;
    }
  }
  file << "}" << endl;
  file.close();

  system("dot -Tpng ./graph.dot -o graph.png");
}

void Graph::insertEdge(int v1, int v2)
{
  cout << "Añadiendo una nueva arista" << endl;
  ofstream file;
  file.open("newEdgeInsert.txt");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i + 1 == v1 && j + 1 == v2)
        file << "1 ";
      else if (i + 1 == v2 && j + 1 == v1)
        file << "1 ";
      else
        file << matriz[i][j] << " ";
    }
    file << endl;
  }
  file.close();
}

void Graph::insertVertex(int v)
{
  cout << "Ingresando un nuevo vertice" << endl;
  int newCR = v + 1;
  ofstream file;
  file.open("newInsertVertex.txt");
  for (int i = 0; i < newCR; i++)
  {
    for (int j = 0; j < newCR; j++)
    {
      if (i + 1 == newCR || j + 1 == newCR)
        file << "0 ";
      else
        file << matriz[i][j] << " ";
    }
    file << endl;
  }
  file.close();
}

void Graph::printEdge()
{
  cout << "IMPRIMIENDO LA ARISTA" << endl;
  int **newMatriz = new int *[rows];
  for (int i = 0; i < rows; i++)
    newMatriz[i] = new int[cols];

  ifstream fe;
  fe.open("newInsertVertex.txt");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      fe >> *(*(newMatriz + i) + j);
  }
  fe.close();

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      cout << *(*(newMatriz + i) + j) << "  ";
    cout << endl;
  }
}

void Graph::removeVertex(int v1)
{
  cout << "Vertice removido" << endl;
  for (int i = v1 - 1; i < rows - 1; i++)
  {
    for (int j = 0; j < cols; j++)
      matriz[i][j] = matriz[i + 1][j];
  }
  for (int i = 0; i < rows - 1; i++)
  {
    for (int j = v1 - 1; j < cols - 1; j++)
      matriz[i][j] = matriz[i][j + 1];
  }
  for (int i = 0; i < rows - 1; i++)
  {
    for (int j = 0; j < cols - 1; j++)
      matriz[i][j] = matriz[i][j];
  }

  cout << "Matriz con vertice eliminado " << v1 << " es : " << endl;
  for (int i = 0; i < rows - 1; i++)
  {
    for (int j = 0; j < cols - 1; j++)
    {
      cout << matriz[i][j] << "  ";
    }
    cout << endl;
  }
}

void Graph::removeEdge(int v1, int v2)
{
  cout << "Arista removido" << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i + 1 == v1 && j + 1 == v2)
        cout << "0  ";
      else if (i + 1 == v2 && j + 1 == v1)
        cout << "0  ";
      else
        cout << matriz[i][j] << "  ";
    }
    cout << endl;
  }
}

void Graph::isEmpty()
{
  bool empty;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matriz[i][j])
        empty = true;
    }
  }
  if (empty)
    cout << "No es un grafo vacio" << endl;
  else
    cout << "Es un grafo vacio" << endl;
}

void Graph::adjency(int v1)
{
  cout << "Los vertices adyacentes a  " << v1 << " son " << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i + 1 == v1)
      {
        if (matriz[i][j] == 1)
        {
          cout << "\t"
               << "El vertice " << v1 << " es adyacente con el vertice " << j + 1 << endl;
        }
      }
    }
    cout << endl;
  }
}