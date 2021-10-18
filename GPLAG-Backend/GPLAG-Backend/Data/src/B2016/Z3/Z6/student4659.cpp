/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete>  veza;
};

int br_slova(std::string s){
    return std::count_if(s.begin(),s.end(),[](char x){bool vrati(false); if((x>='0' && x<='9') || (x>='A' && x<='Z') || (x>='a' && x<='z'))vrati=true; return vrati;});
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    
    if(n<1 || n>v.size())throw std::logic_error("Razvrstavanje nemoguce");
    
    std::shared_ptr<Dijete> pocetak(nullptr),prethodni;
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi(new Dijete);
        novi->ime=v[i]; novi->veza=nullptr;
        if(!pocetak)pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    prethodni->veza=pocetak;
    
        int br(0),br_clanova(v.size()/n+1);
        std::vector<std::set<std::string>> v1;
        auto it1(pocetak);
        auto prije(prethodni);
        for(int i=0;i<n;i++){
            std::set<std::string> skup;
            if(br==v.size()%n)br_clanova--;
            for(int j=0;j<br_clanova;j++){
                if(i==n-1 && j==br_clanova-1){
                    skup.insert(pocetak->ime);
                    pocetak->veza=nullptr;
                    break;
                }    
                skup.insert(it1->ime);
                auto it2(it1);auto poslije(it1->veza);
                int x=br_slova(it1->ime),flag(0),novi_br(0);
                for(int i=0;i<x;i++){
                    it1=it1->veza;
                    if(it1->ime==it2->ime){flag=1;x++;novi_br++;}
                }
                prije->veza=poslije;
                if(prethodni==it2)prethodni=prije;
                if(pocetak==it2)pocetak=poslije;
                    
                if(flag)x-=novi_br;
                if(pocetak!=prethodni){
                    for(int i=0;i<x-1;i++){
                        prije=prije->veza;
                    }    
                }
            }
            br++;
            v1.push_back(skup);
        }
    return v1;
}

int main ()
{
    int n(0);
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    
        std::vector<std::string> v(n);
        std::cout << "Unesite imena djece: "<< std::endl;
        std::cin.ignore(100,'\n');
        for(int i=0;i<n;i++) std::getline(std::cin,v[i]);
        
            int br_timova(0);
            std::cout << "Unesite broj timova: ";
            std::cin >> br_timova;
            try{
                std::vector<std::set<std::string>> v1;
                v1=Razvrstavanje(v,br_timova);
                
                    for(int i=0;i<v1.size();i++){
                        std::cout << "Tim " << i+1 << ": ";
                        int br(0);
                        for(auto x : v1[i]){
                            if(br==v1[i].size()-1)std::cout << x ;
                            else std::cout << x << ", ";
                            br++;
                        }    
                        std::cout << std::endl;
                    }
            }
            catch(std::logic_error e){
                std::cout << "Izuzetak: " << e.what();
            }
	return 0;
}