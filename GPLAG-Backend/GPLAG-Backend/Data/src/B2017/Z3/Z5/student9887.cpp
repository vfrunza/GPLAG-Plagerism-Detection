/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <new>
#include <vector>
//tutorijal 6 zadatak 2

template <typename NekiTip>
auto KreirajIzvrnutiNiz(NekiTip pocetak, NekiTip iza_kraja)->typename std::remove_reference<decltype(pocetak)>::type{
   typedef  typename std::remove_reference<decltype(*pocetak)>::type TipElemenata;
   TipElemenata* pokazivac=nullptr;
    try{
        pokazivac=new TipElemenata[iza_kraja-pocetak];
   int velicina(iza_kraja-pocetak);
   while(pocetak!=iza_kraja){
       pokazivac[velicina-1]=*pocetak;
       velicina--;
       pocetak++;
   }
  
   }
   catch(std::bad_alloc){
       throw;
   }
   return pokazivac;
}
int main ()
{
    std::cout<<"Koliko zelite elemenata: \n";
    int n;
    std::cin>>n;
    std::vector<double> v(n);
    std::cout<<"Unesite elemente: \n";
    for(int i=0;i<n;i++){
        std::cin>>v.at(i);
    }
    
    double *pok=nullptr;try{
    pok=KreirajIzvrnutiNiz(&v[0], &v[n]);
        for(int i=0;i<n;i++){
            std::cout<<pok[i]<<" ";
        }
        delete[] pok;
    }
    catch(...){
        std::cout<<"Problemi sa memorijom!\n";
    }
    
	return 0;
}
