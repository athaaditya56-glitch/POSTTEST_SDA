#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;

//  STRUCT 
struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
};

// NODE 
struct Node {
    Tiket data;
    Node* next;
};

//  QUEUE
struct Queue {
    Node* front = NULL;
    Node* rear = NULL;
};

// STACK 
struct Stack {
    Node* top = NULL;
};

int n = 0;

//  SWAP 
void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

//  TAMBAH 
void tambahKereta(Kereta *arr, int &n) {
    int jml;
    cout << "\nJumlah data: ";
    cin >> jml;

    for(int i=0;i<jml;i++){
        cout<<"\nData ke-"<<i+1<<endl;
        cout<<"Nomor: "; cin>>arr[n+i].nomor;
        cout<<"Nama: "; cin>>arr[n+i].nama;
        cout<<"Asal: "; cin>>arr[n+i].asal;
        cout<<"Tujuan: "; cin>>arr[n+i].tujuan;
        cout<<"Harga: "; cin>>arr[n+i].harga;
    }
    n += jml;
}

//  TAMPIL 
void tampil(Kereta *arr, int n){
    for(int i=0;i<n;i++){
        cout<<"\nKereta "<<i+1<<endl;
        cout<<"Nomor: "<<arr[i].nomor<<endl;
        cout<<"Nama: "<<arr[i].nama<<endl;
        cout<<"Rute: "<<arr[i].asal<<"->"<<arr[i].tujuan<<endl;
        cout<<"Harga: "<<arr[i].harga<<endl;
    }
}

//  LINEAR SEARCH 
void linearSearch(Kereta *arr, int n){
    string asal, tujuan;
    cout<<"Cari asal: "; cin>>asal;
    cout<<"Cari tujuan: "; cin>>tujuan;

    bool ketemu=false;

    for(int i=0;i<n;i++){
        if(arr[i].asal==asal && arr[i].tujuan==tujuan){
            cout<<"Ditemukan: "<<arr[i].nama<<endl;
            swap(&arr[i], &arr[0]);
            ketemu=true;
        }
    }

    if(!ketemu) cout<<"Tidak ditemukan\n";
}

// SORT 
void sortNomor(Kereta *arr, int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].nomor < arr[min].nomor)
                min=j;
        }
        swap(&arr[i], &arr[min]);
    }
}

//  JUMP SEARCH 
int jumpSearch(Kereta *arr,int n,int key){
    int step=sqrt(n);
    int prev=0;

    while(arr[min(step,n)-1].nomor < key){
        prev=step;
        step+=sqrt(n);
        if(prev>=n) return -1;
    }

    for(int i=prev;i<min(step,n);i++){
        if(arr[i].nomor==key){
            cout<<"Ditemukan: "<<arr[i].nama<<endl;
            swap(&arr[i], &arr[0]);
            return i;
        }
    }
    return -1;
}

//  SORT HARGA
void selectionSort(Kereta *arr,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].harga < arr[min].harga)
                min=j;
        }
        swap(&arr[i], &arr[min]);
    }
}

//  MERGE SORT 
void merge(Kereta *arr,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    Kereta L[100],R[100];

    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i].nama <= R[j].nama)
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(Kereta *arr,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

//  QUEUE 
void enqueue(Queue *q){
    Node* baru = new Node;

    cout<<"Nama: "; cin>>baru->data.namaPenumpang;
    cout<<"Asal: "; cin>>baru->data.asal;
    cout<<"Tujuan: "; cin>>baru->data.tujuan;

    baru->next = NULL;

    if(q->rear == NULL){
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }
}

Tiket dequeue(Queue *q){
    Tiket t;

    if(q->front == NULL){
        cout<<"Antrian kosong!\n";
        return t;
    }

    Node* hapus = q->front;
    t = hapus->data;

    cout<<"Diproses: "<<t.namaPenumpang<<endl;

    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    delete hapus;
    return t;
}

void tampilQueue(Queue *q){
    if(q->front == NULL){
        cout<<"Antrian kosong!\n"; return;
    }

    Node* bantu = q->front;
    while(bantu != NULL){
        cout<<bantu->data.namaPenumpang<<" "
            <<bantu->data.asal<<"->"
            <<bantu->data.tujuan<<endl;
        bantu = bantu->next;
    }
}

void peekQueue(Queue *q){
    if(q->front == NULL){
        cout<<"Antrian kosong!\n"; return;
    }
    cout<<"Depan: "<<q->front->data.namaPenumpang<<endl;
}

//  STACK 
void push(Stack *s, Tiket t){
    Node* baru = new Node;
    baru->data = t;
    baru->next = s->top;
    s->top = baru;
}

void pop(Stack *s){
    if(s->top == NULL){
        cout<<"Riwayat kosong!\n"; return;
    }

    Node* hapus = s->top;
    cout<<"Hapus: "<<hapus->data.namaPenumpang<<endl;

    s->top = s->top->next;
    delete hapus;
}

void tampilStack(Stack *s){
    if(s->top == NULL){
        cout<<"Riwayat kosong!\n"; return;
    }

    Node* bantu = s->top;
    while(bantu != NULL){
        cout<<bantu->data.namaPenumpang<<" "
            <<bantu->data.asal<<"->"
            <<bantu->data.tujuan<<endl;
        bantu = bantu->next;
    }
}

void peekStack(Stack *s){
    if(s->top == NULL){
        cout<<"Riwayat kosong!\n"; return;
    }
    cout<<"Terakhir: "<<s->top->data.namaPenumpang<<endl;
}

// MAIN 
int main(){
    Kereta data[MAX];
    Queue q;
    Stack s;

    int pilih;

    do{
        cout<<"\n=== MENU ===\n";
        cout<<"1.Tambah\n2.Tampil\n3.Cari Rute\n4.Cari Nomor\n";
        cout<<"5.Sort Harga\n6.Sort Nama\n";
        cout<<"7.Enqueue\n8.Proses Tiket\n9.Tampil Antrian\n";
        cout<<"10.Tampil Riwayat\n11.Pop Riwayat\n12.Peek\n13.Keluar\n";
        cout<<"Pilih: "; cin>>pilih;

        switch(pilih){
            case 1: tambahKereta(data,n); break;
            case 2: tampil(data,n); break;
            case 3: linearSearch(data,n); break;

            case 4:{
                int key; cout<<"Nomor: "; cin>>key;
                sortNomor(data,n);
                jumpSearch(data,n,key);
                break;
            }

            case 5: selectionSort(data,n); break;
            case 6: mergeSort(data,0,n-1); break;

            case 7: enqueue(&q); break;

            case 8:{
                Tiket t = dequeue(&q);
                if(q.front != NULL || t.namaPenumpang != "")
                    push(&s,t);
                break;
            }

            case 9: tampilQueue(&q); break;
            case 10: tampilStack(&s); break;
            case 11: pop(&s); break;

            case 12:
                peekQueue(&q);
                peekStack(&s);
                break;

            case 13: cout<<"Selesai\n"; break;
        }

    }while(pilih!=13);

    return 0;
}