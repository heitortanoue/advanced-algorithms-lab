#include <iostream>
#include <vector>

using namespace std;

int maxPages(int n, int x, vector<int> &prices, vector<int> &pages)
{
    // tabela 2D com numero maximo de paginas de cada preço e livro
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    // para cada livro
    for (int i = 1; i <= n; i++)
    {
        int price = prices[i - 1];
        int page = pages[i - 1];

        // para cada preço menor que x
        for (int j = 1; j <= x; j++)
        {
            // livro pode ser comprado com o preço atual
            if (price <= j)
            {
                // inclui o livro atual
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + page);
            }
            else
            {
                // exclui o livro atual
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][x];
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    int result = maxPages(n, x, prices, pages);
    cout << result << endl;

    return 0;
}
