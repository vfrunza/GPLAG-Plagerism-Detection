/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <cmath>
#include <sstream>

using namespace std;

class Student{
  int ind;
  string god,naziv,adresa,telefon;
  
  public:
  
  Student(int ind,string god,string naziv,string adresa,string telefon){
      
      int brind=0,temp=ind;
      while(temp!=0){brind++;temp/=10;}
      
      if(brind<5)throw domain_error("Neispravni parametri1");
      this->ind=ind;
      
      if(god!="1" && god!="2" && god!="3" && god!="1/B" && god!="2/B" && god!="3/B" && god!="1/M" && god!="2/M" && god!="1/D" && god!="2/D" && god!="3/D"){
          throw domain_error("Neispravni parametri2");
      }
      else this->god=god;
      
      while(naziv[0]==' ')naziv.erase(0,1);
      
      for(int i=0;i<naziv.size()-1;i++){
          if(naziv[i]==' ' && naziv[i+1]==' ')naziv.erase(i--,1);
      }
      
      if(naziv[naziv.size()-1]==' ') naziv.erase(naziv.size()-1,1);
      
      this->naziv=naziv;
      
      int brojac=100;
      
      for(int i=0;i<telefon.size();i++){
          
          if(telefon[i]<'0' ||telefon[i]>'9'){
             
             if(telefon[i]=='/'){
                 if(brojac!=100)throw domain_error("Neispravni parametri");
                 else brojac+=50;
             }
             else if(telefon[i]=='-'){
                 if(brojac!=150)throw domain_error("Neispravni parametri");
                 else brojac+=50;
             }
             else throw domain_error("Neispravni parametri");
          }
          
      }
      
      this->telefon=telefon;
      
      this->adresa=adresa;
      
      
      
  }
  
  int DajIndeks()const{return this->ind;}
  
  string DajGodinuStudija()const{
      if(god=="1")return "1/B" ;
      if(god=="2")return "2/B";
      if(god=="3")return "3/B";
      return god;
      
  }
  
  string DajImePrezime()const{return this->naziv;}
  
  string DajAdresu()const{return this->adresa;}
  
  string DajTelefon()const{return this->telefon;}
  
  void Ispisi()const{
      cout<<"Broj indeksa: "<<this->DajIndeks()<<endl<<"Godina studija: "<<this->DajGodinuStudija()<<endl<<"Ime i prezime: "<<this->DajImePrezime()<<endl<<"Adresa: "<<
      this->DajAdresu()<<endl<<"Telefon: "<<this->DajTelefon()<<endl;
  }
    
    
};

class Laptop{
    
    int ev_broj;
    string naziv,karakteristike;
    Student *kod_koga_je=nullptr;
    
    public:
    
    Laptop(int i,string n,string k){
      if (i<0)throw domain_error("Neispravni parametri");
      ev_broj=i;naziv=n;karakteristike=k;kod_koga_je=nullptr;
    }
    
    int DajEvidencijskiBroj()const{return ev_broj;}
    
    string DajNaziv()const{return naziv;}
    
    string DajKarakteristike()const{return karakteristike;}
    
    void Zaduzi(Student &s){
      
      if(kod_koga_je!=nullptr)throw domain_error("Laptop vec zaduzen");
      kod_koga_je=&s;
      
    }
    
    void Razduzi(){kod_koga_je=nullptr;}
    
    bool DaLiJeZaduzen()const{
      
      return(kod_koga_je!=nullptr);
      
    }
    
    Student &DajKodKogaJe()const{
      if(kod_koga_je==nullptr) throw domain_error ("Laptop nije zaduzen");
      return *kod_koga_je;
    }
    
    Student *DajPokKodKogaJe()const{return kod_koga_je;}
    
    void Ispisi()const{
      cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<endl;
      cout<<"Naziv: "<<DajNaziv()<<endl;
      cout<<"Karakteristike: "<<DajKarakteristike()<<endl;
    }
    
};

class Administracija{
  
  map<int,Student*> studenti;
  map<int,Laptop*> laptopi;
  
  public:
  
  Administracija(){}
  
  Administracija(Administracija &a){
    
  swap(a.studenti,studenti);
  swap(a.laptopi,laptopi);
  
  }
  
  Administracija(const Administracija &a){
    
    for(auto it=a.studenti.begin();it!=a.studenti.end();it++)
      studenti[it->first]=new Student(*(it->second));
    
     for(auto it=a.laptopi.begin();it!=a.laptopi.end();it++)
      laptopi[it->first]=new Laptop(*(it->second));
  }
  
  void RegistrirajNovogStudenta(int i,string g,string im,string ad,string t){
    
    for(auto it=studenti.begin();it!=studenti.end();it++)
    if(it->first==i)throw domain_error("Student s tim indeksom vec postoji");
    
    studenti.insert({i,new Student(i,g,im,ad,t)});
    
  }
  
  
  void RegistrirajNoviLaptop(int ev,string ime,string k){
    
    for(auto it=laptopi.begin();it!=laptopi.end();it++)
    if(it->first==ev)throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
    
    laptopi.insert({ev,new Laptop(ev,ime,k)});
    
  }
  
  Student &NadjiStudenta(int i)const{
    
    for(auto it=studenti.begin();it!=studenti.end();it++)
    if(it->first==i) return *(it->second);
    
    throw domain_error("Student nije nadjen");
    
  }
  
  Laptop &NadjiLaptop(int ev)const{
    
    for(auto it=laptopi.begin();it!=laptopi.end();it++)
    if(it->first==ev)return *(it->second);
    
    throw domain_error("Laptop nije nadjen");
    
  }
  
  void IzlistajStudente()const{
    int brojac=1;
    
      for(auto it=studenti.begin();it!=studenti.end();it++){
        it->second->Ispisi();
        if(brojac++%2==0)cout<<endl;
      }
    
  }
  
  void IzlistajLaptope()const{
    int brojac=1;
    
      for(auto it=laptopi.begin();it!=laptopi.end();it++){
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen()==true) cout<<"Zaduzio(la): "<<it->second->DajPokKodKogaJe()->DajImePrezime()<<" ("<<it->second->DajPokKodKogaJe()->DajIndeks()<<")"<<endl;
        if(brojac++%2==0)cout<<endl;
      }
    
  }
  
  void ZaduziLaptop(int i,int ev){
    
    auto it=laptopi.find(ev);
    auto it2=studenti.find(i);
    if(it==laptopi.end())throw domain_error ("Laptop nije nadjen");
    if(it2==studenti.end())throw domain_error ("Student nije nadjen");
    
    laptopi[ev]->Zaduzi(NadjiStudenta(i));
  
  }
  
  int NadjiSlobodniLaptop()const{
    
    for(auto it=laptopi.begin();it!=laptopi.end();it++){
      
      if(it->second->DaLiJeZaduzen()==false)return it->first;
      
    }
    
    throw domain_error("Nema slobodnih laptopa");
    
  }
  
  void RazduziLaptop(int ev){
    
    auto it=laptopi.find(ev);
    if(it==laptopi.end())throw domain_error("Laptop nije nadjen");
    if(laptopi[ev]->DaLiJeZaduzen() ==false) throw domain_error ("Laptop nije zaduzen");
    
    laptopi[ev]->Razduzi();
    
  }
  
  void PrikaziZaduzenja()const{
    
    bool zaduzio=false;
    
    for(auto it=laptopi.begin();it!=laptopi.end();it++){
      
      if(it->second->DaLiJeZaduzen()==true){
        cout<<"Student "<<it->second->DajPokKodKogaJe()->DajImePrezime()<<" ("<<it->second->DajPokKodKogaJe()->DajIndeks()<<")"<< " zaduzio/la laptop broj "<<it->first<<endl;
        zaduzio=true;
      }
      
    }
    
    if(zaduzio==false)throw domain_error("Nema zaduzenja");
    
    
  }
  
  ~Administracija(){
    
    for(auto it=studenti.begin();it!=studenti.end();it++)delete it->second;
    
    for(auto it=laptopi.begin();it!=laptopi.end();it++)delete it->second;
  }
  
};

void Ocisti(){
  cin.clear();
      cin.ignore(10000,'\n');
}

int main ()
{
  
  
  Administracija a;

  a.RegistrirajNovogStudenta(18089,"1","Donald Duck","Barska 27","033/626-982");
  a.RegistrirajNovogStudenta(17867,"1/B","Minnie Mouse","Barska 27","061/261-657");
  a.RegistrirajNovogStudenta(10000,"3/D","Gill Bates","Makrohard","012/345-678");
  a.RegistrirajNovogStudenta(14689,"3","Fus Ime","Fus Adresa","112/112-1121");
  
  a.RegistrirajNoviLaptop(1,"Asus","i5 4X3.3 8GB");
  a.RegistrirajNoviLaptop(2,"Dell","Pentium 1X1.3 512MB");
  a.RegistrirajNoviLaptop(3,"Lenovo","Dual Core 2.36 4GB");
  
  a.ZaduziLaptop(18089,1);
  
  cout<<"LEGENDA: "<<endl<<"1)Funkcije :"<<endl
  <<"RNS(indeks,grupa,ime-prezime,adresa,telefon)-Registrira novog studenta"<<endl
  <<"RNL(evidencijski-broj,ime,karakteristike)-Registrira novi laptop"<<endl
  <<"IL-IzlistajLaptope"<<endl<<"IS-IzlistajStudente"<<endl<<"PZ-PrikaziZaduzenja"<<endl
  <<"ZL(evidencijski-broj,indeks)-Zaduzi laptop"<<endl
  <<"RL(evidencijski-broj)-Razduzi laptop"<<endl
  <<"I-Ispisi"<<endl
  <<"2)Variable :"<<endl
  <<"NS(indeks)-Nadji studenta"<<endl
  <<"NL(evidencijski-broj)-Nadji laptop"<<endl
  <<"NSL-Nadji slobodni laptop(vraca int)"<<endl;
  
  while(1){
    
    cout<<"Unesite 0 za kraj, 1 za unos, 2 za pomoc: "<<endl;
    int unos=5;
    cin>>unos;
    if(unos==2)
      cout<<"Prvo unesite ime funkcije, pa zatim variablu po variablu"<<endl;
    else if(unos==0)break;
    
    else if(unos==1){
      Ocisti();
      cout<<"Unesite funkciju "<<endl;
      string fja;
      getline(cin,fja);
      try{
      if(fja=="IL") a.IzlistajLaptope();
      else if(fja=="IS") a.IzlistajStudente();
      else if(fja=="PZ") a.PrikaziZaduzenja();
      else if(fja=="RNS"){
        cout<<"Indeks: "<<endl;
        int i;cin>>i;
        Ocisti();
        cout<<"grupa: (1,2,3,1/B,2/B,3/B,1/M,2/M,1/D,2/D,3/D)"<<endl;
        string g;getline(cin,g);
        cout<<"ime-prezime"<<endl;
        string imp;getline(cin,imp);
        cout<<"adresa "<<endl;
        string adr;getline(cin,adr);
        cout<<"telefon(000/000-000)"<<endl;
        string tel;getline(cin,tel);
        
        a.RegistrirajNovogStudenta(i,g,imp,adr,tel);
  
      }
      else if(fja=="RNL"){
        
        cout<<"Evidencijski broj"<<endl;
        int e;cin>>e;
        cout<<"Ime "<<endl;
        string ime;getline(cin,ime);
        cout<<"Karakteristike "<<endl;
        string kar;getline(cin,kar);
        a.RegistrirajNoviLaptop(e,ime,kar);
        
      }
      else if(fja=="ZL"){
        cout<<"Unesite evidencijski-broj(ili NSL) "<<endl;
        string evbr;int evb;
        getline(cin,evbr);
        
        if(evbr=="NSL")evb=a.NadjiSlobodniLaptop();
       else
          istringstream(evbr)>>evb;
          
          cout<<"Unesite indeks: "<<endl;
          int i;cin>>i;
        a.ZaduziLaptop(i,evb);
        
      }
      else if(fja=="I"){
        cout<<"Za studenta unesite S za laptop L"<<endl;
        char c;cin>>c;
        int br;
        if(c=='S') {cout<<"Unesite indeks"<<endl;cin>>br;a.NadjiStudenta(br).Ispisi();}
        else {cout<<"Unesite evidencijski broj"<<endl;cin>>br;a.NadjiLaptop(br).Ispisi();}
      }
      else if(fja=="RL"){
        cout<<"Unesite evidencijski-broj"<<endl;
        int evb;cin>>evb;
        a.RazduziLaptop(evb);
      }
    }
    catch(exception &ex){
      cout<<ex.what()<<endl<<endl<<endl;
    }
    }
    
  }
  
  
  
  cout<<"Caoo"<<endl;
  
	return 0;
}
