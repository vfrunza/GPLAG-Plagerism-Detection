/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::string;


class GradjanBiH
{
    public:
    enum Pol{Musko,Zensko};
    private:
    string ime;
    long long int JMBG;
    int dan,mjesec,godina,sifra,regija,posljednja;
    Pol spol;
    int BrojDana(int mjesec,int godina)
    {
        if(mjesec!=2)
        {
            if(mjesec==1 or mjesec==3 or mjesec==5 or mjesec==7 or mjesec==8 or mjesec==10 or mjesec==12)
                return 31;
            else if(mjesec==4 or mjesec==6 or mjesec==9 or mjesec==11)
                return 30;
            return 0;
        }
        if(godina%4==0 and godina%100!=0 or godina%400==0)
            return 29;
        return 28;
    }
    void Valjal(int dan,int mjesec,int godina)
    {
        if(godina<1 or dan<1 or mjesec<1 or mjesec>12 or dan>BrojDana(mjesec,godina))
            throw std::logic_error("JMBG nije validan");
    }
    void Sifra(int sifra)
    {
        if(sifra<0 or sifra>99)
            throw std::logic_error("Neispravni podaci");
    }
    int Kreiraj(int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9,int c10,int c11,int c12)
    {
        return (11-((7*(c1+c7))+(6*(c2+c8))+(5*(c3+c9))+(4*(c4+c10))+(3*(c5+c11))+(2*(c6+c12)))%11);
    }
    public:
    GradjanBiH(string ime_i_prezime,long long int jmbg)
    {
        long long int a(jmbg);
        int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
        int brojac(0);
        while(!a)
            a/=10,brojac++;
        if((brojac!=13 and brojac!=12) or jmbg<0)
            throw std::logic_error("JMBG nije validan");
        posljednja=(jmbg%10);
        c13=(jmbg%10);
        jmbg/=10;
        sifra=(jmbg%10);
        c12=(jmbg%10);
        jmbg/=10;
        sifra+=10*(jmbg%10);
        c11=(jmbg%10);
        jmbg/=10;
        sifra+=100*(jmbg%10);
        c10=(jmbg%10);
        jmbg/=10;
        if(sifra>=500)
            spol=Pol::Zensko;
        else
            spol=Pol::Musko;
        regija=(jmbg%10);
        c9=(jmbg%10);
        jmbg/=10;
        regija+=10*(jmbg%10);
        c8=(jmbg%10);
        jmbg/=10;
        godina=(jmbg%10);
        c7=(jmbg%10);
        jmbg/=10;
        godina+=10*(jmbg%10);
        c6=(jmbg%10);
        jmbg/=10;
        godina+=100*(jmbg%10);
        c5=(jmbg%10);
        jmbg/=10;
        mjesec=(jmbg%10);
        c4=(jmbg%10);
        jmbg/=10;
        mjesec+=10*(jmbg%10);
        c3=(jmbg%10);
        jmbg/=10;
        dan=(jmbg%10);
        c2=(jmbg%10);
        jmbg/=10;
        dan+=10*(jmbg%10);
        c1=(jmbg%10);
        if(c1!=0 and brojac==12)
            throw std::logic_error("JMBG nije validan");
        auto pomoc(Kreiraj(c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12));
        if((pomoc==11 and c13!=0) or pomoc==10 or c13!=pomoc)
            throw std::logic_error("JMBG nije validan");
        Valjal(dan,mjesec,godina);
        //treba provjeriti za druge gradjane
    }
    GradjanBiH(string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol)
    {
        try
        {
            Valjal(dan_rodjenja,mjesec_rodjenja,godina_rodjenja);
        }
        catch(std::logic_error)
        {
            throw std::logic_error("Neispravni podaci");
        }
        Sifra(sifra_regije);
        
    }
};
int main ()
{
	return 0;
}