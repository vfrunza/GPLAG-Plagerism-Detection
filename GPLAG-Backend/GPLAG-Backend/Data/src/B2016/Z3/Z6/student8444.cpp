/B2016/2017: Zadaća 3, Zadatak 6

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include <memory>

int brkoraka(std::string s){
    int br=0;
    for(int i=0; i<s.size();i++){
        while(i<s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))){
            br++;
            i++;
        }
    }
    return br;
}

struct Dijete{
    std::string ime;
    //Dijete *sljedeci;
    std::shared_ptr<Dijete> sljedeci;
};
//Dijete *t=nullptr;
//Dijete *poc=nullptr;
std::shared_ptr<Dijete> t(nullptr);

std::shared_ptr<Dijete> poc(nullptr);




void dodaj(const std::string &element){
    //Dijete *novi=new Dijete;
    
    std::shared_ptr<Dijete> novi (new Dijete);
    
    novi->ime=element;
    if(poc==nullptr){//nema elemenata
        poc=novi;
        t=novi;
        t->sljedeci=nullptr;
        
    }
    else {
        t->sljedeci=novi;
        t=novi;
        novi->sljedeci=nullptr;
    }
   
   /* if(t->sljedeci==nullptr){//zadnji element
        t->sljedeci=novi;
        t=novi;
        
    }*/
   /* else {//neki random u sredini
        novi->sljedeci=t->sljedeci;
        t->sljedeci=novi;
        t=novi;
    }*/
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
     if(k<1 || k>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
     std::vector<std::set<std::string>> vrati;
     vrati.resize(k);
     for(int i=0;i<v.size();i++) dodaj(v[i]);
     //std::cout<<t->ime;
     t->sljedeci=poc;
     t=poc;
     //std::cout<<t->ime;
     
     
     int timova=v.size()%k;
     int clanova;//=v.size()/k+1;
     int br_koraka=0;
     
     timova++;
     for(int i=0;i<k;i++){
        timova--;
        if(timova<=0) clanova=v.size()/k;
        else clanova=(v.size()/k)+1;
        while(clanova!=0 && poc!=nullptr){//uslov
       //std::cout<<t->ime;
       //std::cout<<(t->ime).size();
             br_koraka=brkoraka(t->ime);//.size();//ime
             //std::cout<<br_koraka<<"__";
             vrati[i].insert(t->ime);
             clanova--;
               //obrisi();
             //std::cout<<t->ime;
             if(t==poc && poc->sljedeci==poc){//na pocetku i imam jedan element
                 //delete t;
                 t->sljedeci=nullptr;
                 t=poc=nullptr;
                 
             }
             else if(t->sljedeci->sljedeci!=t){//brisem sa pocetka a imam vise od 2 elementa
                  //Dijete *pom=poc;
                  std::shared_ptr<Dijete> pom(poc);
                  
                 while(pom->sljedeci!=t)pom=pom->sljedeci;
                 pom->sljedeci=t->sljedeci;
                 
                 //delete t;
                 poc=pom->sljedeci;
                 t->sljedeci=nullptr;
                 t=pom->sljedeci;
                 //t=t->sljedeci;
                  
             }
             else if(t->sljedeci->sljedeci==t){//imam 2 elementa
              //Dijete *pom=t;
              std::shared_ptr<Dijete> pom(t);
              pom=t->sljedeci;
                 t->sljedeci->sljedeci=t->sljedeci;
                 //delete t;
                 t->sljedeci=nullptr;
                 t=poc=pom;
                // t->sljedeci=nullptr;
             }
             
             else {
                  //Dijete *pom=poc;
                  std::shared_ptr<Dijete> pom(poc);
                 while(pom->sljedeci!=t)pom=pom->sljedeci;
                 pom->sljedeci=t->sljedeci;
                 //delete t;
                t->sljedeci=nullptr;
                 t=pom->sljedeci;
                 
             }
             
        while(br_koraka>1){
            br_koraka--;
            
            
           // if(t->sljedeci==nullptr ) t=poc;
            //else t=t->sljedeci;
            if(t==nullptr) break;
            else if(t->sljedeci==t) break;//jedan element
            //if(poc->sljedeci!=poc && poc!=nullptr) {t=t->sljedeci;}
            else t=t->sljedeci;
            
        }
        //std::cout<<t->ime;
       
     }  
     }
     return vrati;
}

int main ()
{
    int x;
    std::cout<<"Unesite broj djece: ";
    std::cin>>x;
     std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::vector<std::string> v;
    //v.resize(x);
    std::string ime;
    std::cout<<"Unesite imena djece: \n";
    for(int i=0; i<x; i++){std::getline(std::cin,ime); v.push_back(ime);}
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    try{
    std::vector<std::set<std::string>> n=Razvrstavanje(v,k);
    for(int i=0; i<n.size();i++){
        int h=0;
        std::cout<<"Tim "<<i+1<<": ";
        for(std::string j : n[i]){
        std::cout<<j;
        if(h!=n[i].size()-1) std::cout<<", ";
        else std::cout<<std::endl;
        h++;
        }
    }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        
        return 1;
    }
    
	return 0;
}