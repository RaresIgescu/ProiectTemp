//
// Created by riges on 4/14/2024.
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Banca.h"

Banca::Banca(string nume, double tva,const vector <int>& rate): Nume(std::move(nume)), TVA(tva), NumarRate(rate) {}

double Banca::CalculPretFinal(double pret) const {
    return pret + (pret * (TVA/100));
}

double Banca::GetRataLunara(double pret) const{
    int NrRata = 0;
    int Indice;
    for(int i : NumarRate)
        cout << ++NrRata << ". " << i << "\n";
    cout << "Alegeti indicele numarului de rate." << "\n";
    cin >> Indice;
    return double(pret/NumarRate[Indice-1]);
}

void Banca::afisare() const {
    cout << Nume;
}
