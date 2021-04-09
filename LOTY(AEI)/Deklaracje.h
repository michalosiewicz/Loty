#pragma once
/**@file*/
#ifndef DEKLARACJE_H
#define DEKLARACJE_H
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>


using namespace std;
/**lista jednokierunkowa lotow
*/
struct LOT {
	string symbol;///< symbol lotu
	string data;///< data lotu
	string startowe;///< lotnisko startowe
	string docelowe;///< lotnisko docelowe
	string imie;///< imie pasazera
	string nazwisko;///< nazwisko pasazera
	int miejsce;///< numer miejsca pasazera
	LOT* pNext;///< wskaznik na nastepny LOT
};
/**funkcja otwiera plik danych z dysku i sprawdza jego istnienie.
*@param plik plik z ktorego odczytywane sa dane
*@param argv nazwa pliku z ktorego odczytywane sa dane
*@return Funkcja nie zwraca niczego
*/
void otworz_plik(fstream& plik, char** argv);

/**funkcja zapisuje dane z pliku do listy jednokierunkowej
*@param pHead wskaznik na pierwszy element listy
*@param plik plik z ktorego odczytywane sa dane
*@param pasazer zmienna liczaca ilosc wierszy w pliku
*@return Funkcja nie zwraca niczego
*/
void dodaj_do_listy_rekurencyjnie(LOT*& pHead, fstream& plik, int& pasazer);

/**funkcja segreguje liste babelkowo wedlug miejsc pasazerow(a)
*@param pHead wskaznik na pierwszy element listy
*@param pasazer zmienna liczaca ilosc wierszy w pliku
*@return Funkcja nie zwraca niczego
*/
void segreguj_liste_a(LOT*& pHead, int pasazer);

/**funkcja segregujaca liste babelkowo wedlug miejsc pasazerow,mam w sobie funkcje pomocnicza segreguj_liste_a
*@param pHead wskaznik na pierwszy element listy
*@param pasazer zmienna liczaca ilosc wierszy w pliku
*@return Funkcja nie zwraca niczego
*/
void segreguj_liste(LOT*& pHead, int pasazer);

/**funkcja tworzy pliki danych(lotow)
*@param pHead wskaznik na pierwszy element listy
*@param plik tworzony plik z danymi
*@return Funkcja nie zwraca niczego
*/
void utworz_pliki(LOT* pHead, fstream& plik);

/**funkcja usuwa liste
*@param pHead wskaznik na pierwszy element listy
*@return Funkcja nie zwraca niczego
*/
void usun_liste(LOT*& pHead);



#endif
