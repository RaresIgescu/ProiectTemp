//
// Created by riges on 5/23/2024.
//

#ifndef PROIECT_DECORATOR_H
#define PROIECT_DECORATOR_H
#include <iostream>
#include <string>
#include "Masina.h"

class Decorator: public Masina<string, double, int> {
private:
    Masina<string, double, int>* masina;
public:
    explicit Decorator(Masina<string, double, int>* masina);

    void AfiseazaDetalii() const override;

    ~Decorator() override {
        delete masina;
    }
};

#endif //PROIECT_DECORATOR_H
