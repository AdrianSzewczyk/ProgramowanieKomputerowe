#include "Funkcje.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

void Alokacja(Tablica& t, int r) {
    t.rozmiar = r;
    t.tab = new int[r];
}

void Dealokacja(Tablica& t) {
    delete[] t.tab;
    t.tab = nullptr;
    t.rozmiar = 0;
}
void ZapisDoPliku(const Tablica& t) {
    FILE* plik = fopen("Plik.txt", "w");
    if (plik == nullptr) {
        cerr << "Nie mo¿na otworzyæ pliku do zapisu!" << endl;
        return;
    }
    for (int i = 0; i < t.rozmiar; i++) {
        fprintf(plik, "%d;", t.tab[i]);
    }
    fclose(plik);
}

void OdczytZPliku(Tablica& t) {
    FILE* plik = fopen("Plik.txt", "r");
    if (plik == nullptr) {
        cerr << "Nie mo¿na otworzyæ pliku do odczytu!" << endl;
        return;
    }
    for (int i = 0; i < t.rozmiar; i++) {
        fscanf(plik, "%d;", &t.tab[i]);
    }
    fclose(plik);
}