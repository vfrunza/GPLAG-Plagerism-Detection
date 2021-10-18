/*B 2017/2018, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
bool DaLiJeProst(int b)
{
    long int n=b;
    int i,m;
    if (n<0)
        n*=(-1);
    if(n<2)return false;
    else
        m=sqrt(n);
    for(i=m; i>1; i--) {
        if(n%i==0)return false;
    }
    return true;
}
bool DaLiJeSimetrican(int n)
{
    std::deque<int> a;
    int i=0,j=0;
    if(n==-1)
        return 0;
    do {
        a.push_front(n%3);
        j++;
        n/=3;
    } while(n!=0);
    do {
        if (a.at(i)!=a.at(j-1))
            return 0;
        i++;
        j--;
    } while(i<=j);
    return 1;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a,bool d)
{
    int e;
    std::vector<int> b;
    std::vector<int> c;
    for(int i=0; i<a.size(); i++) {
        e=a.at(i);
        if (d==1) {
            if (DaLiJeProst(e)&&DaLiJeSimetrican(e))
                b.push_back(a.at(i));
        } else
            if (!DaLiJeProst(e)&&DaLiJeSimetrican(e))
                c.push_back(a.at(i));
    }
    if(d==1)
         c=b;
        
        
        
    for (int i=0; i<c.size(); i++) {
        for(int j=i; j<c.size(); j++)  {

            if (i==j&&j+1<c.size())
                j++;
            if(i==j&&i+1==c.size())
                break;
            if(c.at(i)==c.at(j)) {
                c.erase(c.begin() + j);
                j--;
            }
        }
    }
        
        
        
        
        
     return c;
}

int main ()
{
    int d,c,i;
    std::vector<int> a;
    std::vector<int> b;
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    do {
        std::cin>>d;
        a.push_back(d);
    } while(d!=-1);
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin>>c;

    if(c!=0&&c!=1) {
        do {
            std::cout<<"Neispravan unos! Unesite ponovo: ";
            std::cin>>c;
        } while(c!=0&&c!=1);
    }
    b=IzdvojiSimetricneTernarne(a,c);


    if(b.size()==0) {
        if(c==1)
            std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
        else
            std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";

    } else {
        if(c==1) {
            std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        } else
            std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for (i=0; i<b.size()-1; i++) {

            std::cout<<b.at(i)<<", ";
        }
        std::cout<<b.at(i)<<".";
    }
    return 0;
}