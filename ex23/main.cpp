#include <iostream>
#include <vector>

const int MOD = 1000000007;

long long fastPow(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> factors(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> factors[i].first >> factors[i].second;
    }

    long long number = 1;
    long long sum = 1;
    long long product = 1;

    for (const auto &factor : factors)
    {
        long long x = factor.first;
        long long k = factor.second;

        long long term = (fastPow(x, k + 1) - 1 + MOD) % MOD;
        long long inv = fastPow(x - 1, MOD - 2);

        number = (number * (k + 1)) % MOD;
        sum = (sum * term * inv) % MOD;
        product = (product * fastPow(x, k)) % MOD;
    }

    std::cout << number << " " << sum << " " << product << std::endl;

    return 0;
}
