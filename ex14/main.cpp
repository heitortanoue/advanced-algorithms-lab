#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;

int countPaths(vector<vector<char>> &grid, int n)
{
    // matriz 2d
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base: Existe um caminho para chegar a celula inicial
    dp[0][0] = 1;

    // calcula o num de caminhos para cada celula
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // celula atual for uma armadilha, pula para a proxima
            if (grid[i][j] == '*')
                continue;

            // calcula o num de caminhos para a celula atual
            // somando o num de caminhos da celula acima e da celula a esquerda
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }

    // num de caminhos para a celula inferior direita
    return dp[n - 1][n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << countPaths(grid, n) << endl;

    return 0;
}
