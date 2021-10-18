/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

bool IspravanDatum(int dan, int mjesec, int godina);
bool TestirajIme(std::string s);
class Datum{
        int d,m,g;
    public:
        Datum(int dan, int mjesec, int godina){
            if(IspravanDatum(dan,mjesec,godina)==false) throw std::domain_error("Neispravan datum");
            d=dan;m=mjesec;g=godina;
        }
        void Postavi(int dan, int mjesec, int godina){
            if(IspravanDatum(dan,mjesec,godina)==false) throw std::domain_error("Neispravan datum");
            d=dan;m=mjesec;g=godina;
        }
        int DajDan() const{return d;}
        int DajMjesec() const{return m;}
        int DajGodinu() const{return g;}
        void Ispisi() const{std::cout << d<<"/"<<m<<"/"<<g;}

};

class Kupac{
        std::string ime;
        Datum d;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): d(datum_rodjenja){
            ime=ime_i_prezime;
            
        }
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
            if(TestirajIme(ime_i_prezime)==false) throw std::domain_error("Neispravno ime i prezime");
            ime=ime_i_prezime;
            try{
                d=datum_rodjenja;
            }catch(std::domain_error){
                throw;
            }
        }
        std::string DajImePrezime() const{return ime;}
        Datum DajDatumRodjenja() const{return d;}
        void Ispisi() const{std::cout << ime <<" (";
            d.Ispisi();
            std::cout  << ")";
        }

};
class Stan{
        std::string ad;
        int spr;
        int br_soba;
        bool postavljen;
        double kvadrata;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
            if(sprat<0||broj_soba<0||kvadratura<0) throw std::domain_error("Neispravan unos podataka");
            ad=adresa;
            sp=sprat;
            br_soba=broj_soba;
            postavljen=namjesten;
            kvadrata=kvadratura;
        }
        void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
            if(sprat<0||broj_soba<0||kvadratura<0) throw std::domain_error("Neispravan unos podataka");
            ad=adresa;
            sp=sprat;
            br_soba=broj_soba;
            postavljen=namjesten;
            kvadrata=kvadratura;
        }
        std::string DajAdresu() const{return ad;}
        int DajSprat() const{return sp;}
        int DajBrojSoba() const{return br_soba;}
        bool DajNamjesten() const{return postavljen;}
        double DajKvadraturu() const{return kvadrata;}
        void Ispisi() const{
            std::cout << "Stan se nalazi na adresi " <<ad<<" na "<<sp<<" spratu i ima "<<br_soba;
            if(br_soba==2||br_soba==3||br_soba==4)std::cout<<" sobe."<<std::endl;
            else std::cout<<" sobe."<<std::endl;
            std::cout << "Kvadratura stana je " <<kvadrata<<" (m^2) i stan je ";
            if(postavljen) std::cout << "namjesten";
            else std::cout<<"nije namjesten";
        }

};
int main ()
{
	return 0;
}

bool IspravanDatum(int dan, int mjesec, int godina){
    if(mjesec>12||mjesec<1) return false;
    if(godina<0) return false;
    if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12){
        if(dan>31 || dan<1) return false;
    }
    if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11){
        if(dan>30 || dan<1) return false;
    }
    if(mjesec==2){
        if(godina%4==0 && godina%100!=0 || godina%400==0){
           // if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) 
            if(dan>29|| dan<1) return false;
        }else{
            if(dan>28|| dan<1) return false;
        }
    }
    return true;
}
bool TestirajIme(std::string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!='-' && s[i]!='\'' && s[i]!=' ')
            if((s[i]<'A'&& s[i]>'9') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z' || s[i]<'0') return false;
    }
    return true;
}