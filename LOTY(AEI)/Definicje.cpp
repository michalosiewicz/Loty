#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Deklaracje.h"

using namespace std;


void otworz_plik(fstream& plik, char** argv) {
	plik.open(argv[1], ios::in);
	if (plik.good())
		cout << "Udalo sie otworzyc plik z danymi." << endl;
	else
	{
		cout << "Nie udalo sie otworzyc pliku z danymi." << endl;
		exit(0);
	}
};

void dodaj_do_listy_rekurencyjnie(LOT*& pHead, fstream& plik, int& pasazer) {
	int nr_danej = 1;
	string dana;
	while (getline(plik, dana, ',')) {
		if (not pHead) {
			pHead = new LOT;
			pHead->pNext = nullptr;
		}
		switch (nr_danej) {
		case 1:
			if (pasazer > 0)
				dana.erase(0, 1);
			pasazer++;
			(*pHead).symbol = dana;
			break;
		case 2:
			(*pHead).data = dana;
			break;
		case 3:
			(*pHead).startowe = dana;
			break;
		case 4:
			(*pHead).docelowe = dana;
			break;
		case 5:
			(*pHead).imie = dana;
			break;
		case 6:
			(*pHead).nazwisko = dana;
			break;
		case 7:
			(*pHead).miejsce = atoi(dana.c_str());
			dodaj_do_listy_rekurencyjnie(pHead->pNext, plik, pasazer);
		}
		nr_danej++;
	}
};

void segreguj_liste_a(LOT*& pHead, int pasazer) {
	if (pasazer > 2) {
		if (pHead->pNext->miejsce > pHead->pNext->pNext->miejsce) {

			LOT* B = pHead->pNext;
			LOT* C = pHead->pNext->pNext;
			LOT* D = pHead->pNext->pNext->pNext;

			pHead->pNext = C;
			pHead->pNext->pNext = B;
			pHead->pNext->pNext->pNext = D;
		}
		pasazer--;
		segreguj_liste_a(pHead->pNext, pasazer);
	}
};

void segreguj_liste(LOT*& pHead, int pasazer) {
	for (int x = 1; x < pasazer; x++) {
		if (pHead->miejsce > pHead->pNext->miejsce) {
			LOT* C = pHead;
			LOT* A = pHead->pNext;
			LOT* B = pHead->pNext->pNext;

			pHead = A;
			pHead->pNext = C;
			pHead->pNext->pNext = B;


		}
		segreguj_liste_a(pHead, pasazer);
	}
}

void utworz_pliki(LOT* pHead, fstream& plik) {
	while (pHead) {
		plik.open(pHead->symbol + ".txt", ios::in);
		if (plik.good()) {
			plik.close();
			plik.open(pHead->symbol + ".txt", ios::app);
			plik << endl << pHead->miejsce << ". " << pHead->imie << " " << pHead->nazwisko;
			plik.close();
		}
		else {
			plik.close();
			plik.open(pHead->symbol + ".txt", ios::out);
			plik << pHead->data << ",";
			plik << pHead->startowe << ",";
			plik << pHead->docelowe << endl;
			plik << pHead->miejsce << ". " << pHead->imie << " " << pHead->nazwisko;
			plik.close();
		}
		pHead = pHead->pNext;
	}
};

void usun_liste(LOT*& pHead) {
	while (pHead)
	{
		LOT* pNastepnik = pHead->pNext;
		delete pHead;
		pHead = pNastepnik;
	}
};