/B2017/2018: Zadaća 5, Zadatak 1
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stdexcept>
#include<map>
#include<utility>
#include<algorithm>
class Student {
    int broj_indeksa;
    std::string godina_studija, imeprezime, adresa, broj_telefona;
    bool ProvjeraIndeksa(int broj);
    bool ProvjeraGodineStudija(std::string god);
    std::string StringBezRazmaka(std::string s);
    bool ProvjeraBrojaTelefona(std::string brojtel);
    public:
    Student(int broj_indeksa, std::string godina_studija, std::string imeprezime, std::string adresa, std::string broj_telefona) {
        if(!ProvjeraIndeksa(broj_indeksa) || !ProvjeraGodineStudija(godina_studija) || !ProvjeraBrojaTelefona(broj_telefona)) throw std::domain_error("Neispravni parametri");
        this->broj_indeksa=broj_indeksa;
        this->godina_studija=godina_studija;
        this->imeprezime=StringBezRazmaka(imeprezime);
        this->adresa=StringBezRazmaka(adresa);
        this->broj_telefona=broj_telefona;
    }
    int DajIndeks() const { return broj_indeksa; }
    std::string DajGodinuStudija() const { 
        if(godina_studija=="1" || godina_studija=="2" || godina_studija=="3") return godina_studija+"/B";
        return godina_studija;
    }
    std::string DajImePrezime() const { return imeprezime; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return broj_telefona; }
    void Ispisi() const { std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl<<"Godina studija: "<<DajGodinuStudija()<<std::endl<<"Ime i prezime: "<<DajImePrezime()<<std::endl<<"Adresa: "<<DajAdresu()<<std::endl<<"Telefon: "<<DajTelefon()<<std::endl; }
};
bool Student::ProvjeraIndeksa(int broj) {
    int br(0);
    while (broj!=0) {
        broj/=10;
        br++;
    }
    if(br!=5) return false;
    return true;
}
bool Student::ProvjeraGodineStudija(std::string god) {
    std::vector<std::string> godine{"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
    for(auto g: godine) {
        if(g==god) return true;
    }
    return false;
}
std::string Student::StringBezRazmaka(std::string s) {
    std::string bezrazmaka;
    for(int i=0; i<s.size(); i++) {
        if(s[i]==' ') {
            while(s[i]==' ' && i<s.size()) i++;
        }
        if(i==s.size()) break;
        if(s[i]!=' ') {
            while(s[i]!=' ' && i<s.size()) {
                bezrazmaka.push_back(s[i]);
                i++;
            }
            bezrazmaka.push_back(' ');
        }
        if(i==s.size()) break;
    }
    bezrazmaka.erase(bezrazmaka.begin()+bezrazmaka.size()-1);
    return bezrazmaka;
}
bool Student::ProvjeraBrojaTelefona(std::string brojtel) {
    for(int i=0; i<brojtel.size(); i++) {
        if(brojtel[i]>='0' && brojtel[i]<='9') {
            while(brojtel[i]>='0' && brojtel[i]<='9' && i<brojtel.size()) i++;
            if(brojtel[i]=='/') {
                i++;
                while(brojtel[i]>='0' && brojtel[i]<='9' && i<brojtel.size()) i++;
                if(i==brojtel.size()) return false;
                if(brojtel[i]=='-') {
                    i++;
                    while(brojtel[i]>='0' && brojtel[i]<='9' && i<brojtel.size()) i++;
                    if(i==brojtel.size()) return true;
                }
            }
        }
        return false;
    }
    return false;
}
class Laptop {
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *kod_koga_je;
    public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) {
        if(ev_broj<0) throw std::domain_error("Neispravni parametri");
        this->ev_broj=ev_broj;
        this->naziv=naziv;
        this->karakteristike=karakteristike;
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    bool DaLiJeZaduzen() const {
        if(!kod_koga_je) return false;
        return true;
    }
    void Zaduzi(Student &student) { 
        if(kod_koga_je) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=&student;
    }
    void Razduzi() {
        if(!kod_koga_je) return;
        delete kod_koga_je;
        kod_koga_je=nullptr;
    }
    Student &DajKodKogaJe() {
        if(!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe() const { return kod_koga_je; }
    void Ispisi() const { std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl<<"Naziv: "<<DajNaziv()<<std::endl<<"Karakteristike: "<<DajKarakteristike()<<std::endl; }
};
class Administracija {
    std::map<int,Student*> studenti;
    std::map<int,Laptop*> laptopi;
    public:
    Administracija()=default;
    Administracija(const Administracija &a);
    Administracija(Administracija &&a);
    Administracija &operator=(const Administracija &a);
    Administracija &operator=(Administracija &&a);
    ~Administracija() {
        for(auto it=studenti.begin(); it!=studenti.end(); it++) delete it->second;
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++) delete it->second;
    }
    void RegistrirajNovogStudenta(int brojindeksa, std::string godina, std::string imeiprez, std::string adress, std::string brojtel);
    void RegistrirajNoviLaptop(int evidencijskibroj, std::string nazivl, std::string karakt);
    Student &NadjiStudenta(int brojindeksa);
    Student NadjiStudenta(int brojindeksa) const;
    Laptop &NadjiLaptop(int evidencijskibroj);
    Laptop NadjiLaptop(int evidencijskibroj) const;
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int brojindeksa, int evidencijskibroj);
    void PrikaziZaduzenja() const;
    int NadjiSlobodanLaptop() const;
    void RazduziLaptop(int evidencijskibroj);
};
Administracija::Administracija(const Administracija &a) {
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
        Student *pok=new Student(it->second->DajIndeks(),it->second->DajGodinuStudija(),it->second->DajImePrezime(),it->second->DajAdresu(),it->second->DajTelefon());
        this->studenti.insert(std::make_pair(it->first,pok));
        pok=nullptr;
    }
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) {
        Laptop *pok=new Laptop(it->second->DajEvidencijskiBroj(),it->second->DajNaziv(),it->second->DajKarakteristike());
        Student kodk(*(it->second->DajPokKodKogaJe()));
        pok->Zaduzi(kodk);
        this->laptopi.insert(std::make_pair(it->first,pok));
        pok=nullptr;
    }   
}
Administracija::Administracija(Administracija &&a) {
    this->laptopi=a.laptopi;
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) it->second=nullptr;
    this->studenti=a.studenti;
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) it->second=nullptr;
}
Administracija &Administracija::operator=(const Administracija &a) {
    for(auto it=this->laptopi.begin(); it!=this->laptopi.end(); it++) if(it->second) delete it->second;
    for(auto it=this->studenti.begin(); it!=this->studenti.end(); it++) if(it->second) delete it->second;
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) {
        Student *pok=new Student(it->second->DajIndeks(),it->second->DajGodinuStudija(),it->second->DajImePrezime(),it->second->DajAdresu(),it->second->DajTelefon());
        this->studenti.insert(std::make_pair(it->first,pok));
        pok=nullptr;
    }
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) {
        Laptop *pok=new Laptop(it->second->DajEvidencijskiBroj(),it->second->DajNaziv(),it->second->DajKarakteristike());
        Student kodk(*(it->second->DajPokKodKogaJe()));
        pok->Zaduzi(kodk);
        this->laptopi.insert(std::make_pair(it->first,pok));
        pok=nullptr;
    }
    return *this;
}
Administracija &Administracija::operator=(Administracija &&a) {
    for(auto it=this->studenti.begin(); it!=this->studenti.end(); it++) delete it->second;
    for(auto it=this->laptopi.begin(); it!=this->laptopi.end(); it++) delete it->second;
    this->studenti=a.studenti;
    this->laptopi=a.laptopi;
    for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) it->second=nullptr;
    for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) it->second=nullptr;
    return *this;
}
void Administracija::RegistrirajNovogStudenta(int brojindeksa, std::string godina, std::string imeiprez, std::string adress, std::string brojtel) {
    auto ima(studenti.find(brojindeksa));
    if(ima!=studenti.end()) throw std::domain_error("Student s tim indeksom vec postoji");
    Student *pok=new Student(brojindeksa,godina,imeiprez,adress,brojtel);
    studenti.insert(std::make_pair(brojindeksa,pok));
    pok=nullptr;
}
void Administracija::RegistrirajNoviLaptop(int evidencijskibroj, std::string nazivl, std::string karakt) {
    auto ima(laptopi.find(evidencijskibroj));
    if(ima!=laptopi.end()) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    Laptop *pok=new Laptop(evidencijskibroj,nazivl,karakt);
    laptopi.insert(std::make_pair(evidencijskibroj,pok));
    pok=nullptr;
}
Student &Administracija::NadjiStudenta(int brojindeksa) {
    auto nadji(studenti.find(brojindeksa));
    if(nadji==studenti.end()) throw std::domain_error("Student nije nadjen");
    return *nadji->second;
}
Student Administracija::NadjiStudenta(int brojindeksa) const {
    auto nadji(studenti.find(brojindeksa));
    if(nadji==studenti.end()) throw std::domain_error("Student nije nadjen");
    return *nadji->second;
}
Laptop &Administracija::NadjiLaptop(int evidencijskibroj) {
    auto nadji(laptopi.find(evidencijskibroj));
    if(nadji==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *nadji->second;
}
Laptop Administracija::NadjiLaptop(int evidencijskibroj) const {
    auto nadji(laptopi.find(evidencijskibroj));
    if(nadji==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    return *nadji->second;
}
void Administracija::IzlistajStudente() const {
    for(auto it=studenti.begin(); it!=studenti.end(); it++) {
        it->second->Student::Ispisi();
        std::cout<<std::endl;
    }
}
void Administracija::IzlistajLaptope() const {
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        it->second->Laptop::Ispisi();
        auto kodk(it->second->DajPokKodKogaJe());
        if(kodk) std::cout<<"Zaduzio(la): "<<kodk->DajImePrezime()<<" ("<<kodk->DajIndeks()<<")"<<std::endl;
        std::cout<<std::endl;
    }
}
void Administracija::ZaduziLaptop(int brojindeksa, int evidencijskibroj) {
    auto nadjistudenta(studenti.find(brojindeksa));
    auto nadjilaptop(laptopi.find(evidencijskibroj));
    if(nadjistudenta==studenti.end()) throw std::domain_error("Student nije nadjen");
    if(nadjilaptop==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    if(nadjilaptop->second->DajPokKodKogaJe()) throw std::domain_error("Laptop vec zaduzen");
    for(auto i=laptopi.begin(); i!=laptopi.end(); i++) {
        auto kkj(i->second->DajPokKodKogaJe());
        if(kkj) {
            if(kkj->DajIndeks()==brojindeksa) throw std::domain_error("Student vec zaduzio laptop");
        }
    }
    nadjilaptop->second->Zaduzi(*nadjistudenta->second);
}
void Administracija::PrikaziZaduzenja() const {
    if(laptopi.size()==0) std::cout<<"Nema zaduzenja"<<std::endl;
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        if(it->second->DaLiJeZaduzen()) std::cout<<"Student "<<it->second->DajKodKogaJe().DajImePrezime()<<" ("<<it->second->DajKodKogaJe().DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<std::endl;
    }
}
int Administracija::NadjiSlobodanLaptop() const {
    auto slobodni(std::find_if(laptopi.begin(),laptopi.end(),[](std::pair<int,Laptop*> p) { if(!p.second->DaLiJeZaduzen()) return true; else return false;}));
    if(slobodni==laptopi.end()) throw std::domain_error("Nema slobodnih laptopa");
    return slobodni->first;
}
void Administracija::RazduziLaptop(int evidencijskibroj) {
    auto razduzi(laptopi.find(evidencijskibroj));
    if(razduzi==laptopi.end()) throw std::domain_error("Laptop nije nadjen");
    else if(razduzi->second->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    razduzi->second->Razduzi();
}
int main () {
    try {
 
    /* Administracija etf;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");


    etf.RegistrirajNovogStudenta(14212, "1","Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    etf.RegistrirajNovogStudenta(17525, "3", "Ante" ,"Trg vjecnih studenata 11", "062/582-757");

    etf.ZaduziLaptop(14212, 122);
    etf.ZaduziLaptop(17525,331);
    etf.IzlistajLaptope();*/
    
    Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    
    etf.ZaduziLaptop(14212, 123);
    etf.ZaduziLaptop(17528, 331);
    int ima (etf.NadjiSlobodanLaptop());
    etf.PrikaziZaduzenja();
    std::cout<<ima;
    }
    catch(std::domain_error izuz) {
        std::cout<<izuz.what();
    }
	return 0;
}
