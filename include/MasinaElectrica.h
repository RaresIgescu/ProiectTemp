//
// Created by riges on 4/14/2024.
//

#ifndef PROIECT_MASINAELECTRICA_H
#define PROIECT_MASINAELECTRICA_H
#include <iostream>
#include <vector>
#include <string>
#include "Masina.h"

class MasinaElectrica : public Masina {
private:
    int Autonomie;
    int TimpIncarcare;
    int ProcentBaterie;
    string NumeBaterie;
public:
    explicit MasinaElectrica(string marca = "", string model = "", float pret = 0, int an = 0, int autonomie = 0, int timpinc = 0, int procent = 0,  string baterie = "");

    MasinaElectrica & operator=(const MasinaElectrica& elec);

    bool operator==(const MasinaElectrica& elec) const;

    ~MasinaElectrica()override;

    [[nodiscard]] float ObtinePretPePiata() const override;

    [[nodiscard]] int CreeazaMasinaElectrica() const override;

    friend istream& operator>>(istream& in, MasinaElectrica& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const MasinaElectrica& car); //operator de afisare supraincarcat
};

#endif //PROIECT_MASINAELECTRICA_H
