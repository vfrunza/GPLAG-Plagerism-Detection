// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <stdexcept>
#include <vector>


template<typename pok_tip>
auto KreirajIzvrnutiNiz (pok_tip p1, pok_tip p2) -> decltype(*p1+*p1)*
{
    decltype (*p1+*p1) *rezultat = nullptr;

    pok_tip pomocni = p1;
    int n = 0;

    while (pomocni!=p2)
        {
            n++;
            pomocni++;
        }

    try
    {
        rezultat = new decltype(*p1+*p1) [n];
    }
    catch(...)
    {
        delete [] rezultat;
        rezultat = nullptr;

        std::bad_alloc e;
        throw e;
    }


     decltype (*p1+*p1) *pok = rezultat+n-1;

    while(p1 != p2)
    {
        *pok = *p1;
        p1++;
        pok--;

    }


    return rezultat;

}





int main ()
{
    try
    {
        std::cout<<"Koliko zelite elemenata: ";
        int n;
        std::cin>>n;

        try
        {
            std::vector<double> test(n);
        }
        catch(...)
        {
            std::cout<<"Nedovoljno memorije!";
            return 0;
        }

        std::cout<<"Unesite elemente: ";
        std::vector<double> v(n);
        for (int i{};i<n;i++)
            std::cin>>v[i];

        double *pok = KreirajIzvrnutiNiz(v.begin(),v.end());

        double *brisanje = pok;
        std::cout<<"Kreirani niz: ";
        for (int i{};i<n;i++)
            {
                std::cout<<*pok<<" ";
                pok++;
            }

        delete [] brisanje;
        brisanje = nullptr;
        pok = nullptr;

    }
    catch(std::bad_alloc e)
    {
        std::cout<<"Nedovoljno memorije!";
    }
    catch(...)
    {
        std::cout<<"Nedovoljno memorije!";
    }



	return 0;
}