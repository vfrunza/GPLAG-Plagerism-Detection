/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <type_traits>
#include <vector>

class Student
{
    int indeks;
    std::string GodinaStudija, ImePrezime, Adresa, BrojTelefona;
    
    bool IspravanIndeks(int indeks)
    {
        int brojac(0);
        while(indeks != 0) { indeks = indeks/10; brojac++; }
        if (brojac == 5) return true;
        return false;
    };
    bool IspravnaGodinaStudija(std::string s)
    {
        std::vector<std::string> v{"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "3/M", "1/D", "2/D", "3/D"};
        auto it(s.begin());
            std::string pomocni;
            while(it != s.end() && *it == ' ') it++;
            while(it != s.end() && *it != ' ') pomocni += *it++;
            while(it != s.end() && *it == ' ') it++;
            if(it != s.end()) return false;
        for(auto it(v.begin()); it != v.end(); it++) if(*it == pomocni) return true;
        return false;
    };
    bool IspravanBrTelefona(std::string Tel)
    {
        auto it(Tel.begin());
        while(it != Tel.end() && *it == ' ') it++;
        while(it != Tel.end() && *it >= '0' && *it <= '9') it++;
        if(it != Tel.end() && *it == '/') it++;
        else return false;
        while(it != Tel.end() && *it >= '0' && *it <= '9') it++;
        if(it != Tel.end() && *it == '-') it++;
        else return false;
        while(it != Tel.end() && *it >= '0' && *it <= '9') it++;
        if(it != Tel.end()) return false;
        return true;
    };
    std::string NapraviImePrez(std::string ImePrez)
    {
        auto it(ImePrez.begin());
        std:: string pomocni;
        while(it != ImePrez.end())
        {
            while(it != ImePrez.end() && *it == ' ') it++;
            while(it != ImePrez.end() && *it != ' ') pomocni += *it++;
            while(it != ImePrez.end() && *it == ' ') it++;
                if(it != ImePrez.end()) pomocni += ' '; 
                else return pomocni;
        }
        return pomocni;
    };
    public:
    
    Student(int indeks, std::string GodStud, std::string ImePrez, std::string Adr, std::string BrojTel)
    {
        if(!(IspravanIndeks(indeks) && IspravnaGodinaStudija(GodStud) && IspravanBrTelefona(BrojTel))) throw std::domain_error("Neispravni parametri\n");
       
        Student::indeks = indeks;
        GodinaStudija = GodStud;
        ImePrezime = NapraviImePrez(ImePrez);
        Adresa = NapraviImePrez(Adr);
        BrojTelefona = BrojTel;
    };
    
    int DajIndeks() const { return indeks; };
    std::string DajGodinuStudija() const 
    {
        if (GodinaStudija == "1") return "1/B";
        else if(GodinaStudija == "2") return "2/B";
        else if(GodinaStudija == "3") return "3/B";
        else return GodinaStudija;
    };
    std::string DajImePrezime() const { return ImePrezime; };
    std::string DajAdresu() const { return Adresa; };
    std::string DajTelefon() const { return BrojTelefona; };
    
    void Ispisi() const
    {
        std::cout<<"Broj indeksa: "<<DajIndeks()<<"\n";
        std::cout<<"Godina studija: "<<DajGodinuStudija()<<"\n";
        std::cout<<"Ime i prezime: "<<DajImePrezime()<<"\n";
        std::cout<<"Adresa: "<<DajAdresu()<<"\n";
        std::cout<<"Telefon: "<<DajTelefon()<<"\n";
    };
};

class Laptop
{
  int ev_broj;
  std::string naziv, karakteristike;
  Student *kod_koga_je;
  
  public:
  
  Laptop(int broj, std::string naz, std::string kar) : kod_koga_je(nullptr), naziv(naz), karakteristike(kar)
  {
      if (broj < 0) throw std::domain_error("Neispravni parametri\n");
      ev_broj = broj;
  };
  
  int DajEvidencijskiBroj() const { return ev_broj; };
  std::string DajNaziv() const { return naziv; };
  std::string DajKarakteristike() const { return karakteristike; };
  
  void Zaduzi(Student &st)
  {
      if(kod_koga_je != nullptr) throw std::domain_error("Laptop vec zaduzen\n");
      kod_koga_je = &st;
  };
  void Razduzi()
  {
      if(kod_koga_je != nullptr) kod_koga_je = nullptr;
  };
  bool DaLiJeZaduzen()
  {
      if(kod_koga_je != nullptr) return true;
      else return false;
  };
  Student& DajKodKogaJe() const
  {
      if(kod_koga_je == nullptr) throw std::domain_error("Laptop nije zaduzen\n");
      return *kod_koga_je;
  };
  Student* DajPokKodKogaJe() const
  {
      return kod_koga_je;
  };
  void Ispisi() const
  {
      std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<"\n";
      std::cout<<"Naziv: "<<DajNaziv()<<"\n";
      std::cout<<"Karakteristike: "<<DajKarakteristike()<<"\n";
  };
};


class Administracija
{
    std::map<int, Student*> studenti;
    std::map<int, Laptop*> laptopi;
    
    public:
    
    Administracija(){};
    Administracija(const Administracija &a)
    {
        for(auto it(a.studenti.begin()); it != a.studenti.end(); it++)
        {
            studenti.insert(std::make_pair<int, Student*>(std::remove_reference<int&>::type(it->first), new Student(it->first, (it->second)->DajGodinuStudija(), (it->second)->DajImePrezime(), (it->second)->DajAdresu(), (it->second)->DajTelefon())));
        }
        for(auto it1(a.laptopi.begin()); it1 != a.laptopi.end(); it1++)
        {
           
            laptopi.insert(std::make_pair<int, Laptop*>(std::remove_reference<int&>::type(it1->first),  new Laptop(it1->first, (it1->second)->DajNaziv(), (it1->second)->DajKarakteristike())));
        }
    };
    Administracija(Administracija &&a)
    {
        for(auto it(a.studenti.begin()); it != a.studenti.end(); it++)
        {
            Student *s(it->second);
            it->second = nullptr;
            studenti.insert(std::make_pair<int, Student*>(std::remove_reference<int&>::type(s->DajIndeks()), std::remove_reference<Student*&>::type(s)));
            s = nullptr;
        }
        for(auto it1(a.laptopi.begin()); it1 != a.laptopi.end(); it1++)
        {
            Laptop *l(it1->second);
            it1->second = nullptr;
            laptopi.insert(std::make_pair<int, Laptop*>(std::remove_reference<int&>::type(l->DajEvidencijskiBroj()), std::remove_reference<Laptop*&>::type(l)));
            l = nullptr;
        }
    };
    ~Administracija()
    {
        auto it1(studenti.begin());
        auto it2(laptopi.begin());
        while(it1 != studenti.end()) { delete it1->second; it1->second = nullptr; it1++;}
        while(it2 != laptopi.end()) { delete it2->second; it2->second = nullptr; it2++;}
        if(!studenti.empty()) studenti.clear();
        if(!laptopi.empty()) laptopi.clear();
    };
    Administracija &operator =(const Administracija &a)
    {
        auto it1(studenti.begin());
        auto it2(laptopi.begin());
        while(it1++ != studenti.end()) { delete it1->second; it1->second = nullptr; }
        while(it2++ != laptopi.end()) { delete it2->second; it2->second = nullptr; }
            studenti.clear();
            laptopi.clear();
        for(auto it(a.studenti.begin()); it != a.studenti.end(); it++)
        {
        
            studenti.insert(std::make_pair<int, Student*>(std::remove_reference<int&>::type(it->first), new Student(it->first, (it->second)->DajGodinuStudija(), (it->second)->DajImePrezime(), (it->second)->DajAdresu(), (it->second)->DajTelefon())));
            
        }
        for(auto it1(a.laptopi.begin()); it1 != a.laptopi.end(); it1++)
        {
            
            laptopi.insert(std::make_pair<int, Laptop*>(std::remove_reference<int&>::type(it1->first), new Laptop(it1->first, (it1->second)->DajNaziv(), (it1->second)->DajKarakteristike())));
        }    
        return *this;
    };
    Administracija &operator =(Administracija &&a)
    {
        auto it1(studenti.begin());
        auto it2(laptopi.begin());
        while(it1++ != studenti.end()) { delete it1->second; it1->second = nullptr; }
        while(it2++ != laptopi.end()) { delete it2->second; it2->second = nullptr; }
            studenti.clear();
            laptopi.clear();
        for(auto it(a.studenti.begin()); it != a.studenti.end(); it++)
        {
            Student *s(it->second);
            it->second = nullptr;
            studenti.insert(std::make_pair<int, Student*>(std::remove_reference<int&>::type(s->DajIndeks()), std::remove_reference<Student*&>::type(s)));
            s = nullptr;
        }
        for(auto it1(a.laptopi.begin()); it1 != a.laptopi.end(); it1++)
        {
            Laptop *l(it1->second);
            it1->second = nullptr;
            laptopi.insert(std::make_pair<int, Laptop*>(std::remove_reference<int&>::type(l->DajEvidencijskiBroj()), std::remove_reference<Laptop*&>::type(l)));
            l = nullptr;
        }    
        return *this;
    };
    void RegistrirajNovogStudenta(int indeks, std::string GodStud, std::string ImePrez, std::string Adr, std::string BrojTel)
    {
         auto iter(studenti.find(indeks));
         if(iter != studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji\n");
         Student *s = new Student(indeks, GodStud, ImePrez, Adr, BrojTel);
         studenti.insert(std::make_pair<int, Student*>(std::remove_reference<int&>::type(indeks), std::remove_reference<Student*&>::type(s)));
         s = nullptr;
    };
    void RegistrirajNoviLaptop(int broj, std::string naz, std::string kar)
    {
        auto iter(laptopi.find(broj));
        if(iter != laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji\n");
        Laptop *l = new Laptop(broj, naz, kar);
        laptopi.insert(std::make_pair<int, Laptop*>(std::remove_reference<int&>::type(broj), std::remove_reference<Laptop*&>::type(l)));
        l = nullptr;
    };
    Student& NadjiStudenta(int indeks)
    {
        auto iter(studenti.find(indeks));
        if(iter == studenti.end()) throw std::domain_error("Student nije nadjen\n");
        return *(iter->second);
    };
    Student NadjiStudenta(int indeks) const
    {
        auto iter(studenti.find(indeks));
        if(iter == studenti.end()) throw std::domain_error("Student nije nadjen\n");
        Student *s = new Student(iter->second->DajIndeks(), iter->second->DajGodinuStudija(), iter->second->DajImePrezime(), iter->second->DajAdresu(),iter->second->DajTelefon());
        return *s;
    };
    Laptop& NadjiLaptop(int broj)
    {
        auto iter(laptopi.find(broj));
        if(iter == laptopi.end()) throw std::domain_error("Laptop nije nadjen\n");
        return *(iter->second);
    };
    Laptop NadjiLaptop(int broj) const
    {
        auto iter(laptopi.find(broj));
        if(iter == laptopi.end()) throw std::domain_error("Laptop nije nadjen\n");
        Laptop *l = new Laptop(broj, iter->second->DajNaziv(), iter->second->DajKarakteristike());
        return *l;
    };
    void IzlistajStudente() const
    {
        int i(0);
        for(auto it(studenti.begin()); it != studenti.end(); it++, i++)
        {
            (it->second)->Ispisi();
            if(i != 0 && i % 2 == 0) std::cout<<"\n";
        }
    };
    void IzlistajLaptope() const
    {
        int i(0);
        for(auto it(laptopi.begin()); it != laptopi.end(); it++, i++)
        {
            (it->second)->Ispisi();
            if((it->second)->DaLiJeZaduzen()) std::cout<<"Zaduzio(la): "<<(it->second)->DajPokKodKogaJe()->DajImePrezime()<<" ("<<it->second->DajPokKodKogaJe()->DajIndeks()<<")\n";
        }
    };
    void ZaduziLaptop(int indeks, int broj)
    {
        auto iter(studenti.find(indeks));
        if(iter == studenti.end()) throw std::domain_error("Student nije nadjen\n");
        auto iter1(laptopi.find(broj));
        if(iter1 == laptopi.end()) throw std::domain_error("Laptop nije nadjen\n");
        if(iter1->second->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen\n");
        for(auto it(laptopi.begin()); it != laptopi.end(); it++)
        {
           if(it->second->DaLiJeZaduzen()) {if(((it->second)->DajPokKodKogaJe())->DajIndeks() == (iter->second)->DajIndeks()) throw std::domain_error("Student je vec zaduzio laptop\n");}
        }
        iter1->second->Zaduzi(*(iter->second));
    };
    int NadjiSlobodniLaptop()
    {
        auto it(laptopi.begin());
        for(; it != laptopi.end(); it++)
        {
            if(it->second->DaLiJeZaduzen()) continue;
            else break;
        }
        if(it == laptopi.end()) throw std::domain_error("Nema slobodnih laptopa\n");
        return it->second->DajEvidencijskiBroj();
    };
    void RazduziLaptop(int broj)
    {
        auto it(laptopi.find(broj));
        if(it == laptopi.end()) throw std::domain_error("Laptop nije nadjen\n");
        if(!(it->second->DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen\n");
        it->second->Razduzi();
    };
    void PrikaziZaduzenja() const
    {
        int stanje(0);
        for(auto it(laptopi.begin()); it != laptopi.end(); it++)
        {
            if(!(it->second->DaLiJeZaduzen())) stanje = 1;
        }
        if(stanje)
        {
           std::cout<<"Nema zaduzenja\n"; 
        }
        else
        {
        for(auto it(laptopi.begin()); it != laptopi.end(); it++)
        {
            if(it->second->DaLiJeZaduzen())
            {
                std::cout<<"Student "<<(it->second->DajPokKodKogaJe())->DajImePrezime()<<" ("<<(it->second->DajPokKodKogaJe())->DajIndeks()<<") zaduzio(la) laptop broj "<<it->first<<"\n";
            }
        }
        }
    };
};


int main ()
{
   Administracija a;
    while(1)
    {
        std::cout<<"Unesite broj opcije koju zelite izvrsiti: 0-Kraj, 1-Dodaj studenta, 2-Dodaj laptop, 3-Izlistaj laptope, 4-Izlistaj Studente,";
        std::cout<<", 5-Nadji laptop, 6-Nadji studenta, 7-Nadji slobodni laptop, 8-Razduzi laptop, 9-Prikazi zaduzenja, 10-Zaduzi laptop: ";
        int n;
        std::cin>>n;
        switch(n)
        {
            case 1 : 
            {
                std::cout<<"Unesite indeks: ";
                int indeks;
                std::cin>>indeks;
                std::cin.ignore(1000, '\n');
                std::string s, godstd,adresa,tel;
                std::cout<<"Unesite godinu studija: ";
                std::getline(std::cin, godstd);
                std::cout<<"Unesite ime i prezime: ";
                std::getline(std::cin, s);
                std::cout<<"Unesite adresu: ";
                std::getline(std::cin, adresa);
                std::cout<<"Unesite telefon: ";
                std::getline(std::cin, tel);
                try{
                a.RegistrirajNovogStudenta(indeks, godstd, s, adresa, tel);
                }
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 2 :
            {
                std::cout<<"Unesite broj laptopa: ";
                int broj;
                std::cin>>broj;
                std::cin.ignore(1000, '\n');
                std::string naziv, kar;
                std::cout<<"Unesite naziv laptopa: ";
                std::getline(std::cin, naziv);
                std::cout<<"Unesite karakteristike: ";
                std::getline(std::cin, kar);
                try{
                    a.RegistrirajNoviLaptop(broj, naziv, kar);
                }
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 3 :
            {
                 a.IzlistajLaptope(); 
            }
            break;
            
            case 4 : 
            {
                a.IzlistajStudente();
            }
            break;
            
            case 5 :
            {
                std::cout<<"Unesite evidencijski broj laptopa: ";
                int broj;
                std::cin>>broj;
                try{
                std::cout<<"Nadjeni laptop:\n";
                (a.NadjiLaptop(broj)).Ispisi();
                }
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 6 :
            {
                std::cout<<"Unesite broj indeksa studenta: ";
                int broj;
                std::cin>>broj;
                try{
                std::cout<<"Nadjeni student:\n";
                (a.NadjiStudenta(broj)).Ispisi();
                }
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 7 :
            {
                try{
                std::cout<<"Evidencijski broj slobodnog laptopa je: "<<a.NadjiSlobodniLaptop()<<"\n";
                }
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 8 :
            {
                std::cout<<"Unesite evidencijski broj laptopa koji zelite razduziti: ";
                int broj;
                std::cin>>broj;
                try{
                a.RazduziLaptop(broj);
                }
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 9 :
            {
                try{a.PrikaziZaduzenja();}
                catch(std::domain_error d)
                {
                    std::cout<<d.what();
                }
            }
            break;
            
            case 10 :
            {
                int indeks, broj;
                std::cout<<"Unesite broj indeksa studenta koji zeli zaduziti laptop: ";
                std::cin>>indeks;
                std::cout<<"Unesite evidencijski broj laptopa koji zelite zaduziti: ";
                std::cin>>broj;
                a.ZaduziLaptop(indeks, broj);
            }
            break;
        }
        
        if(n == 0) break;
    }
	return 0;
}
