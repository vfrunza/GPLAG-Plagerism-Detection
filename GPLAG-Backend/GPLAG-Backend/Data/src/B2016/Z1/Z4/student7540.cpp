/*
   B16/17 (Tutorijal 6, Zadatak 3)
   
    Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
    i sugestije saljite na mail: khodzic2@etf.unsa.ba
   
    Napomene: testovi su konacni tek pred tutorijal
              za krsenje zabrana dobiva se 0 bodova za zadatak
   
*/
#include <stdexcept>
#include <iostream>
#include <new>
 
int** KreirajTrougao(int n)
{
    if (n<=0)
        throw std::domain_error("Broj redova mora biti pozitivan");
    int **a(nullptr);
    try
    {
        a=new int* [n];
        a[0] = new int [n*n];
       
        for(int i(1);i<n;i++)
        {
            a[i]=a[i-1]+(2*(i-1)+1);
        }
       
        for(int i(0);i<n;i++)
        {
            a[i][i]=1;
            int pocetak(0),broj(i+1),kraj(2*i);
            while(pocetak<i)
            {
                a[i][pocetak]=broj;
                a[i][kraj]=broj;
                pocetak++;
                kraj--;
                broj--;
            }
        }
   
    }
    catch(std::bad_alloc izuzetak)
    {
       
        delete[] a;
        throw std::bad_alloc();
    }
   
    return a;
}
 
int main ()
{
    try
    {
        std::cout<<"Koliko zelite redova: ";
        int n;
        std::cin>>n;
        int **pok(KreirajTrougao(n));
        for(int i(0);i<n;i++)
        {
            for(int j(0);j<2*i+1;j++)
            {
                std::cout<<pok[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        delete[] pok[0];
        delete[] pok;
    }
    catch(std::bad_alloc izuzetak)
    {
        std::cout<<"Izuzetak: Nedovoljno memorije!";
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}