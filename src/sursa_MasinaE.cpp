//
// Created by riges on 5/20/2024.
//
#include "MasinaElectrica.cpp"
#include "Masina.cpp"

#include <utility>

template<> Masina<string, double, int>::Masina(string marca, string model, double pret, int an) : Marca(std::move(marca)), Model(std::move(model)), Pret(pret), An(an) {}
template<> MasinaElectrica<string, double, int>::MasinaElectrica(string marca, string model, double pret, int an, int autonomie, int timpinc, int procent, string baterie): Masina<string, double, int>(marca, model, pret, an), Autonomie(autonomie), TimpIncarcare(timpinc), ProcentBaterie(procent), NumeBaterie(baterie) {}