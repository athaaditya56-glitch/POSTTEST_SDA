#include <iostream>
using namespace std;

void tukar(int* a, int* b) {
    int hal = *a;
    *a = *b;
    *b = hal;
}

int main() {
    int x, y;

    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "Sebelum ditukar:";
    cout << "x = " << x << ", y = " << y << endl;

    tukar(&x, &y);

    cout << "Setelah ditukar:";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}