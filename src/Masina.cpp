//
// Created by riges on 4/13/2024.
//
#include <iostream>
#include "Masina.h"
using namespace std;

template <class T1, class T2, class T3>
Masina<T1, T2, T3>::Masina(T1 marca, T1 model, T2 pret, T3 an): Marca(marca), Model(model), Pret(pret), An(an) {}

template <class T1, class T2, class T3>
Masina<T1, T2, T3>::Masina(T1& marca, T1& model, T2 pret): Marca(marca), Model(model), Pret(pret), An(2024) {}

template <class T1, class T2, class T3>
Masina<T1, T2, T3>& Masina<T1, T2, T3>::operator=(const Masina& car1) = default;

template <class T1, class T2, class T3>
Masina<T1, T2, T3>::Masina(const Masina& car) =default;

template <class T1, class T2, class T3>
Masina<T1, T2, T3>::~Masina () =default;

template <class T1, class T2, class T3>
int Masina<T1, T2, T3>::operator==(const Masina& car) const{
    return car.Marca == Marca and car.Model == Model and car.An == An;
}

template <class T1, class T2, class T3>
T1 Masina<T1, T2, T3>::GetMarca() const {
    return Marca;
}

template <class T1, class T2, class T3>
T1 Masina<T1, T2, T3>::GetModel() const {
    return Model;
}

template <class T1, class T2, class T3>
T2 Masina<T1, T2, T3>::GetPret() const {
    return Pret;
}

template <class T1, class T2, class T3>
void Masina<T1, T2, T3>::AfiseazaDetalii() const {
    cout << "Prezentarea masinii: " << "\n";
    cout << "Marca: " << this->Marca << "\n";
    cout << "Model: " << this->Model << "\n";
    cout << "An: " << this->An << "\n";
    cout << "Pret: " << this->Pret << "\n";
    cout << "Dotari: " << "\n" ;
}

template <class T1, class T2, class T3>
istream& operator>>(istream& in, Masina<T1, T2, T3>& car) {
    cout << "Marca masinii: " << endl;
    in >> car.Marca;

    cout << "Modelul masinii: " << endl;
    in >> car.Model;

    cout << "Pretul masinii: " << endl;
    in >> car.Pret;

    cout << "Anul de fabricatie: " << endl;
    in >> car.An;

    return in;
}

template <class T1, class T2, class T3>
ostream& operator<<(ostream& out, const Masina<T1, T2, T3>& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    return out;
}

template <class T1, class T2, class T3>
T2 Masina<T1, T2, T3>::ObtinePretPePiata() const {
    double PretFinal = Pret;
    if (An != 2024)
    {
        cout << "Masina nu este noua deci se va aplica o penalizare mai mare asupra pretului" << "\n";
        cout << "Pretul final este de: ";
        return PretFinal - (PretFinal / 10);
    }
    else
    {
        cout << "Pentru ca masina este noua asupra pretului se va adauga doar adaosul comercial" << "\n";
        cout << "Pretul final este de: ";
        return PretFinal - (3 * PretFinal / 100);
    }
}
