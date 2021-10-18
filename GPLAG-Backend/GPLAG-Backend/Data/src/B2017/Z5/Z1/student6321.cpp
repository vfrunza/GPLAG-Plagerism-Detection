/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>


class Student {
    int  broj_indeksa;
    std::string godina_studija, ime_i_prezime, adresa, broj_telefona;
    
    public:
    
    Student(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona) {
        int br(broj_indeksa);
        
        int brojac=0;

        while(br != 0) {
            int cifra = br % 10;
            br /= 10;
            brojac++;
        }
        if(brojac != 5) throw std::domain_error("Neispravni parametri1");
    
    if(godina_studija != "1" && godina_studija != "2" && godina_studija != "3" && godina_studija != "1/B" && godina_studija != "2/B" && godina_studija != "3/B" && godina_studija != "1/M" && godina_studija != "2/M" && godina_studija != "1/D" && godina_studija != "2/D" && godina_studija != "3/D" )
     throw std::domain_error("Neispravni parametri2");
    
    while(ime_i_prezime[0] == ' ') {
        ime_i_prezime.erase(0,1);
    }
    
    for(int i=1; i<ime_i_prezime.size(); i++) {
        if(ime_i_prezime[i-1] == ' ' && ime_i_prezime[i] == ' ') {
            ime_i_prezime.erase(i, 1);
            i--;
        }
    }
    if(ime_i_prezime[0] == ' ') ime_i_prezime.erase(0,1);
    if(ime_i_prezime[ime_i_prezime.size()] == ' ') ime_i_prezime.erase(ime_i_prezime.size());
    
    // BROJ TELEFONA
   int brojacc=0;
    for(int i=0; i<broj_telefona.size(); i++)  {
        if(broj_telefona[i] < '0' || broj_telefona[i] > '9') {
            if(brojacc == 0 && broj_telefona[i] != '/') throw std::domain_error("Neispravni parametri");
            if(brojacc == 1 && broj_telefona[i] != '-') throw std::domain_error("Neispravni parametri");
            if(brojacc == 2) throw std::domain_error("Neispravni parametri");
        
            brojacc++;
        }
        
        
    }
    
    this->broj_indeksa=broj_indeksa;
    this->godina_studija=godina_studija;
    this->ime_i_prezime=ime_i_prezime;
    this->broj_telefona=broj_telefona;
    this->adresa=adresa;
    
    } //kraj konstruktora
    
    
    int DajIndeks() const {
        return broj_indeksa;
    }
    std::string DajGodinuStudija() const {
        
        return godina_studija;
    }
    
    std::string DajImeiPrezime() const {
        return ime_i_prezime;
    }
    
    std::string DajAdresu() const {
        return adresa;
    }
    
    std::string DajTelefon() const {
        return broj_telefona;
    }
    
    void Ispisi() {
        std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
        std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
        std::cout<<"Ime i prezime: "<<DajImeiPrezime()<<std::endl;
        std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
        std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
        
    }
};

class Laptop {
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je = nullptr;
    
        public:

    Laptop( int ev_broj, std::string naziv, std::string karakteristike) {
        if(ev_broj < 0) throw std::domain_error("Neispravni parametri");
       
       this->ev_broj=ev_broj;
       this->naziv=naziv;
       this->karakteristike=karakteristike;
       this->kod_koga_je=kod_koga_je;
    } 
    
    
    int DajEvidencijskiBroj() const {
        return ev_broj;
    }
    std::string DajNaziv() const {
        return naziv;
    }
    std::string DajKarakterstike() const {
        return karakteristike;
    }
    
    void Zaduzi(Student &s) {
        if(DaLiJeZaduzen())
        throw std::domain_error("Laptop je vec zaduzen");
                else this->kod_koga_je=&s;

    }
    
    void Razduzi () {
        kod_koga_je = nullptr;
    }
    
    bool DaLiJeZaduzen() {
        if(kod_koga_je == nullptr) return false;
        return true;
    }
   Student &DajKodKogaJe() {
        if(!(DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
        else *kod_koga_je;
    }
    Student *DajPokKodKogaJe() {
         if(!(DaLiJeZaduzen())) throw std::domain_error("Laptop nije zaduzen");
        else kod_koga_je;
    }
    
    void Ispisi() {
        std::cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<std::endl;
        std::cout<<"Naziv: "<<DajNaziv()<<std::endl;
        std::cout<<"Karakteristike: "<<DajKarakterstike()<<std::endl;
    }
};

class Administracija {
    
    std::map<int, Student*> s_mapa;
    std::map<int, Laptop*> l_mapa;
    
    public: 
    
    Administracija() {}
    
    
    ~Administracija() {
        for(auto it=s_mapa.begin(); it != s_mapa.end(); it++) delete it->second;
        
        for(auto it=l_mapa.begin(); it != l_mapa.end(); it++) delete it->second;
    }
   void RegistrirajNovogStudenta(int broj_indeksa, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona) {
       Student* s=new Student(broj_indeksa, godina_studija, ime_i_prezime, adresa, broj_telefona);
       
       auto it(this->s_mapa.find(broj_indeksa));
       if(it != s_mapa.end())
       throw std::domain_error("Student s tim indeksm vec postoji");
       this->s_mapa[broj_indeksa]=s;
   }
    
Student &NadjiStudenta(int broj_indeksa) {
           auto it(this->s_mapa.find(broj_indeksa));

           if(it == s_mapa.end())
          throw std::domain_error("Student nije nadjen");
        return *it->second;
}

Laptop &NadjiLaptop(int ev_broj) {
auto it(this->l_mapa.find(ev_broj));

           if(it == l_mapa.end())
          throw std::domain_error("Laptop nije nadjen");
        return *it->second;
}

void IzlistajStudente() {
    for(auto it=s_mapa.begin(); it != s_mapa.end(); it++) {
        it->second->Ispisi();
    }
}

void IzlistajLaptope() {
     for(auto it=l_mapa.begin(); it != l_mapa.end(); it++) {
        it->second->Ispisi();
    }
}


void ZaduziLaptop(int broj_indeksa, int ev_broj) {
    
        Student s=this->NadjiStudenta(broj_indeksa);

    Laptop l=this->NadjiLaptop(ev_broj);
    
    
    
    this->l_mapa[ev_broj]->Zaduzi(NadjiStudenta(broj_indeksa));
    
             
}

int NadjiSlobodniLaptop() {
   for(auto it=l_mapa.begin(); it != l_mapa.end(); it++) {
       if( it->second->DaLiJeZaduzen() == false) return it->first;
   }
    throw std::domain_error("Nema slobodnih laptopa");
}

void RazduziLaptop(int ev_broj) {
    Laptop l=this->NadjiLaptop(ev_broj);
   
    this->l_mapa[ev_broj]->Razduzi();

}

void PrikaziZaduzenja() {
    
    for(auto it=l_mapa.begin(); it != l_mapa.end(); it++) {
        if(it->second->DaLiJeZaduzen()==true) {
            std::cout<<"Student "<<it->second->DajPokKodKogaJe()->DajImeiPrezime()<<" ("<<it->second->DajPokKodKogaJe()->DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<std::endl;
            
        } else std::cout<<"Nema zaduzenja";
            }
}

};


int main ()
{
    try {
        
    for(;;) {
        std::cout<<"Unesite broj za opciju koju zelite ili 0 za kraj: "<<std::endl;
        std::cout<<"1 - Registriraj novog studenta"<<std::endl;
        std::cout<<"2 - Registriraj novi laptop"<<std::endl;
        std::cout<<"3 - Nadji studenta"<<std::endl;
        std::cout<<"4 - NadjiLaptop"<<std::endl;
        std::cout<<"5 - Registriraj novi laptop"<<std::endl;
        std::cout<<"6 - Izlistaj studente"<<std::endl;
        
        int n;
        
        std::cin>>n;
        
        if (n == 0) {
            return 0;
        } else {
        if(n == 1) {
           Student s8(17865, "1/B","   Nejla Bandic         - ", "Miami 6984", "033/421-322");
           s8.Ispisi();
        }
        


    Student s1(17866, "1/B","   Nejla Bandic         - ", "Miami 6984", "033/421-322");
    Student s2(12354, "2/B", "   Alma Almić   ", " Igmanska 154   ", "036/344-666");
    Student s3(12333, "1/D", "Meho Milic ", "Brezovacka 7", "035/422-469");
    Student s4(78975, "3/B", "Ina Matic  ", "Hadzeli 1", "031/456-098");
    
    s1.Ispisi();
    s2.Ispisi();
    s3.Ispisi();
    s4.Ispisi();
    
    std::cout<<std::endl;
    
    Laptop l1(724," Asus 856", "intel 256, bhjgsajgfjd");
    Laptop l2(12, "HP ", "Intel, 8 GB RAM");
    Laptop l3(124, "HP  656", "16 GB RAM, Intel CPU");
    Laptop l4(45, "Asus Aspire", "2.4 GHz, 16 GB RAM");
    
    l1.Ispisi();
    l2.Ispisi();
    l3.Ispisi();
    l4.Ispisi();
    
    std::cout<<std::endl;
    
        }
    }
    } catch(std::exception &ex) {
        std::cout<<ex.what();
    }
    
  //else


	return 0;
}
