/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>

#include <string>
#include <stdexcept>
#include <map>

class Student {
    int broj_indexa;
    std::string godina_studija,ime_i_prezime,adresa,broj_telefona;
    public:
    bool TestIndexa(int broj);
    bool TestGodine(std::string godina);
    bool TestBroja(std::string broj);
    std::string ModificirajIme(std::string s);
    
    Student(int broj_indexa,std::string godina_studija,std::string ime_i_prezime,
            std::string adresa,std::string broj_telefona);
    int DajIndeks() const { return broj_indexa; }
    std::string DajGodinuStudija();
    std::string DajImePrezime() const { return ime_i_prezime; }
    std::string DajAdresu() const { return adresa; }
    std::string DajTelefon() const { return broj_telefona; }
    
    void Ispisi();
};

bool Student::TestIndexa(int broj) {
    if (broj<0) return false;
    int brojac(0);
    while(broj!=0) {
            broj/=10;
            brojac++;
        }
    if(brojac!=5) return false;
    return true;
}
bool Student::TestGodine(std::string godina) {
    if(godina.length()>3 || godina.length()==2 || godina.length()==0) return false;
    if(godina.length()==1 && godina[0]!='1' && godina[0]!='2' && godina[0]!='3') return false;
    if(godina_studija.length()==3) {
    for(int i(0);i<3;i++) {
        if(godina.at(0)!='1' && godina.at(0)!='2' && godina.at(0)!='3') return false;
        if(godina.at(1)!='/') return false;
        if(godina.at(2)!='B' && godina.at(2)!='M' && godina.at(2)!='D') return false;
        if(godina.at(2)=='M' && godina.at(0)=='3') return false;
    }
    }
    return true;
}
bool Student::TestBroja(std::string broj) {
    if(broj.length()<5) return false;
    for(int i(0);i<broj.length();i++) {
        if(broj.at(0)<'0' || broj.at(0)>'9')
            return false;
        if(broj.at(i)!='/' && broj.at(i)!='-' && (broj.at(i)<'0' || broj.at(i)>'9'))
            return false;
        if(broj.at(broj.length()-1)=='-' || broj.at(broj.length()-1)=='/')
            return false;
    }
    int b1(0),b2(0);
    for(int i(0);i<broj.length();i++) {
        if(broj.at(i)=='/') {
            b1++;
            if(b1>1) return false;
        }
        if(broj.at(i)=='-') {
            b2++;
            if(b2>1) return false;
        }
    }
    if(b1==0 || b2==0) return false;
    
    for(int i(0);i<broj.length();i++) {
        if(broj.at(i)=='/' && (broj.at(i-1)=='-' || broj.at(i+1)=='-')) 
            return false;
    }
    
    
    return true;
}
std::string Student::ModificirajIme(std::string s) {
    int duzina(s.size());
    for(int i(0);i<duzina-1;i++) {
        if(s.at(i)==' ' && s.at(i+1)==' ' && i!=0) {
            for(int j(i);j<duzina-1;j++) {
                s.at(j)=s.at(j+1);
            }
            duzina--;
            i--;
        }
        if(s.at(0)==' ') {
            for(int j(i);j<duzina-1;j++) 
                s.at(j)=s.at(j+1);
            duzina--;
            i--;
        }
    }
    
    if(s[duzina-1]==' ' || s[0]==' ') duzina--;
    
    std::string pomocni;
    for(int i(0);i<duzina;i++){
        
        pomocni.push_back(s.at(i));
    }
    s.resize(0);
    for(int i(0);i<duzina;i++) {
        s.push_back(pomocni.at(i));
    }
    return s;
}

Student::Student(int broj_indexa,std::string godina_studija,std::string ime_i_prezime,
            std::string adresa,std::string broj_telefona){
            
            if(!TestIndexa(broj_indexa)) throw std::domain_error("Neispravni parametri");
            if(!TestGodine(godina_studija)) throw std::domain_error("Neispravni parametri");
            if(!TestBroja(broj_telefona)) throw std::domain_error("Neispravni parametri");
            
            Student::broj_indexa=broj_indexa;
            Student::godina_studija=godina_studija;
            Student::ime_i_prezime=ModificirajIme(ime_i_prezime);
            Student::adresa=ModificirajIme(adresa);
            Student::broj_telefona=broj_telefona;
}
std::string Student::DajGodinuStudija() {
    if(godina_studija.length()==1 && (godina_studija.at(0)=='1' || 
        godina_studija.at(0)=='2' || godina_studija.at(0)=='3')) 
        godina_studija=godina_studija+std::string("/B");
    
    return godina_studija;
}
void Student::Ispisi() {
    std::cout<<"Broj indeksa: "<<broj_indexa<<std::endl;
    std::cout<<"Godina studija: "<<(*this).DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<ime_i_prezime<<std::endl;
    std::cout<<"Adresa: "<<adresa<<std::endl;
    std::cout<<"Telefon: "<<broj_telefona<<std::endl;
}

class Laptop{
    int ev_broj;
    std::string naziv, karakteristike;
    Student* kod_koga_je;
    
    public:
    Laptop(int ev_broj,std::string naziv,std::string karakteristike);
    int DajEvidencijskiBroj() { return ev_broj; }
    std::string DajNaziv() { return naziv; }
    std::string DajKarakteristike() { return karakteristike; }
    void Zaduzi(Student &student);
    void Razduzi();
    bool DaLiJeZaduzen();
    Student &DajKodKogaJe();
    Student* DajPokKodKogaJe();
    void Ispisi();
    
};

Laptop::Laptop(int ev_broj,std::string naziv,std::string karakteristike):
    naziv(naziv),karakteristike(karakteristike) {
        if(ev_broj<0) throw std::domain_error("Neispravni parametri");
        Laptop::ev_broj=ev_broj;
        kod_koga_je=nullptr;
}
void Laptop::Zaduzi(Student &student) {
    if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je=new Student(student);
}
void Laptop::Razduzi() {
    kod_koga_je=nullptr;
}
bool Laptop::DaLiJeZaduzen(){
    if(kod_koga_je!=nullptr) return true;
    return false;
}
Student &Laptop::DajKodKogaJe() {
    if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
} 
Student* Laptop::DajPokKodKogaJe() {
    return kod_koga_je;
}
void Laptop::Ispisi() {
    std::cout<<"Evidencijski broj: "<<ev_broj<<"\nNaziv: "<<naziv
    <<"\nKarakteristike: "<<karakteristike<<std::endl;
}

class Administracija {
    std::map<int,Student*> mapastudenata;
    std::map<int,Laptop*> mapalaptopa;
    
    public:
    Administracija(){}
    Administracija(const Administracija &a)=delete;
    Administracija(Administracija &&a) { mapastudenata=std::move(a.mapastudenata);}
    Administracija &operator =(Administracija &a)=delete;
    Administracija &operator =(Administracija &&a) {
        mapastudenata=std::move(a.mapastudenata);
    }
};


int main () {
    
    Student stu(17606,"1","     Amina     Omercevic    ","Kalemova 4","1/1-1");
    stu.Ispisi();
    
    Laptop l(102,"acer","z8 kejdn");
    l.Ispisi();
    
    Administracija a;
	return 0;
}
