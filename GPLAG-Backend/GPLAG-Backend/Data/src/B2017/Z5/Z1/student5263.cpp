/B2017/2018: Zadaća 5, Zadatak 1
//
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#include <algorithm>
class Student{
    int broj_indeksa;
    std::string godina_studija;
    std::string ime_prezime;
    std::string adresa;
    std::string broj_telefona;
    static bool DaLiJePetocifren(int broj){
        int brojac(0);
        while(broj%10!=0){
            broj/=10;
            brojac++;
        }
        return (brojac==5);
    }
    static bool DaLiJeIspravnaGodinaStudija(std::string s){
        if(s.size()>3 || s.size()==0) return false;
        if(s.size()==3 && s[1]=='/' && (s[0]=='1' || s[0]=='2' || s[0]=='3') && (s[2]=='B' || s[2]=='M' || s[2]=='D')) return true;
        if(s.size()==1 && (s[0]=='1' || s[0]=='2' || s[0]=='3')) return true;
        return false;
    }
    void FilterRazmaka(std::string &Str){
    char Ch=' ';
    std::string out;
    bool first = true;
    bool space = false;
    for (std::string::const_iterator it = Str.begin(); it != Str.end(); ++it)
    {
        if (*it == ' ')
        {
            if (first == false)
            {
                space = true;
            }
        }
        else if (*it != Ch)
        {
            if (space)
            {
                out.push_back(' ');
            }
            out.push_back(*it);
            space = false;
            first = false;
        }
        else
        {
            space = false;
        }
    }
     Str=out;
    }
    static bool DaLiJeBrojTelefona(std::string broj){
        std::vector<int> znakovi(2);
        for(int i=0; i<broj.size(); i++){
            if(broj[i]=='-' && znakovi[0]==0) break;
            if(broj[i]=='/') znakovi[0]++;
            if(broj[i]=='-') znakovi[1]++;
        }
        if(znakovi[0]==1 && znakovi[1]==1) return true;
        return false;
    }
    public:
    Student(int broj_indeksa, std::string godina_studija, std::string ime_prezime, std::string adresa, std::string broj_telefona):
    broj_indeksa(broj_indeksa), godina_studija(godina_studija),broj_telefona(broj_telefona){
        if(DaLiJePetocifren(broj_indeksa)==false) throw std::domain_error("Neispravni parametri");
        if(DaLiJeIspravnaGodinaStudija(godina_studija)==false) throw std::domain_error("Neispravni parametri");
        if(DaLiJeBrojTelefona(broj_telefona)==false) throw std::domain_error("Neispravni parametri");
        if(godina_studija.size()==0 || ime_prezime.size()==0 || adresa.size()==0 || broj_telefona.size()==0) throw std::domain_error("Neispravni parametri");
        FilterRazmaka(ime_prezime); FilterRazmaka(adresa);
        Student::ime_prezime=ime_prezime;
        Student::adresa=adresa;
    }
    int DajIndeks()const{
        return broj_indeksa;
    }
    std::string DajGodinuStudija()const{
        std::string s(godina_studija);
        if(s.size()==1 && (s[0]=='1' || s[0]=='2' || s[0]=='3')) s.push_back('/'), s.push_back('B');
        return s;
    }
    std::string DajImePrezime()const{
        return ime_prezime;
    }
    std::string DajAdresu()const{
        return adresa;
    }
    std::string DajTelefon()const{
        return broj_telefona;
    }
    void Ispisi()const{
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl
        <<"Godina studija: "<<DajGodinuStudija()<<std::endl
        <<"Ime i prezime: "<<DajImePrezime()<<std::endl
        <<"Adresa: "<<DajAdresu()<<std::endl
        <<"Telefon: "<<DajTelefon()<<std::endl;
    }
    
};
class Laptop{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *kod_koga_je=nullptr;
    public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike):ev_broj(ev_broj),naziv(naziv),karakteristike(karakteristike){
        if(ev_broj<0 || naziv.size()==0 || karakteristike.size()==0) throw std::domain_error("Neispravni parametri");
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj()const{
        return ev_broj;
    }
    std::string DajNaziv()const{
        return naziv;
    }
    std::string DajKarakteristike()const{
        return karakteristike;
    }
    void Zaduzi(Student &student){
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&student;
    }
    void Razduzi(){
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen(){
        return kod_koga_je;
    }
    Student *DajKodKogaJe(){
        if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return kod_koga_je;
    }
    Student *DajPokKodKogaJe(){
        return kod_koga_je;
    }
    void Ispisi(){
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl
        <<"Naziv: "<<DajNaziv()<<std::endl
        <<"Karakteristike: "<<DajKarakteristike()<<std::endl;
    }
};
class Administracija{
    std::map<int, Student*> mapa_studenta;
    std::map<int, Laptop*> mapa_laptopa;
    public:
    Administracija(){}
    ~Administracija(){
        for(auto &x : mapa_studenta) delete x.second;
        for(auto &x : mapa_laptopa) delete x.second;
    }
    Administracija(const Administracija &admin){
        for(auto &x : admin.mapa_studenta) mapa_studenta[x.first]=new Student(*(x.second));
        for(auto &x : admin.mapa_laptopa) mapa_laptopa[x.first]=new Laptop(*(x.second));
        for(auto &x : admin.mapa_laptopa) (*(mapa_laptopa[x.first])).Razduzi();
    }
    Administracija(Administracija &&admin){
        for(auto &x : admin.mapa_studenta){
            mapa_studenta[x.first]=x.second;
            x.second=nullptr;
        }
        for(auto &x : admin.mapa_laptopa){
            mapa_laptopa[x.first]=x.second;
            x.second=nullptr;
        }
    }
    Administracija &operator =(const Administracija &admin){
        if(this!=&admin){
            for(auto &x : admin.mapa_studenta){
                delete mapa_studenta[x.first];
                mapa_studenta[x.first]=new Student (*(x.second));
            }
            for(auto &x : admin.mapa_laptopa){
                delete mapa_laptopa[x.first];
                mapa_laptopa[x.first]=new Laptop (*(x.second));
                (*(mapa_laptopa[x.first])).Razduzi();
            }
        }
        return *this;
    }
    Administracija &operator =(Administracija &&admin){
            for(auto &x : admin.mapa_studenta){
                delete mapa_studenta[x.first];
                mapa_studenta[x.first]=x.second;
                x.second=nullptr;
            }
            for(auto &x : admin.mapa_laptopa){
                delete mapa_laptopa[x.first];
                mapa_laptopa[x.first]=x.second;
                x.second=nullptr;
            }
        return *this;
    }
    void RegistrirajNovogStudenta(int broj_indeksa, std::string godina_studija, std::string ime_prezime, std::string adresa, std::string broj_telefona){
        if(mapa_studenta.find(broj_indeksa)!=std::end(mapa_studenta)) throw std::domain_error("Student s tim indeksom vec postoji");
        mapa_studenta[broj_indeksa]=new Student (broj_indeksa,godina_studija,ime_prezime,adresa,broj_telefona);
    }
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike){
        if(mapa_laptopa.find(ev_broj)!=std::end(mapa_laptopa)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        mapa_laptopa[ev_broj]=new Laptop (ev_broj,naziv,karakteristike);
    }
    Student &NadjiStudenta(int broj_indeksa){
        auto it(mapa_studenta.find(broj_indeksa));
        if(it==std::end(mapa_studenta)) throw std::domain_error("Student nije nadjen");
        return *((*it).second);
    }
    Student NadjiStudenta(int broj_indeksa)const{
        auto it(mapa_studenta.find(broj_indeksa));
        if(it==std::end(mapa_studenta)) throw std::domain_error("Student nije nadjen");
        Student s=(*(*it).second);
        return s;
    }
    Laptop &NadjiLaptop(int ev_broj){
        auto it(mapa_laptopa.find(ev_broj));
        if(it==std::end(mapa_laptopa)) throw std::domain_error("Laptop nije nadjen");
        return *((*it).second);
    }
    Laptop NadjiLaptop(int ev_broj)const{
        auto it(mapa_laptopa.find(ev_broj));
        if(it==std::end(mapa_laptopa)) throw std::domain_error("Laptop nije nadjen");
        Laptop l=*((*it).second);
        return l;
    }
    void IzlistajStudente()const{
        std::for_each(std::begin(mapa_studenta),std::end(mapa_studenta),[](std::pair<int,Student*> student){
            (student.second)->Ispisi();
            std::cout << std::endl;
        });
    }
    void IzlistajLaptope()const{
        std::for_each(std::begin(mapa_laptopa),std::end(mapa_laptopa),[](std::pair<int,Laptop*> laptop){
            (laptop.second)->Ispisi();
            if((laptop.second)->DaLiJeZaduzen()) std::cout<<"Zaduzio(la): "<<laptop.second->DajKodKogaJe()->DajImePrezime()<<" ("<<laptop.second->DajKodKogaJe()->DajIndeks()<<")";
            std::cout << std::endl;
        });
    }
    void ZaduziLaptop(int broj_indeksa, int ev_broj){
        auto it1(mapa_studenta.find(broj_indeksa));
        if(it1==std::end(mapa_studenta)) throw std::domain_error("Student nije nadjen");
        auto it(mapa_laptopa.find(ev_broj));
        if(it==std::end(mapa_laptopa)) throw std::domain_error("Laptop nije nadjen");
        if(NadjiLaptop(ev_broj).DaLiJeZaduzen()==true) throw std::domain_error("Laptop vec zaduzen");
        for(auto &laptop : mapa_laptopa){
            Student *st=(laptop.second)->DajPokKodKogaJe();
            if(st==(*it1).second) throw std::domain_error("Student je vec zaduzio laptop");
            //if((laptop.second)->DajPokKodKogaJe()==nullptr){ brojac++; continue;}
        }
        //if(brojac==0) throw std::domain_error("Student je vec zaduzio laptop");
        NadjiLaptop(ev_broj).Zaduzi(NadjiStudenta(broj_indeksa));
    }
    int NadjiSlobodniLaptop(){
        for(auto &laptop: mapa_laptopa) if((laptop.second)->DaLiJeZaduzen()==false) return laptop.first;
        throw std::domain_error("Nema slobodnih laptopa");
    }
    void RazduziLaptop(int ev_broj){
        auto it(mapa_laptopa.find(ev_broj));
        if(it==std::end(mapa_laptopa)) throw std::domain_error("Laptop nije nadjen");
        if(NadjiLaptop(ev_broj).DaLiJeZaduzen()==false) throw std::domain_error("Laptop nije zaduzen");
        NadjiLaptop(ev_broj).Razduzi();
    }
    void PrikaziZaduzenja()const{
        std::for_each(std::begin(mapa_laptopa),std::end(mapa_laptopa),[](std::pair<int,Laptop*> laptop){
            if((laptop.second)->DaLiJeZaduzen())std::cout<<"Student "<<laptop.second->DajKodKogaJe()->DajImePrezime()<<" ("<<laptop.second->DajKodKogaJe()->DajIndeks()<<") zaduzio/la laptop broj "<<laptop.second->DajEvidencijskiBroj()<<std::endl;
        });
        int broj_zaduzenja(0);
        for(auto &laptop : mapa_laptopa) if((laptop.second)->DaLiJeZaduzen()==false) broj_zaduzenja++;
        if(broj_zaduzenja==mapa_laptopa.size() || mapa_laptopa.size()==0 || mapa_studenta.size()==0) throw std::domain_error("Nema zaduzenja");
    }
};
int main ()
{
    try{
    Student s(12535,"1","     hlk kk                     ksjkdjksajkjsjk  hhhh     ","hdhdh","122/533-6");
    s.Ispisi();
    Laptop l(724,"ASUS x554l","Intel CPU 2.4 GHz, 8 GB RAM ");
    l.Ispisi();
    Administracija adm;
    adm.RegistrirajNovogStudenta(66666,"1/M","Azrail Zanovetak","Ulica smrti i strave 1", "000/000-000");
    adm.RegistrirajNovogStudenta(99999,"1/D","Lucifer Sunovrat","Ulica smrti i strave 2", "000/000-001");
    adm.RegistrirajNovogStudenta(11111,"2/B","Bajazit Lajka","Turskih sultana 3", "000/000-002");
    adm.RegistrirajNoviLaptop(724,"ASUS x554l","Intel CPU 2.4 GHz, 8 GB RAM ");
    adm.RegistrirajNoviLaptop(728,"ASUS x554l","Intel CPU 2.4 GHz, 2 GB RAM ");
    adm.RegistrirajNoviLaptop(723,"ASUS x554l","Intel CPU 2.4 GHz, 6 GB RAM ");
    adm.RegistrirajNoviLaptop(725,"ASUS x554l","Intel CPU 2.4 GHz, 4 GB RAM ");
    adm.ZaduziLaptop(11111,724);
    adm.IzlistajStudente();
    adm.PrikaziZaduzenja();
    adm.ZaduziLaptop(66666,728);
    adm.PrikaziZaduzenja();
    }catch(std::domain_error Izuzetak){
        std::cout<<Izuzetak.what();
    }
    
    
	return 0;
}
