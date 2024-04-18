//
// Created by riges on 4/14/2024.
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Banca.h"

Banca::Banca(string  nume, float tva,const vector <int>& rate): Nume(std::move(nume)), TVA(tva), NumarRate(rate) {}

string Banca::GetNume() const{
    return Nume;
}

float Banca::CalculPretFinal(float pret) const {
    return pret + (pret * (TVA/100));
}

float Banca::GetRataLunara(float pret) const{
    int NrRata = 0;
    int Indice;
    for(int i : NumarRate)
        cout << ++NrRata << ". " << i << "\n";
    cout << "Alegeti indecele numarului de rate." << "\n";
    cin >> Indice;
    return float(pret/NumarRate[Indice-1]);
}
