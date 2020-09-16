#include <iostream>
#include <cmath>
using namespace std;

void fibonacci(int, long long *);
void show(int, long long *);
void show_lower(int, long long *);
void multiple_three(int, long long *);

int main()
{
    int number{0};
    cout << "Coloque la cantidad de numeros de fibonacci: ";
    cin >> number;
    cout << endl;

    long long *list_fibonacci = new long long[number];

    cout << "La serie fibonacci es: " << endl;
    fibonacci(number, list_fibonacci);
    show(number, list_fibonacci);
    multiple_three(number, list_fibonacci);

    return 0;
}

void fibonacci(int limit, long long *list_fibonacci)
{
    list_fibonacci[0] = 0;
    list_fibonacci[1] = 1;

    for (int i = 2; i < limit; i++)
        list_fibonacci[i] = list_fibonacci[i - 1] + list_fibonacci[i - 2];
}

void show(int limit, long long *list_fibonacci)
{
    for (int i = 0; i < limit; i++)
        cout << list_fibonacci[i] << " ";
    cout << endl;
}

void show_lower(int limit, long long *list)
{
    for (int i = limit - 1; i >= 0; i--)
        cout << list[i] << " ";
    cout << endl;
}

void multiple_three(int limit, long long *list_fibonacci)
{
    int account{0};
    for (int i = 0; i < limit; i++)
    {
        if (list_fibonacci[i] % 3 == 0)
            account += 1;
    }
    long long *list_multiple = new long long[account];
    int j{0};
    for (int i = 0; i < limit; i++)
    {
        if (list_fibonacci[i] % 3 == 0)
        {
            list_multiple[j] = list_fibonacci[i];
            j++;
        }
    }
    cout << "\nLos multiplos de 3 ordenados de forma ascendente: " << endl;
    show(account, list_multiple);
    cout << "\nLos multiplos de 3 ordenados de forma descendente: " << endl;
    show_lower(account, list_multiple);
}