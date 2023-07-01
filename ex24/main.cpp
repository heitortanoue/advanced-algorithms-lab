#include <iostream>
#include <vector>

typedef unsigned long long ll;

const ll MOD = 1e9 + 7;

ll fastPow(ll base, ll exp)
{
    ll result = 1;
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

    std::vector<std::pair<ll, ll>> factors(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> factors[i].first >> factors[i].second;
    }

    ll number = 1;
    ll sum = 1;
    ll product = 1;

    ll pd = 1;
    for (const auto &factor : factors)
    {
        ll x = factor.first;
        ll k = factor.second;

        ll term = (fastPow(x, k + 1) - 1 + MOD) % MOD;
        ll inv = fastPow(x - 1, MOD - 2);

        number = (number * (k + 1)) % MOD;
        sum = (sum * (term * inv % MOD)) % MOD;

        ll p = fastPow(x, k * (k + 1) / 2);
        product = fastPow(product, k + 1) * fastPow(p, pd) % MOD;
        pd = pd * (k + 1) % (MOD - 1);
    }

    std::cout << number << " " << sum << " " << product << std::endl;

    return 0;
}
