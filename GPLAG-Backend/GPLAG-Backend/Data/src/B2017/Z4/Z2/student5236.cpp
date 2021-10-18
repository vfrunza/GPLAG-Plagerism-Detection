/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>

class ApstraktniStudent{
    protected:
    std::string ime;
    std::string prezime;
    int indeks,br_polozenih;
    double pr_ocjena;
    public:
    ApstraktniStudent(const std::string &ime,const std::string &prezime,int indeks){
        ApstraktniStudent::ime=ime;ApstraktniStudent::prezime=prezime;ApstraktniStudent::indeks=indeks;
        br_polozenih=0;pr_ocjena=5;
    }
    std::string DajIme() const{ return ime; }
    std::string DajPrezime() const{return prezime;}
    int DajBrojIndeksa() const{return indeks; }
    int DajBrojPolozenih() const{return br_polozenih;}
    double DajProsjek() const{ return pr_ocjena; }
    void RegistrirajIspit(int ocjena){
        if(ocjena<5 || ocjena >10)
        throw std::domain_error("Neispravna ocjena");
        if(ocjena>5){
            br_polozenih+=1;
            pr_ocjena+=ocjena/br_polozenih;
        }
    }
    void PonistiOcjene(){ br_polozenih=0;pr_ocjena=5; }
    virtual ApstraktniStudent *DajKopiju() const=0;
    virtual void IspisiPodatke() const=0;
};

struct StudentBachelor :public ApstraktniStudent{

    void IspisiPodatke() const override{
        std::cout<<"Student bachelor studija "<<ime<<" "<<prezime<<", sa brojem indeksa "
        <<indeks<<", ima prosjek "<<pr_ocjena<<".";
    }
    ApstraktniStudent *DajKopiju() const override {return new StudentBachelor(*this);}
};
class StudentMaster :public ApstraktniStudent{
    int godina;
    public:
    StudentMaster(const std::string &ime,const std::string &prezime,int indeks,int godina):
        ApstraktniStudent(ime,prezime,indeks),godina(godina) {}
    void IspisiPodatke() const override{
        std::cout<<"Student master studija "<<ime<<" "<<prezime<<", sa brojem indeksa "
        <<indeks<<", zavrsio bachelor studij godine "<<godina<<", ima prosjek "<<pr_ocjena<<".";
    }
    ApstraktniStudent *DajKopiju() const override {return new StudentMaster(*this);}
};
int main ()
{
	return 0;
}
