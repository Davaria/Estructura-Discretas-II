#include <iostream>
#include <fstream>

using namespace std;
struct nodo
{
  int nro;
  struct nodo *izq, *der;
}

;
typedef struct nodo *ArbolBinario;

ArbolBinario crearNodo(int x)
{
  ArbolBinario nuevoNodo = new (struct nodo);
  nuevoNodo->nro = x;
  nuevoNodo->izq = NULL;
  nuevoNodo->der = NULL;
  return nuevoNodo;
}

void insertar(ArbolBinario &arbol, int x)
{
  if (arbol == NULL)
    arbol = crearNodo(x);
  else if (x < arbol->nro)
    insertar(arbol->izq, x);
  else if (x > arbol->nro)
    insertar(arbol->der, x);
}
void preOrden(ArbolBinario arbol)
{
  if (arbol != NULL)
  {
    cout << arbol->nro << " ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}

// void printDot(int **M, int rows, int columns)
// {
//     ofstream file;
//     file.open("graphComplement.dot");
//     file << "graph A {" << endl;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = i; j < columns; j++)
//         {
//             if (M[i][j] == 1)
//                 file << "\t" << i + 1 << "--" << j + 1 << ";" << endl;
//         }
//     }
//     file << "}" << endl;
//     file.close();

//     system("dot -Tpng ./graphComplement.dot -o graphComplement.png");
// }

void enOrden(ArbolBinario arbol)
{
  ofstream file;
  file.open("graphComplement.dot");
  if (arbol != NULL)
  {
    enOrden(arbol->izq);
    cout << arbol->nro << " ";
    file << arbol->nro << " ";
    enOrden(arbol->der);
  }
}
void postOrden(ArbolBinario arbol)
{
  if (arbol != NULL)
  {
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->nro << " ";
  }
}
int main()
{
  ArbolBinario arbol = NULL;
  cout << "\n ...EJEMPLO DE ARBOL BINARIO...  \n";
  // 1 4 7 8 14 17 19 20 22 25 27 28 31
  insertar(arbol, 14);
  insertar(arbol, 8);
  insertar(arbol, 4);
  insertar(arbol, 1);
  insertar(arbol, 7);
  insertar(arbol, 25);
  insertar(arbol, 20);
  insertar(arbol, 17);
  insertar(arbol, 22);
  insertar(arbol, 27);
  insertar(arbol, 31);
  insertar(arbol, 28);
  cout << "\nRecorridos del ArbolBinario\n";
  cout << "\nEn orden   :  ";
  enOrden(arbol);
  cout << "\nPre Orden  :  ";
  preOrden(arbol);
  cout << "\nPost Orden :  ";
  postOrden(arbol);
  cout << endl
       << endl;
  return 0;
}