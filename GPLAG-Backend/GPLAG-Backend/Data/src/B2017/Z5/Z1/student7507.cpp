/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

class Student
{
    int indeks;
    std::string god_studija, ime_i_prezime, adresa, broj_telefona;
public:
    Student(int broj_indeksa, std::string godina_studija, std::string iip, std::string a, std::string broj_tel):indeks(broj_indeksa), god_studija(godina_studija), ime_i_prezime(iip), adresa(a), broj_telefona(broj_tel) {
        if(broj_indeksa < 9999 || godina_studija != "1" || godina_studija != "2" || godina_studija != "3" || godina_studija != "1/B" || godina_studija != "2/B" || godina_studija != "3/B" || godina_studija != "1/M" || godina_studija != "2/M" || godina_studija != "1/D" || godina_studija!= "2/D" || godina_studija != "3/D") throw std::domain_error("Neispravni parametri");
        //dodati svasta

    }
    int DajIndeks() const {
        return indeks;
    }
    std::string DajGodinuStudija() const {
        return god_studija;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }
    void Ispisi() const {
        std::cout << "Broj indeksa: " << DajIndeks() << std::endl;
        std::cout << "Godina studija: " << DajGodinuStudija() << std::endl;
        std::cout << "Ime i prezime: " << DajImePrezime() << std::endl;
        std::cout << "Adresa: " << DajAdresu() << std::endl;
        std::cout << "Telefon: " << DajTelefon() << std::endl;
    }
};

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike, kod_koga_je;
    Student *pok;
public:
    Laptop(int e, std::string naz, std::string kark):ev_broj(e), naziv(naz), karakteristike(kark), pok(nullptr) {
        if(e<0) throw std::domain_error("Neispravni parametri");
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
    // sta vraca ova fja
    void Zaduzi(Student &p) {
        //if(pok != nullptr) throw std::domain_error("Laptop vec zaduzen");
        pok=&p;
    }
    //???
    void Razduzi() {
        if(pok != nullptr) pok = nullptr;
    }
    bool DaLiJeZaduzen() {
        if(pok==nullptr) return false;
        return true;
    }

    Student &DajKodKogaJe() const {
        if(pok == nullptr) throw std::domain_error("Laptop nije zaduzen");
        return *pok;
    }
    //nesto nesto
    Student* DajPokKodKogaJe() const {
        return pok;
    }
    void Ispisi() const {
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl;
        std::cout << "Naziv: " << DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << DajKarakteristike() << std::endl;
    }
};

class Administracija
{
    std::map<int, Student*> studenti;
    std::map<int, Laptop*> laptopi;
public:
    Administracija();
    Administracija(const Administracija &a);
    Administracija(Administracija &&a);
    Administracija &operator=(const Administracija &a);
    Administracija &operator=(Administracija &&a);
    ~Administracija();
    void RegistrirajNovogStudenta(int ind, std::string gs, std::string iip, std::string ad, std::string brtel);
    void RegistrirajNoviLaptop(int evbr, std::string n, std::string k);
    Student &NadjiStudenta(int i) {
        if(studenti.find(i)==studenti.end()) throw std::domain_error("Student nije nadjen");
        return *studenti[i];
    }
    Laptop &NadjiLaptop(int evid_br) {
        if(laptopi.find(evid_br) == laptopi.end()) throw std::domain_error("Laptop nije nadjen");
        return *laptopi[evid_br];
    }
    
    Laptop NadjiLaptop(int evid_br) const 
    {
        for(auto it=laptopi.begin();it!=laptopi.end();it++)
        return *(it->second);
    }

    void IzlistajStudente();
    void IzlistajLaptope();
    void ZaduziLaptop(int inde, int evidbr);
    void NadjiSlobodniLaptop();
    void RazduziLaptop(int evidbr) {
        if(NadjiLaptop(evidbr).DaLiJeZaduzen()) NadjiLaptop(evidbr).Razduzi();
        else throw std::domain_error("Laptop nije zaduzen");
    }
    void PrikaziZaduzenja() const;

};
Administracija::Administracija() {}
Administracija::Administracija(const Administracija &a)
{
    for(auto it1(a.studenti.begin()); it1 != a.studenti.end(); it1++) {
        studenti[it1->first]= new Student(*it1->second);
    }
    for(auto it(a.laptopi.begin()); it!=a.laptopi.end(); it++) {
        laptopi[it->first] = new Laptop(*it->second);
    }
}

Administracija::Administracija(Administracija &&a)
{
    for(auto it1(a.studenti.begin()); it1!=a.studenti.end(); it1++) {
        studenti[it1->first]=it1->second;
        it1->second=nullptr;
    }
    for(auto it(a.laptopi.begin()); it!=a.laptopi.end(); it++) {
        laptopi[it->first]=it->second;
        it->second=nullptr;
    }
}

Administracija &Administracija::operator=(const Administracija &a)
{
    if(&a == this) return *this;// throw std::logic_error("Destruktivna samododjela!"); // nikad nesto sto sama svoj tekst ispisuje
    for(auto it(laptopi.begin()); it!=laptopi.end(); it++) {
        laptopi.erase(it->first);
    }
    laptopi.clear();
    {
        auto it2(studenti.begin());
        for(auto it1(a.studenti.begin()); it1!=a.studenti.end(); it1++) {
            for(; it2 != studenti.end(); it2++) {
                studenti[it1->first]=new Student(*it1->second);
                it2++;
                break;
            }
        }
    }
    auto it2(laptopi.begin());
    for(auto it1(a.laptopi.begin()); it1!=a.laptopi.end(); it1++) {
        for(; it2 != laptopi.end(); it2++) {
            it2->second= new Laptop(*it1->second);
            it2++;
            break;
        }
    }
    return *this;
}

Administracija &Administracija::operator =(Administracija &&a){
    std::swap(studenti, a.studenti);
    std::swap(laptopi, a.laptopi);
    return *this;
}

Administracija::~Administracija(){
    for(auto it(laptopi.begin()); it != laptopi.end(); it++){
        if(it->second != nullptr)
            delete it->second;
    }
    for(auto it(studenti.begin()); it != studenti.end(); it++){
        if(it->second != nullptr)
            delete it->second;
    }
}

void Administracija::RegistrirajNovogStudenta(int ind, std::string gs, std::string iip, std::string ad, std::string brtel){
    if(studenti.find(ind) != studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
    studenti[ind]=new Student(ind, gs, iip,ad,brtel);
    /*studenti[ind]->god_studija=gs;
    studenti[ind]->ime_i_prezime=iip;
    studenti[ind]->adresa=ad;
    studenti[ind]->broj_telefona=brtel;*/
}

void Administracija::RegistrirajNoviLaptop(int evbr, std::string n, std::string k){
    if(laptopi.find(evbr) != laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    laptopi[evbr]=new Laptop(evbr, n, k);
}

void Administracija::IzlistajStudente(){
    for(auto it(studenti.begin()); it != studenti.end(); it++){
        std::cout << "Broj indeksa:"  << it->first << std::endl;
        std::cout << "Godina studija" << it->second->DajGodinuStudija()<< std::endl;
        std::cout << "Ime i prezime: " << it->second->DajImePrezime() << std::endl;
        std::cout << "Adresa: "<< it->second->DajAdresu() << std::endl;
        std::cout << "Telefon: " << it->second->DajTelefon() << std::endl << std::endl;
    }
}

void Administracija::IzlistajLaptope(){
    for(auto it(laptopi.begin()); it != laptopi.end(); it++){
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naziv: " << it->second->DajNaziv() << std::endl;
        std::cout << "Karakteristike: " << it->second->DajKarakteristike() << std::endl;
        if(it->second->DaLiJeZaduzen()){
            std::cout << "Zaduzio(la): " << it->second->DajKodKogaJe().DajImePrezime()<< " (" << it->second->DajKodKogaJe().DajIndeks() << ")" << std::endl;
        }
        std::cout << std::endl;
    }
}
//procitaj tekst again
void Administracija::ZaduziLaptop(int inde, int evidbr){
    NadjiStudenta(inde);
    NadjiLaptop(evidbr);
    if(NadjiLaptop(evidbr).DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
    NadjiLaptop(evidbr).Zaduzi(NadjiStudenta(inde));
   
}

void Administracija::PrikaziZaduzenja() const{
    bool pom(true);
    for(auto it1(studenti.begin()); it1 != studenti.end(); it1++){
        for(auto it2(laptopi.begin()); it2 != laptopi.end(); it2++){
            pom=false;
            std::cout << "Student " << it1->second->DajImePrezime() << " (" << it1->second->DajIndeks() << ") zaduzio/la laptop broj " << it2->first << std::endl;
        }
    }
    if(pom) std::cout << "Nema zaduzenja" << std::endl;
}

int main ()
{
    for(;;){
        std::cout << "Izaberite zeljenu opciju: " << std::endl;
        std::cout << "1 za unos studenta, 2 za unos laptopa, 3 za ispis, 4 za zaduzivanje laptopa, 5 za razduzivanje, 6 izlistaj laptope zaduzene od jednog studenta, 0 za izlaz: ";
        int opcija; 
        std::cin >> opcija;
        Administracija nesto;
        switch(opcija){
            case 1:{
                try{
                std::cout << "Unesite broj indeksa, godinu studija, ime i prezime, adresu i telefon: ";
                std::string god, iip, ad, tel;
                int ind;
                //nije dobro uzima samo jednu rijeci mozda da ides preko getline ??
                // kako da skontam koji mi je parametar neispravan ??
                std::cin >> ind >> god >> iip >> ad  >> tel;
                nesto.RegistrirajNovogStudenta(ind, god, iip, ad, tel);
                }catch(std::domain_error izuzetak){
                    std::cout << izuzetak.what() << std::endl;
                }
            break;
            
            }
            case 2:{
                std::cout << "Unesite evidencijski broj, naziv i karakteristike: " ;
                std::string naziv, kark;
                int ev_broj;
                std::cin >> ev_broj >> naziv >> kark;
                nesto.RegistrirajNoviLaptop(ev_broj, naziv, kark);
            }
            case 3: {
                nesto.IzlistajStudente();
                nesto.IzlistajLaptope();
                break;
            }
            case 4: {
                std::cout << "Unesite broj indeksa i evidencijski broj: " ;
                int ind, ev_broj;
                std::cin >> ind >> std::ws >> ev_broj;
                nesto.ZaduziLaptop(ind, ev_broj);
                break;
            }
            case 5: {
                std::cout << "Unesite evidencijski broj: ";
                int ev_broj;
                std::cin >> ev_broj;
                nesto.RazduziLaptop(ev_broj);
                break;
            }
            case 6:{
                nesto.PrikaziZaduzenja();
                break;
            }
            default: goto izlaz;
            
        }
    }
    izlaz:
    return 0;
}
