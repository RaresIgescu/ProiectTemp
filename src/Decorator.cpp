//
// Created by riges on 5/23/2024.
//
#include <iostream>
#include "Decorator.h"

Decorator::Decorator(Masina<string, double, int>* masina): masina(masina) {}

void Decorator::AfiseazaDetalii() const {
    masina->AfiseazaDetalii();
    cout << "Pachet de navigatie" << "\n";
    cout << "Boxe premium JBL" << "\n";
    cout << "Scaune de piele" << "\n";
}