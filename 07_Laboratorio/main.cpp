#include <iostream>
#include <fstream>
using namespace std;

// TDA NODE
struct Node
{
  char _character;
  int _frecuency;
  struct Node *next;
  struct Node *left, *rigth;
};

// Lista de nodos
struct LinkedList
{
  Node *begin;
  Node *end;
};

// typedef struct Node *Node;
Node *createNode(char character, int frecuency)
{
  Node *newNode = new (Node);
  newNode->_character = character;
  newNode->_frecuency = frecuency;
  newNode->left = nullptr;
  newNode->rigth = nullptr;
  newNode->next = nullptr;
  return newNode;
}

// Creamos una lista enlazada haciendo uso de la struct LinkedList
void insertar(LinkedList &three, int frecuency, char character)
{
  // Creamos un nuevo nodo
  Node *newNode = createNode(character, frecuency);
  // Si nuestra lista esta vacia creamo el primer valor
  if (!three.begin)
    three.begin = newNode;
  // Caso contrario nuestro fin de lista se ira añadiendo un nuevo nodo
  else
    (three.end)->next = newNode;
  // Actualizamos nuestro ultimo nodo de lista
  three.end = newNode;
}

void print(LinkedList three)
{
  if (three.begin)
  {
    Node *current;
    current = three.begin;
    cout << "\tLista de nodos" << endl;
    cout << "-----------------" << endl;
    while (current)
    {
      cout << "C: " << current->_character << " - F: " << current->_frecuency << " -> ";
      current = current->next;
    }
    cout << "nullptr" << endl;
  }
  else
    cout << "List is empty " << endl;
}

void printThree(LinkedList &three)
{
  if (three.begin)
  {
    Node *current, *current1;
    current = current1 = three.begin;
    // Mientras nuestro nodo tenga nodos izquierdo y derecho
    while ((current)->rigth || (current1)->left)
    {
      // En caso de existir un nodo derecho pues existe un nodo izquierdo
      (current->rigth)
          ? current1 = current->left
          : current1 = nullptr;

      // Si tenemos un nodo derecho lo imprimimos
      if ((current)->rigth)
      {

        cout << "\tNodo: " << current->_frecuency << "\tLeft: " << (current->left)->_frecuency << "\tRigth: " << (current->rigth)->_frecuency << endl;
        current = current->rigth;
      }
      // Si tenemos un nodo izquierdo lo imprimimos
      if ((current1)->left)
      {
        cout << "\tNodo: " << current1->_frecuency;
        cout << "\tLeft: " << (current1->left)->_frecuency;
        cout << "\tRigth: " << (current1->rigth)->_frecuency;
        cout << endl;
        current1 = current1->left;
      }
    }
  }
  else
    cout << "List is empty " << endl;
}

// Funcion para desencriptar
void desencrypt(LinkedList &three, string letters)
{
  Node *current = three.begin;
  int i = 0;
  //While para decodifficar cada letra
  while (i < letters.size())
  {
    // Mientras tengamos el Node padre
    while (current->left && current->rigth)
    {
      //Si es 0 va a la iquierda
      if (letters[i] == '0')
        current = current->left;
      //Si es 1 va a la derecha
      if (letters[i] == '1')
        current = current->rigth;
      i++;
    }
    cout << current->_character; //Imprimimos los caracteres
    current = three.begin;       //Para volver al recorrer con el siguiente caracter nuestro nodo debe volver al inicio
  }
  cout << endl;
}

// Funcion para ordenar de forma ascendente por prioridad
void sortByFrecuency(LinkedList &three)
{
  // Nodos temporales para hacer el cambio
  Node *aux1, *aux2;
  // Nodos temporales para almacenar los punteros de left y ritgh de nuestro nodos
  Node *aux_left, *aux_rigth;
  char character;
  int frecuency;

  aux1 = three.begin;
  // Haremos uso de un doble while
  while (aux1->next)
  {
    aux2 = aux1->next;

    while (aux2)
    {
      // Si aux1 es mayor a aux2, haremos un swap
      if (aux1->_frecuency > aux2->_frecuency)
      {
        // Nuestro nodos temporales almacenaran el valor de aux1
        frecuency = aux1->_frecuency;
        character = aux1->_character;
        aux_rigth = aux1->rigth;
        aux_left = aux1->left;
        // Nuestro nodo aux1 toma los valores de aux2
        aux1->_frecuency = aux2->_frecuency;
        aux1->_character = aux2->_character;
        aux1->rigth = aux2->rigth;
        aux1->left = aux2->left;
        // Nuestro nodo aux2 toma los valores de los nodos temporales
        aux2->_frecuency = frecuency;
        aux2->_character = character;
        aux2->rigth = aux_rigth;
        aux2->left = aux_left;
      }
      aux2 = aux2->next;
    }
    aux1 = aux1->next;
  }
}

// TDA NODE

// Leemos un archivo txt y almacenamos la frecuencia en otro archivo
void frecuency(string fileDirection, string fileFrecuency)
{
  ifstream file(fileDirection);
  if (file.is_open())
  {
    char character;
    int account_a{0}, account_b{0}, account_c{0}, account_d{0}, account_e{0}, account_f{0};
    while (!file.eof())
    {
      file >> character;
      switch (character)
      {
      case 'a':
        account_a++;
        break;
      case 'b':
        account_b++;
        break;
      case 'c':
        account_c++;
        break;
      case 'd':
        account_d++;
        break;
      case 'e':
        account_e++;
        break;
      case 'f':
        account_f++;
        break;
      default:
        break;
      }
    }
    // Guardamos las frecuencias
    ofstream file2(fileFrecuency);
    if (file2.is_open())
    {
      file2 << 'a' << " " << account_a << endl;
      file2 << 'b' << " " << account_b << endl;
      file2 << 'c' << " " << account_c << endl;
      file2 << 'd' << " " << account_d << endl;
      file2 << 'e' << " " << account_e << endl;
      file2 << 'f' << " " << account_f << endl;
    }
    else
      cout << "No se pudo abrir el archivo" << endl;
    file2.close();
  }
  else
    cout << "No se pudo abrir el archivo" << endl;
  file.close();
}

void readFile(string fileDirection)
{
  ifstream file(fileDirection);
  if (file.is_open())
  {
    char character;
    while (!file.eof())
    {
      file >> character;
      cout << character << endl;
    }
  }
  else
    cout << "No se pudo abrir el archivo" << endl;
  file.close();
};

// Debemos pasar como parametro la referencia de nuestra lista enlazada y el archivo donde estas nuestras frecuencias
void insertNodeFromFile(LinkedList &three, string fileDirection)
{
  ifstream file(fileDirection);
  if (file.is_open())
  {
    char character;
    int frecuency{0};
    while (!file.eof())
    {
      file >> character;
      file >> frecuency;
      // cout << character << " " << frecuency << endl;
      insertar(three, frecuency, character);
    };
  }
  else
    cout << "No se pudo abrir el archivo" << endl;
  file.close();
}

// Funcion donde creamos nuestro Arbol
void Huffman(LinkedList &list)
{
  /*Importante antes de llamar al la funcion Huffman recordar que nuestra lista esta ordenada y el nodo padre es la suma de dos nodos menores de nuestra lista ordenada*/
  // Creamos nodos temporales
  Node *leftNode, *rigthNode, *fatherNode;
  leftNode = list.begin;          // Nodo izquierdo
  rigthNode = (list.begin)->next; // Nodo derecho
  fatherNode = list.begin;        // Nodo padre

  int quantity = leftNode->_frecuency + rigthNode->_frecuency;

  while ((list.begin)->next)
  {
    fatherNode = createNode(' ', quantity); // Se crea un nuevo nodo

    fatherNode->left = leftNode;
    fatherNode->rigth = rigthNode;
    fatherNode->next = rigthNode->next; // Nodo padre es enlazado a la lista enlazada

    // Retiramos a los nodos hijos de la lista
    leftNode->next = nullptr;
    rigthNode->next = nullptr;
    // Ahora nuesta inicio de la lista sera el nuevo nodo padre
    list.begin = fatherNode;
    // Ordenamos nuestra lista
    sortByFrecuency(list);
    // Si nuestro nodo de inicio tiene un siguiente nodo
    if ((list.begin)->next)
    {
      // Tomamos los valores de los dos menores y repetimos el proceso en el inicio del bucle while
      leftNode = list.begin;
      rigthNode = leftNode->next;
      quantity = leftNode->_frecuency + rigthNode->_frecuency;
    }
  }
  // Imprimimos el arbol
  printThree(list);
}
int main(int argc, char const *argv[])
{
  LinkedList three;
  three.begin = nullptr;
  three.end = nullptr;
  insertNodeFromFile(three, "frecuencia.txt");
  print(three);
  sortByFrecuency(three);
  print(three);
  Huffman(three);
  string cadena1 = "000";
  string cadena2 = "100011001101";
  string cadena3 = "110001001101";
  cout << "CADENA " << cadena1 << "=";
  desencrypt(three, cadena1);
  cout << "CADENA " << cadena2 << "=";
  desencrypt(three, cadena2);
  cout << "CADENA " << cadena3 << "=";
  desencrypt(three, cadena3);
  return 0;
}