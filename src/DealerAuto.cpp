//
// Created by riges on 4/14/2024.
//
#include <iostream>
#include <string>
#include "Banca.h"
#include "DealerAuto.h"
#include "Decorator.h"
#include <typeinfo>
#include <algorithm>
#include <map>
using namespace std;

int Dealer_Auto::ContorTotal = 0;

    Dealer_Auto::Dealer_Auto() {
        PretFinal = 0;
        Flota.insert(new Masina<string, double, int>("AUDI", "A3", 12384.14, 2014)), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("AUDI", "Q7", 32981.92, 2018)), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("AUDI", "A8", 7899.99,2005 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("BMW", "M4", 82394.57, 2019 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("BMW", "E46", 3200.50, 1999 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("BMW", "F92", 12873.82, 2012 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("DACIA", "LOGAN", 2000.99, 2005 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("DACIA", "JOGGER", 16832.67, 2024)), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("DACIA", "DUSTER", 22874.23, 2024)), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("NISSAN", "JUKE", 16823.23, 2016 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("NISSAN", "ALTIMA", 20175.75, 2014 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("NISSAN", "QASHQAI", 38024.76, 2024)), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("FERRARI", "812GTS", 282983.93, 2023 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("FERRARI", "SF90", 482983.92, 2024)), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("FERRARI", "F430", 180923.99, 2004 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("PORSCHE", "CAYENNE", 88928.72, 2013 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("PORSCHE", "911GT3", 32981.92, 2007 )), ContorTotal++;
        Flota.insert(new Masina<string, double, int>("PORSCHE", "PANAMERA", 32981.92,2024 )), ContorTotal++;
        Flota.insert(new MasinaElectrica<string, double, int>("TESLA", "MODELX", 32893, 2017, 320, 3, 80, "XIAOMI")), ContorTotal++;
        Flota.insert(new MasinaElectrica<string, double, int>("TESLA", "MODELY",
                                               55000, 2016, 0, 2, 63, "XIOAMI")), ContorTotal++;
        Flota.insert(new MasinaElectrica<string, double, int>("TESLA", "MODELS",
                                               90000, 2024, 400, 8, 100, "TESLA")), ContorTotal++;
        Flota.insert(new MasinaElectrica<string, double, int>("HYUNDAI", "BAYON",
                                               42000, 2018, 280, 4,
                                                88, "HYUNDAI")), ContorTotal++;
        Flota.insert(new MasinaDiesel<string, double, int>("VOLVO", "XC90",
                                               93999, 2024, 85,
                                               4, "BMW")), ContorTotal++;
        Flota.insert(new MasinaDiesel<string, double, int>("VOLVO", "X30",
                                            32000, 2012, 50,
                                            2, "VOLVO")), ContorTotal++;
        Flota.insert(new MasinaDiesel<string, double, int>("VOLVO", "S60",
                                            13000, 2008, 40,
                                            7, "VOLVO")), ContorTotal++;
        BanciPartenere.insert({9147, Banca("ING", 19.0, {84, 120, 156, 192})});
        BanciPartenere.insert({2184, Banca("BRD", 10, {60,120,180})});
        BanciPartenere.insert({220, Banca("BT", 8, {36, 60, 84, 120, 180})});
    }

    void Dealer_Auto::VerificareStocMasina(){
        string Marca, Model;
        cout << "Introduceti Marca:";
        cin >> Marca;
        cout << "Introduceti Modelul:";
        cin >> Model;
        bool ok1 = false, ok2 = false;
        for(auto & i : Flota)
            if (Marca == i->GetMarca())
                ok1 = true;
        for(auto & i : Flota)
            if (Model == i->GetModel() && i->GetMarca() == Marca)
                ok2 = true;
        if (!ok1 || !ok2)
            cout << "Masina cautata nu este disponibila in stocul nostru!" << endl;
        else
            cout << "Masina se afla in stoc." << endl;
    }

    void Dealer_Auto::VindeMulte() {
        int NrMasini;
        double s = 0;
        cout << "Cate masini vreti sa vindeti?" << "\n";
        cin >> NrMasini;
        cout << "Introduceti, in aceasta ordine, marca si modelul fiecarei masini" << "\n";
        for(int i = 0 ; i < NrMasini ; i ++)
        {
            bool ok = false;
            string marca, model;
            cin >> marca >> model;
            for(auto & j : Flota)
                if (model == j->GetModel() && j->GetMarca() ==  marca)
                {
                    cout << "Masina a fost gasita in gama noastra si veti primi suma de: " << j->GetPret() - (3*j->GetPret())/20 << "\n";
                    s = s + (j->GetPret() - (3*j->GetPret())/20);
                    ok = true;
                    break;
                }
            if (!ok) {
                cout << "Masina introdusa nu a fost gasita in gama noastra." << "\n";
                break;
            }
        }
        cout << "Pentru toate masinile introduse, veti primi o suma totala de: " << s << "\n";
        cout << "Sunteti de acord cu pretul oferit?" << "\n";
        cout << "1 - Da / 2 - Nu" << "\n";
        int numar;
        cin >> numar;
        if (numar == 1)
            cout << "Ne bucuram, banii vor fi virati in contul dumneavoastra in scurt timp." << "\n";
        else
            cout << "Ne pare rau, haideti sa ne uitam la celelalte oferte disponibile in dealerul nostru" << "\n";
    }

    void Dealer_Auto::Vinde()
    {
            string Marca, Model;
            int An, Input;
            double Pret;
            cout << "Introduceti Marca:";
            cin >> Marca;
            cout << "Introduceti Modelul:";
            cin >> Model;
            bool ok1 = false;
            for (const auto &masina: Flota)
            {
                if (masina->GetMarca() == Marca and masina->GetModel() == Model)
                {
                    ok1 = true;
                    cout << "Masina a fost gasita in stocul nostru!" << "\n";
                    cout << "Introduceti anul de fabricatie al masinii dumneavoastra";
                    cin >> An;
                    if(An == 2024)
                    {
                        cout << "Pentru ca masina este noua o sa primiti un pret mai bun pentru vehiculul dumneavostra" << "\n";
                        if(dynamic_cast<MasinaElectrica<string, double, int>*>(masina))
                        {
                            Pret = masina->GetPret();
                            cout << "Masina este electrica, acestea sunt la mare cautare, pretul final va fi de " << Pret - (Pret/20) << "\n";
                            cout << "Suntei de acord cu pretul oferit?" << "\n";
                            cout << "1 - DA || 2 - NU" << "\n";
                            cin >> Input;
                            if (Input == 1)
                                cout << "Ne bucuram, banii vor fi virati in contul dvs. in scurt timp." << "\n";
                            else
                                cout << "Ne pare rau, haideti sa vorbim despre celelalte oferte din dealerul nostru." << "\n";
                        }
                        else if(dynamic_cast<MasinaDiesel<string, double, int>*>(masina))
                        {
                            Pret = masina->GetPret();
                            cout << "Masina este pe diesel, ele polueaza mai tare, pretul final va fi de " << Pret - (Pret/10) << "\n";
                            cout << "Suntei de acord cu pretul oferit?" << "\n";
                            cout << "1 - DA || 2 - NU" << "\n";
                            cin >> Input;
                            if (Input == 1)
                                cout << "Ne bucuram, banii vor fi virati in contul dvs. in scurt timp." << "\n";
                            else
                                cout << "Ne pare rau, haideti sa vorbim despre celelalte oferte din dealerul nostru." << "\n";
                        }
                        else
                        {
                            Pret = masina->GetPret();
                            cout << "Masina este obisnuita pretul final va fi de " << Pret - (3*Pret/20) << "\n";
                            cout << "Suntei de acord cu pretul oferit?" << "\n";
                            cout << "1 - DA || 2 - NU" << "\n";
                            cin >> Input;
                            if (Input == 1)
                                cout << "Ne bucuram, banii vor fi virati in contul dvs. in scurt timp." << "\n";
                            else
                                cout << "Ne pare rau, haideti sa vorbim despre celelalte oferte din dealerul nostru." << "\n";
                        }
                    }
                }
            }
            if (!ok1)
                cout << "Masina nu a fost gasita in stockul nostru si nu va putem face o oferta." << "\n";
        }

    void Dealer_Auto::Cumpara() {
        int functionare = 1;
        int NrBanca;
        int InputMarca;
        int InputModel;
        int InputContinuare;
        double PretInitial = 0;
        double RataLunara;
        string MarcaAleasa;
        string ModelAles;
        string BancaAleasa;
        while (functionare)
        {
            int NrMarca = 1;
            int NrModel = 0;
            cout << "Alegeti mai intai marca automobilului dumneavoastra!" << "\n";
            for (auto iter = Flota.begin(); iter != Flota.end(); advance(iter, 3), ++NrMarca) {
                cout << NrMarca << ". ";
                cout << (*iter)->GetMarca() << "\n";
            }
            cout << "Va rugam alegeti numarul corespunzator marcii dorite:" << "\n";
            cin >> InputMarca;
            while(InputMarca < 1 || InputMarca > 9)
            {
                NrMarca = 0;
                cout << "Nu ati ales corect, reincercati!" << "\n";
                for (auto iter = Flota.begin(); iter != Flota.end(); advance(iter, 3)) {
                    cout << ++NrMarca << ". " << (*iter)->GetMarca() << "\n";
                }
                cin >> InputMarca;
            }
            int count = 0;
            for (auto iter : Flota) {
                if (count == 3 * (InputMarca - 1)) {
                    MarcaAleasa = iter->GetMarca();
                    break;
                }
                ++count;
            }
            cout << "Ati ales marca " << MarcaAleasa << ". Avem la dispozitie urmatoarele modele:" <<"\n";
            for(auto & i : Flota)
                if(i->GetMarca() == MarcaAleasa)
                    cout << ++NrModel << "." << i->GetModel() << "\n";
            cout << "Va rugam alegeti cifra corespunzatoare modelului:" << "\n";
            cin >> InputModel;
            while(InputModel<1 || InputModel > 3)
            {
                cout << "Nu ati ales corect, reincercati!" << "\n";
                for (auto iter = Flota.begin(); iter != Flota.end(); ++iter) {
                    if (iter != Flota.begin()) {
                        auto iterAnterior = prev(iter);
                        if ((*iter)->GetMarca() != (*iterAnterior)->GetMarca()) {
                            cout << ++NrMarca << ". " << (*iter)->GetMarca() << "\n";
                        }
                    }
                }
                cin >> InputModel;
            }
            count = 0;
            for (auto iter : Flota) {
                if (count == 3 * (InputMarca - 1) + (InputModel - 1)) {
                    ModelAles = iter->GetModel();
                    break;
                }
                ++count;
            }
            for(auto & i : Flota)
                if(i->GetMarca() == MarcaAleasa and i->GetModel() == ModelAles)
                    PretInitial = i->GetPret();
            cout << "Pretul masinii dorite este " << PretInitial <<". Daca va convine, puteti merge mai departe cu procesul de cumparare." <<"\n";
            cout << "Continuati?\n1 - Da\n2 - Nu" << "\n";
            cin >> InputContinuare;
            while(InputContinuare < 1 || InputContinuare > 2)
            {
                cout << "Alegere invalida" << "\n";
                cout << "1 - Da\n2 - Nu" << "\n";
                cin >> InputContinuare;
            }
            if (InputContinuare == 1)
            {
                cout << "Suntem incantati sa continuam!" << "\n";
                cout << "Cum doriti sa faceti plata?" << "\n";
                cout << "1 - Cash\n2 - Card" << "\n";
                cin >> InputContinuare;
                while(InputContinuare < 1 || InputContinuare > 2)
                {
                    cout << "Alegere invalida" << "\n";
                    cout << "1 - Da\n2 - Nu" << "\n";
                    cin >> InputContinuare;
                }
                if (InputContinuare == 1)
                {
                    cout << "Avand in vedere ca plata va fi facuta cash, nu vom aduce in discutie achizita cu ajutorul bancii." << "\n";
                    cout << "Doriti sa va echipati vehiculul cu un pachet promotional de dotari?" << "\n";
                    cout << "1 - Da\n2 - Nu" << "\n";
                    cin >> InputContinuare;
                    while(InputContinuare < 1 || InputContinuare > 2)
                    {
                        cout << "Alegere invalida" << "\n";
                        cout << "1 - Da\n2 - Nu" << "\n";
                        cin >> InputContinuare;
                    }
                    if (InputContinuare == 1)
                    {
                        Masina<string, double, int>* temp;
                        cout << "Super, atunci vehiculul dumneavoastra va avea urmatoarele caraacteristici: " << "\n";
                        for (const auto& elem : Flota)
                            if(elem->GetMarca() == MarcaAleasa && elem->GetModel() == ModelAles)
                                temp = elem;
                        Masina<string, double, int>* tempD = new Decorator(temp);
                        tempD->AfiseazaDetalii();
                        cout << "Faceti plata?" << "\n";
                        cout << "1. DA || 2. NU " <<"\n";
                        cin >> InputContinuare;
                        while(InputContinuare < 1 || InputContinuare > 2)
                        {
                            cout << "Alegere invalida" << "\n";
                            cout << "1 - Da\n2 - Nu" << "\n";
                            cin >> InputContinuare;
                        }
                        if(InputContinuare == 1)
                        {
                            cout << "Va multumim" << "\n";
                            cout << "Sunteti interesat de alta masina" << "\n";
                            cout << "1. DA || 2. NU " <<"\n";
                            cin >> InputContinuare;
                            if(InputContinuare == 1) functionare = 1;
                            else functionare  = 0;
                        }
                        else {
                            cout << "Ne pare rau" << "\n";
                            cout << "Sunteti interesat de alta masina" << "\n";
                            cout << "1. DA || 2. NU " <<"\n";
                            cin >> InputContinuare;
                            if(InputContinuare == 1) functionare = 1;
                            else functionare  = 0;
                        }
                    }
                    else
                    {
                        cout << "Nu este nicio problema, plata se va face cat mai curand" << "\n";
                        cout << "Va multumim" << "\n";
                        functionare = 0;
                    }
                }
                else
                {
                    cout << "La plata cu cardul putem sa vorbim despre achizita printr-o banca.\nPentru ca achizitia sa decurga mai usor, introduceti codul bancii la care aveti card" << "\n";
                    NrBanca = 0;
                    cin >> NrBanca;
                    auto i = BanciPartenere.find(NrBanca);
                    if (i != BanciPartenere.end()) {
                        std::cout << "Elementul asociat cheii " << NrBanca << " este: ";
                        i->second.afisare();
                        cout << "\n";
                    }
                    else
                    {
                        cout << "Cheia " << NrBanca << " nu a fost găsită în map.\n";
                    }
                    cout << "Avand in vedere ca folositi banca ";
                    if(i != BanciPartenere.end())
                        i->second.afisare();
                    if(i != BanciPartenere.end())
                        PretFinal = i->second.CalculPretFinal(PretInitial);
                    cout << " dupa adaugarea TVAului bancii, pretul final al masinii va fi " << PretFinal << "\n";
                    cout << "Doriti sa platiti in rate" <<"\n";
                    cout <<"1 - Da\n2 - Nu"<<"\n";
                    cin >> InputContinuare;
                    while(InputContinuare < 1 || InputContinuare > 2)
                    {
                        cout << "Alegere invalida" << "\n";
                        cout << "1 - Da\n2 - Nu" << "\n";
                        cin >> InputContinuare;
                    }
                    if (InputContinuare == 1)
                    {
                        cout << "La banca "; i->second.afisare(); cout << " puteti plati in urmatoarele rate: " << "\n";
                        RataLunara = i->second.GetRataLunara(PretFinal);
                        cout << "In final, rata lunara pentru masina aleasa in raport cu banca partenera este de " << RataLunara << "\n";
                        cout << "Doriti sa va echipati vehiculul cu un pachet premium de dotari?" << "\n";
                        cout << "1 - Da\n2 - Nu"<<"\n";
                        cin >> InputContinuare;
                        while(InputContinuare < 1 || InputContinuare > 2)
                        {
                            cout << "Alegere invalida" << "\n";
                            cout << "1 - Da\n2 - Nu" << "\n";
                            cin >> InputContinuare;
                        }
                        if (InputContinuare == 1)
                        {
                            Masina<string, double, int>* temp;
                            cout << "Super, atunci vehiculul dumneavoastra va avea urmatoarele caraacteristici: " << "\n";
                            for (const auto& elem : Flota)
                                if(elem->GetMarca() == MarcaAleasa && elem->GetModel() == ModelAles)
                                    temp = elem;
                            Masina<string, double, int>* tempD = new Decorator(temp);
                            tempD->AfiseazaDetalii();
                            cout << "Faceti plata?" << "\n";
                            cout << "1. DA || 2. NU " <<"\n";
                            cin >> InputContinuare;
                            while(InputContinuare < 1 || InputContinuare > 2)
                            {
                                cout << "Alegere invalida" << "\n";
                                cout << "1 - Da\n2 - Nu" << "\n";
                                cin >> InputContinuare;
                            }
                            if (InputContinuare == 1)
                            {
                                cout << "Va multumim" << "\n";
                                functionare = 0;
                            }
                            else
                            {
                                cout << "Nu este nicio problema, sunteti interesat de alta masina?" <<"\n";
                                cout <<"1 - Da\n2 - Nu" << "\n";
                                cin >> InputContinuare;
                                while(InputContinuare < 1 || InputContinuare > 2)
                                {
                                    cout << "Alegere invalida" << "\n";
                                    cout << "1 - Da\n2 - Nu" << "\n";
                                    cin >> InputContinuare;
                                }
                                if (InputContinuare == 1)
                                {
                                    functionare = 1;
                                }
                                else
                                    functionare = 0;
                            }
                        }
                        else
                        {
                            cout << "Atunci vehiculul nu va avea extra dotari" << "\n";
                            cout << "Plata se va face in cel mai scurt timp" << "\n";
                            cout << "Sunteti interesat de alta masina?" <<"\n";
                            cout <<"1 - Da\n2 - Nu" << "\n";
                            cin >> InputContinuare;
                            while(InputContinuare < 1 || InputContinuare > 2)
                            {
                                cout << "Alegere invalida" << "\n";
                                cout << "1 - Da\n2 - Nu" << "\n";
                                cin >> InputContinuare;
                            }
                            if (InputContinuare == 1)
                            {
                                functionare = 1;
                            }
                            else
                                functionare = 0;
                        }
                    }
                    else
                    {
                        cout << "Sigur, atunci plata se va face integral prin card bancar!" << "\n";
                        cout << "Sunteti interesat de alta masina?" << "\n";
                        cout <<"1 - Da\n2 - Nu" << "\n";
                        cin >> InputContinuare;
                        while(InputContinuare < 1 || InputContinuare > 2)
                        {
                            cout << "Alegere invalida" << "\n";
                            cout << "1 - Da\n2 - Nu" << "\n";
                            cin >> InputContinuare;
                        }
                        if (InputContinuare == 1)
                            functionare = 1;
                        else
                            functionare = 0;
                    }
                }
            }
            else {
                cout << "Nu este nicio problema, sunteti interesat de alta masina?" <<"\n";
                cout <<"1 - Da\n2 - Nu" << "\n";
                cin >> InputContinuare;
                while(InputContinuare < 1 || InputContinuare > 2)
                {
                    cout << "Alegere invalida" << "\n";
                    cout << "1 - Da\n2 - Nu" << "\n";
                    cin >> InputContinuare;
                }
                if (InputContinuare == 1)
                    functionare = 1;
                else
                    functionare = 0;
            }
        }
    }


    void Dealer_Auto::VizualizareFlota() {
        int Index;
        for (auto iter = Flota.begin(); iter != Flota.end(); advance(iter, 3)) {
            cout << "Gama masinilor de la " << (*iter)->GetMarca() << ":\n";
            int NrModel = 0;
            for (auto iterModel : Flota) {
                if (iterModel->GetMarca() == (*iter)->GetMarca())
                        cout << ++NrModel << ". " << iterModel->GetModel() << "\n";
                }
            cout << "\n";
            }
        cout << "Doriti sa sortati rezultatele?" << "\n";
        cout << "1. DA || 2. NU" << "\n";
        cin >> Index;
        if(Index == 1)
        {
            cout << "Se prezinta rezultatele ordonate crescator dupa Marci" << "\n";
            vector <Masina<string,double,int>*> Vec(Flota.begin(), Flota.end());
            sort(Vec.begin(), Vec.end(), [](const auto& m1, const auto& m2) {
                return m1->GetMarca() < m2->GetMarca();
            });
            for (const auto& elem : Vec) {
                cout << elem->GetMarca() << " " << elem->GetModel() << "\n";
            }
        }
        else
        {
            return;
        }
    }

    void Dealer_Auto::NumaraObiecte()  {
        int ContorMasini = 0;
        int ContorElectrice = 0;
        int ContorDiesel = 0;
        for(const auto& masina: Flota)
        {
            if(dynamic_cast<MasinaElectrica<string, double, int>*>(masina))
                ContorElectrice++;
            else if(dynamic_cast<MasinaDiesel<string, double, int>*>(masina))
                ContorDiesel++;
            else
                ContorMasini++;
        }
        cout << "Numarul total de masini este de: " << Dealer_Auto::ContorTotal << "\n";
        cout << "Care sunt impartite in urmatoarele: " << "\n";
        cout << ContorMasini << " masini normale" << "\n";
        cout << ContorDiesel << " masini pe diesel" << "\n";
        cout << ContorElectrice << " masini electrice" << "\n";
    }

    void Dealer_Auto::VerificareBaterieElectrice() {
        for (const auto &masina: Flota)
            if (dynamic_cast<MasinaElectrica<string, double, int>*>(masina))
                try {
                    if(masina->CreeazaMasinaElectrica() == 1)
                    {
                        cout << "Masina " << masina->GetMarca() << " " << masina->GetModel() << " este functionala." << "\n";
                    }
                }
                catch (const std::exception &e) {
                    std::cerr << "Eroare: " << "Masina " << masina->GetMarca() << " " << masina->GetModel() << e.what() << std::endl;
                }
    }

    void Dealer_Auto::ObtinePret() {
        string marca, model;
        cout << "Introduceti marca si modelul masinii: " << "\n";
        cin >> marca >> model;
        for (const auto &masina: Flota) {
            if (masina->GetMarca() == marca and masina->GetModel() == model) {
                Masina<string, double, int> *pointer = masina;
                cout << pointer->ObtinePretPePiata() << '\n';
            }
        }
    }

    void Dealer_Auto::RTTI() {
        cout << "Fiecare obiect din Flota este de urmatorul fel: " << "\n";
        for (auto &masina : Flota) {
            cout << "Tipul obiectului: ";
            if(typeid(*masina).name()[0] == '6')
                cout << "Masina" << "\n";
            else if(typeid(*masina).name()[0] == '1' && typeid(*masina).name()[1] == '5')
                cout << "Masina Electrica" << "\n";
            else if(typeid(*masina).name()[0] == '1' && typeid(*masina).name()[1] == '2')
                cout << "Masina Diesel" << "\n";
        }
    }

    Dealer_Auto::~Dealer_Auto() {
        for (auto &masina: Flota) {
            delete masina;
        }
    }

