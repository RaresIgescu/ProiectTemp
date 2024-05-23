//
// Created by riges on 5/20/2024.
//
#include <utility>

#include "MasinaDiesel.cpp"

template<> MasinaDiesel<string, double, int>::MasinaDiesel(const string& marca,const string& model, double pret, int an, int rezervor, int poluare,
                                       const string& motor): Masina<string, double, int>(std::move(marca), std::move(model), pret, an), CapacitateRezervor(rezervor), NivelPoluare(poluare), FirmaMotor(std::move(motor)) {}