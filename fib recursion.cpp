#include <iostream>
using namespace std;

int dp[1000];

int fib(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // If already calculated, return it
    if (dp[n] != -1)
        return dp[n];

    // Store the calculated value
    dp[n] = fib(n - 1) + fib(n - 2);

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    // Initialize the array with -1
    for (int i = 0; i < 1000; i++)
        dp[i] = -1;

    cout << fib(n);

    return 0;
}
