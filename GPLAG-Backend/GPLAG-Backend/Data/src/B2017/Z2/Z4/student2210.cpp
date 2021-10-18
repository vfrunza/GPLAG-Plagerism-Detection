#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
 
class ApstraktniStudent
{
    std::string ime,prezime;
    int brindeksa,brpolozenih;
    double prosjecna;
    friend class Student;
public:
    ApstraktniStudent(std::string ime,std::string prezime,int brindeksa): ime(ime),prezime(prezime),brindeksa(brindeksa),brpolozenih(0),prosjecna(5) {};
    std::string DajIme() const {
        return ime;
    }
    std::string DajPrezime() const {
        return prezime;
    }
    int DajBrojIndeksa() const {
        return brindeksa;
    }
    int DajBrojPolozenih() const {
        return brpolozenih;
    }
    double DajProsjek() const {
        return prosjecna;
    }
    void RegistrirajIspit(int oc) {
        if(oc<5 || oc>10) throw std::domain_error("Neispravna ocjena");
        if(oc!=5) {
            prosjecna=(prosjecna*brpolozenih+oc)/(brpolozenih+1);
            brpolozenih++;
        }
    }
    void PonistiOcjene() {
        brpolozenih=0;
        prosjecna=5;
    }
    virtual void IspisiPodatke() const=0;
    virtual ApstraktniStudent *DajKopiju() const=0;
    virtual ~ApstraktniStudent() {};
};
 
class StudentBachelor: public ApstraktniStudent
{
public:
    StudentBachelor(std::string ime,std::string prezime,int brindeksa): ApstraktniStudent(ime,prezime,brindeksa) {};
    void IspisiPodatke() const override {
    std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
    }
    ApstraktniStudent *DajKopiju() const override {
        return new StudentBachelor(*this);
    }
};
 
class StudentMaster: public ApstraktniStudent
{
    int godina;
public:
    StudentMaster(std::string ime,std::string prezime,int brindeksa,int godina): ApstraktniStudent(ime,prezime,brindeksa), godina(godina) {};
    void IspisiPodatke() const override {
        std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godina<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
    }
    ApstraktniStudent *DajKopiju() const override {
        return new StudentMaster(*this);
    }
};
 
class Student
{
    ApstraktniStudent *pok;
public:
    Student(): pok(nullptr){};
    ~Student() {delete pok;};
    Student(const ApstraktniStudent &s): pok(s.DajKopiju()){};
    Student(const Student &s)
    {
        if(!s.pok) pok=nullptr;
        else pok=s.pok->DajKopiju();
    };
    Student &operator=(const Student &s)
    {
        ApstraktniStudent *pnovi(nullptr);
        if(s.pok!=nullptr) pnovi=s.pok->DajKopiju();
        delete pok;
        pok=pnovi;
        return *this;
    }
    Student &operator =(Student &&s)
    {
        std::swap(pok,s.pok);
        return *this;
    }
    void IspisiPodatke() const {pok->IspisiPodatke();}
   
    std::string DajIme() const {
        return pok->DajIme();
    }
    std::string DajPrezime() const {
        return pok->DajPrezime();
    }
    int DajBrojIndeksa() const {
        return pok->DajBrojIndeksa();
    }
    int DajBrojPolozenih() const {
        return pok->DajBrojPolozenih();
    }
    double DajProsjek() const {
        return pok->DajProsjek();
    }
    void RegistrirajIspit(int oc) {
        pok->RegistrirajIspit(oc);
    }
        void PonistiOcjene() {
        pok->brpolozenih=0;
        pok->prosjecna=5;
    }
};
 
int main()
{
    Student s1, s2;
    s1 = StudentBachelor("Dusko", "Dugousko", 1234);
    s2 = StudentMaster("Paja", "Patak", 4312, 2015);
    s1.RegistrirajIspit(6); s1.RegistrirajIspit(9);
    s2.RegistrirajIspit(8);
    s1.IspisiPodatke(); s2.IspisiPodatke();
    s1 = s2;
    s1.IspisiPodatke();
    return 0;
}