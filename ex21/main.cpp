#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int from;
    int to;
    int capacity;
    int flow;
    int cost;
    int reverseEdgeIndex;
};

class Dinic
{
private:
    int n; // Number of nodes
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> nextEdgeIndex;

    bool bfs(int source, int sink)
    {
        level.assign(n, -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();

            for (const Edge &edge : graph[currentNode])
            {
                if (level[edge.to] == -1 && edge.flow < edge.capacity)
                {
                    level[edge.to] = level[currentNode] + 1;
                    q.push(edge.to);
                }
            }
        }

        return level[sink] != -1;
    }

    int dfs(int currentNode, int sink, int minFlow)
    {
        if (currentNode == sink)
            return minFlow;

        while (nextEdgeIndex[currentNode] < graph[currentNode].size())
        {
            Edge &edge = graph[currentNode][nextEdgeIndex[currentNode]];

            if (level[edge.to] == level[currentNode] + 1 && edge.flow < edge.capacity)
            {
                int bottleneckFlow = dfs(edge.to, sink, min(minFlow, edge.capacity - edge.flow));

                if (bottleneckFlow > 0)
                {
                    edge.flow += bottleneckFlow;
                    graph[edge.to][edge.reverseEdgeIndex].flow -= bottleneckFlow;
                    return bottleneckFlow;
                }
            }

            nextEdgeIndex[currentNode]++;
        }

        return 0;
    }

public:
    Dinic(int nodes) : n(nodes), graph(nodes), level(nodes), nextEdgeIndex(nodes) {}

    void addEdge(int from, int to, int capacity, int cost)
    {
        Edge forward = {from, to, capacity, 0, cost, graph[to].size()};
        Edge reverse = {to, from, 0, 0, -cost, graph[from].size()};
        graph[from].push_back(forward);
        graph[to].push_back(reverse);
    }

    vector<Edge> findMinCut(int source, int sink)
    {
        vector<Edge> minCut;
        while (bfs(source, sink))
        {
            nextEdgeIndex.assign(n, 0);
            int minFlow;
            do
            {
                minFlow = dfs(source, sink, numeric_limits<int>::max());
            } while (minFlow > 0);
        }

        for (const vector<Edge> &edges : graph)
        {
            for (const Edge &edge : edges)
            {
                if (edge.capacity > 0 && level[edge.from] != -1 && level[edge.to] == -1)
                {
                    minCut.push_back(edge);
                }
            }
        }

        return minCut;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Dinic dinic(n + 1);

    for (int i = 0; i < m; i++)
    {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;
        dinic.addEdge(city1, city2, 1, cost);
        dinic.addEdge(city2, city1, 1, cost);
    }

    vector<Edge> minCut = dinic.findMinCut(1, 2);

    for (const Edge &edge : minCut)
    {
        cout << edge.from << " " << edge.to << endl;
    }

    return 0;
}
