#include <iostream>
#include <fstream>
#include "math.h"
#include <vector>
#include <list>

using namespace std;
/* 
	primer parametro -> el archivo a encriptar
	segundo parametro -> factor de desplazamiento
	tercer parametro -> em
*/
string encrypt(const string location_file, const int key, bool flag = true)
{
  string data, data_encrypt, text;
  // Leer archivo
  ifstream file;
  file.open(location_file);
  while (getline(file, text))
    file >> text;
  file.close();
  // encriptacion
  char character;
  for (size_t i = 0; i < text.size(); i++)
  {
    if (text[i] != static_cast<char>(32))
    {
      character = static_cast<char>(text[i] + key);

      if (character > 'z')
        character -= 26;
      if (character < 'a')
        character += 26;
      data_encrypt += character;
      data += text[i];
    }
    else
    {
      data += static_cast<char>(32);
      data_encrypt += static_cast<char>(32);
    }
  }
  cout << data_encrypt << endl;
  // Almacenar el archivo desencriptado
  if (flag)
  {
    // Almacenar datos encriptados en un archivo
    ofstream encrypt;
    encrypt.open("./output.txt");
    encrypt << data_encrypt;
    encrypt.close();
  }
  return data_encrypt;
};

string desencrypt(const string location_file, int key)
{
  return encrypt(location_file, -key, false);
};

int main(int argc, char const *argv[])
{
  cout << "Ingrese el factor de desplazamiento" << endl;
  int key{0};
  cin >> key;
  encrypt("./input.txt", key);
  desencrypt("./output.txt", key);
  return 0;
}