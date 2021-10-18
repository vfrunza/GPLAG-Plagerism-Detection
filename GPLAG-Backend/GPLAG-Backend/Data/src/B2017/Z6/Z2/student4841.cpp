/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <cstring>
#include <iomanip>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <fstream>
using namespace std;

class Spremnik{
protected: 
    double weight; 
    string n;
public:
    virtual ~Spremnik(){}
    virtual shared_ptr<Spremnik> DajKopiju()  const= 0;
    virtual shared_ptr<Spremnik> DajPlitkuKopiju()  = 0;
    double DajTezinu() const { return weight;}
    string DajNaziv() const { return n;}
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const =0;
};

class Sanduk: public Spremnik
{
  vector<double> weights;
public:
    double DajUkupnuTezinu() const { 
        double suma=0;
        for(int i=0; i<weights.size(); i++) suma+=weights[i];
        return  suma+weight;
    }
    Sanduk(double t, string naz, vector<double> v)
    {
        weight=t; 
        n=naz;  
        weights=v;
    }
    shared_ptr<Spremnik> DajPlitkuKopiju() override{
        shared_ptr<Sanduk>rez (this);
        return rez;
    }
    shared_ptr<Spremnik> DajKopiju() const override { return make_shared<Sanduk>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Sanduk"<<endl<<"Sadrzaj: "<<n<<endl<<"Tezine predmeta: "; for(int i=0; i<weights.size(); i++) cout<<weights[i]<<" ";
        cout<<"(kg)"<<endl<<"Vlastita tezina: "<<weight<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
};

class Vreca: public Spremnik
{
    double materija;
public:
    double DajUkupnuTezinu() const { 
        return materija+weight;
    }
    Vreca(double t, string naz, double g)
    {
        weight=t; 
        n=naz;  
        materija=g; 
    }
    shared_ptr<Spremnik> DajPlitkuKopiju() override{
        shared_ptr<Vreca>rez(this);
        return rez;
    }
    shared_ptr<Spremnik> DajKopiju() const override{ return make_shared<Vreca>(*this);}
    void Ispisi() const {
        cout<<"Vrsta spremnika: Vreca"<<endl<<"Sadrzaj: "<<n<<endl<<"Vlastita tezina: "<<weight<<" (kg)"<<endl;
        cout<<"Tezina pohranjene materije: "<<materija<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
};

class Bure: public Spremnik
{
   double thickness, volume;
public:
    shared_ptr<Spremnik> DajKopiju() const override { return make_shared<Bure>(*this);}
    Bure(double t, string naz, double g, double z)
    {
        weight=t; n=naz;  thickness=g; volume=z;
    }
    double DajUkupnuTezinu() const { 
        return weight+((volume*thickness)/1000);
    }
    void Ispisi() const {
        cout<<"Vrsta spremnika: Bure"<<endl<<"Sadrzaj: "<<n<<endl<<"Vlastita tezina: "<<weight<<" (kg)"<<endl;
        cout<<"Specificna tezina tecnosti: "<<thickness<<" (kg/m^3)"<<endl<<"Zapremina tecnosti: "<<volume<<" (l)"<<endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    shared_ptr<Spremnik> DajPlitkuKopiju() override {
        shared_ptr<Bure>rez(this);
        return rez;
    }

};

class PolimorfniSpremnik {
 shared_ptr<Spremnik> p_lik;
 void Test() const {
 if(!p_lik) throw std::logic_error("Nespecificiran spremnik");
 }
public:
     PolimorfniSpremnik() : p_lik(nullptr) {}
     ~PolimorfniSpremnik() { p_lik=nullptr; }
     PolimorfniSpremnik(const Spremnik &lik)  {
         p_lik=lik.DajKopiju();
     }
     PolimorfniSpremnik(PolimorfniSpremnik &lik) {
         if(!lik.p_lik) p_lik = nullptr;
         else p_lik = lik.p_lik->DajKopiju();
     }
     PolimorfniSpremnik(PolimorfniSpremnik &&lik) {
         p_lik = lik.p_lik; lik.p_lik = nullptr;
     }
     PolimorfniSpremnik &operator =(PolimorfniSpremnik &lik) {
         shared_ptr<Spremnik>p_novi(nullptr);
         if(lik.p_lik != nullptr) p_novi = lik.p_lik->DajKopiju();
         p_lik=nullptr;
         p_lik = p_novi;
         return *this;
         }
     PolimorfniSpremnik &operator =(PolimorfniSpremnik &&lik) {
         std::swap(p_lik, lik.p_lik);
         return *this;
     }
     double DajTezinu() const { Test(); return p_lik->DajTezinu();}
     string DajNaziv() const { Test(); return p_lik->DajNaziv();}
     double DajUkupnuTezinu() const { Test(); return p_lik->DajUkupnuTezinu();}
     void Ispisi() const { Test(); p_lik->Ispisi();}
};

class Skladiste
{
    vector<shared_ptr<Spremnik>> v;
public:
    Skladiste() {}
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
    ~Skladiste(){
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
    }
    Spremnik *DodajSanduk(double t, string naz, vector<double> wei){
        v.push_back(make_shared<Sanduk>(t,naz,wei));
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
    Spremnik *DodajVrecu(double t, string naz, double g){
        v.push_back(make_shared<Vreca>(t,naz,g));
        return v[v.size()-1].get();
    }
    void IzlistajSkladiste()
    {
        vector<shared_ptr<Spremnik>>s1(v.size());
        for(int i=0; i<v.size(); i++) s1[i]=v[i];
        sort(s1.begin(), s1.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();});
        for(int i=0; i<s1.size(); i++) {s1[i]->Ispisi(); s1[i]=nullptr;}
    }
    Spremnik& DajNajlaksi() 
    {
        if(v.size()==0) throw range_error("Skladiste je prazno");
        double min=v[0]->DajTezinu(); int ind=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]->DajTezinu()<min) 
            {
                min=v[i]->DajTezinu(); ind=i;
                
            }
        }
        return *v[ind];
    }
    Spremnik *DodajBure(double t, string naz, double wei, double z){
        v.push_back(make_shared<Bure>(t,naz,wei,z));
        return v[v.size()-1].get();
    }
    Spremnik& DajNajtezi() 
    {
        if(v.size()==0) throw range_error("Skladiste je prazno");
        sort(v.begin(), v.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){return p1->DajTezinu()>p2->DajTezinu();});
        return *v[0];
    }
    Spremnik *DodajSpremnik(Spremnik *p, bool a) 
    {
        if(a) {
            v.push_back(p->DajPlitkuKopiju()); 
        }
        else v.push_back(p->DajKopiju());
        return v[v.size()-1].get();
    }
    int BrojPreteskih(int t)
    {
        return count_if(v.begin(), v.end(), [t](shared_ptr<Spremnik> p1){return p1->DajUkupnuTezinu()>t;});
    }
    Skladiste(Skladiste &&n)
    {
        v=n.v; n.v.resize(0);
    }
    int BrojPreteskih(int t) const
    {
        return count_if(v.begin(), v.end(), [t](shared_ptr<Spremnik> p1){return p1->DajUkupnuTezinu()>t;});
    }
    Skladiste &operator =(Skladiste &&n)
    {
        if(&n==this) return *this;
        for(int i=0; i<v.size(); i++)  v[i]=nullptr;
        v.resize(0);
        v=n.v; n.v.resize(0);
        return *this;
    }
    void UcitajIzDatoteke(string str)
    {
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
        v.resize(0);
        ifstream tok(str);
        if(!tok) throw logic_error("Trazena datoteka ne postoji");
        string tip;
        while(getline(tok,tip))
        {
            if(tip.size()<3) throw logic_error("Datoteka sadrzi besmislene podatke");
            if(tip[1]!=' ') throw logic_error("Datoteka sadrzi besmislene podatke");
            char kont=tip[0];
            string n=tip.substr(2,tip.size());
            string s1;
            if(kont=='B')
            {
            
                getline(tok,s1);
                int brr=0;
                for(int i=0; i<s1.size(); i++)
                {
                    if(s1[i]==' ') brr++;
                    else if(s1[i]!='.')
                        {
                            if(s1[i]<'0' || s1[i]>'9') throw logic_error("Datoteka sadrzi besmislene podatke");
                        }
                }
                if(brr!=2) throw logic_error("Datoteka sadrzi besmislene podatke");
                string weight,thickness,volume;
                int i=0;
                while(s1[i]!=' ') { weight+=s1[i]; i++;}
                i++;
                while(s1[i]!=' ') { thickness+=s1[i]; i++;}
                i++;
                while(i!=s1.size()) { volume+=s1[i]; i++;}
                double wei=stod(weight), gus=stod(thickness), V=stod(volume);
                v.push_back(make_shared<Bure>(wei,n,gus,V));
            }
            else if(kont=='V')
            {
                getline(tok,s1);
                int brr=0;
                for(int i=0; i<s1.size(); i++)
                {
                    if(s1[i]==' ') brr++;
                    else if(s1[i]!='.')
                        {
                            if(s1[i]<'0' || s1[i]>'9') throw logic_error("Datoteka sadrzi besmislene podatke");
                        }
                }
                if(brr!=1)throw logic_error("Datoteka sadrzi besmislene podatke");
                string weight,volume;
                int i=0;
                while(s1[i]!=' ') { weight+=s1[i]; i++;}
                i++;
                while(i!=s1.size()) { volume+=s1[i]; i++;}
                double wei=stod(weight), V=stod(volume);
                v.push_back(make_shared<Vreca>(wei,n,V));
            }
            else if(kont=='S')
            {
                getline(tok,s1);
                int brr=0;
                for(int i=0; i<s1.size(); i++)
                {
                    if(s1[i]==' ') brr++;
                    else if(s1[i]!='.')
                        {
                            if(s1[i]<'0' || s1[i]>'9') throw logic_error("Datoteka sadrzi besmislene podatke");
                        }
                }
                string weight;
                int i=0;
                while(s1[i]!=' ') { weight+=s1[i]; i++;}
                i++;
                s1=s1.substr(i, s1.size());
                
                vector<double> weights; vector<string> ts1;
                i=0;
                while(1){
                    if(i==s1.size()+1) break;
                    string clan;
                    while(i!=s1.size() && s1[i]!=' ') {clan.push_back(s1[i]); i++;}
                    ts1.push_back(clan);
                    i++;
                }
                
                double wei=stod(weight); 
                for(int i=0; i<ts1.size(); i++) weights.push_back(stod(ts1[i]));
                v.push_back(make_shared<Sanduk>(wei,n,weights));
            }
            
            else throw logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(tok.eof()) return;
        else if(tok.bad()) std::cout << "Problemi pri citanju datoteke";
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
    catch(range_error r) { cout<<r.what();} 
   
	return 0;
}
