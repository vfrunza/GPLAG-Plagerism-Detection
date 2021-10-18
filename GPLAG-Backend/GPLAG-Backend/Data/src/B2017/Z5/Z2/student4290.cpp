/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>
#include <memory>
class Student
{
    std::string ime_prezime,adresa,broj_telefona;
    int broj_indeksa;
    std::string godina_studija;
    std::vector<std::string>v {"1","2","3","1/B","2/B","3/B","1/M","2/M","3/M","1/D","2/D","3/D"};
public:
    Student(int index,std::string gs,std::string i_p,std::string a,std::string tel) {
        int i;
        for( i=0; i<v.size(); i++) {
            if(gs==v.at(i)) break;
        }
        if(i==v.size()) throw std::domain_error("Neispravni parametri");
        int pomocna(index),broj_cifara(0);
        while (pomocna!=0) {
            pomocna/=10;
            broj_cifara++;
        }
        if(broj_cifara!=5) throw std::domain_error("Neispravni parametri");
        std::string s1,s2,s3,s4,s5,dodatak;
        bool b1(true),b3(false),b5(false);
        for(int i(0); i<tel.length(); i++) {
            if((tel[i]>='0'&&tel[i]<='9')&&b1) s1.push_back(tel[i]),b3=false,b5=false;
            if(tel[i]=='/') s2.push_back(tel[i]), b1=false, b3=true;
            if((tel[i]>='0'&&tel[i]<='9')&&b3) s3.push_back(tel[i]),b5=false;
            if(tel[i]=='-') s4.push_back('-'), b5=true,b3=false;
            if((tel[i]>='0'&&tel[i]<='9')&&b5)s5.push_back(tel[i]);
            if((tel[i]<'0'||tel[i]>'9')&&tel[i]!='/'&&tel[i]!='-') dodatak.push_back(tel.at(i));
        }
        if(dodatak.length()!=0||s1+s2+s3+s4+s5!=tel) throw std::domain_error("Neispravni parametri");
        if(s1.length()==0||s2.length()==0||s3.length()==0||s4.length()==0||s5.length()==0||s2.length()>1||s4.length()>1)
            throw std::domain_error("Neispravni parametri");
        broj_indeksa=index;
        godina_studija=gs;
        adresa=a;
        ime_prezime=i_p ;
        broj_telefona=tel;
    }
    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {
        std::string gs(godina_studija);
        if(godina_studija==v.at(0)) gs=v.at(3);
        else if(godina_studija==v.at(1)) gs=v.at(4);
        else if(godina_studija==v.at(2)) gs=v.at(5);
        return gs;
    }
    std::string DajImePrezime() const {
        std::string novi,ime_prezime1(ime_prezime);
        bool t(false);
        for(int i(ime_prezime1.size()-1); i>=0; i--) {
            if(ime_prezime1[i]==' ') ime_prezime1.erase(ime_prezime1.begin()+i);
            else break;
        }
        for(int i(0); i<ime_prezime1.length(); i++) {
            if(ime_prezime1[i]!=' ') {
                novi.push_back(ime_prezime1[i]);
                t=true;
            } else {
                if(t) novi.push_back(' '), t=false;
            }
        }
        return novi;
    }
    std::string DajAdresu() const {
        std::string nova,adresa1(adresa);
        bool t(false);
        for(int i(adresa1.size()-1); i>=0; i--) {
            if(adresa1[i]==' ') adresa1.erase(adresa1.begin()+i);
            else break;
        }
        for(int i(0); i<adresa1.length(); i++) {
            if(adresa1[i]!=' ') {
                nova.push_back(adresa1[i]);
                t=true;
            } else {
                if(t) nova.push_back(' '), t=false;
            }
        }
        return nova;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }
    void Ispisi() const {
        std::cout << "Broj indeksa: "<<this->DajIndeks() << std::endl;
        std::cout << "Godina studija: "<<this->DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " <<this->DajImePrezime()<< std::endl;
        std::cout << "Adresa: " <<this->DajAdresu()<< std::endl;
        std::cout << "Telefon: " <<this->DajTelefon()<< std::endl;
    }
    friend class Laptop;
    friend class Administracija;
};
class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    std::shared_ptr<Student>kod_koga_je;
public:
    Laptop(int b,std::string n,std::string k) {
        kod_koga_je = nullptr ;
        if(b<0) throw std::domain_error("Neispravni parametri");
        ev_broj=b;
        naziv=n;
        karakteristike=k;
    }
    int DajEvidencijskiBroj() const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike() const {
        return karakteristike;
    }
    void Zaduzi(Student &s) {
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        *kod_koga_je=s;
    }
    void Razduzi() {
        if(kod_koga_je!=nullptr) kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() const {
        if(kod_koga_je!=nullptr) return true;
        return false;
    }
    Student &DajKodKogaJe() const {
        if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        else
            return *kod_koga_je;
    }
    std::shared_ptr<Student>DajPokKodKogaJe() const {
        if(kod_koga_je == nullptr) return nullptr;
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout << "Evidencijski broj: "<<ev_broj << std::endl;
        std::cout << "Naziv: "<<naziv << std::endl;
        std::cout << "Karakteristike: "<<karakteristike << std::endl;
    }

};
class Administracija
{
    std::map< int, std::shared_ptr<Student>>studenti;
    std::map< int, std::shared_ptr<Laptop>>laptopi;
public:
    Administracija() {}
    Administracija(const Administracija &a) {
        for(auto it(a.studenti.begin());it!=a.studenti.end();it++) {
           auto s=std::make_shared<Student>(*(it->second));
           studenti.insert({it->first,s});
        }
        for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++) {
           auto l=std::make_shared<Laptop>(*(it->second));
           laptopi.insert({it->first,l});
        }
        
    }
    Administracija(Administracija&&a) {
        studenti=a.studenti;
        laptopi=a.laptopi;
    }
    Administracija &operator = (const Administracija &a) {
           for(auto it(a.studenti.begin());it!=a.studenti.end();it++) {
           auto s=std::make_shared<Student>(*(it->second));
           studenti.insert({it->first,s});
        }
        for(auto it(a.laptopi.begin());it!=a.laptopi.end();it++) {
           auto l=std::make_shared<Laptop>(*(it->second));
           laptopi.insert({it->first,l});
        }
    }
    Administracija &operator = (Administracija &&a);
    void RegistrirajNovogStudenta(int b_i,std::string g_s,std::string i_p,std::string a_s,std::string b_t ) {
        for(auto x : studenti) {
            if(x.first==b_i) throw std::domain_error("Student s tim indeksom vec postoji");
        }
        try {
            auto s=std::make_shared<Student>(b_i,g_s,i_p,a_s,b_t);
            studenti.insert({b_i,s});
        } catch(...) {
            throw;
        }
    }
    void RegistrirajNoviLaptop(int e_b,std::string n_l,std::string k_l) {
        for(auto x : laptopi) if(x.first==e_b) throw std::domain_error("Laptop sa tim evidencijskom brojem vec postoji");
        auto l=std::make_shared<Laptop>(e_b,n_l,k_l);
        laptopi.insert({e_b,l});
    }
    Student &NadjiStudenta(int index) const {
        for(auto x: studenti)
            if(x.first==index) return *x.second;
        throw std::domain_error("Student nije nadjen");
    }
    Laptop &NadjiLaptop(int ev_broj) {
        for(auto x : laptopi)
            if(x.first==ev_broj) return *x.second;
        throw std::domain_error("Laptop nije nadjen");
    }
    void IzlistajStudente() const {
        for(auto x : studenti) {
            (x.second)->Ispisi();
            std::cout  << std::endl;
        }
    }
    void IzlistajLaptope() const {

        for(auto x : laptopi) {
            (x.second)->Ispisi();
            if(x.second->DaLiJeZaduzen())
                std::cout << "Zaduzio(la): "<<(x.second->DajKodKogaJe()).DajImePrezime()<<" ("<<(x.second->DajKodKogaJe().DajIndeks())<<")"<<std::endl;;
            std::cout  << std::endl;
        }
    }
    void ZaduziLaptop(int index,int e_broj) {
        auto it(studenti.find(index));
        if(it==studenti.end()) throw std::domain_error("Student nije nadjen");
        auto it1(laptopi.find(e_broj));
        if(it1==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        if((it1->second)->DajPokKodKogaJe()!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        for(auto x: laptopi) {
            if((x.second)->DajPokKodKogaJe()==it->second)
                throw std::domain_error("Student je vec zaduzio laptop");
        }
        ((it1->second)->Zaduzi(*it->second));
    }
    int NadjiSlobodneLaptope() const {
        for(auto x : laptopi)
            if((x.second)->DajPokKodKogaJe()==nullptr) return x.first;
        throw std::domain_error("Laptop nije nadjen");
    }
    void RazduziLaptop(int e_broj) {
        bool kraj(false);
        auto it(laptopi.find(e_broj));
        if(it==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        for(auto x : laptopi) {
            if((x.first)==e_broj&&(x.second)->DaLiJeZaduzen())  {
                x.second->Razduzi();
                kraj=true;
            }
        }
        if(!kraj) throw std::domain_error("Laptop nije zaduzen");
    }
    void PrikaziZaduzenja() const {
        int brojac(0);
        for(auto x : laptopi)
            if((x.second)->DajPokKodKogaJe()!=nullptr) brojac++;
        if(brojac!=0) {
            for(auto x: laptopi)
                if((x.second)->DajPokKodKogaJe()!=nullptr) {
                    std::cout << "Student "<<(x.second)->DajPokKodKogaJe()->ime_prezime<<" ("<<(x.second)->DajPokKodKogaJe()->broj_indeksa<<")"
                              <<" zaduzio/la laptop broj "<<x.first <<std::endl;
                }
        }
        else std::cout << "Nema zaduzenja" << std::endl;
    }
};
int main ()
{
    try {
        int izbor;
    do {
        Administracija a;
        std::cout << "Odaberite jednu od sljedecih opcija: " << std::endl;
        std::cout << "1 - Registriraj novog studenta\n2 - Registriraj novi laptop\n3 - Ispisi studente\n4 - Ispisi laptope" << std::endl;
        std::cout << "5 - Zaduzi laptop\n6 - Razduzi laptop\n7 - PrikaziZaduzenja" << std::endl;
        std::cin >> izbor;
     if(izbor==1) {
         std::string i_p,b_t,a_s,g_s;
         int b_i;
      std::cout << "Unesite broj indeksa: " << std::endl;   
      std::cin >> b_i;
      std::cout << "Unesite ime i prezime: " << std::endl;
      std::cin.ignore(1000,'\n');
      std::getline(std::cin,i_p);
      std::cout << "Unesite godinu studija: "<< std::endl;
      std::getline(std::cin,g_s);
      std::cout << "Unesite adresu stanovanja: " << std::endl;
      std::getline(std::cin,a_s);
      std::cout << "Unesite broj telefona: " << std::endl;
      std::getline(std::cin,i_p);
      a.RegistrirajNovogStudenta(b_i,g_s,i_p,a_s,b_t);
     }
     if(izbor ==2) {
         int ev_broj;
         std::string naziv,karakteristike;
         std::cout << "Unesite evidencijsi broj laptopa: " << std::endl;
         std::cin >> ev_broj;
         std::cin.ignore(1000,'\n');
         std::cout << "Unesite naziv laptopa: " << std::endl;
         std::getline(std::cin,naziv);
         std::cout << "Unesite karakteristike laptopa: " << std::endl;
         std::getline(std::cin,karakteristike);
         a.RegistrirajNoviLaptop(ev_broj,naziv,karakteristike);
     }
     if(izbor==3) a.IzlistajStudente();
     if(izbor==4) a.IzlistajLaptope();
     if(izbor==5) {
         std::cout << "Unesite broj indeksa studenta koji zeli zaduziti laptop: " << std::endl;
         int i,e_b;
         std::cin >> i;
         std::cout << "Unesite evidencijsi broj laptopa koji ce student zaduziti: " << std::endl;
         std::cin >> e_b;
         a.ZaduziLaptop(i,e_b);
     }
     if(izbor==6) {
         std::cout << "Unesite evidencijsi broj laptopa koji se treba razduziti: " << std::endl;
         int e_b;
         std::cin >> e_b;
         a.RazduziLaptop(e_b);
     }
     if(izbor==7) a.PrikaziZaduzenja();
    }
    while (izbor!=0);  
    } catch(std::domain_error &i) {
        std::cout << i.what() << std::endl;
    }
    return 0;
}
