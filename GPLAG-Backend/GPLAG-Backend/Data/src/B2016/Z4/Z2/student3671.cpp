#include <iostream>
#include <string>
#include <stdexcept>



class GradjaninBiH {
    std::string gradjanin;
    long long int maticni_broj;
    
    bool Datum(int dan, int mjesec, int godina){
        int mjeseci[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0)
            mjeseci[1]++;
        if(dan < 1 || dan > mjeseci[mjesec-1] || mjesec < 1 || mjesec > 12)
            return false;
        return true;
    }
    
    static void Razvrstavanje(long long int broj, int &dan, int &mjesec, int &godina, int &sifra, int &spol){
        long long int br = broj;
        int brojac(0), suma(0), k(1);
        int c;
        c = br%10;
        br/=10;
        while(brojac<3){
            suma += br%10*k;
            k*=10;
            br/=10;
            brojac++;
        }
        spol = suma;
        
        suma=0; brojac=0; k=1;
        
        while(brojac<2){
            suma += br%10*k;
            k*=10;
            br/=10;
            brojac++;
        }
        sifra = suma;
        suma=0; brojac=0; k=1;
        while(brojac<3){
            suma += br%10*k;
            k*=10;
            br/=10;
            brojac++;
        }
        godina = 1000 + suma;
        suma=0; brojac=0; k=1;
        while(brojac<2){
            suma += br%10*k;
            k*=10;
            br/=10;
            brojac++;
        }
        mjesec = suma;
        suma=0; brojac=0; k=1;
        while(brojac<2){
            suma += br%10*k;
            k*=10;
            br/=10;
            brojac++;
        }
        dan = suma;
    }
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){ gradjanin = ime_i_prezime; maticni_broj = jmbg;
        int d, m, g, s, spol;
        Razvrstavanje(jmbg,d,m,g,s,spol);
        if(!Datum(d,m,g)) throw std::logic_error ("JMBG nije validan");
    };
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol){
        gradjanin = ime_i_prezime;
        if(!Datum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije > 99 || sifra_regije < 0) throw std::logic_error ("Neispravni podaci");
        long long int br(0);
        br = dan_rodjenja*100000000000 + mjesec_rodjenja*1000000000;
        
        /*br += mjesec_rodjenja*1000000000;
        
        
        /*br += (godina_rodjenja-1000)*100000;
        br += sifra_regije*100000;*/
        
        
        maticni_broj = br;
    };
    std::string DajImeIPrezime() const { return gradjanin; };
    long long int DajJMBG() const { return maticni_broj; };
    int DajDanRodjenja() const {
        int d, m, g, s;
        int spol;
        GradjaninBiH::Razvrstavanje(maticni_broj,d,m,g,s,spol);
        return d;
    };
    int DajMjesecRodjenja() const {
        int d, m, g, s;
        int spol;
        GradjaninBiH::Razvrstavanje(maticni_broj,d,m,g,s,spol);
        return m;
    };
    int DajGodinuRodjenja() const {
        int spol;
        int d, m, g, s;
        GradjaninBiH::Razvrstavanje(maticni_broj,d,m,g,s,spol);
        return g;
    };
    int DajSifruRegije() const {
        int spol;
        int d, m, g, s;
        GradjaninBiH::Razvrstavanje(maticni_broj,d,m,g,s,spol);
        return s;
    };
    Pol DajPol() const {
        int d, m, g, s;
        int spol;
        GradjaninBiH::Razvrstavanje(maticni_broj,d,m,g,s,spol);
        if(spol<=499)
            return Musko;
        return Zensko;
        
    };
    void PromijeniImeIPrezime(std::string novo_ime){
        GradjaninBiH::gradjanin = novo_ime;
    };
    
    
};

int main ()
{
    try{
        GradjaninBiH a("Bernes Hodzic", 1709995122157);
        GradjaninBiH b("Osman Hopica", 15, 4, 1994, 12, GradjaninBiH::Pol::Musko);
        std::cout<<b.DajJMBG()<<std::endl;
        std::cout<<a.DajImeIPrezime()<<" "<<a.DajJMBG()<<std::endl;
        std::cout<<a.DajDanRodjenja()<<" "<<a.DajMjesecRodjenja()<<" "<<a.DajGodinuRodjenja()<<" "<<a.DajSifruRegije()<<" "<<a.DajPol()<<std::endl;
        a.PromijeniImeIPrezime("Osman Hodzic");
        std::cout<<a.DajImeIPrezime();
    }catch(std::logic_error error){
        std::cout<<error.what();
    }
	return 0;
}