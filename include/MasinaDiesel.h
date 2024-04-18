//
// Created by riges on 4/15/2024.
//

#ifndef PROIECT_MASINADIESEL_H
#define PROIECT_MASINADIESEL_H
#include <iostream>
#include <string>
#include "Masina.h"

class MasinaDiesel : public Masina {
private:
    int CapacitateRezervor;
    int NivelPoluare;
    string FirmaMotor;
public:
    MasinaDiesel(string marca = "", string model = "", float pret = 0, int an = 0, int rezervor = 0, int poluare = 0, string motor = "");

    ~MasinaDiesel();

    int GetRezervor() const;

    int GetPoluare() const;

    string GetMotor() const;

    MasinaDiesel & operator=(const MasinaDiesel& diesel);

    bool operator==(const MasinaDiesel& diesel) const;
};


#endif //PROIECT_MASINADIESEL_H
