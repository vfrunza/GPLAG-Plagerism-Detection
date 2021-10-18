/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>

class Student
{
    int broj_indeksa;                                                           //peterocifreni broj
    std::string godina_studija;
    std::string ime_prezime, adresa, broj_telefona;
public:
    Student (int broj_indeksa, std::string godina_studija, std::string ime_prezime, //konstruktor
             std::string adresa, std::string broj_telefona) ;
    //Pristupne metode:
    int DajIndeks () const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija () const {
        if(godina_studija=="1" || godina_studija=="2" || godina_studija=="3")
            return godina_studija+std::string("/B");
        return godina_studija;
    }
    std::string DajImePrezime () const {
        return ime_prezime;
    }
    std::string DajAdresu () const {
        return adresa;
    }
    std::string DajTelefon () const {
        return broj_telefona;
    }
    void Ispisi () const ;
};

Student::Student (int broj_indeksa, std::string godina_studija, std::string ime_prezime, //konstruktor
                  std::string adresa, std::string broj_telefona)
{
    std::string novi;
    for(int i=0; i<ime_prezime.length(); i++) {                                 //brisanje suvisnih razmaka
        /*while(i<ime_prezime.length() && ime_prezime[i]==' ')
            ime_prezime.erase(ime_prezime.begin()+i);
        while(i<ime_prezime.length() && ime_prezime[i]!=' ') i++;*/
        if(novi.length()==0)
            while(i<ime_prezime.length() && !(ime_prezime[i]==' ')) {
                novi.push_back(ime_prezime[i]);
                i++;
            }
        if(i<ime_prezime.length() && novi.length()!=0 && ime_prezime.at(i)!=' ') {
            novi.push_back(' ');
            while(i<ime_prezime.length() && ime_prezime.at(i)!=' ') {
                novi.push_back(ime_prezime.at(i));
                i++;
            }
        }
    }
    ime_prezime=novi;
    novi="";
    for(int i=0; i<adresa.length(); i++) {                                      //brisanje suvisnig razmaka
        if(novi.length()==0)
            while(i<adresa.length() && !(adresa[i]==' ')) {
                novi.push_back(adresa[i]);
                i++;
            }
        if(i<adresa.length() && novi.length()!=0 && adresa[i]!=' ') {
            novi.push_back(' ');
            while(i<adresa.length() && adresa.at(i)!=' ') {
                novi.push_back(adresa.at(i));
                i++;
            }
        }
    }
    adresa=novi;
    int i(0);                                                                   //provjera broja telefona
    while(i<broj_telefona.length() && (broj_telefona[i]>='0' && broj_telefona[i]<='9')) i++;
    if(!std::cin || broj_telefona[i]!='/') throw std::domain_error("Neispravni parametri");
    i++;
    while(i<broj_telefona.length() && (broj_telefona[i]>='0' && broj_telefona[i]<='9')) i++;
    if(!std::cin || broj_telefona[i]!='-') throw std::domain_error("Neispravni parametri");
    i++;
    while(i<broj_telefona.length() && (broj_telefona[i]>='0' && broj_telefona[i]<='9')) i++;
    if(!std::cin) throw std::domain_error("Neispravni parametri");


    for(int i=0; i<godina_studija.length(); i++)
        while(i<godina_studija.length() && godina_studija[i]==' ')
            godina_studija.erase(godina_studija.begin()+i);
    if (broj_indeksa/10000==0 || broj_indeksa/10000>=10 || !(godina_studija=="1"
            || godina_studija=="2" || godina_studija=="3" || godina_studija=="1/B"
            || godina_studija=="2/B" || godina_studija=="3/B" || godina_studija=="1/M"
            || godina_studija=="2/M" || godina_studija=="3/M" || godina_studija=="1/D"
            || godina_studija=="2/D" || godina_studija=="3/D" ))
        throw std::domain_error("Neispravni parametri");
    Student::broj_indeksa=broj_indeksa;
    Student::godina_studija=godina_studija;
    Student::ime_prezime=ime_prezime;
    Student::adresa=adresa;
    Student::broj_telefona=broj_telefona;
}

void Student::Ispisi() const
{
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl
             <<"Godina studija: "<<DajGodinuStudija()<<std::endl
             <<"Ime i prezime: "<<DajImePrezime()<<std::endl
             <<"Adresa: "<<DajAdresu()<<std::endl
             <<"Telefon: "<<DajTelefon()<<std::endl;
}

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
public:
    Laptop (int ev_broj, std::string naziv, std::string karakteristike);        //konstruktor
    int DajEvidencijskiBroj () const {
        return ev_broj;
    }
    std::string DajNaziv () const {
        return naziv;
    }
    std::string DajKarakteristike () const {
        return karakteristike;
    }
    void Zaduzi (Student &s) {
        if(kod_koga_je!=nullptr)
            throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi () {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen () const {
        return kod_koga_je!=nullptr;
    }
    Student &DajKodKogaJe () const {
        if(kod_koga_je==nullptr)
            throw std::domain_error ("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe () const {
        return kod_koga_je;
    }
    void Ispisi () const ;
};

Laptop::Laptop (int ev_broj, std::string naziv, std::string karakteristike)
{
    if(ev_broj<0) throw std::domain_error("Neispravni parametri");
    Laptop::ev_broj=ev_broj;
    Laptop::naziv=naziv;
    Laptop::karakteristike=karakteristike;
    Laptop::kod_koga_je=nullptr;
}

void Laptop::Ispisi() const
{
    std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl
             <<"Naziv: "<<naziv<<std::endl
             <<"Karakteristike: "<<karakteristike<<std::endl;
}

class Administracija
{
    std::map<int, Student *> studenti;                                          //kljucno polje je broj indeksa
    std::map<int, Laptop *> laptopi;                                            //kljucno polje je evidencijski broj
public:
    Administracija () = default;
    ~ Administracija () {
        for(auto it=studenti.begin(); it!=studenti.end(); it++) delete it->second;
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++) delete it->second;
    }
    Administracija (const Administracija &a);                                   //kopirajuci konstruktor
    Administracija (Administracija &&a);                                        //pomjerajuci konstruktor
    Administracija &operator =(const Administracija &a);                        //kopirajuci operator dodjele
    Administracija &operator =(Administracija &&a);                              //pomjerajuci operator dodjele
    
    void RegistrirajNovogStudenta (int broj_indeksa, std::string godina_studija,
                                   std::string ime_prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike);

    Student &NadjiStudenta (int broj_indeksa);
    Student NadjiStudenta(int broj_indeksa) const ;

    Laptop &NadjiLaptop (int ev_broj);
    Laptop NadjiLaptop(int ev_broj) const;

    void IzlistajStudente () const ;
    void IzlistajLaptope () const;

    void ZaduziLaptop (int broj_indeksa, int ev_broj);

    int NadjiSlobodniLaptop ();

    void RazduziLaptop (int ev_broj);

    void PrikaziZaduzenja () const ;
};

Administracija &Administracija::operator =(Administracija &&a) {
    if(this==&a) return *this;
    for(auto it=this->studenti.begin(); it!=this->studenti.end(); it++) {
        delete it->second;
        studenti.erase(it->first);
    }
    for(auto it=this->laptopi.begin(); it!=this->laptopi.end(); it++) {
        delete it->second;
        laptopi.erase(it->first);
    }
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
        this->studenti.insert({it->first, it->second});
        it->second=nullptr;
    }
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) {
        this->laptopi.insert({it->first, it->second});
        it->second=nullptr;
    }
    return *this;
} 

Administracija::Administracija (Administracija &&a) {
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
        this->studenti.insert({it->first, it->second});
        it->second=nullptr;
    }
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) {
        this->laptopi.insert({it->first, it->second});
        it->second=nullptr;
    }
}

Administracija &Administracija::operator =(const Administracija &a)
{
    if(this==&a) return *this;                                                  //provjera na destruktivnu samododjelu
    for(auto it=this->studenti.begin(); it!=this->studenti.end(); it++) delete it->second;
    for(auto it=this->laptopi.begin(); it!=this->laptopi.end(); it++) delete it->second;
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++)
        this->studenti.insert({it->first, new Student(it->first,
                               it->second->DajGodinuStudija(), it->second->DajImePrezime(), it->second->DajAdresu(), it->second->DajTelefon())
                              });
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++)
        this->laptopi.insert({it->first, new Laptop(it->first,
                              it->second->DajNaziv(), it->second->DajKarakteristike())
                             });
    return *this;
}

Administracija::Administracija (const Administracija &a)
{
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++)
        this->studenti.insert({it->first, new Student(it->first,
                               it->second->DajGodinuStudija(), it->second->DajImePrezime(), it->second->DajAdresu(), it->second->DajTelefon())
                              });
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++)
        this->laptopi.insert({it->first, new Laptop(it->first,
                              it->second->DajNaziv(), it->second->DajKarakteristike())
                             });
}

void Administracija::PrikaziZaduzenja () const
{
    bool postoji(false);
    for(auto it1=laptopi.begin(); it1!=laptopi.end(); it1++) {
        if(it1->second->DajPokKodKogaJe()!=nullptr) {
            postoji=true;
            for(auto it2=studenti.begin(); it2!=studenti.end(); it2++) {
                if(((it1->second)->DajPokKodKogaJe()->DajIndeks())==(it2->first))
                    std::cout<<"Student "<<(it2->second)->DajImePrezime()<<" ("
                             <<(it2->second)->DajIndeks()<<") zaduzio/la laptop broj "
                             <<it1->first<<std::endl;
            }
        }
    }
    if(postoji==false) std::cout<<"Nema zaduzenja";
}

void Administracija::RazduziLaptop (int ev_broj)
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->first==ev_broj) {
            if((it->second)->DajPokKodKogaJe()==nullptr)
                throw std::domain_error("Laptop nije zaduzen");
            else {
                (it->second)->Razduzi();
                return;
            }
        }
    throw std::domain_error("Laptop nije nadjen");
}

int Administracija::NadjiSlobodniLaptop ()
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if((it->second)->DaLiJeZaduzen()==false) return it->first;
    throw std::domain_error("Nema slobodnih laptopa");
}

void Administracija::ZaduziLaptop (int broj_indeksa, int ev_broj)
{
    bool pronadjen(false);
    for(auto it=studenti.begin(); it!=studenti.end(); it++)
        if(it->first==broj_indeksa) {
            pronadjen=true;
            break;
        }
    if(pronadjen==false)
        throw std::domain_error("Student nije nadjen");
    pronadjen=false;
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->first==ev_broj) {
            pronadjen=true;
            break;
        }
    if(pronadjen==false)
        throw std::domain_error("Laptop nije nadjen");

    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->first==ev_broj && (it->second)->DaLiJeZaduzen())
            throw std::domain_error("Laptop vec zaduzen");

    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        if(it->second->DaLiJeZaduzen() && it->second->DajPokKodKogaJe()->DajIndeks()==broj_indeksa)
            throw std::domain_error("Student je vec zaduzio laptop");
    }

    auto laptop = laptopi.find(ev_broj)->second;
    auto student = studenti.find(broj_indeksa)->second;
    laptop->Zaduzi(*student);

}

void Administracija::IzlistajLaptope () const
{
    int brojac(1);
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        (it->second)->Ispisi();
        if((it->second)->DaLiJeZaduzen())
            std::cout<<"Zaduzio(la): "<<((it->second)->DajPokKodKogaJe())->DajImePrezime()<<" "
                     <<"("<<((it->second)->DajPokKodKogaJe())->DajIndeks()<<")"<<std::endl;
        std::cout<<std::endl;
        brojac++;
        if(brojac%2!=0) std::cout<<std::endl;
    }
}

void Administracija::IzlistajStudente() const
{
    int brojac(1);
    for(auto it=studenti.begin(); it!=studenti.end(); it++) {
        (it->second)->Ispisi();
        brojac++;
        if(brojac%2!=0) std::cout<<std::endl;
    }
}

Laptop &Administracija::NadjiLaptop (int ev_broj)
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->first==ev_broj)
            return *(it->second);
    throw std::domain_error("Laptop nije nadjen");
}

Laptop Administracija::NadjiLaptop (int ev_broj) const
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->first==ev_broj)
            return Laptop(*(it->second));
    throw std::domain_error("Laptop nije nadjen");
}

Student Administracija::NadjiStudenta (int broj_indeksa) const
{
    for(auto it=studenti.begin(); it!=studenti.end(); it++)
        if(it->first==broj_indeksa)
            return Student(*(it->second));
    throw std::domain_error("Student nije nadjen");
}

Student &Administracija::NadjiStudenta (int broj_indeksa)
{
    for(auto it=studenti.begin(); it!=studenti.end(); it++)
        if(it->first==broj_indeksa)
            return *(it->second);
    throw std::domain_error("Student nije nadjen");
}

void Administracija::RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike)
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->first==ev_broj)
            throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi.insert({ev_broj, new Laptop(ev_broj, naziv, karakteristike)});
}

void Administracija::RegistrirajNovogStudenta (int broj_indeksa, std::string godina_studija, std::string ime_prezime,
        std::string adresa, std::string broj_telefona)
{
    for(auto it=studenti.begin(); it!=studenti.end(); it++)
        if(it->first==broj_indeksa)
            throw std::domain_error("Student s tim indeksom vec postoji");
    studenti.insert({broj_indeksa, new Student(broj_indeksa,
                     godina_studija, ime_prezime, adresa, broj_telefona)
                    });
}

int main ()
{
    /*Kopiran je javni autotest:
    Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    //etf.IzlistajLaptope();
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "033/664-959");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    //etf.IzlistajStudente();
    etf.ZaduziLaptop(14212, 123);
    etf.ZaduziLaptop(17528, 331);
    //etf.IzlistajLaptope();
    etf.PrikaziZaduzenja();*/
    Administracija etf;
    try {
        for(;;) {
            std::cout<<"Odaberite opciju: "<<std::endl
                     <<" 1 - Registriraj novog studenta"<<std::endl
                     <<" 2 - Registriraj novi laptop"<<std::endl
                     <<" 3 - Nadji studenta"<<std::endl
                     <<" 4 - Nadji laptop"<<std::endl
                     <<" 5 - Zaduzi laptop"<<std::endl
                     <<" 6 - Razduzi laptop"<<std::endl
                     <<" 7 - Nadji slobodan laptop"<<std::endl
                     <<" 8 - Izlistaj studente"<<std::endl
                     <<" 9 - IzlistajLaptope"<<std::endl
                     <<" 10 - PrikaziZaduzenja"<<std::endl
                     <<" 0 ili 'Kraj' za kraj"<<std::endl;
            int unos;
            std::cin>>unos;
            if(!std::cin || unos==0) break;
            else if(unos==1) {
                int broj_indeksa;
                std::string godina_studija, ime_prezime, adresa, broj_telefona;
                std::cout<<"Unesite indeks: ";
                std::cin>>broj_indeksa;
                std::cin.ignore(10000, '\n');
                std::cout<<"Unesite godinu studija: ";
                std::getline(std::cin, godina_studija);
                std::cout<<"Unesite ime i prezime: ";
                std::getline(std::cin, ime_prezime);
                std::cout<<"Unesite broj telefona: ";
                std::getline(std::cin, broj_telefona);
                etf.RegistrirajNovogStudenta(broj_indeksa, godina_studija,
                                             ime_prezime, adresa, broj_telefona);
            } else if(unos==2) {
                std::cout<<"Unesite evidencijski broj:";
                int ev_broj;
                std::cin>>ev_broj;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::string naziv, karakteristike;
                std::cout<<"Unesite naziv: ";
                std::getline(std::cin, naziv);
                std::cout<<"Unesite karakteristike: ";
                std::getline(std::cin, karakteristike);
                etf.RegistrirajNoviLaptop(ev_broj, naziv, karakteristike);
            } else if(unos==3) {
                int broj_indeksa;
                std::cout<<"Unesite indeks: ";
                std::cin>>broj_indeksa;
                etf.NadjiStudenta(broj_indeksa).Ispisi();
                std::cout<<std::endl;
            } else if(unos==4) {
                int ev_broj;
                std::cout<<"Unesite evidencijski broj:";
                std::cin>>ev_broj;
                etf.NadjiLaptop(ev_broj).Ispisi();
                std::cout<<std::endl;
            } else if(unos==5) {
                int broj_indeksa;
                std::cout<<"Unesite indeks: ";
                std::cin>>broj_indeksa;
                int ev_broj;
                std::cout<<"Unesite evidencijski broj:";
                std::cin>>ev_broj;
                etf.ZaduziLaptop(broj_indeksa, ev_broj);
            } else if(unos==6) {
                int ev_broj;
                std::cout<<"Unesite evidencijski broj:";
                std::cin>>ev_broj;
                etf.RazduziLaptop(ev_broj);
            } else if(unos==7) {
                std::cout<<"Slobodan je laptop sa evidencijskim brojem: "<<
                         etf.NadjiSlobodniLaptop();
            } else if(unos==8) {
                etf.IzlistajStudente();
                std::cout<<std::endl;
            } else if(unos==9) {
                etf.IzlistajLaptope();
                std::cout<<std::endl;
            } else if(unos==10) {
                etf.PrikaziZaduzenja();
                std::cout<<std::endl;
            }
        }
    } catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }

    std::cout<<"Dovidjenja!";
    return 0;
}
