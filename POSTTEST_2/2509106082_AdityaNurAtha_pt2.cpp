#include <iostream>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

int n = 0;

// SWAP POINTER 
void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

//  TAMBAH DATA 
void tambahKereta(Kereta *arr, int &n) {
    int jml;
    cout << "\nMasukkan jumlah data: ";
    cin >> jml;

    for(int i = 0; i < jml; i++) {
        cout << "\nData ke-" << i+1 << endl;
        cout << "Nomor Kereta: ";
        cin >> (arr+n+i)->nomor;

        cout << "Nama Kereta: ";
        cin >> (arr+n+i)->nama;

        cout << "Asal: ";
        cin >> (arr+n+i)->asal;

        cout << "Tujuan: ";
        cin >> (arr+n+i)->tujuan;

        cout << "Harga: ";
        cin >> (arr+n+i)->harga;
    }
    n += jml;
}

//  TAMPIL DATA
void tampil(Kereta *arr, int n) {
    cout << "\n=== DATA KERETA ===\n";
    for(int i = 0; i < n; i++) {
        cout << "\nKereta ke-" << i+1 << endl;
        cout << "Nomor  : " << (arr+i)->nomor << endl;
        cout << "Nama   : " << (arr+i)->nama << endl;
        cout << "Asal   : " << (arr+i)->asal << endl;
        cout << "Tujuan : " << (arr+i)->tujuan << endl;
        cout << "Harga  : " << (arr+i)->harga << endl;
    }
}

// LINEAR SEARCH  (CARI RUTE)
void linearSearch(Kereta *arr, int n) {
    string asal, tujuan;
    cout << "\nCari Asal: "; cin >> asal;
    cout << "Cari Tujuan: "; cin >> tujuan;

    bool ketemu = false;

    for(int i = 0; i < n; i++) {

        if((arr+i)->asal == asal && (arr+i)->tujuan == tujuan) {
            cout << "\nDitemukan!\n";
            cout << "Nama: " << (arr+i)->nama << endl;
            cout << "Harga: " << (arr+i)->harga << endl;

            swap(&arr[i], &arr[0]);

            ketemu = true;
        }
    }

    if(!ketemu) cout << "Data tidak ditemukan\n";
}

//   JUMP SEARCH (URUT NO KERETA) 
void sortNomor(Kereta *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j].nomor < arr[min].nomor) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

// = JUMP SEARCH
int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;


    while(arr[min(step, n)-1].nomor < key) {
        prev = step;
        step += sqrt(n);

        if(prev >= n)
            return -1;
    }

    for(int i = prev; i < min(step, n); i++) {
        cout << "Cek " << i << endl;

        if(arr[i].nomor == key) {
            swap(&arr[i], &arr[0]);

            cout << "Ditemukan!\n";
            cout << "Nama Kereta: " << arr[0].nama << endl;

            return 0;
        }
    }

    return -1;
}

//  SELECTION SORT (HARGA) 
void selectionSort(Kereta *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if((arr+j)->harga < (arr+min)->harga) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

//  MERGE SORT (URUT NAMA KERETA) 
void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[100], R[100];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i].nama <= R[j].nama) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

//  MAIN 
int main() {
    Kereta data[100];
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Rute \n";
        cout << "4. Cari Nomor \n";
        cout << "5. Urut Harga\n";
        cout << "6. Urut Nama\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambahKereta(data, n); break;
            case 2: tampil(data, n); break;
            case 3: linearSearch(data, n); break;

            case 4: {
                int key;
                cout << "Masukkan nomor: ";
                cin >> key;

                sortNomor(data, n);

                int idx = jumpSearch(data, n, key);
                if(idx != -1)
                    cout << "Ditemukan: " << data[idx].nama << endl;
                else
                    cout << "Tidak ditemukan\n";
                break;
            }

            case 5: selectionSort(data, n); break;
            case 6: mergeSort(data, 0, n-1); break;
            case 7:
                cout << "Program selesai...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while(pilih != 7);

    return 0;
}