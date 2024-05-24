//
// Created by riges on 5/23/2024.
//
#include <iostream>
#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

int Singleton::iesire = 0;

Singleton::Singleton(): dealer(nullptr) {}

void Singleton::setDealer(Dealer_Auto *Dealer) {
    this->dealer = Dealer;
}

Singleton* Singleton::PreiaInstanta() {
    if(!instance)
        instance = new Singleton();
    return instance;
}

void Singleton::AdaugareOptiune(int key, const string& nume, void (Dealer_Auto::*action)()) {
    Optiuni[key] = std::make_pair(nume, action);
}

void Singleton::Afisare() {
    std::cout << "Bine ati revenit in dealerul nostru autorizat, cu ce va putem ajuta?" << "\n";
    for (const auto& option : Optiuni) {
        std::cout << option.first << ". " << option.second.first << "\n";
    }
    cout << "10. Iesire" << "\n";
}

void Singleton::Alegere() {
    int aleg;
    std::cout << "Alege o optiune: ";
    std::cin >> aleg;

    if(aleg == 10)
    {
        Singleton::iesire = 1;
        return;
    }

    auto it = Optiuni.find(aleg);
    (dealer->*it->second.second)();
}

Singleton::~Singleton() = default;