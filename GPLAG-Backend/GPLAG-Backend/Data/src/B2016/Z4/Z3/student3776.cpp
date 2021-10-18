#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

const double eps(1e-10);

class Datum{
    int dan,mjesec,godina;
public:
Datum(int dan, int mjesec, int godina){Postavi(dan,mjesec,godina);}
void Postavi(int dan, int mjesec, int godina);
int DajDan() const { return dan;}
int DajMjesec() const { return mjesec;}
int DajGodinu() const { return godina;}
void Ispisi() const {std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
void Datum::Postavi(int d,int m,int g){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0  || g%400==0) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw std::domain_error("Neispravan datum!");
    dan=d; mjesec=m; godina=g;
}

class Kupac{
    static bool Isprava(std::string s){
        int duzina(0);
        int p(s.length());
          for(int i(0);i<s.length();i++){
         if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')  || s[i]==' '  || s[i]=='-' || s[i]=='"' ){ duzina++;}
    }
    if(duzina==p){return true;}
    return false;
    }
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) :  ime_i_prezime(ime_i_prezime),datum_rodjenja(datum_rodjenja) {Postavi(ime_i_prezime,datum_rodjenja);}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;}
    void Ispisi() const {std::cout<<ime_i_prezime; std::cout<<"(";datum_rodjenja.Ispisi(); std::cout<<")";}
};
    void Kupac::Postavi(const std::string &s,const Datum &d){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(!Isprava(s)) throw std::domain_error("Neispravno ime i prezime");
    if(datum_rodjenja.DajGodinu()<1 || datum_rodjenja.DajDan()<1 || datum_rodjenja.DajMjesec()<1 || datum_rodjenja.DajMjesec()>12 || datum_rodjenja.DajDan()>broj_dana[datum_rodjenja.DajMjesec()-1]){
        throw std::domain_error("Neispravan datum!");
    }
   else  ime_i_prezime=s; datum_rodjenja=d;
}

class Stan{
    std::string adresica;
    int spratic,sobica;
    bool namjesteno_sve;
    double kvadrata;
     static bool Jednaki(double x,double y){
		if(std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y))) {return true;}
		return false;
	}
    static bool Nejednakost(double a,double b){
        if((a<b) && !Jednaki(a,b)){return true;}
        return false;
    }
    static int Cifre(int broj){
        int br_cif(0),n=broj;
        while(n!=0){
            n/=10;
            br_cif++;
        }
        return br_cif;
    }
    static int modul(int broj){
        int n=broj;
        return n%10;
    }
    static int Odrediti(int broj){
        int brojcifara=Cifre(broj);
        int modulo=modul(broj);
        if(brojcifara==1 && broj==1) {return 1;}/* u*/
        if( brojcifara==1 && (broj==2 || broj==3 || broj==4  )) {return 2;}
        if(brojcifara==1 && (broj>=5 && broj<=20)) {return 3; }
        if(brojcifara!=1 && modulo==1) {return 1;}
        if(brojcifara!=1 && (modulo>=2 && modulo<=4)) {return 2;}
        if(brojcifara!=1 && (modulo>=5 && modulo<=9)) {return 3;}
        if(modulo==0) {return 3;}
    }
    static std::string IspisiNamjesten(bool dokaz){
        std::string s;
        if(dokaz)  s="je namjesten";
        else s="nije namjesten";
        return s;
    }
    public:
    
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){ Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const{ return adresica;}
    int DajSprat() const{ return spratic;}
    int DajBrojSoba() const {return sobica;}
    bool DajNamjesten() const { return namjesteno_sve;}
    double DajKvadraturu() const{ return kvadrata;}
    void Ispisi() const {
    if(Odrediti(DajBrojSoba())==1){std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<" spratu i ima "<<DajBrojSoba()<<" sobu. Kvadratura stana je "<<DajKvadraturu()<<"(m^2)"<<" i stan "<<IspisiNamjesten(DajNamjesten());}
    if(Odrediti(DajBrojSoba())==2){std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<" spratu i ima "<<DajBrojSoba()<<" sobe. Kvadratura stana je "<<DajKvadraturu()<<"(m^2)"<<" i stan "<<IspisiNamjesten(DajNamjesten());}
    if(Odrediti(DajBrojSoba())==3){std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<" spratu i ima "<<DajBrojSoba()<<" soba. Kvadratura stana je "<<DajKvadraturu()<<"(m^2)"<<" i stan "<<IspisiNamjesten(DajNamjesten());}
    }
};
    void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
        if(sprat<0 || broj_soba<0 || Nejednakost(kvadratura,0)) throw std::domain_error("Neispravan unos podataka");
        else adresica=adresa; spratic=sprat; sobica=broj_soba; namjesteno_sve=namjesten; kvadrata=kvadratura;
    }
    
    class Prodaja{
    std::string agent,mucenik,adress;
    double cijena,kvadrati;
     Datum dp;
     Stan novistan;
     Kupac kup;
    int danp,mjesecp,godp,brsob,sprt;
    bool jelNamjesten;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, 
    const Kupac &kupac_stana,const Stan &kupljeni_stan): 
    agent(ime_agenta_prodaje), cijena(cijena_stana), dp(datum_prodaje),novistan(kupljeni_stan),kup(kupac_stana) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
            int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            const std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
            const std::string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata) : roda(datum_rodjenja_kupca), agent(ime_agenta_prodaje),
            cijena(cijena_stana), danp(dan_prodaje), mjesecp(mjesec_prodaje), godp(godina_prodaje),
            mucenik(ime_kupca), adress(adresa_stana),sprt(sprat_stana),brsob(broj_soba),
            jelNamjesten(namjesten_stan),kvadrati(broj_kvadrata) {}
            
    void PromijeniKupca(const Kupac &novi_kupac){ kup=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){novistan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum){ dp=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena=nova_cijena;}
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

    void Prodaja::PomjeriDanUnaprijed() {   Datum dat1(dat); 
    dat1.dan++;     
    if(dat1.dan > Datum::BrojDana(mjesec, godina)) { 
        dat1.dan = 1; dat1.mjesec++;     
        
    }    if(dat1.mjesec > 12) { 
        }    return dat1; 
        }
    




int main ()
{
    try{
        Datum b(18,10,1996);
        std::string s="Emir Jusic";
    Kupac a(s,b);
    std::string g=a.DajImePrezime();
    /*std::cout<<g;*/
    std::string kk="Nahorevska 136";
    int sp=5;
    int brs=5;
    bool n=true;
    double kv= 97;
    Stan stano(kk,sp,brs,n,kv);
    stano.Ispisi();
    }
    
    catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}