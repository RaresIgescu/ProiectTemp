//
// Created by riges on 4/14/2024.
//

#ifndef PROIECT_DEALERAUTO_H
#define PROIECT_DEALERAUTO_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "Masina.h"
#include "Banca.h"
#include "MasinaDiesel.h"
#include "MasinaElectrica.h"
using namespace std;

class Dealer_Auto {
private:
    double PretFinal;
    set <Masina<string, double, int>*> Flota;
    map<int, Banca> BanciPartenere;
    static int ContorTotal;
public:
    Dealer_Auto();
    ~Dealer_Auto();
    void VerificareStocMasina();
    void VindeMulte();
    void Vinde();
    void Cumpara();
    void VizualizareFlota();
    void NumaraObiecte();
    void VerificareBaterieElectrice() ;
    void ObtinePret() ;
    void RTTI() ;
};

#endif //PROIECT_DEALERAUTO_H
