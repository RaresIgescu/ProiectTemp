//
// Created by riges on 4/14/2024.
//

#ifndef PROIECT_DEALERAUTO_H
#define PROIECT_DEALERAUTO_H
#include <iostream>
#include <vector>
#include <string>
#include "Masina.h"
#include "Banca.h"
#include "MasinaDiesel.h"
#include "MasinaElectrica.h"
using namespace std;

class Dealer_Auto {
private:
    float PretFinal;
    vector <Masina*> Flota;
    vector <Banca> BanciPartenere;
    static int ContorTotal;
public:
    Dealer_Auto();
    void VerificareStocMasina() const;
    void VindeMulte() const;
    void Vinde() const;
    void Cumpara();
    void VizualizareFlota() const;
    void NumaraObiecte() const;
    void VerificareBaterieElectrice() const;
    void ObtinePret() const;
};

#endif //PROIECT_DEALERAUTO_H
