/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
class Datum {
    int dan, mjesec, godina;
    void Provjera(int dan, int mjesec, int godina) {
        if(dan > 31 || dan < 1 || mjesec <1 || mjesec>12 ) throw std::domain_error("Neispravan datum");
        else if(((mjesec%2 ==0 && mjesec <7 ) || (mjesec%2!=0 && mjesec>7)) && dan>30 ) throw std::domain_error("Neispravan datum");
        else if(((godina%100 != 0 && godina%4==0) || godina%400 ==0) && mjesec==2 && dan>29) throw std::domain_error("Neispravan datum");
        else if(mjesec==2 && dan>28) throw std::domain_error("Neispravan datum");
    }
public:    
    Datum(int dan, int mjesec, int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina){
        Provjera(dan,mjesec,godina);
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    int DajDan() const{
        return dan;
    }
    int DajMjesec() const{
        return mjesec;
    }
    int DajGodinu() const{
        return godina;
    }
    void Ispisi() const{
        std::cout<<dan << "/" << mjesec<<"/" << godina;
    }

    
};

class Kupac{
    std::string ime_i_prezime;
    Datum *datum_rodjenja;
    void Provjera(std::string ime_i_prezime){
        for(int i =0; i < ime_i_prezime.size(); i++){
            if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-'))
                throw std::domain_error("Neispravno ime i prezime");
        }
    }
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        Provjera(ime_i_prezime);
        this->ime_i_prezime = ime_i_prezime;
        this->datum_rodjenja = new Datum( datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        Provjera(ime_i_prezime);
        this->ime_i_prezime = ime_i_prezime;
        this->datum_rodjenja->Postavi( datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
    }
    std::string DajImePrezime() const{
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const{
        return *datum_rodjenja;
    }
    void Ispisi() const{
        std::cout<< ime_i_prezime << "(";
        datum_rodjenja->Ispisi();
        std::cout<<")";
    }

};

class Stan{
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    void Provjera(int sprat,int broj_soba,double kvadratura){
        if(sprat<0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    }
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
     double kvadratura){
         Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
     }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,
     bool namjesten, double kvadratura){
         Provjera(sprat,broj_soba, kvadratura);
         this->adresa = adresa;
         this->sprat = sprat;
         this->broj_soba = broj_soba;
         this->namjesten = namjesten;
         this->kvadratura = kvadratura;
     }
    std::string DajAdresu() const{
        return adresa;
    }
    int DajSprat() const{
        return sprat;
    }
    int DajBrojSoba() const{
        return broj_soba;
    }
    bool DajNamjesten() const{
        return namjesten;
    }
    double DajKvadraturu() const {
        return kvadratura;
    }
    void Ispisi() const{
        std::cout<<"Stan se nalazi na adresi " << adresa << "na "<< sprat <<". spratu i ima "<< broj_soba;
        if(broj_soba == 1 || (broj_soba>20 && broj_soba%10 ==1)) std::cout << "sobu." << std::endl;
        else if((broj_soba>1 && broj_soba <5) || (broj_soba>20 && broj_soba%10 >1 && broj_soba%10<5) ) std::cout<<"sobe." << std::endl;
        else std::cout << "soba." <<std::endl;
        std::cout<<"Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        if(namjesten == true) std::cout<<"je namjesten.";
        else std::cout<<"nije namjesten.";
        
    }

};

class Prodaja{
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 const Datum &datum_prodaje, const Kupac &kupac_stana,
 const Stan &kupljeni_stan);
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
 const std::string &adresa_stana, int sprat_stana, int broj_soba,
 bool namjesten_stan, double broj_kvadrata);
void PromijeniKupca(const Kupac &novi_kupac); 
void PromijeniStan(const Stan &novi_stan);
void PromijeniDatumKupovine(const Datum &novi_datum);
void PromijeniCijenuProdaje(const double &nova_cijena);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const;
std::string DajImeKupca() const;
Datum DajDatumProdaje() const;
double DajCijenuStana() const;
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;

};



int main ()
{
    std::cout<<"Dobrodosli!"<<std::endl;
    
    while(1){
        std::cout << "Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja" <<std::endl;
        int a;
        std::cin >> a;
        if(a == 0) break;
        else if(a == 1){
            while(1){
                std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj" <<std::endl;
                int b; 
                std::cin >> b;
                if(b == 0) break;
                else if(b == 1){
                    bool gotovo = false;
                    while(gotovo == false){
                        try {
                            std::cout << "Unesite adresu: ";
                            std::string adresa;
                            std::cin.clear();
                            std::cin.ignor(1000,'\n');
                            std::getline(std::cin,adresa);
                            std::cout<<"Unesite sprat: ";
                            int sprat;
                            std::cin >> sprat;
                            std::cout << "Unesite broj soba: ";
                            int broj_soba;
                            std::cin >> broj_soba;
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            int namj;
                            bool namjesten;
                            std::cin >> namj;
                            if(namj == 1){
                                namjesten = true;
                            }
                            else if (namj == 0){
                                namjesten = false;
                            }
                            else {
                                throw std::domain_error("Neispravan unos podataka.");
                            }
                            
                            std::cout << "Unesite kvadraturu: ";
                            double kvadratura;
                            std::cin>> kvadratura;
                            
                            //Dodati stan
                            std::cout << "Stan je uspjesno dodan!" << std::endl;
                            gotovo = true;
                        }
                        catch(std::domain_error e){
                            std::cout <<"Izuzetak: " << e.what() << " Molimo unesite opet"
                        }
                    }
                }
                else if(b == 2){
                    std::cout << "Odaberite stan. Dostupni stanovi su:" <<std::endl;
                    /*for(int i = 0; i < ; i++){
                        std::cout << " " << i+1 << " - ";
                        nekistan.Ispisi();
                    }
                    */
                    try{
                        int c;
                        std::cin>>c;
                        //if(c < 0 || c > ) { }
                        while(1){
                            std::cout << "Odaberite polje koje zelite urediti:\n 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve" << std::endl;
                            int d;
                            if(d == 0){
                                break;
                            }
                            else if(d == 1){
                                std::cout << "Unesite adresu: ";
                                std::string adresa;
                                std::cin.clear();
                                std::cin.ignor(1000,'\n');
                                std::getline(std::cin,adresa);
                            }
                            else if(d == 2){
                                std::cout<<"Unesite sprat: ";
                                int sprat;
                                std::cin >> sprat;
                            }
                            else if(d == 3){
                                std::cout << "Unesite broj soba: ";
                                int broj_soba;
                                std::cin >> broj_soba;    
                            }
                            else if(d == 4){
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                int namj;
                                bool namjesten;
                                std::cin >> namj;
                                if(namj == 1){
                                    namjesten = true;
                                }
                                else if (namj == 0){
                                    namjesten = false;
                                }
                            }
                            else if(d == 5){
                                std::cout << "Unesite kvadraturu: ";
                                double kvadratura;
                                std::cin>> kvadratura;
                            }
                            else if(d == 6){
                                try {
                                    std::cout << "Unesite adresu: ";
                                    std::string adresa;
                                    std::cin.clear();
                                    std::cin.ignor(1000,'\n');
                                    std::getline(std::cin,adresa);
                                    std::cout<<"Unesite sprat: ";
                                    int sprat;
                                    std::cin >> sprat;
                                    std::cout << "Unesite broj soba: ";
                                    int broj_soba;
                                    std::cin >> broj_soba;
                                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                    int namj;
                                    bool namjesten;
                                    std::cin >> namj;
                                    if(namj == 1){
                                        namjesten = true;
                                    }
                                    else if (namj == 0){
                                        namjesten = false;
                                    }
                                    else {
                                        throw std::domain_error("Neispravan unos podataka.");
                                    }
                                    
                                    std::cout << "Unesite kvadraturu: ";
                                    double kvadratura;
                                    std::cin>> kvadratura;
                                    
                                    //Dodati stan
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    gotovo = true;
                                }
                                catch(std::domain_error e){
                                    std::cout <<"Izuzetak: " << e.what() << " Molimo unesite opet"
                                }
                            }
                            else {
                                
                            }
                        }
                    }
                    
                }
                else if(b == 3){
                    /*
                    for(int i = 0; i < ; i++){
                        std::cout << i+1;
                        nekistan.Ispisi();
                    }
                    */
                }
                else if(b == 4){
                    return;
                }
                else {
                    
                }
            }

        }
        else if(a == 2){
            while(1){
                std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj" << std::endl;
                int b;
                std::cin >> b;
                if(b == 0){
                    break;
                }
                else if(b == 1){
                    while(1){
                        try{
                            std::cout <<"Unesite ime i prezime kupca: ";
                            std::string ime_i_prezime;
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::getline(std::cin, ime_i_prezime);
                            
                            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                            char q,w;
                            int dan, mjesec, godina;
                            std::cin >> dan >> q >> mjesec >> w >> godina;
                            
                            
                            std::cout << "Kupac je uspjesno dodan!" << std::endl;
                            break;
                        
                        }
                        catch(std::domain_error){
                            
                        }
                    }
                    
                }
                else if(b == 2){
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" <<std::endl;
                    /*
                    for(int i = 0; i < ; i++){
                        std::cout << " " << i+1 << " - ";
                        nekikupac.Ispisi();
                    }
                    */
                     try{
                            std::cout <<"Unesite ime i prezime kupca: ";
                            std::string ime_i_prezime;
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::getline(std::cin, ime_i_prezime);
                            
                            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                            char q,w;
                            int dan, mjesec, godina;
                            std::cin >> dan >> q >> mjesec >> w >> godina;
                            
                            
                            std::cout << "Kupac je uspjesno izmijenjen!" << std::endl;
                            break;
                        
                        }
                        catch(std::domain_error){
                            
                        }
                }
                else if(b == 3){
                    /*
                    for(int i =0; i < ; i++){
                        nekikupac.Ispisi();
                    }
                    */
                }
                else if(b == 4){
                    return;
                }
                else {
                    
                }
            }
        }
        else if(a == 3){
            
        }
        else {
            
        }
    }
	return 0;
}