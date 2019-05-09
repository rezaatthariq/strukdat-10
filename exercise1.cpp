/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 8 Mei 2019
Deskripsi	: Program Circular Queue Array
*/

#include<iostream>
using namespace std;

const int maxElement=5;

struct Queue
{
	char isi[maxElement];
	int Head;
	int Tail;
};

void createQueue (Queue& Q)
{
	Q.Head=0;
	Q.Tail=-1;
};

void enqueue (Queue& Q, char element)
{
	if (Q.Tail==maxElement-1)
	{
		Q.Tail=Q.Head;
		Q.Head++;
		Q.isi[Q.Tail]=element;
	}
	else
	{
		Q.Tail=Q.Tail+1;
		Q.isi[Q.Tail]=element;
	}
}

void dequeue (Queue& Q, char& elementHapus)
{
	if (Q.Head==-1) cout << "Antrian kosong!";
	else 
	{
		elementHapus=Q.isi[Q.Head];
		for (int i=0; i<Q.Tail; i++)
		{
			Q.isi[i]=Q.isi[i+1];
		}
		
		Q.Tail=Q.Tail-1;
	}
}

void printQueue (Queue Q)
{
	if (Q.Head<Q.Tail)
	{
		for (int i=0; i<=Q.Tail; i++)
		{	
			cout << Q.isi[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i=Q.Head; i<maxElement; i++)
		{
			cout << Q.isi[i] << " ";
		}
		for (int i=0; i<=Q.Tail; i++)
		{
			cout << Q.isi[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Queue Q;
	char element,elementHapus,jawab;
	int pilihan;
	
	createQueue(Q);
	do{
		cout << "\n1. Tambah Antrian\n2. Keluarkan dari Antrian\n3. Tampilkan Antrian\n";
		cout << "Pilih Menu : "; cin >> pilihan;
		switch(pilihan)
		{
			case 1: 
				cout << "Masukkan Inisial : ";cin >> element; 
				enqueue(Q,element); 
				break;
		
			case 2: 
				dequeue(Q,elementHapus); 
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

