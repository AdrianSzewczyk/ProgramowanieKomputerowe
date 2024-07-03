// kol3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Element {
    int i;
    double d;
};

struct Tablica {
    Element* tab;
    int rozmiar;
};

// Funkcja do alokacji tablicy instancji struktury o dwóch polach (int i double)
void Alokacja(Tablica& t, int rozmiar, const Element& wzorzec) {
    t.rozmiar = rozmiar;
    t.tab = new Element[rozmiar];
    for (int j = 0; j < rozmiar; j++) {
        t.tab[j] = wzorzec;
    }
}

// Funkcja do dealokacji tablicy
void Dealokacja(Tablica& t) {
    delete[] t.tab;
    t.tab = nullptr;
    t.rozmiar = 0;
}

// Funkcja do zapisu tablicy do pliku w trybie tekstowym
void ZapisDoPliku(const Tablica& t, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "w");
    if (plik == nullptr) {
        cerr << "Nie można otworzyć pliku do zapisu!" << endl;
        return;
    }
    fprintf(plik, "%d\n", t.rozmiar);
    for (int j = 0; j < t.rozmiar; j++) {
        fprintf(plik, "%d %lf\n", t.tab[j].i, t.tab[j].d);
    }
    fclose(plik);
}

// Funkcja do odczytu tablicy z pliku w trybie tekstowym
void OdczytZPliku(Tablica& t, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik == nullptr) {
        cerr << "Nie można otworzyć pliku do odczytu!" << endl;
        return;
    }
    fscanf(plik, "%d", &t.rozmiar);
    t.tab = new Element[t.rozmiar];
    for (int j = 0; j < t.rozmiar; j++) {
        fscanf(plik, "%d %lf", &t.tab[j].i, &t.tab[j].d);
    }
    fclose(plik);
}

bool PorownajTablice(const Tablica& t1, const Tablica& t2) {
    if (t1.rozmiar != t2.rozmiar) {
        return false;
    }
    for (int i = 0; i < t1.rozmiar; i++) {
        if (t1.tab[i].i != t2.tab[i].i || t1.tab[i].d != t2.tab[i].d) {
            return false;
        }
    }
    return true;
}

int main() {
    const char* nazwaPliku = "Tablica.txt";

    // Tworzenie instancji wzorcowej
    Element wzorzec = { 5, 3.14 };

    // Kod ASCII pierwszej litery nazwiska
    int rozmiar = static_cast<int>('N'); // Zmień 'N' na pierwszą literę Twojego nazwiska

    // Alokacja i inicjalizacja tablicy
    Tablica tablica1;
    Alokacja(tablica1, rozmiar, wzorzec);

    // Zapis do pliku
    ZapisDoPliku(tablica1, nazwaPliku);

    // Alokacja i odczyt tablicy z pliku
    Tablica tablicaOdczyt;
    OdczytZPliku(tablicaOdczyt, nazwaPliku);

    // Porównanie tablic binarnie
    bool takieSame = PorownajTablice(tablica1, tablicaOdczyt);

    // Wyświetlanie wyniku porównania
    if (takieSame) {
        cout << "Tablice są takie same" << endl;
    }
    else {
        cout << "Tablice są różne" << endl;
    }

    // Dealokacja pamięci
    Dealokacja(tablica1);
    Dealokacja(tablicaOdczyt);

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
