#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key);

    return binarySearch(arr, mid + 1, right, key);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    int index = binarySearch(arr, 0, n - 1, key);

    if (index == -1)
        cout << "Not Found";
    else
        cout << "Found at index " << index;

    return 0;
}
