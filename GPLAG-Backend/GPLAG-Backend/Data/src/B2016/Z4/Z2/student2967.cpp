#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

class  Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    Datum(long long int jmbg) {
        int k {12};
        int niz[13];
        long long int n1(jmbg);
        for (int i = 0; n1!=0; i++) {
            if(k<0)
                break;
            niz[k]=n1%10;
            n1 = n1/10;
            k--;
        }

        int dan,mjesec,godina;
        dan=niz[0]*10+niz[1];
        mjesec=niz[2]*10+niz[3];
        godina=1000+niz[4]*100+niz[5]*10+niz[6];
        if(godina<1917) godina+=1000;
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

void Datum::Postavi(int dan,int mjesec,int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0 )) broj_dana[1]++;
    if( godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
class GradjaninBiH
{
    std::string _ime_i_prezime;
    long long int _jmbg;
    Datum datum_rodjenja;
    int _sifra_regije;
    static GradjaninBiH *pos;
    static int broj_registrovanih;
    GradjaninBiH *pret=nullptr;

    static bool ProvjeraJMBG(long long int jmbg) ;
    static int DajKod(long long int jmbg) {
        int k {12};
        int niz[13];
        long long int n1(jmbg);
        for (int i = 0; n1!=0; i++) {
            if(k<0)
                break;
            niz[k]=n1%10;
            n1 = n1/10;
            k--;
        }
        return 100*niz[9]+10*niz[10]+niz[11];

    }
public:
    enum Pol {Musko, Zensko};
    Pol po;
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg): _ime_i_prezime(ime_i_prezime),_jmbg(jmbg),datum_rodjenja(jmbg) {
        if(!ProvjeraJMBG(jmbg)) throw std::logic_error ("JMBG nije validan");
        if(broj_registrovanih>1)
            for(auto k(pos); k!=nullptr; k=k->pret)
                if(k->DajJMBG()==jmbg)
                    throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
        pret=pos;
        pos=this;
        broj_registrovanih++;
        int brojac {},k {12};
        int niz[13];
        long long int n1(jmbg);
        for (int i = 0; n1!=0; i++) {
            if(k<0)
                break;
            niz[k]=n1%10;
            n1 = n1/10;
            k--;
            brojac++;
        }
        if(niz[0]==0)
            brojac++;

        _sifra_regije=10*niz[7]+niz[8];
        int z;
        z=100*niz[9]+10*niz[10]+niz[11];
        if(z>=0 && z<500) {
            po=Musko;
        }

        else if(z>=500 && z<1000) {
            po=Zensko;
        }

        int provjera;
        provjera=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        if( provjera== 11)
            provjera=0;

    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol): _ime_i_prezime(ime_i_prezime), datum_rodjenja(dan_rodjenja,mjesec_rodjenja,godina_rodjenja),_sifra_regije(sifra_regije) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if( (godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 )|| godina_rodjenja % 400 == 0 ) broj_dana[1]++;
        if( godina_rodjenja < 1 || dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > broj_dana[mjesec_rodjenja - 1]) throw std::domain_error("Neispravni podaci");
        else if(sifra_regije<0  ||  sifra_regije>99) throw std::domain_error("Neispravni podaci");
        int max=0;
        if(pol==0) {
            for(auto k(pos); k!=nullptr; k=k->pret)
                if(k->DajDanRodjenja()==dan_rodjenja && k->DajMjesecRodjenja()==mjesec_rodjenja && k->DajGodinuRodjenja()==godina_rodjenja && k->DajSifruRegije()==sifra_regije) {
                    if(DajKod(k->DajJMBG())!=max && max<500)
                        break;
                    else max++;
                }

        } else {
            max=500;
            for(auto k(pos); k!=nullptr; k=k->pret)
                if(k->DajDanRodjenja()==dan_rodjenja && k->DajMjesecRodjenja()==mjesec_rodjenja && k->DajGodinuRodjenja()==godina_rodjenja && k->DajSifruRegije()==sifra_regije) {
                    if(DajKod(k->DajJMBG())!=max && max<1000)
                        break;
                    else max++;
                }
        }
        long long int u=1000000000;
        _jmbg=100000000000*dan_rodjenja;
        
        _jmbg+=u*(mjesec_rodjenja);
        _jmbg+=(1000000*(godina_rodjenja-1000))+(10000*sifra_regije)+max*10;
        int niz[13],k {12};
        long long int n1(_jmbg);
        for (int i = 0; n1!=0; i++) {

            niz[k]=n1%10;
            n1 = n1/10;
            k--;
        }
        int c= 11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        if( c== 11)
            c=0;

        _jmbg+=c;
        pret=pos;
        pos=this;
    }
    ~GradjaninBiH() {
        auto iza(pos);
        for(auto k(pos); k!=nullptr; k=k->pret) {
            if(pos==this) {
                pos=this->pret;
                broj_registrovanih--;
                break;
            } else if(k==this) {
                broj_registrovanih--;
                iza->pret=k->pret;
                break;
            }
            iza=k;
        }

    }
    GradjaninBiH(const GradjaninBiH &r) = delete; // Zabrana kopiranja
    GradjaninBiH &operator =(const GradjaninBiH &r) = delete;
    std::string DajImeIPrezime() const {
        return _ime_i_prezime;
    }
    long long int DajJMBG() const {
        return _jmbg;
    }
    int DajDanRodjenja() const {
        return datum_rodjenja.DajDan();
    }
    int DajMjesecRodjenja() const {
        return datum_rodjenja.DajMjesec();
    }
    int DajGodinuRodjenja() const {
        return datum_rodjenja.DajGodinu();
    }
    int DajSifruRegije() const {
        return _sifra_regije;
    }
    Pol DajPol() const {
        Pol p;
        if(po==0)
            p=Musko;
        else p=Zensko;
        return p;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        _ime_i_prezime=novo_ime;
    }
};

GradjaninBiH * GradjaninBiH::pos=nullptr;
int GradjaninBiH::broj_registrovanih=0;

bool GradjaninBiH::ProvjeraJMBG(long long int jmbg)
{
    int brojac {},k {12};
    int niz[13];
    long long int n1(jmbg);
    for (int i = 0; n1!=0; i++) {
        if(k<0)
            return false;
        niz[k]=n1%10;
        n1 = n1/10;
        k--;
        brojac++;
    }
    if(niz[0]==0)
        brojac++;
    if(brojac!=13)
        return false;
    try {
        int dan,mjesec,godina;
        dan=niz[0]*10+niz[1];
        mjesec=niz[2]*10+niz[3];
        godina=1000+niz[4]*100+niz[5]*10+niz[6];
        if(godina<1917) godina+=1000;
        Datum d(dan,mjesec,godina);
    } catch(...) {

        return false;
    }
    int po;
    po=100*niz[9]+10*niz[10]+niz[11];
    if(po>=0 && po<500) {}

    else if(po>=500 && po<1000) {}

    else return false;

    int provjera;
    provjera=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if( provjera== 11)
        provjera=0;
    if(provjera==10)
        return false;

    if(provjera!=niz[12])
        return false;
    return true;
}
int main ()
{
    int n,i;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    std::cin>>n;
    std::string s;
    long long int u;
    GradjaninBiH *G[100];
    for(int j=0; j<n; j++) G[j]=nullptr;

    for( i=0; i<n; i++) {
        std::cout<<std::endl<<"Unesite ime i prezime (u istom redu): ";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,s);
        std::cout<<std::endl<<"Unesite JMBG: ";
        std::cin>>u;
        try {
            G[i]=new GradjaninBiH(s,u);
            std::cout<<std::endl<<"Unijeli ste gradjanina "<<G[i]->DajImeIPrezime()<<" rodjenog "<<G[i]->DajDanRodjenja()<<"."<<G[i]->DajMjesecRodjenja()<<"."<<G[i]->DajGodinuRodjenja()<<" u regiji "<<G[i]->DajSifruRegije()<<", ";
            if((G[i]->DajPol())==1)
                std::cout<<"zensko.";
            if((G[i]->DajPol())==0)
                std::cout<<"musko.";
        } catch(...) {
            std::cout<<std::endl<<"JMBG nije validan";
            i--;
        }
    }
    int l;
    std::cout<<std::endl<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    std::cin>>l;
    std::string d;
    for(int j=n; j<l+n; j++) G[j]=nullptr;
    for( i=n; i<l+n; i++) {
        std::cout<<std::endl<<"Unesite ime i prezime (u istom redu): ";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,s);
        std::cout<<std::endl<<"Unesite datum rodjenja (format dd/mm/gggg): ";
        try {
            std::getline(std::cin,d);
            int godina = std::stoi ( d.substr( 6, 4 ));
            int dan = std::stoi ( d.substr( 0, 2 ));
            int mjesec = std::stoi ( d.substr( 3, 2 ));
            std::cout<<std::endl<<"Unesite sifru regije: ";
            int sifra;
            std::cin>>sifra;
            std::cin.clear();
            std::cout<<std::endl<<"Unesite M za musko, Z za zensko: ";
            char c;
            std::cin>>c;
            if(c=='M')
                G[i]=new GradjaninBiH(s,dan,mjesec,godina,sifra,GradjaninBiH::Pol::Musko);
            else G[i]=new GradjaninBiH(s,dan,mjesec,godina,sifra,GradjaninBiH::Pol::Zensko);
            std::cout<<std::endl<<"Unijeli ste gradjanina "<<G[i]->DajImeIPrezime()<<" JMBG: "<<G[i]->DajJMBG()<<".";

        } catch(...) {
            std::cout<<std::endl<<"Neispravni podaci";
            i--;
        }
    }
    for(int i=0; i<n+l; i++) delete G[i];
    return 0;
}
