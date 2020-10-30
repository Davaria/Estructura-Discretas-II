#include <iostream>
#include <fstream>

using namespace std;

//Esctructura del nodo
struct nodo
{
    char letra;
    int cantidad;
    struct nodo *next;
    struct nodo *izq, *der;
};

//Definicion del tipo Arbol Huffman a partir de un puntero nodo
typedef struct nodo *AHuffman;

void mostrar(AHuffman a); //Declaracion de la funcion para mostrar la lista enlazada

//Funcion para crear un nodo
AHuffman crearNodo(int x, char l)
{
    AHuffman nuevoNodo = new (struct nodo);
    nuevoNodo->cantidad = x;
    nuevoNodo->letra = l;
    nuevoNodo->next = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

//Funcion para insertar a la lista enlazada
void insertar(AHuffman &arbol, int x, char l)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(x, l);
        cout << arbol->letra << " " << arbol->cantidad << " -> ";
    }
    else
    {
        insertar(arbol->next, x, l);
    }
}

//Funcion para el intercambio de nodos
void swap(AHuffman &raiz, struct nodo *a, struct nodo *b)
{
    struct nodo *temp;
    if (a == raiz)
    {
        if (b->next != NULL)
        {
            temp = b->next;
            a->next = temp;
            b->next = a;
            raiz = b;
        }
        else
        {
            raiz = b;
            b->next = a;
            a->next = NULL;
        }
    }
    else
    {
        temp = raiz;
        while (true)
        {
            if (temp->next == a)
            {
                struct nodo *aux = b->next;
                temp->next = b;
                b->next = a;
                a->next = aux;
                break;
            }

            else
            {
                temp = temp->next;
            }
        }
    }
}

//Funcion para ordenar la lista enlazada en orden ascendente
void ordenar(AHuffman &raiz)
{
    bool cambio;
    struct nodo *temp;
    struct nodo *ultimo = NULL;

    if (raiz == NULL)
        return;

    do
    {
        cambio = false;
        temp = raiz;

        while (temp->next != ultimo)
        {
            if (temp->cantidad > temp->next->cantidad)
            {
                swap(raiz, temp, temp->next);
                cambio = true;
            }
            else
            {
                temp = temp->next;
            }
        }
        ultimo = temp;
    } while (cambio);
}

//Funcion para mostrar la lista enlazada
void mostrar(AHuffman a)
{
    cout << endl;
    struct nodo *temp = a;
    do
    {
        cout << temp->letra << " " << temp->cantidad << " -> ";
        temp = temp->next;
    } while (temp != NULL);
    cout << endl
         << endl;
}

//Funcion para mostrar el arbol de Huffman
void mostrar_Huffman(AHuffman &a)
{
    if (a == NULL)
        return;

    if (a->izq != NULL || a->der != NULL)
    {
        cout << "Nodo " << a->cantidad;
        cout << " Izq " << a->izq->letra << ":" << a->izq->cantidad << " Drc " << a->der->letra << ":" << a->der->cantidad << endl;
    }
    mostrar_Huffman(a->izq);
    mostrar_Huffman(a->der);
}

//Funcion para insertar desde un fichero al arbol de Huffman
void Huffman_insertar(AHuffman &a)
{
    string ln;
    string letras = "abcdeF";
    int cont[6];
    ifstream fe("huffman");
    while (!fe.eof())
    {
        fe >> ln;
        for (int i = 0; i < ln.size(); i++)
        {
            if (ln[i] == 'a')
                cont[0]++;

            if (ln[i] == 'b')
                cont[1]++;

            if (ln[i] == 'c')
                cont[2]++;

            if (ln[i] == 'd')
                cont[3]++;

            if (ln[i] == 'e')
                cont[4]++;

            if (ln[i] == 'F')
                cont[5]++;
        }
    }

    for (int i = 0; i < letras.size(); i++)
    {
        insertar(a, cont[i], letras[i]);
    }
}

//Funcion para construir el arbol de Huffman
void Huffman(AHuffman &a)
{
    nodo *temp1 = a;                                   //para el primer nodo
    nodo *temp2 = a->next;                             //para el segundo nodo
    nodo *temph = a;                                   // para construir un nodo padre con los 2 primeros
    int scantidad = temp1->cantidad + temp2->cantidad; //la suma de los valores de los 2 nodos

    while (a->next != NULL)
    {                                      //while hasta que solo quede un nodo
        temph = crearNodo(scantidad, ' '); //se crea el nodo padre con la suma y sin caracter
        temph->izq = temp1;                //hijo izquierdo
        temph->der = temp2;                //hijo derecho
        temph->next = temp2->next;         //el nodo padre se introduce a la lista enlazada
        // Los hijos ya no estan en la lista enlazada por lo tanto sus next deben apuntar a NULL
        temp1->next = NULL;
        temp2->next = NULL;
        a = temph;  // A la raiz se le asigna el nodo padre
        ordenar(a); //Se ordena la lista
        if (a->next != NULL)
        { //si queda 2 o mas nodos
            //se actualiza los temporales y la cantidad para un nuevo nodo padre
            temp1 = a;
            temp2 = temp1->next;
            scantidad = temp1->cantidad + temp2->cantidad;
        }
    }
    mostrar_Huffman(a);
}

//Funcion recursiva para recorrer el arbol
void recorrer(AHuffman a, char cad, string ruta, bool &t, string &res)
{
    if (a->letra == cad)
    {
        t = true;
        res = ruta;
        return;
    }

    if (a->izq && a->der)
    {
        recorrer(a->izq, cad, ruta + "0", t, res);

        if (t)
        {
            return;
        }

        recorrer(a->der, cad, ruta + "1", t, res);
    }
}

//Funcion para codificar
void Hcodificar(AHuffman a, string cad)
{
    string caracter = "abcdeF";
    int n = caracter.size();
    bool t = false;
    string res[n];

    //For para recorrer cada letra del arbol y obtener su codigo
    for (int i = 0; i < n; i++)
    {
        recorrer(a, caracter[i], "", t, res[i]);
        t = false;
        cout << caracter[i] << " : " << res[i] << endl;
    }

    string codigo;
    //For para asignar el codigo a cada letra
    for (int i = 0; i < cad.size(); i++)
    {
        if (cad[i] == 'a')
            codigo = codigo + res[0];
        if (cad[i] == 'b')
            codigo = codigo + res[1];
        if (cad[i] == 'c')
            codigo = codigo + res[2];
        if (cad[i] == 'd')
            codigo = codigo + res[3];
        if (cad[i] == 'e')
            codigo = codigo + res[4];
        if (cad[i] == 'F')
            codigo = codigo + res[5];
    }
    cout << "Clave " << cad << endl;
    cout << "Codigo " << codigo << endl;
}

//Funcion para decodificar
void Hdecodificar(AHuffman a, string cadena)
{
    nodo *temp = a;
    int i = 0;
    //While para decodifficar cada letra
    while (i < cadena.size())
    {
        //Se ejecuta mientras el nodo sea padre
        while (temp->izq != NULL && temp->der != NULL)
        {
            //Si es 0 va a la iquierda
            if (cadena[i] == '0')
            {
                temp = temp->izq;
            }
            //Si es 1 va a la derecha
            if (cadena[i] == '1')
            {
                temp = temp->der;
            }
            i++;
        }
        cout << temp->letra; //Imprime
        temp = a;            //Se actualiza el temp
    }
    cout << endl;
}

//Funcion principal
int main()
{
    AHuffman a = NULL; //Crea el arbol
    cout << endl;
    Huffman_insertar(a); //Inserta desde un fichero
    ordenar(a);          //Ordena la lista
    mostrar(a);          //Muestra la lista ordenada
    Huffman(a);          //COnstruye e imprime el arbol de Huffman

    //Para decodificar
    string cadena1 = "000";
    string cadena2 = "100011001101";
    string cadena3 = "110001001101";

    cout << endl
         << "Decodificar" << endl;
    cout << "Cadena " << cadena1 << " = ";
    Hdecodificar(a, cadena1);
    cout << "Cadena " << cadena2 << " = ";
    Hdecodificar(a, cadena2);
    cout << "Cadena " << cadena3 << " = ";
    Hdecodificar(a, cadena3);

    //Para codificar
    cout << endl
         << endl
         << "Codificar" << endl;
    Hcodificar(a, "Fabc");
    cout << endl;

    return 0;
}