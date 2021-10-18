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
#include<cstdlib>

bool DaLiJeProst (int n )
{
    for(int i=2; i<n; i++) {

        if (n%i==0) return false;
    }
    return true;
}
int  PretvaranjeUTernarni (int n)
{
    int a(0);
    while(n!=0) {

        int Ostatak=n%3;
        n/=3;
        a=a*10+Ostatak;


    }
    return a;


}

int  OkreniNaopakoBroj (int n)
{

    int k(0);
    while(n>0) {
        int c=n%10;
        k=k*10+c;
        n/=10;


    }
    return k;
}
bool Simetricnost (int n)
{
    if(n==OkreniNaopakoBroj(n)) return true;
    else return false;
}

void PonavljanjeBrojeva(std::vector<int> &k)
{
    for(int i=0; i<k.size(); i++) {
        for(int j=i+1; j<k.size(); j++) {
            if(k.at(i)==k.at(j)) {
                k.erase(k.begin()+j);
                j--;
            }

        }
    }
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool tacno)
{
    PonavljanjeBrojeva(v);
    std::vector<int> a;
    std::vector<int> b;
    for(int i=0; i<v.size(); i++) {
        if(DaLiJeProst(std::abs(v.at(i)))  &&  (PretvaranjeUTernarni(std::abs(v.at(i)))==OkreniNaopakoBroj(PretvaranjeUTernarni(std::abs(v.at(i)))))) a.push_back(v.at(i));
        else if((DaLiJeProst(std::abs(v.at(i)))==false) && (PretvaranjeUTernarni(std::abs(v.at(i)))==OkreniNaopakoBroj(PretvaranjeUTernarni(std::abs(v.at(i)))))) b.push_back(v.at(i));
    }
    if (tacno) return a;
    else return b;
}

int main ()
{
int n;
    std::cout<<"Unesite elemente vektora (-1 za kraj):";
    std::vector<int> v;

  do{

      std::cin>>n;
      if(n!=-1 && n!=0 && n!=1)
      v.push_back(n);
  } while(n!=-1);
   

    std::cout<<" Unesite: 1 - za proste brojeve, 0 - za slozene brojeve:";
int tacno;
for(;;) {
    std::cin>>tacno;
    if( tacno==1 || tacno==0) break; 
    else if (tacno!=1 || tacno!=0) {
    std::cout<<" Neispravan unos! Unesite ponovo:";

}
    }
    


    auto a (IzdvojiSimetricneTernarne(v,true)) , b (IzdvojiSimetricneTernarne(v,false));
    
    if(tacno==true && a.size()==0) std::cout<<" Nema prostih simetricnih brojeva u vektoru.";
    else  if (tacno==true) {
         std::cout<<" Prosti simetricni brojevi iz vektora su: ";
         for(int i=0;i<a.size();i++) {
        if(i==a.size()-1)     std::cout<<a.at(i)<<".";
        else std::cout<<a.at(i)<<", ";
             
         }
     }
    
    else if (tacno==false && b.size()==0) std::cout<<" Nema slozenih simetricnih brojeva u vektoru.";
    else if(tacno==false) {
         std::cout<<" Slozeni simetricni brojevi iz vektora su: ";
         for(int i=0;i<b.size();i++) {
             if(i==b.size()-1) std::cout<<b.at(i)<<".";
             else  std::cout<<b.at(i)<<", ";
         
         }
     }
   

    return 0;
}
    
  
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
