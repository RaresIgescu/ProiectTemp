#include <iostream>
#include "DealerAuto.h"
#include "MasinaElectrica.h"
using namespace std;

int main() {
    int continuare = 1;
    Dealer_Auto dealer;
    while (continuare)
    {
        int InputContinuare;
        cout << "Bine ati revenit in dealerul nostru autorizat, de ce ati fi interesat?" << "\n";
        cout << "1. Vizualizare Flota Masini." << "\n";
        cout << "2. Verificare Stoc." << "\n";
        cout << "3. Vinde o masina." << "\n";
        cout << "4. Cumpara o masina." << "\n";
        cout << "5. Vinde mai multe masini. (Citire a n obiecte)" << "\n";
        cout << "6. Obtine pretul pe piata al unei masini. (Upcasting)" << "\n";
        cout << "7. Numarul total de masini din flota (Downcasting)" << "\n";
        cout << "8. Verificare autonomie masina electrica (Ilustrare Exceptie)" << "\n";
        cout << "9. Iesire." << "\n";
        cin >> InputContinuare;
        if(InputContinuare == 1) {
            dealer.VizualizareFlota();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if(InputContinuare == 2) {
            dealer.VerificareStocMasina();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if(InputContinuare == 3) {
            dealer.Vinde();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if (InputContinuare == 4) {
            dealer.Cumpara();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if(InputContinuare == 5) {
            dealer.VindeMulte();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if(InputContinuare == 6)
        {
              dealer.ObtinePret();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if(InputContinuare == 7) {
            dealer.NumaraObiecte();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if(InputContinuare == 8) {
            dealer.VerificareBaterieElectrice();
            cout << "Continuati procesul?" << "\n";
            cout << "1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            if(InputContinuare == 1)
                continuare = 1;
            else
                continuare = 0;
        }
        else if (InputContinuare == 9) {
            continuare = 0;
        }
    }
    cout << "A fost o placere sa va avem langa noi, la revedere!" << "\n";
}
