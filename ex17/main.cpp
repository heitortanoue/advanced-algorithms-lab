#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonSubsequence(const string &s, const string &t)
{
    int m = s.length();
    int n = t.length();

    // matriz 2d
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                // mesmos caracteres, adiciona 1 ao comprimento máximo
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // escolhe o maximo entre remover o ultimo caractere de s ou de t
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string result;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            // mesmos caracteres, adiciona o caractere na string
            result.push_back(s[i - 1]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            // move pra cima
            --i;
        }
        else
        {
            // move para a esquerda
            --j;
        }
    }

    // inverte a string
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string s, t;

    cin >> s >> t;

    string result = longestCommonSubsequence(s, t);

    cout << result << endl;

    return 0;
}
