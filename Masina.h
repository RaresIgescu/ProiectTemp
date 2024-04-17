//
// Created by riges on 4/13/2024.
//

#ifndef PROIECT_MASINA_H
#define PROIECT_MASINA_H

#include <string>
#include <iostream>

using namespace std;

class Masina {
private:
    string Marca;
    string Model;

protected:
    float Pret;
    int An;

public:
    explicit Masina(string  marca = "",string  model = "", float pret = 0, int an = 0);

    Masina(string& marca, string& model, float pret);

    Masina& operator=(const Masina& car1);

    Masina(const Masina& car);

    virtual ~Masina ();

    int operator==(const Masina& car) const;

    string GetMarca() const;

    string GetModel() const;

    float GetPret() const;

    int GetAn() const;

    virtual float ObtinePretPePiata() const;

    virtual int CreeazaMasinaElectrica() const {}

    friend istream& operator>>(istream& in, Masina& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const Masina& car); //operator de afisare supraincarcat
};
#endif //PROIECT_MASINA_H
