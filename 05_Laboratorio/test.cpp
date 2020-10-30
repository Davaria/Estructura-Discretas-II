#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
typedef int entero; // typedef usado para definir sus propios tipos a partir de los tipos base.
struct coord
{
  int x, y;
};

coord inicializa_punto1()
{
  coord t0;
  t0.x = rand() % 1024;
  t0.y = rand() % 768;
  return t0;
}
coord inicializa_punto2(int x, int y)
{
  coord t0;
  t0.x = x;
  t0.y = y;
  return t0;
}

// 45 grados
float distancia(coord x1, coord y1)
{
  float result = sqrt(pow(x1.x - y1.x, 2) + pow(x1.x - y1.x, 2));
  return result;
}

int main()
{
  coord pt1, pt2;
  srand((unsigned)time(0)); // cambiar la semilla
  pt1 = inicializa_punto1();
  pt2 = inicializa_punto2(40, 40);
  cout << " pt1.x=" << pt1.x << " pt1.y=" << pt1.y << endl;
  entero x, y;
  x = pt2.x;
  y = pt2.y;
  cout << " pt2.x=" << x << " pt2.y = " << y << endl;
  cout << "Distancia entre dos puntos " << distancia(pt1, pt2) << endl;
  return 0;
}