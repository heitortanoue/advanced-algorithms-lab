#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int V, m;
        cin >> V >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
        {
            cin >> coins[i];
        }

        // dp[i]: min de moedas para chegar no valor i
        vector<int> dp(V + 1, INT_MAX);
        dp[0] = 0; // base: zero moedas necessárias para atingir o valor zero

        // calcula o min de cada valor de 1 a V
        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i >= coins[j])
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        cout << dp[V] << endl;
    }

    return 0;
}
