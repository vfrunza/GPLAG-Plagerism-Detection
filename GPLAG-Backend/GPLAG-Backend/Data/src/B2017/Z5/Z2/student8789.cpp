/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <utility>
#include <algorithm>
#include <memory>

class Student{
    int broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa, broj_telefona;
public:
    Student(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona){
        if(broj_indeksa >= 100000 || broj_indeksa <= 9999 || broj_indeksa < 0) throw std::domain_error("Neispravni parametri");
        Student::broj_indeksa = broj_indeksa;
        if(godina_studija == "1" || godina_studija == "2" || godina_studija == "3" || godina_studija == "1/B" || godina_studija == "2/B" || godina_studija == "3/B" || godina_studija == "1/M" || godina_studija == "2/M" || godina_studija == "1/D" || godina_studija == "2/D" || godina_studija == "3/D") Student::godina_studija = godina_studija;
        else throw std::domain_error("Neispravni parametri");
        std::string novi;
        bool zadnji_je_znak(false);
        for(auto i : ime_i_prezime){
            if(i == ' ') zadnji_je_znak = true;
            else if(zadnji_je_znak && i != ' '){
                zadnji_je_znak = false;
                if(novi.size() != 0) novi += ' ';
            }
            if(zadnji_je_znak == false && i != ' '){
                novi += i;
            }
        }
        Student::ime_i_prezime = novi;
        zadnji_je_znak = false;
        novi.clear();
        for(auto i : adresa){
            if(i == ' ') zadnji_je_znak = true;
            else if(zadnji_je_znak && i != ' '){
                zadnji_je_znak = false;
                if(novi.size() != 0) novi += ' ';
            }
            if(zadnji_je_znak == false && i != ' '){
                novi += i;
            }
        }
        Student::adresa = novi;
        zadnji_je_znak = false;
        bool prvi_dio(false);
        int brojac(0);
        for(auto i : broj_telefona){
            if(!prvi_dio){
                if(zadnji_je_znak && i == '/' && brojac == 0){ 
                    zadnji_je_znak = false;
                    brojac++;
                    prvi_dio = true;
                }
                else if(!(i >= '0' && i <= '9')) throw std::domain_error("Neispravni parametri");
                else zadnji_je_znak = true;
            }
            else{
                if(zadnji_je_znak && i == '-' && brojac == 1){ 
                    zadnji_je_znak = false;
                    brojac++;
                }
                else if(!(i >= '0' && i <= '9')) throw std::domain_error("Neispravni parametri");
                else zadnji_je_znak = true;
            }
        }
        if(brojac==2 && zadnji_je_znak) Student::broj_telefona = broj_telefona;
        else throw std::domain_error("Neispravni parametri");
    }
    
    int DajIndeks() const{ return broj_indeksa; }
    
    std::string DajGodinuStudija() const{
        if(godina_studija == "1") return "1/B";
        else if(godina_studija == "2") return "2/B";
        else if(godina_studija == "3") return "3/B";
        else return godina_studija; 
    }
    std::string DajImePrezime() const{ return ime_i_prezime; }
    std::string DajAdresu() const{ return adresa; }
    std::string DajTelefon() const{ return broj_telefona; }
    void Ispisi(){
        std::cout << "Broj indeksa: " << DajIndeks() << "\nGodina studija: " << DajGodinuStudija() << "\nIme i prezime: " << DajImePrezime() << "\nAdresa: " << DajAdresu() << "\nTelefon: " << DajTelefon() << std::endl;
    }
    
};

class Laptop{
    int ev_broj;
    std::string naziv, karakteristike;
    Student* kod_koga_je;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike) : naziv(naziv), karakteristike(karakteristike){
        if(ev_broj < 0) throw std::domain_error("Neispravni parametri");
        Laptop::ev_broj = ev_broj;
        Laptop::kod_koga_je = nullptr;
    }
    
    int DajEvidencijskiBroj() const{ return ev_broj; }
    
    std::string DajNaziv() const{ return naziv; }
    
    std::string DajKarakteristike() const{ return karakteristike; }
    
    void Zaduzi(Student &ko_zaduzuje){
        if(kod_koga_je) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je = &ko_zaduzuje;
    }
    
    void Razduzi(){
        if(DaLiJeZaduzen()) kod_koga_je = nullptr;
    }
    
    bool DaLiJeZaduzen(){ return kod_koga_je != 0; }
    
    Student& KodKogaJe(){
        if(!DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    
    Student* DajPokKodKogaJe() { return kod_koga_je; }
    
    void Ispisi() const{
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << "\nNaziv: " << DajNaziv() << "\nKarakteristike: " << DajKarakteristike() << std::endl;
    }
};

class Administracija{
    std::map<int, std::shared_ptr<Student>> mapa_studenata;
    std::map<int, std::shared_ptr<Laptop>> mapa_laptopa;
public:
    Administracija(){};
    Administracija(const Administracija& staro){
        for(auto& nova_mapa : staro.mapa_studenata){
            (*this).RegistrirajNovogStudenta(nova_mapa.first, nova_mapa.second->DajGodinuStudija(), nova_mapa.second->DajImePrezime(), nova_mapa.second->DajAdresu(), nova_mapa.second->DajTelefon());
        }
        for(auto& nova_mapa : staro.mapa_laptopa){
            (*this).RegistrirajNoviLaptop(nova_mapa.first, nova_mapa.second->DajNaziv(), nova_mapa.second->DajKarakteristike());
        }
    }
    
    Administracija(Administracija&& staro){
        (*this).mapa_studenata = staro.mapa_studenata;
        (*this).mapa_laptopa = staro.mapa_laptopa;
        for(auto& nova_mapa : staro.mapa_studenata)
            nova_mapa.second = nullptr;
        for(auto& nova_mapa : staro.mapa_laptopa)
            nova_mapa.second = nullptr;
    }
    
    Administracija &operator =(const Administracija& staro){
            for(auto& nova_mapa : staro.mapa_studenata){
                (*this).RegistrirajNovogStudenta(nova_mapa.first, nova_mapa.second->DajGodinuStudija(), nova_mapa.second->DajImePrezime(), nova_mapa.second->DajAdresu(), nova_mapa.second->DajTelefon());
            }
            for(auto& nova_mapa : staro.mapa_laptopa){
                (*this).RegistrirajNoviLaptop(nova_mapa.first, nova_mapa.second->DajNaziv(), nova_mapa.second->DajKarakteristike());
            }
        return *this;
    }
    
    Administracija &operator =(Administracija&& staro){
        std::swap(mapa_studenata, staro.mapa_studenata); std::swap(mapa_laptopa, staro.mapa_laptopa);
        return *this;
    }
    
    //~Administracija(){
    //    for(auto& nova_mapa : mapa_studenata) delete nova_mapa.second;
    //    for(auto& nova_mapa : mapa_laptopa) delete nova_mapa.second;
    //}
    
    void RegistrirajNovogStudenta(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona){
        for(auto& nova_mapa : mapa_studenata)
            if(nova_mapa.first == broj_indeksa) throw std::domain_error("Student s tim indeksom vec postoji");
        mapa_studenata[broj_indeksa] = std::make_shared<Student>(broj_indeksa, godina_studija, ime_i_prezime, adresa, broj_telefona);
    }
    
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv, std::string karakteristike){
        for(auto& nova_mapa : mapa_laptopa) 
            if(nova_mapa.first == ev_broj) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        mapa_laptopa[ev_broj] = std::make_shared<Laptop>(ev_broj, naziv, karakteristike);
    }
    
    Student& NadjiStudenta(int broj_indeksa){
        bool ima(false);
        for(auto& nova_mapa : mapa_studenata) 
            if(nova_mapa.first == broj_indeksa){ ima = true; break; }
        if(!ima) throw std::domain_error("Student nije nadjen");
        return *mapa_studenata[broj_indeksa];
    }
    
    Student& NadjiStudenta(int broj_indeksa) const{
        bool ima(false);
        std::pair<int, std::shared_ptr<Student>> novi;
        for(auto& nova_mapa : mapa_studenata) 
            if(nova_mapa.first == broj_indeksa){novi = nova_mapa; ima = true; break; }
        if(!ima) throw std::domain_error("Student nije nadjen");
        return *novi.second;
    }
    
    Laptop& NadjiLaptop(int ev_broj){
        bool ima(false);
        for(auto& nova_mapa : mapa_laptopa)
            if(nova_mapa.first == ev_broj){ ima = true; break; }
        if(!ima) throw std::domain_error("Laptop nije nadjen");
        return *mapa_laptopa[ev_broj];
    }
    
    Laptop& NadjiLaptop(int ev_broj) const{
        bool ima(false);
        std::pair<int, std::shared_ptr<Laptop>> novi;
        for(auto& nova_mapa : mapa_laptopa)
            if(nova_mapa.first == ev_broj){novi = nova_mapa; ima = true; break; }
        if(!ima) throw std::domain_error("Laptop nije nadjen");
        return *novi.second;
    }
    
    void IzlistajStudente() const{
        for(auto& nova_mapa : mapa_studenata){
            nova_mapa.second->Ispisi();
            std::cout << std::endl;
        }
    }
    
    void IzlistajLaptope() const{
        for(auto& nova_mapa : mapa_laptopa){
            nova_mapa.second->Ispisi();
            //std::cout << std::endl;
            if(nova_mapa.second->DaLiJeZaduzen()){
                std::cout << "Zaduzio(la): " << nova_mapa.second->KodKogaJe().DajImePrezime() << " (" << nova_mapa.second->KodKogaJe().DajIndeks() << ")" << std::endl;
            }
            std::cout << std::endl;
        }
    }
    
    void ZaduziLaptop(int broj_indeksa, int ev_broj){
        NadjiStudenta(broj_indeksa);
        NadjiLaptop(ev_broj).DaLiJeZaduzen();
        for(auto& nova_mapa : mapa_laptopa){
            if(nova_mapa.second->DajPokKodKogaJe())
                if(nova_mapa.second->DajPokKodKogaJe()->DajIndeks() == broj_indeksa)
                    throw std::domain_error("Student je vec zaduzio laptop");
        }
        NadjiLaptop(ev_broj).Zaduzi(NadjiStudenta(broj_indeksa));
    }
    
    int NadjiSlobodanLaptop(){
        for(auto& nova_mapa : mapa_laptopa){
            if(!nova_mapa.second->DajPokKodKogaJe()) return nova_mapa.first;
        }
        throw std::domain_error("Nema slobodnih laptopa");
    }
    
    void RazduziLaptop(int ev_broj){
        //bool ima(false);
        //for(auto& nova_mapa : mapa_laptopa)
        //    if(nova_mapa.first == ev_broj){ ima = true; break; }
        //if(!ima) throw std::domain_error("")
        NadjiLaptop(ev_broj).DaLiJeZaduzen();
        NadjiLaptop(ev_broj).Razduzi();
    }
    
    void PrikaziZaduzenja() const{
        bool ima(false);
        for(auto& nova_mapa : mapa_laptopa){
            if(nova_mapa.second->DaLiJeZaduzen()){
                ima = true;    
                std::cout << "Student " << nova_mapa.second->KodKogaJe().DajImePrezime() << " (" << nova_mapa.second->KodKogaJe().DajIndeks() << ") zaduzio/la laptop broj " << nova_mapa.second->DajEvidencijskiBroj() << std::endl;
            }
        }
        if(!ima) std::cout << "Nema zaduzenja";
    }
    
};

int main ()
{
    /*Student novi(16877, "1" , "                     Neko ime        i prezime              ", "                  Neka aaa    a              adresa", "1/2-3");
    novi.Ispisi();
    Student novi1(11111, "1", "a a", "a a", "1/2-3");
    Laptop neki(3211, "a" , "b");
    neki.Zaduzi(novi);
    neki.Razduzi();
    neki.Zaduzi(novi1);
    neki.KodKogaJe().Ispisi();
    //neki.Razduzi();
    std::cout << neki.DajPokKodKogaJe();
    neki.Ispisi();
    Administracija novi;
    novi.RegistrirajNovogStudenta(11111, "1", "a a", "a a", "1/2-3");
    novi.RegistrirajNovogStudenta(11112, "2", "b b", "b b", "1/2-3");
    novi.RegistrirajNovogStudenta(11113, "3", "c c", "c c", "1/2-3");
    
    novi.RegistrirajNoviLaptop(1, "a", "a");
    novi.RegistrirajNoviLaptop(2, "b", "b");
    novi.RegistrirajNoviLaptop(3, "c", "c");
    
    novi.IzlistajStudente();
    novi.IzlistajLaptope();
    
    novi.ZaduziLaptop(11111, 1);
    novi.ZaduziLaptop(11112, 2);
    novi.ZaduziLaptop(11113, novi.NadjiSlobodanLaptop());
    
    novi.PrikaziZaduzenja();
    {
        Administracija novi1=novi;
        //novi1=novi;
    }
    novi.IzlistajStudente();
    //asd
	return 0;*/
}
