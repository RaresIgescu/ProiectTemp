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
    explicit MasinaDiesel(string marca = "", string model = "", float pret = 0, int an = 0, int rezervor = 0, int poluare = 0, string motor = "");

    ~MasinaDiesel() override;

    MasinaDiesel & operator=(const MasinaDiesel& diesel);

    bool operator==(const MasinaDiesel& diesel) const;

    [[nodiscard]] float ObtinePretPePiata() const override;

    friend istream& operator>>(istream& in, MasinaDiesel& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const MasinaDiesel& car);
};


#endif //PROIECT_MASINADIESEL_H
