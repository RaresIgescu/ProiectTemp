#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Masina {
private:
    string Marca;
    string Model;
    float Pret;
    int An;

public:
    explicit Masina(string marca = "", string model = "", float pret = 0, int an = 0): Marca(std::move(marca)), Model(std::move(model)), Pret(pret), An(an) {}

    Masina(string& marca, string& model, float pret): Marca(marca), Model(model), Pret(pret), An(2024) {}

    Masina& operator=(const Masina& car1)= default;

    Masina(const Masina& car): Marca(car.Marca), Model(car.Model), Pret(car.Pret), An(car.An){}

    ~Masina ()=default;

    int operator==(const Masina& car){
        return car.Marca == Marca and car.Model == Model and car.An == An;
    }

    string GetMarca(){
        return Marca;
    }

    string GetModel() {
        return Model;
    }

    float GetPret() const {
        return Pret;
    }

    int GetAn() const {
        return An;
    }

    friend istream& operator>>(istream& in, Masina& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const Masina& car); //operator de afisare supraincarcat
};

istream& operator>>(istream& in, Masina& car) {
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

ostream& operator<<(ostream& out, const Masina& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    return out;
}

class Banca {
private:
    string Nume;
    float TVA;
    vector <int> NumarRate;

public:
    Banca(const string& nume, float tva,const vector <int>& rate): Nume(nume), TVA(tva), NumarRate(rate) {}

    string GetNume() {
        return Nume;
    }

    float CalculPretFinal(float pret) const {
        return pret + (pret * (TVA/100));
    }

    float GetRataLunara(float pret) {
        int NrRata = 0;
        int Indice;
        for(int i : NumarRate)
            cout << ++NrRata << ". " << i << "\n";
        cout << "Alegeti indecele numarului de rate." << "\n";
        cin >> Indice;
        return float(pret/NumarRate[Indice-1]);
    }

};

class Dealer_Auto {
private:
    float PretFinal;
    vector <Masina> Flota;
    vector <Banca> BanciPartenere;
public:
    Dealer_Auto() {
        PretFinal = 0;
        Flota.emplace_back("AUDI", "A3", 12384.14, 2014);
        Flota.emplace_back("AUDI", "Q7", 32981.92 );
        Flota.emplace_back("AUDI", "A8", 7899.99,2005 );
        Flota.emplace_back("BMW", "M4", 82394.57, 2019 );
        Flota.emplace_back("BMW", "E46", 3200.50, 1999 );
        Flota.emplace_back("BMW", "F92", 12873.82, 2012 );
        Flota.emplace_back("DACIA", "LOGAN", 2000.99, 2005 );
        Flota.emplace_back("DACIA", "JOGGER", 16832.67 );
        Flota.emplace_back("DACIA", "DUSTER", 22874.23 );
        Flota.emplace_back("NISSAN", "JUKE", 16823.23, 2016 );
        Flota.emplace_back("NISSAN", "ALTIMA", 20175.75, 2014 );
        Flota.emplace_back("NISSAN", "QASHQAI", 38024.76 );
        Flota.emplace_back("FERRARI", "812GTS", 282983.93, 2023 );
        Flota.emplace_back("FERRARI", "SF90", 482983.92 );
        Flota.emplace_back("FERRARI", "F430", 180923.99, 2004 );
        Flota.emplace_back("PORSCHE", "CAYENNE", 88928.72, 2013 );
        Flota.emplace_back("PORSCHE", "911GT3", 32981.92, 2007 );
        Flota.emplace_back("PORSCHE", "PANAMERA", 32981.92 );
        BanciPartenere.push_back(Banca("ING", 19, {84, 120, 156, 192}));
        BanciPartenere.push_back(Banca("BRD", 10, {60, 120, 180}));
        BanciPartenere.push_back(Banca("BT", 8, {36, 60, 84, 120, 180}));
    }

    void VerificareStocMasina() {
        string Marca, Model;
        cout << "Introduceti Marca:";
        cin >> Marca;
        cout << "Introduceti Modelul:";
        cin >> Model;
        bool ok1 = false, ok2 = false;
        for(auto & i : Flota)
            if (Marca == i.GetMarca())
                ok1 = true;
        for(auto & i : Flota)
            if (Model == i.GetModel())
                ok2 = true;
        if (!ok1 || !ok2)
            cout << "Masina cautata nu este disponibila in stocul nostru!" << endl;
        else
            cout << "Masina se afla in stoc." << endl;
    }

    void Vinde() {
        int functionare = 1;
        while (functionare)
        {
            string Marca, Model;
            cout << "Introduceti Marca:";
            cin >> Marca;
            cout << "Introduceti Modelul:";
            cin >> Model;
            if (Marca == "DACIA" || Marca == "NISSAN")
            {
                if (Model == "LOGAN" || Model == "JOGGER" || Model == "ALTIMA" || Model == "QASHQAI")
                {
                    float PretMasina = ObtinePretMasina(Marca, Model);
                    if (PretMasina == 0)
                    {
                        functionare = NuGasitFunctieVinde();
                        cout << functionare;
                    }
                    else
                    {
                        int AnFab = ObtineAnFab(Marca, Model);
                        if (AnFab == 2024)
                            cout << "Masina nu este de cea mai inalta calitate dar pentru ca este noua veti suferi o penalizare mai mica, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.3) << "\n";
                        else
                            cout << "Masina nu este de cea mai inalta calitate si nu este nici noua, pretul oferit de noi este: " << PretMasina - (PretMasina * 0.35) << "\n";
                        functionare = ContinuareFunctieVinde();
                    }
                }
                else if (Model == "DUSTER" || Model == "JUKE")
                {
                    float PretMasina = ObtinePretMasina(Marca, Model);
                    if (PretMasina == 0)
                        functionare = NuGasitFunctieVinde();
                    else
                    {
                        int AnFab = ObtineAnFab(Marca, Model);
                        if (AnFab == 2024)
                            cout << "Masina este noua si este cautata pe piata, asa ca veti avea o penalizare redusa, pretul nostru este: " << PretMasina - (PretMasina * 0.25) << "\n";
                        else
                            cout << "Masina nu este noua, dar este cautata pe piata, asa ca veti beneficia de un pret special: " << PretMasina - (PretMasina * 0.3) << "\n";
                        functionare = ContinuareFunctieVinde();
                    }
                }
                else
                    functionare = NuGasitFunctieVinde();
            }
            else if (Marca == "AUDI" || Marca == "BMW")
            {
                if (Model == "A3" || Model == "A8" || Model == "E46" || Model == "F92")
                {
                    float PretMasina = ObtinePretMasina(Marca, Model);
                    if(PretMasina == 0)
                        functionare = NuGasitFunctieVinde();
                    else
                    {
                        int AnFab = ObtineAnFab(Marca, Model);
                        if (AnFab == 2024)
                            cout << "Masina este de o calitate medie si pentru ca este noua veti suferi o penalizare mai mica, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.25) << "\n";
                        else
                            cout << "Masina este de o calitate medie, dar nu este noua, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.30) << "\n";
                        functionare = ContinuareFunctieVinde();
                    }
                }
                else if (Model == "M4" || Model == "Q7")
                {
                    float PretMasina = ObtinePretMasina(Marca, Model);
                    if (PretMasina == 0)
                        functionare = NuGasitFunctieVinde();
                    else
                    {
                        int AnFab = ObtineAnFab(Marca, Model);
                        if (AnFab == 2024)
                            cout << "Masina este noua si este cautata pe piata, asa ca veti avea o penalizare redusa, pretul nostru este: " << PretMasina - (PretMasina * 0.2) << "\n";
                        else
                            cout << "Masina nu este noua, dar este cautata pe piata, asa ca veti beneficia de un pret special: " << PretMasina - (PretMasina * 0.25) << "\n";
                        functionare = ContinuareFunctieVinde();
                    }
                }
                else
                    functionare = NuGasitFunctieVinde();
            }
            else if (Marca == "PORSCHE" || Marca == "FERRARI")
            {
                if (Model == "F430" || Model == "SF90" || Model == "CAYENNE" || Model == "911GT3")
                {
                    float PretMasina = ObtinePretMasina(Marca, Model);
                    if (PretMasina == 0)
                        functionare = NuGasitFunctieVinde();
                    else
                    {
                        int AnFab = ObtineAnFab(Marca, Model);
                        if (AnFab == 2024)
                            cout << "Masina este de o calitate premium si pentru ca este noua veti suferi o penalizare mai mica, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.2) << endl;
                        else
                            cout << "Masina este de o calitate premium, dar nu este noua, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.25) << endl;
                        functionare = ContinuareFunctieVinde();
                    }
                }
                else if (Model == "812GTS" || Model == "PANAMERA")
                {
                    float PretMasina = ObtinePretMasina(Marca, Model);
                    if (PretMasina == 0)
                        functionare = NuGasitFunctieVinde();
                    else
                    {
                        int AnFab = ObtineAnFab(Marca, Model);
                        if (AnFab == 2024)
                            cout << "Masina este noua si este cautata pe piata, asa ca veti avea o penalizare redusa, pretul nostru este: " << PretMasina - (PretMasina * 0.15) << "\n";
                        else
                            cout << "Masina nu este noua, dar este cautata pe piata, asa ca veti beneficia de un pret special: " << PretMasina - (PretMasina * 0.2) << "\n";
                        functionare = ContinuareFunctieVinde();
                    }
                }
                else
                    functionare = NuGasitFunctieVinde();
            }
            else
                functionare = NuGasitFunctieVinde();
        }
    }

    void Cumpara() {
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
            for (long unsigned int i = 0 ; i < Flota.size(); i++)
                if(Flota[i].GetMarca() != Flota[i-1].GetMarca())
                    cout << ++NrMarca << "." << Flota[i].GetMarca() << "\n";
            cout << "Va rugam alegeti numarul corespunzator marcii dorite:" << "\n";
            cin >> InputMarca;
            while(InputMarca < 1 || InputMarca > 6)
            {
                NrMarca = 0;
                cout << "Nu ati ales corect, reincercati!" << "\n";
                for (long unsigned int i = 0 ; i < Flota.size(); i++)
                    if(Flota[i].GetMarca() != Flota[i-1].GetMarca())
                        cout << ++NrMarca << "." << Flota[i].GetMarca() << "\n";
                cin >> InputMarca;
            }
            MarcaAleasa = Flota[3 * (InputMarca - 1)].GetMarca();

            cout << "Ati ales marca " << MarcaAleasa << ". Avem la dispozitie urmatoarele modele:" <<"\n";
            for(auto & i : Flota)
                if(i.GetMarca() == MarcaAleasa)
                    cout << ++NrModel << "." << i.GetModel() << "\n";
            cout << "Va rugam alegeti cifra corespunzatoare modelului:" << "\n";
            cin >> InputModel;
            while(InputModel<1 || InputModel > 3)
            {
                cout << "Nu ati ales corect, reincercati!" << "\n";
                for (long unsigned int i = 0 ; i < Flota.size(); i++)
                    if(Flota[i].GetMarca() != Flota[i-1].GetMarca())
                        cout << ++NrMarca << "." << Flota[i].GetMarca() << "\n";
                cin >> InputModel;
            }
            ModelAles = Flota[3 * (InputMarca - 1) + (InputModel - 1)].GetModel();
            for(auto & i : Flota)
                if(i.GetMarca() == MarcaAleasa and i.GetModel() == ModelAles)
                    PretInitial = i.GetPret();
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

    void VizualizareFlota() {
        for(long unsigned int i = 0; i < Flota.size(); i+=3)
        {
            int NrModel = 0;
            cout <<"Gama masinilor de la " << Flota[i].GetMarca() << ":\n";
            for(auto & j : Flota)
                if(j.GetMarca() == Flota[i].GetMarca())
                    cout << ++NrModel << ". " << j.GetModel() << "\n";
            cout << "\n";
        }
    }

    
    static int ContinuareFunctieVinde() {
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

    static int NuGasitFunctieVinde() {
        int functionare;
        cout << "Nu va putem face o oferta deoarece masina nu se afla in stockul nostru in acest moment!" << "\n";
        cout << "Daca doriti sa vindeti alta masina apasati 1, daca vreti sa va intoarceti la meniul principal apasati 0" << "\n";
        cin >> functionare;
        return functionare;
    }

    float ObtinePretMasina(const string& Marca, const string& Model) {
        for(auto & i : Flota)
            if(Marca == i.GetMarca() and Model == i.GetModel())
                return i.GetPret();
        return 0;
    }
    int ObtineAnFab(const string& Marca, const string& Model)
    {
        for(auto & i : Flota)
            if(Marca == i.GetMarca() and Model == i.GetModel())
                return i.GetAn();
        return 0;
    }
};


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
        else if (InputContinuare == 9) {
            continuare = 0;
        }
    }
    cout << "A fost o placere sa va avem langa noi, la revedere!";
}
