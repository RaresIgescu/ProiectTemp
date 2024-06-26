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
    explicit MasinaElectrica(const T1& marca = "",const T1& model = "", T2 pret = 0, T3 an = 0, T3 autonomie = 0, T3 timpinc = 0, T3 procent = 0,  T1 baterie = "");

    MasinaElectrica & operator=(const MasinaElectrica& elec);

    bool operator==(const MasinaElectrica& elec) const;

    ~MasinaElectrica()override;

    [[nodiscard]] T2 ObtinePretPePiata() const override;

    [[nodiscard]] T3 CreeazaMasinaElectrica() const override;

    template <class U1, class U2, class U3>
    friend istream& operator>>(istream& in, MasinaElectrica<U1,U2,U3>& car); //operator de citire supraincarcat
    template <class U1, class U2, class U3>
    friend ostream& operator<<(ostream& out, const MasinaElectrica<U1,U2,U3>& car); //operator de afisare supraincarcat
};

template <class T1, class T2, class T3>
MasinaElectrica<T1, T2, T3>::MasinaElectrica(const T1& marca, const T1& model, T2 pret, T3 an, T3 autonomie, T3 timpinc, T3 procent, T1 baterie) : Masina<T1, T2, T3>(marca, model, pret, an), Autonomie(autonomie), TimpIncarcare(timpinc), ProcentBaterie(procent), NumeBaterie(std::move(baterie)) {}

template <class T1, class T2, class T3>
MasinaElectrica<T1, T2, T3>& MasinaElectrica<T1, T2, T3>::operator=(const MasinaElectrica& elec) {
    Masina<T1, T2, T3>::operator=(elec);
    this->Autonomie = elec.Autonomie;
    this->TimpIncarcare = elec.TimpIncarcare;
    this->NumeBaterie = elec.NumeBaterie;
    return *this;
}

template <class T1, class T2, class T3>
bool MasinaElectrica<T1, T2, T3>::operator==(const MasinaElectrica &elec) const{
    return Masina<T1, T2, T3>::operator==(elec) and Autonomie == elec.Autonomie and NumeBaterie == elec.NumeBaterie;
}

template <class T1, class T2, class T3>
MasinaElectrica<T1, T2, T3>::~MasinaElectrica() =default;

template <class T1, class T2, class T3>
T2 MasinaElectrica<T1, T2, T3>::ObtinePretPePiata() const {
    double PretFinal = this->Pret;
    if (this->An != 2024)
    {
        cout << "Masina nu este noua, dar pentru ca este electrica va suferi o penalizare redusa" << "\n";
        if (ProcentBaterie > 75) {
            cout << "Baterie este optima pentru functionare, pretul final este de: " << PretFinal - (PretFinal / 20);
        } else {
            cout << "Nivelul bateriei nu este unul optim, va putem oferi doar: " << PretFinal - (2 * PretFinal / 25);
            return PretFinal - (2 * PretFinal / 25);
        }
    }
    else
    {
        cout << "Masina este noua, asa ca pretul va suferi doar adaosul comercial" << "\n";
        if (ProcentBaterie > 75)
        {
            cout << "Baterie este optima pentru functionare, pretul final este de: ";
            return PretFinal - (3 * PretFinal / 100);
        }
        else
        {
            cout << "Bateria nu este la un nivel optim de functionare, va putem oferi doar: ";
            return PretFinal - (PretFinal / 20);
        }
    }
    return 0;
}

template <class T1, class T2, class T3>
T3 MasinaElectrica<T1, T2, T3>::CreeazaMasinaElectrica() const {
    if (Autonomie <= 0)
    {
        throw std::invalid_argument(" nu este functionala.");
    }
    else
        return 1;
}

template <class T1, class T2, class T3>
istream& operator>>(istream& in, MasinaElectrica<T1, T2, T3>& car) {
    cout << "Marca masinii: " << endl;
    in >> car.Marca;

    cout << "Modelul masinii: " << endl;
    in >> car.Model;

    cout << "Pretul masinii: " << endl;
    in >> car.Pret;

    cout << "Anul de fabricatie: " << endl;
    in >> car.An;

    cout << "Autonomie: " << "\n";
    in >> car.Autonomie;

    cout << "Timpul de incarcare al bateriei: " << "\n";
    in >> car.TimpIncarcare;

    cout << "Procentajul bateriei: " << "\n";
    in >> car.ProcentBaterie;

    cout << "Producatorul bateriei: " << "\n";
    in >> car.NumeBaterie;

    return in;
}

template <class T1, class T2, class T3>
ostream& operator<<(ostream& out, const MasinaElectrica<T1, T2, T3>& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    out << "Autonomie: " << car.Autonomie << endl;
    out << "Timp Incarcare: " << car.TimpIncarcare << endl;
    out << "Procent Baterie: " << car.ProcentBaterie << endl;
    out << "Numele Bateriei: " << car.NumeBaterie << endl;
    return out;
}

#endif //PROIECT_MASINAELECTRICA_H
