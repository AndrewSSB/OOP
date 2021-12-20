#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>

using namespace std;

class AdapostAnimale{
private:
    float * ConsumIntroZi;
    string * NumeProdus;
    int NrObiecteCumparate;
    string * DotariCusca; // PAT , BOL, JUCARIE
    int * NumarDotare; // nr dotare, adica cate paturi are o cusca, cate boluri are o cusca etc;
    int nrTotalDeDotariCusca; // cate dotari are in total cusca

public:

    void setConsumIntroZi(float *ConsumIntroZi, int NrObiecteCumparate);
    float * getConsumIntroZi();

    void setNumeProdus(string *NumeProdus, int NrObiecteCumparate);
    string * getNumeProdus();

    int getNrObiecteCumparate();

    void setDotariCusca(string *DotariCusca, int nrTotalDeDotariCusca);
    string * getDotariCusca();

    void setNumarDotare(int *NumarDotare, int nr);
    int *getNumarDotare();

    int getNrTotalDeDotariCusca();

    AdapostAnimale(); // constructorul fara parametri
    AdapostAnimale(float *ConsumIntroZi, string *NumeProdus, int NrObiecteCumparate, string *DotariCusca, int*NumarDotare, int nrTotalDeDotariCusca); // cu toti param
    AdapostAnimale(float *ConsumIntroZi, string * NumeProdus, int NrObiecteCumparate); // cu 3 param
    AdapostAnimale(const AdapostAnimale &obj); // copyconstructor;
    AdapostAnimale &operator=(const AdapostAnimale &obj);
    friend ostream &operator<<(ostream & out, const AdapostAnimale &obj); //operator afisare
    friend istream &operator>>(istream & in, AdapostAnimale &obj); //operator citire;
    friend AdapostAnimale operator*(int x, AdapostAnimale &obj); // * la stanga
    string operator[](int index); // metoda mai usoara de a afisa numele produselor;
    AdapostAnimale operator*(int x); // * las dreapta
    AdapostAnimale operator/(int x); // evident la dreapta (obj / variabila)
    bool operator==(AdapostAnimale &obj);
    void Functionalitate_Adapost();
    ~AdapostAnimale(); //destructor

    void Citire();

};
// PENTRU ADAPOST //

void AdapostAnimale::setConsumIntroZi(float *ConsumIntroZi, int NrObiecteCumparate){
    this->NrObiecteCumparate = NrObiecteCumparate;
    if (this->ConsumIntroZi!=NULL)
        delete[] this->ConsumIntroZi;
    this->ConsumIntroZi = new float[NrObiecteCumparate];
    for (int i=0; i<this->NrObiecteCumparate; i++)
        this->ConsumIntroZi[i] = ConsumIntroZi[i];
}
float *AdapostAnimale::getConsumIntroZi(){
    return this->ConsumIntroZi;
}

void AdapostAnimale::setNumeProdus(string *NumeProdus, int NrObiecteCumparate){
    this->NrObiecteCumparate = NrObiecteCumparate;
    if(this->NumeProdus!=NULL)
        delete[] this->NumeProdus;
    this->NumeProdus=new string[NrObiecteCumparate];
    for (int i=0; i<this->NrObiecteCumparate; i++)
        this->NumeProdus[i] = NumeProdus[i];

}
string * AdapostAnimale::getNumeProdus(){
    return this->NumeProdus;
}

int AdapostAnimale::getNrObiecteCumparate(){
    return this->NrObiecteCumparate;
}

void AdapostAnimale::setDotariCusca(string* DotariCusca, int nr){
    this->nrTotalDeDotariCusca = nr;
    if (this->DotariCusca!=NULL)
        delete[] this->DotariCusca;
    this->DotariCusca = new string[this->nrTotalDeDotariCusca];
    for (int i=0; i<this->nrTotalDeDotariCusca; i++)
        this->DotariCusca[i] = DotariCusca[i];
}
string *AdapostAnimale::getDotariCusca(){
    return this->DotariCusca;
}

void AdapostAnimale::setNumarDotare(int *NumarDotare, int nrTotalDeDotariCusca){
    this->nrTotalDeDotariCusca = nrTotalDeDotariCusca;
    if(this->NumarDotare!=NULL)
        delete[] this->NumarDotare;
    this->NumarDotare = new int[this->nrTotalDeDotariCusca];
    for (int i=0; i<this->nrTotalDeDotariCusca; i++)
        this->NumarDotare[i] = NumarDotare[i];
}
int *AdapostAnimale::getNumarDotare(){
    return this->NumarDotare;
}

int AdapostAnimale::getNrTotalDeDotariCusca(){
    return this->nrTotalDeDotariCusca;
}


AdapostAnimale::AdapostAnimale(){ //contructorul fara parametrii
    this->ConsumIntroZi = NULL;
    this->NumarDotare = NULL;
    this->DotariCusca = NULL;
    this->NumeProdus = NULL;
    this->NrObiecteCumparate = 0;
    this->nrTotalDeDotariCusca = 0;
}

AdapostAnimale::AdapostAnimale(float * ConsumIntroZi, string * NumeProdus, int NrObiecteCumparate){
    this->nrTotalDeDotariCusca = 0;
    this->NumarDotare = NULL;
    this->DotariCusca = NULL;

    this->NrObiecteCumparate = NrObiecteCumparate;
    this->NumeProdus = new string[NrObiecteCumparate];
    for (int i=0; i<NrObiecteCumparate; i++)
        this->NumeProdus[i] = NumeProdus[i];

    this->ConsumIntroZi = new float[NrObiecteCumparate];
    for (int i=0; i<NrObiecteCumparate; i++)
        this->ConsumIntroZi[i] = ConsumIntroZi[i];

}
AdapostAnimale::AdapostAnimale(float *ConsumIntroZi, string *NumeProdus, int NrObiecteCumparate, string *DotariCusca, int*NumarDotare, int nrTotalDeDotariCusca){
    this->NrObiecteCumparate = NrObiecteCumparate;
    this->nrTotalDeDotariCusca = nrTotalDeDotariCusca;

    this->ConsumIntroZi = new float[NrObiecteCumparate];
    for(int i = 0; i<NrObiecteCumparate; i++)
        this->ConsumIntroZi[i] = ConsumIntroZi[i];

    this->NumeProdus = new string[NrObiecteCumparate];
    for(int i = 0; i<NrObiecteCumparate; i++)
        this->NumeProdus[i] = NumeProdus[i];

    this->DotariCusca = new string[nrTotalDeDotariCusca];
    for(int i = 0; i<nrTotalDeDotariCusca; i++)
        this->DotariCusca[i] = DotariCusca[i];

    this->NumarDotare = new int[nrTotalDeDotariCusca];
    for(int i = 0; i<nrTotalDeDotariCusca; i++)
        this->NumarDotare[i] = NumarDotare[i];

}

AdapostAnimale::AdapostAnimale(const AdapostAnimale &obj){ // copy constructor
    this->NrObiecteCumparate = obj.NrObiecteCumparate;
    this->nrTotalDeDotariCusca = obj.nrTotalDeDotariCusca;

    this->ConsumIntroZi = new float[obj.NrObiecteCumparate];
    for (int i=0; i<NrObiecteCumparate; i++)
        this->ConsumIntroZi[i] = obj.ConsumIntroZi[i];

    this->NumeProdus = new string[NrObiecteCumparate];
    for(int i = 0; i<NrObiecteCumparate; i++)
        this->NumeProdus[i] = obj.NumeProdus[i];

    this->DotariCusca = new string[obj.nrTotalDeDotariCusca];
    for (int i=0; i<nrTotalDeDotariCusca; i++)
        this->DotariCusca[i] = obj.DotariCusca[i];

    this->NumarDotare = new int[obj.nrTotalDeDotariCusca];
    for (int i=0; i<nrTotalDeDotariCusca; i++)
        this->NumarDotare[i] = obj.NumarDotare[i];

}

AdapostAnimale &AdapostAnimale::operator=(const AdapostAnimale& obj){ // operatorul de atribuire;
    if (this != &obj){
        if (this->ConsumIntroZi!=NULL)
            delete[] this->ConsumIntroZi;
        if(this->NumeProdus!=NULL)
            delete[] NumeProdus;
        if (this->DotariCusca!=NULL)
            delete[] this->DotariCusca;
        if (this->NumarDotare!=NULL)
            delete[] this->NumarDotare;

        this->NrObiecteCumparate = obj.NrObiecteCumparate;
        this->nrTotalDeDotariCusca = obj.nrTotalDeDotariCusca;

        this->ConsumIntroZi = new float[obj.NrObiecteCumparate];
        for (int i=0; i<obj.NrObiecteCumparate; i++)
            this->ConsumIntroZi[i] = obj.ConsumIntroZi[i];

        this->NumeProdus = new string[NrObiecteCumparate];
        for(int i = 0; i<NrObiecteCumparate; i++)
            this->NumeProdus[i] = obj.NumeProdus[i];

        this->DotariCusca = new string[obj.nrTotalDeDotariCusca];
        for (int i=0; i<obj.nrTotalDeDotariCusca; i++)
            this->DotariCusca[i] = obj.DotariCusca[i];

        this->NumarDotare = new int[obj.nrTotalDeDotariCusca];
        for (int i=0; i<obj.nrTotalDeDotariCusca; i++)
            this->NumarDotare[i] = obj.NumarDotare[i];
    }
    return *this;
}

ostream &operator<<(ostream& out, const AdapostAnimale &obj){ // afisare;
    out << "\nIntr-o zi au fost cumparate " << obj.NrObiecteCumparate << " obiecte";
    for (int i=0; i<obj.NrObiecteCumparate; i++)
        out << "\n" << obj.NumeProdus[i] << " in valoare de: " << obj.ConsumIntroZi[i] << " lei";
    out << "\nNumarul total de dotari ale custii este: " << obj.nrTotalDeDotariCusca;
    out << "\nDotarile sunt: ";
    for (int i=0; i<obj.nrTotalDeDotariCusca; i++)
        out << "\n" << obj.NumarDotare[i] << " " << obj.DotariCusca[i] << "(uri)";

    return out;
}

istream &operator>>(istream &in, AdapostAnimale &obj){ //citire de la tastatura
    cout << "Cate produse ati cumparat astazi ? ";
    in >> obj.NrObiecteCumparate;
    cout << "Introduceti cele " << obj.NrObiecteCumparate << " obiecte urmate de pretul lor: \n";
    if(obj.ConsumIntroZi!=NULL)
        delete[] obj.ConsumIntroZi;
    if(obj.NumeProdus!=NULL)
        delete[] obj.NumeProdus;
    obj.NumeProdus = new string[obj.NrObiecteCumparate];
    obj.ConsumIntroZi = new float[obj.NrObiecteCumparate];
    for (int i = 0; i<obj.NrObiecteCumparate; i++){
        cout << "Produsul: ";
        in >> obj.NumeProdus[i];
        cout << "Pretul: ";
        in >> obj.ConsumIntroZi[i];
    }
    cout << "Introduceti numarul de dotari al custii: ";
    in >> obj.nrTotalDeDotariCusca;

    cout << "Introduceti dotarile custii: \n";
    if(obj.DotariCusca!=NULL)
        delete[] obj.DotariCusca;
    obj.DotariCusca = new string[obj.nrTotalDeDotariCusca];
    for(int i=0; i<obj.nrTotalDeDotariCusca; i++)
        in >> obj.DotariCusca[i];

    cout << "Numarul de utilitati: (ex: 2 paturi, 3 boluri): ";
    if(obj.NumarDotare!=NULL)
        delete[] obj.NumarDotare;
    obj.NumarDotare = new int[obj.nrTotalDeDotariCusca];
    for(int i=0; i<obj.nrTotalDeDotariCusca; i++){
        cout << "Cate " << obj.DotariCusca[i] << "(uri) sunt? ";
        in >> obj.NumarDotare[i];
    }
    return in;
}

string AdapostAnimale::operator[](int index){ // operatorul de indexare;
    if(index < 0 && index > this->NrObiecteCumparate){
        cout << "Index out of range";
        exit(0);
    }
    return NumeProdus[index];
}

AdapostAnimale AdapostAnimale::operator*(int x){ // operatorul * la la dreapta
    AdapostAnimale aux(*this);
    for (int i=0; i<aux.NrObiecteCumparate; i++)
        aux.ConsumIntroZi[i] = x*aux.ConsumIntroZi[i];
    return aux;
}

AdapostAnimale operator*(int x, AdapostAnimale &obj){ //operatorul * la stanga
    return obj*x;
}

AdapostAnimale AdapostAnimale::operator/(int x){ // operatorul / ; ! obj/nr NU nr/obj (in exemplul meu nu se potriveste);
    AdapostAnimale aux(*this);
    if (x > 0){
        for (int i=0; i<aux.NrObiecteCumparate; i++)
            aux.ConsumIntroZi[i] = aux.ConsumIntroZi[i]/x;
    }
    return aux;
}

bool AdapostAnimale::operator==(AdapostAnimale &obj){ // operatorul de egalitate
    for (int i=0; i<this->NrObiecteCumparate; i++)
        if (this->ConsumIntroZi[i] == obj.ConsumIntroZi[i] && NumeProdus[i] == obj.NumeProdus[i])
            return true;
    return false;
}


AdapostAnimale::~AdapostAnimale(){

    if (this->ConsumIntroZi!=NULL)
        delete[] this->ConsumIntroZi;
    if(this->NumeProdus!=NULL)
        delete[] this->NumeProdus;
    if (this->DotariCusca!=NULL)
        delete[] this->DotariCusca;
    if (this->NumarDotare!=NULL)
        delete[] this->NumarDotare;

}

void AdapostAnimale::Functionalitate_Adapost(){
    float reducere;
    bool var;
    cout << "Aveti un cupon de reducere ? 1-DA / 0-NU ";
    cin >> var;
    if (var){
        cout << "Introduceti cuponul (in procente): ";
        cin >> reducere;
        reducere = reducere/100;
        for (int i=0; i<this->NrObiecteCumparate; i++)
            this->ConsumIntroZi[i] = this->ConsumIntroZi[i] * reducere;
    for (int i=0; i<this->NrObiecteCumparate; i++)
        cout << this->NumeProdus[i] << " a fost redus la " << this->ConsumIntroZi[i] << " lei de la " << this->ConsumIntroZi[i]/reducere << "\n";
    }
}

void AdapostAnimale::Citire(){
    cout << "Cate produse ati cumparat astazi ? ";
    cin >> this->NrObiecteCumparate;
    cout << "Introduceti cele " << this->NrObiecteCumparate << " obiecte urmate de pretul lor: \n";
    if(this->ConsumIntroZi!=NULL)
        delete[] this->ConsumIntroZi;
    if(this->NumeProdus!=NULL)
        delete[] this->NumeProdus;
    this->NumeProdus = new string[this->NrObiecteCumparate];
    this->ConsumIntroZi = new float[this->NrObiecteCumparate];
    for (int i = 0; i<this->NrObiecteCumparate; i++){
        cout << "Produsul: ";
        cin >> this->NumeProdus[i];
        cout << "Pretul: ";
        cin >> this->ConsumIntroZi[i];
    }
}

// S-A TERMINAT CLASA ADAPOST //


// ETAPA 2 INTERFATA + CLASA ABSTRACTA
class AdapostInterfata{ // sa schimbi numele
public:
    virtual void Asociatie();
    virtual void Fonduri_func() = 0;
};

void AdapostInterfata::Asociatie(){
    cout << "Asociatia SALVEAZA UN PRIETEN va multumeste"; // sa fie un fel de logo
}

class DONATII{
private:
    string nume;
    string prenume;
    float donatie;
public:
    void set_nume(string nume);
    string get_nume();

    void set_prenume(string prenume);
    string get_prenume();

    void set_donatie(float donatie);
    float get_donatie();

    DONATII();
    DONATII(string nume, string prenume, float donatie);
    DONATII(const DONATII &obj);
    DONATII&operator=(const DONATII &obj);

    friend istream&operator>>(istream &in, DONATII &obj);
    friend ostream&operator<<(ostream &out, const DONATII &obj);

    virtual istream&Citire(istream &in);
    virtual ostream&Afisare(ostream &out)const;

    DONATII &operator+(DONATII &obj);
    bool operator==(const DONATII &obj);

    ~DONATII(){}
};
void DONATII::set_nume(string nume){
    this->nume = nume;
}
string DONATII::get_nume(){
    return this->nume;
}

void DONATII::set_prenume(string prenume){
    this->prenume = prenume;
}
string DONATII::get_prenume(){
    return this->prenume;
}

void DONATII::set_donatie(float donatie){
    this->donatie = donatie;
}
float DONATII::get_donatie(){
    return this->donatie;
}

DONATII::DONATII(){
    this->nume = "none";
    this->prenume = "none";
    this->donatie = 0.0;
}

DONATII::DONATII(string nume, string prenume, float donatie){
    this->nume = nume;
    this->prenume = prenume;
    this->donatie = donatie;
}

DONATII::DONATII(const DONATII &obj){
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->donatie = obj.donatie;
}

DONATII &DONATII::operator=(const DONATII &obj){
    if (this!=&obj){
        this->nume = obj.nume;
        this->prenume = obj.prenume;
        this->donatie = obj.donatie;
    }
    return *this;
}

ostream &DONATII::Afisare(ostream &out)const{
    out <<  "\n"<<this->nume << " " << this->prenume;
    out << "\nSuma donata: " << this->donatie << " lei";
    return out;
}

istream &DONATII::Citire(istream &in){
    cout << "\nNumele dvs: "; in >> this->nume;
    cout << "Prenumele dvs: "; in >> this->prenume;
    cout << "Introduceti suma dorita "; in >> this->donatie;
    return in;
}

ostream &operator<<(ostream &out, const DONATII &obj){
    return obj.Afisare(out);
}

istream &operator>>(istream &in, DONATII&obj){
    return obj.Citire(in);
}

DONATII &DONATII::operator+(DONATII &obj){
    obj.nume = this->nume + " " + obj.nume;
    obj.prenume = this->prenume + " " + obj.prenume;
    obj.donatie = this->donatie + obj.donatie;
    return obj;
}

bool DONATII::operator==(const DONATII &obj){
    if(this->nume == obj.nume && this->prenume == obj.prenume && this->donatie == obj.donatie)
        return true;
    return false;
}

class FONDURI:public AdapostInterfata{
private:
    float fonduri;
    int nrDonatori;
    DONATII * donatori;
public:
    FONDURI();
    FONDURI(int nrDonatori, DONATII *donatori);
    FONDURI(const FONDURI&obj);
    FONDURI&operator=(const FONDURI &obj);
    friend istream&operator>>(istream &in, FONDURI &obj);
    friend ostream&operator<<(ostream &out, const FONDURI &obj);

    friend FONDURI operator+(FONDURI fon, const DONATII &don);
    friend FONDURI operator+(const DONATII &don, const FONDURI & fon);

    DONATII operator[](int index);


    void Fonduri_func(){
        int index = 0;
        float maxi;
        if(donatori!=NULL){
            maxi = donatori->get_donatie();
            if (nrDonatori > 1){
                for (int i=0; i<nrDonatori-1; i++)
                    if(maxi < donatori[i+1].get_donatie()){
                        maxi = donatori[i+1].get_donatie();
                        index = i+1;
                    }
                cout << "\nTop donator: " << donatori[index].get_nume() << " " << donatori[index].get_prenume() << " " << donatori[index].get_donatie() << " lei\n";
            }
            else
                cout << "Top donator: " << donatori->get_nume() << " " << donatori->get_prenume() << " " << donatori->get_donatie() << " lei\n";
        }
        else
            cout << "Nu exista niciun donator";
    }

    friend FONDURI operator+(const FONDURI &fond, const FONDURI &obj); // opeartorul adunare pt obiecte de tip fond

    void set_fonduri(float fonduri){this->fonduri = fonduri;}
    float get_fonduri() {return this->fonduri;}

    void Asociatie(){cout << "Asociatia SALVEAZA UN PRIETEN va multumeste!";}

    void Donatori();

    int get_nrDonator(){return this->nrDonatori;}
    ~FONDURI();
};
void FONDURI::Donatori(){
    cout << "Donatorii sunt: \n";
    for (int i=0; i<this->nrDonatori; i++)
        cout << this->donatori[i];

}

FONDURI::FONDURI(){
    this->donatori = NULL;
    this->nrDonatori = 0;
    this->fonduri = 0;
}

FONDURI::FONDURI(int nrDonatori, DONATII *donatori){
    this->nrDonatori = nrDonatori;
    this->donatori = new DONATII[nrDonatori];
    for (int i=0; i<nrDonatori; i++)
        this->donatori[i] = donatori[i];
}

FONDURI::FONDURI(const FONDURI&obj){
    this->fonduri = obj.fonduri;
    this->nrDonatori = obj.nrDonatori;

    this->donatori = new DONATII[obj.nrDonatori];
    for(int i=0; i<obj.nrDonatori; i++)
        this->donatori[i] = obj.donatori[i];

}

FONDURI &FONDURI::operator=(const FONDURI& obj){
    if(this!=&obj){

        if(this->donatori!=NULL)
            delete[] donatori;

        this->fonduri = obj.fonduri;

        this->nrDonatori = obj.nrDonatori;
        this->donatori = new DONATII[obj.nrDonatori];
        for(int i=0; i<obj.nrDonatori; i++)
            this->donatori[i] = obj.donatori[i];
    }
    return *this;
}

FONDURI operator+(FONDURI fon, const DONATII &don){
    DONATII *lista;

    DONATII aux(don);

    lista = new DONATII[fon.nrDonatori];
    for(int i = 0; i<fon.nrDonatori; i++)
        lista[i] = fon[i];
    if(fon.donatori!=NULL)
        delete[] fon.donatori;
    ++fon.nrDonatori;
    fon.donatori = new DONATII[fon.nrDonatori];
    for(int i=0; i<fon.nrDonatori-1;i++)
        fon.donatori[i] = lista[i];
    fon.donatori[fon.nrDonatori-1] = don;

    fon.fonduri += aux.get_donatie();

    return fon;
}

FONDURI operator+(const DONATII &don, const FONDURI &fon){
    FONDURI aux(fon);
    DONATII * lista, aux2(don);
    lista = new DONATII[aux.nrDonatori];
    for(int i=0; i<aux.nrDonatori; i++)
        lista[i] = aux.donatori[i];

    if(aux.donatori!=NULL)
        delete[] aux.donatori;

    ++aux.nrDonatori;
    aux.donatori = new DONATII[aux.nrDonatori];
    for(int i=0; i<aux.nrDonatori-1; i++)
        aux.donatori[i] = lista[i];
    aux.donatori[aux.nrDonatori-1] = don;

    aux.fonduri += aux2.get_donatie(); // actualizez fondurile in functie de donatii - ar trebui sa fie >= donatiile.

    return aux;
}

istream &operator>>(istream &in, FONDURI &obj){
    float fonduriAux = 0.0;

    cout << "Numarul de donatori: ";
    in >> obj.nrDonatori;
    if(obj.donatori!=NULL)
        delete[] obj.donatori;
    obj.donatori = new DONATII[obj.nrDonatori];
    cout << "Introduceti donatorii: ";
    for (int i=0; i<obj.nrDonatori; i++){
        in >> obj.donatori[i];
        fonduriAux = fonduriAux + obj.donatori[i].get_donatie();
    }
    obj.fonduri = fonduriAux;
    return in;
}

ostream &operator<<(ostream &out, const FONDURI &obj){
    out << "\nDonatorii sunt: ";
    for(int i=0; i<obj.nrDonatori; i++)
        out << obj.donatori[i] << " ";
    out << "\nAu fost stranse fonduri in valoare de: " << obj.fonduri << " lei\n";
    return out;
}

DONATII FONDURI::operator[](int index){
    if(0<=index && index<this->nrDonatori)
        return donatori[index];
    else{
        DONATII obj;
        return obj;
    }
}

FONDURI::~FONDURI(){
    if(this->donatori!=NULL)
        delete[] donatori;
}

FONDURI operator+(const FONDURI &fond, const FONDURI &obj){
    FONDURI aux(fond);
    DONATII *lista = new DONATII[aux.nrDonatori];
    for (int i=0; i<aux.nrDonatori; i++)
        lista[i] = aux.donatori[i];

    if (aux.donatori !=NULL)
        delete[] aux.donatori;

    int var = aux.nrDonatori;
    aux.nrDonatori += obj.nrDonatori;

    aux.donatori = new DONATII[aux.nrDonatori];

    for (int i=0; i<var; i++)
        aux.donatori[i] = lista[i];
    for (int i=var; i<aux.nrDonatori; i++)
        aux.donatori[i] = obj.donatori[i-var];

    aux.fonduri += obj.fonduri;

    return aux;

}
// SFARSIT FONDURI si DONATIE //

class AnimalDeCompanie{
private:
    bool Adoptat;
    int VarstaAnimal;
    float GreutateAnimal;
    double InaltimeAnimal;
    string CuloareAnimal;
    char SexAnimal; // M / F
    char * DetaliiAnimal;// daca a fost abandonat, donat etc;
    string DetaliiSuplimentare; // poate sa si lipseasca si se va nota cu -;
    int SanatateAnimal; // 1 - foarte buna, 2 - buna, 3 - rea, 4 - foarte rea;

    const int CodAnimal;
    static int ContorCOD;
public:

    bool getAdoptat();
    void setAdoptat(bool Adoptat);

    int getVarstaAnimal();
    void setVarstaAnimal(int VarstaAnimal);

    float getGreutateAnimal();
    void setGreutateAnimal(float GreutateAnimal);

    double getInaltimeAnimal();
    void setInaltimeAnimal(double InaltimeAnimal);

    string getCuloareAnimal();
    void setCuloareAnimal(string CuloareAnimal);

    char getSexAnimal();
    void setSexAnimal(char SexAnimal);

    char *getDetaliiAnimal();
    void setDetaliiAnimal(char * DetaliiAnimal);

    string getDetaliiSuplimentare();
    void setDetaliiSuplimentare(string DetaliiSuplimentare);

    int getSanatateAnimal();
    void setSanatateAnimal(int SanatateAnimal);

    int getCodAnimal();

    AnimalDeCompanie(); // constructor fara parametri
    AnimalDeCompanie(bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, int SanatateAnimal);
    AnimalDeCompanie(bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, char *DetaliiAnimal, string DetaliiSuplimentare, int SanatateAnimal);// constructor cu toti parametrii;
    AnimalDeCompanie(const AnimalDeCompanie &obj); // copyconstructor
    AnimalDeCompanie &operator=(const AnimalDeCompanie &obj); // operatorul de atribuire egal
    friend ostream &operator<<(ostream & out, const AnimalDeCompanie &obj); // operator afisare
    friend istream &operator>>(istream &in, AnimalDeCompanie &obj); // operator citire
    const AnimalDeCompanie &operator++(); // fac pentru sanatate animal, gen daca e foarte grava si veterinarul are grija de el faca sanatate
    const AnimalDeCompanie operator++(int);
    const AnimalDeCompanie &operator--();
    const AnimalDeCompanie operator--(int);
    explicit operator float();
    void Functionalitate_AnimalDeCompanie();
    ~AnimalDeCompanie(); //destructor

    //ETAPA 2
    virtual ostream&Afisare(ostream &out)const;
    virtual istream&Citire(istream& in);

};

// CLASA ANIMAL;
int AnimalDeCompanie::ContorCOD = 1;

bool AnimalDeCompanie::getAdoptat(){
    return this->Adoptat;
}
void AnimalDeCompanie::setAdoptat(bool Adoptat){
    this->Adoptat = Adoptat;
}

int AnimalDeCompanie::getVarstaAnimal(){
    return this->VarstaAnimal;
}
void AnimalDeCompanie::setVarstaAnimal(int VarstaAnimal){
    this->VarstaAnimal = VarstaAnimal;
}

float AnimalDeCompanie::getGreutateAnimal(){
    return this->GreutateAnimal;
}
void AnimalDeCompanie::setGreutateAnimal(float GreutateAnimal){
    this->GreutateAnimal = GreutateAnimal;
}

double AnimalDeCompanie::getInaltimeAnimal(){
    return this->InaltimeAnimal = InaltimeAnimal;
}
void AnimalDeCompanie::setInaltimeAnimal(double InaltimeAnimal){
    this->InaltimeAnimal = InaltimeAnimal;
}

string AnimalDeCompanie::getCuloareAnimal(){
    return this->CuloareAnimal;
}
void AnimalDeCompanie::setCuloareAnimal(string CuloareAnimal){
    this->CuloareAnimal = CuloareAnimal;
}

char AnimalDeCompanie::getSexAnimal(){
    return this->SexAnimal;
}
void AnimalDeCompanie::setSexAnimal(char SexAnimal){
    this->SexAnimal = SexAnimal;
}

char * AnimalDeCompanie::getDetaliiAnimal(){
    return this->DetaliiAnimal;
}
void AnimalDeCompanie::setDetaliiAnimal(char *DetaliiAnimal){
    if (this->DetaliiAnimal!=NULL)
        delete[] this->DetaliiAnimal;
    this->DetaliiAnimal = new char[strlen(DetaliiAnimal)+1];
    strcpy(this->DetaliiAnimal, DetaliiAnimal);
}
string AnimalDeCompanie::getDetaliiSuplimentare(){
    return this->DetaliiSuplimentare;
}
void AnimalDeCompanie::setDetaliiSuplimentare(string DetaliiSuplimentare){
    this->DetaliiSuplimentare = DetaliiSuplimentare;
}

int AnimalDeCompanie::getSanatateAnimal(){
    return this->SanatateAnimal;
}
void AnimalDeCompanie::setSanatateAnimal(int SanatateAnimal){
    this->SanatateAnimal = SanatateAnimal;
}

int AnimalDeCompanie::getCodAnimal(){
    return this->CodAnimal;
}

AnimalDeCompanie::AnimalDeCompanie():CodAnimal(ContorCOD++){ // constructorul fara parametrii
    this->Adoptat = 1;
    this->VarstaAnimal = 0;
    this->GreutateAnimal = 0;
    this->InaltimeAnimal = 0;
    this->CuloareAnimal = "blank";
    this->SexAnimal = '?';
    this->DetaliiAnimal = new char[strlen("Nothing")+1];
    strcpy(this->DetaliiAnimal, "Nothing");

    this->SanatateAnimal = 0;
    this->DetaliiSuplimentare = "blank";

}

AnimalDeCompanie::AnimalDeCompanie(bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, int SanatateAnimal):CodAnimal(ContorCOD++){
    this->VarstaAnimal = VarstaAnimal;
    this->GreutateAnimal = GreutateAnimal;
    this->InaltimeAnimal = InaltimeAnimal;
    this->CuloareAnimal = CuloareAnimal;
    this->SexAnimal = SexAnimal;
    this->Adoptat = Adoptat;
    this->SanatateAnimal = SanatateAnimal;

    this->DetaliiSuplimentare = "blank";
    this->DetaliiAnimal = new char[strlen("Nothing")+1];
    strcpy(this->DetaliiAnimal, "Nothing");
}

AnimalDeCompanie::AnimalDeCompanie(bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, char *DetaliiAnimal, string DetaliiSuplimentare, int SanatateAnimal):CodAnimal(ContorCOD++){
    this->Adoptat = Adoptat;
    this->VarstaAnimal = VarstaAnimal;
    this->GreutateAnimal = GreutateAnimal;
    this->InaltimeAnimal = InaltimeAnimal;
    this->CuloareAnimal = CuloareAnimal;
    this->SexAnimal = SexAnimal;

    this->DetaliiAnimal = new char[strlen(DetaliiAnimal)+1];
    strcpy(this->DetaliiAnimal, DetaliiAnimal);

    this->DetaliiSuplimentare = DetaliiSuplimentare;
    this->SanatateAnimal = SanatateAnimal;
}

AnimalDeCompanie::AnimalDeCompanie(const AnimalDeCompanie &obj):CodAnimal(ContorCOD){ // copy constructor
    this->Adoptat = obj.Adoptat;
    this->VarstaAnimal = obj.VarstaAnimal;
    this->GreutateAnimal = obj.GreutateAnimal;
    this->InaltimeAnimal = obj.InaltimeAnimal;
    this->CuloareAnimal = obj.CuloareAnimal;
    this->SexAnimal = obj.SexAnimal;
    this->SanatateAnimal = obj.SanatateAnimal;
    this->DetaliiSuplimentare = obj.DetaliiSuplimentare;


    if(obj.DetaliiAnimal==NULL)
        this->DetaliiAnimal=NULL;
    else{
        this->DetaliiAnimal = new char[strlen(obj.DetaliiAnimal)+1];
        strcpy(this->DetaliiAnimal, obj.DetaliiAnimal);
    }

}

ostream &AnimalDeCompanie::Afisare(ostream &out)const{
    if (Adoptat==0)
        out << "Animalul este disponibil";
    else
        out << "Animalul nu este disponibil";
    out <<"\nId animal: " << CodAnimal;
    out <<"\nVarsta animal: " << VarstaAnimal;
    out <<"\nGreutate animal: " << GreutateAnimal;
    out <<"\nInaltime animal: " << InaltimeAnimal;
    out <<"\nCuloare animal: " << CuloareAnimal;
    out <<"\nSex animal: " << SexAnimal;
    out <<"\nDetalii animal: " << DetaliiAnimal;
    out <<"\nDetalii suplimentare: " << DetaliiSuplimentare;
    switch(SanatateAnimal){
    case 1:{
        out <<"\nSanatate animal: VERY GOOD\n";
    break;
    }
    case 2:{
        out <<"\nSanatate animal: GOOD\n";
    break;
    }
    case 3:{
        out <<"\nSanatate animal: BAD\n";
    break;
    }
    case 4:{
        out <<"\nSanatate animal: VERY BAD\n";
    break;
    }
    default:{
        out <<"\nDate gresite";
    break;
    }
    }


    return out;
}

ostream &operator<<(ostream &out, const AnimalDeCompanie &obj){
    return obj.Afisare(out);
}

istream &AnimalDeCompanie::Citire(istream &in){
    Adoptat = 0;
    cout << "Varsta animal: "; in>>VarstaAnimal;
    cout << "Greutate animal: "; in>>GreutateAnimal;
    cout << "Inaltime animal: "; in>>InaltimeAnimal;
    cout << "Culoare animal: "; in>>CuloareAnimal;
    cout << "Sex animal: "; in>>SexAnimal;
    cout << "Detalii animal: ";
    char aux[100];
    in>>aux;
    if (DetaliiAnimal!=NULL)
        delete[] DetaliiAnimal;
    DetaliiAnimal = new char[strlen(aux)+1];
    strcpy(DetaliiAnimal, aux);
    cout << "Sanatate animal (1-fb, 2-b, 3-r, 4-fr): "; in>>SanatateAnimal;
    cout << "Detalii suplimentare (daca exista, max 100 caract): ";
    in.get();
    char aux1[100];
    in.getline(aux1, 100);
    string s(aux1);
    DetaliiSuplimentare = s;

    /*in>>VarstaAnimal;
    in>>GreutateAnimal;
    in>>InaltimeAnimal;
    in>>CuloareAnimal;
    in>>SexAnimal;
    char aux[100];
    in>>aux;
    if (DetaliiAnimal!=NULL)
        delete[] DetaliiAnimal;
    DetaliiAnimal = new char[strlen(aux)+1];
    strcpy(DetaliiAnimal, aux);
    in>>SanatateAnimal;
    in.get();
    char aux1[100];
    in.getline(aux1, 100);
    string s(aux1);
    DetaliiSuplimentare = s; */

    return in;
}

istream &operator>>(istream &in, AnimalDeCompanie &obj){
    return obj.Citire(in);
}

AnimalDeCompanie & AnimalDeCompanie::operator=(const AnimalDeCompanie &obj){ // operator =
    if (this!=&obj){
        this->Adoptat = Adoptat;
        this->VarstaAnimal = obj.VarstaAnimal;
        this->GreutateAnimal = obj.GreutateAnimal;
        this->InaltimeAnimal = obj.InaltimeAnimal;
        this->CuloareAnimal = obj.CuloareAnimal;
        this->SexAnimal = obj.SexAnimal;
        this->SanatateAnimal = obj.SanatateAnimal;
        this->DetaliiSuplimentare = obj.DetaliiSuplimentare;

        if (this->DetaliiAnimal != NULL)
            delete[] this->DetaliiAnimal;

        if(obj.DetaliiAnimal==NULL)
            this->DetaliiAnimal=NULL;
        else{
            this->DetaliiAnimal = new char[strlen(obj.DetaliiAnimal)+1];
            strcpy(this->DetaliiAnimal, obj.DetaliiAnimal);
        }

    }
    return *this;
}

const AnimalDeCompanie & AnimalDeCompanie::operator++(){ //pre-incrementare
    if(this->SanatateAnimal>=1 && this->SanatateAnimal<4)
        this->SanatateAnimal++;
    return *this;
}
const AnimalDeCompanie AnimalDeCompanie::operator++(int){ //post-incrementare
    AnimalDeCompanie aux(*this);
    if(this->SanatateAnimal>=1 && this->SanatateAnimal<4)
        this->SanatateAnimal++;
    return aux;
}

const AnimalDeCompanie & AnimalDeCompanie::operator--(){ //pre-decrementare
    if(this->SanatateAnimal>1 && this->SanatateAnimal<=4)
        this->SanatateAnimal--;
    return *this;
}
const AnimalDeCompanie  AnimalDeCompanie::operator--(int){ //post-decrementare
    AnimalDeCompanie aux(*this);
    if(this->SanatateAnimal>1 && this->SanatateAnimal<=4)
        this->SanatateAnimal--;
    return aux;

}

AnimalDeCompanie::operator float(){
    return (float)this->InaltimeAnimal;
}

AnimalDeCompanie::~AnimalDeCompanie(){
    if (this->DetaliiAnimal!=NULL)
        delete[] this->DetaliiAnimal;

}

void AnimalDeCompanie::Functionalitate_AnimalDeCompanie(){
    cout << "Varsta:" << VarstaAnimal; cout << " ani Inaltime: " << InaltimeAnimal; cout << " metri Greutate: " << GreutateAnimal << " kg";
    cout << "\nDetali animal: " << DetaliiAnimal; cout << " Culoare animal: " << CuloareAnimal; cout << " Sex animal: " << SexAnimal;
    cout << "\nSanatate animal: " << SanatateAnimal; cout << " Detalii suplimentare: " << DetaliiSuplimentare; cout << " Cod animal: " << CodAnimal;
}

// S-A TERMINAT CLASA ANIMAL;

//ETAPA 2

class DOG: public AnimalDeCompanie{
private:
    string nume;
    string rasa;
public:

    string getNume();
    void setNume(string nume);

    string getRasa();
    void setRasa(string rasa);

    DOG();
    DOG(string nume, string rasa, bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, char *DetaliiAnimal, string DetaliiSuplimentare, int SanatateAnimal);
    DOG(const DOG & caine);
    DOG&operator =(const DOG &caine);

    virtual ostream& Afisare(ostream& out)const;
    virtual istream& Citire(istream& in);

    ~DOG();

};

string DOG::getNume(){
    return this->nume;
}

void DOG::setNume(string nume){
    this->nume = nume;
}

string DOG::getRasa(){
    return this->rasa;
}

void DOG::setRasa(string rasa){
    this->rasa = rasa;
}

DOG::DOG():AnimalDeCompanie(){
    this->nume = "none";
    this->rasa = "none";
}

DOG::DOG(string nume, string rasa, bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, char *DetaliiAnimal, string DetaliiSuplimentare, int SanatateAnimal):AnimalDeCompanie(Adoptat, VarstaAnimal, GreutateAnimal, InaltimeAnimal, CuloareAnimal, SexAnimal, DetaliiAnimal, DetaliiSuplimentare, SanatateAnimal){
    this->nume = nume;
    this->rasa = rasa;
}

DOG::DOG(const DOG &caine):AnimalDeCompanie(caine){
    this->nume = caine.nume;
    this->rasa = caine.rasa;
}

DOG &DOG::operator=(const DOG &caine){
    if(this!=&caine){
        AnimalDeCompanie::operator=(caine);
        this->nume = caine.nume;
        this->rasa = caine.rasa;
    }
    return *this;
}

istream &DOG::Citire(istream &in){
    AnimalDeCompanie::Citire(in);
    cout << "Dati un nume cainelui: ";
    in >> nume;
    cout << "Rasa cainelui: ";
    in >> rasa;
    return in;
}

ostream &DOG::Afisare(ostream &out)const{
    AnimalDeCompanie::Afisare(out);
    out << "Numele cainelui este: " << nume;
    out << "\nRasa cainelui este: " << rasa;
    return out;
}

DOG::~DOG(){}

// same pentru pisica;

class CAT: public AnimalDeCompanie{
private:
    string nume;
    string rasa;
public:

    string getNume();
    void setNume(string nume);

    string getRasa();
    void setRasa(string rasa);

    CAT();
    CAT(string nume, string rasa, bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, char *DetaliiAnimal, string DetaliiSuplimentare, int SanatateAnimal);
    CAT(const CAT & pisica);
    CAT&operator =(const CAT &pisica);

    virtual ostream& Afisare(ostream& out)const;
    virtual istream& Citire(istream& in);

    ~CAT();

};

string CAT::getNume(){
    return this->nume;
}

void CAT::setNume(string nume){
    this->nume = nume;
}

string CAT::getRasa(){
    return this->rasa;
}

void CAT::setRasa(string rasa){
    this->rasa = rasa;
}

CAT::CAT():AnimalDeCompanie(){
    this->nume = "none";
    this->rasa = "none";
}

CAT::CAT(string nume, string rasa, bool Adoptat, int VarstaAnimal, float GreutateAnimal, double InaltimeAnimal, string CuloareAnimal, char SexAnimal, char *DetaliiAnimal, string DetaliiSuplimentare, int SanatateAnimal):AnimalDeCompanie(Adoptat, VarstaAnimal, GreutateAnimal, InaltimeAnimal, CuloareAnimal, SexAnimal, DetaliiAnimal, DetaliiSuplimentare, SanatateAnimal){
    this->nume = nume;
    this->rasa = rasa;
}

CAT::CAT(const CAT &pisica):AnimalDeCompanie(pisica){
    this->nume = pisica.nume;
    this->rasa = pisica.rasa;
}

CAT &CAT::operator=(const CAT &pisica){
    if(this!=&pisica){
        AnimalDeCompanie::operator=(pisica);
        this->nume = pisica.nume;
        this->rasa = pisica.rasa;
    }
    return *this;
}

istream &CAT::Citire(istream &in){
    AnimalDeCompanie::Citire(in);
    cout << "Dati un nume pisicii: ";
    in >> nume;
    cout << "Rasa pisicii: ";
    in >> rasa;
    return in;
}

ostream &CAT::Afisare(ostream &out)const{
    AnimalDeCompanie::Afisare(out);
    out << "Numele pisicii este: " << nume;
    out << "\nRasa pisicii este: " << rasa;
    return out;
}

CAT::~CAT(){}

//S A TERMINAT ETAPA 2

class Angajat{
private:
    string Nume;
    string Prenume;
    char *Profesie;// veterinar / ingrijitor etc
    char * cnp;
    int CodProfesie; // ingrijitor 1, veterinar 2 etc; si nu e obligatoriu, va fi o metoda mai usoara
                     // de a ne referii la un angajat, in loc de veterinar putem spune 2 si stim ca ne referim la veterinar.
    int varsta;

    const int CodAngajat;
    static int ContorAngajat;
public:

    string getNume();
    void setNume(string Nume);

    string getPrenume();
    void setPrenume(string Prenume);

    char * getProfesie();
    void setProfesie(char * Profesie);

    char * getCNP();
    void setCNP(char * cnp);

    int getCodProfesie();
    void setCodProfesie(int CodProfesie);

    int getVarsta();
    void setVarsta(int varsta);

    int getCodAngajat();

    Angajat(); // constr fara param
    Angajat(string Nume, string Prenume, char * Profesie, char * cnp, int varsta, int CodProfesie);
    Angajat(string Nume, string Prenume, char * Profesie, char * cnp, int varsta); // pt ca cod profesie nu e obligatoriu
    Angajat(const Angajat& obj); //copy constructor
    Angajat& operator=(const Angajat& obj); // operatorul de atribuire;
    friend ostream& operator<<(ostream& out, const Angajat& obj); // operator afisare
    friend istream& operator>>(istream& in, Angajat& obj); //operator citire
    bool operator==(const Angajat &obj); // verificam daca angajatul s-a mai inregistrat odata;
    bool operator<(int x); // conditie ca nr maxim de caractere introduse pentru 30 caractere;
    bool operator>(int x); // varsta trebuie sa fie peste 25 ani;
    int Functionalitate_Angajat();
    ~Angajat(); //

    // partea 2-a din proiect

    virtual ostream&Afisare(ostream& out)const;
    virtual istream&Citire(istream& in);
};
// AICI INCEPE CLASA ANGAJAT

int Angajat::ContorAngajat = 1;

string Angajat::getNume(){
    return this->Nume;
}
void Angajat::setNume(string Nume){
    this->Nume = Nume;
}

string Angajat::getPrenume(){
    return this->Prenume;
}
void Angajat::setPrenume(string Prenume){
    this->Prenume = Prenume;
}

char * Angajat::getProfesie(){
    return this->Profesie;
}
void Angajat::setProfesie(char * Profesie){
    this->Profesie = Profesie;
}

char * Angajat::getCNP(){
    return this->cnp;
}
void Angajat::setCNP(char * cnp){
    this->cnp = cnp;
}

int Angajat::getCodProfesie(){
    return this->CodProfesie;
}
void Angajat::setCodProfesie(int CodProfesie){
    this->CodProfesie = CodProfesie;
}

int Angajat::getVarsta(){
    return this->varsta;
}
void Angajat::setVarsta(int varsta){
    this->varsta = varsta;
}

int Angajat::getCodAngajat(){
    return this->CodAngajat;
}

Angajat::Angajat():CodAngajat(ContorAngajat++){
    this->Nume = "None";
    this->Prenume = "None";

    this->cnp = new char[strlen("Nothing")+1];
    strcpy(this->cnp, "Nothing");

    this->Profesie = new char[strlen("Nothing")+1];
    strcpy(this->Profesie, "Nothing");

    this->CodProfesie = 0;
    this->varsta = 0;
}

Angajat::Angajat(string Nume, string Prenume, char * Profesie, char * cnp, int varsta):CodAngajat(ContorAngajat++){
    this->Nume = Nume;
    this->Prenume = Prenume;

    this->Profesie = new char[strlen(Profesie)+1];
    strcpy(this->Profesie, Profesie);

    this->cnp = new char[strlen(cnp)+1];
    strcpy(this->cnp, cnp);

    this->varsta = varsta;
}

Angajat::Angajat(string Nume, string Prenume, char *Profesie, char * cnp, int varsta, int CodProfesie):CodAngajat(ContorAngajat++){
    this->Nume = Nume;
    this->Prenume = Prenume;

    this->Profesie = new char[strlen(Profesie)+1];
    strcpy(this->Profesie, Profesie);

    this->cnp = new char[strlen(cnp)+1];
    strcpy(this->cnp, cnp);

    this->varsta = varsta;
    this->CodProfesie = CodProfesie;

}

Angajat::Angajat(const Angajat &obj):CodAngajat(ContorAngajat){
    this->Nume = obj.Nume;
    this->Prenume = obj.Prenume;

    if (obj.Profesie==NULL)
        this->Profesie = NULL;
    else{
        this->Profesie = new char[strlen(obj.Profesie)+1];
        strcpy(this->Profesie, obj.Profesie);
    }

    if (obj.cnp==NULL)
        this->cnp = NULL;
    else{
        this->cnp = new char[strlen(obj.cnp)+1];
        strcpy(this->cnp, obj.cnp);
    }

    this->varsta = obj.varsta;
    this->CodProfesie = obj.CodProfesie;
}

Angajat &Angajat::operator=(const Angajat &obj){
    if(this!=&obj){
        this->Nume = obj.Nume;
        this->Prenume = obj.Prenume;

        if (this->Profesie!=NULL)
            delete[] this->Profesie;
        if (obj.Profesie==NULL)
            this->Profesie = NULL;
        else{
            this->Profesie = new char[strlen(obj.Profesie)+1];
            strcpy(this->Profesie, obj.Profesie);
        }

        if (this->cnp!=NULL)
            delete[] this->cnp;
        if (obj.cnp==NULL)
            this->cnp = NULL;
        else{
            this->cnp = new char[strlen(obj.cnp)+1];
            strcpy(this->cnp, obj.cnp);
        }

        this->varsta = obj.varsta;
        this->CodProfesie = obj.CodProfesie;
    }
    return *this;
}

ostream& Angajat::Afisare(ostream &out)const{
    out <<"\nNumele: " << this->Nume;
    out <<"\nPrenumele: " << this->Prenume;
    out <<"\nVarsta: " << this->varsta;
    out <<"\nCNP: " << this->cnp;
    out <<"\nProfesie: " << this->Profesie;
    out <<"\nCod profesie: " << this->CodProfesie;
    out <<"\nID: " << this->CodAngajat;

    return out;
}

ostream &operator<<(ostream &out, const Angajat &obj){
    return obj.Afisare(out);
}

istream &Angajat::Citire(istream &in){
    /*cout << "\nNume: ";
    in >> this->Nume;
    cout << "\nPrenume: ";
    in>>this->Prenume;
    cout << "\nVarsta: ";
    in>>this->varsta;
    cout << "\nCNP: ";
    in>>this->cnp;
    cout << "\nProfesie: ";
    in>>this->Profesie;
    cout << "\nCod profesie (1-vet, 2-ingrij, 3-menajer, 4-Contabil): ";
    in >>this->CodProfesie; */

    in >> this->Nume;
    in>>this->Prenume;

    in>>this->varsta;

    in>>this->cnp;

    in>>this->Profesie;

    in >>this->CodProfesie;

    return in;
}

istream &operator>>(istream &in, Angajat &obj){
    return obj.Citire(in);
}

bool Angajat::operator==(const Angajat &obj){
    if (strcmp(this->cnp, obj.cnp) == 0 )
        return true;
    return false;
}

bool Angajat::operator<(int x){
    if (strlen(this->Profesie) < x)
        return true;
    return false;
}

bool Angajat::operator>(int x){
    if(this->varsta > x)
        return true;
    return false;
}

Angajat::~Angajat(){
    if(this->Profesie!=NULL)
        delete[] this->Profesie;
    if(this->cnp!=NULL)
        delete[] this->cnp;
}

int Angajat::Functionalitate_Angajat(){ //cv angajare, verifica daca datele introduse sunt corect
        if(this->varsta < 18){
            cout << "Nu aveti varsta minima pentru a va angaja";
            return false;
        }
        else{
            if(strlen(this->cnp) == 13){
                int prima_cifra = ((int)this->cnp[0]-48); // prima cifra 5 sau 6 -> copii nascuti dupa 2000 trebuie sa verific daca au 18 ani, prima 1 sau 2 copii nascuti in pana in 2000;
                int cifra2si3 = ((int)this->cnp[1]-48)*10+(int)this->cnp[2]-48; // verific daca anul din cnp e valid (cifrele de pe poz 1 si 2 indica anul nasterii)
                if ((prima_cifra != 1 || prima_cifra != 2) && this->varsta!=(2021-(1900+cifra2si3))){
                    cout << "Buledin invalid/Varsta nu corespunde";
                    return false;
                }
            }
            else{
                cout << "CNP-ul a fost introdus incorect";
                return false;
            }
        }

        int contor=0;
        for(int i=0; i<this->Nume.size(); i++)
            if (isalpha(this->Nume[i]))
                contor++;
        if (contor != this->Nume.size()){
            cout << "Numele a fost introdus incorect";
            return false;
        }

        contor = 0;
        for(int i=0; i<this->Prenume.size(); i++)
            if (isalpha(this->Prenume[i]))
                contor++;
        if (contor != this->Prenume.size()){
            cout << "Prenumele a fost introdus incorect";
            return false;
        }
    return true;
}

// S-A TERMINAT CLASA ANGAJAT


// INCEPE ETAPA 2;
class ProgramLucru: public Angajat{
private:
    double salariu;
    int nrOreLucru;
    string *zileLucru; //in ce zile lucreaza pe saptamana
    int nrZile;
public:
    double getSalariu();
    void setSalariu(double salariu);

    int getNrOreLucru();
    void setNrOreLucru(int nrOreLucru);

    string *getZileLucru();
    void setZileLucru(string *zileLucru, int nrZile);

    ProgramLucru();
    ProgramLucru(double salariu, int nrOreLucru, string *zileLucru, int nrZile, string Nume, string Prenume, char * Profesie, char * cnp, int varsta, int CodProfesie);
    ProgramLucru(const ProgramLucru& program);
    ProgramLucru&operator=(const ProgramLucru &program);

    virtual ostream&Afisare(ostream& out)const;
    virtual istream&Citire(istream& in);

    double Calculeaza_Salariu();

    ~ProgramLucru();
};

double ProgramLucru::getSalariu(){
    return this->salariu;
}
void ProgramLucru::setSalariu(double salariu){
    this->salariu = salariu;
}

int ProgramLucru::getNrOreLucru(){
    return this->nrOreLucru;
}
void ProgramLucru::setNrOreLucru(int nrOreLucru){
    this->nrOreLucru = nrOreLucru;
}

string *ProgramLucru::getZileLucru(){
    return this->zileLucru;
}
void ProgramLucru::setZileLucru(string *zileLucru, int nrZile){
    this->nrZile = nrZile;
    if(this->zileLucru!=NULL)
        delete[] this->zileLucru;
    this->zileLucru = new string[this->nrZile];
    for (int i=0; i<this->nrZile; i++)
        this->zileLucru[i] = zileLucru[i];
}

ProgramLucru::ProgramLucru():Angajat(){
    this->salariu =0.0;
    this->nrOreLucru = 0;
    this->nrZile = 0;
    this->zileLucru = NULL;
}

ProgramLucru::ProgramLucru(double salariu, int nrOreLucru, string *zileLucru, int nrZile, string Nume, string Prenume, char * Profesie, char * cnp, int varsta, int CodProfesie):Angajat(Nume, Prenume, Profesie, cnp, varsta, CodProfesie){
    this->salariu = salariu;
    this->nrOreLucru = nrOreLucru;

    this->nrZile = nrZile;
    this->zileLucru = new string[nrZile];
    for (int i=0; i<nrZile; i++)
        this->zileLucru[i] = zileLucru[i];
}

ProgramLucru::ProgramLucru(const ProgramLucru& program):Angajat(program){
    this->salariu = program.salariu;
    this->nrOreLucru = program.nrOreLucru;
    this->nrZile = program.nrZile;

    this->zileLucru = new string[this->nrZile];
    for (int i=0; i<this->nrZile; i++)
        this->zileLucru[i] = program.zileLucru[i];
}

ProgramLucru&ProgramLucru::operator=(const ProgramLucru&program){
    if(this!=&program){
        Angajat::operator=(program);
        this->salariu = program.salariu;
        this->nrOreLucru = program.nrOreLucru;
        this->nrZile = program.nrZile;

        if(this->zileLucru!=NULL)
            delete[] this->zileLucru;
        this->zileLucru = new string[program.nrZile];
        for (int i=0; i<program.nrZile; i++)
            this->zileLucru[i] = program.zileLucru[i];
    }
    return *this;
}

double ProgramLucru::Calculeaza_Salariu(){
    //afiseaza salariul saptamanal
    return (this->salariu*this->nrOreLucru*this->nrZile);
}

istream&ProgramLucru::Citire(istream &in){
    Angajat::Citire(in);
    //cout << "\nSalariu:";
    in >> salariu;
    //cout << "\nOre de lucru pe zi: ";
    in >> nrOreLucru;
    //cout << "\nZile de lucru pe saptamana: ";
    in >> nrZile;
    //cout << "\nZilele lucratoare (max 7): ";
    if(zileLucru!=NULL){
        delete[] zileLucru;
    }
    zileLucru = new string[nrZile];
    //cout << "introduceti zilele pe rand: \n";
    for (int i=0; i<nrZile; i++)
        in >> zileLucru[i];
    return in;
}

ostream&ProgramLucru::Afisare(ostream &out) const{
    Angajat::Afisare(out);
    out << "\nSalariu: " << salariu;
    out << "\nOre de lucur pe zi: " << nrOreLucru;
    out << "\nZilele lucratoare sunt: ";
    for (int i=0; i<nrZile; i++)
        out << this->zileLucru[i] << " ";

    return out;
}

ProgramLucru::~ProgramLucru(){
    if(this->zileLucru!=NULL)
        delete[] this->zileLucru;
}

// S-A TERMINAT CLASA ANGAJAT

class Adoptant{
private:
    string Nume;
    string Prenume;
    char * cnp;
    char * nrTel;
    string Adresa;
    int varsta;

public:
    string getNume();
    void setNume(string Nume);

    string getPrenume();
    void setPrenume(string Prenume);

    char * getCNP();
    void setCNP(char * cnp);

    int getVarsta();
    void setVarsta(int varsta);

    string getAdresa();
    void setAdresa(string Adresa);

    char * getNrTel();
    void setNrTel(char * nrTel);


    Adoptant();
    Adoptant(string Nume, string Prenume, char * cnp, string Adresa, char * nrTel, int varsta);
    Adoptant(const Adoptant & obj);
    Adoptant &operator=(const Adoptant &obj);
    friend ostream &operator<<(ostream &out, const Adoptant &obj);
    friend istream &operator>>(istream &in, Adoptant &obj);
    bool operator>(int x);
    bool operator==(int x);
    int Functie_Adoptant();
    ~Adoptant();
};
// AICI INCEPE CLASA ADOPTANT;
string Adoptant::getNume(){
    return this->Nume;
}
void Adoptant::setNume(string Nume){
    this->Nume = Nume;
}

string Adoptant::getPrenume(){
    return this->Prenume;
}
void Adoptant::setPrenume(string Prenume){
    this->Prenume = Prenume;
}

char * Adoptant::getCNP(){
    return this->cnp;
}
void Adoptant::setCNP(char * cnp){
    if (this->cnp!=NULL)
        delete[] this->cnp;
    this->cnp = new char[strlen(cnp)+1];
    strcpy(this->cnp, cnp);
}

int Adoptant::getVarsta(){
    return this->varsta;
}
void Adoptant::setVarsta(int varsta){
    this->varsta = varsta;
}

string Adoptant::getAdresa(){
    return this->Adresa;
}
void Adoptant::setAdresa(string Adresa){
    this->Adresa = Adresa;
}

char * Adoptant::getNrTel(){
    return this->nrTel;
}
void Adoptant::setNrTel(char * nrTel){
    if (this->nrTel!=NULL)
        delete[] this->nrTel;
    this->nrTel = new char[strlen(nrTel)+1];
    strcpy(this->nrTel, nrTel);
}

Adoptant::Adoptant(){
    this->Nume = "None";
    this->Prenume = "None";
    this->cnp = new char[strlen("nothing")+1];
    strcpy(this->cnp, "nothing");
    this->varsta = 0;
    this->Adresa = "None";
    this->nrTel = new char[strlen("nothing")+1];
    strcpy(this->nrTel, "nothing");
}

Adoptant::Adoptant(string Nume, string Prenume, char* cnp, string Adresa, char* nrTel, int varsta){
    this->Nume = Nume;
    this->Prenume = Prenume;

    this->cnp = new char[strlen(cnp)+1];
    strcpy(this->cnp, cnp);

    this->varsta = varsta;
    this->Adresa = Adresa;

    this->nrTel = new char[strlen(nrTel)+1];
    strcpy(this->nrTel, nrTel);
}

Adoptant::Adoptant(const Adoptant &obj){

    this->Nume = obj.Nume;
    this->Prenume = obj.Prenume;

    if (obj.cnp==NULL)
        this->cnp = NULL;
    else{
        this->cnp = new char[strlen(obj.cnp)+1];
        strcpy(this->cnp, obj.cnp);
    }
    this->varsta = obj.varsta;
    this->Adresa = obj.Adresa;
    if (obj.nrTel==NULL)
        this->nrTel = NULL;
    else{
        this->nrTel = new char[strlen(obj.nrTel)+1];
        strcpy(this->nrTel, obj.nrTel);
    }
}

Adoptant & Adoptant::operator=(const Adoptant &obj){
    if(this!=&obj){
        this->Nume = obj.Nume;
        this->Prenume = obj.Prenume;

        if (this->cnp!=NULL)
            delete[] this->cnp;
        if (obj.cnp == NULL)
            this->cnp = NULL;
        else{
            this->cnp = new char[strlen(obj.cnp)+1];
            strcpy(this->cnp, obj.cnp);
        }

        this->varsta = obj.varsta;
        this->Adresa = obj.Adresa;

        if (this->nrTel!=NULL)
            delete[] this->nrTel;
        if (obj.nrTel == NULL)
            this->nrTel = NULL;
        else{
            this->nrTel = new char[strlen(obj.nrTel)+1];
            strcpy(this->nrTel, obj.nrTel);
        }

    }

    return *this;
}

ostream &operator <<(ostream &out, const Adoptant &obj){
    out << "Numele: " << obj.Nume;
    out << "\nPrenumele: " << obj.Prenume;
    out << "\nCNP: " << obj.cnp;
    out << "\nVarsta: " << obj.varsta;
    out << "\nAdresa: " << obj.Adresa;
    out << "\nNumar telefon: " << obj.nrTel;

    return out;
}

istream &operator >>(istream &in, Adoptant &obj){
    cout << "Numele: ";
    in >> obj.Nume;
    cout << "Prenumele: ";
    in >> obj.Prenume;

    cout << "CNP-ul: ";
    char aux1[100];
    in >> aux1;
    if(obj.cnp!=NULL)
        delete[] obj.cnp;
    obj.cnp = new char[strlen(aux1)+1];
    strcpy(obj.cnp, aux1);

    cout << "Varsta dvs: ";
    in >> obj.varsta;
    cout << "Adresa dvs: ";
    in.get();
    char aux2[100];
    in.getline(aux2, 100);
    string s(aux2);
    obj.Adresa = s;

    cout << "Nr. dvs de telefon (10 cifre): ";
    char aux3[100];
    in >> aux3;
    if(obj.nrTel!=NULL)
        delete[] obj.nrTel;
    obj.nrTel = new char[strlen(aux3)+1];
    strcpy(obj.nrTel, aux3);

    return in;
}

bool Adoptant::operator>(int x){ // > pt varsta
    if (this->varsta > x)
        return true;
    return false;
}


bool Adoptant::operator==(int x){ // == verific daca numarul de telefon introdus are 10 caractere;
    if(strlen(this->nrTel)==x)
        return true;
    return false;
}

Adoptant::~Adoptant(){
    if(this->cnp!=NULL)
        delete[] this->cnp;
    if(this->nrTel!=NULL)
        delete[] this->nrTel;
}

int Adoptant::Functie_Adoptant(){ // verific daca o persoana s-a inregistrat corect pentru a adopta un animal;
    if(this->varsta < 18){
        cout << "Nu aveti varsta legala pentru a adopta un animal";
        return false;
    }
    else{
        if(strlen(this->cnp) == 13){
            int cifra2si3 = ((int)this->cnp[1]-48)*10+(int)this->cnp[2]-48; // verific daca anul din cnp e valid (cifrele de pe poz 1 si 2 indica anul nasterii)
            if (cifra2si3 <= 21)
                cifra2si3 = cifra2si3+2000;
            else
                cifra2si3 = cifra2si3+1900;
            if (this->varsta != (2021-cifra2si3)){
                cout << "Buletin invalid/Varsta nu corespunde";
                return false;
            }
        }
        else{
            cout << "CNP-ul a fost introdus incorect";
            return false;
        }
    }

    int contor=0;
    for(int i=0; i<this->Nume.size(); i++)
        if (isalpha(this->Nume[i]))
            contor++;
    if (contor != this->Nume.size()){
        cout << "Numele a fost introdus incorect";
        return false;
    }

    contor = 0;
    for(int i=0; i<this->Prenume.size(); i++)
        if (isalpha(this->Prenume[i]))
            contor++;
    if (contor != this->Prenume.size()){
        cout << "Prenumele a fost introdus incorect";
        return false;
    }
    if(strlen(this->nrTel)!=10){
        cout << "Numarul de telefon este introdus gresit";
        return false;
    }
    return true;
}

// S-A TERMINAT CLASA ADOPTANT

int main()
{
    //map si set trebuie sa stii sa compari 2 lucruri !!!
    int nrCusti = 30;

    // Cateva animale, angajati care exista deja;
    // citire fisier

    ofstream g("angajat.out");

    ifstream fin("angajat.in");

    list<Angajat*> angajat;

    angajat.push_back(new ProgramLucru);
    angajat.push_back(new ProgramLucru);
    angajat.push_back(new ProgramLucru);
    angajat.push_back(new ProgramLucru);
    for (auto x: angajat)
        fin >> *x;

    list<Angajat*>::iterator it = angajat.begin();
    fin.close();

    ifstream din("animal.in");

    set<AnimalDeCompanie *> animal;
    animal.insert(new DOG);
    animal.insert(new DOG);
    animal.insert(new DOG);
    animal.insert(new CAT);
    animal.insert(new CAT);
    animal.insert(new CAT);
    animal.insert(new CAT);

    for(auto y: animal)
        din >> *y;

    din.close();

    vector<AdapostAnimale> adapost;

    FONDURI fond;
    map<int, FONDURI> m;
    m[0] = fond;

    vector<Adoptant> adoptant;
    vector<Angajat> angajat1;

    bool k = 1;
    while(k){
        cout << "\nAngajat - 1\n";
        cout << "\nPersoana - 0\n";
        bool var;
        cin >> var;
        if(var){
            bool ccc = 1;
            while(ccc){
            cout << "Introduceti codul profesiei dvs (1-vet, 2-ingrij, 3-menaj, 4-contab) \n";
            int cod;
            cin >> cod;
                switch(cod){
                    case 1:{
                        bool var1 = 1;
                        cout << "Bun venit, " << (*angajat.begin())->getNume() << "\n";
                        while(var1){
                            cout << "Pentru a vedea toate animalele care au nevoie de ingrijiri medicale - 1\n";
                            cout << "Pentru a ingriji animalele - 2\n";
                            cout << "Pentru submeniu - s\n";
                            cout << "Pentru meniu - m\n";
                            cout << "Pentru a iesii - x\n";
                            char var2;
                            cin >> var2;
                            switch(var2){
                                case '1':{
                                    for (auto x:animal)
                                        if((*x).getSanatateAnimal() <= 3)
                                            cout << *x << "\n------------------\n";
                                break;
                                }
                                case '2':{
                                    for (auto x: animal){
                                        int sec = rand() % 10+1; // facut pentru a avea sens, daca numarul > 5 operatia a reusit si sanatatea creste
                                        if (sec > 5)               // altfel sanatatea descreste, ma rog eu am pus 1 pentru v goo 4 pt v bad
                                            (*x)--;                 // deci daca vreau sa cresc sanatatea trebuie sa scad :))
                                        else
                                            (*x)++;
                                    }
                                break;
                                }
                                case 's':{
                                    var1 = 0;
                                break;
                                }
                                case 'm':{
                                    var1 = 0;
                                    ccc = 0;
                                break;
                                }
                                case 'x':{
                                    var1 = 0;
                                    ccc = 0;
                                    k = 0;
                                }
                            }
                        }
                    break;
                    }
                    case 2:{
                        bool var1 = 1;
                        cout << "Bun venit, " << (*++angajat.begin())->getNume() << "\n";
                        while(var1){
                            cout << "Pentru a face cumparaturi - 1 \n";
                            cout << "Pentru a vedea istoricul cumparaturilor - 2\n";
                            cout << "Pentru submeniu - s\n";
                            cout << "Pentru meniu - m\n";
                            cout << "Pentru a iesii - x\n";
                            char var2;
                            cin >> var2;
                            switch(var2){
                                case '1':{
                                    AdapostAnimale var;
                                    var.Citire();
                                    var.Functionalitate_Adapost();
                                    adapost.push_back(var);
                                    cout << "\n";
                                break;
                                }
                                case '2':{
                                    try{
                                        if(adapost.begin() != adapost.end())
                                            for(int i=0; i<adapost.size(); i++){
                                                for (int j=0; j <adapost[i].getNrObiecteCumparate(); j++)
                                                    cout << "Produs: " << *(adapost[i].getNumeProdus()+j) << " Pret: " << *(adapost[i].getConsumIntroZi()+j) << "\n";
                                                cout << "\n";
                                            }
                                        else
                                            throw "nu";
                                    }
                                    catch(...){
                                        cout << "Ne pare rau nu putem afisa momenta istoricul cumparaturilor\n";
                                    }
                                    cout << "\n";
                                break;
                                }
                                case 's':{
                                    var1 = 0;
                                break;
                                }
                                case 'm':{
                                    var1 = 0;
                                    ccc = 0;
                                break;
                                }
                                case 'x':{
                                    var1 = 0;
                                    ccc = 0;
                                    k = 0;
                                }
                            }
                        }
                    break;
                    }
                    case 3:{
                        bool var1 = 1;
                        cout << "Bun venit, " << (*--(--angajat.end()))->getNume() << "\n";
                        while(var1){
                            cout << "Pentru a vedea ce cusca trebuie curatata - 1\n";
                            cout << "Pentru submeniu - s\n";
                            cout << "Pentru meniu - m\n";
                            cout << "Pentru a iesii - x\n";
                            char var2;
                            cin >> var2;
                            switch(var2){
                                case '1':{
                                    int random = rand() % 50 + 1;
                                    cout << "Trebuie curatata cusca cu numarul " << random;
                                    cout << "\n";
                                break;
                                }
                                case 's':{
                                    var1 = 0;
                                break;
                                }
                                case 'm':{
                                    var1 = 0;
                                    ccc = 0;
                                break;
                                }
                                case 'x':{
                                    var1 = 0;
                                    ccc = 0;
                                    k = 0;
                                }
                            }
                        }
                    break;
                    }
                    case 4:{
                        bool var1 = 1;
                        (*++it);
                        (*++it);
                        cout << "Bun venit, " << (*--angajat.end())->getNume() << "\n";
                        while(var1){
                            cout << "Pentru a vedea fondurile - 1\n";
                            cout << "Pentru a vedea donatorii - 2\n";
                            cout << "Top donator - 3\n";
                            cout << "Pentru submeniu - s\n";
                            cout << "Pentru meniu - m\n";
                            cout << "Pentru a iesii - x\n";
                            char var2;
                            cin >> var2;
                            switch(var2){
                                case '1':{
                                    cout << m[0].get_fonduri() << "\n";
                                break;
                                }
                                case '2':{
                                    m[0].Donatori();
                                    cout << "\n";
                                break;
                                }
                                case '3':{
                                    try{
                                        m[0].Fonduri_func();
                                    }
                                    catch (...){
                                        cout << "\nNe pare rau nu putem calcula momentan clasamentul donatorilor";
                                    }
                                    cout << "\n";
                                break;
                                }
                                case 's':{
                                    var1 = 0;
                                break;
                                }
                                case 'm':{
                                    var1 = 0;
                                    ccc = 0;
                                break;
                                }
                                case 'x':{
                                    var1 = 0;
                                    ccc = 0;
                                    k = 0;
                                }
                            }
                        }
                    break;
                    }
                }
            }
        }
        else{
            bool var3 = 1;
            while(var3){
                cout << "Bun venit!\n";
                cout << "Pentru a face o donatie - 1\n";
                cout << "Pentru a depune o cerere de adoptie - 2 \n";
                cout << "Pentru a depune o cerere de angajare - 3\n";
                cout << "Pentru a oferi spre adoptie un animal - 4\n";
                cout << "Pentru meniu - m\n";
                cout << "Pentru a iesii - x\n";
                char var;
                cin >> var;
                switch(var){
                    case '1':{
                        DONATII obj;
                        cin >> obj;
                        m[0] = m[0] + obj;
                        m[0].Asociatie();
                        cout << "\n";
                    break;
                    }
                    case '2':{
                        Adoptant obj;
                        cin >> obj;
                        if(obj.Functie_Adoptant()){
                            cout << "Cererea a fost trimisa, va multumim!";
                            int var = rand() % 10 +1;
                            if(var > 5){
                                cout << "Felicitari, puteti adopta un animalut!";
                                adoptant.push_back(obj);
                            }
                            else
                                cout << "Ne pare rau, nu puteti adopta un animalut!";
                        }
                        cout << "\n";
                    break;
                    }
                    case '3':{
                        Angajat obj;
                        cin >> obj;
                        if(obj.Functionalitate_Angajat()){
                            cout << "Cererea a fost trimisa, va multumim!";
                            g << obj;
                        }
                        cout << "\n";
                    break;
                    }
                    case '4':{
                        cout << "Ce animalut aveti 1-caine, 0-pisica";
                        int var;
                        cin >> var;
                        if(var){
                            AnimalDeCompanie * loc = new DOG();
                            cin >> *loc;
                            animal.insert(loc);
                        }
                        else{
                            AnimalDeCompanie * boc = new CAT();
                            cin >> *boc;
                            animal.insert(boc);
                        }

                    break;
                    }
                    case 'm':{
                        var3 = 0;
                    break;
                    }
                    case 'x':{
                        var3 = 0;
                        k = 0;
                    }
                }
            }
        }
    }

    g.close();

    angajat.clear();
    animal.clear();
    adapost.clear();
    adoptant.clear();
    angajat1.clear();

    m.erase(0);

    return 0;
}
