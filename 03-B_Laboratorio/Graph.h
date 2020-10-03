#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
  int **matriz, cols, rows;

public:
  ~Graph();
  Graph();
  void setColumnsAndRows(int);
  void print();              //Imprimir matriz
  void printDot();           //Grafica de la matriz
  void insertVertex(int);    //Insertar vertice
  void insertEdge(int, int); //Insertar arista
  void printEdge();          //Imprimir arista
  void removeVertex(int);    //Remover vertice
  void removeEdge(int, int); //Remover arista
  void isEmpty();            //Es o no es un grafo vacio
  void adjency(int);         //Ver adyacentes al vertice
};

#endif