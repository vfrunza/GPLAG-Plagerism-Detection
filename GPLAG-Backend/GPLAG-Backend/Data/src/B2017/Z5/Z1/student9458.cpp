/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <map>


class Student
{
    
    int index;
    std::string god;
    std::string ime;
    std::string stanovanje;
    std::string telefon;

public:
    Student (int br_indexa,std::string godina,std::string ime_pr, std::string adresa,std::string broj):index(br_indexa),
    god(godina),ime(ime_pr),stanovanje(adresa),telefon(broj){
        
        int k=0;

        int proba=index;
        while(proba!=0) {
            proba=proba/10;
            k++;
        }
        if(k!=5 ) throw std::domain_error("Neispravni parametri");

        std::string s("1/B");
        std::string s1("2/B");
        std::string s2("3/B");
        if(god.size()==1 &&(god[0]=='1' || god[0]=='2'|| god[0]=='3')){
            if(god[0]=='1') god=s;
            if(god[0]=='2') god=s1;
            if(god[0]=='3') god=s2;
        }
        else {
            int a=0;
        if((god[0]=='1' || god[0]=='2'|| god[0]=='3')&&(god[1]=='/') && (god[2]=='M' || god[2]=='B' || god[2]=='D')) a=1;
        else throw std::domain_error("Neispravni parametri");
        }
        
        bool a,b;
        for(int i=0; i<ime.size(); i++) {
            a=true;
            if(i!=0){
            if(((ime[i+1]>='A' && ime[i+1]<='Z') || (ime[i+1]>='a' && ime[i+1]<='z'))&&((ime[i-1]>='A' && ime[i-1]<='Z') || (ime[i-1]>='a' && ime[i-1]<='z')))a=false;
            }
            
                if(ime[i]==' '&& a==true ){
                     for(int j=i; j<ime.size(); j++) {
                         ime[j]=ime[j+1];
            }i--;
                    
                    ime.resize(ime.size()-1);
                }
        }
        int m;
        for(m=0; m<telefon.size(); m++) {
            if(telefon[m]=='/' || telefon[m]=='-' || (telefon[m]>='0' && telefon[m]<='9')) continue;
            else break;
        }
        if(m!=telefon.size()) throw std::domain_error("Neispravni parametri");
      
    }
    int DajIndeks() {
        return index;
    }
    std::string DajGodinuStudija() {
        return god;
    }
    std::string DajImePrezime() {
        return ime;
    }
    std::string DajAdresu() {
        return stanovanje;
    }
    std::string DajTelefon() {
        return telefon;
    }
    void Ispisi() {
        std::cout<<"Broj indeksa: "<<DajIndeks() << std::endl<<
                 "Godina studija: "<<DajGodinuStudija()<<std::endl<<"Ime i prezime: "<<DajImePrezime()<<
                 std::endl<<"Adresa: "<<DajAdresu()<<std::endl<<"Telefon: "<<DajTelefon()<<std::endl;
    }

};
class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *kod_koga_je;
public:
    Laptop(int broj,std::string ime,std::string kar): naziv(ime),karakteristike(kar), kod_koga_je(nullptr) {
        if(broj<0) throw std::domain_error("Neispravni parametri");
        ev_broj=broj;
    }

    int DajEvidencijskiBroj() {
        return ev_broj;
    }
    std::string DajNaziv() {
        return naziv;
    }
    std::string DajKarakteristike() {
        return karakteristike;
    }
    void Zaduzi(Student &s) {
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen") ;
        kod_koga_je=&s;

    }
    void Razduzi() {
        if(kod_koga_je!=nullptr) kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() {
        return !(kod_koga_je==nullptr);
        
    }
Student &DajKodKogaJe(){
    if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen") ;
    return *kod_koga_je;
}
    Student *DajPokKodKogaJe() {
        return kod_koga_je;
    }
    void Ispisi() {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl<<
                 "Naziv: "<<DajNaziv()<<std::endl<<"Karakteristike: "<<DajKarakteristike();
    }

};
class Administracija
{

    std::map<int,Laptop*> laptopi;
    std::map<int,Student*> studenti;
public:
Administracija(){}
~Administracija(){
    for(auto it=laptopi.begin();it!=laptopi.end();it++){
        delete laptopi[it->first];
    }
    for(auto it=studenti.begin();it!=studenti.end();it++){
        delete studenti[it->first];
    }
}
Administracija (const Administracija &a);
Administracija(Administracija &&a):laptopi(a.laptopi),studenti(a.studenti){}
Administracija &operator = (const Administracija &a);
Administracija &operator =(Administracija &&a);
void RegistrirajNovogStudenta(int br_indexa,std::string godina,std::string ime_pr, std::string adresa,std::string broj);
void RegistrirajNoviLaptop(int broj,std::string ime,std::string kar);
Student &NadjiStudenta(int br);
Laptop &NadjiLaptop(int br2);
void IzlistajStudente() const;
void IzlistajLaptope() const;
void ZaduziLaptop( int in,int ev);
void RazduziLaptop(int ev);
void PrikaziZaduzenja()const;


};

Administracija::Administracija (const Administracija &a){
    for(auto it=a.laptopi.begin();it!=a.laptopi.end();it++){
        laptopi[it->first]=new Laptop (*(it->second));
    }
    for(auto it=a.studenti.begin();it!=a.studenti.end();it++){
        studenti[it->first]=new Student (*(it->second));
    }
    
}
Administracija &Administracija::operator = (const Administracija &a){
    for(auto it=a.laptopi.begin();it!=a.laptopi.end();it++){
        laptopi[it->first]=new Laptop (*(it->second));
    }
    for(auto it=a.studenti.begin();it!=a.studenti.end();it++){
        studenti[it->first]=new Student (*(it->second));
    }
    return *this;
}
Administracija &Administracija::operator =(Administracija &&a){
    laptopi=a.laptopi;
    studenti=a.studenti;
    return *this;
}
void Administracija::RegistrirajNovogStudenta(int br_indexa,std::string godina,std::string ime_pr, std::string adresa,std::string broj){
    if(studenti.count(br_indexa)) throw std::domain_error("Student s tim indeksom vec postoji");
    Student s(br_indexa,godina,ime_pr,adresa,broj);
    s.DajGodinuStudija()=godina;
    s.DajImePrezime()=ime_pr;
    s.DajAdresu()=adresa;
    s.DajTelefon()=broj;
    studenti[br_indexa]=new Student(s);
}
void Administracija::RegistrirajNoviLaptop(int broj,std::string ime,std::string kar){
    if(laptopi.count(broj)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi[broj]=new Laptop(broj,ime,kar);
    
}
Student &Administracija::NadjiStudenta(int br){
    if(!studenti.count(br)) throw std::domain_error("Student nije nadjen");
    return *studenti[br];
}
Laptop &Administracija::NadjiLaptop(int br2){
    if(!laptopi.count(br2)) throw std::domain_error("Laptop nije nadjen");
    return *laptopi[br2];
}
void Administracija::IzlistajStudente() const{//JEL TREBASSS SVE ISPISATII!!!!!!!

    for(auto it=studenti.begin();it!=studenti.end();it++){
       std::cout<<"Broj indeksa: "<<it->first<< std::endl<<
                 "Godina studija: "<<(it->second)->DajGodinuStudija()<<std::endl<<"Ime i prezime: "<<(it->second)->DajImePrezime()<<
                 std::endl<<"Adresa: "<<(it->second)->DajAdresu()<<std::endl<<"Telefon: "<<(it->second)->DajTelefon()<<std::endl<<std::endl;
    }
}
void Administracija::IzlistajLaptope() const{//JEL TREBASSS SVE ISPISATII!!!!!!!
bool a=true;
    for(auto it=laptopi.begin();it!=laptopi.end();it++){
       
       
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<
                 "Naziv: "<<(it->second)->DajNaziv()<<std::endl<<"Karakteristike: "<<(it->second)->DajKarakteristike()<<std::endl;
       if((it->second)->DaLiJeZaduzen()){
           Student s((it->second)->DajKodKogaJe());
           std::cout<<"Zaduzio(la): "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<")"<<std::endl<<std::endl;
          a =false;
       }
       if(a==true) std::cout<<std::endl;
    }
}
void Administracija::ZaduziLaptop( int in,int ev){
    if(!laptopi.count(ev)) throw std::domain_error("Laptop nije nadjen");
    if(!studenti.count(in)) throw std::domain_error("Student nije nadjen");
    if(laptopi[ev]->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    //fali jos jedan izuzetak
    
    laptopi[ev]->Zaduzi(*studenti[in]);
}
void Administracija::RazduziLaptop(int ev){
    if(!laptopi.count(ev)) throw std::domain_error("Laptop nije nadjen");
    if(!laptopi[ev]->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    laptopi[ev]->Razduzi();
}
void Administracija::PrikaziZaduzenja()const{
    int i=0;
    for(auto it=laptopi.begin();it!=laptopi.end();it++){
       
        if((it->second)->DaLiJeZaduzen()){
             Student s((it->second)->DajKodKogaJe());
            std::cout<<"Student "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<") zaduzio/la laptop broj "<<it->first<<std::endl;
            i++;
        }
    }
    if(i==0) std::cout<<"Nema zaduzenja";
}


int main ()
{
try{
    Administracija a;
    a.RegistrirajNovogStudenta(12345,"1/B","Azra Ka","Josipa","062/330-987");
    a.RegistrirajNoviLaptop(2,"Je","d569");
    a.ZaduziLaptop(12345,2);
    a.IzlistajLaptope();
    a.IzlistajStudente();
    
}
catch(std::domain_error iu){
    std::cout << iu.what();
}

    return 0;
}
