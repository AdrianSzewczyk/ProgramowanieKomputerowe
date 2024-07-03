#pragma once

struct Tablica {
    int* tab;
    int rozmiar;
};

void Alokacja(Tablica& t, int r);
void Dealokacja(Tablica& t);
void ZapisDoPliku(const Tablica& t);
void OdczytZPliku(Tablica& t);