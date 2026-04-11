#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 100;

// ================= STRUCT =================
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

struct Queue {
    Tiket data[MAX];
    int front = 0;
    int rear = -1;
};

struct Stack {
    Tiket data[MAX];
    int top = -1;
};

int n = 0;

// ================= SWAP =================
void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

// ================= TAMBAH =================
void tambahKereta(Kereta *&arr, int &n) {
    int jml;
    cout << "\nJumlah data: ";
    cin >> jml;

    for(int i=0;i<jml;i++){
        cout<<"\nData ke-"<<i+1<<endl;
        cout<<"Nomor: "; cin>>(arr+n+i)->nomor;
        cout<<"Nama: "; cin>>(arr+n+i)->nama;
        cout<<"Asal: "; cin>>(arr+n+i)->asal;
        cout<<"Tujuan: "; cin>>(arr+n+i)->tujuan;
        cout<<"Harga: "; cin>>(arr+n+i)->harga;
    }
    n += jml;
}

// ================= TAMPIL =================
void tampil(Kereta *&arr, int n){
    for(int i=0;i<n;i++){
        cout<<"\nKereta "<<i+1<<endl;
        cout<<"Nomor: "<<(arr+i)->nomor<<endl;
        cout<<"Nama: "<<(arr+i)->nama<<endl;
        cout<<"Rute: "<<(arr+i)->asal<<"->"<<(arr+i)->tujuan<<endl;
        cout<<"Harga: "<<(arr+i)->harga<<endl;
    }
}

// ================= LINEAR SEARCH =================
void linearSearch(Kereta *&arr, int n){
    string asal, tujuan;
    cout<<"Cari asal: "; cin>>asal;
    cout<<"Cari tujuan: "; cin>>tujuan;

    bool ketemu=false;

    for(int i=0;i<n;i++){
        cout<<"Iterasi "<<i+1<<" cek "<<arr[i].asal<<"->"<<arr[i].tujuan<<endl;

        if(arr[i].asal==asal && arr[i].tujuan==tujuan){
            cout<<"Ditemukan: "<<arr[i].nama<<endl;
            swap(&arr[i], &arr[0]);
            ketemu=true;
        }
    }

    if(!ketemu) cout<<"Tidak ditemukan\n";
}

// ================= SORT + JUMP =================
void sortNomor(Kereta *&arr, int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].nomor < arr[min].nomor)
                min=j;
        }
        swap(&arr[i], &arr[min]);
    }
}

int jumpSearch(Kereta *&arr,int n,int key){
    int step=sqrt(n);
    int prev=0;

    while(arr[min(step,n)-1].nomor < key){
        prev=step;
        step+=sqrt(n);
        if(prev>=n) return -1;
    }

    for(int i=prev;i<min(step,n);i++){
        cout<<"Cek "<<i<<endl;
        if(arr[i].nomor==key){
            swap(&arr[i], &arr[0]);
            cout<<"Ditemukan: "<<arr[0].nama<<endl;
            return i;
        }
    }
    return -1;
}

// ================= SORT HARGA =================
void selectionSort(Kereta *&arr,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].harga < arr[min].harga)
                min=j;
        }
        swap(&arr[i], &arr[min]);
    }
}

// ================= MERGE SORT =================
void merge(Kereta *&arr,int l,int m,int r){
    Kereta L[100],R[100];
    int n1=m-l+1,n2=r-m;

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

void mergeSort(Kereta *&arr,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// ================= QUEUE =================
void enqueue(Queue *q){
    if(q->rear==MAX-1){
        cout<<"Antrian penuh!\n"; return;
    }

    q->rear++;
    cout<<"Nama: "; cin>>q->data[q->rear].namaPenumpang;
    cout<<"Asal: "; cin>>q->data[q->rear].asal;
    cout<<"Tujuan: "; cin>>q->data[q->rear].tujuan;
}

Tiket dequeue(Queue *q){
    Tiket t;

    if(q->rear < q->front){
        cout<<"Antrian kosong!\n";
        return t;
    }

    t = q->data[q->front];
    cout<<"Diproses: "<<t.namaPenumpang<<endl;

    q->front++;
    return t;
}

void tampilQueue(Queue *q){
    if(q->rear < q->front){
        cout<<"Kosong\n"; return;
    }

    for(int i=q->front;i<=q->rear;i++){
        cout<<(q->data+i)->namaPenumpang<<" "
            <<(q->data+i)->asal<<"->"
            <<(q->data+i)->tujuan<<endl;
    }
}

void peekQueue(Queue *q){
    if(q->rear < q->front){
        cout<<"Kosong\n"; return;
    }
    cout<<"Depan: "<<q->data[q->front].namaPenumpang<<endl;
}

// ================= STACK =================
void push(Stack *s,Tiket t){
    if(s->top==MAX-1){
        cout<<"Stack penuh!\n"; return;
    }
    s->data[++s->top]=t;
}

void pop(Stack *s){
    if(s->top==-1){
        cout<<"Kosong\n"; return;
    }
    cout<<"Hapus: "<<s->data[s->top--].namaPenumpang<<endl;
}

void tampilStack(Stack *s){
    if(s->top==-1){
        cout<<"Kosong\n"; return;
    }

    for(int i=0;i<=s->top;i++){
        cout<<(s->data+i)->namaPenumpang<<" "
            <<(s->data+i)->asal<<"->"
            <<(s->data+i)->tujuan<<endl;
    }
}

void peekStack(Stack *s){
    if(s->top==-1){
        cout<<"Kosong\n"; return;
    }
    cout<<"Terakhir: "<<s->data[s->top].namaPenumpang<<endl;
}

// ================= MAIN =================
int main(){
    Kereta data[100];
    Kereta *ptr=data;

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
            case 1: tambahKereta(ptr,n); break;
            case 2: tampil(ptr,n); break;
            case 3: linearSearch(ptr,n); break;

            case 4:{
                int key; cin>>key;
                sortNomor(ptr,n);
                jumpSearch(ptr,n,key);
                break;
            }

            case 5: selectionSort(ptr,n); break;
            case 6: mergeSort(ptr,0,n-1); break;

            case 7: enqueue(&q); break;

            case 8:{
                Tiket t = dequeue(&q);
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