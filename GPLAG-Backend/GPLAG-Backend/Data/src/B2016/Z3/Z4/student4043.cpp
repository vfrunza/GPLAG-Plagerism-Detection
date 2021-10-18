/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <list>

int BrojSlova(std::string ime) {
    int br(0);
    //std::cout<<"U funkciji: "<<ime<<std::endl;
    for(int i(0);i<ime.size();i++) {
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9')) br++;
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena,int br_tim) {
    if(br_tim<1 || br_tim>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i(0);i<imena.size();i++) {
        lista.push_back(imena[i]);
    }
    std::vector<std::set<std::string>> timovi(br_tim);
    int k(imena.size()%br_tim);
    //std::cout<<lista.size()<<std::endl;
    auto it(lista.begin());
    int br(BrojSlova(*it));
    timovi[0].insert(*it);
    it=lista.erase(it);
    while(lista.size()!=0) {
        //std::cout<<lista.size()<<std::endl;
        for(int j(0);j<br_tim;j++) {
            for(int i(0);i<br;i++) {
                if(it==lista.end()) it=lista.begin();
                it++;
            }
            it--;
            if(it==lista.end()) it=lista.begin();
            if(j<=k-1) {
                //std::cout<<lista.size()<<std::endl;
                br=BrojSlova(*it);
                timovi[j].insert(*it);
                it=lista.erase(it);
                if(timovi[j].size()!=(imena.size()/br_tim)+1) j--;
            }
            else {
                //std::cout<<lista.size()<<std::endl;
                br=BrojSlova(*it);
                timovi[j].insert(*it);
                it=lista.erase(it);
                if(timovi[j].size()!=(imena.size()/br_tim)) j--;
            }
        }
    }
    return timovi;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::vector<std::string> imena;
    std::cout<<"Unesite imena djece: ";
    for(int i(0);i<n;i++) {
        std::string ime;
        std::cin>>ime;
        imena.push_back(ime);
    }
    std::cout<<"\nUnesite broj timova: ";
    int br_tim;
    std::cin>>br_tim;
    try {
        std::vector<std::set<std::string>> timovi(Razvrstavanje(imena,br_tim));
        for(int i(0);i<timovi.size();i++) {
            std::cout<<"Tim "<<i+1<<": ";
            int j(0);
            for(auto x : timovi[i]) {
                if(j!=timovi[i].size()-1) {
                    std::cout<<x<<", ";
                    j++;
                }
                else {
                    std::cout<<x;
                }
            }
           std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}