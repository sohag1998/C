
#include <iostream>
using namespace std;

int reverse = 0;

void reverseNumber(int num) {
    if (num == 0)
        return;

    reverse = reverse * 10 + (num % 10);
    reverseNumber(num / 10);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    reverseNumber(num);

    cout << "Reversed number: " << reverse << endl;

    return 0;
}
