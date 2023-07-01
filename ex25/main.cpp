#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> calcularLPS(const string &padrao)
{
    int m = padrao.length();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (padrao[i] == padrao[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int contarOcorrenciasPadrao(const string &texto, const string &padrao)
{
    int n = texto.length();
    int m = padrao.length();
    vector<int> lps = calcularLPS(padrao);

    int count = 0;
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (padrao[j] == texto[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            count++;
            j = lps[j - 1];
        }
        else if (i < n && padrao[j] != texto[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return count;
}

int main()
{
    string texto, padrao;
    cin >> texto >> padrao;

    int ocorrencias = contarOcorrenciasPadrao(texto, padrao);
    cout << ocorrencias << endl;

    return 0;
}
