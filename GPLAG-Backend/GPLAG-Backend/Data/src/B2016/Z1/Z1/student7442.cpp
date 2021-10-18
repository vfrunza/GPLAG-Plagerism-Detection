/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> IntVektor;

IntVektor IzbaciDuple(IntVektor vek)
{
    IntVektor v(vek);
   // std::cout<<"TEKST"<<int(v.size())-1;
    for(int i = 0; i<(int(v.size())-1); i++) {
        //std::cout<<"proba";
        for(int j = i+1; j<v.size(); j++) {
            if(v[i]==v[j]) {
                for(int k=j; k<(int(v.size())-1); k++) {
                    v[k]=v[k+1];

                }
                j--;
                v.resize(int(v.size())-1);
            }

        }
    }


    return v;
}


IntVektor Ternarni ( int a)
{

    IntVektor ternarni;
    int broj(a);
    if(broj==0) ternarni.push_back(broj);
    while(broj!=0) {
        ternarni.push_back(abs(broj%3));
        broj=broj/3;
    }
    return ternarni;
}

bool postoji(std::vector<int>v, int trazeni)
{
    for (int i = 0; i < v.size(); i++) {
        if(trazeni==v[i])return true;
    }
    return false;
}


IntVektor IzdvojiGadne( IntVektor v, bool OpakGadan )
{
    IntVektor pomocni;

   // std::cout<<pomocni.size();
    if(OpakGadan) {
        for(int j=0; j<v.size(); j++) {
            IntVektor brojac(3, 0);
            IntVektor ternarnibroj=Ternarni(v[j]);

            for(int i=0; i<ternarnibroj.size(); i++) {
                if(ternarnibroj[i]==0) brojac[0]++;
                else if(ternarnibroj[i]==1) brojac[1]++;
                else if(ternarnibroj[i]==2) brojac[2]++;
            }
            bool paran=true;
            for(int i=0; i<brojac.size(); i++) {
                if(brojac[i]!=0 && brojac[i]%2!=0) paran=false;
            }
            if(paran && !postoji(pomocni,v[j]) ) pomocni.push_back(v[j]);
        }
    } else if(!OpakGadan) {
        for(int j=0; j<v.size(); j++) {
            IntVektor brojac(3, 0);
            IntVektor ternarnibroj=Ternarni(v[j]);

            for(int i=0; i<ternarnibroj.size(); i++) {
                if(ternarnibroj[i]==0) brojac[0]++;
                else if(ternarnibroj[i]==1) brojac[1]++;
                else if (ternarnibroj[i]==2) brojac[2]++;
            }
            bool neparan=true;
            for(int i=0; i<brojac.size(); i++) {
                if(brojac[i]!=0 && brojac[i]%2==0) neparan=false;
            }
            if(neparan&& !postoji(pomocni,v[j]) ) pomocni.push_back(v[j]);

        }
    }
    IntVektor rezultat(IzbaciDuple(pomocni));

    return rezultat;
}

int main ()
{
    IntVektor v1;
    int broj;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
//std::cout << "Odvratnih: " << IzdvojiGadne({2460, 608, 426, 6560, 364}, false).size();
    while(std::cin>>broj && broj!=0) {
        v1.push_back(broj);
    }
 
    IntVektor novi=IzdvojiGadne(v1, 1);
    std::cout<<"Opaki: ";
    for(int i=0; i<novi.size(); i++) std::cout<<novi[i]<<" ";
    IntVektor novi1=IzdvojiGadne(v1, 0);
    std::cout<<std::endl<<"Odvratni: ";
     for(int i=0; i<novi1.size(); i++) std::cout<<novi1[i]<<" ";
    return 0;
}