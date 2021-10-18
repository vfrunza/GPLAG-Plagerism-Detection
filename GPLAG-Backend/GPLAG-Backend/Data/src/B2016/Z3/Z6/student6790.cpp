#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int duzina(std::string s) {
    int br=0;
   for(int i=0; i<s.size(); i++)
   if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')  || (s[i]>='0' && s[i]<='9') ) br++;
   return br;
}
std::vector<std::multiset<std::string>> Razvrstavanje (std::vector<std::string> djeca, int k) {
    std::vector<std::multiset<std::string>> tim(k);
    int n=djeca.size();
    
    std::shared_ptr<Dijete> pocetak=nullptr;
    std::shared_ptr<Dijete> prethodni;
    for(int i=0; i<n; i++) {
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=djeca[i]; novi->sljedeci=nullptr;
        if(pocetak==nullptr) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=nullptr;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    int vel=duzina(pocetak->ime);
    tim[0].insert(pocetak->ime);
    auto poc=pocetak;
    
    for(int i=0; i<n-1; i++) pocetak=pocetak->sljedeci;    //pomijeramo do kraja liste da bismo preusmjerili pokazivac sa elementa koji trebamo izbrisati na sljedeci
    auto next=pocetak->sljedeci;
    pocetak->sljedeci=next->sljedeci;
    pocetak=pocetak->sljedeci;
    int br=0;
    int brojac=1;
    int g=n-1;
    n--;
    for(int i=0; i<g; i++) {
        for(int i=0; i<vel-1; i++) pocetak=pocetak->sljedeci;
        if(br<(g+1)%k && brojac==((g+1)/k+1)) {br++; brojac=0;}
        if(br>=(g+1)%k && brojac==((g+1)/k)) {br++; brojac=0;}
        tim[br].insert(pocetak->ime);
        brojac++;
        vel=duzina(pocetak->ime);
        poc= pocetak;
        for(int i=0; i<n-1; i++) pocetak=pocetak->sljedeci;
        next=pocetak->sljedeci;
        pocetak->sljedeci=next->sljedeci;
        if(n==1) {pocetak->sljedeci=nullptr; }
        else pocetak=pocetak->sljedeci;
        n--;
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
    std::cout<<"Unesite imena djece:"<<std::endl;
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