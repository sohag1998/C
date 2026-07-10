#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compare(Item a, Item b)
{
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[n];

    cout << "Enter weight and value:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].value;
    }

    cout << "Enter capacity: ";
    cin >> W;

    sort(item, item + n, compare);

    double totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (item[i].weight <= W)
        {
            totalValue += item[i].value;
            W -= item[i].weight;
        }
        else
        {
            totalValue +=
                (double)item[i].value *
                W /
                item[i].weight;

            break;
        }
    }

    cout << "Maximum Value = "
         << totalValue;

    return 0;
}
