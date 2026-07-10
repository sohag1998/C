#include <iostream>
using namespace std;

void tower(int n, char source, char aux, char dest)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }

    tower(n - 1, source, dest, aux);

    cout << "Move disk " << n << " from " << source << " to " << dest << endl;

    tower(n - 1, aux, source, dest);
}

int main()
{
    int n;
    cin >> n;

    tower(n, 'A', 'B', 'C');

    return 0;
}
