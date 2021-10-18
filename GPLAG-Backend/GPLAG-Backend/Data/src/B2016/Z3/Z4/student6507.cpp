/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <stdexcept>
#include <list>

int mod(int n, int k){
    int a(n/k);
    return n-a*k;
}
int DuzinaImena(std::string ime){
    int n(0);
    for(int i=0; i<ime.size(); i++)
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9')) n++;

    return n;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int k){
    if(k<1 || k>imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n(imena_djece.size());
    std::list<std::string> lista_imena;
    for(auto x : imena_djece) lista_imena.push_back(x);
    int prva_velicina(std::floor(n/k)+1), broj_prvih_timova(mod(n,k));
    int druga_velicina(std::floor(n/k));
    std::vector<std::set<std::string>> razvrstano(k);
    auto it(lista_imena.begin());
    int prvi(0), duzina(0);
    while(lista_imena.size()!=0){
        if(it==lista_imena.end()) it=lista_imena.begin();
        if(prvi<broj_prvih_timova){
            razvrstano[prvi].insert(*it);
            duzina=DuzinaImena(*it);
            it=lista_imena.erase(it);
            if(razvrstano[prvi].size()==prva_velicina) prvi++;
        }
        else{
            if(prvi==n) break;
            razvrstano[prvi].insert(*it);
            duzina=DuzinaImena(*it);
            it=lista_imena.erase(it);
            if(razvrstano[prvi].size()==druga_velicina) prvi++;
        }
        for(int a=0; a<duzina-1; a++){
            if(it==lista_imena.end()) it=lista_imena.begin();
            it++;
            if(it==lista_imena.end()) it=lista_imena.begin();
        }
    }
    return razvrstano;
}

int main ()
{
    try{
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        std::vector<std::string> imena_djece(n);
        for(auto &x : imena_djece) {std::getline(std::cin, x);}
        std::cout<<"Unesite broj timova: ";
        int k;
        std::cin>>k;
        auto timovi(Razvrstavanje(imena_djece, k));
        for(int i=0; i<k; i++){
            std::cout<<"Tim "<<i+1<<": ";
            int j(0);
            for(auto x : timovi[i]){
                if(j==timovi[i].size()-1) std::cout<<x<<std::endl;
                else std::cout<<x<<", ";
                j++;
            }
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
	return 0;
}