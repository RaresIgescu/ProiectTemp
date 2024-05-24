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

template <class T1, class T2, class T3>
MasinaDiesel<T1, T2, T3>::MasinaDiesel(const T1& marca,const T1& model, T2 pret, T3 an, T3 rezervor, T3 poluare,
                                       const T1& motor): Masina<T1, T2, T3>(marca, model, pret, an), CapacitateRezervor(rezervor), NivelPoluare(poluare), FirmaMotor(motor) {}

template <class T1, class T2, class T3>
MasinaDiesel<T1, T2, T3>::~MasinaDiesel() =default;

template <class T1, class T2, class T3>
MasinaDiesel<T1, T2, T3>& MasinaDiesel<T1, T2, T3>::operator=(const MasinaDiesel& diesel) = default;

template <class T1, class T2, class T3>
bool MasinaDiesel<T1, T2, T3>::operator==(const MasinaDiesel &diesel) const{
    return Masina<T1, T2, T3>::operator==(diesel) and CapacitateRezervor == diesel.CapacitateRezervor and NivelPoluare == diesel.NivelPoluare;
}

template <class T1, class T2, class T3>
T2 MasinaDiesel<T1, T2, T3>::ObtinePretPePiata() const {
    T2 PretFinal = this->Pret;
    if (this->An != 2024)
    {
        cout << "Masina nu este noua, dar pentru ca este pe diesel va suferi o penalizare mai mare" << "\n";
        if (NivelPoluare < 5)
        {
            cout << "Masina polueaza forte tare, pretul final va fi de:  ";
            return  PretFinal - (PretFinal / 25);
        }
        else
        {
            cout << "Itemii de poluare sunt la nivel normal, pretul final este de:  ";
            return PretFinal - (2 * PretFinal / 25);
        }
    }
    else
    {
        cout << "Masina este noua, asa ca pretul va suferi doar adaosul comercial" << "\n";
        if (NivelPoluare < 5)
        {
            cout << "Masina polueaza forte tare, pretul final va fi de:  ";
            return  PretFinal - (PretFinal / 20);
        }
        else
        {
            cout << "Itemii de poluare sunt la nivel normal, pretul final este de:  ";
            return PretFinal - (3 * PretFinal / 25);
        }
    }
}

template <class T1, class T2, class T3>
istream& operator>>(istream& in, MasinaDiesel<T1, T2, T3>& car) {
    cout << "Marca masinii: " << endl;
    in >> car.Marca;

    cout << "Modelul masinii: " << endl;
    in >> car.Model;

    cout << "Pretul masinii: " << endl;
    in >> car.Pret;

    cout << "Anul de fabricatie: " << endl;
    in >> car.An;

    cout << "Capacitatea Rezervorului: " << "\n";
    in >> car.CapacitateRezervor;

    cout << "Nivelul de poluare " << "\n";
    in >> car.NivelPoluare;

    cout << "Firma motorului " << "\n";
    in >> car.FirmaMotor;

    return in;
}

template <class T1, class T2, class T3>
ostream& operator<<(ostream& out, const MasinaDiesel<T1, T2, T3>& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    out << "Capacitatea rezervorului: " << car.CapacitateRezervor << endl;
    out << "Nivelul de poluare: " << car.NivelPoluare << endl;
    out << "Firma motorului: " << car.FirmaMotor << endl;
    return out;
}

#endif //PROIECT_MASINADIESEL_H
