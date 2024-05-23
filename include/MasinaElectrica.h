//
// Created by riges on 4/14/2024.
//

#ifndef PROIECT_MASINAELECTRICA_H
#define PROIECT_MASINAELECTRICA_H
#include <iostream>
#include <vector>
#include <string>
#include "Masina.h"

template <class T1, class T2, class T3>
class MasinaElectrica : public Masina<T1, T2, T3> {
private:
    T3 Autonomie;
    T3 TimpIncarcare;
    T3 ProcentBaterie;
    T1 NumeBaterie;
public:
    explicit MasinaElectrica(T1 marca = "", T1 model = "", T2 pret = 0, T3 an = 0, T3 autonomie = 0, T3 timpinc = 0, T3 procent = 0,  T1 baterie = "");

    MasinaElectrica & operator=(const MasinaElectrica& elec);

    bool operator==(const MasinaElectrica& elec) const;

    ~MasinaElectrica()override;

    [[nodiscard]] T2 ObtinePretPePiata() const override;

    [[nodiscard]] T3 CreeazaMasinaElectrica() const override;

    friend istream& operator>>(istream& in, MasinaElectrica& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const MasinaElectrica& car); //operator de afisare supraincarcat
};

#endif //PROIECT_MASINAELECTRICA_H
