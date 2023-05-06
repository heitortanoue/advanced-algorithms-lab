#include <iostream>

using namespace std;

int buscaBinaria(int esq, int dir, int t, int n, int dist[])
{
    while (esq != dir)
    {
        int somaDist = 0;
        int dia = 0;
        int meio = (esq + dir) / 2;
        
        for (int i = 0; i <= n; i++)
        {
            if (somaDist + dist[i] <= meio)
            {
                somaDist += dist[i];
            }
            else
            {
                dia++;
                somaDist = dist[i];
            }
        }
        if (somaDist > 0)
        {
            dia++;
        }
        if (dia - 1 > t)
        {
            esq = 1 + meio;
            continue;
        }
        dir = meio;
    }
    return esq;
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int dist[1024];
        int num_max = 0;
        int num_min = 0;
        for (int i = 0; i <= n; i++)
        {
            cin >> dist[i];
            num_min = max(num_min, dist[i]);
            num_max += dist[i];
        }
        int res = buscaBinaria(num_min, num_max, k, n, dist);
        cout << res << endl;
    }
    return 0;
}
