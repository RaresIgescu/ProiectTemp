//
// Created by riges on 4/13/2024.
//

#ifndef PROIECT_MASINA_H
#define PROIECT_MASINA_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <class T1, class T2, class T3>
class Masina {
protected:
    T1 Marca;
    T1 Model;
    T2 Pret;
    T3 An;

public:
    explicit Masina(const T1& marca = "",const T1& model = "", T2 pret = 0, T3 an = 0);

    Masina(const T1& marca,const T1& model, T2 pret);

    Masina<T1, T2, T3>& operator=(const Masina<T1, T2, T3>& car1);

    Masina(const Masina<T1, T2, T3>& car);

    virtual ~Masina ();

    int operator==(const Masina<T1, T2, T3>& car) const;

    [[nodiscard]] T1 GetMarca() const;

    [[nodiscard]] T1 GetModel() const;

    [[nodiscard]] T2 GetPret() const;

    [[nodiscard]] virtual T2 ObtinePretPePiata() const;

    [[nodiscard]] virtual T3 CreeazaMasinaElectrica() const { return 0; }

    virtual void AfiseazaDetalii() const;

    friend istream& operator>>(istream& in, Masina<T1, T2, T3>& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const Masina<T1, T2, T3>& car); //operator de afisare supraincarcat
};
#endif //PROIECT_MASINA_H
