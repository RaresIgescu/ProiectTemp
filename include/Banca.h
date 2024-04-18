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
    float TVA;
    vector <int> NumarRate;

public:
    Banca(string  nume, float tva,const vector <int>& rate);

    [[nodiscard]] string GetNume() const;

    [[nodiscard]] float CalculPretFinal(float pret) const;

    [[nodiscard]] float GetRataLunara(float pret) const;

};
#endif //PROIECT_BANCA_H
