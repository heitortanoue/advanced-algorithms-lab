#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string input;
    int query, priority;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> m;

    while (cin >> input, input[0] != '#')
    {
        cin >> query >> priority;
        m[query] = priority;
        pq.push({priority, query});
    }

    int k;
    cin >> k;

    while (k--)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        cout << top.second << endl;
        top.first += m[top.second];
        pq.push(top);
    }
}
