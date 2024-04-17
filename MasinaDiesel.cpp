//
// Created by riges on 4/15/2024.
//
#include <iostream>
#include <cstring>
#include "MasinaDiesel.h"


MasinaDiesel::MasinaDiesel(std::string marca, std::string model, float pret, int an, int rezervor, int poluare,
                           std::string motor): Masina(marca, model, pret, an), CapacitateRezervor(rezervor), NivelPoluare(poluare), FirmaMotor(motor) {}

MasinaDiesel::~MasinaDiesel() =default;

int MasinaDiesel::GetRezervor() const {
    return CapacitateRezervor;
}

int MasinaDiesel::GetPoluare() const {
    return NivelPoluare;
}

string MasinaDiesel::GetMotor() const {
    return FirmaMotor;
}

MasinaDiesel & MasinaDiesel::operator=(const MasinaDiesel& diesel) {
    Masina::operator=(diesel);
    this->CapacitateRezervor = diesel.CapacitateRezervor;
    this->NivelPoluare = diesel.NivelPoluare;
    this->FirmaMotor = diesel.FirmaMotor;
    return *this;
}

bool MasinaDiesel::operator==(const MasinaDiesel &diesel) const{
    return Masina::operator==(diesel) and CapacitateRezervor == diesel.CapacitateRezervor and NivelPoluare == diesel.NivelPoluare;
}
