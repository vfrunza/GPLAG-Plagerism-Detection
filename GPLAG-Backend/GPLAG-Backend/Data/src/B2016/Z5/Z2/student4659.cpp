/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>

struct Korisnik {
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
    std::string naslov,ime_pisca,zanr;
    int godina;
    std::shared_ptr<Korisnik> pok;
    public:
        //KONSTRUKTOR SA 4 PARAMETRA
        Knjiga(std::string s1,std::string s2,std::string s3,int g):naslov(s1),ime_pisca(s2),zanr(s3),godina(g),pok(nullptr) {}
        
        //PRISTUPNE METODE
        std::string DajNaslov() const { return naslov; }
        std::string DajAutora() const { return ime_pisca; }
        std::string DajZanr() const { return zanr; }
        int DajGodinuIzdavanja() const { return godina; }
        std::shared_ptr<Korisnik> DajKodKogaJe() const { return pok; }
        
        //METODE 
        void ZaduziKnjigu(Korisnik &k){ pok=std::make_shared<Korisnik>(k); }
        void RazduziKnjigu(){ pok=nullptr; }
        bool DaLiJeZaduzena(){
            if(pok==nullptr)return false;
            return true;
        }
};

class Biblioteka {
    std::map<int,std::shared_ptr<Knjiga>> m1;
    std::map<int,std::shared_ptr<Korisnik>> m2;
    public:
        //KONSTRUKTOR BEZ PARAMETARA
        Biblioteka()= default;
        
        //KOPIRAJUCI KONSTRUKTOR I OPERATOR DODJELE(DUBOKO KOPIRANJE)
        Biblioteka(const Biblioteka &b);
        Biblioteka &operator =(const Biblioteka &b);
        
        //POMJERAJUCI KONSTRUKTOR I OPERATOR DODJELE(PRIVREMENE OBJEKTE)
        Biblioteka(Biblioteka &&b);
        Biblioteka &operator =(Biblioteka &&b);
        
        //DESTRUKTOR
        ~Biblioteka()=default;
        
        //METODE ZA MANIPULACIJU SA PODACIMA
        void RegistrirajNovogKorisnika(int clanski_broj,std::string s1, std::string s2, std::string s3,std::string s4){
            if(!m2.count(clanski_broj))m2[clanski_broj]=std::make_shared<Korisnik>(Korisnik{s1,s2,s3,s4});
            else throw std::logic_error("Korisnik vec postoji");
        }
        void RegistrirajNovuKnjigu(int broj,std::string s1,std::string s2,std::string s3,int god){
            if(!m1.count(broj))m1[broj]=std::make_shared<Knjiga> (Knjiga(s1,s2,s3,god));
            else throw std::logic_error("Knjiga vec postoji");
        }
        Korisnik &NadjiKorisnika(int clanski_broj){
            if(!m2.count(clanski_broj))throw std::logic_error("Korisnik nije nadjen");
            else return *m2[clanski_broj];
        }
        Knjiga &NadjiKnjigu(int evidencijski_broj){
            if(!m1.count(evidencijski_broj))throw std::logic_error("Knjiga nije nadjena");
            else return *m1[evidencijski_broj];
        }
        void IzlistajKorisnike()const {
            for(auto it=m2.begin();it!=m2.end();it++){
                std::cout << "Clanski broj: " << it->first << std::endl;
                std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
                std::cout << "Adresa: " << it->second->adresa << std::endl;
                std::cout << "Broj telefona: " << it->second->telefon << std::endl;
                std::cout << std::endl;
            }
        }
        void IzlistajKnjige() const {
            for(auto it=m1.begin();it!=m1.end();it++){
                std::cout << "Evidencijski broj: " << it->first << std::endl;
                std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
                std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
                std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
                if(it->second->DaLiJeZaduzena()){
                    std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
                }    
                std::cout << std::endl;
            }
        }
        void ZaduziKnjigu(int evidencijski_broj,int clanski_broj){
            try{
                if(NadjiKnjigu(evidencijski_broj).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
                else NadjiKnjigu(evidencijski_broj).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        void RazduziKnjigu(int evidencijski_broj){
            try{
                std::shared_ptr<Knjiga> p (&NadjiKnjigu(evidencijski_broj));
                if(!p->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
                else p->RazduziKnjigu();
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        void PrikaziZaduzenja(int clanski_broj) {
            try{
                std::shared_ptr<Korisnik> p(&NadjiKorisnika(clanski_broj));
                if(!m2.count(clanski_broj)) std::cout << "Nema zaduzenja za tog korisnik!" << std::endl;
                for(auto it=m1.begin();it!=m1.end();it++){
                    if(it->second->DajKodKogaJe()==p){
                        std::cout << "Evidencijski broj: " << it->first << std::endl;
                        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
                        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
                        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
                        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
                    }
                }    
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
};

Biblioteka::Biblioteka(const Biblioteka &b){
    try{
        for(auto it=b.m1.begin();it!=b.m1.end();it++) m1.insert(std::pair<int,std::shared_ptr<Knjiga>>(it->first,std::make_shared<Knjiga>(Knjiga(*(it->second)))));
        for(auto it=b.m2.begin();it!=b.m2.end();it++) m2.insert(std::pair<int,std::shared_ptr<Korisnik>>(it->first,std::make_shared<Korisnik>(Korisnik(*(it->second)))));    
    }
    catch(...){
        throw;
    }
}

Biblioteka &Biblioteka::operator=(const Biblioteka &b){
    try{
        if(b.m1.size() >= m1.size()){                                // BRISE I KNJIGE I MIJENJA IH SA NOVIM //
            for(auto it=m1.begin();it!=m1.end();it++){
                it->second=nullptr;
                m1.erase(it);
            }
            try{
                for(auto it=b.m1.begin();it!=b.m1.end();it++){
                    RegistrirajNovuKnjigu(it->first,it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
                }
            }
            catch(...){
                for(auto it=m1.begin();it!=m1.end();it++){ 
                    it->second=nullptr;
                }
                throw;
            }
        }
        else {
            for(auto it=m1.begin();it!=m1.end();it++){
                it->second=nullptr;
                m1.erase(it);
            }
            try{
                for(auto it=b.m1.begin();it!=b.m1.end();it++){
                    RegistrirajNovuKnjigu(it->first,it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
                }
            }
            catch(...){
                for(auto it=m1.begin();it!=m1.end();it++){ 
                    it->second=nullptr;
                }
                throw;
            }
        }
    }
    catch(...){
        throw;
    }
    try{
        if(b.m2.size() >= m2.size()){                                   // BRISE KORSINIKE I MIJENJA IH SA NOVIM //
            for(auto it=m2.begin();it!=m2.end();it++){
                it->second=nullptr;
                m2.erase(it);
            }
            try{
                for(auto it=b.m2.begin();it!=b.m2.end();it++){
                    RegistrirajNovogKorisnika(it->first,it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon);
                }
            }
            catch(...){
                for(auto it=m2.begin();it!=m2.end();it++){ 
                    it->second=nullptr;
                }
                throw;
            }
        }
        else {
            for(auto it=m2.begin();it!=m2.end();it++){
                it->second=nullptr;
                m2.erase(it);
            }
            try{
                for(auto it=b.m2.begin();it!=b.m2.end();it++){
                    RegistrirajNovogKorisnika(it->first,it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon);
                }
            }
            catch(...){
                for(auto it=m2.begin();it!=m2.end();it++){ 
                    it->second=nullptr;
                } 
                throw;
            }
        }
    }
    catch(...){
        throw;
    }
    return *this;
}

Biblioteka::Biblioteka(Biblioteka &&b){
    m1=b.m1;
    m2=b.m2;
    for(auto it=b.m1.begin();it!=b.m1.end();it++) it->second=nullptr;
    for(auto it=b.m2.begin();it!=b.m2.end();it++) it->second=nullptr;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b){
    std::swap(m1,b.m1);
    std::swap(m2,b.m2);
    return *this;
}

int main ()
{
    Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();

    return 0;
}