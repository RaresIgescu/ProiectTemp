//
// Created by riges on 4/13/2024.
//
#include <iostream>
#include <string>
#include <utility>
#include "Masina.h"
using namespace std;

Masina::Masina(string marca, string model , double pret, int an): Marca(std::move(marca)), Model(std::move(model)), Pret(pret), An(an) {}

Masina::Masina(string& marca, string& model, double pret): Marca(std::move(marca)), Model(std::move(model)), Pret(pret), An(2024) {}

Masina& Masina::operator=(const Masina& car1) = default;

Masina::Masina(const Masina& car) =default;

Masina::~Masina () =default;

int Masina::operator==(const Masina& car) const{
    return car.Marca == Marca and car.Model == Model and car.An == An;
}

string Masina::GetMarca() const {
    return Marca;
}

string Masina::GetModel() const {
    return Model;
}

double Masina::GetPret() const {
    return Pret;
}

int Masina::GetAn() const {
    return An;
}

istream& operator>>(istream& in, Masina& car) {
    cout << "Marca masinii: " << endl;
    in >> car.Marca;

    cout << "Modelul masinii: " << endl;
    in >> car.Model;

    cout << "Pretul masinii: " << endl;
    in >> car.Pret;

    cout << "Anul de fabricatie: " << endl;
    in >> car.An;

    return in;
}

ostream& operator<<(ostream& out, const Masina& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    return out;
}

double Masina::ObtinePretPePiata() const {
    double PretFinal = Pret;
    if (An != 2024)
    {
        cout << "Masina nu este noua deci se va aplica o penalizare mai mare asupra pretului" << "\n";
        cout << "Pretul final este de: ";
        return PretFinal - (PretFinal / 10);
    }
    else
    {
        cout << "Pentru ca masina este noua asupra pretului se va adauga doar adaosul comercial" << "\n";
        cout << "Pretul final este de: ";
        return PretFinal - (3 * PretFinal / 100);
    }
}
