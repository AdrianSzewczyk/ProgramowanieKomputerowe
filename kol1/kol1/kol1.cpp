// kol1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include "Funkcje.h"

using namespace std;




int main() {
    ktoraTab = 1;
    // Alokacja
    short* zmienna = alokacja(5);
    short* zmienna2 = alokacja(5);

    // Wyświetlanie bitów pierwszego elementu
    cout << bitset<8>(zmienna[-1]) << std::endl;
    cout << bitset<8>(zmienna2[-1]) << std::endl;

    // Zapis do pliku
    ZapisdoPliku(zmienna, 5, "Plik0.txt");

    // Przygotowanie tablicy do odczytu
    short* odczyt = new short[6];  // +1, aby pomieścić nagłówek
    odczyt++;  // Przesunięcie wskaźnika, aby zgodne było z alokacją

    // Odczyt z pliku
    OdczytzPliku(odczyt, 5, "Plik0.txt");

    // Wyświetlanie odczytanych danych
    for (int i = 0; i < 5; i++) {
        cout << odczyt[i] << " ";
    }
    cout << endl;

    // Czyszczenie pamięci
    delete[](odczyt - 1);  // Przesunięcie wskaźnika z powrotem
    delete[](zmienna - 1); // Przesunięcie wskaźnika z powrotem
    delete[](zmienna2 - 1); // Przesunięcie wskaźnika z powrotem
    ktoraTab = 1;

    // Alokacja kolejnych tablic
    short* tablica1 = alokacja(5);
    short* tablica2 = alokacja(6);
    short* tablica3 = alokacja(7);
    ZapisdoPliku(tablica1, 5, "Plik1.txt");
    ZapisdoPliku(tablica2, 6, "Plik2.txt");
    ZapisdoPliku(tablica3, 7, "Plik3.txt");

    // Wybór tablicy do odczytu przez użytkownika
    int wybor;
    const char* nazwaPliku;
    int rozmiar;
    cout << "Podaj numer tablicy którą chcesz odczytać (1, 2, 3): ";
    cin >> wybor;

    switch (wybor) {
    case 1:
        nazwaPliku = "Plik1.txt";
        rozmiar = 5;
        break;
    case 2:
        nazwaPliku = "Plik2.txt";
        rozmiar = 6;
        break;
    case 3:
        nazwaPliku = "Plik3.txt";
        rozmiar = 7;
        break;
    default:
        cerr << "Niepoprawny numer tablicy!" << std::endl;
        return 1;
    }

    short* tablicaDoOdczytu = new short[rozmiar + 1];
    tablicaDoOdczytu++;

    // Odczyt wybranej tablicy z pliku
    OdczytzPliku(tablicaDoOdczytu, rozmiar, nazwaPliku);

    // Wyświetlanie odczytanych danych
    cout << "Odczytana tablica: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablicaDoOdczytu[i] << " ";
    }
    cout << endl;
    //Sprawdzenie poprawnosci zapisu -1 elementu tablicy
    cout << bitset<8>(tablica1[-1]) << std::endl;
    cout << bitset<8>(tablica3[-1]) << std::endl;
    
    // Czyszczenie pamięci
    delete[](tablicaDoOdczytu - 1);
    delete[](tablica1 - 1);
    delete[](tablica2 - 1);
    delete[](tablica3 - 1);

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
