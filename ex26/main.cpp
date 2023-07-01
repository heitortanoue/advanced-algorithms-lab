#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_N = 1e5;
long long arraySufixos[MAX_N], posicao[MAX_N], temp[MAX_N], lcp[MAX_N];
long long gap, N;
string S;

bool compararSufixos(long long x, long long y)
{
    if (posicao[x] != posicao[y])
        return posicao[x] < posicao[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? posicao[x] < posicao[y] : x > y;
}

void construirArraySufixos()
{
    for (long long i = 0; i < N; i++)
        arraySufixos[i] = i, posicao[i] = S[i];

    gap = 1;
    while (true)
    {
        // Ordena os sufixos com base nas chaves de comparação atual e seguinte
        sort(arraySufixos, arraySufixos + N, compararSufixos);

        // Atualiza o array de posição com as novas posições
        temp[0] = 0;
        for (long long i = 1; i < N; i++)
        {
            temp[i] = temp[i - 1] + compararSufixos(arraySufixos[i - 1], arraySufixos[i]);
        }
        for (long long i = 0; i < N; i++)
        {
            posicao[arraySufixos[i]] = temp[i];
        }

        // Se todos os sufixos estiverem ordenados, encerra o loop
        if (temp[N - 1] == N - 1)
        {
            break;
        }

        gap <<= 1;
    }
}

void construirArrayLCP()
{
    // Computa o array de maior prefixo comum (LCP)
    for (long long i = 0, k = 0; i < N; i++)
        if (posicao[i] != N - 1)
        {
            long long j = arraySufixos[posicao[i] + 1];
            while (S[i + k] == S[j + k])
                k++;
            lcp[posicao[i]] = k;
            if (k)
                k--;
        }
}

void imprimirContagemSubstringsDistintas()
{
    long long anterior = 0;
    vector<long long> contagemSubstringsDistintas(N + 1, 0);

    for (long long i = 0; i < N; i++)
    {
        // Atualiza a contagem de substrings distintas para cada comprimento
        contagemSubstringsDistintas[anterior + 1]++;
        contagemSubstringsDistintas[N - arraySufixos[i] + 1]--;
        anterior = lcp[i];
    }

    for (long long i = 1; i <= N; i++)
    {
        cout << contagemSubstringsDistintas[i] << ' ';
        contagemSubstringsDistintas[i + 1] += contagemSubstringsDistintas[i];
    }
}

int main()
{
    cin >> S;
    N = S.size();

    construirArraySufixos();
    construirArrayLCP();

    imprimirContagemSubstringsDistintas();

    return 0;
}
