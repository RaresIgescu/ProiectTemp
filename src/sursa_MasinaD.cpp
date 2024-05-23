//
// Created by riges on 5/20/2024.
//
#include "MasinaDiesel.cpp"

template<> MasinaDiesel<string, double, int>::MasinaDiesel(string marca, string model, double pret, int an, int rezervor, int poluare,
                                       string motor): Masina<string, double, int>(marca, model, pret, an), CapacitateRezervor(rezervor), NivelPoluare(poluare), FirmaMotor(motor) {}