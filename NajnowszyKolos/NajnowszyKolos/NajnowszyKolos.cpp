// NajnowszyKolos.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

struct Struktura {
    float x;
    char y;
};

// Funkcja do alokacji tablicy i inicjalizacji elementów
Struktura* Alokacja(const Struktura& wzorzec, int rozmiar) {
    Struktura* s = new Struktura[rozmiar + 1];
    s[0].y = static_cast<char>(rozmiar);  // Przechowujemy rozmiar w elemencie na pozycji -1 (jako char)
    for (int i = 1; i <= rozmiar; i++) {
        s[i] = wzorzec;  // Kopiujemy wzorcową instancję
    }
    return s + 1;  // Zwracamy wskaźnik przesunięty o jeden, aby s[-1] dawał dostęp do rozmiaru
}

// Funkcja do dealokacji tablicy
void Dealokacja(Struktura* s) {
    delete[](s - 1);  // Przesuwamy wskaźnik z powrotem i dealokujemy
    s = nullptr;
}

// Funkcja do zapisu tablicy do pliku w trybie tekstowym
void ZapisDoPliku(Struktura* s, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "w");
    if (plik == nullptr) {
        std::cerr << "Nie można otworzyć pliku do zapisu!" << std::endl;
        return;
    }

    int rozmiar = s[-1].y;  // Rozmiar jest zapisany w elemencie na pozycji -1
    fprintf(plik, "%d\n", rozmiar);  // Zapisujemy rozmiar

    for (int i = 0; i < rozmiar; i++) {
        fprintf(plik, "%f %c\n", s[i].x, s[i].y);
    }

    fclose(plik);
}

// Funkcja do odczytu tablicy z pliku w trybie tekstowym
Struktura* OdczytZPliku(const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik == nullptr) {
        std::cerr << "Nie można otworzyć pliku do odczytu!" << std::endl;
        return nullptr;
    }

    int rozmiar;
    fscanf(plik, "%d", &rozmiar);  // Odczytujemy rozmiar
    Struktura* s = new Struktura[rozmiar + 1];
    s[0].y = static_cast<char>(rozmiar);  // Przechowujemy rozmiar w elemencie na pozycji -1
    Struktura* ptr = s + 1;  // Przesuwamy wskaźnik, aby s[-1] dawał dostęp do rozmiaru

    for (int i = 0; i < rozmiar; i++) {
        fscanf(plik, "%f %c", &ptr[i].x, &ptr[i].y);
    }

    fclose(plik);
    return ptr;
}

// Funkcja do porównania dwóch tablic
bool PorownajTablice(Struktura* tab1, Struktura* tab2) {
    int rozmiar1 = tab1[-1].y;
    int rozmiar2 = tab2[-1].y;

    if (rozmiar1 != rozmiar2) {
        return false;
    }

    for (int i = 0; i < rozmiar1; i++) {
        if (tab1[i].x != tab2[i].x || tab1[i].y != tab2[i].y) {
            return false;
        }
    }

    return true;
}

int main() {
    Struktura wzorzec = { 3.14f, 'A' };

    // Tworzymy trzy tablice o różnych rozmiarach
    Struktura* tab1 = Alokacja(wzorzec, 5);
    Struktura* tab2 = Alokacja(wzorzec, 10);
    Struktura* tab3 = Alokacja(wzorzec, 15);

    // Zapisujemy najmniejszą i największą tablicę do plików
    ZapisDoPliku(tab1, "TablicaMin.txt");
    ZapisDoPliku(tab3, "TablicaMax.txt");

    // Odczytujemy zapisane tablice do nowych wskaźników
    Struktura* odczytMin = OdczytZPliku("TablicaMin.txt");
    Struktura* odczytMax = OdczytZPliku("TablicaMax.txt");
    std::cout << (int)odczytMin[-1].y<<std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << odczytMin[i].x << " " << odczytMin[i].y << std::endl;
    }

    // Sprawdzamy, czy wczytane tablice są identyczne z pierwowzorami
    bool takieSameMin = PorownajTablice(tab1, odczytMin);
    bool takieSameMax = PorownajTablice(tab3, odczytMax);

    // Wyświetlamy wyniki porównania
    std::cout << "Tablice minimalne są " << (takieSameMin ? "takie same" : "różne") << std::endl;
    std::cout << "Tablice maksymalne są " << (takieSameMax ? "takie same" : "różne") << std::endl;

    // Dealokujemy pamięć
    Dealokacja(tab1);
    Dealokacja(tab2);
    Dealokacja(tab3);
    Dealokacja(odczytMin);
    Dealokacja(odczytMax);

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
