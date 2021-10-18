/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete>sljedeci;
};
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string>v, int n)
{
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<int>br;
    for(int i=0; i<v.size()%n; i++) {
        br.push_back((v.size()/n)+1);
    }
    for(int i=0; i<n-v.size()%n; i++) {
        br.push_back(v.size()/n);
    }
    std::shared_ptr<Dijete>pocetak(nullptr), prethodni;
    for(int i=0; i<v.size(); i++) {
        std::shared_ptr<Dijete>novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    std::vector<std::set<std::string>>v2;
    auto p=pocetak;
    auto p2=pocetak;
    int k(0), br2(0);
    std::set<std::string>skup;
    for(int i=0; i<n; i++) {
        for(;;) {
            if(br[i]==skup.size()) break;
            if(k!=0) for(int j=0; j<k-1; j++) p=p->sljedeci;
            skup.insert(p->ime);
            for(;; p2=p2->sljedeci) {
                if(p2->sljedeci==p) break;
            }
            int br(0);
            for(int i=0; i<(p->ime).length(); i++) {
                if(((p->ime)[i]>='a' && (p->ime)[i]<='z') || ((p->ime)[i]>='A' && (p->ime)[i]<='Z') || ((p->ime)[i]>='0' && (p->ime)[i]<='9')) br++;
            }
            k=br;
            p2->sljedeci=p->sljedeci;
            if(p2!=p) p=p2->sljedeci;
            if(br2==v.size()-1) {
                p->sljedeci=nullptr;
            }
            br2++;
        }
        v2.push_back(skup);
        skup.clear();
    }
    return v2;
}

int main ()
{
    try {
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000,'\n');
        std::vector<std::string> v;
        std::string s;
        std::cout<<"Unesite imena djece: "<<std::endl;
        for(int i=0; i<n; i++) {
            std::getline(std::cin, s);
            v.push_back(s);
        }
        std::cout<<"Unesite broj timova: ";
        int m;
        std::cin>>m;
        std::vector<std::set<std::string>>t;
        t=Razvrstavanje(v, m);
        for(int i=0; i<t.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            if(i==0) {
                for(auto it=t[i].begin(); it!=t[i].end(); it++) {
                    if(it==(--t[i].end())) std::cout<<*it;
                    else std::cout<<*it<<", ";
                }

            } else {
                for(auto it=t[i].begin(); it!=t[i].end(); it++) {
                    if(it==(--t[i].end())) std::cout<<*it;
                    else std::cout<<*it<<", ";
                }
            }
            std::cout<<std::endl;
        }
    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}
