#include <iostream>
#include "Graph.cpp"
using namespace std;

void menu();

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

void menu()
{
    Graph grafo;
    int rowsColumns{0};
    // cout << "Ingresa el numero de filas y columnas: ";
    // cin >> rowsColumns;
    rowsColumns = 5;
    grafo.setColumnsAndRows(rowsColumns);
    grafo.print();
    grafo.printDot();
    grafo.insertVertex(rowsColumns);
    int v1{0}, v2{0};
    cout << "Ingresar coordenadas para agregar una arista : ";
    cin >> v1 >> v2;
    grafo.insertEdge(v1, v2);
    grafo.printEdge();
    cout << "Ingresar el vertice :";
    cin >> v1;
    grafo.removeVertex(v1);
    cout << "Ingresar vertices : ";
    cin >> v1 >> v2;
    grafo.removeEdge(v1, v2);
    cout << "Ingresar vertice : ";
    cin >> v1;
    grafo.adjency(v1);
}