#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <memory>

class Student
{
    int BrojIndeksa;
    std::string GodinaStudija;
    std::string ImeIPrezime;
    std::string Adresa;
    std::string BrojTelefona;
public:
    Student(int br_indeksa, std::string godina, std::string ime, std::string adresa, std::string br_telefona)
    {
        //Indeks
        if(int(std::log10(br_indeksa)+1)!=5) throw std::domain_error("Neispravni parametri");
        BrojIndeksa=br_indeksa;
        //Godina studija
        std::vector<std::string> v{"1","2","3","1/B","2/B","3/B","1/M","2/M","1/D","2/D","3/D"};
        if(std::find(v.begin(),v.end(),godina)==v.end()) throw std::domain_error("Neispravni parametri");
        else
        {
            GodinaStudija=godina;
            if(godina.length()==1) GodinaStudija+="/B"; 
        }
        
        //Ime i prezime
        auto it=ime.begin();
        while(*it==' ') it++;
        while(it!=ime.end())
        {
            if(*it!=' ') ImeIPrezime+=*it;
            else if(*(it-1)!=' ') ImeIPrezime+=" ";
            it++;
        }
        if(*(ImeIPrezime.end()-1)==' ') ImeIPrezime.resize(ImeIPrezime.size()-1);
        
        //Adresa
        it=adresa.begin();
        while(*it==' ') it++;
        while(it!=adresa.end())
        {
            if(*it!=' ') Adresa+=*it;
            else if(*(it-1)!=' ') Adresa+=" ";
            it++;
        }
        if(*(Adresa.end()-1)==' ') Adresa.resize(Adresa.size()-1);
        
        //Broj telefona
        it=br_telefona.begin();
        if(!(*it>='0' && *it<='9')) throw std::domain_error("Neispravni parametri");
        while(*it>='0' && *it<='9') it++;
        if(*it!='/') throw std::domain_error("Neispravni parametri");
        it++;
        if(!(*it>='0' && *it<='9')) throw std::domain_error("Neispravni parametri");
        while(*it>='0' && *it<='9') it++;
        if(*it!='-') throw std::domain_error("Neispravni parametri");
        it++;
        if(!(*it>='0' && *it<='9')) throw std::domain_error("Neispravni parametri");
        while(*it>='0' && *it<='9') it++;
        if(it!=br_telefona.end()) std::domain_error("Neispravni parametri");
        BrojTelefona=br_telefona;
    }
    
    int DajIndeks() const { return BrojIndeksa; }
    std::string DajGodinuStudija() const { return GodinaStudija; }
    std::string DajImePrezime() const { return ImeIPrezime; }
    std::string DajAdresu() const { return Adresa; }
    std::string DajTelefon() const { return BrojTelefona; }
    void Ispisi() const
    {
        std::cout<<"Broj indeksa: "<<BrojIndeksa<<std::endl;
        std::cout<<"Godina studija: "<<GodinaStudija<<std::endl;
        std::cout<<"Ime i prezime: "<<ImeIPrezime<<std::endl;
        std::cout<<"Adresa: "<<Adresa<<std::endl;
        std::cout<<"Telefon: "<<BrojTelefona<<std::endl;
    }
};

class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    std::shared_ptr<Student> kod_koga_je;
public:
    Laptop(int broj, std::string ime, std::string karak) : ev_broj(broj), naziv(ime), karakteristike(karak), kod_koga_je(nullptr) 
    {
        if(broj<0) throw std::domain_error("Neispravni parametri");
    }
    int DajEvidencijskiBroj() const { return ev_broj; }
    std::string DajNaziv() const { return naziv; }
    std::string DajKarakteristike() const { return karakteristike; }
    void Zaduzi(Student &student)
    {
        if(kod_koga_je!=nullptr) throw std::domain_error("Laptop vec zaduzen");
        kod_koga_je=std::make_shared<Student>(student);
    }
    void Razduzi() { kod_koga_je=nullptr; }
    bool DaLiJeZaduzen() { return kod_koga_je!=nullptr; }
    Student &DajKodKogaJe() { if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen"); return *kod_koga_je; }
    std::shared_ptr<Student> DajPokKodKogaJe() { return kod_koga_je; }
    void Ispisi()
    {
        std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl;
        std::cout<<"Naziv: "<<naziv<<std::endl;
        std::cout<<"Karakteristike: "<<karakteristike<<std::endl;
    }
};

class Administracija
{
    std::map<int, std::shared_ptr<Student>> Studenti;
    std::map<int, std::shared_ptr<Laptop>> Laptopi;
public:
    explicit Administracija() = default;
    
    /***************************************************/

    Administracija(const Administracija &admin)
    {
        for(auto par : admin.Studenti) 
        {
            std::pair<int, std::shared_ptr<Student>> novipar;
            auto p=std::shared_ptr<Student>(new Student(*par.second));
            novipar={par.first,p};
            Studenti.insert(novipar);
        }
        for(auto par : admin.Laptopi) 
        {
            std::pair<int, std::shared_ptr<Laptop>> novipar;
            auto p=std::shared_ptr<Laptop>(new Laptop(*par.second));
            novipar={par.first,p};
            Laptopi.insert(novipar);
        }
    }
    Administracija(Administracija &&admin)
    {
        Studenti=admin.Studenti;
        Laptopi=admin.Laptopi;
        admin.Studenti.clear();
        admin.Laptopi.clear();
    }
    Administracija &operator=(const Administracija &admin)
    {
        if(&admin!=this)
        {
            for(auto par : admin.Studenti) 
            {
                std::pair<int, std::shared_ptr<Student>> novipar;
                auto p=std::shared_ptr<Student>(new Student(*par.second));
                novipar={par.first,p};
                Studenti.insert(novipar);
            }
            for(auto par : admin.Laptopi) 
            {
                std::pair<int, std::shared_ptr<Laptop>> novipar;
                auto p=std::shared_ptr<Laptop>(new Laptop(*par.second));
                novipar={par.first,p};
                Laptopi.insert(novipar);
            }
        }
        return *this;
    }
    Administracija &operator=(Administracija &&admin)
    {
        if(&admin!=this)
        {
            Studenti=admin.Studenti;
            Laptopi=admin.Laptopi;
            admin.Studenti.clear();
            admin.Laptopi.clear();
        }
        return *this;
    }
    /***************************************************/
    void RegistrirajNovogStudenta(int br_indeksa, std::string godina, std::string ime, std::string adresa, std::string br_telefona)
    {
        for(auto par : Studenti) if(par.first==br_indeksa) throw std::domain_error("Student s tim indeksom vec postoji");
        auto p=std::shared_ptr<Student>(new Student(br_indeksa, godina, ime, adresa, br_telefona));
        std::pair<int, std::shared_ptr<Student>> par={br_indeksa,p};
        Studenti.insert(par);
    }
    
    void RegistrirajNoviLaptop(int broj, std::string ime, std::string karak)
    {
        for(auto par : Laptopi) if(par.first==broj) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        auto p=std::shared_ptr<Laptop>(new Laptop(broj,ime,karak));
        std::pair<int, std::shared_ptr<Laptop>> par={broj,p};
        Laptopi.insert(par);
    }
    
    Student &NadjiStudenta(int br_indeksa)
    {
        for(auto par : Studenti) if(par.first==br_indeksa) return *par.second;
        throw std::domain_error("Student nije nadjen");
    }
    Student NadjiStudenta(int br_indeksa) const
    {
        for(auto par : Studenti) if(par.first==br_indeksa) return *par.second;
        throw std::domain_error("Student nije nadjen");
    }
    Laptop &NadjiLaptop(int ev_broj)
    {
        for(auto par : Laptopi) if(par.first==ev_broj) return *par.second;
        throw std::domain_error("Laptop nije nadjen");
    }
    Laptop NadjiLaptop(int ev_broj) const
    {
        for(auto par : Laptopi) if(par.first==ev_broj) return *par.second;
        throw std::domain_error("Laptop nije nadjen");
    }
    
    void IzlistajStudente() const { for(auto par : Studenti) { par.second->Ispisi(); std::cout<<std::endl; } }
    void IzlistajLaptope() const 
    {
        for(auto par : Laptopi) 
        { 
            par.second->Ispisi(); 
            if(par.second->DaLiJeZaduzen()) std::cout<<"Zaduzio(la): "<<par.second->DajKodKogaJe().DajImePrezime()<<" ("<<par.second->DajKodKogaJe().DajIndeks()<<")"<<std::endl; 
            std::cout<<std::endl; 
        } 
    }
    void ZaduziLaptop(int indeks, int broj)
    {
        bool nasao(false);
        for(auto par : Studenti) if(par.first==indeks) { nasao=true; break; }
        if(!nasao) throw std::domain_error("Student nije nadjen");
        nasao=false;
        for(auto par : Laptopi) if(par.first==broj) { nasao=true; break; }
        if(!nasao) throw std::domain_error("Laptop nije nadjen");
        
        if(Laptopi[broj]->DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");
        
        for(auto par : Laptopi) 
        {
            if(par.second->DaLiJeZaduzen())
            {
                if(par.second->DajKodKogaJe().DajIndeks() == indeks) throw std::domain_error("Student je vec zaduzio laptop");
            }
        }
        
        Laptopi[broj]->Zaduzi(*Studenti[indeks]);
    }
    
    int NadjiSlobodniLaptop() const
    {
        for(auto par : Laptopi) if(!par.second->DaLiJeZaduzen()) return par.first;
        throw std::domain_error("Nema slobodnih laptopa");
    }
    void RazduziLaptop(int broj)
    {
        for(auto par : Laptopi) 
            if(par.first==broj) 
            {
                if(!par.second->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
                par.second->Razduzi();
                return;
            }
        throw std::domain_error("Laptop nije nadjen");
    }
    
    void PrikaziZaduzenja() const
    {
        bool ima(false);
        for(auto par : Laptopi) if(par.second->DaLiJeZaduzen()) { std::cout<<"Student "<<par.second->DajKodKogaJe().DajImePrezime()<<" ("<<par.second->DajKodKogaJe().DajIndeks()<<") zaduzio/la laptop broj "<<par.second->DajEvidencijskiBroj()<<std::endl; ima=true;}
        if(!ima) std::cout<<"Nema zaduzenja"<<std::endl;
    }
    
};

int main ()
{/*
    Administracija administracija;
    administracija.RegistrirajNovogStudenta(18021,"1","Edis Krsmanovic","Adema Buce do 400","060/317-6076");
    administracija.RegistrirajNovogStudenta(18222,"2/M","Sara Kozic","Alipasino 16000","062/448-554");
    administracija.RegistrirajNovogStudenta(18027,"1","Amila Lakovic","Na Ilidzi negdje ocm kume ba","066/666-666");
    administracija.RegistrirajNoviLaptop(724,"ASUS X554L","Intel CPU 2.4 GHz, 8 GB RAM");
    administracija.RegistrirajNoviLaptop(726,"Intel 700","Intel CPU 2 GHz, 4 GB RAM");
    //administracija.ZaduziLaptop(18021,administracija.NadjiSlobodniLaptop());
    //administracija.ZaduziLaptop(18222,726);
    {
        Administracija admin(std::move(administracija));
        admin=admin;
        admin.IzlistajLaptope();
        admin.IzlistajStudente();
    }
    administracija.RegistrirajNoviLaptop(725,"asd","asdd");
    administracija.RegistrirajNovogStudenta(75525,"2","Dinjo Dinjic","Ulica 5","0/0-1");
    administracija.IzlistajLaptope();
    administracija.IzlistajStudente();*/
        //AT25 - (javni) Test klase Administracija - ZaduziLaptop/PrikaziZaduzenja

    Administracija etf ;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");
    etf.RegistrirajNovogStudenta(14212, "1", "Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    
    etf.ZaduziLaptop(14212, 123);
    etf.ZaduziLaptop(17528, 331);
    
    etf.PrikaziZaduzenja();
	return 0;
}