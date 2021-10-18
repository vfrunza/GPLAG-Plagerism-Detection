/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
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

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
     if(k<1 || k>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
     std::vector<std::set<std::string>> vrati;
     vrati.resize(k);
     //sva imena kopiramo u listu-iz vektora u listu
     std::list<std::string> lista;
     std::copy(v.begin(),v.end(),std::back_inserter(lista));
     
    
     int timova=v.size()%k;
     int clanova;//=v.size()/k+1;
     std::list<std::string>::iterator it;
     it=lista.begin();
     auto kraj=--lista.end();
     //for(std::string s:lista) std::cout<<s;
     int br_koraka=0;
     
     timova++;
     for(int i=0;i<k;i++){
        timova--;
        if(timova<=0) clanova=v.size()/k;
        else clanova=(v.size()/k)+1;
        
        while(clanova!=0 && lista.size()>0){ 
        //&& lista.size()>0){//uslov
            br_koraka=brkoraka(*it);//.size();//ime  
            vrati[i].insert(*it);
          
            
             if(it!=kraj && lista.size()!=1) {it=lista.erase(it); clanova--; }//u sredini---&& it!=lista.begin()
             else if(lista.size()==1 ){ lista.erase(it);clanova--;}
            // else if(it==lista.end() && it==lista.begin()){ lista.erase(it); clanova--;}//jedan elemnt
             else if(it==kraj && it!=lista.begin()&& lista.size()!=1) { //na kraju
                 --kraj;
                 std::list<std::string>::iterator it1;
                 it1=lista.begin();
                 lista.erase(it);
                 it=it1;
                 clanova--;
                 
             }
              /*else if(it!=lista.end() && it==lista.begin()) { //na pocetku
                 it=lista.erase(it);
                  clanova--;
             }*/
             
       while(br_koraka>1){
            br_koraka--;
            
            //std::cout<<"k_";
            if(lista.size()==1) break;
            if(it==kraj && lista.size()!=1) it=lista.begin();
            else if(it!=kraj) it++;
            
            
        }
        //br_koraka=0;
        //std::cout<<lista.size();
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
    for(int i=0; i<x; i++) {std::getline(std::cin,ime); v.push_back(ime);}
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
        if(h!=n[i].size()-1 ) std::cout<<", ";
        else std::cout<<std::endl;
        h++;
        
        }
    }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    
	return 0;
}