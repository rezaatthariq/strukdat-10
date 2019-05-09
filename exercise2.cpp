/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 8 Mei 2019
Deskripsi	: Program Circular Queue Linked List
*/

#include<iostream>
using namespace std;

struct isiQueue
{
	char info;
	isiQueue* next;
};
typedef isiQueue* pointer;
typedef pointer List;

struct Queue
{
	List Head;
	List Tail;
};
Queue Q;

void createQueue (Queue& Q)
{
	Q.Head=Q.Tail=NULL;
}

void createElmt (pointer& pBaru)
{
	pBaru=new isiQueue;
	cout << "Masukkan Inisial : "; cin >> pBaru->info;
	pBaru->next=NULL;
}

void enqueue(Queue& Q, pointer pBaru)
{
	if (Q.Head==NULL && Q.Tail == NULL)
	{
		Q.Head=pBaru;
		Q.Tail=pBaru;
	}
	else
	{
		Q.Tail->next=pBaru;
		Q.Tail=pBaru;
	}
}

void dequeue(Queue& Q, pointer pHapus)
{
	if (Q.Head==NULL && Q.Tail==NULL)
	{
		pHapus=NULL;
		cout << "Antrian kosong!" << endl;
	}
	else if (Q.Head->next==NULL)
	{
		pHapus=Q.Head;
		Q.Head=NULL;
		Q.Tail=NULL;
	}
	else 
	{
		pHapus=Q.Head;
		Q.Head=Q.Head->next;
		pHapus->next=NULL;
	}
}

void printQueue(Queue Q)
{
	pointer pBantu;
	if(Q.Head==NULL && Q.Tail==NULL ) cout << "Antrian kosong!" << endl;
	else
	{	
		pBantu=Q.Head;
		do 
		{
			cout << pBantu->info << " ";
			pBantu=pBantu->next;
		} 
		while (pBantu!=NULL);
	}
	cout << endl;
}

int main()
{
	Queue Q;
	pointer p, pHapus;
	char jawab;
	int pilihan;
	
	createQueue(Q);
	do{
		cout << "\n1. Tambah Antrian\n2. Keluarkan dari Antrian\n3. Tampilkan Antrian\n";
		cout << "Pilih Menu : "; cin >> pilihan;
		switch(pilihan)
		{
			case 1: 
				createElmt(p);
				enqueue(Q,p); 
				break;
		
			case 2: 
				dequeue(Q,pHapus); 
				break;
			
			case 3: 
				printQueue(Q);
				break;
		
			default: 
				cout << "Pilihan tidak tersedia"; 
				break;
		}
		cout << "Ingin Kembali ke Menu? (Y/N) "; cin >>jawab;	
	}while (jawab=='Y' ||jawab=='y');
}
