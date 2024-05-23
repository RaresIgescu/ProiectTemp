//
// Created by riges on 5/20/2024.
//
#include "Masina.cpp"

template<> string Masina<string, double, int>::GetMarca() const {
    return Marca;
}

template <> string Masina<string, double, int>::GetModel() const {
    return Model;
}

template <> double Masina<string, double, int>::GetPret() const {
    return Pret;
}