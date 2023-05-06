#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 50;

int field[MAXN][MAXN];
int dist[MAXN][MAXN];

// Retorna true se (i, j) é uma posição válida no campo minado
bool isValid(int i, int j, int rows, int cols)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        return false;
    }

    // field[i][j] == 0 significa que a posição (i, j) é uma bomba, também não pode visitar vizinhos imediatos
    if (field[i][j] == 0 || (i > 0 && field[i - 1][j] == 0) || (i < rows - 1 && field[i + 1][j] == 0) || (j > 0 && field[i][j - 1] == 0) || (j < cols - 1 && field[i][j + 1] == 0))
    {
        return false;
    }
    {
        return false;
    }
    return i >= 0 && i < rows && j >= 0 && j < cols && field[i][j] != 0;
}

// Retorna o menor caminho possível do início para o fim do campo minado
// ou -1 se não houver caminho válido
int shortestPath(int rows, int cols)
{
    // Inicializa a distância de todas as posições como infinito
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    // Usa uma fila para implementar uma busca em largura (BFS)
    queue<pair<int, int>> q;

    // Insere todas as posições válidas da primeira coluna na fila
    for (int i = 0; i < rows; i++)
    {
        if (field[i][0] != 0)
        {
            q.push(make_pair(i, 0));
            dist[i][0] = field[i][0];
        }
    }

    // Executa a BFS
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        // Visita os vizinhos 4-conectados da posição atual
        vector<pair<int, int>> neighbors = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
        for (auto neighbor : neighbors)
        {
            int ni = neighbor.first;
            int nj = neighbor.second;
            if (isValid(ni, nj, rows, cols) && dist[ni][nj] > dist[i][j] + field[ni][nj])
            {
                dist[ni][nj] = dist[i][j] + field[ni][nj];
                q.push(make_pair(ni, nj));
            }
        }
    }

    // Encontra o menor caminho possível até a última coluna
    int shortest = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        if (dist[i][cols - 1] < shortest)
        {
            shortest = dist[i][cols - 1];
        }
    }

    return shortest == INT_MAX ? -1 : shortest;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> field[i][j];
        }
    }

    int shortest = shortestPath(rows, cols);

    if (shortest == -1)
    {
        cout << "Nao ha caminho valido" << endl;
    }
    else
    {
        cout << "Comprimento da rota = " << shortest << endl;
    }

    return 0;
}
