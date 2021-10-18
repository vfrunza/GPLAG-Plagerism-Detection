#include <iostream>
#include <string>
#include <set>
#include <stdexcept>
#include <vector>
#include <memory>
//#include "sake.h"

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete>sljedeci;
};    

Dijete *NapraviListu(std::vector<std::string> v){
    std::shared_ptr<Dijete> pocetni=nullptr, kraj;
    for(int i=0; i<v.size(); i++){
        std::shared_ptr<Dijete> novi(new Dijete);
        (*novi).ime=v[i];
          (*novi).sljedeci=nullptr;
        if(i==0)
            pocetni=novi;
        else 
            (*kraj).sljedeci=novi; 
        kraj=novi;    
    }
    (*kraj).sljedeci=pocetni;
    return pocetni.get();
}

Dijete  *Izbaci(Dijete* p){
    auto q=p;
    for(auto it2(p->sljedeci.get()); it2!=p; it2=it2->sljedeci.get()){
        q=q->sljedeci.get();
    }
    q->sljedeci=p->sljedeci;
    return (q->sljedeci.get());
}

int Koliko(std::string s){
    int br(0);
    for(int i=0;i<s.length(); i++)
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) 
            br++;
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    auto it(NapraviListu(v)); int v_size;
    std::vector<std::set<std::string>> a(n);
    for(int i=0; i<n; i++)    
    {    
        int max_vel=v.size()/n; 
        if(v.size()%n>i) max_vel+=1;
        v_size=max_vel;
        while (v_size!=0) 
        {
            a[i].insert((*it).ime);
            if(i==n-1 && v_size==1)
            {
                 it->sljedeci=nullptr;
                 v_size--; 
            }
            else
                {
                int potez(Koliko((*it).ime));
                it=Izbaci(it); 
                v_size--;
                int w(1);
                while(w!=potez){
                    it=(*it).sljedeci.get();
                    w++;
                }
            }
        }
    }
    return a;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int br_osoba; std::cin >> br_osoba;
    std::vector<std::string> w(br_osoba);
    std::cout <<"Unesite imena djece:";
    std::cin.ignore(10000, '\n');
    {
        std::string pomocni;
        for(int i=0; i<br_osoba;i++){
            std::getline(std::cin, pomocni);
            w[i]=pomocni;
        }
    }
    std::cout << "\nUnesite broj timova: "; int k; std::cin >> k;
    try {
        auto a(Razvrstavanje(w,k));
        for(int i=0; i<a.size(); i++){
            std::cout << "Tim " <<i+1<<": ";
            int brojac(0);
            for(auto x(a[i].begin()); x!=a[i].end();x++)
                if(brojac++==a[i].size()-1)
                    std::cout << *x;
                else
                    std::cout << *x<<", ";
            std::cout  << std::endl; 
        }
    }
    catch (std::logic_error error) {
        std::cout <<"Izuzetak: "<< error.what() << std::endl;
    }
	return 0;
}