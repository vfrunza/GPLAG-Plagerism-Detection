#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace::std;

bool ValidanDatum(int dan,int mjesec,int godina)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1])
        return false;
    return true;
}
class GradjaninBiH
{   
    string ime;
    long long int jmbg;
    GradjaninBiH *prethodnik;
    static GradjaninBiH *posljednji;
    bool Provjera(long long int jmbg);
public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const
    {
        return ime;
    }
    long long int DajJMBG() const
    {
        return jmbg;
    }
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime)
    {
        ime = novo_ime;
    }
};

bool GradjaninBiH::Provjera(long long int jmbg)
{
    GradjaninBiH *pomocni = posljednji;
    while(pomocni != nullptr)
    {
        if((*pomocni).DajJMBG() == jmbg)
            return true;
    }
    return false;
}
GradjaninBiH *GradjaninBiH::posljednji(nullptr);
GradjaninBiH::GradjaninBiH(string ime_i_prezime,long long int jmbg)
{
    bool ima(false);
    if (posljednji == nullptr)
    {
            prethodnik = nullptr;
    }
    else
    {
        ima = Provjera(jmbg);
        prethodnik = posljednji;
    }
    posljednji = this;
    long long int t(jmbg);
    int c[13];
    int i = 12;
    while(t > 0)
    {
        c[i--] = t%10;
        t/=10;
    }
    if(i > 0)
        c[0] = 0;
    int c13 = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
    if(c13 == 10)
        throw logic_error("JMBG nije validan");
    int dan = c[0]*10 + c[1];
    int mjesec = c[2]*10 + c[3];
    int godina = c[4]*100 + c[5]*10 + c[6];
    if(godina > 17)
        godina+=1000;
    else
        godina+=2000;
    if(ValidanDatum(dan,mjesec,godina) == false)
        throw logic_error("JMBG nije validan");
    ime = ime_i_prezime;
    if(ima)
        jmbg+=10;
    GradjaninBiH::jmbg = jmbg;
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol)
{
    int dan(dan_rodjenja);
    int mjesec(mjesec_rodjenja);
    int godina(godina_rodjenja);
    long long int jmbg(0);
    if(!ValidanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja))
        throw logic_error("Neispravni podaci");
    if(sifra_regije < 0 || sifra_regije > 99)
        throw logic_error("Neispravni podaci");
    int cifre[13];
    cifre[1] = dan%10;
    dan/=10;
    cifre[0] = dan;
    cifre[3] = mjesec%10;
    mjesec = mjesec / 10;
    cifre[2] = mjesec;
    cifre[6] = (godina%100)%10;
    godina /= 10;
    cifre[5] = godina%10;
    godina /=10;
    cifre[4] = godina%10;
    cifre[8] = sifra_regije%10;
    sifra_regije /=10;
    cifre[7] = sifra_regije;
    if(pol == Musko)
    {
        cifre[9] = 0;
    }
    else
        cifre[9] = 5;
    cifre[10] = 0;
    cifre[11] = 0;
    int c[13];
    copy(cifre,cifre+13,c);
    int c13 = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
    if(c13 == 10)
        throw logic_error("Neispravni podaci");
    if(c13 == 11)
        cifre[12] = 0;
    else
        cifre[12] = c13;
    for(int i = 0;i < 13;i++)
    {
       jmbg += cifre[i];
       jmbg*=10;
    }
    jmbg/=10;
    bool ima;
    
    if (posljednji == nullptr)
            prethodnik = nullptr;
    else
    {
        ima = Provjera(jmbg);
        prethodnik = posljednji;
    }
    posljednji = this;
        
    GradjaninBiH::jmbg = jmbg;
    ime = ime_i_prezime;
}

int GradjaninBiH::DajDanRodjenja() const
{
    long long int t(jmbg);
    int c[13];
    int i(0);
    while(t > 0)
    {
        c[i] = t%10;
        t = t/10;
        i++;
    }
    int dan = c[12]*10 + c[11];
    return dan;
}

int GradjaninBiH::DajMjesecRodjenja() const
{
    long long int t(jmbg);
    int c[13];
    int i(0);
    while(t > 0)
    {
        c[i++] = t%10;
        t/=10;
    }
    return c[10]*10 + c[9];
}

int GradjaninBiH::DajGodinuRodjenja() const
{
    long long int t(jmbg);
    int c[13];
    int i(0);
    while(t > 0)
    {
        c[i++] = t%10;
        t/=10;
    }
    int godina = 100*c[8] + 10*c[7] + c[6];
    if(godina > 17)
        godina+=1000;
    else
        godina+=2000;
    return godina;
}
int GradjaninBiH::DajSifruRegije() const
{
    long long int t(jmbg);
    int c[13];
    int i(0);
    while(t > 0)
    {
        c[i++] = t%10;
        t/=10;
    }
    return c[5]*10 + c[4];
    
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    long long int t(jmbg);
    int c[13];
    int i(0);
    while(t > 0)
    {
        c[i++] = t%10;
        t/=10;
    }
    int p(c[3]*100 + 10*c[2] + c[1]);
    if(p >=500)
        return Pol::Zensko;
    return Pol::Musko;
}
int main()
{
    GradjaninBiH *g[100];
    int n;
    cout << "Koliko gradjanja zelite unijeti po JMBG? " << endl;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        string s;
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        cin.ignore();
        getline(cin,s);
        long long int jmbg;
        cout << "Unesite JMBG: " << endl;
        cin >> jmbg;
        cout << jmbg << "XX";
        try
        {
            GradjaninBiH a(s,jmbg);
            g[i] = &a;
            
        }
        catch(exception &e)
        {
            cout << e.what();
            continue;
        }
        cout << "Unjeli ste gradjanina " <<  (*g[i]).DajImeIPrezime() << " rodjenog ";
    }
    return 0;
}