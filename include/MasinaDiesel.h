//
// Created by riges on 4/15/2024.
//

#ifndef PROIECT_MASINADIESEL_H
#define PROIECT_MASINADIESEL_H
#include <iostream>
#include <string>
#include "Masina.h"

template <class T1, class T2, class T3>
class MasinaDiesel : public Masina<T1, T2, T3> {
private:
    T3 CapacitateRezervor;
    T3 NivelPoluare;
    T1 FirmaMotor;
public:
    explicit MasinaDiesel(const T1& marca = "",const T1& model = "", T2 pret = 0, T3 an = 0, T3 rezervor = 0, T3 poluare = 0,const T1& motor = "");

    ~MasinaDiesel() override;

    MasinaDiesel & operator=(const MasinaDiesel& diesel);

    bool operator==(const MasinaDiesel& diesel) const;

    [[nodiscard]] T2 ObtinePretPePiata() const override;

    template <class U1, class U2, class U3>
    friend istream& operator>>(istream& in, MasinaDiesel<U1,U2,U3>& car); //operator de citire supraincarcat
    template <class U1, class U2, class U3>
    friend ostream& operator<<(ostream& out, const MasinaDiesel<U1,U2,U3>& car);
};


#endif //PROIECT_MASINADIESEL_H
