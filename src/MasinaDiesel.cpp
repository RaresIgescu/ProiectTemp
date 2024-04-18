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
