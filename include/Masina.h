//
// Created by riges on 4/13/2024.
//

#ifndef PROIECT_MASINA_H
#define PROIECT_MASINA_H

#include <string>
#include <iostream>

using namespace std;

class Masina {
protected:
    string Marca;
    string Model;
    double Pret;
    int An;

public:
    explicit Masina(string  marca = "",string  model = "", double pret = 0, int an = 0);

    Masina(string& marca, string& model, double pret);

    Masina& operator=(const Masina& car1);

    Masina(const Masina& car);

    virtual ~Masina ();

    int operator==(const Masina& car) const;

    [[nodiscard]] string GetMarca() const;

    [[nodiscard]] string GetModel() const;

    [[nodiscard]] double GetPret() const;

    [[nodiscard]] virtual double ObtinePretPePiata() const;

    [[nodiscard]] virtual int CreeazaMasinaElectrica() const { return 0; }

    friend istream& operator>>(istream& in, Masina& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const Masina& car); //operator de afisare supraincarcat
};
#endif //PROIECT_MASINA_H
