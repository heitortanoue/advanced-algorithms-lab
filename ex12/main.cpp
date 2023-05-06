#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, x, y, z;
int d[305];
int dp[305];

int main()
{
    cin >> n >> x >> y >> z;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = INF;
    }

    // base: se John só precisa de um passe de 1 dia, compra esse passe
    dp[0] = x;

    for (int i = 1; i < n; i++)
    {
        // 1 opcao: passe de 1 dia para hoje
        dp[i] = min(dp[i], dp[i - 1] + x);

        // 2 opcao: passe de 7 dias que começa hoje ou antes
        int j = i - 1;
        while (j >= 0 && d[i] - d[j] + 1 <= 7)
        {
            j--;
        }
        if (j >= 0)
        {
            dp[i] = min(dp[i], dp[j] + y);
        }
        else
        {
            dp[i] = min(dp[i], y);
        }

        // 3 opcao: passe de 30 dias que começa hoje ou antes
        j = i - 1;
        while (j >= 0 && d[i] - d[j] + 1 <= 30)
        {
            j--;
        }
        if (j >= 0)
        {
            dp[i] = min(dp[i], dp[j] + z);
        }
        else
        {
            dp[i] = min(dp[i], z);
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}
