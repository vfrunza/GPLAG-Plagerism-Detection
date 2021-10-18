/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <vector>
class Radnik {
    public:
    std::string ime_i_prezime, adresa;
    int telefon;
    Radnik (std::string ime_i_prezime, std::string adresa, int telefon) : ime_i_prezime(ime_i_prezime), adresa(adresa), telefon(telefon){}
    std::string DajIme() const { return ime_i_prezime; }
    std::string DajAdresu() const { return adresa; }
    int DajTelefon() const { return telefon; }
};
class Imenik 
{
    std::vector<std::shared_ptr<Radnik>> radnici;
    
    void IspisiRadnika(const Radnik &r) {
       
        std::cout << "Ime i prezime: " << r.ime_i_prezime << std::endl
                      << "Adresa: " << r.adresa << std::endl
                      << "Telefon: " << r.telefon << std::endl;
    }
    
public:
    
    explicit Imenik(){}
    ~Imenik(){}
    
    Imenik(const Imenik &i){
       radnici.resize(i.radnici.size()); 
       for( auto x : i.radnici) {
           radnici.push_back(std::make_shared<Radnik> (*x));
       }
    }
    Imenik(Imenik &&i) {
           radnici= std::move(i.radnici);
           i.radnici.clear();
        }
    Imenik &operator = ( const Imenik &i) {
        radnici.clear();
        radnici.resize(i.radnici.size()); 
       for( auto x : i.radnici) {
           radnici.push_back(std::make_shared<Radnik> (*x));
       }
    }
    Imenik &operator = (Imenik &&i){
        std::swap(i.radnici,radnici);
    }
    
    void DodajRadnika(const Radnik &r)
    {
        radnici.push_back(std::make_shared<Radnik>(r));
    }
    void DodajRadnika(std::string ime_i_prezime, std::string adresa,int telefon){
        radnici.push_back(std::make_shared<Radnik>(Radnik(ime_i_prezime,adresa,telefon)));
    }
    void DodajRadnika(std::shared_ptr<Radnik> r){
       std::shared_ptr<Radnik> k=std::make_shared<Radnik>(r);
       radnici.push_back(k);
    }
    void IspisiRadnika(std::string ime_i_prezime) {
       auto r(std::find_if(radnici.begin(),radnici.end(), [&ime_i_prezime](std::shared_ptr<Radnik> r1){
            return (ime_i_prezime==r1->ime_i_prezime);
        }));
        if (r==radnici.end()) throw "error";
        std::cout << "Ime i prezime: " << (**r).ime_i_prezime << std::endl
                      << "Adresa: " << (**r).adresa << std::endl
                      << "Telefon: " << (**r).telefon << std::endl;
    }
    
    void IspisiSveNaSlovo (char slovo){
        for (int i=0; i<radnici.size(); i++){
            if (radnici[i]->ime_i_prezime[0]==slovo)
            IspisiRadnika(*radnici[i]);
        }
    }
    
    void IspisiSortirano (){
        std::sort(radnici.begin(),radnici.end(), [] (std::shared_ptr<Radnik> r1, std::shared_ptr<Radnik> r2) {
            return (r1->ime_i_prezime<r2->ime_i_prezime);
        });
        IspisiImenik();
    }
    
    void IspisiImenik()
    {
        for(int i = 0; i < radnici.size(); i++) {
            std::cout << "Ime i prezime: " << radnici[i]->ime_i_prezime << std::endl
                      << "Adresa: " << radnici[i]->adresa << std::endl
                      << "Telefon: " << radnici[i]->telefon << std::endl;
        }
    }
    
    int& operator [] (std::string ime_i_prezime) {
        auto r(std::find_if(radnici.begin(),radnici.end(), [&ime_i_prezime](std::shared_ptr<Radnik> r1){
            return (ime_i_prezime==r1->ime_i_prezime);
        }));
        if (r==radnici.end()) throw "error";
        return (**r).telefon;
    }
    
};
int main()
{
    Radnik r1{"Meho Mehic", "Zmaja od Bosne 13, Sarajevo", 1234};
    Radnik r2{"Pero Peric", "Travnicka 15, Zenica", 4321};
    Imenik i;
    i.DodajRadnika(r1);
    i.DodajRadnika(r2);
    i.IspisiImenik();
    return 0;
}
