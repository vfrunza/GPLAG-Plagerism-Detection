#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <set>
#include <functional>
#include <list>


int CijeliDio(double x, double Eps = 1e-10){
    return int(x+Eps*std::fabs(x));
}
int DuzinaImena(std::string s){
    int duzina {0};
    for(int i=0; i<s.size(); i++){
        if( ((s[i]>= 'A') && (s[i] <= 'Z'))  || ((s[i]>= 'a') && (s[i] <= 'z')) || ((s[i]>= '0') && (s[i] <= '9')) ) duzina++;
    }
    return duzina;
}

std::vector<std::set<std::string>>  Razvrstavanje(std::vector<std::string> v, int k){
    if(k<1 || k>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> a;
    
    int n(v.size());
    
    int broj_brojnijih_timova(n%k);
   // std::cout<<broj_brojnijih_timova;
    int broj_clanova_brojnijih_timova(CijeliDio(n/k)+1);
   // std::cout <<broj_clanova_brojnijih_timova;
    
    int broj_ostalih_timova(k-broj_brojnijih_timova);
   // std::cout<<broj_ostalih_timova;
    int broj_clanova_ostalih_timova(CijeliDio(n/k));
   // std::cout<<broj_clanova_ostalih_timova;
    
    std::list<std::string> lista_imena;
    for(int i{0}; i<v.size(); i++){
        lista_imena.push_back(v.at(i));
    }  
    auto f(lista_imena.begin()), g(lista_imena.end());
    
    
    //prvo radim za brojnije timove
    
    for(int i=1; i<=broj_brojnijih_timova; i++){
        std::set<std::string> tim;
        for(int j=1; j<=broj_clanova_brojnijih_timova; j++){//ovde se krila greska za testove 4 i 6!!
       
           if(i==1 && f !=g) {  //ovo mi se odnosi na slucaj Damir, pocetni, koji odmah izbacujem
              int vel(DuzinaImena(*f));
            
              tim.insert(*f);
              f=lista_imena.erase(f);
              if(f==g) f=lista_imena.begin();
              j++;
              int br(1);
              while(br<vel){
                f++;
                br++;
                if(f==g) f=lista_imena.begin();}
                }
              
           int vel(DuzinaImena(*f)); 
          
           tim.insert(*f);
           f=lista_imena.erase(f);   
           if(f==g) f=lista_imena.begin();
           int br(1);
           while(br<vel){
              f++;
              br++;
              if(f==g) f=lista_imena.begin();}
    }
    a.push_back(tim);
    }
    
    for(int i=1; i<=broj_ostalih_timova; i++){
        std::set<std::string> tim;
        for(int j=1; j<=broj_clanova_ostalih_timova; j++){
        int vel(DuzinaImena(*f));
        
        tim.insert(*f);
        f=lista_imena.erase(f);   
        if(f==g) f=lista_imena.begin();
         int br(1);
        
        while(br<vel){//ili <=
            f++;
            br++;
            if(f==g) f=lista_imena.begin();}
        }
        a.push_back(tim);
    }  
        

    return a;
}



int main ()
{
    try{
    int n;
    std::cout<< "Unesite broj djece: ";
    std::cin >>n;
    std::cin.ignore(10000, '\n');
    std::vector<std::string> vektor_imena;
    std::cout<< "Unesite imena djece: " <<std::endl;
    int i{0};
    
    while(i<n){
       
        std::string ime;
        std::getline(std::cin, ime);
        vektor_imena.push_back(ime);
        i++;
    }
    
    int m{0};
    std::cout<< "Unesite broj timova: ";
    std::cin >> m;
    
    std::vector<std::set<std::string>>  timovi(Razvrstavanje(vektor_imena, m));
    
    for(int i=0; i<timovi.size(); i++) {
        std::cout<< "Tim " << i+1 << ": ";
        int brojac{0};
        for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++){
            brojac++;
            if(brojac == timovi[i].size()) std::cout << *it;
            else  std::cout << *it<< ", ";
            }
        std::cout<< std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
/*
Damir
Ana
Muhamed
Marko
Ivan
Mirsad
Nikolina
Alen
Jasmina
Merima*/