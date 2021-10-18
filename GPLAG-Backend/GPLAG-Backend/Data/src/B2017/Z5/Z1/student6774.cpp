#include <iostream>
#include<string>
#include<stdexcept>
#include<map>
int size(int broj){
    int i=0;
    while(broj!=0){
        i++;
        broj/=10;
    }
    return i;
}
bool check_year(std::string &god){
    if(god.size()>3)return true;
    if(god.size()==1){
       
        if(god[0]!='1'&&god[0]!='3'&&god[0]!='2')return true;
         
        god=god+std::string("/B");
    }if(god.size()==3){
        if(god[0]!='1'&&god[0]!='3'&&god[0]!='2')return true;
        if(god[1]!='/')return true;
        if(god[2]!='D'&&god[2]!='M'&&god[2]!='B')return true;
    }
    return false;
}
bool check_string(std::string &s){
       for(int i=0;i<s.size();i++){
        if(i==0)
        while(s[i]==' '){s.erase(s.begin()+i);}
        
        else
        if(s[i-1]==' '&&s[i]==' '){s.erase(s.begin()+i);i--;}
    }if(*(s.end()-1)==' ')s.erase(s.end()-1) ;
    return true;
}
bool check_phone(std::string s){
    int i=0;
    while(s[i]>='0'&&s[i]<='9')i++;
    if(s[i]=='/')i++;
    while (s[i]>='0'&&s[i]<='9')i++;
    if(s[i]=='-')i++;
    while (s[i]>='0'&&s[i]<='9')i++;
    if(s.size()!=i)return true;
    return false;
}
class Student{
    int index;std::string year; std::string name;std::string adress;std::string phone;
    public:
    Student(int indeks,std::string god, std::string imeiprezime,std::string adresa,std::string mobitel){
        if(size(indeks)!=5)throw std::domain_error{"Neispravni parametri"};
        if(check_year(god))throw std::domain_error{"Neispravni parametri"};
        check_string(imeiprezime);
        check_string(adresa);
        if(check_phone(mobitel))throw std::domain_error{"Neispravni parametri"};
        year=god;
        name=imeiprezime;
        adress=adresa;
        index=indeks;
        phone=mobitel;
    }
    friend class Administracija;
    int DajIndeks(){return index;}
    std::string DajGodinuStudija(){return year;}
    std::string DajImePrezime(){return name;}
    std::string DajAdresu(){return adress;}
    std::string DajTelefon(){return phone;}
    void Ispisi(){
        std::cout << "Broj indeksa: "<<index<<"\nGodina studija: "<<year<<"\nIme i prezime: "<<name<<"\nAdresa: "<<adress<<"\nTelefon: "<<phone << std::endl;
    }
};
class Laptop{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je=nullptr;
    public:
    Laptop(int br,std::string prvi,std::string drugi){
        if(br<0)throw std::domain_error{"Neispravni parametri"};
        ev_broj=br;naziv=prvi;karakteristike=drugi;kod_koga_je=nullptr;
    }
    friend class Administracija;
    int DajEvidencijskiBroj(){return ev_broj;}
    std::string DajNaziv(){return naziv;}
    std::string DajKarakteristike(){return karakteristike;}
    void Zaduzi(Student &s){
        if(kod_koga_je!=nullptr)throw std::domain_error{"Laptop vec zaduzen"};
        kod_koga_je=&s;
        
    } 
    Laptop(const Laptop &l){
        ev_broj=l.ev_broj;naziv=l.naziv;karakteristike=l.karakteristike;kod_koga_je=l.kod_koga_je;
    }
    void Razduzi(){
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen(){
        return kod_koga_je!=nullptr;
    }
    Student &DajKodKogaJe(){
        if(kod_koga_je==nullptr)throw std::domain_error{"Laptop nije zaduzen"};
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe(){
        return kod_koga_je;
    } 
    void Ispisi(){
        std::cout << "Evidencijski broj: "<<ev_broj<<"\nNaziv: "<<naziv<<"\nKarakteristike: "<<karakteristike << std::endl;
    }
};
class Administracija{
  std::map<int,Laptop*> laptopi;
  std::map<int,Student*>studenti;
  public:
  void RegistrirajNovogStudenta(int indeks,std::string god, std::string imeiprezime,std::string adresa,std::string mobitel){
    if(studenti.find(indeks)!=studenti.end())throw std::domain_error{"Student s tim indeksom vec postoji"};
    studenti[indeks]=new Student(indeks,god,imeiprezime,adresa,mobitel);
  }
  void RegistrirajNoviLaptop(int br,std::string prvi,std::string drugi){
 if(laptopi.find(br)!=laptopi.end())throw std::domain_error{"Laptop s tim evidencijskim brojem vec postoji"};
 laptopi[br]=new Laptop(br,prvi,drugi);
  }
  ~Administracija(){
     
        for(auto it(studenti.begin());it!=studenti.end();it++){
        delete it->second;
    }
      for(auto it(laptopi.begin());it!=laptopi.end();it++){
        delete it->second;
    }
  }
 Student  &NadjiStudenta(int br){
      if(studenti.find(br)!=studenti.end())throw std::domain_error{"Student s tim indeksom vec postoji"};
      return *studenti[br];
 }

 Administracija &operator =(const Administracija &a){
     
       for(auto it(a.studenti.begin());it!=a.studenti.end();it++){
        studenti[it->first]=new Student(*(it->second));
    }
     for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++){
        laptopi[it->first]=new Laptop(it->second->ev_broj,it->second->naziv,it->second->karakteristike);
    }
 }
 Administracija &operator =(Administracija &&a){
     
       for(auto it(a.studenti.begin());it!=a.studenti.end();it++){
        studenti[it->first]=new Student(*(it->second));
    }
     for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++){
        laptopi[it->first]=new Laptop(it->second->ev_broj,it->second->naziv,it->second->karakteristike);
    }
 }
 Administracija (){
 }
 Administracija (const Administracija &a){
     
       for(auto it(a.studenti.begin());it!=a.studenti.end();it++){
        studenti[it->first]=new Student(*(it->second));
    }
     for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++){
        laptopi[it->first]=new Laptop(it->second->ev_broj,it->second->naziv,it->second->karakteristike);
    }
 }
 Laptop NadjiLaptop(int br){
     if(laptopi.find(br)!=laptopi.end())throw std::domain_error{"Laptop nije nadjen"};
      return *laptopi[br];
 }
 void IzlistajStudente(){
     for(auto it(studenti.begin());it!=studenti.end();it++){
        it->second->Ispisi();
        std::cout  << std::endl;
    }
 }
 void IzlistajLaptope(){
     for(auto it(laptopi.begin());it!=laptopi.end();it++){
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen())std::cout << "Zaduzio(la): "<<it->second->kod_koga_je->name<<"("<<it->second->kod_koga_je->index<<")" << std::endl;
        std::cout  << std::endl;
    }
 }
 int NadjiSlobodniLaptop(){
     for(auto it(laptopi.begin());it!=laptopi.end();it++){
       if(it->second->kod_koga_je==nullptr)return it->second->ev_broj;
    }
    throw std::domain_error{"Nema slobodnih laptopa"};
 }
 void RazduziLaptop(int br){
     if(laptopi.find(br)==laptopi.end())throw std::domain_error {"Laptop nije nadjen"};
     if(laptopi.find(br)->second->kod_koga_je==nullptr)throw std::domain_error{"Laptop nije zaduzen"};
     laptopi.find(br)->second->kod_koga_je=nullptr;
 }
 void PrikaziZaduzenja(){
     auto it(laptopi.begin());
     for( it=laptopi.begin();it!=laptopi.end();it++){
      if(it->second->kod_koga_je!=nullptr)break;
    }
    if(it==laptopi.end())std::cout<<"Nema zaduzenja\n";
    for( it=laptopi.begin();it!=laptopi.end();it++){
      std::cout << "Student "<<it->second->kod_koga_je->name<<"("<<it->second->kod_koga_je->index<<") zaduzio/la laptop broj "<<it->second->ev_broj << std::endl;
    }
 }
 void ZaduziLaptop(int st,int lp){
     if(studenti.find(st)==studenti.end())throw std::domain_error {"Student nije nadjen"};
     if(laptopi.find(lp)==laptopi.end())throw std::domain_error {"Laptop nije nadjen"};
     if(laptopi.find(lp)->second->DaLiJeZaduzen())throw std::domain_error{"Laptop vec zaduzen"};
     if(laptopi.find(st)!=laptopi.end())throw std::domain_error{"Student je vec zaduzio laptop"};
    
     laptopi[lp]->kod_koga_je=studenti[st];
 }
    
};
int main (){
   
   Administracija a;
   
   while (1){
    std::cout << "1 za unosenje laptopa | 2 za unosenje studenta | 0 za izlaz!  |  3 za prikazivanje zaduzenja  |  4 za ispisivanje studenta  |  5 za ispisivanje laptopa  | 6 za zaduzivanje |  7 ako zelite naci slobodan laptop | 8 za razduzivanje" << std::endl;
    int n;
    std::cin>>n;
    if(n==0){std::cout << "Dodjite nam opet" << std::endl;break;}
    if(n==1){
        int br;std::string ime;std::string kara;
        std::cout<<"Unesite evidencijski broj laptopa\n";
        std::cin>>br;
        std::cout << "Unesite naziv laptopa" << std::endl;
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,ime);
        std::cout << "Unesite karakteristike laptopa" << std::endl;
         
        std::getline(std::cin,kara);
        try{
            a.RegistrirajNoviLaptop(br,ime,kara);
        }catch(std::domain_error er){
            std::cout<<er.what();
        }
    }
    if(n==2){
        int br;std::string ime;std::string kara;std::string tel;std::string godina;
        std::cout <<"Unesite index studenta"<< std::endl;
        std::cin>>br;
        std::cout << "Unesite godinu studiranja studenta" << std::endl;
         std::cin.ignore(1000,'\n');
        std::getline(std::cin,godina);
        std::cout << "Unesite ime i prezime studenta" << std::endl;
        
        std::getline(std::cin,ime);
        std::cout << "Unesite adresu stanovanja studenta" << std::endl;
        
        std::getline(std::cin,kara);
        std::cout << "Unesite telefon studenta" << std::endl;
         
        std::getline(std::cin,tel);
        try{
            a.RegistrirajNovogStudenta(br,godina,ime,kara,tel);
        }catch(std::domain_error er){
            std::cout<<er.what();
        }
    }
    if(n==3){
        a.PrikaziZaduzenja();
    }if(n==4){
        a.IzlistajStudente();
    }if(n==5){
        a.IzlistajLaptope();
    }
    if(n==6){
        std::cout << "Unesite index studenta koji zeli zaduziti laptop i laptop koji zelite zaduziti" << std::endl;
        int lp,st;
        std::cin>>st>>lp;
        try{
        a.ZaduziLaptop(st,lp);
        }catch(std::domain_error er){
            std::cout << er.what() << std::endl;
        }
    }if(n==7){
        try{
        std::cout << "Prvi slobodan laptop je sa evidencijskim brojem "<<a.NadjiSlobodniLaptop() << std::endl;
        }catch(std::domain_error er){
            std::cout << er.what() << std::endl;
        }
    }
    if(n==8){
        std::cout << "Unesite laptop koji zelite razduziti"<< std::endl;
        int sdasd;
        std::cin>>sdasd;
        try{
            a.RazduziLaptop(sdasd);
        }catch(std::domain_error er){
            std::cout<<er.what();
        }
    }
       
   }
  
	return 0;
}
