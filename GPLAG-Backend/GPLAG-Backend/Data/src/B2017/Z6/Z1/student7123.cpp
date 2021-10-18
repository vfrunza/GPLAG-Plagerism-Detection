/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <cstring>
#include <iomanip>
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdexcept>
using namespace std;

bool valja(string s, char a);


class Spremnik{
protected: 
    double tezina; 
    string naziv;
public:
    virtual void Ispisi() const =0;
    virtual ~Spremnik(){}
    virtual shared_ptr<Spremnik> DajKopiju()  = 0;
    double DajTezinu() const { return tezina;}
    virtual shared_ptr<Spremnik> DajIsti()  = 0;
    string DajNaziv() const { return naziv;}
    virtual double DajUkupnuTezinu() const=0;
};


class Bure: public Spremnik
{
   double gustina, zapremina;
public:

    void Ispisi() const {
        cout<<"Vrsta spremnika: Bure"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<endl<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    Bure(double t, string naz, double g, double z)
    {
        tezina=t; naziv=naz;  gustina=g; zapremina=z;
    }
    shared_ptr<Spremnik> DajKopiju()  override { return make_shared<Bure>(*this);}
    double DajUkupnuTezinu() const { 
        return ((zapremina*gustina)/1000)+tezina;
    }
    shared_ptr<Spremnik> DajIsti() override {
        return shared_ptr<Bure>(this);
    }

};

class Vreca: public Spremnik
{
    double materija;
public:
    double DajUkupnuTezinu() const { 
        return materija+tezina;
    }
    Vreca(double t, string naz, double g)
    {
        tezina=t; naziv=naz;  materija=g; 
    }
    shared_ptr<Spremnik> DajKopiju() override{ return make_shared<Vreca>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Vreca"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Tezina pohranjene materije: "<<materija<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    shared_ptr<Spremnik> DajIsti() override{
        return shared_ptr<Vreca>(this);
    }
    
};

class Sanduk: public Spremnik
{
  vector<double> tezine;
public:
    
    Sanduk(double t, string naz, vector<double> v)
    {
        tezina=t; naziv=naz;  tezine=v;
    }
    shared_ptr<Spremnik> DajKopiju() override { return make_shared<Sanduk>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Sanduk"<<endl<<"Sadrzaj: "<<naziv<<endl<<"Tezine predmeta: "; 
        for(int i=0; i<tezine.size(); i++) cout<<tezine[i]<<" ";
        cout<<"(kg)"<<endl<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        double suma=0;
        for(int i=0; i<tezine.size(); i++) suma+=tezine[i];
        return  suma+tezina;
    }
    shared_ptr<Spremnik> DajIsti() override{
        return shared_ptr<Sanduk>(this);
    }
    
};

class Skladiste
{
    vector<shared_ptr<Spremnik>> v;
public:
    Skladiste() {}
     Spremnik *DodajBure(double t, string naz, double tez, double z){
        v.push_back(make_shared<Bure>(t,naz,tez,z));
        return v[v.size()-1].get();
    }
    ~Skladiste(){
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
    }
    Spremnik *DodajVrecu(double t, string naz, double g){
        v.push_back(make_shared<Vreca>(t,naz,g));
        return v[v.size()-1].get();
    }
    Spremnik *DodajSanduk(double t, string naz, vector<double> tez){
        v.push_back(make_shared<Sanduk>(t,naz,tez));
        return v[v.size()-1].get();
    }
    Spremnik *DodajSpremnik(Spremnik *p, bool a) 
    {
        if(a) {
            v.push_back(p->DajIsti()); 
        }
        else v.push_back(p->DajKopiju());
        return v[v.size()-1].get();
    }
     Skladiste(Skladiste &s)
    {
        for(int i=0; i<s.v.size(); i++) v.push_back(s.v[i]->DajKopiju());
    }
    void BrisiSpremnik(Spremnik *p)
    {
        int ind=-1;
        auto it=find_if(v.begin(), v.end(), [p](shared_ptr<Spremnik> pok){return pok.get()==p;});
        if(it==v.end()) return;
        for(int i=0; i<v.size(); i++)
            if(v[i]==*it) ind=i;
            for(int i=ind; i<v.size()-1; i++)
            {
                auto temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
            }
            v[v.size()-1]=nullptr;
            v.resize(v.size()-1);
    }
    Spremnik& DajNajlaksi() 
    {
        if(v.size()==0) throw range_error("Skladiste je prazno");
        return *min_element(v.begin(), v.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){return p1->DajTezinu()<p2->DajTezinu();})->get();
    }
    Spremnik& DajNajtezi() 
    {
        if(v.size()==0) throw range_error("Skladiste je prazno");
        return *min_element(v.begin(), v.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){return p1->DajTezinu()>p2->DajTezinu();})->get();
    }
    int BrojPreteskih(int br)
    {
        return count_if(v.begin(),v.end(), [br](shared_ptr<Spremnik> p){return p->DajUkupnuTezinu()>br;});
    }
    void UcitajIzDatoteke(string dat)
    {
       
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
        v.resize(0);
        ifstream ulaz(dat);
        if(!ulaz) throw logic_error("Trazena datoteka ne postoji");
        while(1)
        {
            string tip;
            if(!getline(ulaz,tip)) break;
            if(tip.size()<3) throw logic_error("Datoteka sadrzi besmislene podatke");
            if(tip[1]!=' ') throw logic_error("Datoteka sadrzi besmislene podatke");
            if(tip[0]=='B')
            {
                string naziv=tip.substr(2,tip.size());
                string pom; 
                getline(ulaz,pom);
                if(valja(pom,'B')==false) throw logic_error("Datoteka sadrzi besmislene podatke");
         
                string tezina,gustina,zapremina;
                int i=0;
                while(pom[i]!=' ') { tezina+=pom[i]; i++;}
                i++;
                while(pom[i]!=' ') { gustina+=pom[i]; i++;}
                i++;
                while(i!=pom.size()) { zapremina+=pom[i]; i++;}
                double tez=stod(tezina), gus=stod(gustina), zap=stod(zapremina);
                v.push_back(make_shared<Bure>(tez,naziv,gus,zap));
            }
            else if(tip[0]=='S')
            {
                string naziv=tip.substr(2,tip.size());
                string pom; getline(ulaz,pom);
    
                if(valja(pom,'S')==false) throw logic_error("Datoteka sadrzi besmislene podatke");
                string tezina;
                int i=0;
                while(pom[i]!=' ') { tezina+=pom[i]; i++;}
                i++;
                pom=pom.substr(i, pom.size());
                
                vector<double> tezine; vector<string> tpom;
                i=0;
                while(1){
                    if(i==pom.size()+1) break;
                    string clan;
                    while(i!=pom.size() && pom[i]!=' ') {clan.push_back(pom[i]); i++;}
                    tpom.push_back(clan);
                    i++;
                }
                
                double tez=stod(tezina); 
                for(int i=0; i<tpom.size(); i++) tezine.push_back(stod(tpom[i]));
                v.push_back(make_shared<Sanduk>(tez,naziv,tezine));
            }
            else if(tip[0]=='V')
            {
                string naziv=tip.substr(2,tip.size());
                string pom; 
                getline(ulaz,pom);
                if(valja(pom,'V')==false) throw logic_error("Datoteka sadrzi besmislene podatke");
                string tezina,zapremina;
                int i=0;
                while(pom[i]!=' ') { tezina+=pom[i]; i++;}
                i++;
                while(i!=pom.size()) { zapremina+=pom[i]; i++;}
                double tez=stod(tezina), zap=stod(zapremina);
                v.push_back(make_shared<Vreca>(tez,naziv,zap));
            }
            else throw logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(ulaz.eof()) return;
        if(ulaz.bad()) std::cout << "Problemi pri citanju datoteke";
        else std::cout << "Datoteka sadrži besmislene podatke";

    }
    int BrojPreteskih(int t) const
    {
        return count_if(v.begin(),v.end(), [t](shared_ptr<Spremnik> p){return p->DajUkupnuTezinu()>t;});
    }
 
    Skladiste(Skladiste &&n)
    {
        v=n.v; n.v.resize(0);
    }
    Skladiste &operator =(Skladiste &&n)
    {
        if(&n==this) return *this;
        for(int i=0; i<v.size(); i++)  v[i]=nullptr;
        v.resize(0);
        v=n.v; n.v.resize(0);
        return *this;
    }
    void IzlistajSkladiste()
    {
        sort(v.begin(), v.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();});
        for(int i=0; i<v.size(); i++) v[i]->Ispisi();
    }
    Skladiste &operator = (Skladiste &n)
    {
        if(&n==this) return *this;
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
        v.resize(0);
        for(int i=0; i<n.v.size(); i++) v.push_back(n.v[i]->DajKopiju());
        return *this;
    }
};

bool valja(string s, char a)
{
    int brr=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ') brr++;
        else if(s[i]!='.')
            {
                if(s[i]<'0' || s[i]>'9') return false;
            }
    }
    if(a=='V') return brr==1;
    if(a=='B') return brr==2;
    return true;
}

int main ()
{
   
    try{
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }   
    catch(logic_error izuz) { cout<<izuz.what();}
    catch(range_error izuz) { cout<<izuz.what();} 
  
   
	return 0;
}
