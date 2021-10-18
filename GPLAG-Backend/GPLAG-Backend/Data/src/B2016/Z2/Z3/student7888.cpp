#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
      int zbroj(int x)  {
        int zbroj(0);
        while ( x != 0 ) {
            zbroj+=x%10;
            x/=10;
        }
        return zbroj;
    }

  
    template < typename Tip1,typename Tip2,typename Tip3>
    auto UvrnutiPresjek(Tip1 Poc1,Tip1 Kraj1,Tip2 Poc2,Tip2 Kraj2,Tip3 fun(Tip3))-> typename std::remove_reference<decltype(*Poc1)>::type**   {
        int brojac (0);
        auto pomocni2(Poc2);            
        auto pomocni1(Poc1);

                while ( Poc1 != Kraj1 ) {
                            Poc2 = pomocni2;

                    while ( Poc2 != Kraj2 ) {
                        if ( fun(*Poc1) == fun(*Poc2) ) brojac++;
                    
                            Poc2++;
                    }
                            Poc1++;
                }   
                            Poc1 = pomocni1;
                            Poc2 = pomocni2;
               typename std::remove_reference<decltype(*Poc1)>::type**p(nullptr); 
   try {
    typename std::remove_reference<decltype(*Poc1)>::type** p(new typename std::remove_reference<decltype(*Poc1)>::type*[brojac]);
   try {
    for ( int j = 0 ; j < brojac; j++ ) p[j] = new typename std::remove_reference<decltype(*Poc1)>::type[3];
    
                           int i = 0;
        
                 while ( Poc1 != Kraj1  )   {
                                    Poc2 = pomocni2;

                     while ( Poc2 != Kraj2 )    {
                                

                        if ( fun(*Poc2) == fun(*Poc1) )    {
                            p[i][0] = *Poc1;
                            p[i][1] = *Poc2;
                            p[i][2] = fun(*Poc1);
                            i++;
                        }
              
                            Poc2++;

                    }
                            Poc1++;
                }
                return p;
      
   }
   
   catch (...)  {
       for ( int j = 0; j < brojac; j++) delete[] p[j];
        delete[] p;
       
   }
   }
   catch(...)   {
       throw;
   }
       
         
         
                 return p;
         }
     
     

    template < typename Tip1,typename Tip2,typename Tip3>
    int broj_redova(Tip1 Poc1,Tip1 Kraj1,Tip2 Poc2,Tip2 Kraj2,Tip3 fun(Tip3))   {
         int brojac (0);
         auto pomocni2(Poc2);
         auto pomocni1(Poc1);
    
         
          while ( Poc1 != Kraj1 ) {
                                          Poc2 = pomocni2;

                    while ( Poc2 != Kraj2 ) {
                        if ( fun(*Poc1) == fun(*Poc2) ) brojac++;
                            Poc2++;
                    }
                            Poc1++;
                }   
                            Poc1 = pomocni1;
                            Poc2 = pomocni2;
         
         return brojac;
    } 
       

   
int main ()
{
     std::deque<std::deque<int>> Matrica;
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    int a;
    std::cin>>a;
    std::deque<int> Dek1;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    for ( int i = 0 ; i < a; i++)   {
        int unos;
        std::cin>>unos;
        Dek1.push_back(unos);
    }
        std::cout<<"Unesite broj elemenata drugog kontejnera: ";
    int b;
    std::cin>>b;
    std::deque<int> Dek2;
    std::cout<<"Unesite elemente drugog kontejnera: ";
    for ( int i = 0 ; i < b; i++)   {
        int unos;
        std::cin>>unos;
        Dek2.push_back(unos);
    }
        int **p(UvrnutiPresjek(Dek1.begin(),Dek1.end(),Dek2.begin(),Dek2.end(),zbroj));
        std::cout<<"Uvrnuti presjek kontejnera: ";
        for (int i=0; i<broj_redova(Dek1.begin(),Dek1.end(),Dek2.begin(),Dek2.end(),zbroj);i++){
            for (int j=0;j<3;j++){
                std:: cout <<std::setw(7)<< p[i][j];
            }
            std::cout << std::endl;
        }
        for ( int i = 0 ; i < (broj_redova(Dek1.begin(),Dek1.end(),Dek2.begin(),Dek2.end(),zbroj)); i++) delete[] p[i];
        delete[] p;
	return 0;
}