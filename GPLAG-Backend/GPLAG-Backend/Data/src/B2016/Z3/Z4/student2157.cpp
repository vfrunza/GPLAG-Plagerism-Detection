#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Djeca, int broj_timova){
    std::list<std::string> Dj;
    for( int i = 0; i < Djeca.size(); i++){
        Dj.push_back(Djeca[i]);
    }
        int br_clanova(Djeca.size()/broj_timova);
        int br_clanova1(int(Djeca.size()/broj_timova) + 1);
        int br_clanova2(int(Djeca.size()/broj_timova));
        std::vector<std::set<std::string>> Timovi(broj_timova);
        auto j= Dj.begin();
        
            Timovi[0].insert(*j);
            j=Dj.erase(j);
            int k(0);
        for( std::string x : Dj){
            int br(0);
            while(br != x.length()){
                   if(j == Dj.end()) j=Dj.begin();
                        br++;
                    if( br == x.length()) 
                        Timovi[k].insert(*j);
                        j=Dj.erase(j);
                    if( (Timovi[k].size()==br_clanova1 && k==0) || (Timovi[k].size()==br_clanova2 && k!=0) || (Timovi[k].size()==br_clanova)) 
                        k++;}  }
        return Timovi; }

int main (){
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"\nUnesite imena djece: ";
    std::vector<std::string> Djeca;
    for(int i = 0; i < n; i++){
        std::string s;
        std::getline(std::cin, s);
        Djeca.push_back(s);
    }
    std::cout<<"\nUnesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    auto Timovi(Razvrstavanje(Djeca, broj_timova));
    for( int i = 0; i< Timovi.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        for( auto j : Timovi[i]){
            std::cout<<j;
        }
    }
	return 0;
}