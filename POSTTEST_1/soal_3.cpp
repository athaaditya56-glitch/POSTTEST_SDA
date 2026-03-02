#include <iostream>
using namespace std;

void reverseArray(int* dataPtr, int n) {
    int* awalPtr = dataPtr;            
    int* akhirPtr = dataPtr + n - 1;  

    while (awalPtr < akhirPtr) {
        int temp = *awalPtr;
        *awalPtr = *akhirPtr;
        *akhirPtr = temp;

        awalPtr++;
        akhirPtr--;
    }
}

int main() {
    int bilPrima[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik:";
    for (int i = 0; i < 7; i++) {
        cout << bilPrima[i] 
             << " (Alamat: " << &bilPrima[i] << ")";
    }

    reverseArray(bilPrima, 7);

    cout << "Array setelah dibalik:";
    for (int i = 0; i < 7; i++) {
        cout << bilPrima[i] 
             << " (Alamat: " << &bilPrima[i] << ")";
    }

    return 0;
}