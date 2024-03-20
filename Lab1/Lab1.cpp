// Lab1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
//#define M_PI 3.14159265358979323846
using namespace std;
//constexpr double GRANICA_DOL = 0;
//constexpr double GRANICA_GOR = (M_PI/2);
//constexpr double H = (GRANICA_GOR - GRANICA_DOL) / 999;

int main()
{

    int LiczbaP = 5;
    int DodatkowyIterator=LiczbaP, IteratorW=0,IteratorW2=0;
    constexpr size_t rozmiar = 10000;
    double Granica_G, Granica_D,H;
    const double E = 10e-6;
    setlocale(LC_CTYPE, "Polish");
    double tabY[1000];
    cout << "Witaj w programie obliczającym całki numeryczne\n";
    do {
        cout << "Podaj Granice Całkowania\n";
        cin >> Granica_D; 
        cin >> Granica_G;
    } while (Granica_D >= Granica_G);
    H = (Granica_G - Granica_D) / (LiczbaP - 1);

    double calka[rozmiar];
    while (true){
        if (IteratorW2 > 0) {
            if (fabs(calka[DodatkowyIterator - LiczbaP] - calka[(DodatkowyIterator - LiczbaP) - 1]) > E) {
                if (IteratorW < LiczbaP) {
                    for (int i = 0; i < LiczbaP; i++) {
                        tabY[i] = cos(Granica_D + H * i);
                    }
                    for (int j = 1; j < LiczbaP; j++) {
                        calka[DodatkowyIterator - LiczbaP] += tabY[j - 1] + tabY[j];

                    }
                    IteratorW++;
                }
                else if (IteratorW == LiczbaP) {
                    LiczbaP *= 2;
                    DodatkowyIterator += 1;
                    H = (Granica_G - Granica_D) / (LiczbaP - 1);
                }

            }
            else {
                break;
            }
        }
        else IteratorW2++;
        
    }
    
    
    for (int k = 0; k < LiczbaP; k++) {
        calka[k] *= H / 2.0;
        cout << "Tyle wynosi całka dla S równego "<< k <<" "<< calka[k] << endl;
    }
    
    
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
