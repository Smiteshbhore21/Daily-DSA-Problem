#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int &n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int countDivisors(int &n)
{
    int divisor = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0 && isPrime(i))
            divisor++;
    return divisor;
}

int main()
{
    int n = 0;
    int ans = 0;
    cin >> n;

    for (int i = 2; i <= n; i++)
        if (countDivisors(i) == 2)
            ans++;

    cout << ans;

    return 0;
}
