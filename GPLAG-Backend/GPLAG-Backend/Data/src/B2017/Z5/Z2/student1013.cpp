/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <map>
#include <memory>

class Student
{
    int br_indeksa;
    std::string god_studija,ime,adresa,br_telefona;
    static bool TestIndeksa (int br_indeksa) {return br_indeksa>=10000 && br_indeksa<=99999;}
    static bool TestGodinaStudija (std::string god_studija);
    static std::string IzmijeniString (std::string ime);
    static bool TestBrTelefona (std::string s);
public:
    Student (int br_indeksa, std::string god_studija, std::string ime, std::string adresa, std::string br_telefona): br_indeksa(br_indeksa),god_studija(god_studija),
    ime(IzmijeniString(ime)),adresa(IzmijeniString(adresa)),br_telefona(br_telefona) {
        if (!TestIndeksa(br_indeksa) || !TestBrTelefona(br_telefona) || !TestGodinaStudija(god_studija) || ime.size()==0 || adresa.size()==0)
            throw std::domain_error ("Neispravni parametri");
    }
    int DajIndeks () const {return br_indeksa;}
    std::string DajImePrezime () const {return ime;}
    std::string DajAdresu() const {return adresa;}
    std::string DajTelefon () const {return br_telefona;}
    std::string DajGodinuStudija () const {
        if (god_studija=="1") return "1/B";
        if (god_studija=="2") return "2/B";
        if (god_studija=="3") return "3/B";
        return god_studija;
    }
    void Ispisi() const;
};

void Student::Ispisi() const
{
    std::cout<<"Broj indeksa: "<<br_indeksa<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<ime<<std::endl;
    std::cout<<"Adresa: "<<adresa<<std::endl;
    std::cout<<"Telefon: "<<br_telefona<<std::endl;
}

bool Student::TestBrTelefona (std::string s)
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

std::string Student::IzmijeniString (std::string s)
{
    for (int i=0;i<s.size();i++)
    {
        if (i>0 && s[i-1]==' ' && s[i]==' ')
        {
            s.erase(s.begin()+i);
            --i;
        }
    }
    if (s.size()!=0) {
    if (s[0]==' ') s.erase(s.begin());
    if (s[s.size()-1]==' ') s.erase(s.begin()+s.size()-1);}
    return s;
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
    void Zaduzi (Student &s) {if (DaLiJeZaduzen()) throw std::domain_error ("Laptop vec zaduzen"); kod_koga_je=&s;}
    void Razduzi () {kod_koga_je=nullptr;}
    Student &DajKodKogaJe () const { if (!DaLiJeZaduzen()) throw std::domain_error ("Laptop nije zaduzen"); return *kod_koga_je;}
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
    std::map<int,std::shared_ptr<Student>> student;
    std::map<int,std::shared_ptr<Laptop>> laptop;
    void UnistiMapu (std::map<int,std::shared_ptr<Student>> &mapa);
    void UnistiMapu (std::map<int,std::shared_ptr<Laptop>> &mapa);
    std::map<int,std::shared_ptr<Student>> StvoriMapu (const std::map<int,std::shared_ptr<Student>> &mapa);
    std::map<int,std::shared_ptr<Laptop>> StvoriMapu (const std::map<int,std::shared_ptr<Laptop>> &mapa);
public:
    Administracija () = default;
    ~Administracija () = default;
    Administracija (const Administracija &a);
    Administracija (Administracija &&a);
    Administracija &operator= (const Administracija &a);
    Administracija &operator= (Administracija &&a);
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
    auto it(laptop.begin()),kraj(laptop.end());
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
    if (!laptop.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    if (!(laptop[ev_broj]->DaLiJeZaduzen())) throw std::domain_error ("Laptop nije zaduzen");
    laptop[ev_broj]->Razduzi();
}

int Administracija::NadjiSlobodniLaptop () const
{
    int temp(0); bool slobodno(false);
    auto it(laptop.begin()),kraj(laptop.end());
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
    if (!student.count(br_indeksa)) throw std::domain_error ("Student nije nadjen");
    if (!laptop.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    if (laptop[ev_broj]->DaLiJeZaduzen()) throw std::domain_error ("Laptop vec zaduzen");
    auto it(laptop.begin()),kraj(laptop.end());
    while (it!=kraj)
    {
        if (it->second->DaLiJeZaduzen())
        {
            if (it->second->DajKodKogaJe().DajIndeks()==br_indeksa)
                throw std::domain_error ("Student je vec zaduzio laptop");
        }
        it++;
    }
    laptop[ev_broj]->Zaduzi(*(student[br_indeksa]));
}

void Administracija::IzlistajLaptope() const
{
    auto it(laptop.begin()),kraj(laptop.end());
    while (it!=kraj)
    {
        it->second->Ispisi();
        if (it->second->DaLiJeZaduzen())
        std::cout<<"Zaduzio(la): "<<it->second->DajKodKogaJe().DajImePrezime()<<" ("<<it->second->DajKodKogaJe().DajIndeks()<<")\n";
        std::cout<<"\n";
        it++;
    }
}

void Administracija::IzlistajStudente() const
{
    auto it(student.begin()),kraj(student.end());
    while (it!=kraj)
    {
        it->second->Ispisi();
        std::cout<<"\n";
        it++;
    }
}

Laptop Administracija::NadjiLaptop(int ev_broj) const
{
    if (!laptop.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    auto it(laptop.begin()),kraj(laptop.end());
    Laptop *pok(nullptr);
    while (it!=kraj)
    {
        if (it->first==ev_broj)
        {
            pok=it->second.get();
        }
        it++;
    }
    return *pok;
}

Laptop &Administracija::NadjiLaptop(int ev_broj)
{
    if (!laptop.count(ev_broj)) throw std::domain_error ("Laptop nije nadjen");
    return *laptop[ev_broj];
}

Student Administracija::NadjiStudenta(int br_indeksa) const
{
    if (!student.count(br_indeksa)) throw std::domain_error ("Student nije nadjen");
    auto it(student.begin()),kraj(student.end());
    Student *pok(nullptr);
    while (it!=kraj)
    {
        if (it->first==br_indeksa)
        {
            pok=it->second.get();
            break;
        }
        it++;
    }
    return *pok;
}

Student &Administracija::NadjiStudenta(int br_indeksa)
{
    if (!student.count(br_indeksa)) throw std::domain_error ("Student nije nadjen");
    return *student[br_indeksa];
}

void Administracija::RegistrirajNoviLaptop (int ev_broj, std::string naziv, std::string karakteristike)
{
    if (laptop.count(ev_broj)) throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
    laptop[ev_broj]=std::make_shared<Laptop> (ev_broj,naziv,karakteristike);
}

void Administracija::RegistrirajNovogStudenta (int br_indeksa, std::string god_studija, std::string ime, std::string adresa, std::string br_telefona)
{
    if (student.count(br_indeksa)) throw std::domain_error ("Student s tim indeksom vec postoji");
    student[br_indeksa]=std::make_shared<Student> (br_indeksa,god_studija,ime,adresa,br_telefona);
}

void Administracija::UnistiMapu (std::map<int,std::shared_ptr<Student>> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    while (it!=kraj)
    it=mapa.erase(it);
}

void Administracija::UnistiMapu (std::map<int,std::shared_ptr<Laptop>> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    while (it!=kraj)
    it=mapa.erase(it);
}

std::map<int,std::shared_ptr<Student>> Administracija::StvoriMapu (const std::map<int,std::shared_ptr<Student>> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    std::map<int,std::shared_ptr<Student>> temp;
    while (it!=kraj)
    {
        temp[it->first]=std::make_shared<Student> (*(it->second));
        it++;
    }
    return temp;
}

std::map<int,std::shared_ptr<Laptop>> Administracija::StvoriMapu (const std::map<int,std::shared_ptr<Laptop>> &mapa)
{
    auto it(mapa.begin()),kraj(mapa.end());
    std::map<int,std::shared_ptr<Laptop>> temp;
    while (it!=kraj)
    {
        temp[it->first]=std::make_shared<Laptop> (*(it->second));
        it++;
    }
    return temp;
}

Administracija::Administracija (Administracija &&a): student(a.student),laptop(a.laptop)
{
    UnistiMapu(a.student); UnistiMapu(a.laptop);
}

Administracija &Administracija::operator= (Administracija &&a)
{
    std::swap(student,a.student); std::swap(laptop,a.laptop);
    return *this;
}

Administracija::Administracija (const Administracija &a)
{
    student=StvoriMapu(a.student); laptop=StvoriMapu(a.laptop);
}

Administracija &Administracija::operator= (const Administracija &a)
{
    if (&a!=this)
    {
        auto novi_s(StvoriMapu(a.student));
        auto novi_l(StvoriMapu(a.laptop));
        student=novi_s; laptop=novi_l;
    }
    return *this;
}

int main ()
{
    Administracija a;
    for (;;)
    {
        int n;
        std::cout<<"Odaberite opciju:\n1 - Unesi studenta\n2 - Unesi laptop\n3 - Zaduzi laptop\n4 - Razduzi laptop\n5 - Izlistaj laptope\n6- Izlistaj tudente\n7- Kraj\n";
        std::cin>>n;
        if (n==1)
        {
            std::cin.ignore(10000,'\n');
            int indeks;
            std::string ime,adresa,br,god;
            std::cout<<"Unesite ime,prezime, adresu i god_studija: \n";
            std::cin>>ime>>adresa>>br>>god;
            std::cout<<"Unesite indeks: ";
            std::cin>>indeks;
            try{a.RegistrirajNovogStudenta(indeks,god,ime,adresa,br);}
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==2)
        {
            std::cin.ignore(10000,'\n');
            int ev_broj;
            std::string ime,k;
            std::cout<<"Unesite naziv laptopa, te njegove osnovne karakteristike: ";
            std::cin>>ime>>k;
            std::cout<<"Unesite evidencijski broj laptop: ";
            std::cin>>ev_broj;
            try{a.RegistrirajNoviLaptop(ev_broj,ime,k);}
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==3)
        {
            int i,e;
            std::cout<<"Unesite indeks studenta, te evidencijski broj laptopa: ";
            std::cin>>i>>e;
            try{a.ZaduziLaptop(i,e);}
            catch(...)
            {std::cout<<"Greska!UnistiMapu!\n";}
        }
        else if (n==4)
        {
            int e;
            std::cout<<"Unesite evidencijski broj laptopa kojeg zelite da razduzie: ";
            std::cin>>e;
            try {a.RazduziLaptop(e);}
            catch(...)
            {std::cout<<"Greska!Unesite ponovo!\n";}
        }
        else if (n==5) a.IzlistajLaptope();
        else if (n==6) a.IzlistajStudente();
        else if (n==7) break;
    }
	return 0;
}
