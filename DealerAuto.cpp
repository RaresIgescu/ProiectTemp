//
// Created by riges on 4/14/2024.
//
#include <iostream>
#include <string>
#include "Banca.h"
#include "DealerAuto.h"
using namespace std;

int Dealer_Auto::ContorTotal = 0;

    Dealer_Auto::Dealer_Auto() {
        PretFinal = 0;
        Flota.emplace_back(new Masina("AUDI", "A3", 12384.14, 2014)), ContorTotal++;
        Flota.emplace_back(new Masina("AUDI", "Q7", 32981.92 )), ContorTotal++;
        Flota.emplace_back(new Masina("AUDI", "A8", 7899.99,2005 )), ContorTotal++;
        Flota.emplace_back(new Masina("BMW", "M4", 82394.57, 2019 )), ContorTotal++;
        Flota.emplace_back(new Masina("BMW", "E46", 3200.50, 1999 )), ContorTotal++;
        Flota.emplace_back(new Masina("BMW", "F92", 12873.82, 2012 )), ContorTotal++;
        Flota.emplace_back(new Masina("DACIA", "LOGAN", 2000.99, 2005 )), ContorTotal++;
        Flota.emplace_back(new Masina("DACIA", "JOGGER", 16832.67 )), ContorTotal++;
        Flota.emplace_back(new Masina("DACIA", "DUSTER", 22874.23 )), ContorTotal++;
        Flota.emplace_back(new Masina("NISSAN", "JUKE", 16823.23, 2016 )), ContorTotal++;
        Flota.emplace_back(new Masina("NISSAN", "ALTIMA", 20175.75, 2014 )), ContorTotal++;
        Flota.emplace_back(new Masina("NISSAN", "QASHQAI", 38024.76 )), ContorTotal++;
        Flota.emplace_back(new Masina("FERRARI", "812GTS", 282983.93, 2023 )), ContorTotal++;
        Flota.emplace_back(new Masina("FERRARI", "SF90", 482983.92 )), ContorTotal++;
        Flota.emplace_back(new Masina("FERRARI", "F430", 180923.99, 2004 )), ContorTotal++;
        Flota.emplace_back(new Masina("PORSCHE", "CAYENNE", 88928.72, 2013 )), ContorTotal++;
        Flota.emplace_back(new Masina("PORSCHE", "911GT3", 32981.92, 2007 )), ContorTotal++;
        Flota.emplace_back(new Masina("PORSCHE", "PANAMERA", 32981.92 )), ContorTotal++;
        Flota.emplace_back(new MasinaElectrica("TESLA", "MODELX", 32893, 2017, 320, 3, "XIAOMI", 80)), ContorTotal++;
        Flota.emplace_back(new MasinaElectrica("TESLA", "MODELY",
                                               55000, 2016, 0, 2,
                                               "XIOAMI", 63)), ContorTotal++;
        Flota.emplace_back(new MasinaElectrica("TESLA", "MODELS",
                                               90000, 2024, 400, 8,
                                               "TESLA", 100)), ContorTotal++;
        Flota.emplace_back(new MasinaElectrica("HYUNDAI", "BAYON",
                                               42000, 2018, 280, 4,
                                               "HYUNDAI", 88)), ContorTotal++;
        Flota.emplace_back(new MasinaDiesel("VOLVO", "XC90",
                                               93999, 2024, 85,
                                               4, "BMW")), ContorTotal++;
        Flota.emplace_back(new MasinaDiesel("VOLVO", "X30",
                                            32000, 2012, 50,
                                            2, "VOLVO")), ContorTotal++;
        Flota.emplace_back(new MasinaDiesel("VOLVO", "S60",
                                            13000, 2008, 40,
                                            7, "VOLVO")), ContorTotal++;
        BanciPartenere.push_back(Banca("ING", 19, {84, 120, 156, 192}));
        BanciPartenere.push_back(Banca("BRD", 10, {60, 120, 180}));
        BanciPartenere.push_back(Banca("BT", 8, {36, 60, 84, 120, 180}));
    }

    void Dealer_Auto::VerificareStocMasina() const{
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

    void Dealer_Auto::VindeMulte() const{
        int NrMasini;
        float s = 0;
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

    void Dealer_Auto::Vinde() const
    {
            string Marca, Model;
            int An, Input;
            float Pret;
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
                        if(dynamic_cast<MasinaElectrica*>(masina))
                        {
                            Pret = masina->GetPret();
                            cout << "Masina este electrica, acestea sunt la mare cautare, pretul final va fi de " << Pret - (Pret/20) << "\n";
                            cout << "Suntei de acord cu pretul oferit?" << "\n";
                            cout << "1 - DA \ 2 - NU" << "\n";
                            cin >> Input;
                            if (Input == 1)
                                cout << "Ne bucuram, banii vor fi virati in contul dvs. in scurt timp." << "\n";
                            else
                                cout << "Ne pare rau, haideti sa vorbim despre celelalte oferte din dealerul nostru." << "\n";
                        }
                        else if(dynamic_cast<MasinaDiesel*>(masina))
                        {
                            Pret = masina->GetPret();
                            cout << "Masina este pe diesel, ele polueaza mai tare, pretul final va fi de " << Pret - (Pret/10) << "\n";
                            cout << "Suntei de acord cu pretul oferit?" << "\n";
                            cout << "1 - DA \ 2 - NU" << "\n";
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
                            cout << "1 - DA \ 2 - NU" << "\n";
                            cin >> Input;
                            if (Input == 1)
                                cout << "Ne bucuram, banii vor fi virati in contul dvs. in scurt timp." << "\n";
                            else
                                cout << "Ne pare rau, haideti sa vorbim despre celelalte oferte din dealerul nostru." << "\n";
                        }
                    }
                }
            }
            if (ok1 == false)
                cout << "Masina nu a fost gasita in stockul nostru si nu va putem face o oferta." << "\n";
        }

    void Dealer_Auto::Cumpara() {
        int functionare = 1;
        int NrBanca;
        int InputMarca;
        int InputModel;
        int InputContinuare;
        int IndexBanca;
        float PretInitial = 0;
        float RataLunara;
        string MarcaAleasa;
        string ModelAles;
        string BancaAleasa;
        while (functionare)
        {
            int NrMarca = 0;
            int NrModel = 0;
            cout << "Alegeti mai intai marca automobilului dumneavoastra!" << "\n";
            cout << ++NrMarca << "." << Flota[0]->GetMarca() << "\n";
            for (long unsigned int i = 1 ; i < Flota.size(); i++)
                if(Flota[i]->GetMarca() != Flota[i-1]->GetMarca())
                    cout << ++NrMarca << "." << Flota[i]->GetMarca() << "\n";
            cout << "Va rugam alegeti numarul corespunzator marcii dorite:" << "\n";
            cin >> InputMarca;
            while(InputMarca < 1 || InputMarca > 9)
            {
                NrMarca = 0;
                cout << "Nu ati ales corect, reincercati!" << "\n";
                cout << ++NrMarca << "." << Flota[0]->GetMarca() << "\n";
                for (long unsigned int i = 1 ; i < Flota.size(); i++)
                    if(Flota[i]->GetMarca() != Flota[i-1]->GetMarca())
                        cout << ++NrMarca << "." << Flota[i]->GetMarca() << "\n";
                cin >> InputMarca;
            }
            MarcaAleasa = Flota[3 * (InputMarca - 1)]->GetMarca();

            cout << "Ati ales marca " << MarcaAleasa << ". Avem la dispozitie urmatoarele modele:" <<"\n";
            for(auto & i : Flota)
                if(i->GetMarca() == MarcaAleasa)
                    cout << ++NrModel << "." << i->GetModel() << "\n";
            cout << "Va rugam alegeti cifra corespunzatoare modelului:" << "\n";
            cin >> InputModel;
            while(InputModel<1 || InputModel > 3)
            {
                cout << "Nu ati ales corect, reincercati!" << "\n";
                cout << ++NrMarca << "." << Flota[0]->GetMarca() << "\n";
                for (long unsigned int i = 1 ; i < Flota.size(); i++)
                    if(Flota[i]->GetMarca() != Flota[i]->GetMarca())
                        cout << ++NrMarca << "." << Flota[i-1]->GetMarca() << "\n";
                cin >> InputModel;
            }
            ModelAles = Flota[3 * (InputMarca - 1) + (InputModel - 1)]->GetModel();
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
                    cout << "Avand in vedere ca plata va fi facuta cash, nu vom aduce in discutie achizita cu ajutorul bancii.\nVa multumim ca ati facut afaceri cu noi.\nVoi aduce managerul dealer-ului pentru a numara bancnotele.\nIntre timp ati fi interesat de o alta masina? " << "\n";
                    cout << "1 - Da\n2 - Nu" << "\n";
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
                else
                {
                    cout << "La plata cu cardul putem sa vorbim despre achizita printr-o banca.\nPentru ca achizitia sa decurga mai usor, alegeti una dintre bancile partenere:" << "\n";
                    NrBanca = 0;
                    for(auto & i : BanciPartenere)
                        cout << ++NrBanca << ". " << i.GetNume()<< "\n";
                    cin >> InputContinuare;
                    BancaAleasa = BanciPartenere[InputContinuare-1].GetNume();
                    PretFinal = BanciPartenere[InputContinuare-1].CalculPretFinal(PretInitial);
                    IndexBanca = InputContinuare - 1;
                    cout << "Avand in vedere ca folositi banca " << BancaAleasa << "dupa adaugarea TVAului bancii, pretul final al masinii va fi " << PretFinal << "\n";
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
                        cout << "La banca " << BancaAleasa << " puteti plati in urmatoarele rate: " << "\n";
                        RataLunara = BanciPartenere[IndexBanca].GetRataLunara(PretFinal);
                        cout << "In final, rata lunara pentru masina aleasa in raport cu banca partenera este de " << RataLunara << "\n";
                        cout << "Finalizati plata?" << "\n";
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
                            cout << "A fost o placere sa facem afaceri cu voi, sunteti interesat de o alta masina?" << "\n";
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
                                functionare = 1;
                            }
                            else
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
                                functionare = 1;
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

    void Dealer_Auto::VizualizareFlota() const{
        for(long unsigned int i = 0; i < Flota.size(); i+=3)
        {
            int NrModel = 0;
            cout <<"Gama masinilor de la " << Flota[i]->GetMarca() << ":\n";
            for(auto & j : Flota)
                if(j->GetMarca() == Flota[i]->GetMarca())
                    cout << ++NrModel << ". " << j->GetModel() << "\n";
            cout << "\n";
        }
    }

    int Dealer_Auto::ContinuareFunctieVinde() {
        int input;
        int functionare;
        cout << "Doriti sa continuati?" << endl;
        cout << "1 - Da\n2 - Nu" << "\n";
        cin >> input;
        if (input == 1)
        {
            cout << "Banii vor fi virati in contul dumneavoastra in cel mai scurt timp, multumim ca ne-ati ales!" << endl;
        }
        else
            cout << "Nu este nicio problema, oferta ramane valabila incontinuare!" << endl;
        cout << "Daca doriti sa vindeti alta masina apasati 1, daca vreti sa va intoarceti la meniul principal apasati 0" << endl;
        cin >> functionare;
        return functionare;
    }

    int Dealer_Auto::NuGasitFunctieVinde() {
        int functionare;
        cout << "Nu va putem face o oferta deoarece masina nu se afla in stockul nostru in acest moment!" << "\n";
        cout << "Daca doriti sa vindeti alta masina apasati 1, daca vreti sa va intoarceti la meniul principal apasati 0" << "\n";
        cin >> functionare;
        return functionare;
    }

    float Dealer_Auto::ObtinePretMasina(const string& Marca, const string& Model) const{
        for(auto & i : Flota)
            if(Marca == i->GetMarca() and Model == i->GetModel())
                return i->GetPret();
        return 0;
    }
    int Dealer_Auto::ObtineAnFab(const string& Marca, const string& Model) const{
        for(auto & i : Flota)
            if(Marca == i->GetMarca() and Model == i->GetModel())
                return i->GetAn();
        return 0;
    }

    void Dealer_Auto::NumaraObiecte() const {
        int ContorMasini = 0;
        int ContorElectrice = 0;
        int ContorDiesel = 0;
        for(const auto& masina: Flota)
        {
            if(dynamic_cast<MasinaElectrica*>(masina))
                ContorElectrice++;
            else if(dynamic_cast<MasinaDiesel*>(masina))
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

    void Dealer_Auto::VerificareBaterieElectrice() const {
        for (const auto &masina: Flota)
            if (dynamic_cast<MasinaElectrica *>(masina))
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
