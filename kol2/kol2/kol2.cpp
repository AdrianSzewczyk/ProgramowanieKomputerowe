// kol2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Funkcje.h"

using namespace std;







int main() {
    Tablica tablica1;
    Alokacja(tablica1, 5);
    for (int i = 0; i < 5; i++) {
        tablica1.tab[i] = i;
    }

    ZapisDoPliku(tablica1);

    Tablica tablicaOdczyt;
    Alokacja(tablicaOdczyt, 5);
    OdczytZPliku(tablicaOdczyt);

    for (int i = 0; i < 5; i++) {
        cout << tablicaOdczyt.tab[i] << " ";
    }
    cout << endl;

    bool takieSame = true;
    for (int i = 0; i < 5; i++) {
        if (tablicaOdczyt.tab[i] != tablica1.tab[i]) {
            cout << "Tablice są różne" << endl;
            takieSame = false;
            break;
        }
    }

    if (takieSame) {
        cout << "Tablice są takie same" << endl;
    }

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
