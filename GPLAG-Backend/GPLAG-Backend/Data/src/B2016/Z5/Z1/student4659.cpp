/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

struct Korisnik {
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
    std::string naslov,ime_pisca,zanr;
    int godina;
    Korisnik *pok;
    public:
        //KONSTRUKTOR SA 4 PARAMETRA
        Knjiga(std::string s1,std::string s2,std::string s3,int g):naslov(s1),ime_pisca(s2),zanr(s3),godina(g),pok(nullptr) {}
        
        //PRISTUPNE METODE
        std::string DajNaslov() const { return naslov; }
        std::string DajAutora() const { return ime_pisca; }
        std::string DajZanr() const { return zanr; }
        int DajGodinuIzdavanja() const { return godina; }
        Korisnik * DajKodKogaJe() const { return pok; }
        
        //METODE 
        void ZaduziKnjigu(Korisnik &k){ pok=&k; }
        void RazduziKnjigu(){ pok=nullptr; }
        bool DaLiJeZaduzena(){
            if(pok==nullptr)return false;
            return true;
        }
};

class Biblioteka {
    std::map<int,Knjiga*> m1;
    std::map<int,Korisnik*> m2;
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
        ~Biblioteka(){
            for(auto it=m1.begin();it!=m1.end();it++) delete it->second;
            for(auto it=m2.begin();it!=m2.end();it++) delete it->second;
        }
        
        //METODE ZA MANIPULACIJU SA PODACIMA
        void RegistrirajNovogKorisnika(int clanski_broj,std::string s1, std::string s2, std::string s3,std::string s4){
            if(!m2.count(clanski_broj))m2[clanski_broj]=new Korisnik{s1,s2,s3,s4};
            else throw std::logic_error("Korisnik vec postoji");
        }
        void RegistrirajNovuKnjigu(int broj,std::string s1,std::string s2,std::string s3,int god){
            if(!m1.count(broj))m1[broj]=new Knjiga(s1,s2,s3,god);
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
                Korisnik *pok1(&NadjiKorisnika(clanski_broj));
                Knjiga *pok2(&NadjiKnjigu(evidencijski_broj));
                if(pok2->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
                else pok2->ZaduziKnjigu(*pok1);
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        void RazduziKnjigu(int evidencijski_broj){
            try{
                Knjiga *p (&NadjiKnjigu(evidencijski_broj));
                if(!p->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
                else p->RazduziKnjigu();
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        void PrikaziZaduzenja(int clanski_broj) {
            try{
                Korisnik *p(&NadjiKorisnika(clanski_broj));
                auto it=m1.begin();
                for(;it!=m1.end();it++)if(it->second->DajKodKogaJe()==p)break;
                if(it==m1.end()){
                    std::cout << "Nema zaduzenja za tog korisnik!" << std::endl;
                    return ;
                }    
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
        for(auto it=b.m1.begin();it!=b.m1.end();it++) m1.insert(std::pair<int,Knjiga*>(it->first,new Knjiga(*(it->second))));
        for(auto it=b.m2.begin();it!=b.m2.end();it++) m2.insert(std::pair<int,Korisnik*>(it->first,new Korisnik(*(it->second))));    
    }
    catch(...){
        throw;
    }
}

Biblioteka &Biblioteka::operator=(const Biblioteka &b){
    try{
        if(b.m1.size() >= m1.size()){                                // BRISE I KNJIGE I MIJENJA IH SA NOVIM //
            for(auto it=m1.begin();it!=m1.end();it++){
                delete it->second;
                m1.erase(it);
            }
            try{
                for(auto it=b.m1.begin();it!=b.m1.end();it++){
                    RegistrirajNovuKnjigu(it->first,it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
                }
            }
            catch(...){
                for(auto it=m1.begin();it!=m1.end();it++){ 
                    delete it->second;
                }
                throw;
            }
        }
        else {
            for(auto it=m1.begin();it!=m1.end();it++){
                delete it->second;
                m1.erase(it);
            }
            try{
                for(auto it=b.m1.begin();it!=b.m1.end();it++){
                    RegistrirajNovuKnjigu(it->first,it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja());
                }
            }
            catch(...){
                for(auto it=m1.begin();it!=m1.end();it++){ 
                    delete it->second;
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
                delete it->second;
                m2.erase(it);
            }
            try{
                for(auto it=b.m2.begin();it!=b.m2.end();it++){
                    RegistrirajNovogKorisnika(it->first,it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon);
                }
            }
            catch(...){
                for(auto it=m2.begin();it!=m2.end();it++){ 
                    delete it->second;
                }
                throw;
            }
        }
        else {
            for(auto it=m2.begin();it!=m2.end();it++){
                delete it->second;
                m2.erase(it);
            }
            try{
                for(auto it=b.m2.begin();it!=b.m2.end();it++){
                    RegistrirajNovogKorisnika(it->first,it->second->ime,it->second->prezime,it->second->adresa,it->second->telefon);
                }
            }
            catch(...){
                for(auto it=m2.begin();it!=m2.end();it++){ 
                    delete it->second;
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
    Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.PrikaziZaduzenja(1234);
    return 0;
}