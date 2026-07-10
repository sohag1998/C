#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int target, int index)
{
    if (target == 0)
        return true;

    if (index == n || target < 0)
        return false;

    // বর্তমান উপাদান নেওয়া
    if (subsetSum(arr, n, target - arr[index], index + 1))
        return true;

    // বর্তমান উপাদান না নেওয়া
    if (subsetSum(arr, n, target, index + 1))
        return true;

    return false;
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int target = 9;

    if (subsetSum(arr, n, target, 0))
        cout << "Subset exists";
    else
        cout << "Subset does not exist";

    return 0;
}
