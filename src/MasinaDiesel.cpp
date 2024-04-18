//
// Created by riges on 4/15/2024.
//
#include <iostream>
#include <string>
#include <utility>
#include "MasinaDiesel.h"


MasinaDiesel::MasinaDiesel(std::string marca, std::string model, float pret, int an, int rezervor, int poluare,
                           std::string motor): Masina(std::move(marca), std::move(model), pret, an), CapacitateRezervor(rezervor), NivelPoluare(poluare), FirmaMotor(std::move(motor)) {}

MasinaDiesel::~MasinaDiesel() =default;

MasinaDiesel & MasinaDiesel::operator=(const MasinaDiesel& diesel) = default;

bool MasinaDiesel::operator==(const MasinaDiesel &diesel) const{
    return Masina::operator==(diesel) and CapacitateRezervor == diesel.CapacitateRezervor and NivelPoluare == diesel.NivelPoluare;
}

float MasinaDiesel::ObtinePretPePiata() const {
    float PretFinal = Pret;
    if (An != 2024)
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
    return 0;
}

istream& operator>>(istream& in, MasinaDiesel& car) {
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

ostream& operator<<(ostream& out, const MasinaDiesel& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    out << "Capacitatea rezervorului: " << car.CapacitateRezervor << endl;
    out << "Nivelul de poluare: " << car.NivelPoluare << endl;
    out << "Firma motorului: " << car.FirmaMotor << endl;
    return out;
}
