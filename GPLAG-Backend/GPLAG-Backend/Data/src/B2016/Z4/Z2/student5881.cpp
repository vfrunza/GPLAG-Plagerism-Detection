/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>

//enum Pol {Musko, Zensko};

struct UmotaniNiz{
    int a[13];
};

class GradjaninBiH{
    std::string ime_i_prezime;
    long long int JMBG;
    static int brojac;
    GradjaninBiH *pok;
    static GradjaninBiH *posljednji;
    UmotaniNiz Razvrstaj(long long int broj) const{
        UmotaniNiz rez;
        int i(12);
        while(broj!=0){
            rez.a[i]=broj%10;
            broj /= 10; i--;
        }
        return rez;
    }
    void TestDatuma(int dan, int mjesec, int godina) const{
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan < 1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error("Neispravan datum");
    }
    long long int GeneratorJMBG(int dan, int mjesec, int godina, int sifra, int pol) const{
        TestDatuma(dan,mjesec,godina);
        int niz[13];
        if(dan<10){ niz[0]=0; niz[1]=dan; }
        else{  for(int i=1; i>=0; i--){ niz[i]=dan%10; dan/=10; }}
        if(mjesec<10){ niz[2]=0; niz[3]=mjesec; }
        else{ for(int i=3; i>=2; i--){ niz[i]=mjesec%10; mjesec/=10; }}
        for(int i=6; i>=4; i--){ niz[i]=godina%10; godina/=10; }
        for(int i=8; i>=7; i--){ niz[i]=sifra%10; sifra/=10; }
        if(pol<10){ niz[9]=0; niz[10]=0; niz[11]=pol; }
        else if(pol<100){  niz[9]=0; for(int i=11; i>=10; i--){ niz[i]=pol%10; pol/=10; }}
        else {for(int i=11; i>=9; i--){ niz[i]=pol%10; pol/=10; }}
        niz[12]= 11 - (7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11])) %11;
        if(niz[12]==11) niz[12]=0;
        if(niz[12]==10) throw std::logic_error("JMBG nije validan");
        long long int rez(0); int brojac(0);
        for(int i=12; i>=0; i--){ rez += niz[i]*std::pow(10,brojac); brojac++; }
        return rez;
    }
    bool Postoji(long long int a, long long int b) const{
        return a==b;
    }
public:

    /*void Ispisi() const{ 
        std::cout << ime_i_prezime << std::endl;
        auto rez(Razvrstaj(JMBG));
        for(int i=0; i<13; i++) std::cout << rez.a[i];
        std::cout << std::endl;
    }*/
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime), JMBG(jmbg){
        while(posljednji!=nullptr){
            if(posljednji==this) continue;
            if(Postoji(this->JMBG,posljednji->JMBG)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            posljednji=posljednji->pok;
        }
        if(brojac==0){ pok=nullptr; posljednji=this; }
        else { pok=posljednji; posljednji=this; }
        brojac++;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
        int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime) {
            if(pol==Pol::Musko){
                int pol_broj(0);
                JMBG=GeneratorJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol_broj);
                while(posljednji!=nullptr){
                    if(Postoji(JMBG,posljednji->JMBG)) {
                        pol_broj++; 
                        if(pol_broj==500) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
                        JMBG=GeneratorJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol_broj);
                    }
                    else posljednji=posljednji->pok;
                }
            }
            else{
                int pol_broj(500);
                JMBG=GeneratorJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol_broj);
                while(posljednji!=nullptr){
                    if(Postoji(JMBG,posljednji->JMBG)) {
                        pol_broj++; 
                        if(pol_broj==1000) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
                        JMBG=GeneratorJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol_broj);
                    }
                    else posljednji=posljednji->pok;
                }
            }
        if(brojac==0){ pok=nullptr; posljednji=this; }
        else { pok=posljednji; posljednji=this; }
        brojac++;
    }
    ~GradjaninBiH(){
        GradjaninBiH *pok1=posljednji, *pok2=posljednji;
        if(pok2==this){ pok2=pok2->pok; posljednji=posljednji->pok; }
        else{
            while(pok2!=nullptr){
                pok2=pok2->pok;
                if(pok2==this){
                    pok2=pok2->pok;
                    pok1->pok=pok2;
                    break;
                }
                pok1=pok1->pok;
            }
        }
    }
    std::string DajImeIPrezime() const{ return ime_i_prezime; }
    long long int DajJMBG() const{return JMBG;}
    int DajDanRodjenja() const{ auto v(Razvrstaj(JMBG)); return v.a[0]*10+v.a[1];}
    int DajMjesecRodjenja() const{ auto v(Razvrstaj(JMBG)); return v.a[2]*10+v.a[3];}
    int DajGodinuRodjenja() const{ auto v(Razvrstaj(JMBG)); if(v.a[4]==0) return 2000+v.a[5]*10+v.a[6];
        return 1000+v.a[4]*100+v.a[5]*10+v.a[6];}
    int DajSifruRegije() const{ auto v(Razvrstaj(JMBG)); return v.a[7]*10+v.a[8];}
    Pol DajPol() const{ auto v(Razvrstaj(JMBG)); auto pom(v.a[9]*100+v.a[10]*10+v.a[11]);
        if(pom<500) return Pol::Musko; return Pol::Zensko;}
    void PromijeniImeIPrezime(std::string novo_ime){ ime_i_prezime=novo_ime; }
};

int GradjaninBiH::brojac = 0;
GradjaninBiH* GradjaninBiH::posljednji = nullptr;

int main ()
{
/*	int broj;
	std::cout << "Koliko gradjana zelite unijeti po JMBG? " ;
	std::cin >> broj;
	std::cin >> std::ws;
	for(int i=0; i<broj; i++){
	    std::string ime;
	    std::cin >> std::ws;
	    std::cout << "Unesite ime i prezime (u istom redu): " ;
	    std::getline(std::cin,ime);
	    long long int JMBG;
	    std::cout << "Unesite JMBG: " ;
	    std::cin >> JMBG;
	    GradjaninBiH gradjanin(ime,JMBG);
	    std::cout << "Unijeli ste gradjanina " << gradjanin.DajImeIPrezime() << " rodjenog " << gradjanin.DajDanRodjenja() << "." << gradjanin.DajMjesecRodjenja() << "." 
	              << gradjanin.DajGodinuRodjenja() << " u regiji " << gradjanin.DajSifruRegije() << ", " << gradjanin.DajPol() << "." << std::endl;
	}
	int x;
	std::cout << "Koliko gradjana zelite unijeti po datumu rodjena, regiji i polu? " ;
	std::cin >> x; std::cin >> std::ws;
	/*std::vector<GradjaninBiH> vec; 
	vec.resize(x);
	for(int i=0; i<x; i++){
	    std::string ime;
	    std::cin >> std::ws;
	    std::cout << "Unesite ime i prezime (u istom redu): " ;
	    std::getline(std::cin, ime);
	    int dan, mjesec, godina;
	    char znak1, znak2;
	    std::cout << "Unesite datum rodjenja (format dd/mm/gg): " ;
	    std::cin >> dan >> znak1 >> mjesec >> znak2 >> godina ;
	    int sifra;
	    std::cout << "Unesite sifru regije: " ;
	    std::cin >> sifra;
	    std::string pol;
	    std::cout << "Unesite M za musko, Z za zensko: " ;
	    std::cin >> std::ws;
	    std::getline(std::cin, pol);
	    //GradjaninBiH temp;
	    if(pol=='M'){ GradjaninBiH temp(ime,dan,mjesec,godina,sifra,0); std::cout << "Unijeli ste gradjanina " << ime << "JMBG: " << temp.DajJMBG(); }
	    else if(pol=='Z'){ GradjaninBiH temp(ime,dan,mjesec,godina,sifra,1); std::cout << "Unijeli ste gradjanina " << ime << "JMBG: " << temp.DajJMBG(); }
	    //std::cout << "Unijeli ste gradjanina " << ime << "JMBG: " << temp.DajJMBG();
	}
	*/
	return 0;
}