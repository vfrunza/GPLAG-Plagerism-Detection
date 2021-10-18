/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <string>
class Student{
  int indeks;
  std::string ime_prezime,adresa,godina_studija,broj_tel;
bool Godina(std::string s){
    std::vector<std::string> a{"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
    return (std::count(a.begin(),a.end(),s));
}
bool Broj(std::string s){
    for(int i=0;i<s.length();i++){
        if(!std::isdigit(s[i]))return false;
        else{
            while(std::isdigit(s[i])&&i!=s.length()-1)i++;
            if(s[i]!='/'||i==s.length()-1) return false;
            else i++;
            while(std::isdigit(s[i])&&i!=s.length()-1)i++;
            if(s[i]!='-'||i==s.length()-1) return false;
            else i++;
            while(std::isdigit(s[i])&&i!=s.length()-1)i++;
            if(i==s.length()-1) return true;
        }
    }
}
std::string UkloniRazmake(std::string s){
    for(int i=0;i<s.length();i++){
        while(s[i]==' '&&i!=s.length()-1) s.erase(s.begin()+i);
        while(s[i]!=' '&&i!=s.length()-1)i++;
    }
    while(s.length()>0&&s[s.length()-1]==' ') s.erase(s.begin()+s.length()-1);
    return s;
}

std::string PopraviGodinu(std::string s){
    if(s=="1")s="1/B";
    if(s=="2")s="2/B";
    if(s=="3")s="3/B";
    return s;
}
  public:
  Student(int ind,std::string godina, std::string ime, std::string adr, std::string broj){
      if(!Godina(godina)||!Broj(broj)||ind<10000)throw std::domain_error("Neispravni parametri");
      indeks=ind;
      ime_prezime=UkloniRazmake(ime);
      adresa=UkloniRazmake(adr);
      godina_studija=PopraviGodinu(godina);
      broj_tel=broj;
  }
  int DajIndeks()const{ return indeks;}
  std::string DajGodinuStudija()const{return godina_studija;}
  std::string DajAdresu()const{return adresa;}
  std::string DajTelefon()const{return broj_tel;}
  std::string DajImePrezime()const{return ime_prezime;}
  void Ispisi()const;
  
};

void Student::Ispisi()const{
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl<<"Godina studija: "<<DajGodinuStudija()<<std::endl<<
    "Ime i prezime: "<<DajImePrezime()<<std::endl<<"Adresa: "<<DajAdresu()<<std::endl<<"Telefon: "<<DajTelefon()<<std::endl;
}

class Laptop{
  int ev_broj;
  std::string naziv,karakteristike;
  Student* kod_koga_je;
  public:
  Laptop(int broj,std::string ime,std::string karakt):naziv(ime),karakteristike(karakt),kod_koga_je(nullptr){
      if(broj<0)throw std::domain_error("Neispravni parametri");
      ev_broj=broj;
  }
  int DajEvidencijskiBroj()const{return ev_broj;}
  std::string DajNaziv()const{return naziv;}
  std::string DajKarakteristike()const{return karakteristike;}
  void Zaduzi(Student& s){
      if(kod_koga_je!=nullptr)throw std::domain_error("Laptop vec zaduzen");
      else *kod_koga_je=s;
  }
  void Razduzi(){
      delete kod_koga_je;
      kod_koga_je=nullptr;
  }
  bool DaLiJeZaduzen()const{
      if(kod_koga_je==nullptr) return false;
      return true;
  }
  Student& DajKodKogaJe()const{
      if(kod_koga_je==nullptr)throw std::domain_error("Laptop nije zaduzen");
      else return *kod_koga_je;
  }
  Student* DajPokKodKogaJe()const{ return kod_koga_je; }

void Ispisi()const{
    std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl<<"Naziv: "<<naziv<<std::endl<<"Karakteristike: "<<karakteristike<<std::endl;
}
};
class Administracija{
        std::map<int,Student*> studenti;
        std::map<int,Laptop*> laptopi;
        public:
        Administracija(){};
        Administracija(const Administracija& a){
        
}
    
};


int main ()
{
	return 0;
}
