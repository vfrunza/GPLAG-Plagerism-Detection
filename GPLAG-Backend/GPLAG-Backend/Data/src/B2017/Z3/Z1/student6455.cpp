/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <new>
#include <limits>
#include <stdexcept>
#include <cmath>
//tutorijal 6 zadatak 1
template <typename NekiTip>
NekiTip* GenerirajStepeneDvojke(int n){
    if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan! \n");
    NekiTip* pok=nullptr;
     if(std::pow(2,n)>std::numeric_limits<NekiTip>::max()) throw std::runtime_error("Prekoracen dozvoljeni opseg!\n");
    try{
        pok=new NekiTip[n];
        for(int i=0;i<n;i++){
            pok[i]=std::pow(2,i);
        }
       
    }
    catch(...){
        std::cout<<"Nedovoljno memorije!\n";
    }
    return pok;
}
int main ()
{
    std::cout<<"Unesite cijeli broj n: \n";
    int n;
    std::cin>>n;
    long long int *pok=nullptr;
    try{
    pok=GenerirajStepeneDvojke<long long int>(n);
    for(int i=0;i<n;i++){
        std::cout<<pok[i]<<" ";
    }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    catch(std::runtime_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}
