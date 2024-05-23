//
// Created by riges on 4/14/2024.
//

#ifndef PROIECT_BANCA_H
#define PROIECT_BANCA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Banca {
private:
    string Nume;
    double TVA;
    vector <int> NumarRate;

public:
    Banca(string nume, double tva, const vector <int>& rate);

    [[nodiscard]] string GetNume() const;

    [[nodiscard]] double CalculPretFinal(double pret) const;

    [[nodiscard]] double GetRataLunara(double pret) const;

    void afisare() const;

};
#endif //PROIECT_BANCA_H
