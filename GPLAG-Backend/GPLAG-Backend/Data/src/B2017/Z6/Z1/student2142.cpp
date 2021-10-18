/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


class Spremnik
{
    protected:
    string sadrzaj;
    double tezina;
    
    public:
    Spremnik(string s,double t):sadrzaj(s),tezina(t){};
    virtual shared_ptr<Spremnik> DajKopiju()=0;
    virtual shared_ptr<Spremnik> DajPok()=0;
    string DajNaziv() const{ return sadrzaj;}
    double DajTezinu() const{return tezina;}
    virtual double DajUkupnuTezinu()const =0;
    virtual void Ispisi()=0;
    virtual ~Spremnik(){};
};
//Sanduk,Vreca,Bure
//Skladiste(kontejner)

class Sanduk:public Spremnik
{
  vector<double> v;
  public:  
  Sanduk(const double &t,const string &s,const vector<double>&v):Spremnik(s,t),v(v){};
  double DajUkupnuTezinu() const
  {
      double suma=0;
      for(int i=0;i<v.size();i++)
        suma+=v[i];
      return suma+DajTezinu();
  }
  void Ispisi()
  {
      cout<<"Vrsta spremnika: Sanduk"<<endl;
      cout<<"Sadrzaj: "<<DajNaziv()<<endl;
      cout<<"Tezine predmeta: ";
      for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
      cout<<"(kg)"<<endl;
      cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<endl;
      cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
  }
  shared_ptr<Spremnik> DajKopiju(){
      return make_shared<Sanduk>(*this);
  }
  shared_ptr<Spremnik> DajPok()
  {
    return shared_ptr<Sanduk>(this);
  }
};

class Vreca:public Spremnik
{
    double t;
    public:
    Vreca(double t,string s,const double t1):Spremnik(s,t),t(t1){};
    double DajUkupnuTezinu() const
    {
      return t+DajTezinu();
    }
    void Ispisi()
    {
      cout<<"Vrsta spremnika: Vreca"<<endl;
      cout<<"Sadrzaj: "<<DajNaziv()<<endl;
      cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl;
      cout<<"Tezina pohranjene materije: "<<t<<" (kg)"<<endl;
      cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    
 
  shared_ptr<Spremnik> DajKopiju()
  {
      return make_shared<Vreca>(*this);
  }
  
  shared_ptr<Spremnik> DajPok()
  {
    return shared_ptr<Vreca>(this);
  }
};

class Bure:public Spremnik
{
    double gust,zapremina;
    public:
    Bure(const double &t,const string &s,const double &gust,const double &z):Spremnik(s,t),gust(gust),zapremina(z){};
    double DajUkupnuTezinu() const
    {
      return (gust*zapremina)/1000+DajTezinu();
    }
    void Ispisi()
    {
      cout<<"Vrsta spremnika: Bure"<<endl;
      cout<<"Sadrzaj: "<<DajNaziv()<<endl;
      cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl;
      cout<<"Specificna tezina tecnosti: "<<gust<<" (kg/m^3)"<<endl;
      cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<endl;
      cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;
    }
    
  shared_ptr<Spremnik> DajKopiju(){
      return make_shared<Bure>(*this);
  }
  
  shared_ptr<Spremnik> DajPok()
  {
    return shared_ptr<Bure>(this);
  }
};

class Skladiste
{   
    vector<shared_ptr<Spremnik>> v;
    
    void SortirajSkladiste()
    {
      sort(v.begin(),v.end(),[](shared_ptr<Spremnik>a,shared_ptr<Spremnik> b)
                             {
                               return a->DajUkupnuTezinu()>b->DajUkupnuTezinu();
                             }
      
      );
    }
    void SortirajSkladiste1()
    {
      sort(v.begin(),v.end(),[](shared_ptr<Spremnik>a,shared_ptr<Spremnik> b)
                             {
                               return a->DajTezinu()<b->DajTezinu();
                             }
      
      );
    }
    
    public:
    Skladiste(){};
    Skladiste(Skladiste &s)
    {
      for(int i=0;i<s.v.size();i++)
        v.push_back(s.v[i]->DajKopiju());
    }
    Skladiste(Skladiste &&s)
    {
      for(int i=0;i<s.v.size();i++)
          v.push_back(s.v[i]->DajKopiju());
      
      s.v.resize(0);
    }
    Skladiste &operator=(Skladiste &s)
    {
        if(this!=&s)
        {
          v.resize(0);
          
      for(int i=0;i<s.v.size();i++)
        v.push_back(s.v[i]);
        }
        return *this;
    }
    Skladiste &operator=(Skladiste &&s)
    {
       if(this!=&s)
        {
           v.resize(0);
           for(int i=0;i<s.v.size();i++)
            v.push_back(s.v[i]->DajKopiju());
      
           s.v.resize(0);
        }
        return *this;
    }
    
    ~Skladiste()
    {
      for(int i=0;i<v.size();i++)
        v[i]=nullptr;
      v.resize(0);
    }
    Spremnik* DodajSanduk(const double t,const string s,const vector<double>&v1)
    {
        //Sanduk *pok=new Sanduk(t,s,v1);
        v.push_back(make_shared<Sanduk>(t,s,v1));
        return v[v.size()-1].get();
    }
    Spremnik* DodajVrecu(double t,string s,const double t1)
    {
      //  Vreca *pok=new Vreca(t,s,t1);
        v.push_back(make_shared<Vreca>(t,s,t1));
        return v[v.size()-1].get();
    }
    Spremnik* DodajBure(const double &t,const string &s,const double &gust,const double &z)
    {
      //Bure *pok=new Bure(t,s,gust,z);
      v.push_back(make_shared<Bure>(t,s,gust,z));
      return v[v.size()-1].get();
    }
    Spremnik* DodajSpremnik(Spremnik *pok,bool Vlasnistvo)
    {
      
      if(Vlasnistvo) v.push_back(pok->DajPok());
      else v.push_back(pok->DajKopiju());
      return v[v.size()-1].get();
    }
    void BrisiSpremnik(Spremnik *pok)
    {
      for(int i=0;i<v.size();i++)
        if(v[i].get()==pok)
        {
          v[i]=nullptr;
          for(int j=i;j<v.size()-1;j++)
            v[j]=v[j+1];
          v.resize(v.size()-1);
        }
          
    }
    Spremnik &DajNajlaksi() 
    {
      if(v.size()==0) throw range_error("Skladiste je prazno");
        this->SortirajSkladiste1();
        return *v[0];
    }
    Spremnik &DajNajtezi() 
    {
      if(v.size()==0) throw range_error("Skladiste je prazno");
        this->SortirajSkladiste1();
        return *v[v.size()-1];
    }
    int BrojPreteskih(int n)const
    {   
        int br=0;
        for(int i=0;i<v.size();i++)
            if(v[i]->DajUkupnuTezinu()>n)
              br++;
              
        return br;
    }
    void IzlistajSkladiste()
    { 
      SortirajSkladiste();
      for(int i=0;i<v.size();i++)
        {v[i]->Ispisi(); cout<<endl;}
    }
    void UcitajIzDatoteke(string d)
    {
        ifstream ulaz(d);
        if(!ulaz) throw logic_error("Trazena datoteka ne postoji");
        for(int i=0; i<v.size(); i++) v[i]=nullptr;
        v.resize(0);
        //ifstream ulaz(dat);
        while(1)
        {
            string tip;
            if(!getline(ulaz,tip)) break;
            if(tip.size()<3 || (tip.size()>=3 && tip[1]!=' ')) throw logic_error("Datoteka sadrzi besmislene podatke");
            char a=tip[0];
            switch(a) {
              case('B'):
            {
                string naziv=tip.substr(2,tip.size());
                string pom; 
                getline(ulaz,pom);
                //if(teststringabure(pom)==false) throw logic_error("Datoteka sadrzi besmislene podatke");
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
            case('S'):
            {
                string naziv=tip.substr(2,tip.size());
                string pom; getline(ulaz,pom);
                //if(teststringasanduk(pom)==false) throw logic_error("Datoteka sadrzi besmislene podatke");
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
            case('V'):
            {
                string naziv=tip.substr(2,tip.size());
                string pom; 
                getline(ulaz,pom);
                //if(teststringavreca(pom)==false) throw logic_error("Datoteka sadrzi besmislene podatke");
                string tezina,zapremina;
                int i=0;
                while(pom[i]!=' ') { tezina+=pom[i]; i++;}
                i++;
                while(i!=pom.size()) { zapremina+=pom[i]; i++;}
                double tez=stod(tezina), zap=stod(zapremina);
                v.push_back(make_shared<Vreca>(tez,naziv,zap));
            }
            default: { throw logic_error("Datoteka sadrzi besmislene podatke");}
            }
            
        }
        if(ulaz.eof()) return;
        if(ulaz.bad()) std::cout << "Problemi pri citanju datoteke";
        else std::cout << "Datoteka sadrži besmislene podatke";
    }
    
    
};

int main ()
{   
  try
    {

        Skladiste ETF;
        ETF.DodajSanduk(50, "Voce", {1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300, 150);
        ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        ETF.DodajSpremnik(b, false);
        delete b;
        //ETF.IzlistajSkladiste();
        ETF.DajNajlaksi().Ispisi();
        std::cout << ETF.BrojPreteskih(40) << std::endl;
        ETF.DajNajtezi().Ispisi();
    }
    catch(std::range_error re)
    {
        std::cout << re.what();
    }
	return 0;
}
