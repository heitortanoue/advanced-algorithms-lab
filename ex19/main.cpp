#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long, long long> pii;

const long long INF = 1e11;

vector<vector<pii>> adj;

long long primMST(long long n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<long long> key(n + 1, INF);
    vector<bool> visited(n + 1, false);
    long long totalCost = 0;

    pq.push({0, 1}); // Start with city 1
    key[1] = 0;

    while (!pq.empty())
    {
        long long u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        totalCost += key[u];

        for (auto &neighbor : adj[u])
        {
            long long v = neighbor.first;
            long long cost = neighbor.second;

            if (!visited[v] && cost < key[v])
            {
                key[v] = cost;
                pq.push({cost, v});
            }
        }
    }

    // Check if there is a path between all cities
    for (long long i = 1; i <= n; i++)
    {
        if (!visited[i])
            return -1; // IMPOSSIBLE
    }

    return totalCost;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    long long minCost = primMST(n);

    if (minCost == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << minCost << endl;

    return 0;
}
