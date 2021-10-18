/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;

class Student {
    int index;
    string godina_studija, ime_prezime, adresa, broj_telefona;
    
    bool DajBrojCifara(int n) {
        int brojac(0);
        while (n!=0) {
            brojac++;
            n/=10;
        }
        if (brojac==5) return true;
        return false;
    }
    public:
        Student(int index, string godina_studija, string ime_prezime, string adresa, string broj_telefona) { 
            if (!(DajBrojCifara(index))) throw std::domain_error ("Neispravni parametri")
            if (godina_studija!='1' && godina_studija!='2' && godina_studija!='3' && godina_studija!='1/B' && godina_studija!='2/B' && godina_studija!='3/B' && godina_studija!='1/M' && godina_studija!='2/M' && godina_studija!='3/M' && godina_studija!='1/D' && godina_studija!='2/D' && godina_studija!='\3/D') {
                throw std::domain_error ("Neispravni parametri");
            }
            Student::index=index; Student::godina_studija=godina_studija; Student::ime_prezime=ime_prezime; Student::adresa=adresa; Student::broj_telefona=broj_telefona;
    }
    int DajIndeks() const { return index; }
    string DajGodinuStudija() const { return godina_studija; } //FALI OVDE
    string DajImePrezime() const { return ime_prezime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return broj_telefona; }
    
    void Ispisi() { 
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
        std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
        std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
        std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
        std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
    }
    
};

class Laptop {
    int ev_broj;
    string naziv, karakteristike;
    Student *kod_koga_je;
    public:
        Laptop (int ev_broj_pom, string naziv_pom, string karakteristike_pom) {
            if (ev_broj_pom<0) throw std::domain_error ("Neispravni parametri");
            ev_broj=ev_broj_pom; naziv=naziv_pom; karakteristike=karakteristike_pom; kod_koga_je=nullptr;
        }
        int DajEvidencijskiBroj() const { return ev_broj; }
        string DajNaziv() const { return naziv; }
        string DajKarakteristike() const { return karakteristike; }
        
        void Zaduzi(Student &st) { kod_koga_je=&st; }
        
        void Razduzi() { if (kod_koga_je!=nullptr) kod_koga_je=nullptr; }
        
        bool DaLiJeZaduzen() { if(kod_koga_je==nullptr) return false; return true; }
        
        Student &DajKodKogaJe() const {
            if (kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
            else return *kod_koga_je;
        }
        
        Student* DajKodKogaJe() const { return kod_koga_je; }
        
        void Ispisi() const {
            std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
            std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
            std::cout<<"Karakteristike: "<<DajKarakteristike()<<std::endl;
        }
};

class Administracija {
    std::map<int, Student*>mapa1;
    std::map<int, Laptop*>mapa2;
    public:
        Administracija() {}
        
        ~Administracija() {
            for (auto it(mapa2.begin()); it!=mapa2.end(); it++) {
                if (it->second!=nullptr)
                    delete it->second;
            }
            for (auto it(mapa1.begin()); it!=mapa1.end(); it++) {
                if (it->second!=nullptr)
                    delete it->second;
            }
        }
        
        Administracija(const Administracija &a) {
            for (auto it1(a.mapa2.begin); it1!=a.mapa2.end; it1++) {
                mapa1[it1->first]=new Student(*it1->second);
            }
            for (auto it2(a.mapa1.begin()), it2!=a.mapa2.end; it2++) {
                mapa2[it2->first]=it2->second;
                it2->second=nullptr;
            }
        }
        
        Administracija(Administracija &&a) {
            for (auto it1(a.mapa1.begin); it1!=(a.mapa1.begin); it++) {
                mapa1[it1->first]=it1->second;
                it1->second=nullptr;
            }
            for (auto it2(a.mapa2.begin); it2!=(a.mapa.end); it2++) {
                mapa2[it2->first]=it2->second;
                it2->second=nullptr;
            }
        }
        
        Administracija &operator =(const Administracija &a) {
            if (&a==this) throw std::logic_error("Destruktivna samododjela!");
            for (auto it(std::begin(mapa2)); it!=std::end(mapa2); it++) {
                mapa2.erase(it->first);
            }
            mapa2.clear();
            {
                auto pom(mapa1.begin());
                for (auto it1(a.studenti.begin()); it1!=a.studenti.end(); it1++) {
                    for (; it2!=studenti.end(); it2++) {
                        mapa1[it1->first]=new Student (*it1->second);
                        it2++;
                        break;
                    }
                }
            }
            auto it2(mapa2.begin());
            for (auto it1(a.mapa2.begin()); it1!=a.mapa2.end(); it1++) {
                for (; it2!=mapa2.end(); it2++) {
                    it2->second = new Laptop(*it1->second);
                    it2++;
                    break;
                }
            }
            return *this;
        }
        
        Administracija &operator =(Administracija &&a) {
            std::swap(mapa1, a.mapa1);
            std::swap(mapa2, a.mapa2);
            return *this;
        }        
        
        void RegistrirajNovogStudenta(int indeks_pom, string godina_studija_pom, string ime_prezime_pom, string adresa_pom, string broj_telefona_pom) {
            if (mapa1.find(indeks_pom)!=mapa1.end()) throw std::domain_error ("Student s tim indeksom vec postoji");
            mapa1[indeks_pom]=new Student(indeks_pom, godina_studija_pom, ime_prezime_pom, adresa_pom, broj_telefona_pom);
            /*mapa1[indeks_pom]->ime_prezime=ime_prezime_pom;
            mapa1[indeks_pom]->adresa=adresa_pom;
            mapa1[indeks_pom]->broj_telefona=broj_telefona_pom;*/
        }
        
        void RegistrirajNoviLaptop(int ev_broj_pom, string pom1, string pom2) {
            if (mapa2.find(ev_broj_pom)!=mapa2.end()) throw std::domain_error ("Laptop s tim evidencijskim brojem vec postoji");
            mapa2[ev_broj_pom]=new Laptop(ev_broj_pom, pom1, pom2);
        }
        
        void IzlistajLaptope() {
            for (auto it(mapa2.begin()); it!=mapa2.end(); it++) {
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                std::cout<<"Naziv: "<<it->second->DajNaziv()<<std::endl;
                std::cout<<"Karakteristike: "<<it->second->DajKarakteristike()<<std::endl;
                if (it->second->DaLiJeZaduzen()) {
                    std::cout<<"Zaduzio(la): "<<it->second->DajKodKogaJe().DajImePrezime()<<" ("<<it->second->DajKodKogaJe().DajIndeks()<<")"<<std::endl;
                }
                std::cout<<std::endl;
            }
        }
        
        
        
        
};




int main () {
    for (;;) {
        int unos;
        std::cout<<"Moguce akcije: 1 - unos studenta,\n2 - unos laptopa,\n3 - ispis,\n4 - zaduzivanje laptopa,\n5 - razduzivanje laptopa,\n6 - lista laptopa,\n0 - izlaz";
        std::cout<<std::endl;
        std::cout<<"Izaberite akciju za poduzimanje: ";
        std::cin>>unos;
        if (unos==0) break;
        else if (uno1==1) {
            try {
                std::cout<<"Unesite broj indeksa, godinu studija, ime i prezime studenta, adresu i telefon studenta: ";
                
            }
        }
        
        
        
    }
    
    
    
    
    
	return 0;
}
