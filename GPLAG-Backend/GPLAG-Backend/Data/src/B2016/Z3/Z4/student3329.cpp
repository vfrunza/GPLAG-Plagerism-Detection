#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int BrojSlovBr(std::string s){
    int brojac(0);
    for(auto x : s)
        if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')) brojac++;
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int k){
    if(k<1 || k>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vrati(k);
    std::list<std::string> l(imena.size());
    std::vector<int> velicine(k);
    int nk=imena.size()%k;
    for(int i=0; i<k; i++)
        if(nk){
            velicine[i]=int(imena.size()/k)+1; nk--;
        }else{
            velicine[i]=int(imena.size()/k);
        }
    int f(0);
    for(auto it=l.begin(); it!=l.end(); it++)
        *it=imena[f++];
    
    vrati.begin()->insert(*(l.begin()));
    int pomjeri_za(BrojSlovBr(*(l.begin())));
    auto it=l.erase(l.begin());
    
    for(int i=0; i<k; i++){ //grupe djece
        while(vrati[i].size()!=velicine[i]){
            for(int j=0; j<pomjeri_za-1; j++){
                it++; if(it==l.end()) it=l.begin();
            }
            vrati[i].insert(*it);
            pomjeri_za=BrojSlovBr(*it);
            it=l.erase(it);
            if(it==l.end()) it=l.begin();
        }
    }
    return vrati;
}

int main (){
    std::cout<<"Unesite broj djece: ";
    int n; std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::vector<std::string> imena(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++)
        std::getline(std::cin, imena[i]);
    std::cout<<"Unesite broj timova: ";
    int k; std::cin>>k;
    std::vector<std::set<std::string>> razvrst;
    try{
        razvrst=Razvrstavanje(imena, k);
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    int i(0);
    for(auto x : razvrst){
        std::cout<<"Tim "<<++i<<": ";
        int b(1);
        for(auto y : x){
            if(b==razvrst[i-1].size())
                std::cout<<y;
            else std::cout<<y<<", ";
            b++;
        }
        std::cout<<std::endl;
    }
	return 0;
}