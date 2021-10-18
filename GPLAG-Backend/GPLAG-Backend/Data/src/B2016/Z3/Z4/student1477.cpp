/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n)
{
    if(n<1 || n>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<int>br;
    for(int i=0; i<v.size()%n; i++) {
        br.push_back((v.size()/n)+1);
    }
    for(int i=0; i<n-v.size()%n; i++) {
        br.push_back(v.size()/n);
    }

    std::list<std::string> lista(v.size());
    for(int i=0; i<v.size(); i++) lista.push_back(v[i]);
    std::vector<std::set<std::string>> v2;
    std::set<std::string> skup;
    auto it=lista.begin();
    for(int i=0; i<n; i++) {
        if(i==0) {
            for(;;) {
                if(br[i]+1==skup.size()) break;
                int br(0);
                for(int i=0; i<(*it).length(); i++) {
                    if(((*it)[i]>='a' && (*it)[i]<='z') || ((*it)[i]>='A' && (*it)[i]<='Z') || ((*it)[i]>='0' && (*it)[i]<='9')) br++;
                }
                int k=br;
                skup.insert(*it);
                it=lista.erase(it);
                for(int j=0; j<k-1; j++) {
                    if(it==lista.end()) it=lista.begin();
                    it++;
                }
                if(it==lista.end()) it=lista.begin();
            }
            v2.push_back(skup);
            skup.clear();
        } else {
            for(;;) {
                if(br[i]==skup.size()) break;
                int br(0);
                for(int i=0; i<(*it).length(); i++) {
                    if(((*it)[i]>='a' && (*it)[i]<='z') || ((*it)[i]>='A' && (*it)[i]<='Z') || ((*it)[i]>='0' && (*it)[i]<='9')) br++;
                }
                int k(br);
                skup.insert(*it);
                it=lista.erase(it);
                for(int j=0; j<k-1; j++) {
                    if(it==lista.end()) it=lista.begin();
                    it++;
                }
                if(it==lista.end()) it=lista.begin();
            }
            v2.push_back(skup);
            skup.clear();
        }
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
                for(auto it=++t[i].begin(); it!=t[i].end(); it++) {
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
