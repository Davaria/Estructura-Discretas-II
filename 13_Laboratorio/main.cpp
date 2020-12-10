#include <iostream>
#include <fstream>
#include "math.h"
#include <vector>
#include <list>

using namespace std;

string readFile(const string location_file)
{
  string text;
  ifstream file(location_file);
  if (file.is_open())
    getline(file, text);
  else
    cout << "No se pudo abrir el archivo" << endl;
  file.close();
  return text;
}

string encryptCesar(const string location_file, const int key, bool flag = true)
{
  string data, data_encrypt, text;
  // Leer archivo
  text = readFile(location_file);
  // encriptacion
  char character;
  for (size_t i = 0; i < text.size(); i++)
  {
    if (text[i] != static_cast<char>(32))
    {
      character = static_cast<char>(text[i] + key);

      if (character > 'Z')
        character -= 26;
      if (character < 'A')
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
    encrypt.open("./output_cesar.txt");
    encrypt << data_encrypt;
    encrypt.close();
  }
  return data_encrypt;
};

string writeFile(const string location_file, const string text)
{
  ofstream file(location_file);
  if (file.is_open())
    file << text;
  else
    cout << "No se pudo abrir el archivo" << endl;
  file.close();
  return text;
}

string encryptVigenere(const string file, const string key)
{
  string data_encrypt;
  string text = readFile(file);

  for (int i = 0; i < text.length(); i++)
    data_encrypt += ((text[i] + key[i]) % 26) + 'A';
  writeFile("output.txt", data_encrypt);
  return data_encrypt;
}

string decryptVigenere(const string file, const string key)
{
  string text = readFile(file);
  string decrypt = "";
  for (int i = 0; i < text.length(); i++)
    decrypt += ((text[i] - key[i] + 26) % 26) + 'A';
  return decrypt;
}

string breakOutCesar(const string file)
{
  string text, password_root, password, key;
  text = readFile(file);
  password_root = readFile("./input_cesar.txt");

  for (size_t i = 0; i < text.size(); i++)
    key += 'A';

  for (size_t i = 0; i < text.size(); i++)
  {
    password += text[i];
    while (password[i] != password_root[i])
    {
      key[i] = key[i] + 1;
      password[i] = ((text[i] - key[i] + 26) % 26) + 'A';
    }
  }
  cout << "Descrifado: " << password << endl;
  return key;
}

int main(int argc, char const *argv[])
{
  string data_encrypt, data_decrypt, cesar_encrypt;
  data_encrypt = encryptVigenere("./input.txt", "CIELO");
  data_decrypt = decryptVigenere("./output.txt", "CIELO");
  cesar_encrypt = encryptCesar("./input_cesar.txt", 2);
  cout
      << "Cifrado de Vigenere" << endl
      << data_encrypt << endl
      << data_decrypt << endl
      << "Cifrado de Cesar" << endl
      << cesar_encrypt << endl;
  cout << "Rompimiento de cesar" << breakOutCesar("./output_cesar.txt") << endl;

  return 0;
}