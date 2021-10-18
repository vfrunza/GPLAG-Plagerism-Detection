/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <map>


class Student
{
    int broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa, broj_telefona;
public:
    Student(int br_ind, std::string god, std::string ime, std::string ad, std::string br):
        broj_indeksa(br_ind), adresa(ad) {
        for(int i=0; i<ime.length();) {
            while(ime.at(i++) == ' ' && i<ime.length());
            if(i==ime.length()) break;
            i--;
            while(ime.at(i) != ' ' && i<ime.length()) {
                ime_i_prezime+=ime.at(i++);
                if(i>=ime.length()) break;
            }
            ime_i_prezime+=' ';
        }
        if(god.at(0) != '1' && god.at(0) != '2' && god.at(0) != '3' && god.length() == 1)
            throw std::domain_error("Neispravni parametri");
        if(god.length() > 1 && (god.at(1) != '/' || (god.at(2) != 'M' && god.at(2) != 'B' && god.at(2) != 'D')))
            throw std::domain_error("Neispravni parametri");
        godina_studija=god;

        if(*br.begin() > '9' || *br.begin() < '0' || *(br.end()-1) < '0' || *(br.end()-1) > '9') throw std::domain_error("Neispravni parametri");

        for(auto it=br.begin(); it!=br.end(); it++) {
            while(*it >= '0' && *it <= '9' && it!=br.end()) it++;
            if(*it != '/') throw std::domain_error("Neispravni parametri");
            it++;
            while(*it >= '0' && *it <= '9' && it!=br.end()) it++;
            if(*it != '-') throw std::domain_error("Neispravni parametri");
            else break;
        }
        broj_telefona=br;
    }
    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {
        std::string temp(godina_studija);
        if(temp.length()==1) {
            temp.push_back('/');
            temp.push_back('B');
        }
        return temp;
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
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
        std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
        std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
        std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
        std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
    }
};
class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;
    public:
    Laptop(int br, std::string naz, std::string kar): naziv(naz), karakteristike(kar), kod_koga_je(nullptr){
        if(br < 0) throw std::domain_error("Neispravni parametri");
        ev_broj=br;
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
        if(kod_koga_je != nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je = &s;
    }
    void Razduzi() {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() const {
        return kod_koga_je;
    }
    Student &DajKodKogaJe() const {
        if(!kod_koga_je) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe() const {
        return kod_koga_je;
    }
    void Ispisi() const {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
        std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
        std::cout<<"Karakteristike: "<<DajKarakteristike()<<std::endl;
    }
    
};
class Administracija
{
    std::map<int, new Student*> studenti;
    std::map<int, new Laptop*> laptopi;
    public:
    
};
int main ()
{
    try {
        Student s(18025, "1", "Emina Tahirovic", "Sta Te Briga", "000/0000000000-00");
        s.Ispisi();
        std::cout<<std::endl;
        Laptop l(17450, "ASUS K75V", "Intel Core i7, 2.3GHz, 4GB RAM");
        l.Ispisi();
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    return 0;
}
