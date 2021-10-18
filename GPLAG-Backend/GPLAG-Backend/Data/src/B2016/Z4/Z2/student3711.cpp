/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <memory>

int male=0;
int female=500;

class GradjaninBiH{
    private:
        GradjaninBiH *posljednje_kreirani;
        static GradjaninBiH *zadnji;
        std::string ime_i_prezime;
        int dan_rodjenja, mjesec_rodjenja, godina_rodjenja;
        int sifra_regije;
        long long int jmbg;
        int pol;
        // privatne fcije
        long long int DajBroj(GradjaninBiH &ptr){
            return ptr.jmbg;
        }
        bool ImaLiIstih(long long int broj){
            GradjaninBiH *priv = zadnji;
			for (;;){
                if (priv == nullptr) return false;
                if (broj == DajBroj(*priv)) return true;
                priv = priv->posljednje_kreirani;
			}
        }
    public:
        enum Pol {Musko, Zensko};
        //KONSTRUKTOR 1
        GradjaninBiH (std::string ime_i_prezime, long long int jmbg){
            if(jmbg<=0){
                throw std::logic_error("Jmbg nije validan");
            }
            // Rad sa ciframa
            long long int c[13];
            c[0] = 0;
            long long int tmp_desetica = 1000000000000;
            long long int tmp_broj = jmbg;
            for(int i=0; i<13; i++){
                c[i] = tmp_broj / tmp_desetica;
                tmp_broj = tmp_broj % tmp_desetica;
                tmp_desetica = tmp_desetica / 10;
            }
            // d1 d2 m1 m2 g1 g2 g3
            //  0  1  2  3  4  5  6
            int dan, mjesec, godina;
            dan = c[0] * 10 + c[1] * 1;
            mjesec = c[2] * 10 + c[3] * 1;
            godina = c[4] * 100 + c[5] * 10 + c[6] * 1 + 1000;
            int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0){
                broj_dana[1]++;
            }
            if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1] ){
                throw std::logic_error("Jmbg nije validan");
            }
            int kontrolna_cifta = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11])) % 11;
            
            if(kontrolna_cifta == 11){
                kontrolna_cifta = 0;
            } else if(kontrolna_cifta == 10){
                throw std::logic_error("Neispravn kod");
            }
            
            if(kontrolna_cifta != c[12]){
                throw std::logic_error("Jmbg nije validan");
            }
            
            int sifra = c[7]*10 + c[8]*1;
            
            // Prolazak kroz listu
            if (zadnji == nullptr) {
                GradjaninBiH::ime_i_prezime = ime_i_prezime;
                GradjaninBiH::dan_rodjenja = dan; GradjaninBiH::mjesec_rodjenja = mjesec; GradjaninBiH::godina_rodjenja = godina;
                GradjaninBiH::jmbg = jmbg;
                GradjaninBiH::sifra_regije = sifra;
                if(c[9]>=5){
                    GradjaninBiH::pol = Zensko;
                } else {
                    GradjaninBiH::pol = Musko;
                }
                posljednje_kreirani = nullptr;
                zadnji = this;
            }
            else {
				if (ImaLiIstih(jmbg)){
				    throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
				}
				else {
                    GradjaninBiH::ime_i_prezime = ime_i_prezime;
                    GradjaninBiH::dan_rodjenja = dan; GradjaninBiH::mjesec_rodjenja = mjesec; GradjaninBiH::godina_rodjenja = godina;
                    GradjaninBiH::jmbg = jmbg;
                    GradjaninBiH::sifra_regije = sifra;
                    if(c[9]>=5){
                        pol = Zensko;
                        GradjaninBiH::pol = 1;
                    } else {
                        pol = Musko;
                        GradjaninBiH::pol = 2;
                    }
					posljednje_kreirani = zadnji;
					zadnji = this;
				}
            }
        }
        
        // KONSTRUKTOR 2    
        GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
            // VALIDACIJE
            // - validacija datuma rodjenja
            int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if((godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0) || godina_rodjenja % 400 == 0){
                broj_dana[1]++;
            }
            if(godina_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja < 1 || dan_rodjenja > broj_dana[mjesec_rodjenja-1] ){
                throw std::logic_error("Neispravan podaci");
            }
            // - validacija sifre regije
            if(sifra_regije<0 || sifra_regije>99){
                throw std::logic_error("Neispravni podaci");
            } else {
                GradjaninBiH::sifra_regije = sifra_regije;
            }
            
            // KREIRANJE JMBGA
            long long int c[13];
            // dan rodjenja 
            c[0] = dan_rodjenja/10;
            c[1] = dan_rodjenja%10;
            // mjesec rodjenja
            c[2] = mjesec_rodjenja/10;
            c[3] = mjesec_rodjenja%10;
            // godina rodjenja
            int tmp_godina = godina_rodjenja; 
            c[6] = tmp_godina%10;
            tmp_godina = tmp_godina/10;
            c[5] = tmp_godina%10;
            tmp_godina = tmp_godina/10;
            c[4] = tmp_godina%10;
            // sifra regije
            c[7] = sifra_regije/10;
            c[8] = sifra_regije%10;
            
            // osobe na isti dan u istoj regiji
            // 0 - 499 M
            // 500 - 999 F
            if(pol == Musko){
                int tmp_male = male;
                c[11] = tmp_male%10;
                tmp_male = tmp_male/10;
                c[10] = tmp_male%10;
                tmp_male = tmp_male/10;
                c[9] = tmp_male%10;
                ++male;
            } else if(pol == Zensko){
                int tmp_female = female;
                c[11] = tmp_female%10;
                tmp_female = tmp_female/10;
                c[10] = tmp_female%10;
                tmp_female = tmp_female/10;
                c[9] = tmp_female%10;
                ++female;
            } else {
                throw std::logic_error("Neispravni podaci");
            }
            // kontrolna cifra
            c[12] = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11])) % 11;
            if(c[12] == 11){
                c[12] = 0;
            } else if(c[12] == 10){
                throw std::logic_error("Neispravn kod");
            }
            
            // sve cifre u broj
            long long int tmp_desetica = 1000000000000;
            long long int jedinstveni_broj = 0;
            for(int i=0; i<13; i++){
                jedinstveni_broj = jedinstveni_broj + (c[i] * tmp_desetica);
                tmp_desetica = tmp_desetica / 10;
            }
            
            /*while(1){
                bool istina(false);
                istina = ImaLiIstih(jedinstveni_broj);
                if(istina == true){
                    if(pol == Zensko){
                        // promjeni cifru koda
                        int tmp_female = female;
                        c[11] = tmp_female%10;
                        tmp_female = tmp_female/10;
                        c[10] = tmp_female%10;
                        tmp_female = tmp_female/10;
                        c[9] = tmp_female%10;
                        ++female;
                        // pretvori u broj
                        for(int i=0; i<13; i++){
                            jedinstveni_broj = jedinstveni_broj + (c[i] * tmp_desetica);
                            tmp_desetica = tmp_desetica / 10;
                        }
                    } 
                    else if (pol == Musko){
                        // promjeni cifru koda
                        int tmp_male = male;
                        c[11] = tmp_male%10;
                        tmp_male = tmp_male/10;
                        c[10] = tmp_male%10;
                        tmp_male = tmp_male/10;
                        c[9] = tmp_male%10;
                        ++male;
                        // pretvori u broj
                        for(int i=0; i<13; i++){
                            jedinstveni_broj = jedinstveni_broj + (c[i] * tmp_desetica);
                            tmp_desetica = tmp_desetica / 10;
                        }
                    }
                } else if(istina == false){
                    break;
                }
            }*/
            
            
            if (zadnji == nullptr) {
                GradjaninBiH::jmbg = jedinstveni_broj;
                GradjaninBiH::ime_i_prezime = ime_i_prezime;
                GradjaninBiH::dan_rodjenja = dan_rodjenja; GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja; GradjaninBiH::godina_rodjenja = godina_rodjenja;
                GradjaninBiH::pol = pol;
                GradjaninBiH::sifra_regije = sifra_regije;
                posljednje_kreirani = nullptr;
                zadnji = this;
            }
            else {
				if (ImaLiIstih(jmbg)){
        			if(pol == Musko){
                        int tmp_male = male;
                        c[11] = tmp_male%10;
                        tmp_male = tmp_male/10;
                        c[10] = tmp_male%10;
                        tmp_male = tmp_male/10;
                        c[9] = tmp_male%10;
                        ++male;
                    } else if(pol == Zensko){
                        int tmp_female = female;
                        c[11] = tmp_female%10;
                        tmp_female = tmp_female/10;
                        c[10] = tmp_female%10;
                        tmp_female = tmp_female/10;
                        c[9] = tmp_female%10;
                        ++female;
                    }
                    
                    long long int tmp_desetica = 1000000000000;
                    long long int jedinstveni_broj = 0;
                    for(int i=0; i<13; i++){
                        jedinstveni_broj = jedinstveni_broj + (c[i] * tmp_desetica);
                        tmp_desetica = tmp_desetica / 10;
                    }
				    throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
				}
				else {
                    GradjaninBiH::jmbg = jedinstveni_broj;
                    GradjaninBiH::ime_i_prezime = ime_i_prezime;
                    GradjaninBiH::dan_rodjenja = dan_rodjenja; GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja; GradjaninBiH::godina_rodjenja = godina_rodjenja;
                    GradjaninBiH::pol = pol;
                    GradjaninBiH::sifra_regije = sifra_regije;
					posljednje_kreirani = zadnji;
					zadnji = this;
				}
            }
        }
        
        // Daj Fcije
        std::string DajImeIPrezime () const{
            return GradjaninBiH::ime_i_prezime;
        }
        long long int DajJMBG () const {
            return jmbg;
        }
        int DajDanRodjenja() const{
            return dan_rodjenja;
        }
        int DajMjesecRodjenja() const{
            return mjesec_rodjenja;
        }
        int DajGodinuRodjenja() const{
            return godina_rodjenja;
        }
        int DajSifruRegije() const{
            return sifra_regije;
        }
        Pol DajPol() const{
            if(GradjaninBiH::pol == 0){
                return Musko;
            } else {
                return Zensko;
            }
        };
        // promjena prezimena osobe
        void PromijeniImeIPrezime(std::string novo_ime){
            GradjaninBiH::ime_i_prezime = novo_ime;
        };
        // DESTRUKTOR
        ~GradjaninBiH(){
            GradjaninBiH *zaBrisanje = zadnji;
            GradjaninBiH *pomicni = zadnji;
            pomicni = pomicni->posljednje_kreirani;
            zaBrisanje = nullptr;
        }
};

GradjaninBiH* GradjaninBiH::zadnji(nullptr);
//GradjaniBiH* GradjaniBiH::posljednje_kreirani(nullptr);

int main (){
    GradjaninBiH *pokazivaci[100];
    for(int i=0; i<100; i++){
        pokazivaci[i] = nullptr;
    }
    int broj_po_jmbg;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? ";
    std::cin >> broj_po_jmbg;
    for(int i=0; i<broj_po_jmbg; i++){
        std::string ime_tmp;
        std::cout << "Unesite ime i prezime (u istom redu): ";
        std::getline(std::cin, ime_tmp);
        std::cin.ignore(10000,'\n');
        int jmbg;
        std::cout << "Unesite JMBG: ";
        std::cin >> jmbg;
        std::cin.ignore(10000,'\n');
        
        pokazivaci[i] = new GradjaninBiH(ime_tmp, jmbg);
        
        std::cout << pokazivaci[i]->DajImeIPrezime() << std::endl;
    

    }   
    
    
    /*
    int broj_po_datumu;
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjena, regiji i polu? ";
    std::cin >> broj_po_datumu;
    for(int i=0; i<broj_po_datumu; i++){
        
    }*/

    /*
    try{
        std::cout << "------------------------------------------------" << std::endl;
        GradjaninBiH o ("Zan Klod Sejdic", 13, 5, 1956, 17 , GradjaninBiH::Pol::Musko);
        GradjaninBiH b ("Mujo Mujic", 13, 5, 1956, 17 , GradjaninBiH::Pol::Musko);
        GradjaninBiH c ("Fata Selimovic", 13, 5, 1956, 17 , GradjaninBiH::Pol::Zensko);
        std::cout << o.DajPol() << "|" << o.DajImeIPrezime() << "|" << o.DajJMBG() << "|" << o.DajDanRodjenja() << "|" << o.DajMjesecRodjenja() << "|" << o.DajGodinuRodjenja() << "|" << std::endl;
        std::cout << b.DajPol() << "|" << b.DajImeIPrezime() << "|" << b.DajJMBG() << "|" << b.DajDanRodjenja() << "|" << b.DajMjesecRodjenja() << "|" << b.DajGodinuRodjenja() << "|" << std::endl;
        std::cout << c.DajPol() << "|" << c.DajImeIPrezime() << "|" << c.DajJMBG() << "|" << c.DajDanRodjenja() << "|" << c.DajMjesecRodjenja() << "|" << c.DajGodinuRodjenja() << "|" << std::endl;
        
        GradjaninBiH g1("Rambo Sulejmanovic", 3013017180005);
        GradjaninBiH g2("Zan Klod Sejdic", 110969191334);
        std::cout << g1.DajPol() << "|" << g1.DajImeIPrezime() << "|" << g1.DajJMBG() << "|" << g1.DajDanRodjenja() << "|" << g1.DajMjesecRodjenja() << "|" << g1.DajGodinuRodjenja() << "|" << std::endl;
        std::cout << g2.DajPol() << "|" << g2.DajImeIPrezime() << "|" << g2.DajJMBG() << "|" << g2.DajDanRodjenja() << "|" << g2.DajMjesecRodjenja() << "|" << g2.DajGodinuRodjenja() << "|" << std::endl;
        
        GradjaninBiH d ("Huso Selimovic", 13, 5, 1956, 17 , GradjaninBiH::Pol::Musko);
        std::cout << d.DajPol() << "|" << d.DajImeIPrezime() << "|" << d.DajJMBG() << "|" << d.DajDanRodjenja() << "|" << d.DajMjesecRodjenja() << "|" << d.DajGodinuRodjenja() << "|" << std::endl;
        
        GradjaninBiH e ("Erol Red", 13, 5, 1956, 17 , GradjaninBiH::Pol::Musko);
        std::cout << e.DajPol() << "|" << e.DajImeIPrezime() << "|" << e.DajJMBG() << "|" << e.DajDanRodjenja() << "|" << e.DajMjesecRodjenja() << "|" << e.DajGodinuRodjenja() << "|" << std::endl;
    
        std::cout << "------------------------------------------------" << std::endl;
    } catch (std::logic_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    } */
    
    return 0;
}