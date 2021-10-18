/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <memory>
using namespace std;

bool teststringavreca(string s)
{
    int brr=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ') brr++;
        else if(s[i]!='.')
            {
                //cout<<s[i]<<endl;
                if(s[i]<'0' || s[i]>'9') return false;
            }
    }
    return brr==1;
}
bool teststringabure(string s)
{
    int brr=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ') brr++;
        else if(s[i]!='.')
            {
                //cout<<s[i]<<endl;
                if(s[i]<'0' || s[i]>'9') return false;
            }
    }
    return brr==2;
}
bool teststringasanduk(string s)
{
    int brr=0;
    //cout<<s<<endl;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ') brr++;
        else if(s[i]!='.')
            {
             //   cout<<s[i]<<endl;
                if(s[i]<'0' || s[i]>'9') return false;
            }
    }
    return true;
}

class Spremnik{
protected: 
    double tezina; 
    string naziv;
public:
    virtual ~Spremnik(){}
    double DajTezinu() const { return tezina;}
    string DajNaziv() const { return naziv;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const =0;
    virtual shared_ptr<Spremnik> DajKopiju()  = 0;
    virtual shared_ptr<Spremnik> DajIsti()  = 0;
    //virtual shared_ptr<Spremnik> DajKopiju()  = 0;
    //virtual shared_ptr<Spremnik> DajIsti()  = 0;
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
    //shared_ptr<Spremnik> DajKopiju()  override { return make_shared<Sanduk>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Sanduk"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl;
        cout<<"Tezine predmeta: "; for(int i=0; i<tezine.size(); i++) cout<<tezine[i]<<" ";
        cout<<"(kg)"<<endl;
        cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        double suma=0;
        for(int i=0; i<tezine.size(); i++) suma+=tezine[i];
        return  suma+tezina;
    }
    shared_ptr<Spremnik> DajIsti() override{
        shared_ptr<Sanduk>rez (this);
        return rez;
    }
    
};

class Bure: public Spremnik
{
   double gustina, zapremina;
public:
    Bure(double t, string naz, double g, double z)
    {
        tezina=t; naziv=naz;  gustina=g; zapremina=z;
    }
    shared_ptr<Spremnik> DajKopiju()  override { return make_shared<Bure>(*this);}
    //shared_ptr<Spremnik> DajKopiju() override { return make_shared<Bure>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Bure"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl;
        cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Specificna tezina tecnosti: "<<gustina<<" (kg/m^3)"<<endl;
        cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        return ((zapremina*gustina)/1000)+tezina;
    }
    shared_ptr<Spremnik> DajIsti() override {
        shared_ptr<Bure>rez(this);
        return rez;
    }

};

class Vreca: public Spremnik
{
    double materija;
public:
    Vreca(double t, string naz, double g)
    {
        tezina=t; naziv=naz;  materija=g; 
    }
    shared_ptr<Spremnik> DajKopiju() override{ return make_shared<Vreca>(*this);}
    //shared_ptr<Spremnik> DajKopiju()  override{ return make_shared<Vreca>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Vreca"<<endl;
        cout<<"Sadrzaj: "<<naziv<<endl;
        cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
        cout<<"Tezina pohranjene materije: "<<materija<<" (kg)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    double DajUkupnuTezinu() const { 
        return materija+tezina;
    }
    shared_ptr<Spremnik> DajIsti() override{
        shared_ptr<Vreca>rez(this);
        return rez;
    }
    
};

class Skladiste
{
    vector<shared_ptr<Spremnik>> v;
public:
    Skladiste() {}
    ~Skladiste(){
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
    }
    Spremnik *DodajSanduk(double t, string naz, vector<double> tez){
        v.push_back(make_shared<Sanduk>(t,naz,tez));
        return v[v.size()-1].get();
    }
    Spremnik *DodajVrecu(double t, string naz, double g){
        v.push_back(make_shared<Vreca>(t,naz,g));
        return v[v.size()-1].get();
    }
    Spremnik *DodajBure(double t, string naz, double tez, double z){
        v.push_back(make_shared<Bure>(t,naz,tez,z));
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
    void BrisiSpremnik(Spremnik *p)
    {
        int ind=-1;
        for(int i=0; i<v.size(); i++)
            if(v[i].get()==p) ind=i;
        if(ind!=-1){
            for(int i=ind; i<v.size()-1; i++)
            {
                auto temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
            }
            v[v.size()-1]=nullptr;
            v.resize(v.size()-1);
         }
    }
    Spremnik& DajNajlaksi() 
    {
        if(v.size()==0) throw range_error("Skladiste je prazno");
        double min=999999999; int ind=-1;
        for(int i=0; i<v.size(); i++){
            if(v[i]->DajTezinu()<min) 
            {
                min=v[i]->DajTezinu(); ind=i;
                
            }
        }
        return *v[ind];
    }
    Spremnik& DajNajtezi() 
    {
        if(v.size()==0) throw range_error("Skladiste je prazno");
        double min=0; int ind=-1;
        for(int i=0; i<v.size(); i++){
            if(v[i]->DajTezinu()>min) 
            {
                min=v[i]->DajTezinu(); ind=i;
                
            }
        }
        return *v[ind];
    }
    int BrojPreteskih(int t)
    {
        int br=0;
        for(int i=0; i<v.size(); i++) if(v[i]->DajUkupnuTezinu()>t) br++;
        return br;
    }
    int BrojPreteskih(int t) const
    {
        int br=0;
        for(int i=0; i<v.size(); i++) if(v[i]->DajUkupnuTezinu()>t) br++;
        return br;
    }
    Skladiste(Skladiste &s)
    {
        for(int i=0; i<s.v.size(); i++) v.push_back(s.v[i]->DajKopiju());
    }
    Skladiste &operator = (Skladiste &n)
    {
        if(&n==this) return *this;
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
        v.resize(0);
        for(int i=0; i<n.v.size(); i++) v.push_back(n.v[i]->DajKopiju());
        return *this;
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
        vector<shared_ptr<Spremnik>>pom(v.size());
        for(int i=0; i<v.size(); i++) pom[i]=v[i];
        
        sort(pom.begin(), pom.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();});
        
        for(int i=0; i<pom.size(); i++) pom[i]->Ispisi();
        
        for(int i=0; i<pom.size(); i++) pom[i]=nullptr;
    }
    void UcitajIzDatoteke(string dat)
    {
        //dat+=".txt";
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
        v.resize(0);
        ifstream ulaz(dat);
        if(!ulaz) throw logic_error("Trazena datoteka ne postoji");
        while(1)
        {
            string tip;
            if(!getline(ulaz,tip)) break;
            //cout<<tip<<endl;
            if(tip.size()<3) throw logic_error("Datoteka sadrzi besmislene podatke");
            if(tip[1]!=' ') throw logic_error("Datoteka sadrzi besmislene podatke");
            if(tip[0]=='B')
            {
                string naziv=tip.substr(2,tip.size());
                string pom; 
                getline(ulaz,pom);
                if(teststringabure(pom)==false) throw logic_error("Datoteka sadrzi besmislene podatke");
                //cout<<pom<<endl;
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
                //cout<<pom<<endl;
                if(teststringasanduk(pom)==false) throw logic_error("Datoteka sadrzi besmislene podatke");
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
                double znj=tezine[0];
                if((tezine.size()-1)!=znj) throw logic_error("Datoteka sadrzi besmislene podatke");
                for(int i=0; i<tezine.size()-1; i++) tezine[i]=tezine[i+1];
                tezine.resize(tezine.size()-1);
                v.push_back(make_shared<Sanduk>(tez,naziv,tezine));
            }
            else if(tip[0]=='V')
            {
                string naziv=tip.substr(2,tip.size());
                string pom; 
                getline(ulaz,pom);
                if(teststringavreca(pom)==false) throw logic_error("Datoteka sadrzi besmislene podatke");
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
};

int main ()
{
   
    try{
        
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }   
    catch(logic_error l) { cout<<l.what();}
    catch(range_error l) { cout<<l.what();} 
    /*
        cout<<"Dodjela: "<<endl;
        Skladiste s1=s;
        s1.IzlistajSkladiste();
        cout<<endl;
        cout<<"Kopija: "<<endl;
        Skladiste s2(s);
        s2.IzlistajSkladiste();
        
        cout<<endl<<"Dodavanje objekata:"<<endl;
        s.DodajSanduk(50, "Armatura", {1,3,5,6});
        s.DodajVrecu(0.1, "Jabuke", 25.5);
        s.DodajBure(5, "Barut", 1300, 150);
        s.DodajSpremnik(new Vreca(0.5, "Pijesak", 40), true);
        Bure *b = new Bure(15, "Ulje", 1000, 200);
        s.DodajSpremnik(b, false);
        delete b;
        s.IzlistajSkladiste();
        
        cout<<endl<<"Najlaksi i najtezi: "<<endl;
        s.DajNajlaksi().Ispisi(); s.DajNajtezi().Ispisi();
        
        cout<<endl<<"Broj preteskih u odnosu na 50 kg: "<<s.BrojPreteskih(50);
        
    }   
    catch(logic_error l) { cout<<l.what();}
    catch(range_error l) { cout<<l.what();} */
   
	return 0;
}
