/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include<string>
#include <map>

class Student
{
    int broj_indeksa;
    std::string godina_studija;
    std::string imeprezime,broj_telefona,adresa;
public:
    Student(int broj_indeksa, std::string godina_studija, std::string imeprezime,std::string adresa, std::string broj_telefona);
    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {
        return godina_studija;
    }
    std::string DajImePrezime() const {
        return imeprezime;
    }
    std::string DajTelefon() const {
        return broj_telefona;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    void Ispisi() const;
};

class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student *p;
public:
    Laptop(int ev_broj, std::string naziv, std::string karakteristike): naziv(naziv), karakteristike(karakteristike),p(0) {
        if(ev_broj<0) throw std::domain_error("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
    }
    int DajEvidencijskiBroj()const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakteristike()const {
        return karakteristike;
    }
    void Zaduzi(Student &s) {
        if(p!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        p=&s;
    }
    void Razduzi() {
        if(p!=nullptr) p=nullptr;
    }
    bool DaLiJeZaduzen() {
        if(p!=nullptr) return true;
        return false;
    }
    Student*& DajKodKogaJe() {
        if(p==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return p;
    }

    Student* DajPokKodKogaJe()const {
        return p;
    }
    void Ispisi() const;

};

class Administracija
{
    std::map<Student, int> studenti;
    std::map<Laptop, int> laptopi;
public:
    Administracija() {}
    Administracija(Administracija &&a) {
        studenti=a.studenti;
        a.studenti.clear();
        laptopi=a.laptopi;
        a.laptopi.clear();
    }
    Administracija &operator =(Administracija &&a) {
        studenti=a.studenti;
        a.studenti.clear();
        laptopi=a.laptopi;
        a.laptopi.clear();
        return *this;
    }
    void RegistrirajNovogStudenta(int broj_indeksa, std::string godina_studija, std::string imeprezime,std::string adresa, std::string broj_telefona) {
        for(auto it=studenti.begin(); it!=studenti.end(); it++) {
            if(it->second==broj_indeksa) throw std::domain_error ("Student sa tim indeksom vec postoji");
        }

    }
};

Student::Student(int broj_indeksa,std::string godina_studija, std::string imeprezime, std::string adresa, std::string broj_telefona)
{
    Student::broj_indeksa=broj_indeksa;
    if(godina_studija!="1" && godina_studija!="2" && godina_studija!="3" && godina_studija!="1/B" && godina_studija!="2/B" && godina_studija!="3/B" && godina_studija!="1/M" && godina_studija!="2/M" && godina_studija!="1/D" && godina_studija!="2/D" && godina_studija!="3/D") throw std::domain_error("Neispravni parametri");
    else (Student::godina_studija=godina_studija);
    std::cout<<Student::godina_studija;
    bool space(false);
    int n(imeprezime.length()), i(0),j(-1);
    while(++j<n && imeprezime[j]==' ');
    while(j<n) {
        if(imeprezime[j]!=' ') {
            if(i-1>=0 && imeprezime[i-1]==' ') imeprezime[i-1]=imeprezime[j++];
            else imeprezime[i++]=imeprezime[j++];
            space=false;
        } else if(imeprezime[j++]==' ') {
            if(!space) {
                imeprezime[i++]=' ';
                space=true;
            }
        }
    }
    if(i<=1) imeprezime.erase(imeprezime.begin()+i,imeprezime.end());
    else imeprezime.erase(imeprezime.begin()+i-1, imeprezime.end());
    Student::imeprezime=imeprezime;
    space=false;
    n=(adresa.length()), i=0,j=-1;
    while(++j<n && adresa[j]==' ');
    while(j<n) {
        if(adresa[j]!=' ') {
            if(i-1>=0 && adresa[i-1]==' ') adresa[i-1]=adresa[j++];
            else adresa[i++]=adresa[j++];
            space=false;
        } else if(adresa[j++]==' ') {
            if(!space) {
                adresa[i++]=' ';
                space=true;
            }
        }
    }
    if(i<=1) adresa.erase(adresa.begin()+i,adresa.end());
    else adresa.erase(adresa.begin()+i-1, adresa.end());
    Student::adresa=adresa;
    i=0;
    while(broj_telefona[i]<=9 && broj_telefona[i]>=0) i++;
    if(broj_telefona[i]!='/') throw std::domain_error ("Neispravni parametri");
    i++;
    while(broj_telefona[i]<=9 && broj_telefona[i]>=0) i++;
    if(broj_telefona[i]!='-') throw std::domain_error("Neispravni parametri");
    i++;
    while(broj_telefona[i]<=9 && broj_telefona[i]>=0 && i<n) i++;
    if(i+1!=n) throw std::domain_error("Neispravni parametri");
}

void Student::Ispisi() const
{
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
    std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
    std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
}

void Laptop::Ispisi() const
{
    std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
    std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
    std::cout<<"Karakteristike: "<<DajKarakteristike()<<std::endl;
}
int main ()
{
    return 0;
}
