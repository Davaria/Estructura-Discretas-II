// This program shows a basic DFS (Depth First Search) implementation
// in C++.
// By: Nick from CoffeeBeforeArch

#include <list>
#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
private:
    int **matriz, V;
    list<int> *adj;
    list<int> *three;
    void DFS_recursivo(int, bool *);
    void aletory(); //Nuevas aristas
    void addEdge(int, int);

public:
    ~Graph();
    Graph();
    void setColumnsAndRows(int);
    void createAdj(Graph &);
    void DFS(int s);
    list<int> *getTree();
    void printTree(list<int> *);
    void print();
};

// Graph::Graph(int v)
//     : V{v}, adj{new list<int>[v]}
// {
// V = v;
//   adj = new list<int>[v];
// }

list<int> *Graph::getTree()
{
    return three;
}
Graph::~Graph()
{
    for (int i = 0; i < V; i++)
        delete[] matriz[i];
    delete[] matriz;
}

Graph::Graph()
{
    V = 0;
}

void Graph::createAdj(Graph &g)
{
    // V = v;
    // adj = new list<int>[v];

    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            if (matriz[i][j] == 1)
                g.addEdge(i, j);
        }
    }
}

void Graph::setColumnsAndRows(int v)
{
    V = v;
    adj = new list<int>[V + 1];
    three = new list<int>[V + 1];
    matriz = new int *[V];
    for (int i = 0; i < V; i++)
        matriz[i] = new int[V];

    ifstream file;
    file.open("./matriz.txt");
    for (int i = 0; i < V; i++)
    {
        // for (size_t j = i; j < V; j++)
        for (size_t j = 0; j < V; j++)
        {
            file >> matriz[i][j];
            // cout << matriz[i][j];
            // if (rand() % 2 == 1)
            // {
            //   matriz[i][j] = 1;
            //   matriz[j][i] = 1;
            // }
            // else
            // {
            //   matriz[i][j] = 0;
            //   matriz[j][i] = 0;
            // }
        }
        // matriz[i][i] = 0;
    }
    file.close();

    this->aletory();
}

void Graph::aletory()
{
    // int limit = (Vfor (int i = 0; i < v2 * (cols - 1)) / 2,
    int account{0};
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = i; j < V; j++)
        {
            (matriz[i][j] == 0)
                ? account += 1
                : account;
        }
    }
    account -= V;
    srand(time(NULL));
    int limit = rand() % 2 + 1;
    cout << "La aletoriedad es de : " << limit << endl;

    for (;;)
    {

        ofstream file;
        file.open("./coordenadas.txt", ios::trunc);
        account = 0;
        for (size_t i = 0; i < V - 1; i++)
        {
            for (size_t j = i; j < V; j++)
            {
                if (i != j)
                {
                    if (!matriz[i][j] && rand() % 2 == 1)
                    {
                        matriz[i][j] = 1;
                        matriz[j][i] = 1;
                        account++;
                        file << i << " " << j << endl;
                        // Almacenamos las variables en un archivo
                        cout << account << endl;
                    }
                }
            }
        };
        file.close();

        if (account == limit)
            break;

        ifstream coord;
        coord.open("./matriz.txt");
        int i{0}, j{0};
        while (!coord.eof())
        {
            coord >> i >> j;
            matriz[i][j] = matriz[j][i] = 0;
        };
        coord.close();
    };
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS_recursivo(int s, bool *const visited)
{
    visited[s] = true;
    for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
    {
        if (!visited[*i])
        {
            three[s].push_back(*i);
            DFS_recursivo(*i, visited);
        }
    }
}

void Graph::DFS(int s)
{
    bool *const visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    DFS_recursivo(s, visited);
    // cout << "Vertice visitado " << s << endl;
}

void Graph::printTree(list<int> *l)
{
    ofstream file;
    file.open("depth.dot");
    file << "graph A {" << endl;
    list<int>::iterator j;

    for (int i = 1; i <= V; i++)
    {
        for (j = l[i].begin(); j != l[i].end(); j++)
        {
            file << "\t" << i << "--" << *j << ";" << endl;
        }
    }
    file << "}" << endl;
    file.close();
    system("dot -Tpng ./depth.dot -o depth.png");
}

void Graph::print()
{
    for (int i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    cout << "Generado desde el paso base " << endl;
    int option{0};
    // cout << "Cuantos columnas y filas desea añadir: " << endl;
    // cin >> option;
    option = 4;
    Graph graph;
    graph.setColumnsAndRows(option);
    graph.print();
    graph.createAdj(graph);
    graph.DFS(1);
    cout << "Arbol de profundidad generado favor de revisar el archivo png" << endl;
    graph.printTree(graph.getTree());

    return 0;
}