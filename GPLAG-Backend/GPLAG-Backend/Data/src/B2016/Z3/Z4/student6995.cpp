#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>
int BrojSlovaiCifara(std::string s){
    int brojac(0);
    for(int i(0);i < s.length();i++){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9')brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int k){
   std::vector<std::set<std::string>> timovi(k);
   std::list<std::string> djeca;
   for(int i(0);i < v.size();i++)djeca.push_back(v[i]);
   if(k < 1 || k > djeca.size())throw std::logic_error("Razvrstavanje nemoguce"); 
   int tmp(djeca.size());
   auto it(djeca.begin());
    int mod(tmp%k);
   for(int i(0);i < k;i++){
        int djece_u_timu;
        if(tmp%k != 0 && mod != 0){djece_u_timu=tmp/k+1;mod--;}
        else djece_u_timu = tmp/k;
        
        for(int j(0);j < djece_u_timu;j++){
            int broj(BrojSlovaiCifara(*it)-1);
            timovi[i].insert(*it);
            it=djeca.erase(it);
            if(it == djeca.end())
                it=djeca.begin();
            if(i==k-1 && j == djece_u_timu-1)break;
            
            while(broj){
                while(broj && it != djeca.end())it++,broj--;
                if(it == djeca.end())it=djeca.begin();
            }
        }
   }
   return timovi;
}
int main ()
{
    int k,broj_djece;
    std::vector<std::set<std::string>> timovi;
    std::vector<std::string> djeca;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite imena djece: ";
    for(int i(0);i < broj_djece;i++){
        std::string s;
        std::getline(std::cin,s);
        djeca.push_back(s);
    }
    std::cout << "\nUnesite broj timova: ";
    std::cin >> k;
    try{
        timovi = Razvrstavanje(djeca,k);
    }catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: "<< izuzetak.what();
        return 0;
    }
        for(int i(0);i < timovi.size();i++){
            std::cout << "Tim " << i+1 << ": ";
            auto it(timovi[i].begin());
            std::cout << *it++;
            while(it != timovi[i].end()){
                std::cout << ", " << *it++;
            }
            std::cout << "\n";
        }
        
    
	return 0;
    
}