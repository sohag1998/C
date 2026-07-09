
#include <iostream>
using namespace std;

int rev = 0;

void reverseNumber(int num) {
    if (num == 0)
        return;

    rev = rev * 10 + (num % 10);
    reverseNumber(num / 10);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    reverseNumber(num);

    cout << "Reversed number: " << rev << endl;

    return 0;
}
