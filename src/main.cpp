#include <iostream>
#include "DealerAuto.h"
#include "MasinaElectrica.h"
#include "Singleton.h"
using namespace std;

int main() {
    Masina<string, double, int> masina;
    int continuare = 1;
    Dealer_Auto dealer;
    Singleton* meniu = Singleton::PreiaInstanta();
    meniu->setDealer(&dealer);
    meniu->AdaugareOptiune(1, "Vizualizarea flotei de masini", &Dealer_Auto::VizualizareFlota);
    meniu->AdaugareOptiune(2, "Verificarea stocului unei masini", &Dealer_Auto::VerificareStocMasina);
    meniu->AdaugareOptiune(3, "Vinde o masina", &Dealer_Auto::Vinde);
    meniu->AdaugareOptiune(4, "Cumpara o masina", &Dealer_Auto::Cumpara);
    meniu->AdaugareOptiune(5, "Vinde mai multe masini", &Dealer_Auto::VindeMulte);
    meniu->AdaugareOptiune(6, "Obtine pretul pe piata al unei masini",&Dealer_Auto::ObtinePret);
    meniu->AdaugareOptiune(7, "Numarul de masini din fiecare categorie", &Dealer_Auto::NumaraObiecte);
    meniu->AdaugareOptiune(8, "Verificare procent baterie", &Dealer_Auto::VerificareBaterieElectrice);
    meniu->AdaugareOptiune(9, "Tipul fiecarei masini din flota",&Dealer_Auto::RTTI);
    while (continuare)
    {
        int InputContinuare;
        meniu->Afisare();
        meniu->Alegere();
        if(Singleton::iesire == 1)
        {
            continuare = 0;
            break;
        }
        cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
    }
    cout << "A fost o placere sa va avem langa noi, la revedere!" << "\n";
}