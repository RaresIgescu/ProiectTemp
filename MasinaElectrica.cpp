//
// Created by riges on 4/14/2024.
//
#include <iostream>
#include <string>
#include <utility>
#include "MasinaElectrica.h"

MasinaElectrica::MasinaElectrica(string marca, string model, float pret, int an, int autonomie, int timpinc, string baterie, int procent) : Masina(std::move(marca), std::move(model), pret, an), Autonomie(autonomie), TimpIncarcare(timpinc), NumeBaterie(std::move(baterie)), ProcentBaterie(procent) {}

int MasinaElectrica::GetAutonomie() const{
    return Autonomie;
}

int MasinaElectrica::GetTimp() const{
    return TimpIncarcare;
}

int MasinaElectrica::GetProcent() const {
    return ProcentBaterie;
}

string MasinaElectrica::GetBaterie() const{
    return NumeBaterie;
}

MasinaElectrica & MasinaElectrica::operator=(const MasinaElectrica& elec) {
    Masina::operator=(elec);
    this->Autonomie = elec.Autonomie;
    this->TimpIncarcare = elec.TimpIncarcare;
    this->NumeBaterie = elec.NumeBaterie;
    return *this;
}

bool MasinaElectrica::operator==(const MasinaElectrica &elec) const{
    return Masina::operator==(elec) and Autonomie == elec.Autonomie and NumeBaterie == elec.NumeBaterie;
}

MasinaElectrica::~MasinaElectrica() =default;

float MasinaElectrica::ObtinePretPePiata() const {
    float PretFinal = Pret;
        if (An != 2024)
        {
            cout << "Masina nu este noua, dar pentru ca este electrica va suferi o penalizare redusa" << "\n";
            if (ProcentBaterie > 75) {
                cout << "Baterie este optima pentru functionare, pretul final este de: " << PretFinal - (PretFinal / 20)
                     << "\n";
                return PretFinal - (PretFinal / 20);
            } else {
                cout << "Nivelul bateriei nu este unul optim, va putem oferi doar: " << PretFinal - (2 * PretFinal / 25)
                     << "\n";
                return PretFinal - (2 * PretFinal / 25);
            }
        }
        else
        {
        cout << "Masina este noua, asa ca pretul va suferi doar adaosul comercial" << "\n";
        if (ProcentBaterie > 75) {
            cout << "Baterie este optima pentru functionare, pretul final este de: "
                 << PretFinal - (3 * PretFinal / 100) << "\n";
            return PretFinal - (3 * PretFinal / 100);
        }
        else {
            cout << "Bateria nu este la un nivel optim de functionare, va putem oferi doar: "
                 << PretFinal - (PretFinal / 20) << "\n";
            return PretFinal - (PretFinal / 20);
        }
        }
    }

    int MasinaElectrica::CreeazaMasinaElectrica() const {
        if (Autonomie <= 0)
        {
            throw std::invalid_argument(" nu este functionala.");
        }
        else
            return 1;
}

