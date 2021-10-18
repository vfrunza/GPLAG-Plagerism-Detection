/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

class Student{
    int br_indeksa;
    std::string ime_i_prezime, adresa, god_studija, br_tel;
    bool jel_broj(char a){return (a>'0' && a<'9');}
    bool jel_slovo(char a){return((a>'a' && a<'z')||(a>'A' && a<'Z'));}
    public:
    Student(int index,  std::string god,std::string ime, std::string adr, std::string telefon);
    std::string DajImePrezime()const{return ime_i_prezime;}
    std::string DajAdresu()const{return adresa;}
    std::string DajTelefon()const{return br_tel;}
    std::string DajGodinuStudija()const{if(god_studija=="1") return "1/B";
    else if(god_studija=="2") return "2/B";
    else if(god_studija=="3") return "3/B";
        else return god_studija;
    }
    int DajIndeks()const{return br_indeksa;}
    void Ispisi()const;
};
void Student::Ispisi() const{
    std::cout << "Broj indeksa: "<<br_indeksa << std::endl;
    std::cout << "Godina studija: ";
    std::cout << god_studija << std::endl;
    std::cout << "Ime i prezime: "<<ime_i_prezime << std::endl;
    std::cout << "Adresa: " << adresa<< std::endl;
    std::cout << "Telefon: "<<br_tel << std::endl;
}
Student::Student(int index,std::string god, std::string ime, std::string adr, std::string telefon){
        if(index<10000 || index>99999) throw std::domain_error ("Neispravni parametri");
        if(!(god=="1" || god=="2" || god=="3" || god=="1/B" || god=="2/B" || god=="3/B" || god=="1/M" || god=="2/M" || god=="1/D" || god=="2/D"|| god=="3/D" ))
            throw std::domain_error ("Neispravni parametri");
       /*for(int i=0;i<telefon.length()-1;i++){
          if(((i==0 || i==telefon.length()-1) && !jel_broj(telefon[i])) || (!(jel_broj(telefon[i])) && (telefon[i]!='/'|| telefon[i]!='-')))  
          throw std::domain_error ("Neispravni parametri");
        }*/
        br_indeksa=index;
        god_studija=god;
        br_tel=telefon;
        for(int i=1;i<ime.length()-1;i++){
            if(ime[i]==' ' && (ime [i-1]==' ' || ime[i+1]==' ')) ime.erase(ime.begin()+i);
        }
        auto it(ime.begin()); while(!jel_slovo(*it)) ime.erase(it);
        while(ime.length()==' '){
        if(ime[ime.length()]==' ') ime.erase(ime.begin()+ime.length());
        }
        if(god_studija=="1") god_studija= "1/B";
    else if(god_studija=="2") god_studija= "2/B";
    else if(god_studija=="3") god_studija= "3/B";
        else god_studija=god;
        ime_i_prezime = ime;
        adresa=adr;
    }
class Laptop{
  int ev_broj;
  std::string naziv, karakteristike;
  Student* kod_koga_je;
  public:
  Laptop(int br, std::string ime, std::string karak){
      if(br<0) throw std::domain_error("Neispravni parametri");
      ev_broj=br; naziv=ime; karakteristike=karak; kod_koga_je=nullptr;
  }
  int DajEvidencijskiBroj()const{return ev_broj;}
  std::string DajNaziv()const{return naziv;}
  std::string DajKarakteristike()const{return karakteristike;}
  void Zaduzi(Student &s){
      if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
      Student* x(&s); kod_koga_je=x;
  }
  void Razduzi(){
      if(kod_koga_je!=nullptr) kod_koga_je=nullptr;
  }
  bool DaLiJeZaduzen() const{ return (kod_koga_je!=nullptr);  }
  Student& KodKogaJe()const{if(kod_koga_je==nullptr)throw std::domain_error("Laptop nije zaduzen");
      return *kod_koga_je;
  }
  Student* DajPokKodKogaJe()const{return kod_koga_je;}
  void Ispisi()const;
};
void Laptop::Ispisi() const{
    std::cout << "Evidencijski broj: "<<ev_broj << std::endl;
    std::cout << "Naziv: "<<naziv << std::endl;
    std::cout << "Karakteristike: "<<karakteristike << std::endl;
}
int main ()
{
	return 0;
}
