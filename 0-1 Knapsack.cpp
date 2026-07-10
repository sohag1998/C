#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n + 1], value[n + 1];

    cout << "Enter weight and value:\n";

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << "Enter capacity: ";
    cin >> W;

    int dp[n + 1][W + 1];

    // Initialize
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }
    
    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i] + dp[i - 1][w - weight[i]]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Value = " << dp[n][W];

    return 0;
}
