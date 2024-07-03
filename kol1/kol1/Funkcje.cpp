#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Funkcje.h"

using namespace std;

int ktoraTab = 1;

short* alokacja(int rozmiar) {
    short* tab = new short[rozmiar + 1] {};
    tab[0] = ktoraTab;
    tab[0] = tab[0] << 4;
    tab[0] = tab[0] | rozmiar;
    ktoraTab++;
    
    return tab + 1;
}

void ZapisdoPliku(short* tablica, const int rozmiar, const char* Nazwapliku) {
    FILE* plik = fopen(Nazwapliku, "w+b");
    if (plik != nullptr) {
        fwrite(tablica - 1, sizeof(short), rozmiar + 1, plik);
        fclose(plik);
    }
    else {
        cerr << "Nie mo¿na otworzyæ pliku do zapisu!" << std::endl;
    }
}

void OdczytzPliku(short* tablica, const int rozmiar, const char* Nazwapliku) {
    FILE* plik = fopen(Nazwapliku, "rb");
    if (plik != nullptr) {
        fread(tablica - 1, sizeof(short), rozmiar + 1, plik);
        fclose(plik);
    }
    else {
        cerr << "Nie mo¿na otworzyæ pliku do odczytu!" << std::endl;
    }
}