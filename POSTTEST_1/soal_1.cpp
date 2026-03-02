#include <iostream>
using namespace std;

/*
ANALISIS


Algoritma:
1. min = A[0]
2. Loop dari i = 1 sampai n-1
3. Bandingkan A[i] dengan min
4. Jika lebih kecil, update min dan indeks

Best Case:
Tidak pernah update min di dalam loop
Tmin(n) ≈ c + (n - 1)c
Big-O = O(n)

Worst Case:
Selalu update min di setiap iterasi
Tmax(n) ≈ c + 2(n - 1)c
Big-O = O(n)
*/

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }

    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int minimum = FindMin(A, 8, indexMin);

    cout << "Nilai minimum : " << minimum << endl;
    cout << "Indeks minimum: " << indexMin << endl;

    return 0;
}