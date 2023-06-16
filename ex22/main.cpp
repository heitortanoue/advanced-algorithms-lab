#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int INF = 1e9;
const int MAX_V = 55;

int residual[MAX_V][MAX_V], maxFlow, currentFlow, source, sink;
vector<vector<int>> adjacencyList;
vector<int> parent;

int numCities, numConnections, count = 1;

bitset<MAX_V> visitedCities;
set<int> minCutSet;

// Realiza uma busca em profundidade a partir de uma cidade para marcar todas as cidades alcançáveis
void dfs(int cidade)
{
    visitedCities.set(cidade);
    minCutSet.insert(cidade);
    for (int i = 0; i < (int) adjacencyList[cidade].size(); i++)
    {
        int cidadeVizinha = adjacencyList[cidade][i];
        if (!visitedCities.test(cidadeVizinha) && residual[cidade][cidadeVizinha] > 0)
        {
            dfs(cidadeVizinha);
        }
    }
}

// Encontra o corte mínimo entre as cidades alcançáveis a partir da fonte e as outras cidades
void encontrarCorteMinimo()
{
    minCutSet.clear();
    visitedCities.reset();
    dfs(source);

    for (int cidade : minCutSet)
    {
        for (int vizinho : adjacencyList[cidade])
        {
            if (minCutSet.count(vizinho))
                continue;
            if (residual[cidade][vizinho] <= 0)
            {
                printf("%d %d\n", cidade + 1, vizinho + 1);
            }
        }
    }
    printf("\n");
}

// Realiza a operação de aumento do fluxo na rede residual
void aumentarFluxo(int cidade, int fluxoMinimo)
{
    if (cidade == source)
    {
        currentFlow = fluxoMinimo;
        return;
    }
    else if (parent[cidade] != -1)
    {
        aumentarFluxo(parent[cidade], min(fluxoMinimo, residual[parent[cidade]][cidade]));
        residual[parent[cidade]][cidade] -= currentFlow;
        residual[cidade][parent[cidade]] += currentFlow;
    }
}

// Encontra o fluxo máximo na rede usando o algoritmo de Edmonds-Karp
void encontrarFluxoMaximo()
{
    maxFlow = 0;
    while (true)
    {
        currentFlow = 0;
        bitset<MAX_V> visited;
        visited.set(source);
        queue<int> q;
        q.push(source);
        parent.assign(MAX_V, -1);

        while (!q.empty())
        {
            int cidade = q.front();
            q.pop();
            if (cidade == sink)
                break;
            for (int vizinho : adjacencyList[cidade])
            {
                if (residual[cidade][vizinho] > 0 && !visited.test(vizinho))
                {
                    visited.set(vizinho);
                    q.push(vizinho);
                    parent[vizinho] = cidade;
                }
            }
        }
        aumentarFluxo(sink, INF);
        if (currentFlow == 0)
            break;
        maxFlow += currentFlow;
    }
}

int main()
{
    while (scanf("%d %d", &numCities, &numConnections) && numCities && numConnections)
    {
        memset(residual, 0, sizeof residual);
        adjacencyList.assign(numCities, vector<int>());

        source = 0;
        sink = 1;

        for (int i = 0; i < numConnections; i++)
        {
            int cidade1, cidade2, custo;
            scanf("%d %d %d", &cidade1, &cidade2, &custo);
            cidade1--;
            cidade2--;
            residual[cidade1][cidade2] += custo;
            residual[cidade2][cidade1] += custo;
            adjacencyList[cidade1].push_back(cidade2);
            adjacencyList[cidade2].push_back(cidade1);
        }

        encontrarFluxoMaximo();
        encontrarCorteMinimo();
    }

    return 0;
}
