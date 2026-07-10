#include <iostream>
using namespace std;

bool prime(int n, int i)
{
    if (n < 2)
        return false;

    if (i * i > n)
        return true;

    if (n % i == 0)
        return false;

    return prime(n, i + 1);
}

int main()
{
    int n;
    cin >> n;

    if (prime(n, 2))
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
}
