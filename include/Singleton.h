//
// Created by riges on 5/23/2024.
//

#ifndef PROIECT_SINGLETON_H
#define PROIECT_SINGLETON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "DealerAuto.h"
class Singleton {
private:
    static Singleton* instance;
    Dealer_Auto* dealer;
    std::map<int, std::pair<string, void(Dealer_Auto::*)()>> Optiuni;

    Singleton();
public:
    static int iesire;
    void AdaugareOptiune(int key, const string& nume, void (Dealer_Auto::*action)());
    static Singleton* PreiaInstanta();
    void setDealer(Dealer_Auto* dealer);
    void Afisare();
    void Alegere();
    ~Singleton();
};

#endif //PROIECT_SINGLETON_H
