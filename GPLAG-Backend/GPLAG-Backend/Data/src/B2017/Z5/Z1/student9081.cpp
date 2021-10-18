/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <map>
#include <new>

class Student 
{
    int br_indeksa;
    std::string god_studija,ime,adresa,br_telefona;
    static bool TestIndeksa (int br_indeksa) {return br_indeksa>=10000 && br_indeksa<=99999;}
    static bool TestGodinaStudija (std::string god_studija);
    static std::string IzmijeniString (std::string ime);
    static bool TestBrojTelefona (std::string s);
public:
    Student (int br_indeksa, std::string god_studija, std::string ime, std::string adresa, std::string br_telefona): br_indeksa(br_indeksa),god_studija(god_studija),
    ime(IzmijeniString(ime)),adresa(IzmijeniString(adresa)),br_telefona(br_telefona) {
        if (!TestIndeksa(br_indeksa) || !TestGodinaStudija(god_studija) || !TestBrojTelefona(br_telefona) || ime.size()==0 || adresa.size()==0)
            throw std::domain_error ("Neispravni parametri");
    }
    int DajIndeks () const {return br_indeksa;}
    std::string DajImePrezime () const {return ime;}
    std::string DajAdresu () const {return adresa;}
    std::string DajTelefon () const {return br_telefona;}
    std::string DajGodinuStudija () const {
        if (god_studija=="1") return "1/B";
        if (god_studija=="2") return "2/B";
        if (god_studija=="3") return "3/B";
        return god_studija;
    }
    void Ispisi () const;
};

void Student::Ispisi () const
{
    std::cout<<"Broj indeksa: "<<br_indeksa<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<ime<<std::endl;
    std::cout<<"Adresa: "<<adresa<<std::endl;
    std::cout<<"Telefon: "<<br_telefona<<std::endl;
}

bool Student::TestBrojTelefona (std::string s)
{
    int brojac_cr(0),brojac_ks(0),brojac_s(0);
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='-')
        {
            brojac_cr++;
            if (brojac_ks!=1) return false;
            if (brojac_s==0) return false;
            brojac_s=0;
        }
        else if (s[i]=='/')
        {
            brojac_ks++;
            if (brojac_cr!=0) return false;
            if (brojac_s==0) return false;
            brojac_s=0;
        }
        else if (!(s[i]>='0' && s[i]<='9')) return false;
        else if (s[i]>='0' && s[i]<='9') brojac_s++;
    }
    if (brojac_s==0) return false;
    if (brojac_cr!=1 || brojac_ks!=1) return false;
    return true;
}

bool Student::TestGodinaStudija (std::string s)
{
    const char *niz[]{"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
    for (int i=0;i<11;i++)
    {
        if (s==niz[i])
        return true;
    }
    return false;
}

std::string Student::IzmijeniString (std::string ime)
{
    for (int i=0;i<ime.size();i++)
    {
        if (i>0 && ime[i-1]==' ' && ime[i]==' ')
        {
            ime.erase(ime.begin()+i);
            --i;
        }
    }
    if (ime.size()!=0) {
    if (ime[0]==' ') ime.erase(ime.begin());
    if (ime[ime.size()-1]==' ') ime.erase(ime.begin()+ime.size()-1);}
    return ime;
}

class Laptop
{
    int ev_broj;
    std::string naziv,karakteristike;
    Student *kod_koga_je;
public:
    Laptop (int ev_broj, std::string naziv, std::string karakteristike): ev_broj(ev_broj),naziv(naziv),karakteristike(karakteristike),kod_koga_je(nullptr) {
        if (ev_broj<0 || naziv.size()==0 || karakteristike.size()==0) throw std::domain_error ("Neispravni parametri");
    }
    int DajEvidencijskiBroj () const {return ev_broj;}
    std::string DajNaziv () const {return naziv;}
    std::string DajKarakteristike () const {return karakteristike;}
    bool DaLiJeZaduzen () const {return kod_koga_je!=nullptr;}
    void Zaduzi (Student &s) { if (DaLiJeZaduzen()) throw std::domain_error ("Laptop vec zaduzen"); kod_koga_je=&s;}
    void Razduzi () {kod_koga_je=nullptr;}
    Student &DajKodKogaJe () const {if (!DaLiJeZaduzen()) throw std::domain_error ("Laptop nije zaduzen"); return *kod_koga_je;}
    Student *DajPokKodKogaJe () const {if (!DaLiJeZaduzen()) return nullptr; return kod_koga_je;}
    void Ispisi() const;
};

void Laptop::Ispisi() const
{
    std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl;
    std::cout<<"Naziv: "<<naziv<<std::endl;
    std::cout<<"Karakteristike: "<<karakteristike<<std::endl;
}

class Administracija
{
    std::map<int,Student*> studenti;
    std::map<int,Laptop*> laptopi;
    void UnistiMapuStudenata (std::map<int,Student*> &mapa);
    void UnistiMapuLaptopa (std::map<int,Laptop*> &mapa);
    std::map<int,Student*> StvoriMapu (const std::map<int,Student*> &mapa);
    std::map<int,Laptop*> StvoriMapu (const std::map<int,Laptop*> &mapa);
    static void DealocirajL(std::map<int,Laptop*> &mapa);
    static void DealocirajS(std::map<int,Student*> &mapa);
public:
    Administracija () = default;
    ~Administracija () {DealocirajS(studenti); DealocirajL(laptopi);}
    Administracija (const Administracija &a);
    Administracija (Administracija &&a);
    Administracija &operator = (const Administracija &a);
    Administracija &operator = (Administracija &&a);
    void RegistrirajNovogStudenta (int br_indeksa, std::string god_studija, std::string ime, std::string adresa, std::string br_telefona);
    void RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike);
    Student &NadjiStudenta (int br_indeksa);
    Student NadjiStudenta (int br_indeksa) const;
    Laptop &NadjiLaptop (int ev_broj);
    Laptop NadjiLaptop (int ev_broj) const;
    void IzlistajStudente () const;
    void IzlistajLaptope () const;
    void ZaduziLaptop (int br_indeksa, int ev_broj);
    int NadjiSlobodniLaptop () const;
    void RazduziLaptop (int ev_broj);
    void PrikaziZaduzenja () const;
};

void Administracija::PrikaziZaduzenja () const
{
    auto it(laptopi.begin()),kraj(laptopi.end());
    bool zaduzen(false);
    while (it!=kraj)
    {
        if (it->second->DaLiJeZaduzen())
        {
            zaduzen=true;
            std::cout<<"Student "<<it->second->DajKodKogaJe().DajImePrezime()<<" ("<<it->second->DajKodKogaJe().DajIndeks()<<") zaduzio/la laptop broj "<<it->first<<"\n";
        }
        it++;
    }
    if (!zaduzen) std::cout<<"Nema zaduzenja\n";
}

void Administracija::RazduziLaptop(int ev_broj)
{
    if (!laptopi.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    if (!(laptopi[ev_broj]->DaLiJeZaduzen())) throw std::domain_error ("Laptop nije zaduzen");
    laptopi[ev_broj]->Razduzi();
}

int Administracija::NadjiSlobodniLaptop() const
{
    int temp(0); bool slobodno(false);
    auto it(laptopi.begin()),kraj(laptopi.end());
    while (it!=kraj)
    {
        if (!(it->second->DaLiJeZaduzen()))
        {
            temp=it->first;
            slobodno=true;
            break;
        }
        it++;
    }
    if (!slobodno) throw std::domain_error ("Nema slobodnih laptopa");
    return temp;
}

void Administracija::ZaduziLaptop (int br_indeksa, int ev_broj)
{
    if (!studenti.count(br_indeksa)) throw std::domain_error ("Student nije nadjen");
    if (!laptopi.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    if (laptopi[ev_broj]->DaLiJeZaduzen()) throw std::domain_error ("Laptop vec zaduzen");
    auto it(laptopi.begin()),kraj(laptopi.end());
    while (it!=kraj)
    {
        if (it->second->DaLiJeZaduzen())
        {
            if (it->second->DajKodKogaJe().DajIndeks()==br_indeksa)
                throw std::domain_error ("Student je vec zaduzio laptop");
        }
        it++;
    }
    laptopi[ev_broj]->Zaduzi(*studenti[br_indeksa]);
}

void Administracija::IzlistajLaptope () const
{
    auto it(laptopi.begin()),kraj(laptopi.end());
    while (it!=kraj)
    {
        it->second->Ispisi();
        if (it->second->DaLiJeZaduzen())
        std::cout<<"Zaduzio(la): "<<it->second->DajKodKogaJe().DajImePrezime()<<" ("<<it->second->DajKodKogaJe().DajIndeks()<<")\n";
        std::cout<<"\n";
        it++;
    }
}

void Administracija::IzlistajStudente () const
{
    auto it(studenti.begin()),kraj(studenti.end());
    while (it!=kraj)
    {
        it->second->Ispisi();
        std::cout<<"\n";
        it++;
    }
}

Laptop Administracija::NadjiLaptop(int ev_broj) const
{
    if (!laptopi.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    auto it(laptopi.begin()),kraj(laptopi.end());
    Laptop *pok(nullptr);
    while (it!=kraj)
    {
        if (it->first==ev_broj)
        {
            pok=it->second; break;
        }
        it++;
    }
    return *pok;
}

Laptop &Administracija::NadjiLaptop(int ev_broj)
{
    if (!laptopi.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    return *laptopi[ev_broj];
}

Student Administracija::NadjiStudenta (int br_indeksa) const
{
    if (!studenti.count(br_indeksa)) throw std::domain_error ("Student nije nadjen");
    auto it(studenti.begin()),kraj(studenti.end());
    Student *pok(nullptr);
    while (it!=kraj)
    {
        if (it->first==br_indeksa)
        {
            pok=it->second;
            break;
        }
        it++;
    }
    return *pok;
}

Student &Administracija::NadjiStudenta(int br_indeksa)
{
    if (!studenti.count(br_indeksa)) throw std::domain_error ("Student nije nadjen");
    return *studenti[br_indeksa];
}

void Administracija::RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike)
{
    if (laptopi.count(ev_broj)) throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
    laptopi[ev_broj]=new Laptop(ev_broj,naziv,karakteristike);
}

void Administracija::RegistrirajNovogStudenta (int br_indeksa, std::string god_studija, std::string ime, std::string adresa, std::string br_telefona)
{
    if (studenti.count(br_indeksa)) throw std::domain_error ("Student s tim indeksom vec postoji");
    studenti[br_indeksa]=new Student(br_indeksa,god_studija,ime,adresa,br_telefona);
}

void Administracija::DealocirajL (std::map<int,Laptop*> &laptopi)
{
    auto it(laptopi.begin()),kraj(laptopi.end());
    while (it!=kraj)
    {
        delete it->second; it->second=nullptr;
        it++;
    }
}

void Administracija::DealocirajS (std::map<int,Student*> &studenti)
{
    auto it(studenti.begin()),kraj(studenti.end());
    while (it!=kraj)
    {
        delete it->second; it->second=nullptr;
        it++;
    }
}

void Administracija::UnistiMapuStudenata (std::map<int,Student*> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    while (it!=kraj)
    it=mapa.erase(it);
}

void Administracija::UnistiMapuLaptopa (std::map<int,Laptop*> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    while (it!=kraj)
    it=mapa.erase(it);
}

std::map<int,Student*> Administracija::StvoriMapu (const std::map<int,Student*> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    std::map<int,Student*> temp;
    while (it!=kraj)
    {
        temp[it->first]=nullptr;
        it++;
    }
    it=mapa.begin();
    try
    {
        while (it!=kraj)
        {
            temp[it->first]= new Student(*(it->second));
            it++;
        }
    }
    catch (std::bad_alloc)
    {
        DealocirajS(temp);
        throw;
    }
    return temp;
}

std::map<int,Laptop*> Administracija::StvoriMapu (const std::map<int,Laptop*> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    std::map<int,Laptop*> temp;
    while (it!=kraj)
    {
        temp[it->first]=nullptr;
        it++;
    }
    it=mapa.begin();
    try
    {
        while (it!=kraj)
        {
            temp[it->first]=new Laptop(*(it->second));
            it++;
        }
    }
    catch (std::bad_alloc)
    {
        DealocirajL(temp);
        throw;
    }
    return temp;
}

Administracija::Administracija (Administracija &&a): studenti(a.studenti),laptopi(a.laptopi)
{
    UnistiMapuLaptopa(a.laptopi); UnistiMapuStudenata(a.studenti);
}

Administracija::Administracija (const Administracija &a)
{
    studenti=StvoriMapu(a.studenti); laptopi=StvoriMapu(a.laptopi);
}

Administracija &Administracija::operator= (const Administracija &a)
{
    if (&a!=this) {
    std::map<int,Student*> st(StvoriMapu(a.studenti));
    std::map<int,Laptop*> lp(StvoriMapu(a.laptopi));
    DealocirajL(this->laptopi); DealocirajS(this->studenti);
    UnistiMapuLaptopa(this->laptopi); UnistiMapuStudenata(this->studenti);
    studenti=st; laptopi=lp;}
    return *this;
}

Administracija &Administracija::operator= (Administracija &&a)
{
    std::swap(studenti,a.studenti); std::swap(laptopi,a.laptopi);
    return *this;
}

int main ()
{
    Administracija a;
    for(;;)
    {
        int n;
        std::cout<<"Odaberite jednu od opcija:\n1 - Unesi novog studenta\n2 - Unesi novi laptop\n3 - Zaduzi laptop\n4 - Razduzi laptop\n5 - Nadji studenta\n6 - Nadji laptop\n";
        std::cout<<"7 - Izlistaj sve studente\n8 - Izlistaj sve laptope\n9 - Kraj\n";
        std::cin>>n;
        if (n==1)
        {
            std::cin.ignore(10000,'\n');
            int indeks;
            std::string ime,adresa,br_telefona,god_studija;
            std::cout<<"Unesite indeks: ";
            std::cin>>indeks;
            std::cout<<"Unesite ime i prezime: ";
            std::cin>>ime;
            std::cout<<"Unesite adresu i broj telefona ";
            std::cin>>adresa>>br_telefona;
            std::cout<<"Unesite godinu studija: ";
            std::cin>>god_studija;
            try {
            a.RegistrirajNovogStudenta(indeks,god_studija,ime,adresa,br_telefona);}
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==2)
        {
            std::cin.ignore(10000,'\n');
            int br;
            std::string ime,k;
            std::cout<<"Unesite evidencijski broj laptopa: ";
            std::cin>>br;
            std::cout<<"Unesite ime laptopa: ";
            std::cin>>ime;
            std::cout<<"Unesite karakteristike: ";
            std::cin>>k;
            try {a.RegistrirajNoviLaptop(br,ime,k);}
            catch(...)
            {std::cout<<"Greska!Unesite ponovo\n";}
        }
        else if (n==3)
        {
            int i,e;
            std::cout<<"Unesite indeks i ev broj: ";
            std::cin>>i>>e;
            try {a.ZaduziLaptop(i,e); }
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==4)
        {
            int e;
            std::cout<<"Unesite ev broj laptopa: ";
            std::cin>>e;
            try {a.RazduziLaptop(e);}
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==5)
        {
            int i;
            std::cout<<"Unesi indeks za pretragu: ";
            std::cin>>i;
            try
            {
                Student s(a.NadjiStudenta(i));
                std::cout<<"Ime studenta je "<<s.DajImePrezime();
            }
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==6)
        {
            int e;
            std::cout<<"Unesite ev broj za pretragu: ";
            std::cin>>e;
            try
            {
                Laptop l(a.NadjiLaptop(e));
                std::cout<<"Naziv laptopa je "<<l.DajNaziv();
            }
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==7) a.IzlistajStudente();
        else if (n==8) a.IzlistajLaptope();
        else if (n==9) break;
    }
	return 0;
}
