#include <iostream>
#include <fstream>
#include<cstdlib>
#include"Deklaracje.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc < 2) {
		cout << "Brak argumentow";
		return 0;
	}
	fstream dane;
	otworz_plik(dane, argv);
	LOT* pGlowa = nullptr;
	int pasazer = 0;
	dodaj_do_listy_rekurencyjnie(pGlowa, dane, pasazer);
	dane.close();
	segreguj_liste(pGlowa, pasazer);
	utworz_pliki(pGlowa, dane);
	usun_liste(pGlowa);

	return 0;
}