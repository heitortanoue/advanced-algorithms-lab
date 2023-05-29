#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string &s1, const string &s2)
{
    int n = s1.length();
    int m = s2.length();

    // tabela de distancias
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; // caracteres iguais
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
            // escolhe o minimo entre remover, inserir ou substituir
        }
    }

    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int distance = editDistance(s1, s2);
    cout << distance << endl;

    return 0;
}
