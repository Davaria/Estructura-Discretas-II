#include <iostream>
#include <fstream>
using namespace std;

// TDA NODE
struct Node
{
  char _character;
  int _frecuency;
  Node *next;
  Node *left, *rigth;
};

typedef struct Node *ThreeHuffman;

ThreeHuffman createNode(char character, int frecuency)
{
  Node *newNode = new (Node);
  newNode->_character = character;
  newNode->_frecuency = frecuency;
  newNode->left = nullptr;
  newNode->rigth = nullptr;
  newNode->next = nullptr;
  return newNode;
}

void insertar(ThreeHuffman &three, int frecuency, char character)
{
  if (three)
    three = createNode(character, frecuency);
}

void print(ThreeHuffman three)
{
  if (three)
  {
    Node *current;
    current = three;
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

void printThree(ThreeHuffman &three)
{
  if (three)
  {
    cout << "Nodo: " << three->_frecuency;
    cout << "Left: " << three->_frecuency << "Rigth: " << three->_frecuency << endl;
  }
  else
    cout << "List is empty " << endl;
  printThree(three->left);
  printThree(three->rigth);
}

void sortByFrecuency(ThreeHuffman &three)
{
  Node *aux1, *aux2;
  Node *aux_left, *aux_rigth;
  char character;
  int frecuency;

  aux1 = three;
  while (aux1->next)
  {
    aux2 = aux1->next;

    while (aux2)
    {
      if (aux1->_frecuency > aux2->_frecuency)
      {
        frecuency = aux1->_frecuency;
        character = aux1->_character;
        aux_rigth = aux1->rigth;
        aux_left = aux1->left;

        aux1->_frecuency = aux2->_frecuency;
        aux1->_character = aux2->_character;
        aux1->rigth = aux2->rigth;
        aux1->left = aux2->left;

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
void insertNodeFromFile(ThreeHuffman &three, string fileDirection)
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

void createThreeHuffman(ThreeHuffman &list)
{
  Node *temp1, *temp2, *temph;
  temp1 = list;
  temp2 = (list)->next;
  temph = list;

  int quantity = temp1->_frecuency + temp2->_frecuency;

  while (list.begin != nullptr)
  {
    temph = createNode(' ', quantity);

    temph->left = temp1;
    temph->rigth = temp2;
    temph->next = temp2->next;

    temp1->next = nullptr;
    temp2->next = nullptr;

    list.begin = temph;

    sortByFrecuency(list);
    if ((list.begin)->next != nullptr)
    {

      temp1 = list.begin;
      temp2 = temp1->next;
      quantity = temp1->_frecuency + temp2->_frecuency;
    }
  }
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
  createThreeHuffman(three);

  return 0;
}