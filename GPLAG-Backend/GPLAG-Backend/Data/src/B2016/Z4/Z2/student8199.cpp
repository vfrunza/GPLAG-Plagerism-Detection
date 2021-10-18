/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class GradjaninBiH
{
    enum Pol {Musko, Zensko};
    string ime_i_prezime;
    long long int jmbg;
    
    GradjaninBiH (string ime, long long int jmb)
    {
        int d, m, g, pom(jmb);
        
        int br[13];
        
        if (log(10) + 1 != 13)
        {
            for (int i = 12; i > 0; i--)
            {
                br[i] = pom % 10;
                pom /= 10;
            }
            br[0] = 0;
        }
        
        else
        {
            for (int i = 12; i >= 0; i--)
            {
                br[i] = pom % 10;
                pom /= 10;
            }
        }
        
        d = br[0] * 10 + br[1];
        m = br[2] * 10 + br[3];
        g = 1000 + br[4] * 100 + br[5] * 10 + br[6];
        
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((g % 4==0 && g % 100 !=0) || g % 400==0) broj_dana[1]++;
        if (g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) throw domain_error("Neispravan datum");
        
        ime_i_prezime = ime;
        jmbg = jmb;
    }
    
    GradjaninBiH(string ime, int d, int m, int g, int sifra, Pol pol)
    {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
        if (g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) throw domain_error("Neispravni podaci");
        
        if (sifra < 0 || sifra > 99) throw domain_error ("Neispravni podaci");
        
        ime_i_prezime = ime;
        
        
    }
};

int main ()
{
	return 0;
}