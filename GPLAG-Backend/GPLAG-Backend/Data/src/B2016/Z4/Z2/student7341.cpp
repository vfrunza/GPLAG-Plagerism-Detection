/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class GradjaninBiH {
    enum Pol {Musko, Zensko};
    std::string ime_i_prezime;
    int jmbg[13];
    GradjaninBiH *prethodni(nullptr);         //pokazivac na onog prije
    static GradjaninBiH *posljednji(nullptr); //pokazivac na zadnjeg napravljenog
    
    public:
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        GradjaninBiH *novi(new Gradanin);
        //prebacis jmbg u niz cifre
        long int pomocni(jmbg);
        int niz[13];
        int i=0;
        while(pomocni!=0){
            int cifra=int(pomocni%10);
            pomocni[i]=cifra;
            pomocni=pomocni/10;
            i++;
        }
        if(i==11) niz[12]=0;
        
        //testiras valja li jmbg tj je li dobar datum
        
        
        novi->ime_i_prezime=ime_i_prezime;
        novi->jmbg=jmbg;
       //ako je prvi posljedni ce biti nullptr jer je tako inicijaliziran na pocetku i onda prethodni je isto nullptr
       if(!(novi->posljednji)) novi->prethodni=nullptr;
       //ako nije na povetku prethodni pokazuje na zadnji napravljen
        else novi-> prethodni=novi->posljednji;
        novi->posljednji=novi;
    }
    
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol){
     // jel ispravan datum     
     int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if(godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0) broj dana[1]++;
     if(godina_rodjenja < 1 || dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || 
     dan_rodjenja > broj dana[mjesec_rodjenja – 1]) throw std::logic_error("Neispravani podaci!");
     
}
         
         
         
         
         
         
     }
    std::string DajImeIPrezime() const
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
}

int main ()
{
	return 0;
}