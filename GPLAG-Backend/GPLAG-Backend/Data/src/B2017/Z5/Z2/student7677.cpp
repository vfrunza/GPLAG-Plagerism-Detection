/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

using namespace std;

class Student{
  
  int br_indeksa;
  string godina_studija;
  string ime_i_prezime;
  string adresa;
  string telefon;
  
  public:
  
  Student (int br_ind, string g_s, string i_i_p, string a, string t){
      
      int br=0;
      int pom=br_ind;
      
      while(pom!=0){
          br++;
          pom/=10;
      }
      if(br<5)throw domain_error("Neispravni parametri");
      
      if(g_s!="1" && g_s!="2" && g_s!="3" && g_s!="1/B" && g_s!="2/B" && g_s!="3/B" && g_s!="1/M" && g_s!="2/M" &&g_s!="1/D" && g_s!="2/D" && g_s!="3/D" )
        throw domain_error("Neispravni parametri");
        
        //ime i prezime
        
        while(i_i_p[0]==' ')i_i_p.erase(0,1);
        for(int i=0;i<i_i_p.size()-1;i++){
            if(i_i_p[i]==' '&& i_i_p[i+1]==' '){
                i_i_p.erase(i,1);
                i--;
            }
        }
      if(i_i_p[i_i_p.size()-1]==' ')i_i_p.erase(i_i_p.size()-1,1);
      
      //telefon
      int pom1;
      for(pom1=0;t[pom1]!='/';pom1++){
          if(t[pom1]>'9' || t[pom1]<'0'){
              throw domain_error("Neispravni parametri");
          }
        }
        pom1++;
        for(pom1;t[pom1]!='-';pom1++){
            if(t[pom1]>'9' || t[pom1]<'0'){
              throw domain_error("Neispravni parametri");
          }
        }
        pom1++;
        for(pom1;pom1<t.size();pom1++){
             if(t[pom1]>'9' || t[pom1]<'0'){
              throw domain_error("Neispravni parametri");
          }
        }
        
        this->br_indeksa=br_ind;
        this->ime_i_prezime=i_i_p;
        this->godina_studija=g_s;
        this->telefon=t;
        this->adresa=a;
      
  }
  
  int DajIndeks(){ return br_indeksa;}
  
  string DajGodinuStudija(){
      if(godina_studija=="1")godina_studija="1/B";
      if(godina_studija=="2")godina_studija="2/B";
      if(godina_studija=="3")godina_studija="3/B";

    return godina_studija;
  }
  
  string DajImePrezime(){return ime_i_prezime;}
  string DajAdresu(){ return adresa; }
  string DajTelefon(){ return telefon;}
  
  void Ispis(){
      cout<<"Broj indeksa: "<<br_indeksa<<endl<<"Godina studija: "<<godina_studija<<endl<<
      "Ime i prezime: "<<ime_i_prezime<<endl<<"Adresa: "<<adresa<<endl<<"Telefon: "<<telefon<<endl;
  }
  
    
};

class Laptop{
  
    int ev_broj;
    string naziv;
    string karakteristike;
    Student *kod_koga_je=nullptr;
    
    public:
    
    Laptop(int ev_b, string n, string k){
        if(ev_b<0)throw domain_error ("Neispravni parametri");
        
        this->ev_broj=ev_b;
        this->naziv=n;
        this->karakteristike=k;
    }
    
    int DajEvidencijskiBroj(){ return ev_broj;}
    string DajNaziv(){ return naziv;}
    string DajKarakteristike(){ return karakteristike;}
   
   
    void Zaduzi (Student &s){
        if(DaLiJeZaduzen())throw domain_error("Laptop vec zaduzen");
        else this->kod_koga_je=&s;
    }
    
    void Razduzi(){
        kod_koga_je=nullptr;
    }
    
    bool DaLiJeZaduzen(){
        if(kod_koga_je==nullptr)return false;
        return true;
    }
    
    Student &DajKodKogaJe(){
        if(!(DaLiJeZaduzen()))throw domain_error("Laptop vec zaduzen");
        return *kod_koga_je;
    }
    
    Student *DajPokKodKogaJe(){
        if(!(DaLiJeZaduzen()))kod_koga_je=nullptr;
        return kod_koga_je;
    }
    
    void Ispis(){
        cout<<"Evidencijski broj: "<<ev_broj<<endl<<"Naziv: "<<naziv<<endl<<"Karakterostike: "<<karakteristike<<endl;
    }
};

class Administracija{
  
    map<int,shared_ptr<Student>>mapa_studenata;
    map<int,shared_ptr<Laptop>>mapa_laptopa;
    
    public:
    
    Administracija(){}
    
    
    Administracija(const Administracija &a){
        
        auto it=a.mapa_studenata.begin();
        while (it!=a.mapa_studenata.end()) {
            shared_ptr<Student> ptr=make_shared<Student>(Student(it->second.get()->DajIndeks(),
            it->second.get()->DajGodinuStudija(),it->second.get()->DajImePrezime(),it->second.get()->DajAdresu(),it->second.get()->DajTelefon()));
            this->mapa_studenata[it->first]=ptr;
            it++;
        }
        auto it2=a.mapa_laptopa.begin();
        while (it2!=a.mapa_laptopa.end()) {
            
           shared_ptr<Laptop> ptr=make_shared<Laptop>(Laptop(it2->second->DajEvidencijskiBroj(),it2->second->DajNaziv(),it2->second->DajKarakteristike()));
            this->mapa_laptopa[it2->first]=ptr;
            it2++;
        }
    }
    
    void RegistrirajNovogStudenta(int br_ind, string g_s, string i_i_p, string a, string t){
        
        auto it(this->mapa_studenata.find(br_ind));
        if(it!=this->mapa_studenata.end())throw domain_error("Student s tim indeksom vec postoji");
        
        shared_ptr<Student> ptr=make_shared<Student>(Student(br_ind,g_s,i_i_p,a,t));
        this->mapa_studenata.insert({br_ind,ptr});
    }

    void RegistrirajNoviLaptop(int ev_b, string n, string k){
        
        auto it(this->mapa_laptopa.find(ev_b));
        if(it!=this->mapa_laptopa.end())throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
        
        shared_ptr<Laptop> ptr=make_shared<Laptop>(Laptop(ev_b,n,k));
        this->mapa_laptopa[ev_b]=ptr;
    }
    
    Student &NadjiStudenta(int br_i){
        
        auto it(this->mapa_studenata.find(br_i));
        if(it==this->mapa_studenata.end())throw domain_error("Student nije nadjen");
        
        return *mapa_studenata[br_i];
    }
    
    Laptop &NadjiLaptop(int ev_b){
        
        auto it(this->mapa_laptopa.find(ev_b));
        if(it==this->mapa_laptopa.end())throw domain_error("Laptop nije nadjen");
        
        return *mapa_laptopa[ev_b];
    }
    
    void IzlistajStudente(){
        int a=0;
        
        for(auto it=this->mapa_studenata.begin(); it!=this->mapa_studenata.end();it++){
            a++;
            it->second->Ispis();
            if(a%2==0)cout<<endl;
        }
    }
    
    void IzlistajLaptope(){
        
       for(auto it=this->mapa_laptopa.begin(); it!=this->mapa_laptopa.end();it++){
           it->second->Ispis();
           if(it->second->DajPokKodKogaJe()!=nullptr)
           cout<<"Zaduzio(la):"<<it->second->DajPokKodKogaJe()->DajImePrezime()<<"("<<it->second->DajPokKodKogaJe()->DajIndeks()<<")"<<endl;
       }

    }
    
    void ZaduziLaptop( int ind, int ev_br){
        
        Student s=this->NadjiStudenta(ind);
        Laptop l=this->NadjiLaptop(ev_br);
        
        this->mapa_laptopa[ev_br]->Zaduzi(this->NadjiStudenta(ind));
        
    }
    
    void RazduziLaptop(int ev_br){
        
        Laptop l=this->NadjiLaptop(ev_br);
        this->mapa_laptopa[ev_br]->Razduzi();
    }
    
    int NadjiSlobodniLaptop(){
        
        for(auto it=mapa_laptopa.begin();it!=mapa_laptopa.end();it++){
            if(it->second->DaLiJeZaduzen()==false)return it->second->DajEvidencijskiBroj();
        }
        
        throw domain_error("Nema slobodnih laptopa");
    }
    
    void PrikaziZaduzenja(){
        bool postoji=false;
        for(auto it=mapa_laptopa.begin();it!=mapa_laptopa.end();it++){
            if(it->second->DaLiJeZaduzen()==true){
                postoji=true;
                cout<<"Student "<<it->second->DajPokKodKogaJe()->DajImePrezime()<<"("<<it->second->DajPokKodKogaJe()->DajIndeks()<<") zaduzio(la) laptop broj "<<
                it->second->DajEvidencijskiBroj()<<endl;
            }
        }
        if(postoji==false)cout<<"Nema zaduzenja"<<endl;
    }
    
};

int main (){
        try{
        int n_s, n_l;
        Administracija adm;
        
        //STUDENTI!!
        cout<<"Koliko imate studenata?"<<endl;
        cin>>n_s;
        
        cout<<"Unesite podatke o studentima!"<<endl;
       
       for(int i=0;i<n_s;i++){
            int br_ind;
            string g_s,a,t,i_i_p;
            
            cout<<i+1<<". student:"<<endl<<"BROJ INDEKSA: ";
            cin>>br_ind;
            cin.clear();
            cin.ignore(10000,'\n');
            
            cout<<endl<<"GODINA STUDIJA: ";
            getline(cin,g_s);
            
            cout<<endl<<"IME I PREZIME: ";
            getline(cin,i_i_p);
            
            cout<<endl<<"ADRESA STANOVANJA: ";
            getline(cin,a);
            
            cout<<endl<<"TELEFON: ";
            getline(cin,t);
            
            
            adm.RegistrirajNovogStudenta(br_ind,g_s,i_i_p,a,t);
        }
        cout<<endl;
        
        //LAPTOPI!!
        cout<<"Koliko imate laptopa?"<<endl;
        cin>>n_l;
        
        cout<<"Unesite podatke o laptop!";
        
        for(int i=0;i<n_l;i++){
            
            int ev_br;
            string n, k;
            cout<<i+1<<". laptop: "<<endl<<"EVIDENCIJSKI BROJ: ";
            cin>>ev_br;
            cin.clear();
            cin.ignore(10000,'\n');
            
            cout<<endl<<"NAZIV: ";
            getline(cin,n);
            
            cout<<endl<<"KARAKTERISTIKE: ";
            getline(cin,k);
            
            
            adm.RegistrirajNoviLaptop(ev_br,n,k);
        }
        
        cout<<"Koliko zelite laptopa zaduziti?";
        int z_l;
        cin>>z_l;
        
        cout<<"Unesite broj indeksa studena koji zeli da zaduzi laptop, te evidencijski broj laptopa koji zaduzuje (respektivno)!"<<endl;
        
        for(int i=0;i<z_l;i++){
            int br_ind,ev_br;
            cout<<i+1<<". zaduzeni laptop: "<<endl;
            cin>>br_ind>>ev_br;
            adm.ZaduziLaptop(br_ind,ev_br);
        }
        
        Administracija b_adm(adm);
        
        cout<<"Koliko zelite razduziti laptopa?"<<endl;
        int r_l;
        cin>>r_l;
        if(r_l==0)cout<<"Ne zelim razduziti niti jedan laptop."<<endl;
        else{
            for(int i=0;i<r_l;i++){
             int ev_br;
            cout<<i+1<<". razduzeni laptop: "<<endl;
            cin>>ev_br;
            adm.RazduziLaptop(ev_br);
            }
        }
        
        cout<<endl;
        adm.PrikaziZaduzenja();
        cout<<endl;
        b_adm.PrikaziZaduzenja();
        cout<<endl;
        adm.IzlistajLaptope();
        adm.IzlistajStudente();
        
        
    }catch(domain_error izuzetak){
        cout<<izuzetak.what();
    }
    
    
	return 0;
}
