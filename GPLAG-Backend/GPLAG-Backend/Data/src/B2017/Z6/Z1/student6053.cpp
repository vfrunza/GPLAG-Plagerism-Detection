/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>
using namespace std;
class Spremnik {
    double kg;
    string naziv;
    protected:
    Spremnik(double kg,string n):kg(kg),naziv(n){}
    string DajNaziv()const{return naziv;}
    public:
    double DajTezinu()const{return kg;}
    virtual double DajUkupnuTezinu()const=0;
    virtual void Ispisi()const=0;
    virtual shared_ptr<Spremnik> DajKopiju()const=0;
    virtual ~Spremnik(){}
};
class Skladiste {
    vector<shared_ptr<Spremnik>> v;
    void A(){throw logic_error("Datoteka sadrzi besmislene podatke");}
    public:
    Skladiste(){}
    Skladiste(const Skladiste &a);
    Skladiste(Skladiste &&a);
    Skladiste &operator=(const Skladiste &a);
    Skladiste &operator=(Skladiste &&a);
    Spremnik* DodajSanduk(double tezina,string s,vector<double> vekt);
    Spremnik* DodajVrecu(double tezina,string s,double prasak);
    Spremnik* DodajBure(double tezina,string s,double gustina,double zapremina);
    Spremnik* DodajSpremnik(Spremnik* p,bool moj);
    void BrisiSpremnik(Spremnik *p);
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    int BrojPreteskih(int x)const;
    void IzlistajSkladiste()const;
    void UcitajIzDatoteke(string s);
};
void Skladiste::UcitajIzDatoteke(string s){
    ifstream ulaz(s);
    if(!ulaz) throw logic_error("Trazena datoteka ne postoji");
    for(;;){
        char slovo;
        ulaz >> slovo;
        string ime;
        if(slovo == 'S'){
            double tezina;
            int broj;
            getline(ulaz,ime);
            if(!ime.empty() and ime[0] != ' ')
                A();
            ime.erase(0,1);
            ulaz >> tezina >> broj;
            vector<double> v(broj);
            for(int i=0;i<v.size();i++)
                ulaz >> v[i];
            ulaz.ignore(1000,'\n');
            if(!ulaz) break;
            DodajSanduk(tezina,ime,v);
        }
        else if(slovo == 'V'){
            double vreca,materija;
            getline(ulaz,ime);
            if(!ime.empty() and ime[0] != ' ')
                A();
            ime.erase(0,1);
            ulaz >> vreca >> materija;
            if(!ulaz) break;
            ulaz.ignore(1000,'\n');
            DodajVrecu(vreca,ime,materija);
        }
        else if(slovo == 'B'){
            double tezina,gustina,zapremina;
            getline(ulaz,ime);
            if(!ime.empty() and ime[0] != ' ')
                A();
            ime.erase(0,1);
            ulaz >> tezina >> gustina >> zapremina;
            if(!ulaz) break;
            ulaz.ignore(1000,'\n');
            DodajBure(tezina,ime,gustina,zapremina);
        }
        else
            break;
    }
    ulaz >> ws;
    if(ulaz.bad())
        throw logic_error("Problemi pri citanju datoteke");
    else if(!ulaz.eof())
        A();
}
void Skladiste::IzlistajSkladiste()const{
    auto pomoc=v;
    sort(pomoc.begin(),pomoc.end(),[](shared_ptr<Spremnik> p1,shared_ptr<Spremnik> p2){
        return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();
    });
    for(auto b:pomoc)
        if(b)
            b->Ispisi();
}
int Skladiste::BrojPreteskih(int x)const{
    int br=0;
    for(auto b:v)
        if(b->DajUkupnuTezinu()>x)
            br++;
    return br;
}
Spremnik &Skladiste::DajNajlaksi(){
    if(v.empty())
        throw range_error("Skladiste je prazno");
    return **min_element(v.begin(),v.end(),[](shared_ptr<Spremnik> p1,shared_ptr<Spremnik> p2){
        return p1->DajTezinu()<p2->DajTezinu();
    });
}
Spremnik &Skladiste::DajNajtezi(){
    if(v.empty())
        throw range_error("Skladiste je prazno");
    return **max_element(v.begin(),v.end(),[](shared_ptr<Spremnik> p1,shared_ptr<Spremnik> p2){
        return p1->DajTezinu()<p2->DajTezinu();
    });
}
void Skladiste::BrisiSpremnik(Spremnik *p){
    for(auto it=v.begin();it!=v.end();it++)
        if((*it).get() == p){
            *it = nullptr;
            v.erase(it);
            break;
        }
}
Spremnik* Skladiste::DodajSpremnik(Spremnik* p,bool moj){
    if(moj){
        v.push_back(shared_ptr<Spremnik>(p));
        return p;
    }
    auto a = p->DajKopiju();
    v.push_back(a);
    return a.get();
}
Skladiste::Skladiste(const Skladiste &a){
    for(int i=0;i<a.v.size();i++)
        v.push_back(a.v[i]->DajKopiju());
}
Skladiste &Skladiste::operator =(Skladiste &&a){
    if(this == &a)return *this;
    for(auto b:v)
        b = nullptr;
    v = a.v;
    for(auto b:a.v)
        b = nullptr;
    a.v.clear();
    return *this;
}
Skladiste &Skladiste::operator=(const Skladiste &a){
    if(this == &a)return *this;
    for(auto b:v)
        b = nullptr;
    for(int i=0;i<a.v.size();i++)
        v.push_back(a.v[i]->DajKopiju());
    return *this;
}
Skladiste::Skladiste(Skladiste &&a){
    v=a.v;
    for(auto b:a.v)
        b = nullptr;
    a.v.clear();
}
class Sanduk : public Spremnik {
    vector<double> v;
    public:
    shared_ptr<Spremnik> DajKopiju()const override{return make_shared<Sanduk>(*this);}
    Sanduk(double tezina,string s,vector<double> vekt):Spremnik(tezina,s),v(vekt){}
    void Ispisi()const override;
    double DajUkupnuTezinu()const override;
    ~Sanduk()override{}
};
class Vreca : public Spremnik {
    double prasak;
    public:
    shared_ptr<Spremnik> DajKopiju()const override{return make_shared<Vreca>(*this);}
    Vreca(double tezina,string s,double prasak):Spremnik(tezina,s),prasak(prasak){}
    void Ispisi()const override;
    double DajUkupnuTezinu()const override;
    ~Vreca()override{}
};
class Bure : public Spremnik {
    double gustina,zapremina;
    public:
    shared_ptr<Spremnik> DajKopiju()const override{return make_shared<Bure>(*this);}
    Bure(double tezina,string s,double gustina,double zapremina):Spremnik(tezina,s),gustina(gustina),zapremina(zapremina){}
    void Ispisi()const override;
    double DajUkupnuTezinu()const override;
    ~Bure()override{}
};
Spremnik* Skladiste::DodajSanduk(double tezina,string s,vector<double> vekt){
    auto a = make_shared<Sanduk>(tezina,s,vekt);
    v.push_back(a);
    return a.get();
}
Spremnik* Skladiste::DodajVrecu(double tezina,string s,double prasak){
    auto a = make_shared<Vreca>(tezina,s,prasak);
    v.push_back(a);
    return a.get();
}
Spremnik* Skladiste::DodajBure(double tezina,string s,double gustina,double zapremina){
    auto a = make_shared<Bure>(tezina,s,gustina,zapremina);
    v.push_back(a);
    return a.get();
}
void Bure::Ispisi()const{
    cout<<"Vrsta spremnika: Bure\n";
    cout<<"Sadrzaj: "<<DajNaziv()<<"\n";
    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)\n";
    cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)\n";
    cout<<"Zapremina tecnosti: "<<zapremina<<" (l)\n";
    cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
}
double Bure::DajUkupnuTezinu()const{
    return (zapremina/1000)*gustina+DajTezinu();
}
void Vreca::Ispisi()const{
    cout<<"Vrsta spremnika: Vreca\n";
    cout<<"Sadrzaj: "<<DajNaziv()<<"\n";
    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)\n";
    cout<<"Tezina pohranjene materije: "<<prasak<<" (kg)\n";
    cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
}
double Vreca::DajUkupnuTezinu()const{
    return DajTezinu()+prasak;
}
double Sanduk::DajUkupnuTezinu()const{
    double suma(0);
    for(auto a:v)
        suma+=a;
    return suma+DajTezinu();
}
void Sanduk::Ispisi()const{
    cout<<"Vrsta spremnika: Sanduk\n";
    cout<<"Sadrzaj: "<<DajNaziv()<<"\n";
    cout<<"Tezine predmeta: ";
    for(auto a:v)
    cout<<a<<" ";
    cout<<"(kg)\n";
    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)\n";
    cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
}
int main (){
    try{
    ofstream izlaz("TEST.TXT");
    izlaz << "S Tepsije\n9 5 2 3 1 2 2 4 3 1 3\n";
    izlaz << "V Brasno\n0.9 100\n";
    izlaz << "B Suncokretovo ulje\n5 1300 150";
    izlaz.flush();
    izlaz.close();
    Skladiste magacin;
    magacin.UcitajIzDatoteke("TEST.TXT");
    magacin.IzlistajSkladiste();
}
catch(logic_error e){
    cout << e.what();
}
	return 0;
}