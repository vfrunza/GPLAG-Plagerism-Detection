
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int duzina(std::string s) {
    int br=0;
   for(int i=0; i<s.size(); i++)
   if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')  || (s[i]>='0' && s[i]<='9') ) br++;
   return br;
}
std::vector<std::multiset<std::string>> Razvrstavanje (std::vector<std::string> djeca, int k) {
    std::vector<std::multiset<std::string>> tim(k);
    int n=djeca.size();
    
    
    std::list<std::string> lista;
    for(int i=0; i<n; i++) lista.push_back(djeca[i]);
    tim[0].insert(djeca[0]);
    int vel=duzina(djeca[0]); 
    auto it=lista.begin();
    it=lista.erase(it);
    int br=0;
    int brojac=1;
    while(lista.size()!=0) {
        
        for(int j=0; j<vel-1; j++) {if(it==lista.end())  it=lista.begin(); it++;}
        if(it==lista.end())  it=lista.begin();
        vel=duzina(*it);
        if(br<n%k && brojac==(n/k+1)) {br++; brojac=0;}
        if(br>=n%k && brojac==(n/k)) {br++, brojac=0;}
        tim[br].insert(*it);
        brojac++;
        it=lista.erase(it);
        
                                                      //u vektor pomocni dodajemo ime dj.
    }
    
    return tim;
}

int main ()
{ 
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::vector<std::string> djeca(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++) std::getline(std::cin, djeca[i]); 
    int k;
    try{
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
    if(k<1 || k>n) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::multiset<std::string>> tim{Razvrstavanje(djeca, k)};
    for(int i=0; i<tim.size(); i++) {
        std::cout<<"Tim "<<i+1<<": "; 
        auto poc=tim[i].begin();
        int velicina=tim[i].size();
        for(int j=0; j<velicina-1; j++) {std::cout<<*poc<<", "; poc++;}
        std::cout<<*poc;
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error i) {std::cout<<"Izuzetak: "<<i.what();}
    
	return 0;
}