#include <iostream>
#include <string>
#include <stdexcept>
#include <string>
#include <vector>
class Student {
    void ProvjeriCifre ();
    void Izuzetak ();
    void ProvjeriGodinuStudija ();
    void ObradiImePrezime ();
    void ObradiAdresuStudenta();
    void ProvjeraBroja();
    int BrojIndexa;
    std::string GodinaStudija, ImePrezime,
                AdresaStudenta, BrojTelefonaStudenta;
public:
    Student (int BrojIndexa, std::string GodinaStudija, std::string ImePrezime,
    std::string AdresaStudenta, std::string BrojTelefonaStudenta);

    int DajIndeks ()const {return BrojIndexa;}
    std::string DajGodinuStudija  ()const { return GodinaStudija;}
    std::string DajImePrezime  () const {return ImePrezime;}
    std::string DajAdresu  ()const { return AdresaStudenta;}
    std::string DajTelefon  ()const { return  BrojTelefonaStudenta;}
    void Ispisi () const {

     std::cout<<"\n"
              <<"Broj indeksa: "<<BrojIndexa<<"\n"
              << "Godina studija: "<<GodinaStudija<<"\n"
              <<  "Ime i prezime: " <<ImePrezime<<"\n"
             <<  "Adresa: " <<AdresaStudenta<<"\n"
             <<  "Telefon:" <<BrojTelefonaStudenta<<"\n";

    }
};
void Student::ObradiImePrezime() {
std::string pomocna;
int i =0;
while (i!=ImePrezime.size() && ImePrezime.at(i) == ' ') i++;
    for (int j=i; j<ImePrezime.size(); j++)
    {   int pocetna (j);
        while (j<ImePrezime.size() && ImePrezime.at(j)!= ' ') j++;
        pomocna+=ImePrezime.substr(pocetna, j-pocetna);
        if (j!=ImePrezime.size() ) pomocna+=" ";
        while (j<ImePrezime.size() && ImePrezime.at(j)== ' ') j++;
        j--;
    }
ImePrezime = pomocna;
}
void Student::ObradiAdresuStudenta() {
    std::string pomocna;
    int i =0;
    while (i!=AdresaStudenta.size() && AdresaStudenta.at(i) == ' ') i++;
    for (int j=i; j<AdresaStudenta.size(); j++)
    {   int pocetna (j);
        while (j<AdresaStudenta.size() && AdresaStudenta.at(j)!= ' ') j++;
        pomocna+=AdresaStudenta.substr(pocetna, j-pocetna);
        if (j!=AdresaStudenta.size() ) pomocna+=" ";
        while (j<AdresaStudenta.size() && AdresaStudenta.at(j)== ' ') j++;
        j--;
    }
    AdresaStudenta = pomocna;
}
void Student::Izuzetak() {

    throw std::domain_error ("Neispravni parametri");
}
void Student::ProvjeraBroja() {
    int cifra1(0), cifra2(0), cifra3(0), i(0);
    while (i<BrojTelefonaStudenta.size() && BrojTelefonaStudenta.at(i)!='/') {
        if (BrojTelefonaStudenta.at(i)<'0' || BrojTelefonaStudenta.at(i)>'9') Izuzetak();
        cifra1++;
        i++;
    }
    i++;
    if (cifra1==0) Izuzetak();
    while (i<BrojTelefonaStudenta.size() && BrojTelefonaStudenta.at(i)!='-') {
        if (BrojTelefonaStudenta.at(i)<'0' || BrojTelefonaStudenta.at(i)>'9') Izuzetak();
        cifra2++;
        i++;
    }
    i++;
    if (cifra2==0) Izuzetak();
    while (i<BrojTelefonaStudenta.size() ) {
        if (BrojTelefonaStudenta.at(i)<'0' || BrojTelefonaStudenta.at(i)>'9') Izuzetak();
        cifra3++;
        i++;
    }
    if (cifra3==0) Izuzetak();


}
void Student::ProvjeriCifre() {
    int broj(0);
    auto x (BrojIndexa);
    while (x) {
        x/=10;
        broj++; }
    if (broj!=5) Izuzetak();
}

void Student::ProvjeriGodinuStudija () {
    std::vector<std::string> v {"1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D" , "3/D"};
    for (auto x : v ){
        if (x==GodinaStudija) return;
    }
    Izuzetak();
}
 Student::Student  (int BrIndexa, std::string GodStudija, std::string ImePrez, std::string AdrStudenta, std::string BrTelefonaStudenta){

     if (GodStudija.size()==1 ) GodStudija+="/B";
     this->BrojIndexa=BrIndexa;
     this->GodinaStudija=GodStudija;
     this->ImePrezime=ImePrez;
     this->AdresaStudenta=AdrStudenta;
     this->BrojTelefonaStudenta=BrTelefonaStudenta;
    ProvjeriCifre();
    ProvjeriGodinuStudija();
    ObradiImePrezime();
    ObradiAdresuStudenta();
    ProvjeraBroja ();


 }


int main() {
    std::string a {"kenan"};
Student kenan (17912, "1", "   keno     arijana mesi          ", "bistrik 33", "061/282-668");
kenan.Ispisi();

    return 0;
}


