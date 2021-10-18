#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>

template<typename tip1,typename tip2,typename tip3,typename tip4>// 18.04.2016 Problemi sa c9 odnsono sa automatskim snimanjem ; Uvrnuta razlika će biti kopirana te modifikovana u slučaju pozivanja iste fje sa 4 parametra

auto UvrnutiPresjek(tip1 pocetak1,tip1 kraj1,tip2 pocetak2, tip2 kraj2, tip4 f(tip3)) ->  std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>>  {
   std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>> Presjek;
    int vrsta(0);
    for(int i=0;i!= kraj1-pocetak1;i++){
        for(int j=0;j!=kraj2-pocetak2;j++){
            if(f(pocetak1[i])==f(pocetak2[j])){
                Presjek.resize(Presjek.size()+1);
                Presjek[vrsta].push_back(pocetak1[i]);
                Presjek[vrsta].push_back(pocetak2[j]);
                Presjek[vrsta].push_back(f(pocetak1[i]));
                vrsta++;
            }
        }
    }
    std::sort(Presjek.begin(),Presjek.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Prvi,std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Drugi)
    {
        return(Prvi[2]<Drugi[2] || (Prvi[2]==Drugi[2] && Prvi[0]<Drugi[0]) || (Prvi[2]==Drugi[2] && Prvi[0]==Drugi[0] &&Prvi[1]<Drugi[1]));
    }
    );
    return Presjek;
}

// Uvrnuti presjek bez petog parametra najefikasnije ćemo uraditi modifikacijom istoimene funkcije sa pet parametara
template<typename tip1,typename tip2>
auto UvrnutiPresjek(tip1 pocetak1,tip1 kraj1,tip2 pocetak2, tip2 kraj2) ->  std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>>  {
   std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>> Presjek;
    int vrsta(0);
    for(int i=0;i!= kraj1-pocetak1;i++){
        for(int j=0;j!=kraj2-pocetak2;j++){
            if(pocetak1[i]==pocetak2[j]){
                Presjek.resize(Presjek.size()+1);
                Presjek[vrsta].push_back(pocetak1[i]);
                Presjek[vrsta].push_back(0);
                Presjek[vrsta].push_back(0);
                vrsta++;
            }
        }
    }
    std::sort(Presjek.begin(),Presjek.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Prvi,std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Drugi)
    {
        return(Prvi[0]<Drugi[0]);
    }
    );
    return Presjek;
}


//UvrnutaRazlika je slična presjeku, uz neke minorne promjene

template<typename tip1,typename tip2,typename tip3,typename tip4>
auto UvrnutaRazlika(tip1 pocetak1,tip1 kraj1,tip2 pocetak2, tip2 kraj2, tip4 f(tip3)) ->  std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>>  {
   std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>> Razlika;
    int vrsta(0);
    for(int i=0;i!= kraj1-pocetak1;i++){
        bool ima(false);
        for(int j=0;j!=kraj2-pocetak2;j++){
            
            if(f(pocetak1[i])==f(pocetak2[j])){
               ima=true;
               break;
            }
        }
        if(ima ==false) {
             Razlika.resize(Razlika.size()+1);
            Razlika[vrsta].push_back(pocetak1[i]);
            Razlika[vrsta].push_back(f(pocetak1[i]));
           
            vrsta++;   // Problemi sa spašavanjem koda
        }
    }//Kopija za drugi skup
    for(int i=0;i!= kraj2-pocetak2;i++){
        bool ima(false);
        for(int j=0;j!=kraj1-pocetak1;j++){
            
            if(f(pocetak2[i])==f(pocetak1[j])){
               ima=true;
               break;
            }
        }
        if(ima ==false) {
             Razlika.resize(Razlika.size()+1);
            Razlika[vrsta].push_back(pocetak2[i]);
            Razlika[vrsta].push_back(f(pocetak2[i]));
           
            vrsta++;   // Problemi sa spašavanjem koda
        }
    }
    
    
    std::sort(Razlika.begin(),Razlika.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Prvi,std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Drugi)
    {
        return(Prvi[0]>Drugi[0]|| (Prvi[0]==Drugi[0] && Prvi[1]>Drugi[1]));
    }
    );
    return Razlika;
}


//Uvrnuta razlika sa 4 parametra
template<typename tip1,typename tip2>
auto UvrnutaRazlika(tip1 pocetak1,tip1 kraj1,tip2 pocetak2, tip2 kraj2) ->  std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>>  {
   std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type>> Razlika;
    int vrsta(0);
    for(int i=0;i!= kraj1-pocetak1;i++){
        bool ima(false);
        for(int j=0;j!=kraj2-pocetak2;j++){
            
            if(pocetak1[i]==pocetak2[j]){
               ima=true;
               break;
            }
        }
        if(ima ==false) {
             Razlika.resize(Razlika.size()+1);
            Razlika[vrsta].push_back(pocetak1[i]);
            Razlika[vrsta].push_back(0);
           
            vrsta++;   // Problemi sa spašavanjem koda
        }
    }//Kopija za drugi skup
    for(int i=0;i!= kraj2-pocetak2;i++){
        bool ima(false);
        for(int j=0;j!=kraj1-pocetak1;j++){
            
            if(pocetak2[i]==pocetak1[j]){
               ima=true;
               break;
            }
        }
        if(ima ==false) {
             Razlika.resize(Razlika.size()+1);
            Razlika[vrsta].push_back(pocetak2[i]);
            Razlika[vrsta].push_back(0);
           
            vrsta++;   
        }
    }
    
    
    std::sort(Razlika.begin(),Razlika.end(),[](std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Prvi,std::vector<typename std::remove_reference<decltype(*pocetak1+*pocetak2)>::type> Drugi)
    {
        return(Prvi[0]>Drugi[0]);
    }
    );
    return Razlika;
}



int SumaCifara(long long int broj){
    int suma(0);
    while(broj !=0){
        suma+=abs(broj%10);
        broj/=10;
    }
    return suma;
}
int SumaDjelilaca( long long int broj){                                                         //XX
    int SumaD(0);
    long long int tmp(abs(broj));
        for(int i=1;i<=tmp;i++){
            if( tmp%i==0)  SumaD+=i;
        }
            
    return SumaD;
}

int BrojProstihFaktora (long long int broj){
    int br(0);
    
        for(int i=2;i<=broj;i++){
                if(broj%i==0){
                bool Prost(true);
                for(int j=2;j<sqrt(i);j++){
                    if(i%j==0){
                        Prost=false;
                        break;
                    }
                }
                
                
                
                if(Prost){
                    while(broj%i==0){
                         br++;
                      broj=broj/i;
                    }
                }
            }    
                }
                
            
           
    
    return br;
}

int BrojSavrsenihDjelilaca ( long long  int broj){
   
    int br(0);
        for(int i=1;i<=broj;i++){
            if(broj % i ==0){
                //trazimo savrsen 
                int SumaD(0);
                for(int j=1; j<i;j++){
                    if(i%j==0){
                        SumaD=SumaD+j;
                    }
                }
                if (SumaD==i) br++;
            }
        }
    
    return br;
}
int main ()
{
    std::deque<int> PrviKont;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    int n;
    std::cin >> n;
    
     
    int element;
    std::cout << "Unesite elemente prvog kontejnera: " ;
     std::cin >> element;
     PrviKont.push_back(element);
    for(int i=1;i<n;i++){
        
        std::cin >> element;
     
            bool ima(false);
            for(int j=0;j<i;j++){
                if(PrviKont[j]==element) {i--; ima=true;break;}
            }
            if (!ima)
                PrviKont.push_back(element);
        
    }
    
    
    std::cout << "Unesite broj elemenata drugog kontejnera: " ;
    int m;
    std::cin >> m;
    
    std::deque<int> DrugiKont;
      std::cout << "Unesite elemente drugog kontejnera: " ;
      std::cin >> element;
      DrugiKont.push_back(element);
      
      
    for(int i=1;i<m;i++){
        std::cin >> element;
        bool ima(false);
        for(int j=0;j<i;j++){
            if(DrugiKont[j]==element){i--;ima=true;break;}
        }
        if(!ima)
        DrugiKont.push_back(element);
    }
    
    std::cout << "Uvrnuti presjek kontejnera:" << std::endl;//ISPIS--
    std::vector<std::vector<int>> Presjek(UvrnutiPresjek(PrviKont.begin(),PrviKont.end(),DrugiKont.begin(),DrugiKont.end(),SumaCifara));
    for(int i=0;i<Presjek.size();i++){
        std::cout <<std::setw(6)<< Presjek[i][0]<<" ";
        std::cout <<std::setw(6)<< Presjek[i][1]<<" ";
        std::cout <<std::setw(6)<< Presjek[i][2]<<" ";
        std::cout <<std::endl;
    }
    std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
    std::vector<std::vector<int>> Razlika(UvrnutaRazlika(PrviKont.begin(),PrviKont.end(),DrugiKont.begin(),DrugiKont.end(),BrojProstihFaktora));
    for(int i=0;i<Razlika.size();i++){
        std::cout <<std::setw(6)<< Razlika[i][0]<<" ";
        std::cout <<std::setw(6) <<Razlika[i][1]<<" " ;
        std::cout<<std::endl; 
        
      
       
    }
    std::cout << "Dovidjenja!";
	return 0;
}