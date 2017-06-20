#include "Test.h"
#include <iostream>
#define VAL 1000000000
using namespace std;

struct Edge
{
    int agmh, to, weight;
};

vector<Edge> get(int ** graph, int size)
{
    vector<Edge> edges;

    for (int i = 0; i <size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(graph[i][j]!=-1)
            {
                Edge edge;
                edge.agmh = i;
                edge.to = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
            }
        }
    }

    return edges;
}

int* getShortestPath(int** graph, int size, int origin)
{
    int vSize = size;
    vector<Edge> edges = get(graph, size);

    int newE = edges.size();
    int dist[size];

    int *newDist = new int[size];

    for (int i = 0; i < vSize; i++)
    {
        dist[i] = VAL;
        newDist[i] = (int)NULL;
    }

    dist[origin] = 0;

    for (int i = 1; i <= vSize-1; i++)
    {
        for (int j = 0; j < newE; j++)
        {
            int u = edges[j].agmh;
            int v = edges[j].to;
            int weight = edges[j].weight;
            if (dist[u] + weight < dist[v] && dist[u]!=VAL)
            {
                dist[v] = dist[u] + weight;
                newDist[v] = u;
            }
        }
    }


    for (int i = 0; i < newE; i++)
    {
        int u = edges[i].agmh;
        int v = edges[i].to;
        int weight = edges[i].weight;

        if (dist[u] != VAL && dist[u] + weight < dist[v])
            printf("");
    }

    return newDist;
}

int main ()
{
    test();
    return 0;
}
