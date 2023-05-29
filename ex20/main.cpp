#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> team;
vector<vector<int>> adj_list;

bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    team[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj_list[node])
        {
            if (team[neighbor] == team[node])
            {
                return false; // Conflict, same team as a friend
            }

            if (team[neighbor] == 0)
            {
                team[neighbor] = 3 - team[node];
                q.push(neighbor);
            }
        }
    }

    return true; // No conflicts
}

int main()
{
    int n, m;
    cin >> n >> m;

    team.resize(n + 1, 0);
    adj_list.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (team[i] == 0 && !bfs(i))
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << team[i] << " ";
    }
    cout << endl;

    return 0;
}
