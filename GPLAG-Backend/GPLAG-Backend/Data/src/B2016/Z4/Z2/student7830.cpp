/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>

class GradjanjnBiH{ 
    std::string iip;
    long long int JMBG;
    GradjanjnBiH* prosli_gradjanin;
    static GradjanjnBiH* posljenji_gradjanin;
    bool DatumTest(int dan, int mjesec, int godina) const 
    {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0)
            broj_dana[1]++;
        if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
            return false;
        return true;
    }
public:
    enum Pol {Musko, Zensko};
    GradjanjnBiH(std::string ime_i_prezime, long long int jmbg) 
    {
        int dan = jmbg/int(pow(10,11));
        int mjesec = jmbg%int(pow(10,11))/int(pow(10,9));
        int godina_rodjenja;
        if(JMBG/int(pow(10,6))%int(pow(10,3)) > 17) 
            godina_rodjenja = 1000+JMBG/int(pow(10,6))%int(pow(10,3)); 
        else 
            godina_rodjenja = 2000+JMBG/int(pow(10,6))%int(pow(10,3));
        bool ispravan_datum(DatumTest(dan, mjesec, godina_rodjenja));
        if(!ispravan_datum)
            throw std::logic_error("JMBG nije validan");
        iip = ime_i_prezime; 
        JMBG = jmbg;
        prosli_gradjanin = posljenji_gradjanin;
        GradjanjnBiH* pok(this);
        while(pok != nullptr)
        {
            pok = pok->prosli_gradjanin;
            if(pok->JMBG == jmbg)
                throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        posljenji_gradjanin = this;
    }
    GradjanjnBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
    {
        iip = ime_i_prezime;
        int tr_broj(0);
        JMBG = dan_rodjenja*pow(10,11) + mjesec_rodjenja*pow(10,9) + (godina_rodjenja%1000)*pow(10,6) + sifra_regije*pow(10,4);
        prosli_gradjanin = posljenji_gradjanin;
        GradjanjnBiH* pok = this;
        while(pok != nullptr)
        {
            pok = pok->prosli_gradjanin;
            if(pok->JMBG/10000 == JMBG/10000)
                tr_broj++;
        }
        JMBG += tr_broj*10;
        long long int c13 = 11 - (7*(dan_rodjenja/10 + godina_rodjenja%10) + 6*(dan_rodjenja%10 + sifra_regije/10) + 5*(mjesec_rodjenja/10 + sifra_regije%10) 
            + 4*(mjesec_rodjenja%10 + tr_broj/100) + 3*(godina_rodjenja%1000/100 + tr_broj%100/10) + 2*(godina_rodjenja%100/10 + tr_broj%10))%11;
        if(c13 == 11)
            c13 = 0;
        if(c13 == 10)
            throw std::logic_error("JMBG nije validan");
        posljenji_gradjanin = this;
    }
    std::string DajImeIPrezime() const {return iip;}
    long long int DajJMBG() const {return JMBG;}
    int DajDanRodjenja() const {return JMBG/int(pow(10,11));}
    int DajMjesecRodjenja() const {return JMBG/int(pow(10,9))%int(pow(10,11));}
    int DajGodinuRodjenja() const {if(JMBG/int(pow(10,6))%int(pow(10,3)) > 17) return 1000+JMBG/int(pow(10,6))%int(pow(10,3)); else return 2000+JMBG/int(pow(10,6))%int(pow(10,3));}
    int DajSifruRegije() const {return JMBG/int(pow(10,4))%int(pow(10,6));}
    Pol DajPol() const { if(JMBG/10%int(pow(10,8)) > 0 && JMBG/10%int(pow(10,8)) < 499) return Musko; else return Zensko;}
    void PromijeniImeIPrezime(std::string novo_ime) {iip = novo_ime;}
};

int main ()
{
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG?";
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::string iip;
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, iip);
        std::cout<<"Unesite JMBG: ";
        long long int jmbg;
        std::cin>>jmbg;
        GradjanjnBiH temp(iip, jmbg);
        std::cout<<"Unijeli ste gradjanina "<<temp.DajImeIPrezime()<<" rodjenog "<<temp.DajDanRodjenja()<<"."<<temp.DajMjesecRodjenja()<<"."<<temp.DajGodinuRodjenja()<<" u regiji "<<temp.DajSifruRegije()<<", "<<temp.DajPol()<<".";
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?";
    int m;
    std::cin>>m;
    for(int i = 0; i < m; i++)
    {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::string iip;
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, iip);
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): ";
        int d,m,g;
        char t;
        std::cin.ignore(10000, '\n');
        std::cin>>d>>t>>m>>t>>g;
        std::cout<<"Unesite sifru regije: ";
        int sifra;
        std::cin>>sifra;
        std::cout<<"Unesite M za musko, Z za zensko: ";
        char pol;
        std::cin.ignore(10000, '\n');
        std::cin>>pol;
        GradjanjnBiH::Pol pol2;
        if(pol == 'M')
            pol2 = GradjanjnBiH::Musko;
        if(pol == 'Z')
            pol2 = GradjanjnBiH::Zensko;
        GradjanjnBiH temp(iip, d, m, g, sifra, pol2);
        std::cout<<"Unijeli ste gradjanina "<<iip<<" JMBG: "<<temp.DajJMBG();
    }
	return 0;
}