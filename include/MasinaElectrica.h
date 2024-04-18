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
    explicit MasinaElectrica(string marca = "", string model = "", float pret = 0, int an = 0, int autonomie = 0, int timpinc = 0, string baterie = "", int procent = 0);

    int GetAutonomie() const;

    int GetTimp() const;

    string GetBaterie() const;

    int GetProcent() const;

    MasinaElectrica & operator=(const MasinaElectrica& elec);

    bool operator==(const MasinaElectrica& elec) const;

    ~MasinaElectrica()override;

    float ObtinePretPePiata() const override;

    int CreeazaMasinaElectrica() const override;

};

#endif //PROIECT_MASINAELECTRICA_H
