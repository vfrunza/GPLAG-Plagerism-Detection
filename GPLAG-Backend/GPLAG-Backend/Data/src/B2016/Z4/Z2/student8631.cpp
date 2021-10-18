/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<stdexcept>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

enum Pol {Musko, Zensko};

class GradjaninBiH
{

    string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifraregije, pol_osobe, trinaesti;
    Pol pol;
    GradjaninBiH *prvi_pokazivac;
    static GradjaninBiH *drugi_pokazivac;


    void Testirajmbg(long long int jmbg) const {
        if(jmbg<999999999999 || jmbg>100000000000000)
            throw range_error("Pogresan jmbg!");
    }
    //GradjaninBiH operator=(GradjaninBiH Amina)=delete;

    void Za_drugi_konst(int dan, int mjesec, int godina, int sifra,Pol pol) {
        if(dan<10) {
            int niz[12];

            if(mjesec<10) niz[1]=0;

            else {
                niz[1]=(mjesec%10)/10;
            }
            niz[0]=dan;
            niz[2]=mjesec;
            int a=godina%10;
            int b=sifra%10;

            for(int i=3; i<5; i++) {
                niz[i]=godina%10;
                godina/=10;
            }
            for(int i=8; i<10; i++) {
                niz[i]=(pol_osobe%10)/10;
            }
            niz[5]=a;
            niz[6]=(sifra%10)/10;
            niz[7]=b;

            int brojac=0;
            GradjaninBiH *pok=prvi_pokazivac;
            while (pok!=nullptr) {
                if(pok->DajSifruRegije()==sifraregije &&pok->DajMjesecRodjenja()==mjesec_rodjenja && pok->DajDanRodjenja()==dan_rodjenja &&
                        pok ->DajGodinuRodjenja()==godina_rodjenja)
                    brojac++;
            }
            if(pol==Musko) brojac=brojac+0;
            else brojac=brojac+500;
            niz[10]=(brojac)%10;
            niz[11]=(11-(7*(niz[5])+6*(niz[0]+niz[6])+5*(niz[1]+niz[7])+4*(niz[2])+niz[8])+3*(niz[3]+niz[9])+2*(niz[4]+niz[10]))%11;
        }

        else if(dan>10) {
            int niz[13];
            int prvi=(dan%10)/10;
            int a=godina%10;
            int pol_=pol_osobe%10;
            int sifra_=sifra%10;
            niz[0]=prvi;
            niz[1]=dan;
            niz[3]=mjesec;
            if(mjesec<10) {
                niz[2]=mjesec%10;
                mjesec/=10;
            } else if(mjesec>10) {
                niz[2]=0;
            }

            for(int i=4; i<6; i++) {
                niz[i]=a/10;
            }
            for(int i=9; i<11; i++) {
                niz[i]=(pol_)/10;
            }
            niz[6]=a;
            niz[7]=sifra_/10;

            int brojac=0;
            GradjaninBiH *pok=prvi_pokazivac;
            while (pok!=nullptr) {
                if(pok->DajSifruRegije()==sifraregije && pok->DajDanRodjenja()==dan_rodjenja &&
                        pok->DajMjesecRodjenja()==mjesec_rodjenja && pok ->DajGodinuRodjenja()==godina_rodjenja)
                    brojac++;
            }
            if(pol==Musko) brojac=brojac+0;
            else brojac=brojac+500;

            niz[8]=sifra_;
            pol_osobe=brojac;
            niz[11]=pol_;
            niz[12]=(11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3])+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        }

    }
    void ispitaj(long long int jmbg) {

        long long int kopija=jmbg;
        int brojac=0;
        while (kopija!=0) {
            brojac++;
            kopija/=10;
        }
        if(brojac!=12 && brojac!=13) throw logic_error("JMBG nije validan");
    }

    void Za_prvi_konst(long long int jmbg) {
        ispitaj(jmbg);
        long long int novo_jmbg(jmbg);
        trinaesti=novo_jmbg%10;
        novo_jmbg/=10;
        pol_osobe=0;
        int i=0;
        while(i<3) {
            static int k=1;
            pol_osobe+=novo_jmbg%10*k;
            novo_jmbg/=10;
            k*=10;
            i++;
        }
        if(pol_osobe>500) pol=Zensko;
        else pol=Musko;
        sifraregije=0;
        int j=0;
        while(j<2) {
            static int k=1;
            sifraregije+=novo_jmbg%10*k;

            novo_jmbg/=10;
            k*=10;
            j++;
        }
        godina_rodjenja=0;
        int m=0;
        while(m<3) {
            static int k=1;
            godina_rodjenja+=novo_jmbg%10*k;

            novo_jmbg/=10;
            k*=10;
            m++;
        }
        if(godina_rodjenja<17) godina_rodjenja=godina_rodjenja+2000;
        else godina_rodjenja=godina_rodjenja+1000;

        mjesec_rodjenja=0;
        int n=0;
        while(n<2)

        {
            static int k=1;
            mjesec_rodjenja+=novo_jmbg%10*k;
            novo_jmbg/=10;
            k*=10;
            n++;
        }
        long long int kopija=jmbg;
        int brojac=0;
        while (kopija!=0) {
            brojac++;
            kopija/=10;
        }
        if(brojac!=12) {
            dan_rodjenja=novo_jmbg%10;
            novo_jmbg/=10;
            dan_rodjenja=dan_rodjenja+novo_jmbg*10;
        } else {
            dan_rodjenja=novo_jmbg;
        }
    }

public:

    GradjaninBiH(string ime_i_prezime, long long int jmbg);
    GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifraregije, Pol pol);
    string DajImeIPrezime() const;
    long long int DajJMBG()const;
    int DajDanRodjenja() const {
        return dan_rodjenja;
    }
    int DajMjesecRodjenja() const {
        return mjesec_rodjenja;
    }
    int DajGodinuRodjenja() const {
        return godina_rodjenja;
    }
    int DajSifruRegije() const;
    Pol DajPol() const {
        return pol;
    }
    void PromijeniImeIPrezime(string novo_ime) {
        ime_i_prezime=novo_ime;
    }
    /*
     ~GradjaninBiH() {
         GradjaninBiH * trenutni=sljedeci;
         while (trenutni!=this) {
             sljedeci=trenutni;
             trenutni=trenutni->prvi_pokazivac;
         }
         sljedeci->prvi_pokazivac=trenutni->prvi_pokazivac;
    }*/

    /*
      for(int i=0; i<13; i++)
        {
            while (i<3) {
                niz[i]=d;
                i+=2;
            }
            while (i<5) {
                niz[i]=m;
                i+=4;
            }
            while (i<8) {
                niz[i]=g;
                i+=7;
            }
            while (i<10) {
                niz[i]=sifra;
                i+=9;
            }
            while (i<13) {
                niz[i]=pol;
                i+=12;
            }
        }
        */
    //   trinaesti=(11-(7*(niz[11]+niz[5])+6*(niz[10]+niz[4])+5*(niz[9]+niz[3])+4*(niz[6])+niz[2])+3*(niz[7]+niz[1])+2*(niz[6]+niz[0]))%11;


};

bool  IspravnostDatuma(int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    if( godina%4==0 || godina%400==0 && godina %100!=0) broj_dana[1]++;
    return true;
    if(godina <1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        return false;
}
string DajIme(string s)
{
    int j=0;
    string ime;
    for(int i=0; i<s.size(); i++) {
        if(!(s[i]>'A'|| s[i]<'Z') &&  (s[i]>'a'|| s[i]<'z'))  j=i;
    }
    ime= s.substr(0,  j);
    return ime;
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int jmbg)
{
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::jmbg=jmbg;
    Za_prvi_konst(jmbg);
    if(!IspravnostDatuma(dan_rodjenja, mjesec_rodjenja, godina_rodjenja))
        throw  logic_error("JMBG nije validan");
}
GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja,int mjesec_rodjenja, int godina_rodjenja, int sifraregije, Pol pol)
{
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::dan_rodjenja=dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja=godina_rodjenja;
    if(sifraregije<0 || sifraregije>99) throw logic_error("Neispravn podaci");
    GradjaninBiH::sifraregije=sifraregije;
    GradjaninBiH::pol=pol;
    Za_drugi_konst(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifraregije, pol);
    if(!IspravnostDatuma(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw logic_error("Neispravni podaci");
}

string GradjaninBiH::DajImeIPrezime()const
{
    return ime_i_prezime;
}
long long int GradjaninBiH::DajJMBG() const
{
    return jmbg;
}

int GradjaninBiH::DajSifruRegije() const
{
    return sifraregije;
}




int main ()
{
    long long jmbg;
    int broj;
    cout<<"Koliko gradjana zelite unijeti po JMBG?"<<endl;
    cin>>broj;
    for(int i=0; i<broj; i++) {
        try {
            string ImePrezime;
            cout<<"Unesite ime i prezime(u istom redu):"<<endl;
            getline(cin, ImePrezime);
            std::cout << "Unesite JMBG:" << std::endl;
            GradjaninBiH Amina(ImePrezime,jmbg);
            cout<<"Unijeli ste gradjanina "<<DajIme(ImePrezime)<<"rodjenog "<<Amina.DajDanRodjenja()<<"."<<Amina.DajMjesecRodjenja()<<"."<<Amina.DajGodinuRodjenja()<<
                " u regiji"<<Amina.DajSifruRegije()<<",";
            if(Amina.DajPol()==Zensko) cout<<"zensko."<<endl;
            else cout<<"musko."<<endl;
        } catch(logic_error e) {
            cout<<e.what()<<endl;
        }
    }
    int broj_2;
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?"<<endl;
    cin>>broj_2;
    for(int i=0; i<broj_2; i++) {
        string ImePrezime;
        int d;
        int m;
        int g;
        int sifra_reg;
        char M_Z;
        Pol pol_covjek;
        cout<<"Unesite ime i prezime(u istom redu):"<<endl;
        getline(cin, ImePrezime);
        cout<<"Unesite datum rodjenja (format dd/mm/gg)"<<endl;
        cin>>d>>m>>g;
        cout<<"Unesite sifru regije:"<<endl;
        cin>>sifra_reg;
        cout<<"Unesite M za musko, Z za zensko:"<<endl;
        cin>>M_Z;
        if(M_Z=='M') pol_covjek=Musko;
        else pol_covjek=Zensko;

        try {
            cout<<"Unijeli ste gradjanina";
            GradjaninBiH Adna(ImePrezime, d,m,g, sifra_reg, pol_covjek);
            cout<<DajIme(ImePrezime)<<" JMBG:"<<Adna.DajJMBG()<<endl;
        } catch(logic_error e) {
            cout<<e.what()<<endl;
        }
    }
    return 0;
}
